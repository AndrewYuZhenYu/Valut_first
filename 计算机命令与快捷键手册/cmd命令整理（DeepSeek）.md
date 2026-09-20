好的，我来为你整理一份**全面且详细的 Windows 命令提示符（CMD）命令手册**。

CMD（Command Prompt）是 Windows 系统的命令行解释器，虽然 PowerShell 更强大，但 CMD 依然轻便、通用，在系统维护、网络诊断、批量处理等方面非常实用。

---

## 📁 一、文件与目录管理

这些是最基础的命令，用于浏览、创建、删除文件和文件夹。

| 命令 | 功能说明 | 使用示例 | 备注 |
| :--- | :--- | :--- | :--- |
| **`dir`** | 显示当前目录下的文件和子文件夹列表 | `dir`<br>`dir /w`（宽格式显示）<br>`dir /p`（分页显示） | 相当于 Linux 的 `ls` |
| **`cd`** | 切换当前目录 | `cd C:\Windows`<br>`cd ..`（返回上级目录）<br>`cd \`（返回根目录） | 切换盘符需要先输入盘符如 `D:` |
| **`mkdir`** 或 **`md`** | 创建新文件夹 | `mkdir MyFolder`<br>`md "My Folder"`（路径含空格要加引号） | 可一次创建多级目录 |
| **`rmdir`** 或 **`rd`** | 删除空文件夹 | `rmdir MyFolder`<br>`rmdir /s MyFolder`（删除文件夹及其所有内容） | `/s` 删除目录树，`/q` 安静模式 |
| **`del`** 或 **`erase`** | 删除文件 | `del file.txt`<br>`del *.tmp`（删除所有tmp文件）<br>`del /p *.*`（逐个确认删除） | 删除后不进回收站，谨慎使用 |
| **`copy`** | 复制文件 | `copy source.txt dest.txt`<br>`copy *.txt D:\backup\` | 可合并文件：`copy a.txt+b.txt c.txt` |
| **`xcopy`** | 高级复制文件和目录树 | `xcopy C:\src D:\dst /E /I` | `/E` 复制目录含空目录，`/H` 复制隐藏文件 |
| **`robocopy`** | 可靠的文件复制（适合大量数据） | `robocopy C:\src D:\dst /MIR` | 比 xcopy 更强大，支持断点续传和多线程 |
| **`move`** | 移动文件或目录 | `move file.txt D:\folder\`<br>`move old.txt new.txt`（重命名） | 也可用于重命名文件和文件夹 |
| **`rename`** 或 **`ren`** | 重命名文件或文件夹 | `ren oldname.txt newname.txt`<br>`ren *.jpg *.jpeg` | 不支持跨盘符重命名 |
| **`type`** | 在命令行中显示文本文件内容 | `type readme.txt` | 类似 Linux 的 `cat` |
| **`more`** | 分屏显示文本文件内容 | `type long.txt \| more`<br>`more long.txt` | 按空格翻页，按 Q 退出 |
| **`find`** | 在文件中搜索字符串 | `find "error" log.txt`<br>`find /i "hello" *.txt`（不区分大小写） | `/n` 显示行号 |
| **`findstr`** | 增强版字符串搜索（支持正则） | `findstr "error" *.log`<br>`findstr /r "[0-9]" file.txt` | 比 `find` 更强大 |

---

## 🖥️ 二、系统信息与管理

用于查询系统状态、关机、查看进程等。

| 命令 | 功能说明 | 使用示例 | 备注 |
| :--- | :--- | :--- | :--- |
| **`systeminfo`** | 显示详细的系统配置信息 | `systeminfo` | 包括 OS 版本、内存、网卡、补丁等 |
| **`tasklist`** | 列出当前正在运行的进程 | `tasklist`<br>`tasklist /fi "imagename eq chrome.exe"` | 类似 Linux 的 `ps` |
| **`taskkill`** | 终止一个或多个进程 | `taskkill /pid 1234`<br>`taskkill /im notepad.exe /f` | `/f` 强制终止 |
| **`shutdown`** | 关机、重启、注销 | `shutdown /s /t 60`（60秒后关机）<br>`shutdown /r /t 0`（立即重启）<br>`shutdown /a`（取消关机） | `/s`关机，`/r`重启，`/l`注销 |
| **`ver`** | 显示当前 Windows 版本号 | `ver` | 快速查看系统版本 |
| **`whoami`** | 显示当前登录的用户名 | `whoami` | 快速确认身份 |
| **`hostname`** | 显示计算机名称 | `hostname` | 可用于远程识别 |
| **`set`** | 显示、设置或删除环境变量 | `set`（显示所有）<br>`set PATH`（显示特定变量） | 仅对当前 CMD 窗口有效 |
| **`path`** | 显示或设置可执行文件的搜索路径 | `path`<br>`path C:\mybin;%PATH%` | 影响命令查找范围 |
| **`date`** 和 **`time`** | 显示或更改系统日期/时间 | `date`<br>`time` | 可加参数自动设置 |
| **`cls`** | 清空屏幕 | `cls` | 类似 Linux 的 `clear` |
| **`exit`** | 退出 CMD 窗口 | `exit` | 关闭当前命令行会话 |

---

## 🌐 三、网络相关命令

网络故障排查和配置的必备命令。

| 命令 | 功能说明 | 使用示例 | 备注 |
| :--- | :--- | :--- | :--- |
| **`ipconfig`** | 显示网络配置信息 | `ipconfig`（基本）<br>`ipconfig /all`（详细信息）<br>`ipconfig /release`（释放IP）<br>`ipconfig /renew`（重新获取IP）<br>`ipconfig /flushdns`（刷新DNS缓存） | 最常用的网络命令之一 |
| **`ping`** | 测试网络连通性和延迟 | `ping google.com`<br>`ping -n 10 192.168.1.1`（发送10个包）<br>`ping -t 8.8.8.8`（持续ping，Ctrl+C停止） | `/t` 持续 ping |
| **`tracert`** | 追踪数据包到达目标经过的路由 | `tracert google.com`<br>`tracert -d 8.8.8.8`（不解析主机名，更快） | 定位网络瓶颈 |
| **`pathping`** | 结合 ping 和 tracert，分析网络质量 | `pathping google.com` | 显示丢包率和延迟统计 |
| **`nslookup`** | 查询 DNS 解析记录 | `nslookup google.com`<br>`nslookup 8.8.8.8`（反向查询） | 可用于排查域名解析问题 |
| **`netstat`** | 显示网络连接、路由表、端口监听 | `netstat -an`（所有连接和端口）<br>`netstat -b`（显示进程名，需管理员）<br>`netstat -r`（显示路由表） | `/o` 显示进程 PID |
| **`route`** | 显示或修改本地 IP 路由表 | `route print`<br>`route add 0.0.0.0 mask 0.0.0.0 192.168.1.1` | 添加/删除静态路由 |
| **`arp`** | 显示或修改 ARP 缓存（IP→MAC） | `arp -a`（显示缓存）<br>`arp -d`（清空缓存） | 用于局域网问题排查 |
| **`netsh`** | 网络配置和排障的强大工具 | `netsh interface show interface`<br>`netsh winsock reset`（重置网络栈） | 子命令极多，可修改防火墙、WiFi 等 |
| **`telnet`** | 测试端口连通性 | `telnet 192.168.1.1 80` | 需先在“启用或关闭Windows功能”中开启 |
| **`curl`** | 命令行 HTTP 请求工具 | `curl https://api.example.com`<br>`curl -O https://file.zip`（下载文件） | Win10 1803 后内置 |
| **`ssh`** | SSH 远程连接 | `ssh user@192.168.1.100` | Win10 后内置 OpenSSH 客户端 |

