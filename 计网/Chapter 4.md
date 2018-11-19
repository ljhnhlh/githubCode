# Chapter 4 网络层

## 4.1 introduction

网络层与传输层区别：

网络层是主机间通信，传输层是进程间通信

route vs forwarding

route规划从src到dst的路径

forwarding 决定选择路由器的哪个出口，根据内部的转发表来决定



packet在网络层传输过程（下图）：

路由器A收到packet时，A先将packet从物理层 传到网络层，经过网络层处理后，再往下发送到物理层，然后再转发到另一个router，重复执行该步骤，直到dst，

![在这里插入图片描述](https://img-blog.csdnimg.cn/20181119235535944.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3FxXzM2MzAzODYy,size_16,color_FFFFFF,t_70)

## 4.1virtual circuit and datagram networks

>  aggregate 聚集

datagram: 用于智能终端，复杂性在端系统上（即很多事情都是在接收端处理，如packet顺序，拼接等），是网络层的无连接服务

VC connection:用于电话等比较简单的通信工具，复杂性在router上，是网络层的有连接服务

VC 有vc number，是可变的，在forwarding 是根据表来改变，每次转发差不多都会改变，根据最长前缀匹配规则进行转发

VC 的连接状态由路由器维护

VC 如今不用了

三次握手建立连接并发送数据：

![在这里插入图片描述](https://img-blog.csdnimg.cn/20181120004604520.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3FxXzM2MzAzODYy,size_16,color_FFFFFF,t_70)

