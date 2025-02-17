'''
2021/12/2
Sample solution for Lab9 COMP3055 UNNC
Environments:	Python = 3.7.4
		numpy = 1.19.1
		pytorch = 1.10.0
		torchvision = 0.11.1
'''

# load data from local file, fetch_openml() also works
import numpy as np
import torch
import torch.nn as nn
import torch.nn.functional as F
import torch.optim as optim
from torch.autograd import Variable
from torchvision import datasets, transforms


class Net(nn.Module):
	def __init__(self):
		super(Net, self).__init__()
		# 1 input image channel, 6 output channels, 3x3
		# square convolution kernel
		self.conv1 = nn.Conv2d(1, 6, 3)
		self.conv2 = nn.Conv2d(6, 16, 3)
		# 6*6 from image dimension
		self.fc1 = nn.Linear(16 * 6 * 6, 120)
		self.fc2 = nn.Linear(120, 84)
		self.fc3 = nn.Linear(84, 10)

	def forward(self, x):
		# Max pooling over a (2, 2) window
		x = F.max_pool2d(F.relu(self.conv1(x)), (2, 2))
		x = F.max_pool2d(F.relu(self.conv2(x)), 2)
		x = x.view(-1, self.num_flat_features(x))
		x = F.relu(self.fc1(x))
		x = F.relu(self.fc2(x))
		x = self.fc3(x)
		return x

	def num_flat_features(self, x):
		# all dimensions except the batch dimension
		size = x.size()[1:]  
		num_features = 1
		for s in size:
			num_features *= s
		return num_features


def load_data(train_batch_size, test_batch_size):
	# Fetch training data: total 60000 samples
	train_loader = torch.utils.data.DataLoader(
		datasets.MNIST('data', train=True, download=True,transform=transforms.Compose([transforms.Resize((32, 32)),transforms.ToTensor(),transforms.Normalize((0.1307,), (0.3081,))])),batch_size=train_batch_size, shuffle=True)

	# Fetch test data: total 10000 samples
	test_loader = torch.utils.data.DataLoader(
		datasets.MNIST('data', train=False, transform=transforms.Compose([transforms.Resize((32, 32)),transforms.ToTensor(),transforms.Normalize((0.1307,), (0.3081,))
        ])),batch_size=test_batch_size, shuffle=True)

	return (train_loader, test_loader)


def train(model, optimizer, epoch, train_loader, log_interval):
	# State that you are training the model
	model.train()

	# define loss function
	loss_fn = torch.nn.CrossEntropyLoss()

	# Iterate over batches of data
	for batch_idx, (data, target) in enumerate(train_loader):
		# Wrap the input and target output in the `Variable` wrapper
		data, target = Variable(data), Variable(target)

		# Clear the gradients, since PyTorch accumulates them
		optimizer.zero_grad()

		# Forward propagation
		output = model(data)

		loss = loss_fn(output, target)

		# Backward propagation
		loss.backward()

		# Update the parameters(weight,bias)
		optimizer.step()

		# print log
		if batch_idx % log_interval == 0:
			print('Train set, Epoch {} [{}/{} ({:.0f}%)]\tLoss: {:.6f}'.format(epoch, batch_idx * len(data), len(train_loader.dataset), 100. * batch_idx / len(train_loader),loss.item()))


def test(model, epoch, test_loader):
	# State that you are testing the model; this prevents layers e.g. Dropout to take effect
	model.eval()

	# Init loss & correct prediction accumulators
	test_loss = 0
	correct = 0

	# define loss function
	loss_fn = torch.nn.CrossEntropyLoss(size_average=False)

	# Iterate over data
	for data, target in test_loader:
		data, target = Variable(data), Variable(target)

		# Forward propagation
		output = model(data)

		# Calculate & accumulate loss
		test_loss += loss_fn(output, target).item()

		# Get the index of the max log-probability (the predicted output label)
		pred = np.argmax(output.data, axis=1)

		# If correct, increment correct prediction accumulator
		correct = correct + np.equal(pred, target.data).sum()

	# Print log
	test_loss /= len(test_loader.dataset)
	print('\nTest set, Epoch {} , Average loss: {:.4f}, Accuracy: {}/{} ({:.0f}%)\n'.format(epoch,
		test_loss, correct, len(test_loader.dataset),
		100. * correct / len(test_loader.dataset)))


model = Net()

lr = 0.01
momentum = 0.5
optimizer = optim.SGD(model.parameters(), lr=lr, momentum=momentum)

train_batch_size = 64
test_batch_size = 1000
train_loader, test_loader = load_data(train_batch_size, test_batch_size)

epochs = 10
log_interval = 100
for epoch in range(1, epochs + 1):
	train(model, optimizer, epoch, train_loader, log_interval=log_interval)
	test(model, epoch, test_loader)