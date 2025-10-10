
# MASM 指令和函数

## MOVSX、MOVZX

``MOVZX``：复制尺寸较小的操作数到尺寸较大的操作数 - **不看符号，直接高位补0，低位赋值**
``MOVSX``：符号扩展传送指令，最高位循环填充所有扩展位 - **先看符号，高位正号全补0、负号全补1，然后低位赋值**

```Assemble
.data
    var1 BYTE 0A0h
.code
    movzx eax,var1 ;零扩展：EAX = 000000A0h
    movsz ebx,var1 ;var1二进制最高位为1，所以符号扩展：EBX = FFFFFFA0h
```

## XCHG指令

该指令可以交换两个操作数的内容

```Assemble
XCHG reg,reg
XCHG reg,mem
XCHG mem,reg
```

## NEG、NOT指令

+ ``NEG``：把操作数按位取反加一 （可以用来求一个数的相反数）
+ ``NOT``：把操作数按位取反

```Assemble
MOV AL 77
NEG AL（计算后的AL的结果为-77）
;NOT AL（计算后的AL的结果为-78）
```

```Assemble
.data 
        var DWORD 1000h
.code
       neg var；在对 var 执行 NEG 操作后，其十六进制值是 FFFFF000h
```

## OFFSET指令

在MASM32的32位程序中，应该是这样的：

```Assemble
.data
    var1 DWORD 0
.code
    mov eax, OFFSET var1 ; EAX 存储 var1 的偏移地址，占用 4 字节
```
