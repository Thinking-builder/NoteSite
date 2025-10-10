
# MASM32基本程序

本文参考了[CSDN - 汇编proto、proc、invoke伪指令与函数声明、函数定义、函数调用](https://blog.csdn.net/u011770174/article/details/77914375),其中代码来源于此，特此声明。

首先我们转载一个像诗一样优美的汇编程序范例

```Assemble
.386
.MODEL FLAT, C       
.DATA

.CODE
;------------------------------------------------------
;函数声明
Asm_Function_1 proto stdcall :dword,:dword

;------------------------------------------------------
;主函数
main_proc PROC
    ;函数调用
    invoke    Asm_Function_1,100,100h
    mov        edx,eax
main_proc ENDP

;------------------------------------------------------
;函数定义,实现简单功能 返回 arg1 + arg2 的值
Asm_Function_1 PROC  stdcall arg1:dword,arg2:dword
    mov        eax,arg1
    add        eax,arg2
    ret    8
Asm_Function_1 endp

END
```
