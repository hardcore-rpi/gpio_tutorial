#闪烁LED
Pins: 11,12,13,15,16,18,22

#闪烁LED

这是一个简单的控制GPIO输出的例子。  

首先，在```blink_init()```函数中，初始化 bcm2835 GPIO。GPIO 的初始化工作由 BCM2835 C 库的```bcm2835_init(void)```函数完成，主要是打开 /dev/mem 文件，并在用户空间映射GPIO控制寄存器的物理内存。紧接着，调用 BCM2835 C 库函数```bcm2835_gpio_fsel(...)```设定指定管脚的功能。我们在这里把 ```P1_11``` 管脚设为输出```BCM2835_GPIO_FSEL_OUTP```。

初始化 GPIO，并设置管脚功能后，可以进行输出操作了。BCM2835 C 库函数```bcm2835_gpio_write（...）```给指定的GPIO设置一个输出值。

GPIO 使用结束后，调用 BCM2835 C 库函数```bcm2835_close(void)```进行清理工作。这个函数释放申请的内存，并关闭 /dev/mem 文件（它在 ```bcm2835_init(void)``` 中被打开了）。
