# Qt整理的基础控件说明

[MENU]

## 前序
>个人整理Qt开发中常用的基础控件，加以整合以便在后期的项目中直接使用。基础控件中包含了网络收集来的控件和自己编写的控件，来自网络的控件都标明了出处。
若有冒犯请及时联系我，予以删除。

** 若觉得对您有用,欢迎Star和Fork **

>Email  :kevinlq0912@163.com  
QQ      :2313828706  
Oschina :http://git.oschina.net/kevinlq0912   
GitHub  :https://github.com/kevinlq  

## 环境说明

>本人测试环境  
Qt:5.4.2 Mingw  
OS:windows7 64b  
其他环境测试完成后一并标注    

## 工程说明

本工程将各个控件进行了分类，每类控件都各自封装成对应的库，可以方便调用，各个控件的头文件和源文件分别存放，方便了后期直接调用dll以及头文件，工程大致框架如下所示:

![工程框架说明](/doc/project_frame.png)

## 如何编译本工程
* 打开本项目源码，打开工程文件`LQFramKit.pro`,去掉影子编译选项，直接点击编译并运行即可，最终生成的可执行文件以及对应的库文件都在`bin`文件中，具体可以编译完成后查看。

## 使用本工程

## 测试用例

>测试用例中针对不同的控件进行了说明，也有对应的demo作为展示

若不想生成动态库，则编译时在对应pro文件中添加宏定义
```
DISABLE_LIBRARY_FEATURES
```

### 仪表相关控件测试

#### 1. 汽车仪表1

 控件来源:https://www.linux-apps.com/browse/cat/280/page/2/ord/latest/  
 最终效果:  

![仪表盘](/screen/gauge.png)

![动态效果图](/screen/gauge.gif)

由于录制关系，动态图显示某些颜色不正常。  
#### 2. 汽车仪表2    
 控件来源:https://www.linux-apps.com/browse/cat/280/page/2/ord/latest/  
 最终效果  
![仪表盘](/screen/meter.png)  

![动态图](/screen/meter.gif)  

#### 3. 姿势仪表  

>姿势仪表是展示当前水平以及垂直方向的程度，使用滑块来进行模拟控制，可以很明显的看到，当滑动相应的滑块过程中，姿势发生了相应的变化。

![姿势仪表](/screen/attitudemeter.png)

#### 4. 速度仪表1

控件来源:https://github.com/Berrima/Qt-custom-gauge-widget   
最终效果如下所示：

![速度仪表1](/screen/speed1.png)

#### 5. 速度仪表2

最终效果如下所示： 

![速度仪表2](/screen/speed2.png)

#### 6. 圆形进度条

>圆形进度条继承QWidget，有7种样式可供选择，demo中详细的记录了各种样式效果。

![圆形进度条](/screen/roundPorgressbar.png)

#### 7. 多彩进度条

>多彩进度条继承在QWidget,采用QPainter进行了绘制实现的。

![多彩进度条](/screen/ColorProgress.png)


#### 8. 速度仪表3
> 来源于网络，修改了部分bug以及添加一些接口

* 静态图

![](/screen/speedwatch2.png)

### 界面显示类测试

####  1. 自定义搜索框

>自定义搜素框是继承自QLineEdit，然后对其进行了布局，使得button可以显示出来，最后处理了相关的事件，看起来更加符合常规。更加详细的用法可以看工程中对应的demo。

![自定义搜索框](/screen/search.png)

#### 2.自定义ComBox

>自定义ComBox继承自QCombBox，实现了一些特殊用法，源码中写的比较高明，有待于更进一步去学习。

![自定义ComBox](/screen/customComBox.png)

#### 3. 自定义启动界面(带进度条显示)

>自定义启动界面继承自`QSplashScreen`来实现了的，添加了进度条以便显示启动进度，预留出对应的时间接口，可以控制显示的的时间，这个时间根据具体的程序加载时间进行传递。

![自定义启动界面](/screen/Splashscreen.png)

#### 4. 超炫启动界面
>继承自QWidget,在paintEvent事件中进行不断旋转背景图片实现，具体其他效果可以替换其他不同的图片而实现

![超炫启动界面](/screen/start.png)

#### 4. 自定义switch切换按钮
>switch切换按钮继承自QWidget,利用QPainter进行绘制而实现，以前弄过一个继承自QPushButton,然后使用逻辑变量控制，当按下button时显示不同的图片，这样太依赖于美工，没有具体样式的图片，按钮演示无法修改，目前使用重绘比较灵活，缺点是性能有缺失，毕竟重绘效率不高。

![自定义switch切换按钮动界面](/screen/switch.png)

#### 5. 自定义消息框
>自定义消息框继承自QDialog,通过布局实现了一个简单的消息框，所以的样式由样式表进行控制。效果如下所示:

![自定义消息框](/screen/messagebox.png)

#### 6. 导航进度条
> 导航进度条继承QWidget,通过QPainter进行绘制。

* 来源
[http://www.qtcn.org/bbs/read-htm-tid-62954.html](http://www.qtcn.org/bbs/read-htm-tid-62954.html)

* 使用方法
使用时只需要继承该 类即可，或者选择控件提升的办法  
要显示不同的进度只需要调用setValue()方法即可

![导航进度条](/screen/drawprogressbar.png)

#### 7. 尺子

* 来源 [http://www.qtcn.org/bbs/read-htm-tid-61601.html](http://www.qtcn.org/bbs/read-htm-tid-61601.html)

* 使用方法

继承crule类即可，或者选择界面提升方法也行。

原作者实现了基本的功能，后期可以添加尺子360°旋转，更加人性化一些

![尺子](/screen/ruler.png)

#### 8. IP地址输入框

* 来源

本空间来源于这篇博客  
[小豪之家](http://blog.csdn.net/small_qch/article/details/7068234)

在原作者基础上主要优化和增加了如下功能：
1. 添加了使用点号自动跳到下个输入框；
2. 添加了使用键盘方向键控制焦点切换；

输入功能基本仿照一般的网络调试助手IP地址输入框功能

![某某网络调试助手](/screen/nettool.png)

* 使用方法

选择继承或者提升IpAddressWidget类 均可以实现对应的效果

![IP地址输入框](/screen/ipAddress.png)

获取输入框的IP地址:

```
    /**
      @brief getIpAddress() 获取IP地址
    */
    QString getIpAddress () const;
```

#### 9. 弹窗提醒工具

* 来源 https://git.oschina.net/cassfrontend/qt-notify

![](/screen/msgNotify.png)


#### 10. 树状导航
* 来源网络

![](/screen/navlistview.png)

#### 11. tabWidget
![tabWidget](/screen/tabwidget.png)


### 辅助工具类测试
>辅助工具类包含了常见的一些小工具，比如二维码生成、验证码生成、进制转换、数据通信(串口(232,485)、网络、CAN等)
 
#### 1. 性能测试工具
 
>性能监测工具可以模拟windows系统自带的性能监测效果，目前显示的波纹采用定时器进行模拟，具体实际使用过程中可以传入相应的数据值。demo中有详细的介绍。

![性能监测](/screen/perfmon.png)

#### 2. 二维码识别工具
>二维码识别采用第三发库来实现

![二维码识别](/screen/qzxing.png)

测试时使用自己支付宝付款码进行了测试

### 图表控件类测试
>图表控件类包含了常见的图表，比如各种统计图(条形图、扇形图、折线图、饼图等等)


## 版本更新记录
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
