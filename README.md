# Qt整理的基础控件说明
>个人整理Qt开发中常用的基础控件，加以整合以便在后期的项目中直接使用。基础控件中包含了网络收集来的控件和自己编写的控件，来自网络的控件都标明了出处。
若有冒犯请及时联系我，予以删除。

## 环境说明：
>本人测试环境
Qt:5.4.2
OS:windows7 64b
其他环境测试完成后一并标注。

## 版本更新
* V 0.0.0.0 构建了控件整体框架，完善了一些表达；
* V 0.0.0.1 添加了洗车仪表盘控件，有2中风格，具体效果在自带的demo中可以运行看到；

## 如何编译本工程
* 打开本项目源码，打开工程文件`LQFramKit.pro`,去掉影子编译选项，直接点击编译并运行即可，最终生成的可执行文件以及对应的库文件都在`bin`文件中，具体可以编译完成后查看。

## 使用本工程

## 测试用例
* 汽车仪表1
 控件来源:https://www.linux-apps.com/browse/cat/280/page/2/ord/latest/
 最终效果
![仪表盘](http://git.oschina.net/kevinlq0912/LQFramKit/raw/master/screen/gauge.png)
![动态效果图][http://git.oschina.net/kevinlq0912/LQFramKit/raw/master/screen/gauge.gif]
由于录制关系，动态图显示某些颜色不正常。
* 汽车仪表2
 控件来源:https://www.linux-apps.com/browse/cat/280/page/2/ord/latest/
 最终效果
![仪表盘](http://git.oschina.net/kevinlq0912/LQFramKit/raw/master/screen/meter.png)
![动态效果图][http://git.oschina.net/kevinlq0912/LQFramKit/raw/master/screen/meter.gif]
