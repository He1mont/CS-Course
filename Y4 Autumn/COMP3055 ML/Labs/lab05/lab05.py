from sklearn.cluster import KMeans
import matplotlib.pyplot as plt
import numpy as np

# Load data
data = np.load('../data/mnist.npz', allow_pickle=True)
tr_feats, tr_label = data['x_train'][:1000], data['y_train'][:1000]
te_feats, te_label = data['x_test'][:1000], data['y_test'][:1000]

############ Apply k-means on training set ############
kmeans = KMeans(n_clusters=10).fit(tr_feats)
# kmeans.labels_ = tr_label     # 给不给label对结果没有影响
centers = np.reshape(kmeans.cluster_centers_, (10, 28, 28))

plt.figure()
for i in range(10):
    plt.subplot(3, 4, i+1)
    plt.imshow(centers[i])
plt.show()

############ Visualize label histogram of one cluster ############
y_cluster = kmeans.predict(te_feats)
y_cluster1 = [te_label[i]   for i in range(len(te_label)) if y_cluster[i] == 0]     # 找到所有被预测出来为0的图片的实际标签
print(y_cluster)
print(y_cluster1)

plt.hist(y_cluster1, [i for i in range(10)])        # 把这些图片的实际标签用直方图显示出来
plt.show()
