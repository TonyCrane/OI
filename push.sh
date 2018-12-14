#!/bin/bash

read -p "请输入commit信息 > " commit
read -p "请输入本地仓库名 > " origin

git add --all
echo -e "\n\n"

git commit -m "$commit"
echo -e "\n\n"

git push $origin master
