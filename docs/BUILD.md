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

`main.c` 依次调用 `OLED_Init()`、`PWM_Init()`、`Motor_Init()`，写入两行显示文本后进入空循环。唯一的前进调用已被注释。它没有蓝牙初始化、接收中断、命令解析、舵机、超声波或自动避障调用。

初始化 PWM 的比较值为 0，方向 GPIO 被置低。是否实际停车仍应测试驱动板和接线；动作函数需要后续显式接入主程序。

本次整理的验证结果单独记录于 [验证记录](VERIFICATION.md)。编译通过只证明软件能构建，不证明接线和运动功能已经验收。
