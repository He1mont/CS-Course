from sklearn.datasets import fetch_openml 
import numpy as np
import matplotlib.pyplot as plt

# 储存 X_small, y_small 到 ../1k.npz
# X, y = fetch_openml('mnist_784', data_home='../', return_X_y=True)
# X_small = X[:1000]
# y_small = y[:1000]
# np.savez('../data/lab02_1k.npz', X_small, y_small)

# x_train = X.values[:60000]
# y_train = y.values[:60000]
# x_test  = X.values[60000:]
# y_test  = y.values[60000:]
# np.savez('../data/mnist.npz', x_train=x_train, y_train=y_train, x_test=x_test,  y_test=y_test)


# Load Data from npz
data = np.load('../data/lab02_1k.npz', allow_pickle=True)
new_X = data['arr_0'].reshape(-1, 28, 28)   # Reshape X for imshow
new_y = data['arr_1']           
print(type(new_y))          # NumPy nd-array

# 统计这1000张里每个digit分别有几个
num_of_sample = []
for i in range(10):
    num_of_sample.append(len(np.nonzero(new_y == str(i))[0]))
print(num_of_sample)

# 找到label里所有为'2'的数据的下标，并返回一个list，长度为99
index = np.nonzero(new_y == '2')[0]

# 画图
plt.figure()
for i in range(len(index)):
    plt.subplot(9, 11, i + 1)           # 9行11列第i+1个位置
    plt.imshow(new_X[index[i]], cmap='gray')
    plt.xticks([]), plt.yticks([])      # 传递空列表[]，隐藏xy轴上的刻度
plt.tight_layout()
plt.show()


