import numpy as np
from matplotlib import pyplot as plt
from sklearn.datasets import fetch_openml
from sklearn.neighbors import KNeighborsClassifier

'''
    Task 1: Play with MNIST
'''

X, y = fetch_openml('mnist_784', data_home='./', return_X_y=True)
X = X / 255.

# sub-task2: save the first 1000 data in both X and y using savez
#			 load the saved file in the subsequent running using load

X_small = X[:1000]
y_small = y[:1000]
X_small = X_small.values
y_small = y_small.values

np.savez('1k.npz', X_small=X_small, y_small=y_small)



'''
    Task 2: solve handwritten digit recognition by instance based learning technique (KNN)
'''

data = np.load('1k.npz', allow_pickle=True)
X_small = data['X_small']
y_small = data['y_small']
index = np.nonzero(y_small == '2')[0]       # 找到label里所有值为2的下标
te_feats = [X_small[i] for i in index]      # 训练集里所有表示为2的样本

knn = KNeighborsClassifier(n_neighbors=2)
knn.fit(X_small, y_small)  # Fit the model using X_small as training data and y_small as target values
prediction = knn.predict(te_feats)  # Predict the class labels for te_feats (i.e. first 99 images of digit 2)
print(prediction)