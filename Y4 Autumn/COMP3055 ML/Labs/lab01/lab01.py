from sklearn.datasets import fetch_openml 
import matplotlib.pyplot as plt

X, y = fetch_openml('mnist_784', data_home='../', return_X_y=True)
# X = X / 255

print(f'X size = {X.size}, y size = {y.size}')      # 784*70,000, 70,000
print(f'X dim  = {X.ndim}, y dim =  {y.ndim}')      # 2, 1

# Subset of first 1000
new_X = X[:1000]
new_y = y[:1000]

print(f'X size = {new_X.size}, y size = {new_y.size}')      # 784*1000, 1000
print(f'X dim  = {new_X.ndim}, y dim =  {new_y.ndim}')      # 2, 1

# Pandas dataframes to NumPy
new_X = new_X.values.reshape(-1, 28, 28)    

plt.figure()

for i in range(10):
    plt.subplot(2, 5, i + 1)        # 2行5列第i+1个位置
    plt.imshow(new_X[i], cmap='gray')
    plt.title(f"Label: {new_y[i]}") # 设置标题为相应的标签
    plt.xticks([]), plt.yticks([])  # 传递空列表[]，隐藏xy轴上的刻度

plt.tight_layout()
plt.show()