---

## 🛠️ 四、磁盘与文件系统

管理磁盘分区、格式化、修复等。

| 命令 | 功能说明 | 使用示例 | 备注 |
| :--- | :--- | :--- | :--- |
| **`diskpart`** | 磁盘分区管理工具（交互式） | `diskpart` → `list disk` → `select disk 0` → `list partition` | 功能强大，操作需谨慎 |
| **`chkdsk`** | 检查磁盘错误并修复 | `chkdsk C:`（只读检查）<br>`chkdsk D: /f /r`（修复错误+恢复坏扇区） | `/f` 修复，`/r` 恢复 |
| **`format`** | 格式化磁盘 | `format E: /fs:NTFS /q`（快速格式化为NTFS） | 会清除所有数据 |
| **`vol`** | 显示磁盘卷标和序列号 | `vol C:` | 快速查看卷信息 |
| **`label`** | 创建、修改或删除磁盘卷标 | `label D: MyDrive` | 也可直接 `label` 按提示操作 |
| **`fsutil`** | 高级文件系统操作 | `fsutil volume queryfree C:`（查询空闲空间）<br>`fsutil fsinfo drives`（列出所有驱动器） | 管理员权限常用 |
| **`compact`** | 显示或更改 NTFS 压缩状态 | `compact /c /s C:\data`（压缩目录） | 节省空间但可能影响性能 |
| **`mountvol`** | 创建、列出或删除卷装载点 | `mountvol` | 用于管理盘符与卷的挂载 |

---

## 👥 五、用户与权限管理

管理用户账户、组成员、文件权限等。

