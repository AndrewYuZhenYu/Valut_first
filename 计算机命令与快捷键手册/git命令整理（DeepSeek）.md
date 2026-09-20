# Git 命令完全手册

## 1. 配置与初始化

### 配置命令

```bash
# 设置全局用户名和邮箱
git config --global user.name "Your Name"
git config --global user.email "your.email@example.com"

# 设置当前仓库的用户名和邮箱
git config user.name "Your Name"
git config user.email "your.email@example.com"

# 查看所有配置
git config --list

# 查看全局配置
git config --global --list

# 设置默认编辑器
git config --global core.editor "code --wait"

# 设置别名
git config --global alias.co checkout
git config --global alias.br branch
git config --global alias.st status
git config --global alias.lg "log --oneline --graph"

# 设置颜色输出
git config --global color.ui auto

# 设置行尾处理（Windows）
git config --global core.autocrlf true

# 设置行尾处理（Mac/Linux）
git config --global core.autocrlf input

# 查看特定配置项
git config user.name
```

### 初始化仓库

```bash
# 初始化新仓库
git init

# 初始化指定目录的仓库
git init /path/to/repository

# 初始化裸仓库（用于远程仓库）
git init --bare

# 克隆远程仓库
git clone <repository-url>

# 克隆特定分支
git clone -b <branch-name> <repository-url>

# 克隆指定深度（浅克隆）
git clone --depth 1 <repository-url>

# 克隆到指定目录
git clone <repository-url> <directory-name>
```

## 2. 基本操作

### 文件状态

```bash
# 查看状态
git status

# 简短输出状态
git status -s
git status --short

# 忽略被追踪文件的修改（仅显示未追踪文件）
git status -uno
```

### 添加文件

```bash
# 添加单个文件
git add <filename>

# 添加多个文件
git add file1 file2 file3

# 添加所有文件（包括新文件、修改、删除）
git add -A
git add --all

# 添加当前目录所有文件（不包括删除）
git add .

# 添加所有修改和删除（不包括新文件）
git add -u
git add --update

# 交互式添加（按块选择）
git add -i

# 补丁模式添加（逐块确认）
git add -p
```

### 提交

```bash
# 提交并添加消息
git commit -m "commit message"

# 提交所有已追踪的修改（跳过git add）
git commit -a -m "message"

# 修改最后一次提交（消息或内容）
git commit --amend

# 修改最后一次提交的消息
git commit --amend -m "new message"

# 添加文件到最后一次提交
git add forgotten-file
git commit --amend

# 空提交（用于触发CI/CD）
git commit --allow-empty -m "trigger build"
```

## 3. 分支操作

### 创建与切换

```bash
# 列出本地分支
git branch

# 列出所有分支（包括远程）
git branch -a

# 列出远程分支
git branch -r

# 创建新分支
git branch <branch-name>

# 切换分支
git checkout <branch-name>

# 创建并切换分支
git checkout -b <branch-name>

# 从远程分支创建本地分支
git checkout -b <local-branch> origin/<remote-branch>

# 切换回上一个分支
git checkout -

# 使用switch命令（Git 2.23+）
git switch <branch-name>
git switch -c <branch-name>
```

### 合并与变基

```bash
# 合并分支
git merge <branch-name>

# 快进合并（禁用快进）
git merge --no-ff <branch-name>

# 压缩合并（将多个提交压缩成一个）
git merge --squash <branch-name>

# 合并并提交（默认）
git merge --commit <branch-name>

# 变基操作
git rebase <branch-name>

# 交互式变基（整理提交历史）
git rebase -i HEAD~3

# 继续变基（解决冲突后）
git rebase --continue

# 跳过当前提交
git rebase --skip

# 放弃变基
git rebase --abort

# 变基时保留合并提交
git rebase --preserve-merges
```

### 删除分支

```bash
# 删除本地分支
git branch -d <branch-name>

# 强制删除未合并的分支
git branch -D <branch-name>

# 删除远程分支
git push origin --delete <branch-name>
git push origin :<branch-name>

# 清理本地不存在的远程分支引用
git remote prune origin
```

## 4. 远程操作

