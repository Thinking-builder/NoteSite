
# MASM32 Hello World

```Assemble
str_hello BYTE “Hello World!”, 0Dh, 0Ah, 
          BYTE “I love assembly language”, 
          BYTE 0Dh, 0Ah, 0
```

+ ``0Dh``和``0Ah``是CR/LF（回车、换行）的ASCII编码
+ 字符串的结尾是``0``

在这一点上，和DOS系统就不一样了。而且值得注意的是，'$'符号在MASM中可以用来**计算字符串的长度大小**
  
```Assemble
;计算字符串的长度
str_hello BYTE “Hello World!”, 0Dh, 0Ah, 
          BYTE “I love assembly language”, 
          BYTE 0Dh, 0Ah, 0
str_size = ($ - str_hello)

;计算数组的个数
dw_array DWORD 0, 1, 2, 3, 4
array_size = ($ - dw_array)/4 
;这里为什么除4的原因很简单，因为'$'是地址，如果你懂了之前的知识，这很容易理解
```

## StdIn、StdOut

``StdIn  PROTO :DWORD,:DWORD`` 有两个参数，第一个是内存存储空间的起始地址，第二个是内存存储空间的大小。

``StdOut PROTO :DWORD``  只有一个参数，是内存存储空间的起始地址。

```Assemble
.data
    buf BYTE 20 dup(0)
.code
    invoke StdIn,addr buf,20
    invoke StdOut,addr buf
```

## Invoke

使用invoke伪指令会**帮你完成参数校检和压参操作**，也就是说不用写压参的push指令。直接和高级语言一样直接调用函数即可.

``invoke 函数名[，参数1][，参数2]……``

```Assemble
;有参数函数
invoke  Asm_Function_1,100,0x100

;没有参数函数
invoke Asm_Function_2
```

## Hello World

```Assemble
.386
.model flat, stdcall
option casemap :none
include \masm32\include\windows.inc
include \masm32\include\kernel32.inc
include \masm32\include\masm32.inc
includelib \masm32\lib\kernel32.lib
includelib \masm32\lib\masm32.lib
;常用程序开头，调用一些固有库，类似'#include<iostream>'

.data
str_hello BYTE "Hello World!", 0

.code
start:
invoke StdOut, addr str_hello
invoke ExitProcess, 0
END start
```
