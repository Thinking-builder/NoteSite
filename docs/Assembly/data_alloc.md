# 数据传送与运算

> 本章包含的内容：
> 1.数据传送指令（重点:``mov``,``movzx``,``movsx``）
> 2.算数运算指令
> 3.伪指令和操作符（重点:``offset``,``ptr``,``label``）
> 4.循环语句
> 5.内存操作数与寻址方式

## 数据传送指令

### mov指令

!!! note "MOV指令"
    mov - Move(Opcodes:88,89,8A,8B,8C,8E...)
    语法：
    + ``mov <reg>,<reg>``
    + ``mov <reg>,<mem>``
    + ``mov <mem>,<reg>``
    + ``mov <reg>,<imm>``
    + ``mov <mem>,<imm>``
    例子：
    ``mov BYTE ptr[var],5``

    解释：
    ``<reg>``:寄存器
    ``<mem>``:内存操作数（类似C++已经定义的变量）
    ``<imm>``:及时操作数（类似C++临时变量，或者是临时``lambda``

    movzx - 整数的零扩展
    movsx - 符号扩展传送指令

### LAFH、SAHF指令

### XCHG指令

e.g.使用XCHG指令实现C++的``swap``函数：交换两个内存操作数的值

```Asm
.data
  var1 DWORD 100h
  var2 DWORD 200h
.code
  mov var1,eax
  xchg eax,var2
  mov eax,var1
```

## 算数运算指令

### INC指令、DEC指令

INC指令使得操作数加1；
DEC指令从操作数减1；

两者的语法相同：

```asm
inc <reg>
inc <mem>
```

### ADD指令、SUB指令

$$ADD <Src>,<Dest>$$

ADD将相同尺寸的源操作数和目的操作数相加，相加的**结果存储在目的操作数**中。

### NEG指令

## 伪指令和操作符

### OFFSET操作符

OFFSET操作符返回数据标号的偏移地址。
OFFSET操作符获得的偏移地址占用4个字节。

### PTR操作符

PTR操作符可以重载操作数声明的默认尺寸。

```asm
.data
  var1 WORD 1234h
  var2 WORD 5678h
.code
  mov eax,DWORD PTR var1
  ;寄存器eax的十六进制值是56781234h
```

### TYPE操作符

返回变量的字节数

### LENGTHOF操作符

### SIZEOF操作符

### LABEL伪指令

## 循环语句

MASM32汇编程序如何实现循环？

程序通过控制转移改变汇编语言执行顺序的方法 - **无条件控制转移、条件控制转移**。

一般来说，一个汇编循环体的常见的结构如下：

```asm
MOV CX, 5         ; 设置循环次数为5次
LOOP_START:
    ; 循环体代码
    ; 可以在这里执行需要重复的操作
    DEC CX         ; 循环次数减1
    JNZ LOOP_START  ; 如果CX寄存器不为0，则继续循环

```

### CMP指令

### LOOP指令

+ LOOP **〈目的地址〉**
  
LOOP循环执行的内层逻辑：
  ECX寄存器为循环计数器
  LOOP指令执行时，ECX减一

  如果ECX不等于0，


## 内存操作数和寻址方式

### 间接寻址

任何一个32位寄存器