### 远程仓库管理

```bash
# 查看远程仓库
git remote

# 查看详细信息
git remote -v

# 添加远程仓库
git remote add <name> <url>

# 修改远程仓库地址
git remote set-url <name> <new-url>

# 删除远程仓库
git remote remove <name>

# 重命名远程仓库
git remote rename <old-name> <new-name>

# 显示远程仓库信息
git remote show <name>
```

### 推送与拉取

```bash
# 推送分支
git push origin <branch-name>

# 推送并设置上游
git push -u origin <branch-name>

# 推送所有分支
git push --all origin

# 推送标签
git push --tags

# 删除远程分支
git push origin --delete <branch-name>

# 强制推送（危险）
git push --force origin <branch-name>

# 强制推送但避免覆盖他人提交
git push --force-with-lease

# 拉取远程更新
git pull

# 拉取并变基
git pull --rebase

# 仅获取远程更新（不合并）
git fetch

# 获取所有远程仓库的更新
git fetch --all

# 获取特定分支
git fetch origin <branch-name>

# 获取并清理已删除的远程分支引用
git fetch --prune
```

## 5. 查看历史

### 日志查看

```bash
# 查看提交历史
git log

# 单行显示
git log --oneline

# 图形化显示
git log --graph

# 显示最近n条提交
git log -n 10

# 显示每次修改的差异
git log -p

# 显示统计信息
git log --stat

# 指定作者
git log --author="name"

# 指定提交者
git log --committer="name"

# 搜索提交消息
git log --grep="keyword"

# 显示文件修改历史
git log --follow <filename>

# 查看某个文件的修改历史
git log -p <filename>

# 美化输出
git log --pretty=format:"%h - %an, %ar : %s"

# 显示分支图
git log --oneline --graph --all --decorate
```

### 差异对比

```bash
# 查看工作区和暂存区的差异
git diff

# 查看暂存区和最后提交的差异
git diff --staged
git diff --cached

# 查看工作区和最后提交的差异
git diff HEAD

# 查看两个提交的差异
git diff <commit1> <commit2>

# 查看两个分支的差异
git diff <branch1> <branch2>

# 查看单个文件的差异
git diff <filename>

# 显示差异的统计信息
git diff --stat

# 忽略空白字符
git diff -w

# 查看文件的单词级别差异
git diff --word-diff
```

## 6. 撤销与恢复

### 工作区撤销

```bash
# 丢弃工作区的修改
git checkout -- <filename>
git restore <filename>  # Git 2.23+

# 丢弃所有工作区修改
git checkout -- .
git restore .  # Git 2.23+

# 从暂存区移除文件（不删除文件）
git reset HEAD <filename>
git restore --staged <filename>  # Git 2.23+

# 取消暂存所有文件
git reset HEAD
```

### 提交撤销

```bash
# 撤销提交，保留修改
git reset --soft HEAD~1

# 撤销提交，并取消暂存
git reset --mixed HEAD~1

# 彻底撤销提交，删除修改
git reset --hard HEAD~1

# 撤销到指定提交
git reset --hard <commit-hash>

# 撤销合并
git reset --hard ORIG_HEAD

# 恢复指定提交（生成新提交）
git revert <commit-hash>

# 恢复多个提交
git revert <oldest>..<newest>

# 恢复合并提交
git revert -m 1 <merge-commit-hash>

# 恢复但不自动提交
git revert -n <commit-hash>
```

### 暂存操作

```bash
# 暂存当前修改
git stash

# 暂存并包含未追踪文件
git stash -u
git stash --include-untracked

# 暂存所有文件（包括被忽略的文件）
git stash -a

# 列出所有暂存
git stash list

# 恢复最近暂存（保留暂存）
git stash apply

# 恢复特定暂存
git stash apply stash@{1}

# 恢复并删除暂存
git stash pop

# 删除最近暂存
git stash drop

# 删除特定暂存
git stash drop stash@{1}

# 清空所有暂存
git stash clear

# 查看暂存内容
git stash show

# 查看暂存内容的详细信息
git stash show -p
```

## 7. 标签管理

### 创建标签

