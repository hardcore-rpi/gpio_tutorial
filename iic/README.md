# 树莓派IIC总线操作例程

IIC总线调试工具 i2c-tools
```
sudo apt-get install i2c-tools
```

加载IIC驱动
```
sudo modprobe i2c_bcm2708
sudo modprobe i2c_dev
```

例程

1. ds1307 实时时钟
1. PCF8574 IO扩展

更多信息，访问：  
[树莓派学习笔记——I2C设备载入和速率设置](http://blog.csdn.net/xukai871105/article/details/18234075)
