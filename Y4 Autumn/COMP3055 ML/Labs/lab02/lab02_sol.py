import numpy as np
from matplotlib import pyplot as plt
from sklearn.datasets import fetch_openml
from sklearn.neighbors import KNeighborsClassifier

'''
    Task 1: Play with MNIST
'''

X, y = fetch_openml('mnist_784', data_home='./', return_X_y=True)
X = X / 255

# sub-task2: save the first 1000 data in both X and y using savez
#			 load the saved file in the subsequent running using load

X_small = X[:1000]
y_small = y[:1000]
X_small = X_small.values
y_small = y_small.values

np.savez('1k.npz', X_small=X_small, y_small=y_small)

'''
	Example: load compressed data again

	data = np.load('1k.npz')
	X_small = data['X_small']
	y_small = data['y_small']
'''

# sub-task3: count the number of images for each class
index = np.nonzero(y_small == '2')[0]

row = 9
column = 11
counter = 0

for _ in range(row):
    for _ in range(column):
        plt.subplot(row, column, counter + 1)
        x = X_small[index[counter]]  # retrieve img feature by index
        x = x.reshape(28, 28)  # reshape x from vector to matrix
        plt.imshow(x, cmap='gray')
        plt.xticks([])
        plt.yticks([])
        counter += 1
plt.show()
