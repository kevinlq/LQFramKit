## 使用本工程

> 以下都是具体控件使用demo

## 测试用例

>测试用例中针对不同的控件进行了说明，也有对应的demo作为展示


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

#### 9. 波形进度条
>来源于qt论坛，核心算法是liudianwu-Qt侠提供的思路

[来源地址](http://www.qtcn.org/bbs/read-htm-tid-63591-page-e.html#a)

![](/screen/wavePro.gif)


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

#### 12. toleranceBar
- 来源于网络，自己修改了一些接口添加了相关注释

![toleranceBar](/screen/toleranceBar.png);


### 辅助工具类测试
>辅助工具类包含了常见的一些小工具，比如二维码生成、验证码生成、进制转换、数据通信(串口(232,485)、网络、CAN等)
 
#### 1. 性能测试工具
 
>性能监测工具可以模拟windows系统自带的性能监测效果，目前显示的波纹采用定时器进行模拟，具体实际使用过程中可以传入相应的数据值。demo中有详细的介绍。

![性能监测](/screen/perfmon.png)

#### 2. 二维码识别工具
>二维码识别采用第三发库来实现

![二维码识别](/screen/qzxing.png)


![性能监测](/screen/perfmon.png)

测试时使用自己支付宝付款码进行了测试

#### 3. 工程模板生成

该工具可以用来生成一系列工程文件，省去自己动手生成(主要配合自己项目中使用到的子工程系列)!
![工程模板生成](/screen/proCreate.png)

### 图表控件类测试
>图表控件类包含了常见的图表，比如各种统计图(条形图、扇形图、折线图、饼图等等)