```bash
# 创建轻量标签
git tag <tag-name>

# 创建附注标签（推荐）
git tag -a <tag-name> -m "tag message"

# 为历史提交打标签
git tag -a <tag-name> <commit-hash> -m "message"

# 创建签名标签
git tag -s <tag-name> -m "message"
```

### 查看与删除

```bash
# 列出所有标签
git tag

# 列出匹配模式的标签
git tag -l "v1.*"

# 查看标签详细信息
git show <tag-name>

# 删除本地标签
git tag -d <tag-name>

# 删除远程标签
git push origin --delete <tag-name>
git push origin :refs/tags/<tag-name>

# 推送单个标签
git push origin <tag-name>

# 推送所有标签
git push --tags

# 推送所有标签并包括未推送的提交
git push --follow-tags
```

## 8. 高级操作

### 交互式变基

```bash
# 整理最近3次提交
git rebase -i HEAD~3

# 交互式变基的常用命令：
# pick - 使用该提交
# reword - 使用该提交但修改提交信息
# edit - 使用该提交但停下来修改
# squash - 使用该提交但合并到前一个提交
# fixup - 类似squash但丢弃提交信息
# drop - 删除该提交

# 拆分提交
git rebase -i HEAD~1
# 在编辑器中将要拆分的提交标记为edit
git reset HEAD^
git add file1
git commit -m "part 1"
git add file2
git commit -m "part 2"
git rebase --continue
```

### 二分查找定位问题

```bash
# 开始二分查找
git bisect start

# 标记当前版本有问题
git bisect bad

# 标记已知正常版本
git bisect good <commit-hash>

# 测试当前版本并标记
git bisect good  # 如果正常
git bisect bad   # 如果有问题

# 使用脚本自动测试
git bisect run <command>

# 重置二分查找
git bisect reset

# 查看二分查找日志
git bisect log
```

### 子模块管理

```bash
# 添加子模块
git submodule add <repository-url> <path>

# 克隆包含子模块的仓库
git clone --recursive <repository-url>

# 初始化子模块
git submodule init

# 更新子模块
git submodule update

# 更新所有子模块到最新版本
git submodule update --remote

# 更新子模块并递归
git submodule update --init --recursive

# 查看子模块状态
git submodule status

# 删除子模块
git submodule deinit <path>
git rm <path>
```

### 补丁操作

```bash
# 生成补丁文件
git format-patch -1 <commit-hash>

# 生成最后n次提交的补丁
git format-patch -n HEAD

# 生成两个提交之间的补丁
git format-patch <commit1>..<commit2>

# 应用补丁
git apply <patch-file>

# 检查补丁是否可用
git apply --check <patch-file>

# 应用并添加修改
git am <patch-file>

# 应用一系列补丁
git am *.patch

# 跳过失败的补丁
git am --skip

# 解决冲突后继续应用
git am --continue

# 放弃应用补丁
git am --abort
```

## 9. 清理与优化

### 垃圾回收

```bash
# 手动触发垃圾回收
git gc

# 激进模式垃圾回收
git gc --aggressive

# 自动垃圾回收
git gc --auto

# 检查仓库对象
git fsck

# 验证完整性和连接性
git fsck --full

# 清理未引用的对象
git prune

# 优化仓库
git repack
```

### 清理命令

```bash
# 清理未追踪的文件
git clean

# 预览要删除的文件
git clean -n

# 删除未追踪的文件
git clean -f

# 删除未追踪的目录
git clean -fd

# 删除被.gitignore忽略的文件
git clean -fx

# 交互式清理
git clean -i

# 移除追踪但忽略的文件
git rm --cached <filename>

# 从版本库中删除文件
git rm <filename>

# 删除目录
git rm -r <directory>
```

## 10. 调试与诊断

### 查看变更历史

```bash
# 查看每行代码的最后修改
git blame <filename>

# 带日期和作者信息的blame
git blame -L 10,20 <filename>

# 忽略空白字符
git blame -w <filename>

# 显示修改前的原始行号
git blame -l <filename>

# 查看文件移动历史
git blame -M <filename>

# 查看代码段移动历史
git blame -C <filename>

# 查找文本何时出现
git log -S "text" --source --all

# 查找新增或删除的内容
git log -G "regex" --source --all

# 查看某个函数的变更历史
git log -L :function-name:<filename>
```

