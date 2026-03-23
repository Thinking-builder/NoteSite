
# Yara

> 本文主要参考文献，推荐大家可以去看看原作者的博客，我的笔记是它的扩展版本
> [先知社区：从零到一掌握yara规则编写](https://xz.aliyun.com/news/17520)

`YARA`是一种恶意软件模式匹配的工具 可以根据二进制 文本进行模式匹配

## Yara 示例

YARA规则由以下三部分组成：

1. **元数据 (meta)**：提供规则的描述性信息，如作者、日期等。
2. **字符串部分 (strings)**：定义需要匹配的字符串，可以是文本、十六进制或正则表达式。
3. **条件部分 (condition)**：指定匹配条件，决定规则何时触发

写出来的yara文件的后缀一般是`*.yar`。

假设我们现在要检测某个特定的文件：

```bash
yara rule.yar /path/to/suspicious.exe
# yara + 编写的*.yar + 待检测的文件
```

| 参数     | 含义                     | 示例                             |
| ------ | ---------------------- | ------------------------------ |
| `-r`   | 递归扫描目录下的所有文件           | `yara -r rule.yar /home/user/` |
| `-s`   | 输出匹配到的字符串内容            | `yara -s rule.yar malware.bin` |
| `-X`   | 输出匹配到的 XOR key（用于加密检测） | `yara -X rule.yar malware.bin` |
| `-p N` | 使用 N 个线程并行扫描           | `yara -p 8 rule.yar dir/`      |
| `-c`   | 只输出匹配数量，不显示详细信息        | `yara -c rule.yar samples/`    |

## 规则标识符

规则标识符是上面简单规则示例中跟在rule后的词, 比如下面基本规则中单词"dummy"也可以是一个规则标识符, 标识符命名有如下要求:

+ 英文字母或数字组成的字符串
+ 可以使用下划线字符
+ 第一个字符不能使用数字
+ **对大小写敏感**
+ 不能超过128个字符

## Yara 基本规则

每条规则都必须有一个**名称**和**条件**。

```yara
rule dummy {
         condition: true
 }
```

通常而言，每条规则的结构包括**字符串定义和条件**，如下所示：

```yara
rule HelloRule //This is an example for green hand
{ 
    string:
        $text_str = "possible text"
        $hex_str = {FB A3 7C 6?}
    condition:
        $text_str or $hex_str
}
```

## 怎么定义字符串

我们一共有三种方法：十六进制字符串、文本字符串、正则表达式。

### 十六进制字符串

**通配符** 十六进制字符串可以使用通配符`?`表示：

```yara
rule WormDetector
{
    strings:
        $hex_string = {FE 32 7? ?? D9}
    condition:
        $hex_string
}
```

这个规则会匹配文件中下面这些字符串

```text
FE 32 76 DD D9
```

等等，诸如此类的字符串（`?`能够匹配任意字母）

---

**不定长通配符** 用`[start_len-end_len]`这个符号表示，例如`[2-4]`，就是可以匹配任意长度从2到4的十六进制字符基本单元。

```yara
rule WormDetector
{
    strings:
        $hex_string = {AE [2-4] 97}
    condition:
        $hex_string
}
```

---

**有条件的字符串** 创建一个字符串对应多个情况

```yara
rule WormDetector
{
    strings:
        $hex_string = {AC 17 (FE AA | C1) B8}
    
    condition:
        $hex_string
}
```

### 文本字符串

除了使用十六进制的字符串，我们还可以使用文本：

```yara
rule WormDetector
{
    strings:
        $alert_string = "I'm coming...\n" //可以使用反斜杠作为转义符
    
    condition:
        $alert_string
}
```

**修饰符** 下面我们介绍修饰符，增加匹配的条件：

```yara
rule WormDetector
{
    strings:
        $normal_string = "Danger" nocase //nocase修饰符关闭Yara对大小写敏感
        $wide_string = "Closeing" wide nocase //wide 修饰符搜索宽字符串（例如UTF-16）
        $all_string = "你好hello" ascii wide nocase //使用两种方式搜索，ascii窄编码和宽编码方式
        $web_string = "feishu" fullword //匹配前后没有附加其他字符的单词（全词匹配）
    condition:
        $web_string
}
```

这个yara可以匹配：

```text
www.feishu.com
cn.feishu.edu
```

不可以匹配：

```text
aaafeishu.com
```

!!! Note "一些提示"
    **宽字符串**：用两个字节表示一个字符，很不同于我们在C++中学习过的`char`(一个字节表示一个字符)。仔细想为什么会有宽字符串。比如UTF-16就是宽字符串，用来支持中文、韩文等多语言字符。
    **字符串编码的默认方式**：ASCII编码方式

### 正则表达式

yara的正则表达式写在`\ \`之中，我们示范一个MD5码的检测规则书写:

```yara
rule MD5Detector
{
    strings:
        $re1 = /md5: [0-9a-fA-F]{32}/
        $re2 = /state: (on|off)/

    condition:
        $re1 and $re2
}
```

改规则将能够捕获任何状态下找到所有的md5字符串。同样值得一提的事，**我们能够在正则表达式中使用文本修饰符**。

**元字符** 指一个字符对于正则表达式解析器有特定含义的字符

|元字符|含义|
|---|---|
|`**`|引用下一个元字符|
|`^`|匹配文件开头|
|`$`|匹配文件的末尾|
|`｜`|多选|
|`()`|分组|
|`[]`|方括号字符类|

我们也可以使用以下量词：

|量词符号|含义|
|---|---|
|`*`|匹配0次或者多次|
|`+`|匹配1次或者多次|
|`?`|匹配0次或者1次|
|`{n}`|只匹配n次|
|`{n,}`|至少匹配n次|
|`{,m}`|至多匹配m次|
|`{n,m`|匹配n到m次|

也可以使用下面的转义字符：

|转义符|含义|
|---|---|
|`\t`|水平制表符|
|`\n`|换行符|
|`\r`|回车符|
|`\f`|换页符|
|`\a`|响铃|
|`\xNN`|十六进制代码为NN的字符|

也可以使用下面的字符类

|字符类|含义|
|---|---|
|`\w`|匹配单词字符，（单词可由字母数字加“_”组成）|
|`\W`|匹配非单词字符串|
|`\s`|匹配空白符|
|`\S`|匹配非空白符|
|`\d`|匹配一个十进制数字字符|
|`\D`|匹配一个非数字字符|
|`\b`|匹配单词边界|
|`\B`|匹配非单词边界|

我们考虑后续出一个正则表达式的教程来教会大家快速书写正则表达式

## 怎么写条件

我们之前展示中，可以看到，条件部分必须包含一个布尔表达式，说明在何种情况下满足规则。

### 布尔运算

字符串标识符相当于布尔变量，其值取决于文件中相关字符串是否存在。

```yara
rule PickUP
{
    strings:
        $a = "a"
        $b = "b"
        $c = "c"
        $d = "d"
    condition:
        ($a or $b) and ($c or $d)
}
```

### 字符串计数

我们使用`#`代替字符串标识符中的`$`，标识对该字符串的计数操作

```yara
rule CounterDetector
{
    strings:
        $a = "a"
        $b = "b"
    condition:
        #a == 2 and #b > 2
}
```

上面规则表示的含义是，**当样本中a字符串出现的次数等于2并且b字符串出现此处大于2时，规则生效**。

### 字符串偏移

有时我们还是需要知道该字符串是否在文件的某个特定偏移处, 或是在进程地址空间的某个虚拟地址处. 在这种情况下, 我们就需要操作符`at`.

```yara
rule Find
{
    strings:
        $a = "a"
        $b = "b"
    condition:
        $a at 100 and $b at 200
}
```

如果在文件的偏移100处(或者在一个正在运行的进程中, 位于虚拟地址100位置)发现了字符串`$a`, 我们的规则就能捕获到该字符串. 当然字符串`$b`也要在偏移200位置上才行.**你也可以使用十六进制表示而不一定要十进制.**

at操作符指定到一个具体的偏移量, 而你可以使用操作符in来指定字符串的位置范围。

```yara
rule Find
{
    strings:
        $a = "a"
        $b = "b"
    condition:
        $a in (0..100) and $b in (100..filesize)
}
```

字符串$a必须在偏移0-100之间才能找到, 而$b则必须是在偏移100到文件末尾位置(才能找到).

你也可以使用`@a[i]`来取得字符串`$a`第i个字符的偏移量或虚拟地址. 字符串索引以1开头 , 故第1个字符是`@a[1]`, 第2个是`@[a2]`并依此类推, 而不是以`@a[0]`开始. 如果你提供的索引值大过字符串总共出现的次数. 那结果就将是值NaN(Not a Number, 非数字).

### 匹配长度

对于包含跳转的许多正则表达式和十六进制字符串, 匹配长度用一个变量表示. 如果你有一个正则表达式/fo*/, 可以匹配字符串fo, foo和fooo, 那么各个的匹配长度都是不同的.

在字符串标识符前加一个!得到匹配长度, 你就可以将匹配长度作为你条件的一部分. 跟你获取偏移时使用字符@类似, `!a[1]`是第一个匹配到的字符串`$a`的长度, 而`!a[2]`就是第二个匹配到的字符串的长度, 依此类推. `!a`是`!a[1]`的缩写.

```yara
rule Hak5
{
    strings:
        $re1 = /hack*/    // Will catch on hacker, hacked, hack, hack*
 
    condition:
        !re1[1] == 4 and !re1[2] > 6
}
```

那么该规则可以匹配到下面的字符串：

```text
We hack things. We are hackers.
```

### 取值

可以通过 intxx uintxx 来读取指定偏移的值 我们通过一个例子说明：

```yara
rule pefile {
 
     condition: 
         uint16be(0) == 0x4d5a and uint32(uint32(0x3c)) == 0x4550 
                 
 }
```

**be代表大端序 默认小段序**
这里也可以使用虚拟地址：

```yara
rule testRule{
     condition:    uint16be(0x7ffe0006) == 0xa00f 
 }
```

### OF

表示至少满足 n 个在制定的字符集中：

```yara
rule PickUP
{
    strings:
        $a = "a"
        $b = "b"
        $c = "c"
    condition:
        2 of ($a,$b,$c)
}
```

### FOR

```yara
import "console"
 
 rule a{
     strings:
         $a = "114514"
 
     condition:    
         for all i in (1..3) : ( console.log(@a[i]))
 
 
 }
```
