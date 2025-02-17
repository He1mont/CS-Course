import numpy as np
from sklearn.metrics import f1_score, accuracy_score
from collections import Counter
import math
from lab04_sol import Bayes_pret

def data_loader():
    data = np.load('../data/mnist.npz', allow_pickle=True)
    x_train, y_train, x_test, y_test = data['x_train'], data['y_train'], data['x_test'], data['y_test']
    y_train = y_train.astype(int)       # 这两行不加会报错
    y_test = y_test.astype(int)

    tr_feats = np.reshape(x_train[:1000], (1000, 784))
    tr_label = y_train[:1000]
    te_feats = np.reshape(x_test[:100], (100, 784))
    te_label = y_test[:100]
    return tr_feats, tr_label, te_feats, te_label

# Return the predict label for an image

def bayes_train(tr_feats, tr_label, m):
    # Calculate Priority Probability: P(d)
    num_total = tr_feats.shape[0]
    num_per_label = Counter(tr_label)
    priorP = [num_per_label[i] / num_total  for i in range(10)]

    # Calculate Posterior Probability: P(X|d) = P(x1|d) * P(x2|d) * ...
    # P(xi|d) = label d里所有第i个pixel值为xi的图片数量 / label d的图片数量
    # Trick 1: 不用离散的数量比值来代表概率，而是用归一化之后的intensity value的总和/数量来代表概率
    # Trick 3: 将所有的pixel value二分化，只考虑0和非0的情况，这样子可以避免数数所造成的计算上的复杂度
    # 这里的posteriorP[i][j]代表给定label i，给定pixel j，如果x_j是非零数值，x_j属于label i的概率
    posteriorNum = np.empty((10, tr_feats.shape[1])) 
    posteriorP = np.empty((10, tr_feats.shape[1]))
    for i in range(10):
        posteriorNum[i] = tr_feats[np.where(tr_label == i)].sum(axis=0)     # .sum(axis=0) 对于每一个pixel进行sum
        posteriorP[i] = (posteriorNum[i] / 255 + m/255) / (num_per_label[i] + m)    # /255 为了归一化处理
    return priorP, posteriorP

def bayes_predict(te_feats, te_label, priorP, posteriorP):
    predict = np.empty(te_feats.shape[0])
    for i in range(te_feats.shape[0]):          # i 遍历每一个图片
        prob = [math.log(priorP[ii]) for ii in range(10)]
        for j in range(10):                     # j 遍历每一个label
            for k in range(te_feats.shape[1]):  # k 遍历每一个pixel
                prob[j] += math.log(posteriorP[j][k])  if te_feats[i][k] > 0 else math.log(1-posteriorP[j][k])
        predict[i] = np.argmax(prob)
        # print(prob)
    return predict

def my_bayes(te_feats, te_label, tr_feats, tr_label, m):
    # Param Setting
    d = np.zeros(10, dtype=object)      # d[i]表示label是i的图片在训练集中的索引
    for i in range(10):
        d[i] = np.nonzero(tr_label == i)[0]
    num_feats = len(tr_feats[0])
    P = 1 / num_feats
    mP = m * P
    denominators = [len(d[i]) + m  for i in range(10)]

    # Apply Model
    predict = []
    for image in te_feats:
        prob = [np.log(len(d[i]) / tr_label.shape[0])  for i in range(10)]  # Priority Probability
        for i in range(10):
            for j in range(num_feats):
                n_c = np.sum(image[j] == tr_feats[d[i], j])
                prob[i] += np.log((n_c + mP) / denominators[i])         # Posterior Probability using m-measure
        predict.append(np.argmax(prob))
    return predict

def main():
    # m = 3
    m = 10
    tr_feats, tr_label, te_feats, te_label = data_loader()
    priorP, posteriorP = bayes_train(tr_feats, tr_label, m)

    pred1 = bayes_predict(te_feats, te_label, priorP, posteriorP)
    pred2, _ = Bayes_pret(te_feats, te_label, priorP, posteriorP)
    pred3 = my_bayes(te_feats, te_label, tr_feats, tr_label, m)

    acc1 = f1_score(te_label, pred1, average="macro")
    acc2 = f1_score(te_label, pred2, average="macro")
    acc3 = f1_score(te_label, pred3, average="macro")
    print(f'acc1 = {acc1}, acc2 = {acc2}, acc3 = {acc3}')

    
if __name__ == "__main__":
    main()