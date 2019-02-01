#!/bin/bash

read -p "请输入文件名(无后缀名) > " filename
echo "读取源文件 : $filename.cpp"
if [ ! -f "$filename.cpp" ] ; then
	echo "C++文件不存在！"
	exit
fi

echo "读取输入文件：$filename.in"
if [ ! -f "$filename.in" ] ; then
	echo "输入文件不存在！"
	exit
fi

echo "读取输出文件：$filename.out"
if [ ! -f "$filename.out" ] ; then
	echo "输出文件不存在！"
	exit
fi

echo -e "\n成功读取文件"

g++ -o $filename $filename.cpp
if [ $? -ne 0 ] ; then
	echo "\n\n编译错误！"
	exit
fi
echo -e "\n编译成功\n"

./$filename < $filename.in > a.out
diff --ignore-space-change --ignore-blank-lines $filename.out a.out
if [ $? -ne 0 ] ; then
	echo -e "\n\n输出结果错误！"
	exit
fi

cat a.out
echo -e "\n\n样例通过，用时："
/usr/bin/time -f "time: %U\n" ./$filename < $filename.in > a.out

y="y"

read -p "是否整理文件?(y/n) > " op
if [ $op = $y ] ; then
	rm $filename
	rm a.out
	mv $filename.out outputs/
	mv $filename.cpp codes/
	mv $filename.in inputs/
	echo "整理成功"
fi

