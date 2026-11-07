# 公开整理验证记录

## 2026-11-07 蓝牙遥控版本

用 Keil µVision 和 ARM Compiler 5.06 update 5 build 528 对 `Project.uvprojx` 的 `Target 1` 执行完整 Rebuild。进程退出码为 0。

```text
Program Size: Code=4404 RO-data=1788 RW-data=20 ZI-data=1636
".\Objects\Project.axf" - 0 Error(s), 0 Warning(s).
```

统一换行后，79 个源码及工程文件均与桌面工程一致，71 个工程文件引用均存在。蓝牙联调、烧录和整车动作尚待实测。

## 2026-10-26 电机基础版本

### 完整重建

使用 Keil MDK 5.24、ARM Compiler 5.06 update 5 build 528 和 Keil.STM32F1xx_DFP 2.2.0，对 `Project.uvprojx` 的 `Target 1` 执行完整 Rebuild。

```text
Program Size: Code=2908 RO-data=1772 RW-data=0 ZI-data=1632
".\Objects\Project.axf" - 0 Error(s), 0 Warning(s).
```

µVision 进程退出码为 0。以上为本次实际构建输出，不沿用原目录的历史产物。

### 文件核对

源码及工程文件共 79 个，SHA-256逐文件核对均与作者的现用目录一致；Keil 工程引用的 71 个文件均存在。此前对 `Hardware/Car.h` 的声明调整已撤回，原始文件按现用目录保留。

发布文件排除编译产物、个人 IDE 布局与调试配置。私有备考材料、简历和联系方式不进入本仓库。

### 验证边界

本次没有连接开发板、烧录或上板运行，也没有实测 PWM 波形、轮序、停止、整车动作或传感器。默认 `main.c` 没有运动入口，蓝牙与传感器是占位代码。编译成功不代表这些功能已完成。

后续模块的真实硬件验收按 [测试步骤](TESTING.md)追加，不覆盖本次记录。