### 仓库信息查看

```bash
# 查看仓库信息
git ls-files

# 查看被追踪的文件
git ls-tree HEAD

# 查看未合并的文件
git ls-files -u

# 查看被忽略的文件
git ls-files --others -i --exclude-standard

# 查看工作树信息
git ls-tree -r HEAD --name-only

# 显示索引信息
git ls-files --stage

# 统计代码行数
git ls-files | xargs wc -l

# 查看提交活跃度
git shortlog -sn
git shortlog -sne
```

## 11. 协作工作流

### 处理冲突

```bash
# 查看冲突文件
git status

# 使用工具解决冲突
git mergetool

# 采用当前分支版本
git checkout --ours <filename>
git checkout HEAD -- <filename>  # 旧语法

# 采用合并分支版本
git checkout --theirs <filename>

# 标记冲突已解决
git add <filename>

# 查看冲突类型
git ls-files -u

# 查看三方差异
git diff --base <filename>
git diff --ours <filename>
git diff --theirs <filename>
```

### 拣选与樱桃拣选

```bash
# 拣选单个提交
git cherry-pick <commit-hash>

# 拣选多个提交
git cherry-pick <commit1> <commit2>

# 拣选范围
git cherry-pick <commit1>..<commit2>

# 拣选但不自动提交
git cherry-pick -n <commit-hash>

# 继续拣选（解决冲突后）
git cherry-pick --continue

# 跳过当前拣选
git cherry-pick --skip

# 放弃拣选
git cherry-pick --abort

# 拣选并编辑提交信息
git cherry-pick -e <commit-hash>
```

### 变基远程分支

```bash
# 从上游变基
git pull --rebase

# 设置默认变基
git config --global pull.rebase true

# 变基到远程分支
git rebase origin/main

# 变基并保留合并提交
git rebase --preserve-merges origin/main

# 交互式变基远程分支
git rebase -i origin/main

# 推送变基后的分支
git push --force-with-lease
```

## 12. 工作树管理

```bash
# 添加工作树
git worktree add <path> <branch>

# 添加并创建新分支
git worktree add -b <new-branch> <path> <start-point>

# 列出所有工作树
git worktree list

# 锁定工作树
git worktree lock <path>

# 解锁工作树
git worktree unlock <path>

# 删除工作树
git worktree remove <path>

# 清理工作树元数据
git worktree prune
```

## 13. 归档与导出

```bash
# 创建代码归档
git archive --format=zip HEAD > archive.zip

# 创建tar归档
git archive --format=tar HEAD > archive.tar

# 导出指定分支
git archive --format=zip --output=archive.zip main

# 导出指定提交
git archive --format=zip <commit-hash> > archive.zip

# 导出子目录
git archive --format=zip HEAD:subdirectory > archive.zip

# 添加前缀
git archive --format=zip --prefix=project-name/ HEAD > archive.zip

# 使用管道创建tar并压缩
git archive HEAD | gzip > archive.tar.gz
git archive HEAD | bzip2 > archive.tar.bz2
```

## 14. 配置管理

### 配置文件位置

```bash
# 系统级配置 /etc/gitconfig
git config --system --list

# 全局配置 ~/.gitconfig
git config --global --list

# 仓库级配置 .git/config
git config --local --list

# 编辑配置文件
git config --global --edit

# 删除配置项
git config --global --unset <key>

# 添加多值配置
git config --global --add <key> <value>
```

### 常用配置示例

```bash
# 设置别名
git config --global alias.co checkout
git config --global alias.br branch
git config --global alias.st status
git config --global alias.lg "log --oneline --graph --all"
git config --global alias.unstage "reset HEAD --"
git config --global alias.last "log -1 HEAD"
git config --global alias.visual "!gitk"

# 设置代理
git config --global http.proxy http://proxy.example.com:8080
git config --global https.proxy https://proxy.example.com:8080
git config --global --unset http.proxy

# 设置差分析工具
git config --global merge.tool vimdiff
git config --global diff.tool vimdiff

# 设置缓存
git config --global credential.helper cache
git config --global credential.helper 'cache --timeout=3600'

# 性能优化
git config --global core.preloadindex true
git config --global core.fscache true
git config --global gc.auto 256
```

