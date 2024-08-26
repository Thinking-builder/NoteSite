
# Easy markdown

>本篇文章的定位是掌握markdown的大致所有的语法（非扩展版本的），如果想要涉猎更加高妙的用法，例如快捷键等等，请参见beautiful markdown.
>本篇文章的参考资料源于[此处](https://markdownguide.org)。

## Markdown 标题语法{#beginning}

```C++
# heading level1

## heading level2

### heading level3

#### heading level4

##### heading level5

###### heading level6
```

>NOtice：标题与正文之间需要保持一行的空格
>语法规范：并且一级标题下面里面需要有二级标题，才能使用正常的标题

## Markdown 段落、换行语法

要创建段落，请使用空白行将文本分割。

比如这样，与上一句话实现了分割。

注意，不要这样：

```C++
    //使用缩进Tab，空格Space都无效
    I like math//其实并没有实际效果！在预览种无效果
```

如果你想实现换行而不是新建一个段落，你可以执行的操作：

```C++
    //way1
    I like math.  //两个空格+换行
    and I like English.

    //way2
    I like math.<br>//使用html的标签
    and I like English.
```

## Markdown 强调语法

### 粗体

|Markdown    |Html        |Preview     |
|------------|------------|------------|
|I just love `**bold text**`|I just love `<strong>bold text</strong>`|I just love **bold text**|

### 斜体

|Markdown    |Html        |Preview     |
|------------|------------|------------|
|A `*cat*` meow|A `<em>cat</em>` meow|A *cat* meow|

### 粗体和斜体的混合使用

|Markdown    |Html        |Preview     |
|------------|------------|------------|
|I like `***markdown***`|I like `<strong><em>markdown</em></strong>`|I like ***markdown***|

## Markdown 引用语法（又称块引用）

### 单引用

```C++
>Whatever happened,I like markdown!
```

预览效果如下：
>Whatever happened,I like markdown!

### 多引用

```C++
//如果引用块需要包含多个段落，可以在句子之间添加一个“>”
>I like markdown!
>
>who like markdown except you!
```

预览效果如下：
>I like markdown!
>
>who like markdown except you!

### 嵌套引用

```C++
//如果是嵌套引用，可以在需要嵌套的句子前面添加一个“>>”
>I like markdown!
>
>>who like markdown except you!
```

预览效果如下：
>I like markdown!
>
>>who like markdown except you!

### 带有其他元素的引用

```C++
//块引用 可以包含几乎所有的markdown元素
> - Revenue was off the chart.
> - Profits were higher than ever.
>
>  *Everything* is going according to **plan**.
```

预览效果如下：

> - Revenue was off the chart.
> - Profits were higher than ever.
>
> *Everything* is going according to **plan**.

## Markdown 列表语法

### 有序列表

|Markdown    |Html        |Preview     |
|------------|------------|------------|
|`1. first thing`<br>`2. second thing`|`<ol><li>1. first thing </li><li>2. second thing</li></ol>`|1. first thing <br> 2. second thing|

### 无序列表

> 创建无序列表，可以使用减号（-）、加号（+）或者单星号（*）

|Markdown    |Html        |Preview     |
|------------|------------|------------|
|`- First thing`|`<ul><li>First thing </li></ul>`|- First thing(表格内无法预览)|

预览效果入下：

- First thing

>注意事项：你需要在文本和这种语法句子之间保持空行，以免报错！
>
>一般地，在vscode里面不会使用（*）（+），而是使用（-）来创建无序列表。

### 可以在列表中嵌入其他元素

不再过多展示，因为这个真的不要太简单！

## Markdown 代码语法

### 单词、短语代码

|Markdown    |Html        |Preview     |
|------------|------------|------------|
|I type,supported by `` `markdown` ``|`I type,supported by <code>markdown</code>`|I type,supported by `markdown`|

### 转义反引号

详情请点开本文档的源代码，查看上面的代码。上面的代码使用了转义反引号。

### 编程多行代码段

```C++
//```(这里添加编程语言)
//多行代码内容
//```
```

## Markdown 分割线语法

```C++
//可以使用的分割线
***
---
______//推荐，下划线
```

预览效果如下：

>Hello，
>______
>World!

## Markdown 链接语法

### 链接与title

|Markdown    |Html        |Preview     |
|------------|------------|------------|
|`这是一个链接 [Markdown语法](https://markdown.com.cn)。`|`<a href="超链接地址" title="超链接title">超链接显示名</a>`|这是一个链接 [Markdown语法](https://markdown.com.cn)。|

### 网址以及email

```C++
//<https://markdown.com.cn>
//<fake@example.com>
```

预览效果如下：

<https://markdown.com.cn>
<fake@example.com>

## 带格式化的链接

```C++
//I love supporting the **[EFF](https://eff.org)**.
//This is the *[Markdown Guide](https://www.markdownguide.org)*.
//See the section on [`code`](#code).

//要将链接表示为代码，请在方括号中添加反引号。
```

预览效果如下：
I love supporting the **[EFF](https://eff.org)**.
This is the *[Markdown Guide](https://www.markdownguide.org)*.
See the section on [`code`](#code).

### 引用类型的链接

```C++
//链接的第一部分,注意之间需要一个空格（VScode）
[name] [label1]
//裂解的第二部分
//一般会放在段落的末尾或者md文档的末尾
[label1]:https://www.markdownguide.org
```

预览效果如下

>[markdownguide] [1]
>
>[1]:https://www.markdownguide.org

## Markdown 图片语法

### 一般的图片

|Markdown    |Html        |Preview     |
|------------|------------|------------|
|`![图片alt](图片链接 “图片title”)`|`<img src="picture link" alt="picture alt(format)" title="name" >`|略|

>在VScode中，直接把图片复制粘贴在这里就可以，不需要自己手码。

### 链接图片

```C++
//格式参考如下：
[![图片alt](图片链接 “图片title”)](网址链接)
```

预览效果如下:  

[![Markdownguide](hero-1.png "markdown")](https://markdownguide.org)

## Markdown 转义字符语法

### 可做转义的字符

要显示原本用于格式化markdown文本的符号，一般使用反斜杠（\）

下面列出可以转义的符号：
|`\`|`*`|`_`|`{}`|`[]`|`()`|`#`|`+`|`-`|`.`|`!`|

### 自动转义的字符

在Html文件中，常常对`<`和`&`两个符号进行特殊处理，如果你只想要使用这些符号，那么你必须使用实体的形式
像是`&lt;`和`&amp;`  
原因是，`<`常常用作起始标签，`&`用于标记Html实体。

>即使你在markdown中没有用实体的形式写，它也会自动将两个符号转义为html的实体形式

## Markdown 内嵌Html标签

>因为VScode并没有内嵌Html标签，语法系统不支持，所以略去，详情见[Markdown 内嵌html标签](https://markdown.com.cn/basic-syntax/htmls.html)

## Markdown 表格

### 一般化表格创建

```C++
| Syntax      | Description |
| ----------- | ----------- |//使用三个或多个连字符（---）创建每列的标题
| Header      | Title       |
| Paragraph   | Text        |
```

预览效果如下：
| Syntax      | Description |
| ----------- | ----------- |
| Header      | Title       |
| Paragraph   | Text        |

### 对齐

```C++
| Syntax      | Description | Test Text     |
| :---        |    :----:   |          ---: |
| Header      | Title       | Here's this   |
| Paragraph   | Text        | And more      |
//左对齐         中间对齐          右对齐
```

预览效果如下：
| Syntax      | Description | Test Text     |
| :---        |    :----:   |          ---: |
| Header      | Title       | Here's this   |
| Paragraph   | Text        | And more      |

## Markdown 脚注语法

```C++
Here's a simple footnote,[^1] and here's a longer one.[^bignote]

[^1]: This is the first footnote.

[^bignote]: Here's one with multiple paragraphs and code.
```

预览效果如下：
Here's a simple footnote,[^1] and here's a longer one.[^bignote]

[^1]: This is the first footnote.

[^bignote]: Here's one with multiple paragraphs and code.

## Markdown 删除线语法

``~~世界是平坦的。~~ 我们现在知道世界是圆的``

预览效果如下  

~~世界是平坦的。~~ 我们现在知道世界是圆的;

### Markdown 标题编号

> 这个可以方便回访文档的任何一个部分，值得一学。

``### My Great Heading {#custom-id}``

预览效果如下：（配合链接使用）
[go back to beginning](#beginning)

## Markdown 任务列表语法

```C++
- [x] Write the press release 
- [ ] Update the website
- [ ] Contact the media
```

预览效果如下：

- [x] Write the press release
- [ ] Update the website
- [ ] Contact the media

______

>还有一部分本文档并没有涉及，比如markdown的emoji使用等，此处可以参考[Markdownguide](https://markdownguide.org)
