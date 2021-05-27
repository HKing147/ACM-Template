# ACM-Template

> [English](./README.md)

## 安装

#### 前提:安装好 _xelatex_ 和 _pandoc_

> ### 克隆仓库
>
> ```shell
> git clone https://github.com/HKing147/ACM-Template.git
> ```
>
> ### 安装字体
>
> #### 主要字体:Latin Modern Mono 和华文楷体,代码字体为 Consolas,代码注释字体为 Latin Modern Mono
>
> ```shell
> cd ACM-template/.fonts/
> cp ./* /usr/share/fonts/
> mkfontscale
> mkfontdir
> fc-cache
> ```
>
> ### 生成 pdf 模板文件
>
> ```shell
> cd ..
> make
> ```

## 使用

> ### 主目录下的 config 配置文件
>
> #### 每行代表一个含有模板代码文件的*一级*目录名
>
> ### 其它子目录下的 config 配置文件
>
> #### 有 4 个参数(_注:一般四个参数不同时都有，有第四个参数一般就没有第 2、3 个参_)
>
> #### 参数含义：<当前标题名><代码文件或说明文件><代码文件或说明文件><下级标题名>
