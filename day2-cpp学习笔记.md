# Day2 Git & GitHub
## 环境
Git‑for‑windows，国内镜像下载安装，全部选项默认Next。

## 完整执行命令
```powershell
git --version
git config --global user.name "用户名"
git config --global user.email "邮箱"
git init
git add .
git commit -m "Day1 C++练习，hello calc程序，学习笔记md"
# 复制GitHub网页提供两行命令
git remote add origin https://github.com/xxx/cpp-learning.git
git push -u origin main