| 命令 | 功能说明 | 使用示例 | 备注 |
| :--- | :--- | :--- | :--- |
| **`net user`** | 添加、修改或查看用户账户 | `net user`（列出所有用户）<br>`net user newuser pass /add`（添加用户）<br>`net user newuser /delete`（删除用户） | 需要管理员权限 |
| **`net localgroup`** | 管理本地组 | `net localgroup administrators`<br>`net localgroup users newuser /add` | 将用户加入组 |
| **`runas`** | 以其他用户权限运行程序 | `runas /user:admin "cmd.exe"`<br>`runas /profile /env /user:domain\name "notepad.exe"` | 无需切换登录 |
| **`whoami`** | 显示当前用户及权限 | `whoami /all` | 查看详细令牌信息 |
| **`icacls`** | 显示或修改文件/目录的 ACL 权限 | `icacls C:\folder`（查看）<br>`icacls C:\folder /grant user:(F)`（授予完全控制） | 比 `cacls` 更现代 |
| **`cacls`** | 旧版文件权限管理命令 | `cacls C:\folder /E /P user:R` | 已淘汰，建议用 `icacls` |
| **`takeown`** | 获取文件或文件夹的所有权 | `takeown /f C:\locked /r` | 常用于解决“拒绝访问”问题 |

---

## 🔄 六、进程与服务管理

| 命令 | 功能说明 | 使用示例 | 备注 |
| :--- | :--- | :--- | :--- |
| **`sc`** | 与服务控制管理器通信（创建、查询、停止服务等） | `sc query`（列出服务状态）<br>`sc stop Spooler`（停止打印服务）<br>`sc start WSearch`（启动搜索服务） | 功能极强，需管理员 |
| **`wmic`** | Windows Management Instrumentation 命令行 | `wmic process list brief`（列出进程）<br>`wmic process where name="chrome.exe" delete` | 部分新 Windows 已弃用，改用 PowerShell |
| **`schtasks`** | 计划任务管理 | `schtasks /query`（列出任务）<br>`schtasks /create /tn "MyTask" /tr "C:\script.bat" /sc daily` | 自动化脚本必备 |

---

## 📜 七、批处理与流程控制

用于编写 `.bat` 脚本时的常见命令。

| 命令 | 功能说明 | 示例/说明 |
| :--- | :--- | :--- |
| **`echo`** | 显示消息或开启/关闭回显 | `echo Hello`<br>`echo off` / `echo on` |
| **`@`** | 隐藏当前行的回显 | `@echo off` |
| **`rem`** | 注释 | `rem 这是一行注释` |
| **`pause`** | 暂停脚本执行，按任意键继续 | `pause` |
| **`if`** | 条件判断 | `if exist file.txt (echo 存在) else (echo 不存在)` |
| **`for`** | 循环命令 | `for %i in (*.txt) do echo %i` |
| **`setlocal`** / **`endlocal`** | 限制变量的作用范围 | 常用于防止变量污染 |
| **`call`** | 从一个批处理调用另一个 | `call other.bat` |
| **`goto`** | 跳转到标签 | `goto :label` |
| **`title`** | 修改 CMD 窗口标题 | `title 我的脚本` |
| **`color`** | 更改控制台前景/背景色 | `color 0A`（黑底绿字） |
| **`timeout`** | 延迟指定秒数 | `timeout /t 5 /nobreak` |

---

## 🔍 八、实用小技巧与杂项

| 命令 | 功能说明 | 示例 |
| :--- | :--- | :--- |
| **`|`**（管道符） | 将前一个命令的输出作为后一个命令的输入 | `dir \| find ".txt"` |
| **`>`** | 将输出重定向到文件（覆盖） | `dir > list.txt` |
| **`>>`** | 将输出追加到文件末尾 | `echo Done >> log.txt` |
| **`<`** | 从文件读取输入 | `sort < input.txt` |
| **`&`** | 依次执行多个命令 | `cd C:\ & dir` |
| **`&&`** | 只有前一个命令成功时才执行下一个 | `ping google.com && echo 在线` |
| **`\|\|`** | 只有前一个命令失败时才执行下一个 | `copy a.txt b.txt \|\| echo 复制失败` |
| **`cd`** 或 **`chdir`** | 查看当前完整路径 | `cd` 不带参数 |
| **`start`** | 在新窗口中运行程序或打开文件/网址 | `start notepad.exe`<br>`start https://google.com` |
| **`where`** | 查找命令或文件的位置 | `where ping`<br>`where *.exe` |

---

## ⚠️ 使用提醒

1. **管理员权限**：很多系统级命令（如 `diskpart`、`chkdsk /f`、`netsh winsock reset`）需要以**管理员身份运行 CMD**。右键“命令提示符” → “以管理员身份运行”。

2. **不可逆操作**：`del`、`format`、`rmdir /s` 等命令删除或格式化的数据**不会进入回收站**，请确认后再执行。

3. **获取帮助**：大部分命令支持 `/?` 参数显示帮助信息，例如 `ping /?`、`robocopy /?`。

4. **路径含空格**：务必用英文双引号括起来，例如 `cd "C:\Program Files"`。

5. **环境差异**：部分命令（如 `curl`、`ssh`）从 Win10 1803 开始才内置，旧系统可能需要单独安装。

6. **现代替代**：如果你需要更强大的脚本能力，建议逐步学习 **PowerShell**，它兼容多数 CMD 命令且功能更丰富。

---

希望这份 CMD 命令手册对你有帮助。如果需要进一步了解某个命令的详细用法，或想学习批处理脚本编写，可以随时告诉我。