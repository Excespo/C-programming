import torch
print("torch version: ", torch.__version__)
print("cuda version: ", torch.version.cuda)
print("cuda available: ",torch.cuda.is_available())
print("cudnn version: ", torch.backends.cudnn.version())
print("cudnn available: ",torch.cudnn_is_acceptable(torch.ones(1).cuda()))
