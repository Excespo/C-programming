# tensorRT via NVIDIA

# pre: CUDA & CUDNN on linux

`Command 'nvcc' not found, but can be installed with apt install nvidia-cuda-toolkit`

cuda is under __/usr/local/cuda__

神bug: `nvcc` + __Capital V__ 查看cuda版本

神bug2: `nvidia-smi` __没有空格__ 纯纯的无语了

神question: `nvcc -V`: V10.1.243, `nvidia-smi`: 11.4 前者是runtime api的版本， 后者是driver api的版本，可想而知是向下兼容的


查看linux版本信息
`cat /etc/issue` or `cat /proc/version`

安装tensorRT 具体看wx公众号 oldpan博客

解压缩完了，bashrc改好了，进samples一make，诶，还就那个lcudnn not found 我寻思着你这个cudnn是不是脑子有病啊，和cuda要兼容你不会放在一起？他妈解压缩完复制黏贴过去就完事？你确实有点毛病

一堆undefined reference，而且可以看到/usr/local/cuda-9.2/include 和 /lib64 下文件齐全，甚至我认为有多出的文件，只能说我的意见是暂时搁置，问题有点大

conclusion:
 - [官方文档](https://docs.nvidia.com/deeplearning/tensorrt/index.html)
 - 理论上在/TensorRT/samples下编译（参考上文博客）
 - cudnn和trt都需要加入环境变量，我的方式是`vim ~/.bashrc`然后`export LD_LIBRARY_PATH=`，具体百度一下
 - 版本不匹配和链接应该是最有可能的问题，我个人更倾向于后者，但是超出目前的对linux的理解太多，处理不了
 - TODO


