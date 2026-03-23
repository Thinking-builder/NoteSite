# Shell 入门

> 这页作为终端与命令行的快速入门说明，补齐此前站内缺失的 Shell 入口。

## 为什么要学 Shell

Shell 的价值不在于记住很多命令，而在于理解“如何和文件系统、进程、管道交互”：

- 你会更容易理解 Git、MkDocs、编译器和包管理器的命令结构
- 你可以更高效地批量处理文件、搜索文本、查看日志
- 很多开发工具本质上都只是更复杂的命令行封装

## 最常用的三类命令

### 文件与目录

```bash
pwd
ls -la
cd docs
mkdir notes
mv old.md new.md
cp a.md backup/a.md
rm unused.md
```

### 文本查看与搜索

```bash
cat README.md
sed -n '1,40p' mkdocs.yml
rg "mkdocs gh-deploy" .
find docs -name '*.md'
```

### 管道与重定向

```bash
rg '^# ' docs -g '*.md' | sort
mkdocs build --clean > build.log
```

## 和本站最相关的命令

```bash
mkdocs build --clean
mkdocs gh-deploy
git status
git add .
git commit -m "..."
```

## 建议的学习顺序

1. 先理解路径、目录、文件移动
2. 再理解搜索、过滤、管道
3. 最后把 Git 和 MkDocs 命令串起来使用
