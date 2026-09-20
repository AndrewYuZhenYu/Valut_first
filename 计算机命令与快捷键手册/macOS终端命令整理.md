# macOS 终端常用命令整理

macOS 基于 Darwin 内核，终端（Terminal）默认使用 **zsh**（自 macOS Catalina 起），同时兼容大部分 Unix/Linux 命令。本文整理 macOS 终端下最常用的命令，涵盖文件管理、系统操作、网络诊断、开发工具等场景。

---

## 📁 一、文件与目录管理

这些是与 Linux 通用的基础命令，用于日常文件浏览、创建、删除和查找。

| 命令 | 功能说明 | 使用示例 | 备注 |
| :--- | :--- | :--- | :--- |
| **`ls`** | 列出目录内容 | `ls`<br>`ls -la`（显示隐藏文件及详细信息）<br>`ls -lh`（人类可读的文件大小） | `-a` 显示隐藏文件，`-l` 长格式，`-h` 易读大小 |
| **`cd`** | 切换当前目录 | `cd /Users/xxx/Documents`<br>`cd ..`（返回上级）<br>`cd ~`（返回用户主目录）<br>`cd -`（返回上一个目录） | `~` 代表当前用户的主目录 `/Users/用户名` |
| **`pwd`** | 显示当前工作目录的完整路径 | `pwd` | Print Working Directory |
| **`mkdir`** | 创建新目录 | `mkdir MyFolder`<br>`mkdir -p a/b/c`（递归创建多级目录） | `-p` 自动创建父级目录 |
| **`rmdir`** | 删除空目录 | `rmdir emptyFolder` | 只能删除空目录 |
| **`rm`** | 删除文件或目录 | `rm file.txt`<br>`rm -rf folder/`（强制递归删除）<br>`rm -i *.txt`（逐个确认删除） | **⚠️ 谨慎使用 `-rf`，不可恢复** |
| **`cp`** | 复制文件或目录 | `cp src.txt dest.txt`<br>`cp -r folder/ backup/`（递归复制目录）<br>`cp -a src/ dst/`（保留属性完整复制） | `-r` 递归，`-a` 归档模式 |
| **`mv`** | 移动或重命名文件/目录 | `mv old.txt new.txt`（重命名）<br>`mv file.txt ~/Documents/`（移动） | 同盘移动极快（只改元数据） |
| **`touch`** | 创建空文件或更新文件时间戳 | `touch newfile.txt`<br>`touch -t 202501011200 file.txt`（指定时间戳） | 文件已存在时只更新时间戳 |
| **`cat`** | 查看/拼接文件内容 | `cat file.txt`<br>`cat a.txt b.txt > c.txt`（合并文件） | 适合小文件 |
| **`less`** | 分页查看文件内容 | `less large.log`<br>`less -N file.txt`（显示行号） | 按 `q` 退出，`/` 搜索，`n` 下一个 |
| **`head`** / **`tail`** | 查看文件头/尾部 | `head -n 20 file.txt`（前20行）<br>`tail -f app.log`（实时追踪日志） | `tail -f` 极常用，`Ctrl+C` 退出 |
| **`ln`** | 创建链接 | `ln -s /path/to/target linkname`（软链接）<br>`ln target hardlink`（硬链接） | macOS 也支持 Finder 的"替身"（Alias），与软链接不同 |
| **`open`** | 用默认应用打开文件/目录/URL | `open .`（在 Finder 中打开当前目录）<br>`open -a "Visual Studio Code" file.txt`<br>`open https://google.com` | **macOS 特有命令**，非常实用 |
| **`find`** | 搜索文件 | `find . -name "*.txt"`<br>`find . -type d -name "node_modules"`<br>`find . -mtime -7`（最近7天修改的文件） | 功能强大，配合 `-exec` 可执行操作 |
| **`mdfind`** | Spotlight 搜索（按内容/元数据） | `mdfind "kind:pdf"`<br>`mdfind -name "报告"`<br>`mdfind -onlyin ~/Documents "关键词"` | **macOS 特有**，比 `find` 更快（基于索引） |
| **`fd`** | 更快的文件搜索（需 brew 安装） | `fd pattern`<br>`fd -e txt`（按扩展名）<br>`fd --type d`（只搜目录） | `brew install fd`，比 `find` 更快更友好 |

