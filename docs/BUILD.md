# 构建说明

## 原工程配置

| 项目 | 配置 |
| --- | --- |
| IDE | Keil µVision / MDK |
| MCU | STM32F103C8，对应 STM32F103C8T6 |
| 编译器记录 | ARM Compiler 5，V5.06 update 5 build 528 |
| 器件包记录 | Keil.STM32F1xx_DFP.2.2.0 |
| 启动文件 | Start/startup_stm32f10x_md.s |
| 库 | STM32F10x StdPeriph V3.5.0，仓库随附 |
| Flash / SRAM | 64 KiB / 20 KiB，采用工程内配置 |
| 头文件目录 | Start、User、Library、Hardware |
| 预定义 | USE_STDPERIPH_DRIVER |

工程保留 ARM Compiler 5 配置；没有声称已迁移到 Arm Compiler 6、GCC 或 STM32CubeIDE。若本机使用其他版本，先确认兼容性，不直接把更换工具链当成同一次功能更新。

## 操作

1. 打开根目录 `Project.uvprojx`，安装或选择对应器件包与 ARM Compiler 5。
2. 使用 Rebuild 编译整个目标，保存错误、警告与代码占用输出。
3. 在 Options for Target 中按实际下载器选择 ST-Link 与 SWD，并检查 Flash 下载算法。
4. 下载前架空车轮，核对电机电源和可用停止方式。首次验证只测试一个通道。

输出位于 `Objects/` 和 `Listings/`，被 `.gitignore` 排除。当前工程默认不生成 HEX，需要时在 Output 中启用；不要把旧 `Objects/` 文件当作当前源码的编译证据。

## 主程序行为

`main.c` 初始化 OLED、PWM、电机和 HC-05，随后轮询 USART1 接收字节。收到有效指令时执行对应动作，并刷新 OLED 上的左右 PWM 设定值和方向。指令见 [README](../README.md#蓝牙指令)。

初始化 PWM 的比较值为 0，方向 GPIO 被置低。上电静止和收到 `S` 后的停车行为应分别在实物上验证。

本次整理的验证结果单独记录于 [验证记录](VERIFICATION.md)。编译通过只证明软件能构建，不证明接线和运动功能已经验收。
