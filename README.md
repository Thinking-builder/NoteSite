# Thinking Builder Notes

一个基于 `MkDocs` 和 `Material for MkDocs` 的个人知识站点，用来长期整理课程笔记、技术总结与经验分享。

遵循 CC0 1.0 通用知识共享协议。

## 仓库结构

- `docs/`: 站点源内容，所有 Markdown、PDF、HTML 示例和静态资源都从这里发布
- `mkdocs.yml`: 站点导航、主题、插件和发布配置
- `site/`: 本地构建产物，不纳入版本控制

## 维护规则

新增或调整内容时，请同步检查：

1. 文件是否放在正确栏目目录下
2. `mkdocs.yml` 导航是否已更新
3. `docs/content_catalog.md` 是否收录该内容
4. 栏目导览页是否需要补充入口

## 常用命令

```bash
mkdocs build --clean
mkdocs gh-deploy
```
