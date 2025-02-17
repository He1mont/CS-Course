'''
Sample solution for Lab COMP3055 UNNC
Environments:   Python = 3.7.4
                numpy = 1.19.1
                scikit-learn = 0.21.3
                matplotlib = 3.1.1
'''

import numpy as np
from sklearn.decomposition import PCA
from sklearn.neighbors import KNeighborsClassifier
import matplotlib.pyplot as plt

# Load data
# data = np.load('mnist.npz')
# x_train,y_train,x_test,y_test = data['x_train'], data['y_train'], data['x_test'],data['y_test']

# X_small = np.reshape(x_train[0:1000], (1000,784))
# Y_small = y_train[0:1000]
# X_test = np.reshape(x_test[0:1000], (1000,784))
# Y_test = y_test[0:1000]

# Load data from my MNIST
data = np.load('../data/mnist.npz', allow_pickle=True)
tr_feats, tr_label = data['x_train'][:1000], data['y_train'][:1000]
te_feats, te_label = data['x_test'][:1000], data['y_test'][:1000]
X_small, Y_small, X_test, Y_test = tr_feats, tr_label, te_feats, te_label


######################## Task 1 ########################
# apply PCA to reduce feature information
pca = PCA(n_components=28) # you can try different value here
X_small_trans = pca.fit_transform(X_small)
X_test_trans = pca.transform(X_test)
print('Information kept: ', sum(pca.explained_variance_ratio_)*100, '%')
print('Noise variance: ', pca.noise_variance_)

# compare predict score before & after PCA 
knn0 = KNeighborsClassifier(n_neighbors=3)
knn0.fit(X_small, Y_small)
print('KNN score before PCA: ', knn0.score(X_test, Y_test))

knn1 = KNeighborsClassifier(n_neighbors=3)
knn1.fit(X_small_trans, Y_small)
print('KNN score after PCA: ', knn1.score(X_test_trans, Y_test))


######################## Task 2 ########################

X_small_trains_reconst = pca.inverse_transform(X_small_trans)   # reconstruction

plt.figure()
for i in range(10):
    plt.subplot(3,4,i+1)
    plt.imshow(np.reshape(X_small_trains_reconst[i],(28,28)), cmap=plt.cm.gray)
plt.savefig("X_reconstruct.png")
plt.show()

plt.figure()
for i in range(10):
    plt.subplot(3,4,i+1)
    plt.imshow(np.reshape(X_small[i],(28,28)), cmap=plt.cm.gray)
plt.savefig("X_origin.png")
plt.show()