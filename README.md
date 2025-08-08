# 适用于Linux环境的LVGL模拟器

------

## 一、简介

对LVGL官方项目进行了一些整合和修改，以达到开箱即用的目的。添加了使用VSCode和CLion开发调试的配置。

已验证可用的环境有：

- WSL2 + Ubuntu 22.04
- VMware + Ubuntu 22.04
- Fedora 42 KDE Plasma Wayland

*其他环境没有尝试过，欢迎添加对不同环境的支持。*

### 版本说明

| 组件         | 版本           | 备注                   |
| ------------ | -------------- | ---------------------- |
| `lvgl`       | `release/v8.3` | 不支持直接更换其他版本 |
| `lv_drivers` | `release/v8.3` | 不支持直接更换其他版本 |

## 二、操作指南

### 获取项目

克隆仓库并初始化子模块：

```bash
git clone --recursive https://github.com/haoruanwn/lvglsim_linux.git
```

或者分步执行：

```bash
# 1. 克隆本仓库
git clone https://github.com/haoruanwn/lvglsim_linux.git

# 2. 进入项目目录并初始化子模块
cd lvglsim_linux
git submodule update --init --recursive
```

### 编译、运行与调试

本项目已添加VSCode和CLion的配置文件，可直接用于开发和调试。

具体方法请参考：

- [使用VSCode进行开发调试](https://www.google.com/search?q=./docs/使用vscode开发调试.md&authuser=1)

  效果展示：

  ![Snipaste_2025-08-08_14-03-39](https://markdownforyuanhao.oss-cn-hangzhou.aliyuncs.com/img1/20250808142437007.png)

- [使用CLion进行开发调试](https://www.google.com/search?q=./docs/使用clion开发调试.md&authuser=1)

  效果展示：

  ![Snipaste_2025-08-08_14-05-05](https://markdownforyuanhao.oss-cn-hangzhou.aliyuncs.com/img1/20250808142450035.png)

也可以直接使用命令行进行编译运行：

```bash
# 调用预设的配置 (例如 Debug)
cmake --preset Debug

# 使用预设进行构建
cmake --build --preset Debug
```

## 三、引用与致谢

- **LVGL官方仓库**
  - [lvgl/lv_drivers](https://github.com/lvgl/lv_drivers.git)
  - [lvgl/lvgl](https://github.com/lvgl/lvgl.git)
