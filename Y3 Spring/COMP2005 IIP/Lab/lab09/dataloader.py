# Created by Ziling Wu
# Supervised by Dr Armaghan Moemeni
# Last Updated: December 4th, 2023


from torch.utils.data import Dataset
import os
import random
import cv2
import torchvision.transforms.functional as TF


class MNIST(Dataset):
    def __init__(self, partition="train"):
        """
        training set
        """
        super(MNIST, self).__init__()
        # initialize the root path of the dataset
        if partition == "train":
            root_path = "./MNIST/mnist_train/"
        else:
            root_path = "./MNIST/mnist_test/"

        # create a list of image path - label pair: [(image_path, label), ...]
        self.image_path_label_pairs = []

        # obtain data of training or testing
        # obtain categories, categories are names of sub-folders
        categories = os.listdir(root_path)
        # load images of each sub-folder (category)
        for category in categories:
            # load image names under the current sub-folder
            image_names = os.listdir(root_path + category)
            # load image paths and corresponding categories
            self.image_path_label_pairs.extend([(root_path + category + "/" + image_name, int(category)) for image_name in image_names])

        # shuffle the dataset
        random.shuffle(self.image_path_label_pairs)

    def __getitem__(self, index):
        """
        according to index obtain image and its label
        :param index:
        :return:
        """
        # obtain current image path - label pair corresponding to the index
        image_path_label_pair = self.image_path_label_pairs[index]
        # obtain image path
        image_path = image_path_label_pair[0]
        # obtain label
        label = image_path_label_pair[1]
        # load the image
        image = cv2.imread(image_path, cv2.IMREAD_GRAYSCALE)
        # transfer the image from opencv to pytorch tensor
        torch_image = TF.to_tensor(image)
        # normalization
        torch_image = TF.normalize(torch_image, mean=[0.1307], std=[0.3081])
        return torch_image, label

    def __len__(self):
        return len(self.image_path_label_pairs)