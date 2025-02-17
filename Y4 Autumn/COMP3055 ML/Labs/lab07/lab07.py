import numpy as np

class Perceptron:
    def __init__(self, num_weight, num_epoch=100, lr=0.01):
        self.num_weight = num_weight
        self.num_epoch = num_epoch
        self.lr = lr
        self.weights = np.zeros(num_weight)
        self.bias = 0

    @staticmethod   # 这个是静态函数，带self的都是实例函数
    def activation(input):  return 1 if input > 0 else 0        # sign

    def forward(self, tr_feats):
        return [Perceptron.activation(np.dot(feat, self.weights) + self.bias)
                                               for feat in tr_feats]

    # Use batch mode to update weights
    def update_batch_mode(self, tr_feats, tr_label, output):
        # Update weights:
        for i in range(self.num_weight):
            tmp = 0
            for k in range(len(tr_label)):
                tmp += tr_feats[k][i] * (tr_label[k] - output[k])
            self.weights[i] += self.lr * tmp
        # Update bias
        tmp = 0
        for k in range(len(tr_label)):
            tmp += (tr_label[k] - output[k])
        self.bias += self.lr * tmp
        
    # Use online mode to update weights
    def update_online_mode(self, tr_feats, tr_label, output):
        for k in range(len(tr_label)):
            diff = tr_label[k] - output[k]
            self.bias += self.lr * diff      # update bias
            for i in range(self.num_weight):   # update weights
                self.weights[i] += diff * tr_feats[k][i]

    def train(self, tr_feats, tr_label):
        for _ in range(self.num_epoch):
            output = self.forward(tr_feats)
            self.update_batch_mode(tr_feats, tr_label, output)
            # self.update_online_mode(tr_feats, tr_label, output)
            # print(f'Epoch #{i}:\t weights = {self.weights}\tbias = {self.bias}')
        print(f'weights = {self.weights}\tbias = {self.bias}')

    def predict(self, feature):
        return Perceptron.activation(np.dot(feature, self.weights) + self.bias)

class ADLINE:
    def __init__(self, num_weight, num_epoch=100, lr=0.01, batch_mode=True):
        self.num_weight = num_weight
        self.num_epoch = num_epoch
        self.lr = lr
        self.batch_mode = batch_mode
        self.weights = np.zeros(num_weight)
        self.bias = 0

    @staticmethod
    def activation(input): return input            # NO activation
    
    def forward(self, tr_feats):
        return [ADLINE.activation(np.dot(feat, self.weights) + self.bias)
                                    for feat in tr_feats]

    # Use batch mode to update weights
    def update_batch_mode(self, tr_feats, tr_label, output):
        # Update weights:
        for i in range(self.num_weight):
            tmp = 0
            for k in range(len(tr_label)):
                tmp += tr_feats[k][i] * (tr_label[k] - output[k])
            self.weights[i] += self.lr * tmp
        # Update bias
        tmp = 0
        for k in range(len(tr_label)):
            tmp += (tr_label[k] - output[k])
        self.bias += self.lr * tmp
        
    # Use online mode to update weights
    def update_online_mode(self, tr_feats, tr_label, output):
        for k in range(len(tr_label)):
            diff = tr_label[k] - output[k]
            self.bias += self.lr * diff      # update bias
            for i in range(self.num_weight):   # update weights
                self.weights[i] += diff * tr_feats[k][i]

    def train(self, tr_feats, tr_label):
        for _ in range(self.num_epoch):
            output = self.forward(tr_feats)
            self.update_batch_mode(tr_feats, tr_label, output)
            # self.update_online_mode(tr_feats, tr_label, output)
            # print(f'Epoch #{i}:\t weights = {self.weights}\tbias = {self.bias}')
        print(f'weights = {self.weights}\tbias = {self.bias}')

    def predict(self, feature):
        out = np.dot(feature, self.weights) + self.bias
        return 1 if out > 0.5 else 0


# Dataset Init
feats = [[0,0], [0,1], [1,0], [1,1]]
AND_label = [0, 0, 0, 1]
OR_label  = [0, 1, 1, 1]

# flag = True 代表用Perceptron，False代表ADLINE，区别在于有没有activation function
print('--------------- Perceptron in Batch Mode ---------------')
lr, num_epoch = 0.1, 50

and_perceptron = Perceptron(num_weight=2, num_epoch=num_epoch, lr=lr)
and_perceptron.train(feats, AND_label)
print(f'input = {[1,1]}, output = {and_perceptron.predict([1, 1])}')
print(f'input = {[1,0]}, output = {and_perceptron.predict([1, 0])}')
print(f'input = {[0,1]}, output = {and_perceptron.predict([0, 1])}')
print(f'input = {[0,0]}, output = {and_perceptron.predict([0, 0])}')

or_perceptron = Perceptron(num_weight=2, num_epoch=num_epoch, lr=lr)
or_perceptron.train(feats, OR_label)
print(f'input = {[1,1]}, output = {or_perceptron.predict([1, 1])}')
print(f'input = {[1,0]}, output = {or_perceptron.predict([1, 0])}')
print(f'input = {[0,1]}, output = {or_perceptron.predict([0, 1])}')
print(f'input = {[0,0]}, output = {or_perceptron.predict([0, 0])}')


print('--------------- ADLINE in Batch Mode ---------------')
and_adline = ADLINE(num_weight=2)
and_adline.train(feats, AND_label)
print(f'input = {[1,1]}, output = {and_adline.predict([1, 1])}')
print(f'input = {[1,0]}, output = {and_adline.predict([1, 0])}')
print(f'input = {[0,1]}, output = {and_adline.predict([0, 1])}')
print(f'input = {[0,0]}, output = {and_adline.predict([0, 0])}')

or_adline = ADLINE(num_weight=2)
or_adline.train(feats, OR_label)
print(f'input = {[1,1]}, output = {or_adline.predict([1, 1])}')
print(f'input = {[1,0]}, output = {or_adline.predict([1, 0])}')
print(f'input = {[0,1]}, output = {or_adline.predict([0, 1])}')
print(f'input = {[0,0]}, output = {or_adline.predict([0, 0])}')


print('--------------- ADLINE in Online Mode ---------------')
and_adline_online = ADLINE(num_weight=2, batch_mode=False)
and_adline_online.train(feats, AND_label)
print(f'input = {[1,1]}, output = {and_adline_online.predict([1, 1])}')
print(f'input = {[1,0]}, output = {and_adline_online.predict([1, 0])}')
print(f'input = {[0,1]}, output = {and_adline_online.predict([0, 1])}')
print(f'input = {[0,0]}, output = {and_adline_online.predict([0, 0])}')

or_adline_online = ADLINE(num_weight=2, batch_mode=False)
or_adline_online.train(feats, OR_label)
print(f'input = {[1,1]}, output = {or_adline_online.predict([1, 1])}')
print(f'input = {[1,0]}, output = {or_adline_online.predict([1, 0])}')
print(f'input = {[0,1]}, output = {or_adline_online.predict([0, 1])}')
print(f'input = {[0,0]}, output = {or_adline_online.predict([0, 0])}')


