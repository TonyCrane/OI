#!/bin/bash

read -p "请输入要提取的文件名(不加后缀名) > " filename

echo "读取源文件 : codes/$filename.cpp"
if [ ! -f "codes/$filename.cpp" ] ; then
	echo "C++文件不存在！"
	exit
fi

echo "读取输入文件：inputs/$filename.in"
if [ ! -f "inputs/$filename.in" ] ; then
	echo "输入文件不存在！"
	exit
fi

echo "读取输出文件：outputs/$filename.out"
if [ ! -f "outputs/$filename.out" ] ; then
	echo "输出文件不存在！"
	exit
fi

echo -e "\n成功读取文件"

mv codes/$filename.cpp $filename.cpp
mv inputs/$filename.in $filename.in
mv outputs/$filename.out $filename.out
echo -e "\n文件提取成功"