---

## 💾 二、文件内容处理

查看、搜索、编辑文件内容的常用命令。

| 命令 | 功能说明 | 使用示例 | 备注 |
| :--- | :--- | :--- | :--- |
| **`grep`** | 文本搜索（支持正则） | `grep "error" app.log`<br>`grep -r "TODO" ./src/`（递归搜索）<br>`grep -i -n "warning" *.log`（忽略大小写+行号） | `-v` 反向匹配，`-c` 计数，`-A/-B` 上下文行 |
| **`ripgrep` (rg)** | 极快的文本搜索（需 brew） | `rg "pattern"`<br>`rg -t py "import"`（只搜 Python 文件）<br>`rg --hidden "TODO"` | `brew install ripgrep`，默认忽略 .gitignore |
| **`wc`** | 统计行数/单词数/字节数 | `wc -l file.txt`（行数）<br>`wc -w file.txt`（单词数）<br>`wc -c file.txt`（字节数） | 常配合管道使用 |
| **`sort`** | 排序文本行 | `sort file.txt`<br>`sort -n numbers.txt`（按数值排序）<br>`sort -u file.txt`（去重排序） | `-r` 逆序，`-k` 按列排序 |
| **`uniq`** | 去重（需先排序） | `sort file.txt \| uniq`<br>`sort file.txt \| uniq -c`（统计出现次数）<br>`sort file.txt \| uniq -d`（只显示重复行） | 通常与 `sort` 配合使用 |
| **`cut`** | 按列截取文本 | `cut -d',' -f1,3 data.csv`（逗号分隔取1,3列）<br>`cut -c1-10 file.txt`（每行前10字符） | `-d` 分隔符，`-f` 字段 |
| **`sed`** | 流编辑器，文本替换处理 | `sed 's/old/new/g' file.txt`（全局替换）<br>`sed -i '' 's/foo/bar/g' *.txt`（原地替换） | **macOS 注意：`-i` 后须加 `''`**（与 Linux 不同） |
| **`awk`** | 强大的文本处理语言 | `awk '{print $1, $3}' data.txt`<br>`awk -F',' '{sum+=$2} END{print sum}' data.csv` | 适合处理结构化文本 |
| **`diff`** | 比较两个文件的差异 | `diff file1.txt file2.txt`<br>`diff -r dir1/ dir2/`（递归比较目录） | 输出格式可选 `-u`（unified） |
| **`vim`** / **`nano`** | 终端文本编辑器 | `vim file.txt`<br>`nano file.txt` | macOS 自带 vim 和 nano |

---

## 🖥️ 三、系统信息与管理

查询 macOS 系统状态、硬件信息、进程管理。

