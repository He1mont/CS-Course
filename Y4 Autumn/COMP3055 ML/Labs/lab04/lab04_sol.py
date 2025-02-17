'''
Sample solution for Lab COMP3055 UNNC
Environments:	Python = 3.7.4
		numpy = 1.19.1
		scikit-learn = 0.21.3
		matplotlib = 3.1.1
'''

# load data from local file, fetch_openml() also works
import numpy as np
from collections import Counter
import math

data = np.load('../data/mnist.npz', allow_pickle=True)
x_train, y_train, x_test, y_test = data['x_train'], data['y_train'], data['x_test'], data['y_test']
# # check the maximum value in your saved x_train & x_test, if max value <= 1, multiply with 255
# x_train = x_train * 255
# x_test = x_test * 255
# ensure y_train and y_test as integer
y_train = y_train.astype(int)
y_test = y_test.astype(int)

# obtain a small set for the lab exercise
X_small = np.reshape(x_train[0:1000], (1000, 784))
Y_small = y_train[0:1000]
X_test = np.reshape(x_test[0:100], (100, 784))
Y_test = y_test[0:100]
print('data load finish')

def Bayes_train(train_x, train_y, m):
    # prior probability - P(d)
    totalNum = train_x.shape[0]
    classNum = Counter(train_y)
    # P(d=i) = total number of class i / total number of all classes
    prioriP = np.array([classNum[i] / totalNum for i in range(10)])

    # posterior probability - P(X|d), also a set of P(xi|d)
    # create empty array with shape of (10, 784), 10 refers to the number of classes and 784 refers to the number of features
    posteriorNum = np.empty((10, train_x.shape[1]))
    posteriorP = np.empty((10, train_x.shape[1]))

    for i in range(10):
        # TRICK 1: treat brightness as continuous value to reduce calculation complexity
        posteriorNum[i] = train_x[np.where(train_y == i)].sum(axis=0)
        # m-estimation smoothing
        posteriorP[i] = (posteriorNum[i] / 255 + m/255) / (classNum[i] + m)     # 除以255是为了归一化处理
    return prioriP, posteriorP


def Bayes_pret(test_x, test_y, prioriP, posteriorP):
    # create an empty array for recording the predictions
    pret = np.empty(test_x.shape[0])
    for i in range(test_x.shape[0]):
        # create an empty array for recording the probability of each class for the i th testing sample
        prob = np.empty(10)
        for j in range(10):
            # TRICK 2: take log(x1)+log(x2)+... to instead of x1·x2·... to avoid decreasing to zero
            # TRICK 3: only consider two situation for pixel, dark or bright, to be consistent with TRICK 1
            # if a pixel is bright (!=0), we take the computed posterior probability, otherwise 1 minus it
            temp = sum([math.log(1 - posteriorP[j][x]) if test_x[i][x] == 0 else math.log(posteriorP[j][x]) for x in
                        range(test_x.shape[1])])
            prob[j] = np.array(math.log(prioriP[j]) + temp)

            # you can also try below code for the multiplication (without TRICK 2)
            # p = 1.
            # for x in range(test_x.shape[1]):
            #     temp = 1 - posteriorP[j][x] if test_x[i][x] == 0 else posteriorP[j][x]
            #     p = p * temp
            # prob[j] = prioriP[j] * p

        pret[i] = np.argmax(prob)   # get the digit with most probability
    return pret, (pret == test_y).sum() / test_y.shape[0]


# P(d|X) = P(X|d)P(d) / P(X)
# P(X|d) = P(x0|d)P(x1|d)...P(xn|d)
# P(dk|X) = max(P(d1|X), P(d2|X), ... , P(d10|X))
# prioriP - P(d)
# posteriorP - P(X|d)
m = 10
prioriP, posteriorP = Bayes_train(X_small, Y_small, m)
_, accuracy = Bayes_pret(X_test, Y_test, prioriP, posteriorP)
print('clf accuracy (ours with m =', m, '): ', accuracy)

# sklearn examples
from sklearn.naive_bayes import MultinomialNB
clf0 = MultinomialNB()
clf0.fit(X_small, Y_small)
accuracy0 = clf0.score(X_test, Y_test)
print('clf accuracy (sklearn MultinomialNB):', accuracy0)

from sklearn.naive_bayes import GaussianNB
clf1 = GaussianNB()
clf1.fit(X_small, Y_small)
accuracy1 = clf1.score(X_test, Y_test)
print('clf accuracy (sklearn GaussianNB):', accuracy1)

from sklearn.naive_bayes import ComplementNB
clf2 = ComplementNB()
clf2.fit(X_small, Y_small)
accuracy2 = clf2.score(X_test, Y_test)
print('clf accuracy (sklearn ComplementNB):', accuracy2)