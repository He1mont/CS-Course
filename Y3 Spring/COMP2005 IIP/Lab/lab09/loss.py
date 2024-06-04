# Created by Ziling Wu
# Supervised by Dr Armaghan Moemeni
# Last Updated: December 4th, 2023

import torch
import torch.nn as nn


class MyCrossEntropyLoss(nn.Module):
    def __int__(self):
        super(MyCrossEntropyLoss, self).__int__()

    def forward(self, predictions, labels, reduction="mean"):
        """
        calculate loss function
        :param reduction: mean or sum
        :param labels: ground truth class of each input sample
        :param predictions: output given by the model without being normalized and softmaxed
        :return:
        """
        # softmax
        probabilities = torch.exp(predictions) / torch.sum(torch.exp(predictions), dim=1).reshape(predictions.size(0), 1)
        # obtain predicted probabilities of each input sample's ground truth class
        probabilities = probabilities[range(probabilities.size(0)), labels]
        # calculate cross entropy
        loss = - torch.log(probabilities)
        # average the loss of each sample or calculate summation
        if reduction == "mean":
            loss = torch.sum(loss) / loss.size(0)
        elif reduction == "sum":
            loss = torch.sum(loss)
        return loss