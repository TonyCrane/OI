#!/bin/bash

read -p "请输入题目(无后缀名) > " filename
touch $filename.in
touch $filename.out
touch $filename.cpp
echo "成功创建文件"