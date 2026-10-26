# 公开整理验证记录

日期：2026-10-26。对象为按作者正在完善的桌面工程同步后的公开源码。

## 完整重建

使用 Keil MDK 5.24、ARM Compiler 5.06 update 5 build 528 和 Keil.STM32F1xx_DFP 2.2.0，对 `Project.uvprojx` 的 `Target 1` 执行完整 Rebuild。

```text
Program Size: Code=2908 RO-data=1772 RW-data=0 ZI-data=1632
".\Objects\Project.axf" - 0 Error(s), 0 Warning(s).
```

µVision 进程退出码为 0。以上为本次实际构建输出，不沿用原目录的历史产物。

## 文件核对

源码及工程文件共 79 个，SHA-256逐文件核对均与作者的现用目录一致；Keil 工程引用的 71 个文件均存在。此前对 `Hardware/Car.h` 的声明调整已撤回，原始文件按现用目录保留。

发布文件排除编译产物、个人 IDE 布局与调试配置。私有备考材料、简历和联系方式不进入本仓库。

## 验证边界

本次没有连接开发板、烧录或上板运行，也没有实测 PWM 波形、轮序、停止、整车动作或传感器。默认 `main.c` 没有运动入口，蓝牙与传感器是占位代码。编译成功不代表这些功能已完成。

后续模块的真实硬件验收按 [测试步骤](TESTING.md)追加，不覆盖本次记录。
