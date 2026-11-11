# STM32F103C8T6 四轮智能车

这是一个四轮小车练习项目。STM32F103C8T6 通过两块 TB6612FNG 驱动四个直流电机，用 TIM2 的四个通道输出 PWM。HC-05 接收蓝牙指令，OLED 显示当前动作和左右两侧的 PWM 设定值。

## 蓝牙指令

HC-05 使用 USART1，串口参数为 `9600 8N1`。每次发一个 ASCII 字符，字母用大写。

| 指令 | 动作 |
| --- | --- |
| `1`、`2`、`3` | 一档、二档、三档前进 |
| `B` | 后退 |
| `L`、`R` | 左转、右转 |
| `A`、`D` | 左移、右移 |
| `Q`、`E` | 原地逆时针、顺时针旋转（从车体上方看） |
| `S` | 停车，四路 PWM 比较值清零 |

横移和原地旋转的 PWM 比较值为 50。横移需要支持横移的轮组，实际方向需按车头朝向和轮组安装实测。

上电后等待指令，收到其他字符时保持原来的动作。蓝牙断开或手机停止发指令后，程序也会保留上一次的电机输出。

## 接线

| 模块 | 主控引脚 |
| --- | --- |
| 电机 PWM | PA0 到 PA3，对应 TIM2 CH1 到 CH4 |
| HC-05 | PA9（TX）接模块 RXD，PA10（RX）接模块 TXD |
| OLED | PB8 接 SCL，PB9 接 SDA |

各模块与主控共地。电机方向脚、驱动板供电和 STBY 接法见 [硬件与引脚](docs/HARDWARE.md)。

## 编译和测试

1. 克隆仓库，用 Keil µVision 打开根目录的 `Project.uvprojx`。
2. 按 [构建说明](docs/BUILD.md) 配置 ARM Compiler 5 和 STM32F1 器件包，选择 `Target 1` 后执行 Rebuild。
3. 首次上板时先架空车轮，确认上电时车轮静止，再用 `1` 和 `S` 测试前进和停车。其他动作的测试步骤见 [测试说明](docs/TESTING.md)。

蓝牙遥控版本已在 Keil 完整重建，0 错误、0 警告。蓝牙联调和整车动作待实测。见 [构建验证记录](docs/VERIFICATION.md)。

## 工程结构

```text
User/           主程序、配置与中断模板
Hardware/       PWM、电机、整车动作、OLED、HC-05；舵机和超声波占位
Start/          ST 启动文件、系统时钟与 ARM CMSIS
Library/        STM32F10x 标准外设库 V3.5.0
docs/           接线、构建、验证和扩展计划
Project.uvprojx Keil 工程入口
```

## 后续计划

先实测轮位、转向和停车，再加入蓝牙命令超时停车。SG90 舵机和 HC-SR04 超声波模块分别调通后，再做停车扫描和低速避障。后续可按需要加编码器测速、PID 或循迹。见 [开发路线](docs/ROADMAP.md)。

## 版本与许可

各版本的改动见 [变更记录](CHANGELOG.md)。

[MIT 许可](LICENSE) 适用于项目原创代码和新增文档。ST 标准库、ARM CMSIS、ST 模板和 OLED 参考驱动的来源与许可见 [第三方来源说明](THIRD_PARTY_NOTICES.md)。
