'''
2021/11/18
Sample solution for Lab7 COMP3055 UNNC
Environments:	Python = 3.7.4
		numpy = 1.19.1
'''

from functools import reduce

class Perceptron(object):
    def __init__(self, input_num, activator):
        self.activator = activator
        self.weights = [0.0 for _ in range(input_num)]
        self.bias = 0.0

    def predict(self, input_vec):
        return self.activator(
            reduce(lambda a, b: a + b,
                   list(map(lambda tp: tp[0] * tp[1], zip(input_vec, self.weights))), 0.0) + self.bias)
        
    def train(self, input_vecs, labels, iteration, rate):
        for i in range(iteration):
            self._one_iteration(input_vecs, labels, rate)

    def _one_iteration(self, input_vecs, labels, rate):
        samples = zip(input_vecs, labels)
        for (input_vec, label) in samples:
            output = self.predict(input_vec)
            self._update_weights(input_vec, output, label, rate)

    def _update_weights(self, input_vec, output, label, rate):
        delta = label - output
        self.weights = list(map( lambda tp: tp[1] + rate * delta * tp[0], zip(input_vec, self.weights)) )
        self.bias += rate * delta
        #print("label - output = delta:" ,label, output, delta)
        #print("weights ", self.weights)
        #print("bias", self.bias)

def f(x):
    #activate func
    return 1 if x > 0.5 else 0

def train_and_perceptron(iteration, rate):
    p = Perceptron(2, f)
    input_vecs, labels = [[1,1], [0,0], [1,0], [0,1]], [1, 0, 0, 0]
    p.train(input_vecs, labels, iteration, rate)
    return p

def train_or_perceptron(iteration, rate):
    p = Perceptron(2, f)
    input_vecs, labels = [[1,1], [0,0], [1,0], [0,1]], [1, 0, 1, 1]
    p.train(input_vecs, labels, iteration, rate)
    return p
	
iteration = 10
learning_rate = 0.25
and_perception = train_and_perceptron(iteration, learning_rate)
or_perception = train_or_perceptron(iteration, learning_rate)

print('Perceptron result:')
print ('1 and 1 = %d' % and_perception.predict([1, 1]))
print ('0 and 0 = %d' % and_perception.predict([0, 0]))
print ('1 and 0 = %d' % and_perception.predict([1, 0]))
print ('0 and 1 = %d' % and_perception.predict([0, 1]))
print ('1 or 1 = %d' % or_perception.predict([1, 1]))
print ('0 or 0 = %d' % or_perception.predict([0, 0]))
print ('1 or 0 = %d' % or_perception.predict([1, 0]))
print ('0 or 1 = %d' % or_perception.predict([0, 1]))


import numpy as np

class AdlineGD(object):
    """AdlineGD Classifier"""
    def __init__(self,eta=0.25,n_iter=10):
        self.eta = eta
        self.n_iter = n_iter

    def fit(self,X,y):
        self.w_ = np.zeros(X.shape[1])
        self.b_ = np.zeros(1)
        self.cost_ = []

        for _ in range(self.n_iter):
            output = self.net_input(X)
            errors = y - output
            cost = (errors**2).sum()/2.0
            self.cost_.append(cost)
            self.w_ += self.eta * np.dot(X.T,errors)
            self.b_ += self.eta * errors.sum()
        return self

    def net_input(self,x):
        return np.dot(x,self.w_) + self.b_

    def activation(self,x):
        return self.net_input(x)

    def predict(self,x):
        return np.where(self.activation(x) > 0.5, 1, 0)

or_adline = AdlineGD()
or_adline.fit(np.array([[1,1], [0,0], [1,0], [0,1]]), [1, 0, 1, 1])

and_adline = AdlineGD()
and_adline.fit(np.array([[1,1], [0,0], [1,0], [0,1]]), [1, 0, 0, 0])

print ('ADLINE result:')
print ('1 and 1 = %d' % and_adline.predict([1, 1]))
print ('0 and 0 = %d' % and_adline.predict([0, 0]))
print ('1 and 0 = %d' % and_adline.predict([1, 0]))
print ('0 and 1 = %d' % and_adline.predict([0, 1]))
print ('1 or 1 = %d' % or_adline.predict([1, 1]))
print ('0 or 0 = %d' % or_adline.predict([0, 0]))
print ('1 or 0 = %d' % or_adline.predict([1, 0]))
print ('0 or 1 = %d' % or_adline.predict([0, 1]))