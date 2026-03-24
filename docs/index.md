# Thinking Builder Notes

<div class="tb-hero" markdown>
<div class="tb-hero__copy">
<p class="tb-eyebrow">Knowledge Base · Notes Site · Long-term Maintenance</p>
<p
  class="tb-typewriter"
  data-typewriter='["把零散课程笔记整理成一个可以持续扩展的知识网站","让课程总结、技术笔记和经验分享拥有清晰入口","用 MkDocs Material 把内容组织成长期维护的知识系统"]'
  aria-label="把零散课程笔记整理成一个可以持续扩展的知识网站"
>
  <span class="tb-typewriter__text">把零散课程笔记整理成一个可以持续扩展的知识网站</span><span class="tb-typewriter__caret" aria-hidden="true"></span>
</p>
<p class="tb-hero__lead">
这里收录数学、AI、编程语言、汇编与逆向、工具实践、课程经验与兴趣分享。整个站点基于
<strong>MkDocs</strong> 与 <strong>Material for MkDocs</strong> 组织，目标不是一次性展示，而是长期积累与持续迭代。
</p>
<div class="tb-hero-meta">
  <span>68 篇 Markdown 笔记</span>
  <span>11 份 PDF 资料</span>
  <span>1 个 ZIP 归档</span>
  <span>长期增量维护</span>
</div>
<div class="tb-hero-actions">
  <a class="md-button md-button--primary" href="content_catalog/">立即浏览全部内容</a>
  <a class="md-button" href="repository_map/">查看仓库结构</a>
</div>
</div>

<div class="tb-hero__art" aria-hidden="true">
  <div class="tb-orbit tb-orbit--a"></div>
  <div class="tb-orbit tb-orbit--b"></div>
  <div class="tb-orbit tb-orbit--c"></div>
  <div class="tb-signal">
    <span class="tb-signal__label">Topics</span>
    <strong>Math · AI · Code · Reverse</strong>
  </div>
  <div class="tb-panel tb-panel--top">
    <span class="tb-panel__kicker">Structure</span>
    <strong>清晰导航</strong>
    <small>每篇笔记都有归属</small>
  </div>
  <div class="tb-panel tb-panel--bottom">
    <span class="tb-panel__kicker">Workflow</span>
    <strong>MkDocs + Material</strong>
    <small>build / deploy / iterate</small>
  </div>
</div>
</div>

<div class="grid cards" markdown>

-   ## 先看这里

    ---

    了解站点的使命、浏览方式以及维护原则。

    [站点使命](Introduction.md)

    [仓库结构与文件归属](repository_map.md)

-   ## 全站总览

    ---

    所有已发布内容都在这里集中收录，适合快速检索与巡检。

    [查看内容总览](content_catalog.md)

    [查看资料附件](resources/index.md)

-   ## 数学与形式化

    ---

    线性代数完整版与早期简版、信息科学数学笔记都已归档到统一入口。

    [进入数学栏目](math/index.md)

-   ## 计算机与 AI

    ---

    覆盖 CS 基础、AI 导论、深度学习、SQL、C++、Qt、Shell 与 Assembly。

    [进入技术栏目](tech/index.md)

-   ## 工具与经验

    ---

    包括 Git、Vim、Yara、课程经验以及交流项目记录。

    [查看工具实践](practice/index.md)

    [查看课程经验](experience/index.md)

</div>

## 本次整理重点

- 将此前未纳入导航的 AI 导论、信息科学数学、Assembly 原理与逆向等内容全部补上入口
- 新增“仓库结构与文件归属”“全站内容总览”“资料附件总表”三类管理页面
- 改用 Material 风格的统一首页与栏目页，减少首页中的内联样式和一次性排版
- 清理构建产物与临时文件，后续部署只依赖 `mkdocs gh-deploy`

## 推荐浏览路径

1. 初次访问：先读 [站点使命](Introduction.md)
2. 想系统看内容：直接打开 [全站内容总览](content_catalog.md)
3. 想按专题浏览：从 [数学](math/index.md)、[计算机与 AI](tech/index.md)、[工具与实践](practice/index.md) 进入

## 联系方式

如果你有勘误、建议或希望交流的主题，可以联系：<amorstep7@gmail.com>

![Welcome](./Welcome.gif)
