import matplotlib.pyplot as plt
import numpy as np
from sklearn.datasets import fetch_openml

X, y = fetch_openml('mnist_784', data_home='../', return_X_y=True)                               # download the data
X = X / 255.                                                                                    # do data normalization

# it creates mldata folder in your root project folder
# rescale the data, use the traditional train/test split
# X_train, X_test = X[:60000], X[60000:]                                                        
# y_train, y_test = y[:60000], y[60000:]
X_small = X[:1000]                                                                              # obtain the first thousand data
y_small = y[:1000]                                                                              # obtain the first thousand label

print(X_small.shape)

print(len(np.nonzero(y_small.values.astype('int') == 0)[0]))


# display the first 10 digits in the training set
plt.figure()                                                                            
for i in range(10):                                                                             # draw 10 pictures
    plt.subplot(2, 5, i+1)                                                                      # set the subplot id
    plt.imshow(X_small.loc[i].values.reshape((28, 28)), cmap='gray')                            # convert the one dimentional data into two dimentional image
    plt.xticks([]), plt.yticks([])                                                              # delete the x axis and y axis scale
plt.show()


num_of_sample = []
for i in range(10):
    num_of_sample.append(len(np.nonzero(y_small.values.astype('int') == i)[0]))                 # count the number of sampled per category       

# If you want to display all the samples for a specific digit (take '2' for example), the
# following command might help:

plt.figure()
index = np.nonzero(y_small.values.astype('int') == 2)[0]                                       # count the total number of image with label == 2
    
for i in range(len(index)):                                                                     # draw the image in size of 11*11
    plt.subplot(11, 11, i+1)
    plt.imshow(X_small.loc[index[i]].values.reshape(28, 28), cmap='gray')
    plt.xticks([]), plt.yticks([])                                                              # delete the axis scale
plt.show()


X_small_norm = np.zeros(X_small.values.shape)                                                   # normalization -- x = (x-mean(x)) / std(x)
for i in range(X_small.shape[0]):
    X_small_norm[i, :] = (X_small.loc[i].values - np.mean(X_small.loc[i].values)) / np.std(X_small.loc[i].values)   #normalization equation