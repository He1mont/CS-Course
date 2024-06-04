# Created by Ziling Wu
# Supervised by Dr Armaghan Moemeni
# Last Updated: December 4th, 2023


from DataLoader import MNIST
from net import ToyModel
from LossFunction import MyCrossEntropyLoss
import torch
import torch.nn as nn
import torch.utils.data as Data

# hyper-parameters
BATCH_SIZE = 32
EPOCH = 10
LR = 0.0001  # learning rate

if __name__ == '__main__':
    # initialize model
    model = ToyModel()

    # initialize training devices
    train_device = torch.device("cuda:0" if torch.cuda.is_available() else "cpu")

    # move the model to the training device
    model.to(train_device)

    # set the model to the "train" mode
    model.train()

    # initialize the dataset
    mnist = MNIST(partition="train")

    # initialize the dataloader
    loader = Data.DataLoader(
        dataset=mnist,  # torch TensorDataset format
        batch_size=BATCH_SIZE,  # mini batch size
        shuffle=True,  # it is good to shuffle the dataset
        pin_memory=True,
        drop_last=True,
        num_workers=1,  # load the data with multiple threads
    )

    # initialize loss function provided by pytorch
    loss_func = nn.CrossEntropyLoss(reduction="mean")
    # initialize our customized cross entropy loss
    my_loss_func = MyCrossEntropyLoss()

    # initialize optimizer
    optimizer = torch.optim.Adam(model.parameters(), lr=LR)

    # train
    for epoch in range(EPOCH):
        # go through every images for one time is called an epoch
        for torch_images, labels in loader:
            # move the images to the training device
            torch_images = torch_images.to(train_device)
            labels = labels.to(train_device)
            # obtain the output of the model
            predictions = model.forward(torch_images)
            # calculate loss function
            loss = my_loss_func(predictions, labels)
            # update parameters
            optimizer.zero_grad()  # clear the history accumulated gradients
            loss.backward()  # back propagation
            optimizer.step()  # gradient decent
            # print process
            print('epoch:', epoch, '|my train loss:%.4f' % loss,
                  '|official train loss:%.4f' % loss_func(predictions, labels))
        # save model per epoch
        torch.save(model.state_dict(), './module/net' + str(epoch) + '.pkl')