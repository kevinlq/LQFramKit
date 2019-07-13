# LQFramKit

[英语/English](README.md)

> 使用C++ Qt5封装的一些控件，以便后期项目中直接使用。这些控件有些是来自于网络有些属于个人封装，代码中都有出处

## 结果
|Rank| Time|content|speed |
|--|--|--|--|
|0 | 20170411|LQFramKit基础结构 |![95.0163%](http://progressed.io/bar/95)|
|1 | 20170601| 汽车仪表盘|![100.00%](http://progressed.io/bar/100)|


## 使用指南

### 项目使用条件

Qt 5

### 如何编译

>本人测试环境  
Qt:5.4.2 Mingw   5.11
OS:windows7 64b  
其他环境测试完成后一并标注  

```
新增linux下编译

Qt: 5.5.1 Qt5.11
OS: ubuntu 16.04
```

### 编译&&运行

* 打开本项目源码，打开工程文件`LQFramKit.pro`,按照下图所示进行编译配置即可：

![编译配置](/screen/build_setting.png)

建议按照上述配置，添加宏定义`CONFIG+=MinGW`

`以下以 windows 平台为例`,其他平台以我博客为主进行配置

具体针对不同平台编译宏定义不同，可以参考我这篇文章[http://kevinlq.com/2017/09/18/Qt-black-technology/](http://kevinlq.com/2017/09/18/Qt-black-technology/)

## 可执行文件下载地址

https://download.csdn.net/download/u013704336/10854235


![demo](/screen/homeWidget.png)



## 贡献指南

请阅读 [CONTRIBUTING.md](#) 了解如何向这个项目贡献代码

## 版本历史

* V 0.0.0.0 构建了控件整体框架，完善了一些表达；
* V 0.0.0.1 添加了汽车仪表盘控件，有2中风格，具体效果在自带的demo中可以运行看到；
* V 0.0.0.2 添加了自定义搜索框、性能监控、姿势仪表控件；
* V 0.0.0.3 添加了2个速度仪表控件;
* V 0.0.0.4 添加了圆形进度条控件，并编写对应的demo进行演示;
* V 0.0.0.5 添加了启动界面，修复了资源文件添加的bug,多个工程中如果添加的资源文件名称相同，出现了无法调用问题，比如都新建了一个image的资源文件，调用过程中发现一直提醒找不到该文件。   
在网上找到了一篇文章：http://www.cnblogs.com/lzjsky/archive/2012/08/20/2647471.html  分析了比较详细，说明了资源文件的前因后果。
* V 0.0.0.6 添加了switch切换按钮，并进行了测试；
* V 0.0.0.7 添加了自定义消息框界面，编写相关demo测试;
* V 0.0.0.8 添加了二维码检测功能空间(后面计划添加二维码生成功能空间)；
* V 0.0.0.9 添加超酷启动界面控件demo;
* V 0.0.1.0 添加了导航进度条控件以及demo;
* V 0.0.1.1 添加了尺子工具及其demo;
* V 0.0.1.2 添加了IP地址输入框空间及其demo;
* V 0.0.1.3 添加了消息弹窗控件以及demo;
* V 0.0.1.4 添加了速度仪表3及其demo；
* V 0.0.1.5 添加树状导航及其demo；
* V 0.0.1.6 添加tabWidget窗体;
* V 0.0.1.7 添加了toleranceBar及其demo；
* V 0.0.1.8 添加了波形进度条及其demo;
* V 0.0.1.9 调整工程结构，解决Qt 5.4以后编译错误(2018年4月21日);
* V 0.0.2.0 添加工程模板生成工具(2018年5月6日);
* V 0.0.2.1 在linux下编译通过，解决一些编译问题(2018年8月24日);

## 修复bug

**2018年4月21日**

### 在Qt5.4之后编译时会出现某些库中的方法无法找到问题，比如下面的错误：

![build_setting](/screen/bugs/build_error_tools.png)

原因是该方法控件引入了 `W32` API ,导致后面Qt版本编译时找不到，Qt5.4之前的版本没有该问题。

**解决方案**

```
添加对应的W32库文件即可.
win32:{
    LIBS+=-L -lGdi32
}
```

### xxx
**2018年4月21日**

### 在linux 下编译不过问题解决

以前一直在 `windows`下进行编译，最近有盆友说是在 `linux`下无法编译通过，所以特此尝试了下，问题总算处理了.

在使用UI提升后，居然无法找到对应自定义控件的头文件，很是让然头疼.

`QRoundProgressBar`类提升后，总是在找`qroundprogressbar.h`头文件，因为 linux 对大小写很敏感，所以肯定编译不过，以前在 `windows`下没有任何问题.

**解决方案**

```
尝试清理重新编译还是不行，只能全部取消窗口部件提升，再重新提升即可解决！

2018年08月23日18:14:07
```

![linux下运行截图](/screen/linux/Screenshot_2018-08-23.png)



## 关于作者

- **kevinlq**  - [kevinlq](http://kevinlq.com/)
- **GitHub**  - [kevinlq](https://github.com/kevinlq)https://github.com/kevinlq 
- **Email:** kevinlq0912@163.com
- **QQ:** 2313828706

#### <i class="fa fa-eye"></i> 若觉得对您有用,欢迎Star和Fork


查看更多关于这个项目的贡献者，请阅读 [contributors](#)

## 授权协议


这个项目 `Apache License 2.0` 协议， 请点击 [LICENSE](LICENSE) 了解更多细节

## 致谢
