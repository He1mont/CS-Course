'''
2021/11/25
Sample solution for Lab8 COMP3055 UNNC
Environments:	Python = 3.7.4
		numpy = 1.19.1
		scikit-learn = 0.21.3
		matplotlib = 3.1.1
'''

# load data from local file, fetch_openml() also works
import numpy as np
from sklearn.neural_network import MLPClassifier
import matplotlib.pyplot as plt


data = np.load('mnist.npz')
x_train,y_train,x_test,y_test = data['x_train'], data['y_train'], data['x_test'],data['y_test']

X_small = np.reshape(x_train[0:1000], (1000,784))
Y_small = y_train[0:1000]
X_test = np.reshape(x_test[0:1000], (1000,784))
Y_test = y_test[0:1000]
print('data load finish')


# apply MLP classifier
mlp = MLPClassifier(hidden_layer_sizes=(1024,),max_iter=1000,solver='adam',verbose=10,learning_rate_init=0.001)
mlp.fit(X_small, Y_small)
print('MLP accuracy:', mlp.score(X_test, Y_test))


# visualize weights as matrix
fig, axes = plt.subplots(4, 4)
# use global min / max to ensure all weights are shown on the same scale
vmin, vmax = mlp.coefs_[0].min(), mlp.coefs_[0].max()
for coef, ax in zip(mlp.coefs_[0].T, axes.ravel()):
    ax.matshow(coef.reshape(28, 28), cmap=plt.cm.gray, vmin=.5 * vmin, vmax=.5 * vmax)
    ax.set_xticks(())
    ax.set_yticks(())
plt.show()