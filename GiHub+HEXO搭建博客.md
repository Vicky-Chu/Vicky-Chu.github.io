---
title: How to set up HEXO
---

# 一、准备工作

****1.因为hexo是由node.js 生成的，所以需要下载安装node.js**

![在这里插入图片描述](https://img-blog.csdnimg.cn/20201201193106778.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3FxXzUxNTI3NjM4,size_16,color_FFFFFF,t_70#pic_center)


**2.安装Git和配置好Git环境，安装成功在桌面右击鼠标右键会有下图标志**
![在这里插入图片描述](https://img-blog.csdnimg.cn/20201201191825608.jpg#pic_center)


## 二、搭建GitHub Pages
**1.注册一个GitHub账号，并登录**

**2.创建仓库**
1>点击“NEW"
![在这里插入图片描述](https://img-blog.csdnimg.cn/20201201192140390.png#pic_center)
2>填写仓库信息
![在这里插入图片描述](https://img-blog.csdnimg.cn/20201201192617905.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3FxXzUxNTI3NjM4,size_16,color_FFFFFF,t_70#pic_center)
**3.启用GitHub Pages**
1>点击“setting”进入设置
![在这里插入图片描述](https://img-blog.csdnimg.cn/20201201192901820.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3FxXzUxNTI3NjM4,size_16,color_FFFFFF,t_70#pic_center)
2>往下拉找到“GitHub Pages”，如图显示说明已开启
![在这里插入图片描述](https://img-blog.csdnimg.cn/20201201193415547.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3FxXzUxNTI3NjM4,size_16,color_FFFFFF,t_70#pic_center)
**

## 三、HEXO
**1.安装HEXO**
1>在认为合适的地方创建文件夹，然后在文件夹里右击鼠标，选择“Git Bash Here”
2>输入npm install -g hexo进行安装（不要忘记空格）
![在这里插入图片描述](https://img-blog.csdnimg.cn/20201201194422110.png#pic_center)
然后使用 hexo -v，查看是否安装成功

3>输入 hexo init 初始化文件夹
看到最后的“start blogging with Hexo！”表示成功

4>输入 npm install 安装所需要的组件

5>输入 hexo g 第一次体验hexo

6>输入 hexo s ，启动本地服务器，通过访问http://localhost:4000，正式体验Hexo
成功！

## **四、部署到GitHub**
**1.使用Hexo deploy部署到GitHub**
1>编辑创建的文件夹根目录下_config.yml文件，添加如下代码，并保存（sunkeepero换成自己的用户名）
![在这里插入图片描述](https://img-blog.csdnimg.cn/20201201195447818.jpg#pic_center)
2>安装一个扩展
输入 npm install hexo-deploy-git --save

## 2.检查SSH Keys设置
1>输入cd ~/.ssh
如果出现下图情况，说明不存在.ssh
![在这里插入图片描述](https://img-blog.csdnimg.cn/2020120119594477.jpg?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3FxXzUxNTI3NjM4,size_16,color_FFFFFF,t_70#pic_center)
解决方法：输入 $ ssh-keygen -t rsa -C “xxxxxxxx@qq.com”（注册邮箱）
![在这里插入图片描述](https://img-blog.csdnimg.cn/20201201200215868.jpg?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3FxXzUxNTI3NjM4,size_16,color_FFFFFF,t_70#pic_center)
再次进行下图操作，出现相同文件说明成功
![在这里插入图片描述](https://img-blog.csdnimg.cn/20201201200247525.jpg?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3FxXzUxNTI3NjM4,size_16,color_FFFFFF,t_70#pic_center)
2>输入eval "$(ssh-agent -s)",添加密钥到ssh-agent



3>再输入ssh-add ~/.ssh/id_rsa，添加生成的SSH key到ssh-agent

## **3.添加SSH Key 到GitHub**
1>点击settings
![在这里插入图片描述](https://img-blog.csdnimg.cn/20201201201149200.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3FxXzUxNTI3NjM4,size_16,color_FFFFFF,t_70#pic_center)
2>点击“SSH and GPG keys”，然后点击“New SSH key”新建SSH keys
![在这里插入图片描述](https://img-blog.csdnimg.cn/20201201201404430.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3FxXzUxNTI3NjM4,size_16,color_FFFFFF,t_70#pic_center)

![在这里插入图片描述](https://img-blog.csdnimg.cn/20201201201416402.png#pic_center)

3>填写key
题目随便填
key的内容在电脑中找到名字是"id_rsa.pub"的文件将里面内容复制到key的框里

4>输入ssh -T git@github.com，测试添加ssh是否成功。如果看到Hi后面是你的用户名，说明成功（中间会输入一个yes，再按enter键）

5>设置你的账号信息

## 4.部署到GitHub
输入 hexo d -g
使用（用户名）github.io 即可访问自己的博客（括号里输自己的用户名）


















