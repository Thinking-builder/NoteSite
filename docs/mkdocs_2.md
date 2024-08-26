
# Mkdocs 安装以及初始化指引

> 为什么会写一篇关于Mkdocs的安装指引？
> 因为官方文档的安装指引只是**理想情况**下的指引，期间会出现其他的情况并且网络上难以搜罗到简单并且清晰的解决方案。

## 理想情况的顺利安装流程

- 请参考[Mkdocs`Installation](https://www.mkdocs.org/user-guide/installation/)

## 差错情形1：Runtime Error

系统提示：（终端或者cmd）The read operation timed out

解决：输入``pip --default-timeout=1000 install mkdocs``

## 差错情形2: Unicode Decode Error

使用入门指南中的``curl 'https://jaspervdj.be/lorem-markdownum/markdown.txt' > docs/about.md``来添加页面**可能会产生错误**

原因是：这种方式创建的``md文件``是采用**UTF-16**编码的，当遇到python**UTF-8**的解码方式自然会出错。

## 差错情形3: Python3，pip3（MacOS）

当您使用的是Python 3的版本时，你如果按照官网给的命令行，绝对找不到！

解决方案：``pip install mkdocs`` --> pip**3** install mkdocs

> 不用怀疑自己是否安装了pip，一般都默认安装了。

————————————

如果还有疑问或者其他情形，欢迎联系：<202536953@qq.com>
