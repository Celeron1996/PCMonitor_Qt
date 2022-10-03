# PCMonitor_Qt
pc monitor
在Qt上编写程序，通过TCP socket 接口，用HTTP GET 协议，获取软件 “Open Hardware Monitor”生成的data.json数据，电脑的硬件信息被封装成json文件
Qt在获取json文件后，对其进行解析，得到各种硬件数据，如cpu型号，温度，使用率等，再通过Qt的波形图组件，进行可视化显示（这是我理想中的目标，，，如果有时间的话，，，）
关于软件“Open Hardware Monitor”：
官网：https://openhardwaremonitor.org/
源码：https://github.com/openhardwaremonitor/openhardwaremonitor
