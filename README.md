# QGitHubReport

[中文/Chinese](README_zh.md)

> c++ Qt5 implementation of some controls.

## Results
|Rank| Time|speed |
|--|--|--|
|0 | 20190111|![29.0163%](http://progressed.io/bar/29)|


## Getting Started 

### Prerequisites

Qt 5

### How to build
> build environment
Qt:5.4.2 Mingw   5.11
OS:windows7 64b  

```
Qt: 5.5.1 Qt5.11
OS: ubuntu 16.04
```

### build and run

* open the project source code, open the project file `LQFramKit. Pro`, according to the compiler configuration can be shown below:

![build setting](/screen/build_setting.png)

Suggestions according to the above configuration, add macro definition `CONFIG + = MinGW`

`windows` platform:

Specific for different platforms to compile macro definition is different, you can refer to this article [http://kevinlq.com/2017/09/18/Qt-black-technology/](http://kevinlq.com/2017/09/18/Qt-black-technology/)

## exec software download address

https://download.csdn.net/download/u013704336/10854235


[demo](/screen/homeWidget.png)


## Contributing

Please read [CONTRIBUTING.md](#) for details on our code of conduct, and the process for submitting pull requests to us.


## Release History

* V 0.0.0.0 builds the overall framework of the control, perfecting some expressions;
* V 0.0.0.1 Added the car dashboard control, there are 2 styles, the specific effect can be seen in the built-in demo;
* V 0.0.0.2 added custom search box, performance monitoring, posture meter control;
* V 0.0.0.3 added 2 speed meter controls;
* V 0.0.0.4 added a circular progress bar control and wrote the corresponding demo for demonstration;
* V 0.0.0.5 added the startup interface, fixed the bug of resource file addition. If the name of the added resource file is the same in multiple projects, there is a problem that cannot be called. For example, a new image resource file is created, and it is found during the call. Always reminded that the file could not be found.
An article was found online: http://www.cnblogs.com/lzjsky/archive/2012/08/20/2647471.html The analysis is more detailed and explains the cause and effect of the resource file.
* V 0.0.0.6 added the switch switch button and tested it;
* V 0.0.0.7 added a custom message box interface, writing related demo tests;
* V 0.0.0.8 added the QR code detection function space (planned to add the QR code generation function space later);
* V 0.0.0.9 add cool startup interface control demo;
* V 0.0.1.0 added navigation progress bar control and demo;
* V 0.0.1.1 added the ruler tool and its demo;
* V 0.0.1.2 added IP address input box space and its demo;
* V 0.0.1.3 added message pop-up window control and demo;
* V 0.0.1.4 added speed meter 3 and its demo;
* V 0.0.1.5 Add tree navigation and its demo;
* V 0.0.1.6 Add a tabWidget form;
* V 0.0.1.7 added toleranceBar and its demo;
* V 0.0.1.8 added waveform progress bar and its demo;
* V 0.0.1.9 Adjust the engineering structure to solve the compilation error after Qt 5.4 (April 21, 2018);
* V 0.0.2.0 Add project template generation tool (May 6, 2018);
* V 0.0.2.1 Compile under linux to solve some compilation problems (August 24, 2018);

## fix bug


## Authors

- **kevinlq**  - [kevinlq](http://kevinlq.com/)
- **GitHub**  - [kevinlq](https://github.com/kevinlq)https://github.com/kevinlq 
- **Email:** kevinlq0912@163.com
- **QQ:** 2313828706

To see more contributors to this project, please read [contributors](#)

## License

For this project `Apache License 2.0`  agreement, please click [LICENSE](LICENSE) for more details.

## Acknowledgments
