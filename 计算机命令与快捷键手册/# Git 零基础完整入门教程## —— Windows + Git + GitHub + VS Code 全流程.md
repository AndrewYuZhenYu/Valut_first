
# 一、先知道我们最终要做什么

假设你电脑上有一个项目：

```text
我的项目
├── main.cpp
├── test.cpp
└── README.md
```

我们希望最后变成：

```text
电脑
│
│  VS Code 编辑
│
▼
本地项目文件夹
│
│  Git 管理
│
▼
GitHub
│
└── 我的项目
```

以后你修改了电脑上的文件，只需要：

```text
修改文件
   ↓
保存
   ↓
Git 提交
   ↓
上传到 GitHub
```

GitHub 上就会出现最新版本。

反过来，如果 GitHub 上已经有别人修改过的内容：

```text
GitHub
   ↓
拉取
   ↓
电脑
```

你的电脑也可以获得最新内容。

---

# 二、你需要准备什么

整个教程需要：

1. 一台 Windows 电脑
    
2. 一个 GitHub 账号
    
3. Git
    
4. VS Code
    

其中：

- **Git**：负责管理文件版本
    
- **GitHub**：负责把 Git 仓库放到网上
    
- **VS Code**：负责编辑代码和操作 Git
    

VS Code 本身已经内置 Git 图形界面，可以直接进行查看修改、提交、推送等操作。([Visual Studio Code](https://code.visualstudio.com/docs/sourcecontrol/quickstart?utm_source=chatgpt.com "Quickstart: use source control in VS Code"))

---

# 三、第一步：安装 Git

## 1. 打开 Git 官网

进入：

[Git for Windows 官方下载页面](https://git-scm.com/install/windows?utm_source=chatgpt.com)

目前 Git for Windows 的最新稳定版本是 **2.56.0**。([Git](https://git-scm.com/install/windows?utm_source=chatgpt.com "Git - Install for Windows"))

进入页面以后，找到：

```text
Click here to download the latest x64 version of Git for Windows
```

点击下载。

---

# 四、安装 Git

下载完成后，找到安装程序。

一般类似：

```text
Git-2.xx.x-64-bit.exe
```

双击运行。

---

## 1. 出现安装欢迎界面

直接：

```text
Next
```

---

## 2. Select Destination Location

这是选择 Git 安装在哪里。

**直接保持默认。**

例如：

```text
C:\Program Files\Git
```

点击：

```text
Next
```

---

## 3. Select Components

这里会出现很多复选框。

对于第一次安装：

**保持默认即可。**

点击：

```text
Next
```

---

## 4. Start Menu Folder

继续：

```text
Next
```

---

## 5. Choosing the default editor

这里可能会问：

```text
Which editor would you like Git to use?
```

如果你已经安装了 VS Code，可以选择：

```text
Visual Studio Code
```

如果没有，也可以直接保持默认。

**这里不是决定以后用什么软件写代码。**

点击：

```text
Next
```

---

## 6. Adjusting the name of the initial branch

如果看到：

```text
Let Git decide
```

或者：

```text
Override the default branch name for new repositories
```

对于现在的 Git，新手建议选择：

```text
main
```

如果界面没有这个选项，直接保持默认也可以。

---

## 7. PATH 设置

你可能会看到：

```text
Adjusting your PATH environment
```

这里通常有三个选项。

选择：

```text
Git from the command line and also from 3rd-party software
```

**这一项非常重要。**

然后：

```text
Next
```

---

## 8. HTTPS 设置

看到：

```text
Choosing HTTPS transport backend
```

保持默认：

```text
Use the OpenSSL library
```

点击：

```text
Next
```

---

## 9. 换行符设置

看到：

```text
Configuring the line ending conversions
```

一般保持默认：

```text
Checkout Windows-style, commit Unix-style line endings
```

点击：

```text
Next
```

---

## 10. Git Bash 设置

后面的选项基本都：

**保持默认 → Next**

最后看到：

```text
Install
```

点击：

```text
Install
```

等待安装。

---

# 五、检查 Git 有没有安装成功

安装完成以后，点击：

```text
Finish
```

然后按：

```text
Win + R
```

输入：

```text
cmd
```

按 Enter。

打开 Windows 命令提示符。

输入：

```bash
git --version
```

按 Enter。

如果看到类似：

```text
git version 2.56.0.windows.1
```

说明：

# Git 安装成功。

版本号不同没有关系。

---

# 六、顺便配置 Git 的用户名和邮箱

这是第一次使用 Git 时建议做的事情。

打开：

```text
cmd
```

输入：

```bash
git config --global user.name "你的名字"
```

例如：

```bash
git config --global user.name "Andrew"
```

然后输入：

```bash
git config --global user.email "你的邮箱"
```

例如：

```bash
git config --global user.email "123456789@qq.com"
```

注意：

这里的邮箱**建议使用你 GitHub 账号绑定的邮箱**。

例如你的 GitHub 邮箱是：

```text
123456789@qq.com
```

那么就写：

```bash
git config --global user.email "123456789@qq.com"
```

---

# 七、检查刚才的设置

输入：

```bash
git config --global user.name
```

应该显示：

```text
Andrew
```

再输入：

```bash
git config --global user.email
```

应该显示：

```text
123456789@qq.com
```

如果正确，就可以继续。

---

# 八、第二步：准备 GitHub

打开：

[GitHub 官方网站](https://github.com/?utm_source=chatgpt.com)

如果已经有账号：

```text
Sign in
```

登录即可。

如果没有账号：

```text
Sign up
```

注册一个。

---

# 九、第三步：在 GitHub 创建一个仓库

登录 GitHub。

进入 GitHub 首页以后，在右上角找到：

```text
+
```

点击。

然后选择：

```text
New repository
```

GitHub 当前创建仓库的入口就是右上角菜单中的 **New repository**。([GitHub Docs](https://docs.github.com/en/repositories/creating-and-managing-repositories/creating-a-new-repository?apiVersion=2022-11-28&utm_source=chatgpt.com "Creating a new repository - GitHub Docs"))

---

# 十、填写仓库信息

你会看到创建仓库页面。

假设我们准备创建一个：

```text
GitTest
```

的仓库。

---

## 1. Repository name

填写：

```text
GitTest
```

也就是说：

```text
Repository name:
GitTest
```

---

## 2. Description

可以填写：

```text
My first Git repository
```

也可以不填。

---

## 3. Public / Private

这里非常重要。

你会看到：

```text
Public
Private
```

### Public

任何人都可以看到你的仓库。

### Private

只有你以及你授权的人可以看到。

如果你只是自己练习：

**建议选择 Private。**

---

# 十一、Add README

你会看到：

```text
Add a README file
```

第一次按照本教程操作时：

**建议勾选。**

这样 GitHub 会直接帮你创建：

```text
README.md
```

文件。

---

# 十二、其他选项

你可能还会看到：

```text
.gitignore
Choose a license
```

第一次练习可以：

```text
.gitignore：先不选
License：先不选
```

以后真正创建项目的时候再配置。

---

# 十三、创建仓库

最后点击：

```text
Create repository
```

等待页面加载。

现在你的 GitHub 上已经有：

```text
GitTest
```

这个仓库了。

GitHub 官方目前的创建流程也是填写仓库名称、描述、可见性，然后点击 **Create repository**。([GitHub Docs](https://docs.github.com/en/repositories/creating-and-managing-repositories/creating-a-new-repository?apiVersion=2022-11-28&utm_source=chatgpt.com "Creating a new repository - GitHub Docs"))

---

# 十四、现在你的电脑里还没有这个项目

这一点非常重要。

此时：

```text
GitHub：

GitTest
└── README.md
```

但是：

```text
你的电脑：

还没有 GitTest
```

所以我们下一步要做：

# 把 GitHub 上的仓库下载到电脑。

这个动作叫：

# Clone（克隆）

---

# 十五、第四步：复制 GitHub 仓库地址

打开刚才创建的：

```text
GitTest
```

在文件列表上方找到：

```text
Code
```

点击。

会出现一个菜单。

找到：

```text
HTTPS
```

下面类似：

```text
https://github.com/你的用户名/GitTest.git
```

点击右边的复制按钮。

GitHub 官方目前也是通过 **Code → HTTPS → Copy URL** 获取克隆地址。([GitHub Docs](https://docs.github.com/en/repositories/creating-and-managing-repositories/cloning-a-repository?tool=desktop&utm_source=chatgpt.com "Cloning a repository - GitHub Docs"))

---

# 十六、第五步：在电脑上选择项目存放位置

例如你想把所有 Git 项目放在：

```text
D:\Projects
```

那么先在电脑上创建：

```text
D:\Projects
```

这个文件夹。

以后你的项目就可以统一放在这里。

例如：

```text
D:\Projects
├── GitTest
├── CppProject
├── PDFProject
└── ...
```

---

# 十七、打开命令提示符

按：

```text
Win + R
```

输入：

```text
cmd
```

按 Enter。

---

# 十八、进入 Projects 文件夹

如果你的目录是：

```text
D:\Projects
```

输入：

```bash
D:
```

回车。

然后：

```bash
cd Projects
```

回车。

现在命令行应该位于：

```text
D:\Projects
```

---

# 十九、开始 Clone

输入：

```bash
git clone https://github.com/你的用户名/GitTest.git
```

例如：

```bash
git clone https://github.com/Andrew/GitTest.git
```

然后按 Enter。

Git 会开始下载。

最后通常会看到类似：

```text
Cloning into 'GitTest'...
Receiving objects: 100%
Resolving deltas: 100%
```

没有报错就说明成功。

---

# 二十、现在电脑发生了什么

打开：

```text
D:\Projects
```

你会发现多了：

```text
GitTest
```

打开它：

```text
D:\Projects\GitTest
```

里面有：

```text
README.md
```

这就是刚才 GitHub 上面的仓库。

也就是说：

```text
GitHub
   │
   │ clone
   ↓
电脑
D:\Projects\GitTest
```

以后这个文件夹就是你的：

# 本地 Git 仓库。

GitHub 官方对 clone 的定义也正是：把 GitHub 上的仓库复制到本地电脑，使本地仓库可以与远程仓库同步。([GitHub Docs](https://docs.github.com/en/repositories/creating-and-managing-repositories/cloning-a-repository?tool=desktop&utm_source=chatgpt.com "Cloning a repository - GitHub Docs"))

---

# 二十一、非常重要：以后不要随便重新 Clone

例如你已经有：

```text
D:\Projects\GitTest
```

以后就不要每次都：

```bash
git clone ...
```

否则你可能创建出：

```text
GitTest
GitTest-1
GitTest-2
GitTest-3
```

甚至把自己搞混。

**一个仓库正常情况下只需要 Clone 一次。**

以后直接进入这个文件夹工作即可。

---

# 二十二、第六步：用 VS Code 打开仓库

现在打开 VS Code。

选择：

```text
File
↓
Open Folder
```

找到：

```text
D:\Projects\GitTest
```

选择：

```text
Select Folder
```

---

# 二十三、确认 VS Code 已经识别 Git

打开项目以后，看 VS Code 左侧。

找到：

```text
Source Control
```

通常是一个类似分支的图标。

点击。

如果能够看到：

```text
SOURCE CONTROL
```

说明 VS Code 已经发现这个文件夹是 Git 仓库。

---

# 二十四、为什么 VS Code 能自动发现 Git？

因为你刚才：

```text
git clone
```

以后，Git 会在：

```text
GitTest
```

里面建立 Git 仓库信息。

所以 VS Code 打开这个文件夹后，会自动识别。

VS Code 官方文档也明确说明，VS Code 使用的 Git 仓库与命令行 Git 是同一个仓库；你可以在 VS Code 图形界面操作，也可以在终端操作。([Visual Studio Code](https://code.visualstudio.com/docs/sourcecontrol/overview?utm_source=chatgpt.com "Source control in VS Code"))

---

# 二十五、第七步：在项目里面创建一个文件

现在我们真正开始操作。

在 VS Code 左侧：

```text
GitTest
```

上点击右键。

选择：

```text
New File
```

输入：

```text
hello.txt
```

然后按 Enter。

---

# 二十六、写一点内容

打开：

```text
hello.txt
```

输入：

```text
Hello GitHub!
```

然后：

```text
Ctrl + S
```

保存。

现在：

```text
电脑上的 GitTest
```

已经发生了变化。

但是：

# GitHub 还没有变化。

这点非常重要。

你只是：

```text
修改了本地文件
```

并没有上传。

---

# 二十七、第八步：查看发生了什么变化

点击 VS Code 左侧：

```text
Source Control
```

你应该会看到：

```text
CHANGES

hello.txt
```

这意味着：

> Git 发现 hello.txt 是一个新文件。

---

# 二十八、第九步：把修改加入提交

在：

```text
CHANGES
```

下面找到：

```text
hello.txt
```

旁边通常会有：

```text
+
```

点击它。

现在文件会从：

```text
CHANGES
```

移动到：

```text
STAGED CHANGES
```

这一步叫：

# Stage

对于新手，你暂时只需要记住：

> **想把这次修改正式保存进 Git，就先把它加入 Staged Changes。**

---

# 二十九、第十步：写提交说明

在 Source Control 面板上方，你会看到一个输入框。

输入：

```text
添加 hello.txt
```

或者：

```text
Add hello.txt
```

这个文字就是这一次修改的说明。

---

# 三十、第十一步：Commit

点击：

```text
Commit
```

或者上方的：

如果 VS Code 提示：

```text
Please tell me who you are
```

说明之前没有配置用户名和邮箱。

回到前面的：

```bash
git config --global user.name "你的名字"
git config --global user.email "你的邮箱"
```

重新配置即可。

---

# 三十一、现在发生了什么？

你刚刚做的是：

```text
修改 hello.txt
      ↓
Stage
      ↓
Commit
```

此时：

```text
电脑
  ↓
Git 已经记录了这次修改
```

但是注意：

# 仍然没有上传到 GitHub。

---

# 三十二、第十二步：Push 上传到 GitHub

现在需要点击：

```text
Sync Changes
```

或者：

```text
Push
```

不同版本的 VS Code 界面可能略有区别。

如果看到：

```text
Publish Branch
```

也可以点击。

第一次连接的时候，VS Code 可能要求你登录 GitHub。

---

# 三十三、GitHub 登录

如果弹出浏览器：

```text
Sign in to GitHub
```

按照提示登录。

如果出现：

```text
Authorize Visual Studio Code
```

按照提示允许。

完成之后返回 VS Code。

---

# 三十四、再次 Push

如果刚才没有自动完成：

点击：

```text
Source Control
```

然后：

```text
Sync Changes
```

或者：

```text
Push
```

等待完成。

---

# 三十五、回到 GitHub 查看

重新打开你的 GitHub 仓库：

```text
GitTest
```

刷新页面。

现在应该能看到：

```text
README.md
hello.txt
```

打开：

```text
hello.txt
```

里面就是：

```text
Hello GitHub!
```

恭喜。

你已经完成了整个 Git 最核心的流程：

# Windows → Git → GitHub → Clone → VS Code → 修改 → Commit → Push → GitHub

---

# 三十六、以后最常用的工作流程

以后你做项目，最常见的情况就是下面这样。

假设你有：

```text
D:\Projects\GitTest
```

---

## 第 1 步：打开项目

打开：

```text
VS Code
```

然后：

```text
File
→ Open Folder
→ D:\Projects\GitTest
```

---

## 第 2 步：修改文件

例如修改：

```text
hello.txt
```

变成：

```text
Hello GitHub!

This is my second change.
```

保存：

```text
Ctrl + S
```

---

## 第 3 步：打开 Source Control

点击左侧：

```text
Source Control
```

查看修改。

---

## 第 4 步：Stage

点击文件旁边的：

```text
+
```

---

## 第 5 步：Commit

输入：

```text
更新 hello.txt
```

点击：

```text
Commit
```

---

## 第 6 步：Push

点击：

```text
Sync Changes
```

或者：

```text
Push
```

---

## 第 7 步：GitHub 查看

刷新 GitHub。

完成。

---

# 三十七、以后你只需要记住这四个动作

如果你完全不想记 Git 的大量命令：

# 修改 → Stage → Commit → Push

也就是：

```text
修改文件
   ↓
保存
   ↓
Stage
   ↓
Commit
   ↓
Push
   ↓
GitHub
```

这是你作为普通个人开发者最常用的流程。

---

# 三十八、如果不用 VS Code，也可以用命令

虽然本教程主要使用 VS Code，但你最好还是认识下面几个命令。

进入项目：

```bash
cd D:\Projects\GitTest
```

查看状态：

```bash
git status
```

加入所有修改：

```bash
git add .
```

提交：

```bash
git commit -m "更新项目"
```

上传：

```bash
git push
```

所以完整命令就是：

```bash
git add .
git commit -m "更新项目"
git push
```

这三个命令非常重要。

---

# 三十九、如何从 GitHub 获取别人刚刚上传的修改

假设：

```text
GitHub
```

上有新的修改。

你电脑上的项目还是旧版本。

打开 VS Code。

点击：

```text
Source Control
```

找到：

```text
Pull
```

或者：

```text
Sync Changes
```

点击。

也可以在终端输入：

```bash
git pull
```

完成之后，本地文件就会更新。

GitHub 官方把 `pull` 用于获取远程仓库的新变化；它会获取远程变化并合并到当前本地分支。([GitHub Docs](https://docs.github.com/en/get-started/using-git/getting-changes-from-a-remote-repository?utm_source=chatgpt.com "Getting changes from a remote repository - GitHub Docs"))

---

# 四十、所以以后有两个方向

你可以把它直接记成：

```text
电脑 → GitHub

Push
```

以及：

```text
GitHub → 电脑

Pull
```

也就是：

|你想做什么|操作|
|---|---|
|上传电脑上的修改|Push|
|获取 GitHub 上的新修改|Pull|
|第一次把仓库下载到电脑|Clone|
|把修改正式记录下来|Commit|
|准备某些修改进行 Commit|Stage|

---

# 四十一、Clone 和 Pull 不要搞混

这是新手特别容易搞混的地方。

### 第一次

GitHub 有仓库：

```text
GitHub
  ↓
Clone
  ↓
电脑
```

使用：

```bash
git clone
```

---

### 已经 Clone 过

电脑已经有这个项目：

```text
电脑
  ↕
GitHub
```

以后同步：

```text
git pull
```

或者：

```text
git push
```

所以：

> **第一次下载 → Clone**

> **以后更新 → Pull**

> **自己上传 → Push**

---

# 四十二、如果你修改了文件，然后后悔了

比如：

```text
hello.txt
```

你修改成：

```text
非常重要的新内容
```

结果发现改错了。

如果这个修改还没有 Commit，可以在 VS Code 的 Source Control 中找到这个文件。

可以选择：

```text
Discard Changes
```

这会把没有提交的修改丢掉。

**注意：**

这个操作可能导致你的修改直接消失。

所以不确定的时候不要乱点。

---

# 四十三、如果已经 Commit 了怎么办？

如果你已经：

```text
Commit
```

不要马上慌。

Git 的特点就是：

> 已经提交的历史通常还可以恢复。

但是对于刚开始学 Git 的人，暂时不要急着学各种复杂的：

```text
reset
revert
rebase
cherry-pick
```

这些以后再学。

目前先把：

```text
Clone
Pull
Stage
Commit
Push
```

用熟。

---

# 四十四、如何查看一个文件有没有被修改

打开：

```text
Source Control
```

例如看到：

```text
M hello.txt
```

其中：

```text
M
```

表示这个文件被修改了。

如果看到：

```text
U
```

通常表示这是一个尚未被 Git 跟踪的新文件。

你现在不需要深入理解这些字母。

只需要知道：

> Source Control 里面出现文件，说明 Git 发现项目有变化。

---

# 四十五、如何创建新的 GitHub 仓库并开始一个新项目

以后你想做：

```text
C++Project
```

可以重复：

```text
GitHub
↓
New repository
↓
C++Project
↓
Create repository
↓
Code
↓
HTTPS
↓
复制地址
↓
电脑
↓
git clone
↓
VS Code
```

然后开始写代码。

---

# 四十六、一个非常重要的原则

如果你已经在 GitHub 创建了：

```text
C++Project
```

那么：

# 不要在电脑上另外创建一个同名普通文件夹，然后再把它硬塞进去。

最简单的方法就是：

```text
GitHub 创建仓库
        ↓
git clone
        ↓
得到 C++Project 文件夹
        ↓
VS Code 打开 C++Project
        ↓
开始写代码
```

这样最不容易出问题。

---

# 四十七、如果你已经有一个电脑上的项目怎么办？

这是另一种很常见的情况。

例如你已经有：

```text
D:\Projects\MyCppProject
```

里面已经有：

```text
main.cpp
Student.cpp
Student.h
README.md
```

现在你想：

> 把这个**已经存在的电脑文件夹**上传到 GitHub。

这种情况**不要先 Clone 一个空文件夹再套进去**。

可以直接把这个已有项目初始化为 Git 仓库，然后连接 GitHub。

---

# 四十八、已有本地项目上传 GitHub

进入你的项目：

```text
D:\Projects\MyCppProject
```

在这个文件夹里打开终端。

最简单的方法：

在文件夹地址栏输入：

```text
cmd
```

然后按 Enter。

---

## 第一步：初始化 Git

输入：

```bash
git init
```

---

## 第二步：添加所有文件

输入：

```bash
git add .
```

---

## 第三步：第一次提交

输入：

```bash
git commit -m "首次提交"
```

---

## 第四步：在 GitHub 创建一个仓库

GitHub：

```text
New repository
```

例如：

```text
MyCppProject
```

---

## 非常重要

如果你准备把：

```text
本地已有项目
```

上传到：

```text
GitHub 新仓库
```

那么创建 GitHub 仓库时，**不要勾选 Add README**。

也不要先添加：

```text
.gitignore
License
```

对于第一次操作，最好让 GitHub 仓库保持空白。

这样最简单。

---

# 四十九、连接本地项目和 GitHub

复制 GitHub 仓库 HTTPS 地址。

例如：

```text
https://github.com/你的用户名/MyCppProject.git
```

然后在本地项目终端输入：

```bash
git remote add origin https://github.com/你的用户名/MyCppProject.git
```

然后：

```bash
git branch -M main
```

最后：

```bash
git push -u origin main
```

完成以后刷新 GitHub。

你的：

```text
main.cpp
Student.cpp
Student.h
README.md
```

就会出现在 GitHub 上。

---

# 五十、以后这个项目怎么上传？

第一次：

```bash
git init
git add .
git commit -m "首次提交"
git remote add origin https://github.com/你的用户名/MyCppProject.git
git branch -M main
git push -u origin main
```

以后再修改代码：

```bash
git add .
git commit -m "更新代码"
git push
```

就可以了。

---

# 五十一、推荐你以后主要使用 VS Code

对于你这种日常写 C/C++ 项目的情况，实际上不需要每次都手动输入：

```bash
git add .
git commit -m "xxx"
git push
```

可以直接使用 VS Code 左侧：

```text
Source Control
```

完成：

```text
查看修改
↓
Stage
↓
Commit
↓
Push
```

VS Code 官方本身就支持这一整套 Git 工作流。([Visual Studio Code](https://code.visualstudio.com/docs/sourcecontrol/overview?utm_source=chatgpt.com "Source control in VS Code"))

---

# 五十二、VS Code 里的几个按钮到底是什么

你以后经常会看到这些东西。

## `+`

```text
Stage
```

把修改加入下一次 Commit。

---

## `✓`

```text
Commit
```

把已经 Stage 的修改记录下来。

---

## `↑`

通常表示：

```text
Push
```

把本地 Commit 上传到 GitHub。

---

## `↓`

通常表示：

```text
Pull
```

从 GitHub 获取最新内容。

---

## `↻`

通常：

```text
Sync
```

同步本地和远程仓库。

---

# 五十三、最推荐你的日常操作方法

以后打开一个已经连接 GitHub 的项目。

第一件事：

```text
Pull
```

确保电脑是最新版本。

然后：

```text
开始写代码
```

写完：

```text
Ctrl + S
```

然后：

```text
Source Control
↓
查看修改
↓
Stage
↓
Commit
↓
Push
```

完成。

所以你以后实际上就是：

```text
打开项目
   ↓
Pull
   ↓
写代码
   ↓
保存
   ↓
Stage
   ↓
Commit
   ↓
Push
   ↓
结束
```

---

# 五十四、Commit 信息怎么写？

新手不用搞复杂。

直接写清楚：

```text
添加学生类
```

```text
修复计算错误
```

```text
增加链表功能
```

```text
修改 README
```

```text
完成第一次作业
```

就可以。

不要写：

```text
aaa
```

```text
test
```

```text
111
```

因为过几个月以后你自己都不知道这个 Commit 干了什么。

---

# 五十五、一个完整的实际例子

假设你现在做一个 C++ 项目：

```text
StudentSystem
```

---

## 第一次

GitHub：

```text
New repository
```

创建：

```text
StudentSystem
```

然后：

```text
Code
→ HTTPS
→ Copy
```

---

电脑：

```bash
cd D:\Projects
```

然后：

```bash
git clone https://github.com/你的用户名/StudentSystem.git
```

---

VS Code：

```text
Open Folder
→ StudentSystem
```

---

创建：

```text
main.cpp
```

写：

```cpp
#include <iostream>

int main()
{
    std::cout << "Student System";
    return 0;
}
```

保存。

---

VS Code：

```text
Source Control
```

看到：

```text
main.cpp
```

点击：

```text
+
```

然后输入：

```text
添加 main.cpp
```

点击：

```text
Commit
```

然后：

```text
Sync Changes
```

---

GitHub：

刷新：

```text
StudentSystem
```

看到：

```text
README.md
main.cpp
```

完成。

---

# 五十六、第二次修改

第二天打开：

```text
StudentSystem
```

先：

```text
Pull
```

然后修改：

```text
main.cpp
```

保存。

Source Control：

```text
main.cpp
```

点击：

```text
+
```

Commit：

```text
完善主程序
```

然后：

```text
Push
```

完成。

---

# 五十七、第三次修改

再加入：

```text
Student.h
Student.cpp
```

然后：

```text
Stage
↓
Commit
↓
Push
```

Commit 可以写：

```text
添加 Student 类
```

于是 GitHub 上的项目逐渐变成：

```text
StudentSystem
│
├── README.md
├── main.cpp
├── Student.h
└── Student.cpp
```

而 Git 还会保存：

```text
第一次提交
第二次提交
第三次提交
……
```

以后你可以查看过去的版本。

---

# 五十八、如果 VS Code 说 Git 找不到

如果 VS Code 里面出现类似：

```text
Git not found
```

先关闭 VS Code。

重新打开。

然后：

```text
Terminal
→ New Terminal
```

输入：

```bash
git --version
```

如果能看到：

```text
git version 2.xx.x
```

说明 Git 正常。

VS Code 官方也建议安装 Git 后在 VS Code 终端执行 `git --version` 检查 Git 是否可用；如果安装后 VS Code 没有识别，重启 VS Code 是常见的处理方式。([Visual Studio Code](https://code.visualstudio.com/docs/sourcecontrol/quickstart?utm_source=chatgpt.com "Quickstart: use source control in VS Code"))

---

# 五十九、如果 Push 时让你登录 GitHub

这是正常的。

GitHub 现在不会让你简单地把 GitHub 登录密码直接当作 Git 密码使用。

通常 VS Code 会弹出浏览器，让你：

```text
登录 GitHub
↓
授权 VS Code
↓
返回 VS Code
```

按照提示操作即可。

---

# 六十、如果出现 Authentication Failed

如果看到：

```text
Authentication failed
```

不要反复输入 GitHub 密码。

优先：

1. 确认浏览器已经登录 GitHub
    
2. 确认 VS Code 已经登录 GitHub
    
3. 重启 VS Code
    
4. 再次 Push
    

如果仍然失败，再单独处理 GitHub 身份验证问题。

---

# 六十一、如果出现 `nothing to commit`

例如：

```text
nothing to commit, working tree clean
```

这通常不是错误。

意思就是：

> 现在没有新的修改需要提交。

如果你刚刚已经：

```text
Commit
```

然后又点了一次 Commit，就很可能看到这个。

不用处理。

---

# 六十二、如果出现 `Everything up-to-date`

例如：

```text
Everything up-to-date
```

也不是错误。

意思：

> GitHub 已经是最新的，没有东西需要上传。

不用处理。

---

# 六十三、如果出现 `git is not recognized`

例如：

```text
'git' is not recognized as an internal or external command
```

说明 Windows 找不到 Git。

先检查：

```bash
git --version
```

如果 Windows CMD 和 VS Code 都找不到：

1. 确认 Git 是否安装成功
    
2. 关闭 CMD
    
3. 重新打开 CMD
    
4. 再执行：
    

```bash
git --version
```

如果仍然不行，重新安装 Git，并确认安装过程中 PATH 选择的是：

```text
Git from the command line and also from 3rd-party software
```

---

# 六十四、如果 GitHub 上看不到自己的修改

按照下面顺序检查：

```text
① 文件有没有保存
        ↓
② Source Control 有没有显示修改
        ↓
③ 有没有 Stage
        ↓
④ 有没有 Commit
        ↓
⑤ 有没有 Push
        ↓
⑥ 刷新 GitHub
```

最常见的问题就是：

> **只修改了文件，却没有 Push。**

---

# 六十五、一个非常重要的概念：本地和 GitHub 是两个地方

以后千万不要把：

```text
电脑上的项目
```

和：

```text
GitHub 上的项目
```

理解成“同一个文件夹”。

它们实际上是：

```text
电脑
└── 本地仓库
       ↕
      Git
       ↕
GitHub
└── 远程仓库
```

所以：

```text
修改电脑文件
```

不会自动修改 GitHub。

必须：

```text
Commit
+
Push
```

---

# 六十六、反过来也一样

别人修改 GitHub：

```text
GitHub
```

你的电脑也不会自动变化。

需要：

```text
Pull
```

所以：

```text
电脑 → GitHub
```

主要用：

```text
Commit
Push
```

而：

```text
GitHub → 电脑
```

主要用：

```text
Pull
```

---

# 六十七、你现在真正需要记住的 Git 命令

不要一下子背几十个。

第一阶段只记：

```bash
git clone
```

第一次下载仓库。

---

```bash
git status
```

查看现在有没有修改。

---

```bash
git add .
```

把所有修改加入 Stage。

---

```bash
git commit -m "说明"
```

提交修改。

---

```bash
git push
```

上传 GitHub。

---

```bash
git pull
```

从 GitHub 获取最新内容。

---

# 六十八、最终形成一张脑图

```text
                    GitHub
                      │
                      │
                 远程仓库
                      │
             ┌────────┴────────┐
             │                 │
           Pull              Push
             │                 │
             ↓                 ↑
        ┌─────────────────────────┐
        │       本地仓库           │
        │                         │
        │       VS Code           │
        │          │              │
        │        修改文件          │
        │          ↓              │
        │        Stage            │
        │          ↓              │
        │        Commit           │
        │          │              │
        └─────────────────────────┘
```

第一次：

```text
GitHub
   ↓
Clone
   ↓
本地
```

以后：

```text
GitHub
   ↓
Pull
   ↓
本地
```

以及：

```text
本地
   ↓
修改
   ↓
Stage
   ↓
Commit
   ↓
Push
   ↓
GitHub
```

---

# 六十九、你以后新建项目最推荐的两种方式

## 情况 A：项目还没开始写

最推荐：

```text
GitHub 创建仓库
        ↓
Clone
        ↓
VS Code 打开
        ↓
开始写代码
```

---

## 情况 B：项目已经在电脑上写好了

使用：

```text
本地项目
   ↓
git init
   ↓
git add .
   ↓
git commit
   ↓
GitHub 创建空仓库
   ↓
git remote add origin
   ↓
git push
```

---

# 七十、最后给你一份“真正日常使用”的速查表

|我要做什么|操作|
|---|---|
|第一次下载 GitHub 项目|`git clone`|
|查看有没有修改|`git status`|
|把修改加入提交|`git add .`|
|创建一次提交|`git commit -m "说明"`|
|上传 GitHub|`git push`|
|获取 GitHub 最新内容|`git pull`|
|第一次让已有项目进入 Git|`git init`|
|查看远程 GitHub 地址|`git remote -v`|

---

# 七十一、你真正需要记住的完整流程

如果你只看最后这一部分，那么记住：

## 第一次建立项目

```text
GitHub
 ↓
New repository
 ↓
复制 HTTPS 地址
 ↓
电脑
 ↓
git clone
 ↓
VS Code Open Folder
```

---

## 每天开始工作

```text
打开项目
 ↓
Pull
 ↓
开始写代码
```

---

## 写完代码

```text
保存
 ↓
Source Control
 ↓
Stage
 ↓
Commit
 ↓
Push
```

---

## 最终

```text
                 GitHub
                    ↑
                  Push
                    ↑
                 Commit
                    ↑
                  Stage
                    ↑
                修改文件
                    ↑
                 VS Code
                    ↑
                  Clone
                    ↑
                 GitHub
```

**整个 Git 入门阶段，先把这一套流程做熟，比背大量 Git 命令重要得多。**

GitHub 官方的仓库、克隆以及 VS Code 的 Git 文档也都是围绕这套基本工作流展开的。([GitHub Docs](https://docs.github.com/en/get-started/start-your-journey/creating-a-repository-for-your-project-on-github?utm_source=chatgpt.com "Creating a repository for your project on GitHub - GitHub Docs"))

### 官方入口

- [Git 官方网站 / Windows 安装](https://git-scm.com/install/windows?utm_source=chatgpt.com)
    
- [GitHub](https://github.com/?utm_source=chatgpt.com)
    
- [GitHub：创建仓库](https://docs.github.com/en/repositories/creating-and-managing-repositories/creating-a-new-repository?utm_source=chatgpt.com)
    
- [GitHub：克隆仓库](https://docs.github.com/en/repositories/creating-and-managing-repositories/cloning-a-repository?utm_source=chatgpt.com)
    
- [VS Code：Git / Source Control](https://code.visualstudio.com/docs/sourcecontrol/overview?utm_source=chatgpt.com)
    

如果把这份教程作为**真正长期使用的 Git 小白手册**，下一步最值得补充的是「**GitHub + VS Code 实战第二篇：`.gitignore`、删除/恢复文件、查看历史版本、回退、分支、Merge、解决冲突、Fork 和 Pull Request**」。这些内容等你把上面的基础流程跑通后再学，会顺很多。