| 命令 | 功能说明 | 使用示例 | 备注 |
| :--- | :--- | :--- | :--- |
| **`uname`** | 显示系统信息 | `uname -a`（全部信息）<br>`uname -m`（硬件架构，如 arm64）<br>`uname -r`（内核版本） | macOS 返回 Darwin 内核版本 |
| **`sw_vers`** | 显示 macOS 版本信息 | `sw_vers`<br>`sw_vers -productVersion`（仅版本号） | **macOS 特有** |
| **`system_profiler`** | 详细系统报告 | `system_profiler SPHardwareDataType`（硬件概览）<br>`system_profiler SPDisplaysDataType`（显示器信息）<br>`system_profiler SPSoftwareDataType`（软件信息） | **macOS 特有**，相当于"系统信息"App |
| **`sysctl`** | 读取/设置内核参数 | `sysctl -a \| grep cpu`（CPU 相关信息）<br>`sysctl hw.memsize`（物理内存大小）<br>`sysctl machdep.cpu.brand_string`（CPU 型号） | 大量硬件信息可通过此命令获取 |
| **`top`** | 实时查看进程和系统资源 | `top`<br>`top -u -s 5`（每5秒刷新按CPU排序） | 按 `q` 退出，`?` 查看帮助 |
| **`htop`** | 增强版进程管理器（需 brew） | `htop` | `brew install htop`，界面更友好 |
| **`ps`** | 显示当前进程状态 | `ps aux`（所有用户所有进程）<br>`ps aux \| grep chrome`（查找特定进程） | `a`所有用户，`u`用户格式，`x`无终端进程 |
| **`kill`** | 向进程发送信号 | `kill 1234`（优雅终止）<br>`kill -9 1234`（强制终止）<br>`killall "Google Chrome"`（按名称终止） | 先用 `kill` 15（默认），不行再用 `-9` |
| **`lsof`** | 列出打开的文件/端口 | `lsof -i :8080`（查看占用8080端口的进程）<br>`lsof -p 1234`（某进程打开的文件）<br>`lsof -u $(whoami)`（当前用户打开的文件） | 排查端口占用时最常用 |
| **`du`** | 磁盘用量统计 | `du -sh *`（当前目录各文件/夹大小）<br>`du -sh .`（当前目录总大小）<br>`du -d 1 -h ~/`（主目录一级子目录大小） | `-s` 汇总，`-h` 人类可读 |
| **`df`** | 磁盘空间查看 | `df -h`（已挂载磁盘的可用空间） | `-h` 人类可读格式 |
| **`ncdu`** | 交互式磁盘用量分析（需 brew） | `ncdu ~/` | `brew install ncdu`，比 `du` 直观 |
| **`diskutil`** | 磁盘管理工具 | `diskutil list`（列出所有磁盘和分区）<br>`diskutil info /`（根卷信息）<br>`diskutil verifyVolume /`（验证磁盘） | **macOS 特有**，相当于"磁盘工具"App 的命令行版 |
| **`vm_stat`** | 查看虚拟内存统计 | `vm_stat`<br>`vm_stat 1`（每秒刷新） | **macOS 特有**，类似 Linux 的 `vmstat` |
| **`pmset`** | 电源管理设置 | `pmset -g`（查看当前电源设置）<br>`pmset -g batt`（电池状态）<br>`pmset sleepnow`（立即睡眠） | **macOS 特有**，`caffeinate` 可阻止睡眠 |
| **`caffeinate`** | 阻止系统睡眠 | `caffeinate -i make`（编译期间禁止空闲睡眠）<br>`caffeinate -d -t 3600`（禁止显示器休眠1小时） | **macOS 特有**，运行长时间任务时很有用 |
| **`nettop`** | 实时网络流量监控 | `nettop -m tcp`（只看TCP连接） | **macOS 特有**，按 `q` 退出 |
| **`hostname`** | 显示/设置主机名 | `hostname`<br>`sudo scutil --set HostName "my-mac"` | 也用于网络识别 |

---

## 🌐 四、网络相关命令

网络诊断、配置和测试的必备命令。

