在 Windows 系统中，**CMD（命令提示符，Command Prompt）** 是一个基于文本的命令行解释程序。虽然现在微软大力推行更现代的 PowerShell 和 Windows Terminal，但 CMD 依然凭借其极快的启动速度、低资源占用以及在旧脚本/批处理（.bat）中的绝对统治力，成为每个 IT 从业者和高级用户的必备工具。

为了让你查阅和学习时一目了然，我们按照**实际应用场景**对 CMD 命令进行了分门别类的详细整理，并在最后附带了一些高效使用 CMD 的“冷知识”和保姆级操作技巧。

## 📂 一、 目录与文件操作（基础高频）

这是在命令行中移动、查看、管理文件和文件夹时最常用的基础命令。

|**命令**|**全称与功能说明**|**实用示例与参数解析**|
|---|---|---|
|**`cd`**|**C**hange **D**irectory<br><br>  <br><br>切换当前工作目录|`cd \` 切换到当前盘符的根目录<br><br>  <br><br>`cd ..` 返回上一级目录<br><br>  <br><br>`cd /d D:\Work` **跨盘符切换**（必须加 `/d` 参数才能直接从 C 盘跳到 D 盘）|
|**`dir`**|**Dir**ectory<br><br>  <br><br>列出当前目录下的文件和文件夹|`dir` 显示当前目录的简要列表<br><br>  <br><br>`dir /a` 显示包含隐藏文件在内的所有文件<br><br>  <br><br>`dir /s` 递归显示当前目录及**所有子目录**下的文件|
|**`md` / `mkdir`**|**M**ake **D**irectory<br><br>  <br><br>创建新文件夹|`md NewFolder` 在当前目录下创建一个名为 NewFolder 的文件夹|
|**`rd` / `rmdir`**|**R**emove **D**irectory<br><br>  <br><br>删除文件夹|`rd EmptyFolder` 删除空文件夹<br><br>  <br><br>`rd /s /q BadFolder` **强制删除非空文件夹**（`/s` 包含子目录，`/q` 静默模式不提示确认，危险操作！）|
|**`copy`**|**Copy**<br><br>  <br><br>复制文件（不含文件夹）|`copy a.txt D:\Backup\` 将 a.txt 复制到 D 盘 Backup 目录下<br><br>  <br><br>`copy *.txt Combined.txt` 将当前目录下所有 txt 文件内容合并到 Combined.txt 中|
|**`xcopy`**|**E**xtended **Copy**<br><br>  <br><br>高级复制（可复制目录树）|`xcopy C:\Src D:\Dst /e /h /y` 复制 Src 目录下的所有子目录（含空目录 `/e`）、隐藏文件（`/h`），且覆盖同名文件时不提示（`/y`）|
|**`move`**|**Move**<br><br>  <br><br>移动文件或重命名文件夹|`move a.txt D:\` 将 a.txt 移动到 D 盘根目录<br><br>  <br><br>`move OldName NewName` 将文件夹或文件重命名|
|**`del` / `erase`**|**Del**ete<br><br>  <br><br>删除文件（注意：不经过回收站！）|`del test.txt` 删除 test.txt<br><br>  <br><br>`del /f /s /q *.log` 强制（`/f`）静默（`/q`）删除当前及子目录下（`/s`）的所有 .log 日志文件|
|**`ren` / `rename`**|**Ren**ame<br><br>  <br><br>重命名文件|`ren report.txt summary.txt` 将 report.txt 改名为 summary.txt|
|**`type`**|**Type**<br><br>  <br><br>在命令行中查看文本文件内容|`type config.ini` 直接在窗口中打印出 config.ini 的文本内容|

## 🌐 二、 网络诊断与管理（排查网络必用）

当你的电脑断网、卡顿、或者无法访问某个服务器时，这些命令是排查网络故障的“三大件”。

|**命令**|**全称与功能说明**|**实用示例与参数解析**|
|---|---|---|
|**`ping`**|**Packet Internet Groper**<br><br>  <br><br>测试网络连通性及延迟|`ping [www.baidu.com](https://www.baidu.com)` 向目标发送 4 个数据包测试连通性<br><br>  <br><br>`ping -t 192.168.1.1` **不停地连续 Ping** 目标（按 `Ctrl + C` 退出），常用于观察网络抖动<br><br>  <br><br>`ping -n 10 10.0.0.1` 指定发送 10 个数据包|
|**`ipconfig`**|**IP** **Config**uration<br><br>  <br><br>显示和管理本地网络适配器设置|`ipconfig` 查看本机 IP 地址、子网掩码和默认网关<br><br>  <br><br>`ipconfig /all` 查看极其详细的信息（包含 MAC 地址、DNS 服务器、DHCP 状态）<br><br>  <br><br>`ipconfig /flushdns` **刷新 DNS 缓存**（上网打不开网页但 QQ 能上时，必试此命令）|
|**`netstat`**|**Net**work **Stat**istics<br><br>  <br><br>显示网络连接、路由表及端口状态|`netstat -ano` 显示所有连接的端口以及对应的进程 PID（常用于排查端口被谁占用了）<br><br>  <br><br>`netstat -p tcp` 仅显示 TCP 协议的连接状态|
|**`tracert`**|**Trace** **R**ou**t**e<br><br>  <br><br>路由追踪（查看数据包经过了哪些路由器）|`tracert 8.8.8.8` 跟踪从你家电脑到谷歌 DNS 服务器之间经过的所有网络节点，能查出网络卡在哪个骨干网上|
|**`nslookup`**|**N**ame **S**erver **Lookup**<br><br>  <br><br>查询域名解析（DNS）是否正常|`nslookup github.com` 查询域名对应的 IP 地址<br><br>  <br><br>`nslookup github.com 8.8.8.8` 使用指定的 DNS 服务器（8.8.8.8）去解析目标域名|

## 💻 三、 系统信息、进程与性能管理

用于监控电脑当前的运行状态、强制结束卡死的软件或者查看硬件配置。

|**命令**|**全称与功能说明**|**实用示例与参数解析**|
|---|---|---|
|**`systeminfo`**|**System Info**rmation<br><br>  <br><br>查询极其详细的系统和硬件信息|`systeminfo` 运行后会加载一段时间，输出包括：OS 版本、主板 BIOS、内存大小、甚至**系统初始安装日期**和已安装的补丁列表。|
|**`tasklist`**|**Task List**<br><br>  <br><br>列出当前系统中运行的所有进程|`tasklist` 显示映像名称、PID、会话名和内存占用<br><br>  <br><br>`tasklist /fi "memusage gt 100000"` 过滤（`/fi`）显示内存占用大于 100MB（100000 KB）的进程|
|**`taskkill`**|**Task Kill**<br><br>  <br><br>结束指定的进程/顽固后台软件|`taskkill /pid 4120` 结束 PID 为 4120 的进程<br><br>  <br><br>`taskkill /f /im notepad.exe` **强制（`/f`）结束**所有映像名称（`/im`）为 notepad.exe（记事本）的程序|
|**`chkdsk`**|**Ch**ec**k** **D**i**sk**<br><br>  <br><br>检查磁盘驱动器中的错误并修复|`chkdsk C: /f` 检查并自动修复（`/f`） C 盘的文件系统错误（通常需要重启电脑并在开机前执行）|
|**`sfc`**|**S**ystem **F**ile **C**hecker<br><br>  <br><br>系统文件检查器（修复系统受损核心文件）|`sfc /scannow` **扫描并自动修复所有受损的系统核心文件**（蓝屏、系统组件报错、功能异常时的免重装修复神技，需要管理员权限）|
|**`dxdiag`**|**DirectX Diagnostic Tool**<br><br>  <br><br>直接弹出 DirectX 诊断工具窗口|`dxdiag` 能够非常直观地查看显卡型号、显存、显示驱动等硬件参数（常用于买新电脑时验机）|

## ⚙️ 四、 磁盘、用户与高级系统配置

这些命令通常涉及到更底层的 Windows 策略、安全及自动化控制。

|**命令**|**功能说明**|**实用示例与参数解析**|
|---|---|---|
|**`shutdown`**|**控制计算机关机、重启或休眠**|`shutdown /s /t 3600` **定时关机**：在 3600 秒（1小时）后自动关机<br><br>  <br><br>`shutdown /r /t 0` **立即重启**（`/r` 代表重启，`/t 0` 代表倒计时 0 秒）<br><br>  <br><br>`shutdown /a` **取消自动关机**（手抖按错关机键后的救星）|
|**`net user`**|**管理系统本地用户账户**<br><br>  <br><br>（增加、删除、改密码）|`net user` 查看当前电脑的所有用户名<br><br>  <br><br>`net user admin 123456 /add` 创建一个名为 admin、密码为 123456 的新用户<br><br>  <br><br>`net user admin *` 修改 admin 的密码（输入时密码不可见，更安全）|
|**`gpupdate`**|**G**roup **P**olicy Update<br><br>  <br><br>强制立即刷新组策略|`gpupdate /force` 当你在策略组（gpedit.msc）中修改了系统限制（如禁用U盘、限制更新）后，不用重启，用它直接强制生效。|
|**`diskpart`**|**Disk Part**ition<br><br>  <br><br>极为强大的磁盘分区管理工具|输入 `diskpart` 后会进入一个独立的磁盘交互环境，可以实现常规软件无法做到的硬格式化、隐藏分区、转换 GPT/MBR 格式等（新手慎用）。|
|**`format`**|**Format**<br><br>  <br><br>格式化磁盘分区|`format D: /fs:ntfs /q` 使用 NTFS 文件系统（`/fs`）快速（`/q`）格式化 D 盘。|

## 🧰 五、 常用“一键直达”的独立组件命令

在 CMD 中直接输入以下命令并回车，可以**绕开繁琐的控制面板**，直接弹出对应的 Windows 图形化功能窗口：

- **`calc`**：弹出内置计算器。
    
- **`notepad`**：新建并打开一个记事本。
    
- **`regedit`**：打开**注册表编辑器**（极重要，修改系统核心配置）。
    
- **`msconfig`**：打开系统配置（可管理系统引导、服务、服务启动项）。
    
- **`cleanmgr`**：打开 Windows 官方的**磁盘清理工具**（清理系统垃圾和 C 盘）。
    
- **`mstsc`**：打开**远程桌面连接**（Remote Desktop Connection）。
    
- **`compmgmt.msc`**：打开**计算机管理**（包含设备管理器、磁盘管理、事件查看器等大一统工具）。
    
- **`services.msc`**：打开**本地服务列表**（关闭或开启 Windows Update 等后台服务）。
    

## 🔥 CMD 高级操作技巧（效率翻倍）

学会这些技巧，在别人眼里你就是“命令行高手”：

### 1. Tab 键自动补全（最核心的偷懒技巧）

- 你不需要完整输入一长串的文件夹名称或文件名。例如你想进入一个叫 `VeryLongFolderName` 的目录，只需输入 `cd Ve` 然后**按下键盘上的 `Tab` 键**，CMD 会自动帮你把名字补全。如果有多个相似的，连续按 `Tab` 可以来回切换。
    

### 2. 管道符与重定向（数据导出）

- **重定向 `>` 或 `>>`**：如果你想把命令输出的一大堆文字保存下来查看，不要用鼠标去苦苦复制。
    
    - `systeminfo > D:\sys_info.txt`：把系统信息**覆盖写入**到 D 盘的 txt 文件中。
        
    - `ipconfig >> D:\net_log.txt`：把网络信息**追加写入**到文件的末尾。
        
- **管道符 `|`**：把前一个命令的输出，作为后一个命令的输入。
    
    - 示例：`tasklist | findstr "chrome"`（在所有的进程列表中，只过滤并显示包含 "chrome" 关键字的行）。
        

### 3. 多条命令连着发

- **`&`（无条件顺序执行）**：`cd /d D:\Work & dir`（先切换到目录，接着立即列出文件，不管前面有没有成功）。
    
- **`&&`（成功后才执行）**：`ping 192.168.1.1 && echo 网络正常`（只有当 Ping 通了，屏幕上才会打印出“网络正常”）。
    

### 4. 快捷键小贴士

- **`Ctrl + C`**：如果一个命令正在疯狂刷屏或者卡死（比如 `ping -t`），按它能**立即强行中止**当前命令。
    
- **方向键 `↑` 或 `↓`**：可以快速翻看并直接调用你**之前输入过的历史命令**，免去重复打字的烦恼。
    
- **`cls`**：屏幕上的东西太多太杂了？输入 `cls` 回车，瞬间清空屏幕，还你一个干净的界面。