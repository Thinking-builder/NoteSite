#include <iostream>

using namespace std;

void Swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
} // 这个可以使用xchg实现

void BubbleSort(int *arr, int size)
{
    // 从开始遍历的话把大的数交换后放到后面
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
                swap(arr[j], arr[j + 1]);
        } // 循环套循环
    } // 汇编这里用循环实现
}

int main()
{
    int arr[10] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    BubbleSort(arr, 10);
    for (int i = 0; i < 10; i++)
        cout << arr[i] << " ";
    return 0;
}

/*
涉及的知识点对照C++代码整理：
0.数据类型认知

本实验要求是比较10个1万以内的数字，然后这10个数字将会存储在一个数组里面

BYTE - 1个字节 - 最大值FF - 255；
WORD - 2个字节 - 最大值FFFF - 65535

那么本实验中我们为了最小的空间开支，我们使用WORD数据类型

然后类比C++创建数组的方式，因为汇编代码中的数组是顺序存储的，我们有如下的创建数组的方式：

```asm
；定义一个已经初始化好了的数组

table dword 10h,20h,30h,40h ;这个table就是一个符合要求的数组（一维数组）

；定义一个没有初始化的数组 - 数组名 命令 元素个数 dup(?)
barray WORD 20 dup(?)
```

我们需要知道关于访问这些数组的方式，所以需要给出一些基本的操作集合：
（1）获取指定位置的数组元素
我们以上面的table为例子，使用mov操作存储到数组的第一个元素
我们使用相对寻找地址的技巧，确定数组的元素
```asm
mov esi,1
mov eax,[table+esi*2] ;以table的地址位置做相对地址偏移，这个代表了table[b]的含义
```
(2)实现数组元素的修改和转换

我们需要实现数组元素的修改，一步到位的话，我们需要实现数组元素的交换

```asm
mov esi,pAdarray

L2:
    mov eax,[esi]
    cmp eax,[esi+2]
    jl L3 ;L3重新来一次准循环，相当于跳出这个处理函数
    xchg eax,[esi+2]
    mov [esi],eax

```


1. if (arr[j] > arr[j + 1]) - 汇编语言仿照书写IF-ELSE语句

使用cmp指令以及助记符（本节我们会用到的 - JB 小于跳转，JA大于跳转）
```asm:
cmp dword ptr ds:[var1],20     ; 判断是否大于20
jl L1                          ; 不大于则跳转

cmp dword ptr ds:[var2],100    ; 判断是否小于100
jg L1                          ; 不小于则跳转
```

底层原理阐述：CMP(比较)指令执行从目的操作数中减去源操作数的隐含减法操作，并且不修改任何操作数。
对于无符号的数字，机器通过ZF（零标志）、CF（进位）标志位的值对应出比较结果。
而通过有符号的数字，机器通过OF（溢出）、SF（符号）标志位的0、1状态比较出结果


2.循环的构建

循环的构建可以使用模块化的思维构建，也就是说需要构建一个Loop控制观测整个循环体

```asm

L3:
    add esi,2
    loop L2

    pop ecx
    loop L1
```

一般来说循环体的伪代码：

```asm
MOV CX, 5         ; 设置循环次数为5次
LOOP_START:
    ; 循环体代码
    ; 可以在这里执行需要重复的操作
    DEC CX         ; 循环次数减1
    JNZ LOOP_START  ; 如果CX寄存器不为0，则继续循环

```

3.利用堆栈模拟实现C++函数模块

如果我要在汇编代码中实现C++的函数并且成功地传入参数：
```C++
void BubbleSort(int *arr,int length) //传入数组的地质、数组的长度
```

在汇编中，我们一般是通过把相关的参数压入栈中，然后编写如下的PROC：

```asm
FunctionName PROC
    ;填充函数主体，使用ESP寄存器访问栈顶调取函数参数
FunctionName ENDP

.code
MAIN PROC

    push num2              ; 压入第二个参数
    push num1              ; 压入第一个参数
    call FunctionName     ; 调用函数
    mov result, eax        ; 将返回的结果存储到 result 变量中

    ; 结束程序
    invoke ExitProcess, 0

MAIN ENDP
END MAIN
```

*/