| 命令 | 功能说明 | 使用示例 | 备注 |
| :--- | :--- | :--- | :--- |
| **`ifconfig`** | 查看/配置网络接口 | `ifconfig`<br>`ifconfig en0`（查看 Wi-Fi 接口详情） | macOS 上 `en0` 通常是 Wi-Fi，`en1`/`enX` 是以太网 |
| **`networksetup`** | 管理网络配置 | `networksetup -listallhardwareports`（列出所有网络接口）<br>`networksetup -getdnsservers Wi-Fi`（查看DNS）<br>`sudo networksetup -setdnsservers Wi-Fi 8.8.8.8`（设置DNS） | **macOS 特有**，命令行版"网络"偏好设置 |
| **`ping`** | 测试网络连通性 | `ping google.com`<br>`ping -c 4 8.8.8.8`（发送4个包后停止） | macOS 默认持续 ping，`-c` 指定次数 |
| **`traceroute`** | 追踪网络路径 | `traceroute google.com`<br>`traceroute -n 8.8.8.8`（不解析主机名） | 对应 Windows 的 `tracert` |
| **`nslookup`** / **`dig`** | DNS 查询工具 | `nslookup google.com`<br>`dig google.com`（更详细）<br>`dig -x 8.8.8.8`（反向查询） | `dig` 信息更丰富 |
| **`curl`** | 发送 HTTP 请求/下载文件 | `curl https://api.example.com`<br>`curl -O https://example.com/file.zip`（下载）<br>`curl -X POST -d '{"key":"val"}' https://api.example.com` | 功能极强，支持多种协议 |
| **`wget`** | 下载文件（需 brew） | `wget https://example.com/file.zip` | `brew install wget`，支持递归下载 |
| **`ssh`** | 远程登录 | `ssh user@192.168.1.1`<br>`ssh -i ~/.ssh/key user@host`（指定私钥）<br>`ssh -p 2222 user@host`（指定端口） | macOS 自带 OpenSSH |
| **`scp`** | 远程文件拷贝 | `scp file.txt user@host:/path/`<br>`scp -r folder/ user@host:/path/`（递归拷贝）<br>`scp user@host:/path/file.txt .`（从远程下载） | 基于 SSH 协议 |
| **`rsync`** | 高效的远程/本地同步 | `rsync -avz src/ dst/`<br>`rsync -avz -e ssh src/ user@host:/path/`（远程同步） | `-a` 归档，`-v` 详细，`-z` 压缩，`--delete` 删除目标多余文件 |
| **`netstat`** | 查看网络连接和统计 | `netstat -an \| grep LISTEN`（查看监听端口）<br>`netstat -rn`（查看路由表） | 部分功能已被 `lsof -i` 替代 |
| **`arp`** | ARP 缓存管理 | `arp -a`（查看 ARP 表） | 查看局域网设备 |
| **`tcpdump`** | 抓包分析 | `sudo tcpdump -i en0`（抓取 Wi-Fi 网卡包）<br>`sudo tcpdump -i en0 port 443`（只抓443端口） | 需 root 权限，功能强大 |
| **`airport`** | Wi-Fi 扫描（隐藏命令） | `/System/Library/PrivateFrameworks/Apple80211.framework/Versions/Current/Resources/airport -s`（扫描 Wi-Fi）<br>建议创建别名：`alias airport='/System/Library/PrivateFrameworks/Apple80211.framework/Versions/Current/Resources/airport'` | **macOS 特有隐藏工具**，查看 Wi-Fi 信号强度等 |

---

## 👤 五、用户与权限管理

管理用户账户、文件权限和 ACL。

| 命令 | 功能说明 | 使用示例 | 备注 |
| :--- | :--- | :--- | :--- |
| **`whoami`** | 显示当前登录用户名 | `whoami` | 快速确认身份 |
| **`who`** | 显示当前登录的用户 | `who` | 列出所有登录会话 |
| **`id`** | 显示用户ID和组信息 | `id`<br>`id username` | UID、GID 及所属组 |
| **`chmod`** | 修改文件/目录权限 | `chmod 755 script.sh`<br>`chmod +x script.sh`（添加执行权限）<br>`chmod -R 644 *.txt`（递归设置） | `r=4 w=2 x=1`，`u/g/o` 分别代表所有者/组/其他人 |
| **`chown`** | 修改文件/目录所有者 | `sudo chown user:staff file.txt`<br>`sudo chown -R user:staff folder/`（递归） | macOS 默认用户组是 `staff` |
| **`sudo`** | 以超级用户权限执行命令 | `sudo make install`<br>`sudo -s`（获取 root shell）<br>`sudo !!`（以 sudo 重新执行上一条） | 输入当前用户密码（非 root 密码） |
| **`dscl`** | 目录服务命令行工具 | `dscl . -list /Users`（列出所有用户）<br>`dscl . -read /Users/username`（读取用户信息） | **macOS 特有**，操作 Open Directory |
| **`passwd`** | 修改密码 | `passwd`（修改自己的密码） | macOS 建议通过"系统设置"修改 |
| **`su`** | 切换用户 | `su - username` | macOS 上 root 用户默认禁用 |

---

## 📦 六、软件包管理（Homebrew）

