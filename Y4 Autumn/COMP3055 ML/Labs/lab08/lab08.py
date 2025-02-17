import numpy as np
import matplotlib.pyplot as plt
import seaborn as sns

from sklearn.neural_network import MLPClassifier 
from sklearn.metrics import accuracy_score, confusion_matrix

# Load data
data = np.load('../data/mnist.npz', allow_pickle=True)
tr_feats, tr_label = data['x_train'][:1000], data['y_train'][:1000]
te_feats, te_label = data['x_test'][:1000], data['y_test'][:1000]

######################## Task 1&3 ########################
feat_size =28*28
mlp = MLPClassifier(hidden_layer_sizes=(feat_size*2, feat_size), max_iter=100, alpha=1e-4, solver='sgd', 
                    verbose=10, tol=1e-4, random_state=1,learning_rate_init=.001) 
mlp.fit(tr_feats, tr_label)
output = mlp.predict(te_feats)

print(f'Accuracy Score: {accuracy_score(te_label, output)}')
print(f'Confusion Matrix:\n {confusion_matrix(te_label, output)}')


######################## Task 2 ########################
index_2 = np.nonzero(te_label == '2')[0]
index_5 = np.nonzero(te_label == '5')[0]
feat_2 = [te_feats[i]   for i in index_2]
feat_5 = [te_feats[i]   for i in index_5]

pred_2 = mlp.predict(feat_2)
pred_5 = mlp.predict(feat_5)

print(f'Accuracy Score for digit 2: {accuracy_score(['2']*len(index_2), pred_2)}')
print(f'Accuracy Score for digit 5: {accuracy_score(['5']*len(index_5), pred_5)}')


######################## Task 4 ########################
for i, weights in enumerate(mlp.coefs_):
    plt.figure(figsize=(10, 5))
    sns.heatmap(weights, cmap='viridis')
    plt.title(f'Layer {i + 1} Weights')
    plt.xlabel('Neurons in Layer {}'.format(i + 1))
    plt.ylabel('Neurons in Layer {}'.format(i))
    plt.show()

