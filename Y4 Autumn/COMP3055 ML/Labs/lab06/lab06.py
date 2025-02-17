import numpy as np
from sklearn.decomposition import PCA
from sklearn.neighbors import KNeighborsClassifier
import matplotlib.pyplot as plt

# Load Data
data = np.load('../data/mnist.npz', allow_pickle=True)
tr_feats, tr_label = data['x_train'][:1000], data['y_train'][:1000]
te_feats, te_label = data['x_test'][:1000], data['y_test'][:1000]

########################## Task 1 ##########################
print(tr_feats.shape)
pca = PCA(n_components=28)      
tr_feats_trans = pca.fit_transform(tr_feats)        # fit_transform 相当于knn里的fit
te_feats_trans = pca.transform(te_feats)            # tranform 相当于knn里的predict
print('Information kept: ', sum(pca.explained_variance_ratio_)*100, '%')
print('Noise variance: ', pca.noise_variance_)      # 越大的噪声方差 信息丢失越严重

# Use tr_trans for training and te_trans for testing
knn0 = KNeighborsClassifier(n_neighbors=3)
knn1 = KNeighborsClassifier(n_neighbors=3)

knn0.fit(tr_feats, tr_label)
print('KNN score before PCA: ', knn0.score(te_feats, te_label))

knn1.fit(tr_feats_trans, tr_label)
print('KNN score after PCA: ', knn1.score(te_feats_trans, te_label))


########################## Task 2 ##########################

tr_feats_trans_reconst = pca.inverse_transform(tr_feats_trans)   # Reconstruction

plt.figure()
for i in range(10):     # 只显示前面10张
    plt.subplot(3,4,i+1)
    plt.imshow(np.reshape(tr_feats_trans_reconst[i],(28,28)), cmap=plt.cm.gray)
plt.savefig("X_reconstruct.png")
plt.show()

plt.figure()
for i in range(10):
    plt.subplot(3,4,i+1)
    plt.imshow(np.reshape(tr_feats[i],(28,28)), cmap=plt.cm.gray)
plt.savefig("X_origin.png")
plt.show()
