# 洛谷

### 目录列表
- codes
	C++源文件
- inputs
	输入文件
- outputs
	输出文件
- [x] run.sh 运行并检测代码的脚本文件
- [x] return.sh 提前文件的脚本
- [x] push.sh 自动上传到GitHub的脚本文件

### run.sh使用
`$ ./run.sh`即可使用，需输入文件名(不加后缀名)

整理代码的位置需要根据需要调整

删除多余空格及空行进行比较

编译命令为 `g++ -o $filename $filename.cpp` 可自行更改

输出时间为user时间

目前不支持打破死循环等

### return.sh使用
`$ ./return.sh`即可使用，可将整理到文件夹中的源文件、输入输出文件提取出来

路径可自行更改

