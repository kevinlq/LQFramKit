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
* V 0.0.0.1 添加了汽车仪表盘控件，有2中风格，具体效果在自带的demo中可以运行看到；
* V 0.0.0.2 添加了自定义搜索框、性能监控、姿势仪表控件；
## 如何编译本工程
* 打开本项目源码，打开工程文件`LQFramKit.pro`,去掉影子编译选项，直接点击编译并运行即可，最终生成的可执行文件以及对应的库文件都在`bin`文件中，具体可以编译完成后查看。

## 使用本工程

## 测试用例
1 汽车仪表1
 控件来源:https://www.linux-apps.com/browse/cat/280/page/2/ord/latest/  
 最终效果  
![仪表盘](http://git.oschina.net/kevinlq0912/LQFramKit/raw/master/screen/gauge.png)
<img src="[http://git.oschina.net/kevinlq0912/LQFramKit/raw/master/screen/gauge.gif" alt="Flash animation" />

由于录制关系，动态图显示某些颜色不正常。  
2 汽车仪表2  
 控件来源:https://www.linux-apps.com/browse/cat/280/page/2/ord/latest/  
 最终效果  
![仪表盘](http://git.oschina.net/kevinlq0912/LQFramKit/raw/master/screen/meter.png)  
<img src="[http://git.oschina.net/kevinlq0912/LQFramKit/raw/master/screen/meter.gif" alt="Flash animation" />

3.姿势仪表
姿势仪表是展示当前水平以及垂直方向的程度，使用滑块来进行模拟控制，可以很明显的看到，当滑动相应的滑块过程中，姿势发生了相应的变化。
![姿势仪表](http://git.oschina.net/kevinlq0912/LQFramKit/raw/master/screen/attitudemeter.png)
4.自定义搜索框
自定义搜素框是继承自QLineEdit，然后对其进行了布局，使得button可以显示出来，最后处理了相关的事件，看起来更加符合常规。更加详细的用法可以看工程中对应的demo。
![自定义搜索框](http://git.oschina.net/kevinlq0912/LQFramKit/raw/master/screen/search.png)
4.性能监控
性能监测工具可以模拟windows系统自带的性能检测效果，目前显示的波纹采用定时器进行模拟，具体实际使用过程中可以传入相应的数据值。demo中有详细的介绍。
![性能检测](http://git.oschina.net/kevinlq0912/LQFramKit/raw/master/screen/perfmon.png)