## 15. 别名与快捷命令

```bash
# 创建复杂别名
git config --global alias.graph "log --graph --oneline --all --decorate"

# 创建包含参数的别名
git config --global alias.newbranch "!f() { git checkout -b $1; }; f"

# 创建命令组合
git config --global alias.sync "!git pull --rebase && git push"

# 创建shell命令别名
git config --global alias.ignore "!echo $1 >> .gitignore"

# 查看所有别名
git config --global --get-regexp alias

# 常用别名示例
# git st = git status
# git ci = git commit
# git br = git branch
# git co = git checkout
# git df = git diff
# git lg = git log --oneline --graph
# git undo = git reset --soft HEAD^
```

## 16. 故障排除

### 常见问题解决

```bash
# 重置所有未提交的更改
git reset --hard HEAD

# 删除未追踪的文件和目录
git clean -fd

# 恢复已删除的分支
git reflog
git checkout -b <branch-name> <commit-hash>

# 修复分离HEAD状态
git branch <new-branch>
git checkout <new-branch>

# 处理 "fatal: refusing to merge unrelated histories"
git pull origin main --allow-unrelated-histories

# 修改错误的作者信息
git commit --amend --author="New Author <email@example.com>"

# 批量修改历史作者信息（需要谨慎）
git filter-branch --env-filter '
OLD_EMAIL="old@example.com"
CORRECT_NAME="New Name"
CORRECT_EMAIL="new@example.com"
if [ "$GIT_COMMITTER_EMAIL" = "$OLD_EMAIL" ]
then
    export GIT_COMMITTER_NAME="$CORRECT_NAME"
    export GIT_COMMITTER_EMAIL="$CORRECT_EMAIL"
fi
' --tag-name-filter cat -- --branches --tags
```

### 性能诊断

```bash
# 测量命令执行时间
git --exec-path

# 查看Git版本
git --version

# 调试模式执行命令
GIT_TRACE=1 git push origin main

# 查看性能统计
GIT_TRACE_PERFORMANCE=1 git clone <url>

# 查看打包信息
git verify-pack -v .git/objects/pack/*.idx

# 查看仓库大小
git count-objects -vH

# 查找大文件
git rev-list --objects --all | git cat-file --batch-check='%(objecttype) %(objectname) %(objectsize) %(rest)' | awk '/^blob/ {print substr($0,6)}' | sort --numeric-sort --key=2 | tail -10
```

## 17. 安全性

### GPG签名

```bash
# 配置GPG密钥
git config --global user.signingkey <key-id>

# 对提交进行签名
git commit -S -m "signed commit"

# 对标签进行签名
git tag -s <tag-name> -m "signed tag"

# 验证签名
git log --show-signature

# 验证标签签名
git tag -v <tag-name>

# 要求所有提交都有签名
git config --global commit.gpgsign true
```

### 敏感信息处理

```bash
# 从历史中删除文件
git filter-branch --force --index-filter \
  "git rm --cached --ignore-unmatch <file>" \
  --prune-empty --tag-name-filter cat -- --all

# 使用BFG Repo-Cleaner（推荐）
# bfg --delete-files <file>

# 添加敏感文件到.gitignore
echo "config/secrets.yml" >> .gitignore

# 禁止跟踪文件权限变更
git config core.fileMode false

# 扫描历史中的敏感信息
git log -S "password" --source --all
```

## 总结

这份命令手册涵盖了Git的绝大多数常用和高级命令。建议：

1. **日常开发**：重点关注基本操作、分支管理和撤销恢复
2. **团队协作**：熟悉远程操作、冲突处理和变基
3. **项目管理**：掌握标签、子模块和归档操作
4. **问题排查**：学习二分查找和blame命令
5. **效率提升**：合理使用别名和配置优化

记住，Git命令繁多，但80%的日常操作只需要20%的常用命令。建议从基础开始，逐步掌握高级功能。