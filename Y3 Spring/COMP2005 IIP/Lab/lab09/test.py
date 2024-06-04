# Created by Ziling Wu
# Supervised by Dr Armaghan Moemeni
# Last Updated: December 4th, 2023

import torch
import numpy as np
from DataLoader import MNIST
from net import ToyModel
import torch.utils.data as Data
import cv2


def denormalize(tensor, mean, std):
    """
    denormalize tensor in shape (1, 1, H, W)
    mean: mean when normalizing
    std: standard difference when normalizing
    """
    from torchvision.transforms.functional import normalize
    mean = np.array(mean)
    std = np.array(std)
    _mean = -mean / std
    _std = 1 / std
    return normalize(tensor, _mean, _std)


if __name__ == '__main__':
    # initialize inference devices
    test_device = torch.device("cuda:0" if torch.cuda.is_available() else "cpu")

    # load the model's well-trained weight
    model = ToyModel()
    model.load_state_dict(torch.load("./module/net9.pkl"))

    # move the model to the test device
    model.to(test_device)

    # set the model to the "inference" mode
    model.eval()

    # initialize the dataset
    mnist = MNIST(partition="test")

    # initialize the dataloader
    loader = Data.DataLoader(
        dataset=mnist,  # torch TensorDataset format
        batch_size=1,  # mini batch size
        shuffle=True,  # it is good to shuffle the dataset
        pin_memory=True,
        drop_last=True,
        num_workers=1,  # load the data with multiple threads
    )

    # prediction
    for torch_images, labels in loader:
        # move the images to the test device
        torch_images = torch_images.to(test_device)
        labels = labels.to(test_device)
        # obtain the output of the model
        predictions = model.forward(torch_images)
        # obtain the predicted category
        _, predicted_class = torch.max(predictions, dim=1)
        # denormalize the torch image for visualization
        image = denormalize(torch_images[0], mean=[0.1307], std=[0.3081])
        # change the image from pytorch tensor to opencv(numpy array)
        image = (image.cpu().numpy() * 255).astype(np.uint8)[0]
        # enlarge the image for visualization (the original image's size is 28x28, which is too small)
        image = cv2.resize(image, (280, 280))
        # put the predicted category on the image for visualization
        cv2.putText(image, "predicted class: " + str(predicted_class.cpu().numpy()[0]), (10, 20), cv2.FONT_HERSHEY_SIMPLEX, 0.5,
                    255, 1)
        # visualization
        cv2.imshow("", image)
        # wait for user input
        pressedKey = cv2.waitKey(0) & 0xFF
        if pressedKey == ord('q'):
            # press q to quit
            break
        else:
            continue
    cv2.destroyAllWindows()