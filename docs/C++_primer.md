
# C++ 进阶

> 该page将会从类开始介绍C++，类以及对象是C++不同于C的重要特性之一。</br>
> 因为笔者所接受的教学主要以PPt演示为主，逻辑性一般，所以在此使用md来梳理记忆重要知识

## 重载

> - **为什么C++有重载？**</br>
> 运算符重载：C++的运算符只支持基本的数据类型，但不支持自定义的数据类型

!!! tip 一些不能重载的情况：
    - 类与对象：
    析构函数不能够重载（没有返回值）；</br>
    定义的拷贝构造函数中的形式参数不能够重载；</br>

### 函数重载

> **函数重载实际上就是不同函数使用同一个名字**

基本规则是：

1. 重载函数至少有一对参数类型不同
2. 重载函数的参数个数不同

```C++
//一个正确的情况
void printstar();
void printstar(int,int);
void printstar(int,double);
//一个会引起二义性的情况
float add(int a,int b);
int add(int a,int b,int c = 0);

add(1,2)//该函数不知道调用哪一个函数
```

### 运算符重载

这个比较简单直接，记忆模板就可以了  

```C++
typename opeartor (+) (typename a,int b)//左边定义类型，右边基本类型
{
    //函数主体，就是+的内涵扩展
}
```

## 动态内存分配

??? note 基本动态分配
    动态分配一个变量：</br>
    ``int *p = new int(3);``
    ``new``+``数据类型``+``（初始值）``</br>
    动态分配一个数组：</br>
    ``int *p = new int[n];//n可以是变量，p是指向首元素的指针``
    </br>
    - 使用的基本流程：
    1. 判定是否分配成功
    ```C++
    int n;
    cin>>n;
    int *p = new int[n];
    if(p == NULL) return 0;
    ```
    2. 内存回收</br>
    ``new`` 对应 ``delete``</br>
    ``new[]`` 对应 ``delete[]``  
    注意 ⚠️：动态分配的内存空间的地址被修改，``delete``时会报错
    ```C++
    int *p = new int[20];
    for(int i = 0;i<20;i++)
    {
        *p = i;
        p++;//error's reason
    }delete []p;//error!
    ```

!!! question 如何保证动态内存分配浪费的空间最少？

### 动态分配与结构体

> 具体细节参考下面的代码解析

```C++
    struct student{
        char name[30];
        int id;
    };
    student* p = new student[30];
    cin>>(p+1)->id>>(p+1)->name;
    cout<<(p+1)->id<<" "<<(p+1)->name<<endl;
```

### 动态分配与二维数组

> 具体细节参考下面的代码解析

```C++
    int m,n;cin>>m>>n;
    int **pp = new int*[m];//apt to be wrong!
    for(int i = 0;i<m;i++)
    {
        pp[i] = new int[n];
    }//build 2-d array 
    if(pp == NULL) {cout<<"ERROR!"<<endl;return 0;}

    for(int i = 0;i<m;i++)
    {
        for(int j = 0;j<n;j++)
        {
            cin>>pp[i][j];
        }
    }//write in 2-d array 

    int *diger = &pp[0][0];
    for(int i = 0;i<m*n;i++)//如果你理解数组在内存中的分配关系，那么他就是一维数组
    {
        cout<<(int)*(diger+i)<<" ";
    }//pop out 2-d array

    for(int i = 0;i<m;i++)
    {
        delete [] pp[i];
    }
    delete [] pp;//clear 2-d array
```

!!! note 延伸：动态生成锯齿数组
    ```C++
    int m,n;cin>>m>>n;
    int **pp = new int*[m];//apt to be wrong!
    pp[0] = new int[3];
    pp[1] = new int[2];
    ```

## 类和对象

> 笔者不再赘述关于**类**的**定义**以及基础的**构成**
</br>

### 类的初始化及方法

- 通过默认值初始化

- 通过初始化列表初始化

```C++
//如果类的数据成员是公有的，可以使用初始化列表进行初始化
class address{
public:
  long telenum;
  char addr[30];
};
class person{
public:
  char name[15];
  int age;
  address paddr;
};

person p1 = {"Zhang hua",23,{2475096,"Nankai University"}}
```

</br>
- 通过构造函数初始化
</br>
??? warning
