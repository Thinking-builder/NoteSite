
# 汇编语言与逆向工程

这门课对初学者十分不友好，而且你如果只是上课听听，大概率的情况是你啥也学不到。

举个简单的例子，比如说“**段地址*16+偏移地址 = 物理地址**”这个知识点，如果你理解的不透彻的话，你大概率可能看不懂下面这张图片（为什么两个不同的地址拿取了相同的内容？）

![地址的本质](./地址的本质.png)

在知乎上，我发布了一篇回答[汇编语言光速入门（理解本质而非死记硬背版）](https://zhuanlan.zhihu.com/p/11914694601)，你可以参考下，但是为啥我还要做一个笔记本。因为网络上教授汇编尤其是MASM32或者Intel的IA-32处理器体系架构的教程零散且杂乱，所以我就做了一个搜集整理和再思考的工作。希望能够帮到你。



<div
    class="animated-card"
    style="border: 2px solid #d1e3f8; border-radius: 12px; padding: 20px; max-width: 420px; background-color: #f9fbfd; box-shadow: 0 4px 6px rgba(0, 0, 0, 0.1); font-family: 'Segoe UI', Tahoma, Geneva, Verdana, sans-serif; margin: 20px auto;">
    <a href="https://www.zhihu.com/question/48624109/answer/52487739079" target="_blank"
        style="text-decoration: none; color: #1e293b; display: block;">
        <h2 style="font-size: 18px; font-weight: bold; margin-bottom: 10px; color: #2563eb; transition: color 0.3s ease;">
            怎样在两周之内学好汇编语言？
        </h2>
        <p style="font-size: 14px; color: #475569;">点击查看详细内容：知乎上一个有趣的问题及其精选答案。</p>
    </a>
</div>

<style>
    /* 初始淡入动画，仅在页面加载时生效 */
    .animated-card {
        animation: fadeIn 0.8s ease;
    }

    @keyframes fadeIn {
        from {
            opacity: 0;
            transform: scale(0.9);
        }
        to {
            opacity: 1;
            transform: scale(1);
        }
    }

    /* 鼠标悬浮效果，仅在悬浮到卡片本身时生效 */
    .animated-card:hover {
        transform: scale(1.05);
        box-shadow: 0 8px 12px rgba(0, 0, 0, 0.15);
        background-color: #eef4fa;
        transition: transform 0.3s ease, box-shadow 0.3s ease, background-color 0.3s ease;
    }

    .animated-card:hover h2 {
        color: #0f172a;
    }
</style>
