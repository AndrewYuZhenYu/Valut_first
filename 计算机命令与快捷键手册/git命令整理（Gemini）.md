# Git 核心命令系统化完全指南

## 1. 基础配置与初始化

### 初始化仓库

- `git init`：在当前目录初始化一个新的 Git 本地仓库。
    
- `git init <project-name>`：新建一个目录并将其初始化为 Git 本地仓库。
    

### 全局与局部配置

> 📌 **注意**：`--global` 作用于当前系统用户，若不加则仅作用于当前仓库。

- `git config --global user.name "Your Name"`：配置全局提交者姓名。
    
- `git config --global user.email "your_email@example.com"`：配置全局提交者邮箱。
    
- `git config --list`：列出当前所有的 Git 配置项。
    
- `git config <key>`：查看特定配置项的值（例如 `git config user.name`）。
    

## 2. 工作流核心操作（暂存与提交）

### 状态查看

- `git status`：查看工作区与暂存区的实时状态。
    
- `git status -s`：以简短的格式输出状态（`M` 修改，`A` 新增，`D` 删除，`??` 未追踪）。
    

### 暂存文件 (Stage)

- `git add <file>`：将指定文件的修改添加到暂存区。
    
- `git add <dir>`：将指定目录下的所有修改添加到暂存区。
    
- `git add .` 或 `git add -A`：将当前项目下所有工作区的修改、新增和删除同步到暂存区。
    

### 提交更新 (Commit)

- `git commit -m "commit message"`：将暂存区的内容提交到本地仓库，并添加提交说明。
    
- `git commit -a -m "commit message"`：跳过 `git add`，直接将所有**已追踪**文件的修改提交到本地仓库。
    
- `git commit --amend`：修改上一次的提交信息，或者将当前暂存区的新改动合并到上一次提交中。
    

## 3. 差异对比与历史追踪

### 差异比对 (Diff)

- `git diff`：查看**工作区**与**暂存区**之间的差异。
    
- `git diff --cached` 或 `git diff --staged`：查看**暂存区**与**最新本地提交 (HEAD)** 之间的差异。
    
- `git diff HEAD`：查看**工作区**与**最新本地提交 (HEAD)** 之间的全部差异。
    
- `git diff <branch1> <branch2>`：比对两个分支之间的代码差异。
    

### 日志查看 (Log)

- `git log`：显示详细的提交历史记录。
    
- `git log --oneline`：以单行精简格式显示提交历史。
    
- `git log -p -n <number>`：显示最近 `n` 次提交，并展示每次提交的具体代码差异。
    
- `git log --graph --oneline --all`：以图形化拓扑结构展示所有分支的提交历史与合并走向。
    
- `git reflog`：记录本地仓库的所有操作日志（包括已被删除的提交和分支切换，常用于灾难恢复）。
    

## 4. 分支管理与代码合并

### 分支浏览与创建

- `git branch`：列出所有本地分支，当前所在分支前会带有 `*` 号。
    
- `git branch -a`：列出所有本地分支和远程分支。
    
- `git branch <branch-name>`：基于当前分支创建新分支，但不切换。
    

### 分支切换与检出

- `git checkout <branch-name>`：切换到指定分支。
    
- `git checkout -b <branch-name>`：创建并直接切换到该新分支。
    
- `git switch <branch-name>`：切换到指定分支（Git 2.23+ 推荐的纯粹切换命令）。
    
- `git switch -c <branch-name>`：创建并切换到新分支。
    

### 分支合并与变基

- `git merge <branch-name>`：将指定分支合并到当前分支。
    
- `git rebase <branch-name>`：将当前分支变基到指定分支之上（拉直提交历史）。
    

### 分支删除

- `git branch -d <branch-name>`：删除已合并的安全分支。
    
- `git branch -D <branch-name>`：强制删除未合并的分支。
    

## 5. 撤销与回滚操作

> ⚠️ **高危预警**：带有 `--hard` 参数的命令会彻底覆盖工作区代码，执行前请务必确认。

### 撤销工作区修改

- `git checkout -- <file>`：丢弃工作区中指定文件的修改，恢复到暂存区或最后一次提交的状态。
    
- `git checkout .`：丢弃当前工作区所有未暂存的修改。
    

### 取消暂存 (Unstage)

- `git restore --staged <file>`：将文件从暂存区移出，保持工作区不变（Git 2.23+ 推荐）。
    
- `git reset HEAD <file>`：旧版本中将文件从暂存区移出的命令。
    

### 版本回退 (Reset)

- `git reset --soft <commit-id>`：回退到指定提交。**保留**工作区与暂存区的代码修改。
    
- `git reset --mixed <commit-id>`：（默认模式）回退到指定提交。**保留**工作区修改，但**清空**暂存区。
    
- `git reset --hard <commit-id>`：彻底回退到指定提交。**清空**工作区与暂存区的所有未提交改动。
    

### 撤销已发布的提交 (Revert)

- `git revert <commit-id>`：通过创建一个新的反向提交来抵消指定提交的改动，适用于已推送到远程的分支。
    

## 6. 远程仓库交互

### 关联与查看

- `git remote -v`：查看当前关联的远程仓库地址及别名。
    
- `git remote add <shortname> <url>`：添加一个新的远程仓库并指定别名（通常为 `origin`）。
    
- `git remote remove <shortname>`：断开与指定远程仓库的关联。
    

### 推送与拉取

- `git clone <url>`：克隆远程仓库到本地，自动建立追踪关系。
    
- `git fetch <remote>`：从远程仓库下载所有分支和标签的最新变动，但不自动合并。
    
- `git pull <remote> <branch>`：从远程获取最新版本并自动合并到当前本地分支（相当于 `fetch` + `merge`）。
    
- `git push <remote> <branch>`：将本地指定分支的提交推送到远程对应分支。
    
- `git push -u origin <branch>`：推送分支并建立本地与远程的长期追踪关系，后续可直接简写为 `git push`。
    

## 7. 储藏管理 (Stash)

> 当你在开发新特性时收到紧急 Bug 修复任务，但当前代码尚未完善无法提交，可使用 `stash` 暂存工作现场。

- `git stash` 或 `git stash save "message"`：储藏当前工作区与暂存区的未提交修改。
    
- `git stash list`：查看所有储藏的记录列表。
    
- `git stash apply <stash@{id}>`：恢复指定的储藏内容，但**不删除**该储藏记录（默认恢复最近一次，即 `stash@{0}`）。
    
- `git stash pop`：恢复最近一次储藏的内容，并将其从储藏列表中**删除**。
    
- `git stash drop <stash@{id}>`：从列表中手工删除指定的储藏。
    
- `git stash clear`：清空所有的储藏记录。