# Created by Ziling Wu
# Supervised by Dr Armaghan Moemeni
# Last Updated: December 4th, 2023


import torch.nn as nn


class ToyModel(nn.Module):
    def __init__(self):
        super(ToyModel, self).__init__()
        # create two convolutional layers
        self.conv1 = nn.Conv2d(in_channels=1, out_channels=8, kernel_size=5)
        self.conv2 = nn.Conv2d(in_channels=8, out_channels=16, kernel_size=5)
        # create a max pooling layer
        self.pooling = nn.MaxPool2d(kernel_size=2, stride=2)
        # create an activation function layer
        self.relu = nn.ReLU()
        # create fully connected layers
        self.FC1 = nn.Linear(in_features=16*4*4, out_features=64)
        self.FC2 = nn.Linear(in_features=64, out_features=32)
        # create classification head
        self.cls = nn.Linear(in_features=32, out_features=10)

    def forward(self, x):
        # conv layer 1
        x = self.conv1(x)
        # activation
        x = self.relu(x)
        # max pooling
        x = self.pooling(x)
        # conv layer 2
        x = self.conv2(x)
        # activation
        x = self.relu(x)
        # max pooling
        x = self.pooling(x)
        # reshape the output of the last step to the shape of the next fully connected layer's input
        x = x.reshape(x.size(0), 16*4*4)   # batch size, in_features, out_features
        # fully connected layer 1
        x = self.FC1(x)
        # activation
        x = self.relu(x)
        # fully connected layer 2
        x = self.FC2(x)
        # activation
        x = self.relu(x)
        # classification layer, i.e. the output layer
        x = self.cls(x)
        return x