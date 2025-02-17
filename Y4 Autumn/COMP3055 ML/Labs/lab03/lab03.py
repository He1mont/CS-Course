import numpy as np
from matplotlib import pyplot as plt
from sklearn.neighbors import KNeighborsClassifier
from sklearn.datasets import fetch_openml
from sklearn.model_selection import cross_val_score
from sklearn.metrics import confusion_matrix, accuracy_score, f1_score

########################## Task 1 ########################## 
"""
    te_feats: 测试样本集
    tr_feat, tr_label: 训练集和label
"""
def myknn(te_feats, tr_feats, tr_label, k):
    output = []
    for image in te_feats:
        dist = [np.linalg.norm(np.array(image) - np.array(train)) for train in tr_feats]
        indices = np.argsort(np.array(dist))[:k]    # 找到dist列表里数据最小的k个值的下标
        labels = [tr_label[i] for i in indices]     # 找到距离最小的k个图片对应的label

        # 找到label里出现次数最多的那个返回
        unique_elements, counts = np.unique(np.array(labels), return_counts=True)    
        most_common_index = np.argmax(counts)
        most_common_element = unique_elements[most_common_index]

        output.append(most_common_element) 
    return np.array(output)

########################## Task 2 ########################## 
def getMetrics(preds, labels):
    TP = np.zeros(10, dtype=int)
    FP = np.zeros(10, dtype=int)
    TN = np.zeros(10, dtype=int)
    FN = np.zeros(10, dtype=int)

    for i in range(10):
        TP[i] = np.sum((preds == str(i)) & (labels == str(i)))
        FP[i] = np.sum((preds == str(i)) & (labels != str(i)))
        TN[i] = np.sum((preds != str(i)) & (labels != str(i)))
        FN[i] = np.sum((preds != str(i)) & (labels == str(i)))

    return TP, FP, TN, FN

def calErrorRate(preds, labels):
    TP, FP, _, _ = getMetrics(preds, labels)
    precision = 0
    for i in range(10):
        precision += TP[i] / (TP[i] + FP[i])    if TP[i] + FP[i] > 0 else 0
    return 1 - precision / 10

def plotFigure(errorList):
    x_axis = [i+1   for i in range(9)]
    plt.figure()
    plt.plot(x_axis, errorList, marker='o', linestyle='-', color='b')
    plt.title('Error Rate vs k')
    plt.grid(True)
    plt.show()

def findBestK(iter_num, fold_num, feats, label):
    fold_size = len(feats) // fold_num   # 200
    errorList = []
    
    for k in range(iter_num):
        errorRate = 0
        for i in range(5):
            # Split training datas
            te_feats = feats[fold_size*i : fold_size*(i+1)]
            te_label = label[fold_size*i : fold_size*(i+1)]
            tr_feats = np.concatenate((feats[0:fold_size*i], feats[fold_size*(i+1):]))
            tr_label = np.concatenate((label[0:fold_size*i], label[fold_size*(i+1):]))
            # Apply knn and calculate error rate
            predict = myknn(te_feats, tr_feats, tr_label, k+1)
            errorRate += calErrorRate(predict, te_label)
        errorList.append(errorRate/5)

    plotFigure(errorList)
    return np.argsort(np.array(errorList))[0]+1    # 返回errorList里数值最小的下标，即k

########################## Task 3 ########################## 
# def calF1Score(preds, labels):
#     TP, FP, _, FN = getMetrics(preds, labels)
#     F1 = np.zeros(10, dtype=float)
#     for i in range(10):
#         precision = TP[i] / (TP[i] + FP[i])    if TP[i] + FP[i] > 0 else 0
#         recall    = TP[i] / (TP[i] + FN[i])    if TP[i] + FN[i] > 0 else 0
#         F1[i] = 2 * (precision * recall) / (precision + recall)
#     return F1

def eval_myknn(te_feats, te_label, tr_feats, tr_label, best_k):
    knn = KNeighborsClassifier(n_neighbors=best_k)
    knn.fit(tr_feats, tr_label)
    te_pred = knn.predict(te_feats)
    
    # te_pred = myknn(te_feats, tr_feats, tr_label, best_k)
    print('f1_score: ')
    print(f1_score(te_label, te_pred, average='macro'))       
    print('-----------------------')
    print('Confusion_matrix: ')
    print(confusion_matrix(te_label, te_pred))    

########################## Task 4 ########################## 
def findBestK_Auto(iter_num, fold_num, tr_feats, tr_label):
    errorList = []

    for k in range(iter_num):
        knn = KNeighborsClassifier(n_neighbors=k+1)
        accuracy = cross_val_score(knn, tr_feats, tr_label, cv=fold_num, scoring='accuracy')     # A list of accuracies of 5 folders
        errorList.append(1 - accuracy.mean())
    plotFigure(errorList)
    return np.argsort(np.array(errorList))[0]+1    # 返回errorList里数值最小的下标，即k


def main():
    # Hyper-param setting
    iter_num = 9
    fold_num  = 5

    # Load MNIST Dataset
    # X, y = fetch_openml('mnist_784', data_home='../', return_X_y=True)  # fetch data using fetch_openml function
    # X = X.values  # Extract X values (from DataFrame to Numpy array)
    # y = y.values  # Extract Y values (from DataFrame to Numpy array)
    # tr_feats = X[:1000]
    # tr_label = y[:1000]
    # te_feats = X[-10000:]
    # te_label = y[-10000:]
    data = np.load('../data/mnist.npz', allow_pickle=True)
    tr_feats, tr_label = data['x_train'][:1000], data['y_train'][:1000]
    te_feats, te_label = data['x_test'][:], data['y_test'][:]


    # Task 1 and 2
    k1 = findBestK(iter_num, fold_num, tr_feats, tr_label)

    # Task 3
    eval_myknn(te_feats, te_label, tr_feats, tr_label, k1)

    # Task 4
    k2 = findBestK_Auto(iter_num, fold_num, tr_feats, tr_label)

    """
    myKnn和调库计算出来的knn数值不同 是因为底层对距离的计算有差异 是正常的
    """

if __name__ == "__main__":
    main()

