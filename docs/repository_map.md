# 仓库结构与文件归属

> 这页用于说明“哪些文件属于哪个栏目、哪些文件是站点基础设施、哪些只是构建产物”，避免后续继续出现内容和导航不同步的问题。

## 顶层结构

| 路径 | 归属 | 说明 |
| --- | --- | --- |
| `docs/` | 站点源内容 | 所有会被 MkDocs 发布的 Markdown、PDF、HTML、图片、脚本资源 |
| `mkdocs.yml` | 站点配置 | 导航、主题、插件、静态资源注册、站点 URL |
| `README.md` | 仓库说明 | 面向维护者的快速说明与发布命令 |
| `site/` | 构建产物 | `mkdocs build` 生成目录，不纳入版本控制 |

## `docs/` 下的栏目归属

| 路径 | 栏目归属 | 内容类型 |
| --- | --- | --- |
| `docs/index.md` | 首页 | 站点总入口与导航分发页 |
| `docs/Introduction.md` | 关于本站 | 站点使命、浏览方式、维护原则 |
| `docs/repository_map.md` | 关于本站 | 仓库结构与同步更新规则 |
| `docs/content_catalog.md` | 关于本站 | 全站内容索引 |
| `docs/math/` | 数学栏目导览 | 数学专题入口页 |
| `docs/Linear_Algebra/` | 数学 / 线性代数 | 完整版、早期简版与 PDF 附件 |
| `docs/ISmath/` | 数学 / 信息科学数学 | 整除、同余、同余方程、原根和指数 |
| `docs/tech/` | 计算机与 AI 导览 | 技术专题入口页 |
| `docs/AI _Intro/` | 计算机与 AI / AI 导论 | 六章课程笔记与配图 |
| `docs/Deep_Learning/` | 计算机与 AI / 深度学习 | 预备知识、线性神经网络 |
| `docs/SQL/` | 计算机与 AI / SQL | SQL、DQL、DDL、DML 与配图 |
| `docs/Cplusplus/` | 计算机与 AI / C++ | 指针、编译器、链接器、学习指南 |
| `docs/Assembly/` | 计算机与 AI / 汇编与逆向 | 基础、MASM32、逆向工程、实验材料 |
| `docs/Tools/` | 工具与实践 | 当前收录 Yara |
| `docs/practice/` | 工具与实践导览 | Git、Vim、Yara 的统一入口 |
| `docs/experience/` | 经验与课程导览 | 大一课程经验与交流项目记录入口 |
| `docs/FreshM1/` `docs/FreshM2/` | 经验与课程 / 附件 | 学习资料 PDF |
| `docs/resources/` | 资料附件 | 全站 PDF、HTML、ZIP 的集中入口 |
| `docs/img/` `docs/javascripts/` | 站点静态资源 | favicon、MathJax 配置等 |

## 当前的同步更新规则

新增内容时，至少同步下面四处：

1. 把文件放进正确目录，避免再次堆在 `docs/` 根目录或临时目录里
2. 更新 `mkdocs.yml`，让页面能进入站点导航
3. 更新 [全站内容总览](content_catalog.md)，保证巡检时能看见全部内容
4. 如果是重要专题，再补充对应栏目导览页，保证首页到内容页的路径清晰

## 哪些文件不再纳入版本控制

以下内容属于本地噪音或构建结果，已经从维护逻辑中剥离：

- `site/` 构建产物
- `.DS_Store`
- `*.swp` / `*.swo`

这样处理后，仓库只保留可维护的源文件与配置文件，`mkdocs gh-deploy` 会在发布时重新构建并推送静态站点。