[Homebrew](https://brew.sh) 是 macOS 上事实标准的包管理器，几乎必备。

| 命令 | 功能说明 | 使用示例 | 备注 |
| :--- | :--- | :--- | :--- |
| **`brew install`** | 安装软件包 | `brew install git`<br>`brew install --cask google-chrome`（安装 GUI 应用） | `--cask` 用于 GUI 应用 |
| **`brew uninstall`** | 卸载软件包 | `brew uninstall git` | `--zap` 同时清除相关文件 |
| **`brew search`** | 搜索软件包 | `brew search python` | 搜索 formulae 和 casks |
| **`brew info`** | 查看软件包信息 | `brew info git` | 版本、依赖、安装选项等 |
| **`brew update`** | 更新 Homebrew 自身 | `brew update` | 建议执行 `upgrade` 前先 update |
| **`brew upgrade`** | 升级已安装的软件包 | `brew upgrade`（升级全部）<br>`brew upgrade git`（升级特定包） | 定期执行以保持软件最新 |
| **`brew list`** | 列出已安装的包 | `brew list`<br>`brew list --cask`（只列 GUI 应用） | 查看安装了哪些软件 |
| **`brew cleanup`** | 清理旧版本和缓存 | `brew cleanup`<br>`brew cleanup -n`（模拟，不实际删除） | 释放磁盘空间 |
| **`brew doctor`** | 诊断 Homebrew 问题 | `brew doctor` | 排查安装/配置问题 |
| **`brew services`** | 管理后台服务 | `brew services list`<br>`brew services start mysql`<br>`brew services stop nginx` | 如 MySQL、Redis 等服务的启动/停止 |

---

## 🔧 七、Shell 与终端操作

zsh 环境操作、历史命令、别名等。

| 命令 | 功能说明 | 使用示例 | 备注 |
| :--- | :--- | :--- | :--- |
| **`history`** | 查看命令历史 | `history`<br>`history \| grep git`（搜索历史中的 git 命令）<br>`!123`（执行历史中第123条） | `!!` 执行上一条，`!$` 上一条的最后参数 |
| **`alias`** | 创建命令别名 | `alias ll='ls -la'`<br>`alias gs='git status'`<br>`alias`（查看所有别名） | 永久生效需写入 `~/.zshrc` |
| **`unalias`** | 删除命令别名 | `unalias ll` | 恢复默认行为 |
| **`echo`** | 输出文本/变量 | `echo "Hello"`<br>`echo $PATH`（查看环境变量）<br>`echo $?`（上一条命令的退出状态码） | `$?` 为 0 表示上一条命令成功 |
| **`export`** | 设置环境变量 | `export PATH="/usr/local/bin:$PATH"`<br>`export JAVA_HOME="/Library/Java/Home"` | 写入 `~/.zshrc` 以永久生效 |
| **`source`** | 在当前 Shell 中执行脚本 | `source ~/.zshrc`<br>`. ~/.zshrc`（`.` 是 `source` 的简写） | 使配置立即生效 |
| **`which`** | 查找命令的完整路径 | `which python`<br>`which -a python`（显示所有匹配） | 查看使用的是哪个版本的命令 |
| **`where`** | 查找命令的所有位置 | `where python` | macOS zsh 内置，比 `which -a` 更详细 |
| **`whatis`** | 显示命令的简要说明 | `whatis ls` | 一行描述 |
| **`man`** | 查看命令手册 | `man ls`<br>`man -k keyword`（按关键词搜索手册） | 按 `q` 退出，`/` 搜索 |
| **`type`** | 显示命令的类型 | `type ls`（是否为别名/内置命令/二进制） | zsh 中比 `which` 更精确 |
| **`clear`** | 清屏 | `clear`<br>`Cmd+K` | `Cmd+K` 是终端快捷键 |
| **`tee`** | 同时输出到屏幕和文件 | `make 2>&1 \| tee build.log` | 想看输出又想保存日志时使用 |
| **`xargs`** | 将标准输入转为命令参数 | `find . -name "*.txt" \| xargs rm`<br>`ls \| xargs -I {} echo "File: {}"` | 适合管道中需要参数的命令 |

---

## 📋 八、文件压缩与归档

macOS 支持多种压缩格式。

| 命令 | 功能说明 | 使用示例 | 备注 |
| :--- | :--- | :--- | :--- |
| **`tar`** | 打包/解包 tar 归档 | `tar -czf archive.tar.gz folder/`（打包并 gzip 压缩）<br>`tar -xzf archive.tar.gz`（解压）<br>`tar -xvf archive.tar`（解压并显示文件列表） | `-c`创建 `-x`解压 `-z`gzip `-v`详细 `-f`文件 |
| **`gzip`** / **`gunzip`** | gzip 压缩/解压 | `gzip file.txt`（生成 file.txt.gz）<br>`gunzip file.txt.gz`（解压）<br>`gzip -d file.txt.gz`（等同于 gunzip） | 只能压缩单个文件，常配合 tar 使用 |
| **`zip`** / **`unzip`** | zip 格式压缩/解压 | `zip -r archive.zip folder/`（递归压缩）<br>`unzip archive.zip`<br>`unzip -l archive.zip`（列出内容不解压） | 跨平台兼容性好 |
| **`ditto`** | 归档/复制（保留 macOS 特性） | `ditto -c -k --keepParent folder/ archive.zip`<br>`ditto -x -k archive.zip target/`（解压） | **macOS 特有**，保留资源分叉和 HFS+ 元数据 |
| **`bzip2`** | bzip2 压缩（比 gzip 更小） | `bzip2 file.txt`<br>`bunzip2 file.txt.bz2`<br>`tar -cjf archive.tar.bz2 folder/` | 压缩率更高但速度较慢 |

---

## 🛠️ 九、开发者常用命令

程序开发中高频使用的命令。

| 命令 | 功能说明 | 使用示例 | 备注 |
| :--- | :--- | :--- | :--- |
| **`xcode-select`** | 管理 Xcode 命令行工具 | `xcode-select --install`（安装命令行工具）<br>`xcode-select -p`（查看路径）<br>`sudo xcode-select --reset`（重置路径） | **macOS 特有**，编译软件前必备 |
| **`make`** | 构建自动化工具 | `make`<br>`make -j8`（8线程并行编译）<br>`make install` | 需先安装 Xcode 命令行工具 |
| **`gcc`** / **`clang`** | C/C++ 编译器 | `clang hello.c -o hello`<br>`clang++ -std=c++17 main.cpp -o main` | macOS 的 `gcc` 实际上是 clang |
| **`python3`** | Python 解释器 | `python3 script.py`<br>`python3 -m http.server 8000`（快速启动 HTTP 服务器）<br>`python3 -m venv venv`（创建虚拟环境） | macOS 自带 python3 |
| **`pip3`** | Python 包管理器 | `pip3 install requests`<br>`pip3 list`（列出已安装包）<br>`pip3 freeze > requirements.txt`（导出依赖） | 建议在虚拟环境中使用 |
| **`git`** | 版本控制 | `git clone https://github.com/...`<br>`git status` / `git add` / `git commit` / `git push` | `brew install git` 获取最新版 |
| **`nvm`** | Node.js 版本管理器 | `nvm install 20`<br>`nvm use 20`<br>`nvm ls`（列出已安装版本） | `brew install nvm`，初次使用需配置 `~/.zshrc` |
| **`npm`** / **`npx`** | Node.js 包管理/运行 | `npm install`<br>`npm run dev`<br>`npx create-react-app my-app` | Node.js 项目必备 |
| **`docker`** | 容器管理 | `docker ps`<br>`docker-compose up`<br>`docker build -t myapp .` | [Docker Desktop](https://www.docker.com/products/docker-desktop/) 或 `brew install docker` |
| **`defaults`** | 读写 macOS 偏好设置 | `defaults read com.apple.finder`（查看 Finder 偏好）<br>`defaults write com.apple.finder AppleShowAllFiles -bool true`（显示隐藏文件）<br>`killall Finder`（偏好改后重启 Finder） | **macOS 特有**，可配置大量隐藏选项 |
| **`plutil`** | 操作 plist 文件 | `plutil -p file.plist`（以可读格式打印）<br>`plutil -convert json file.plist -o file.json`（转 JSON） | **macOS 特有**，plist 是 macOS 的配置格式 |
| **`xcrun`** | 运行 Xcode 工具链命令 | `xcrun simctl list`（列出 iOS 模拟器）<br>`xcrun altool --upload-app ...`（上传应用到 App Store） | **macOS 特有**，iOS/macOS 开发必备 |

---

## 🎯 十、macOS 实用技巧

一些 macOS 特有的高效操作。

| 命令 | 功能说明 | 使用示例 | 备注 |
| :--- | :--- | :--- | :--- |
| **`pbcopy`** / **`pbpaste`** | 与系统剪贴板交互 | `cat file.txt \| pbcopy`（内容复制到剪贴板）<br>`pbpaste > file.txt`（剪贴板内容保存到文件）<br>`pbpaste \| sort \| pbcopy`（剪贴板内容排序后放回） | **macOS 特有**，超实用 |
| **`screencapture`** | 命令行截图 | `screencapture screenshot.png`（全屏截图）<br>`screencapture -i -c`（交互截图并复制到剪贴板）<br>`screencapture -T 5 screen.png`（5秒后截图） | **macOS 特有**，可脚本化 |
| **`say`** | 文字转语音 | `say "Hello World"`<br>`say -v "Tingting" "你好"`（中文语音）<br>`say -o output.aiff "Hello"`（输出音频文件） | **macOS 特有** |
| **`osascript`** | 执行 AppleScript/JavaScript 脚本 | `osascript -e 'display notification "完成" with title "提醒"'`（发送通知）<br>`osascript -e 'tell app "Finder" to display dialog "Hello"'`（弹出对话框） | **macOS 特有**，可自动化 macOS 原生操作 |
| **`mdfind` + `mdls`** | Spotlight 搜索 + 查看元数据 | `mdfind "kMDItemKind == 'PDF'"`<br>`mdls file.pdf`（查看文件所有元数据） | **macOS 特有**，深层搜索 |
| **`softwareupdate`** | 管理 macOS 系统更新 | `softwareupdate -l`（列出可用更新）<br>`sudo softwareupdate -i -a`（安装所有更新）<br>`softwareupdate --fetch-full-installer`（下载完整安装器） | **macOS 特有** |
| **`pkgutil`** | 管理已安装的 .pkg 包 | `pkgutil --pkgs`（列出所有已安装的 .pkg 包）<br>`pkgutil --files com.apple.pkg.Safari`（列出某包的文件） | **macOS 特有** |
| **`launchctl`** | 管理 launchd 服务/守护进程 | `launchctl list`（列出所有服务）<br>`launchctl load ~/Library/LaunchAgents/com.example.plist`（加载服务）<br>`launchctl unload ...`（卸载服务） | **macOS 特有**，类似 Linux 的 systemd |
| **`tmutil`** | Time Machine 备份管理 | `tmutil startbackup`（手动开始备份）<br>`tmutil listbackups`（列出备份）<br>`tmutil compare`（比较当前与备份差异） | **macOS 特有** |

---

## 📝 附录：常用快捷键（终端内）

| 快捷键 | 功能 |
| :--- | :--- |
| `Ctrl + A` | 光标移到行首 |
| `Ctrl + E` | 光标移到行尾 |
| `Ctrl + U` | 清除光标前的内容 |
| `Ctrl + K` | 清除光标后的内容 |
| `Ctrl + W` | 删除前一个单词 |
| `Ctrl + L` | 清屏（同 `clear`） |
| `Ctrl + C` | 终止当前运行的程序 |
| `Ctrl + D` | 退出当前 Shell 会话（EOF） |
| `Ctrl + R` | 搜索历史命令 |
| `Tab` | 自动补全路径或命令 |
| `Cmd + K` | 在终端中清屏 |
| `Cmd + T` | 新建标签页 |
| `Cmd + +/-` | 放大/缩小字体 |

---

> **提示**：
> - macOS 终端默认使用 **zsh**，配置文件为 `~/.zshrc`。
> - 安装 [Homebrew](https://brew.sh) 可以极大扩展命令生态。
> - 推荐配合 [iTerm2](https://iterm2.com) + [Oh My Zsh](https://ohmyz.sh) 使用，体验更佳。
> - 安装 Xcode 命令行工具：`xcode-select --install`
