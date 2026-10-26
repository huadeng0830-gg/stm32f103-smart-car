# 第三方来源与许可范围

本仓库保留原工程中的供应商和参考代码，未删除其文件头、版权声明或免责声明。根目录 MIT 仅授权项目原创贡献与新增文档，不改写第三方代码的许可。

| 路径 | 文件中能确认的来源 | 处理 |
| --- | --- | --- |
| `Library/` | STMicroelectronics，STM32F10x StdPeriph V3.5.0 | 保留原始声明，不纳入本项目 MIT |
| `Start/core_cm3.*` | ARM Limited，CMSIS Cortex-M3 | 保留原始许可和免责声明，不纳入本项目 MIT |
| `Start/` 其余文件 | ST 启动和系统模板 | 保留原始声明，不纳入本项目 MIT |
| `User/stm32f10x_conf.h`、`User/stm32f10x_it.*` | ST 标准库工程模板，含项目引用调整 | 原模板部分不纳入本项目 MIT |
| `Hardware/OLED.c`、`OLED.h`、`OLED_Font.h` | 随原工程提供的 OLED 参考驱动，文件未标注完整来源和许可证 | 保留原样，未据此取得额外授权，不纳入本项目 MIT；复用前核对来源与适用条款 |

对无完整来源标记的 OLED 文件，后续维护应补充可核实的原始来源及许可，或替换为授权明确的实现，不推断其为原创或可任意再许可。

[ST 标准外设库入口](https://www.st.com/en/embedded-software/stm32-standard-peripheral-libraries.html)可用于查阅官方发行资料。具体组件以所用版本的原始条款为准，本文件不重新授予第三方代码权利。
