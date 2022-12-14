# 【排序】

## 【总结】

|                  | 时间复杂度 | 空间复杂度 | 稳定性 |
| :--------------- | :--------: | :--------: | :----: |
| 选择排序         |   O(N^2)   |    O(1)    |   ×    |
| 冒泡排序         |   O(N^2)   |    O(1)    |   √    |
| 插入             |   O(N^2)   |    O(1)    |   √    |
| 归并             | O(N*logN)  |    O(N)    |   √    |
| 快排（随机版本） | O(N*logN)  |  O(logN)   |   ×    |
| 堆排序           | O(N*logN)  |    O(1)    |   ×    |

1、基于比较的排序，无法做到时间复杂度比O(N*logN)还低。

2、基于比较的排序，无法做到时间复杂度O(N*logN)，空间复杂度比O(N)优，且稳定。

---

常见的坑：

1、归并排序的额外空间复杂度可以变成O(1)，但是非常难且会丧失稳定性，不需要掌握。-- "归并排序内部缓存法"

2、"原地归并排序"。。会让归并排序的时间复杂度变成O(N^2)。

3、快速排序可以做到稳定性问题，但是非常难不需要掌握，且会让空间复杂度变成O(N)。-- "01 stable sort"

4、所有的改进都不重要，因为目前还没找到时间复杂度O(N*logN)，额外空间复杂度O(1)，又稳定的排序。

5、有一道题目，是奇数放在数组左边，偶数放在数组右边，还要求原始的相对次序不变，碰到这个问题，可以怼面试官=。=

---

工程上对排序的改进：

- 1、充分利用O(N*logN)和O(N^2)排序各自的优势

比如：快排中间夹杂插入排序（如L > R - 60，则调用插入排序）。大样本量使用快排的调度方式，小样本量使用插入排序的小常数时间。-- 综合排序算法。

- 2、稳定性的考虑

编程语言API的排序算法夹杂了多种排序，若是内置类型比如int，则会调用快排。若是用户自定义类型，则会使用归并排序，保证数据排序后的稳定性。

## P3 认识复杂度和简单排序算法

### 1、常数操作

一个操作如果跟样本量没有关系，每次都是固定时间内完成的操作。     

### 2、**选择排序**

（每次将 i - n-1 位的最小值，放在第i位置，i=0,1,2,...）

- 访问操作：N + N - 1 + N - 2 + ...

- 比较操作：N + N - 1 + N - 2 + ...

- 交换操作：N

一共进行的常数操作数量 表达式：an^2 + bn + c。 => O(n^2)

```c++
// 选择排序：一次遍历后，将最小的元素放到最前
```

### 3、评价一个算法流程好坏

先看时间复杂度指标，（如果复杂度指标是一样的）然后再分析不同数据样本下的实际运行时间，也就是“常数项时间”。

### 4、**冒泡排序**

从i - n-1位遍历，相邻两个元素，小的在前，大的在后；遍历完一次后确定最后索引位置的元素（最大值）。

```c++
// 冒泡排序 (遍历0~n-1的元素，两两比较，一次遍历后将最大的元素放到最后)
```

### 5、异或运算

相同为0，不同为1，也可以理解成不进位的相加。定律：满足交换律和结合律；a ^ 0 = a； a ^ a  = 0.

a与b交换写法：（前提是a和b是两块独立的内存，比如数组下标相同的两个数，不能这样写）

> a = a ^ b;
>
> b = a ^ b;
>
> a = a ^ b;

考题：a. 某个数组中存在1个数出现次数为奇数次，其他均为偶数次。b. 某个数组中存在2个数出现次数为奇数次，其他均为偶数次。取a最右侧的1: a ^ (~a + 1)

### 6、**插入排序** 

从 i - n-1位遍历，保证0-i位有序，若i比i-1小则交换，再审视i-1位。时间复杂度按最坏情况估计。插入排序可能是O(n)，最差是O(n^2)

```c++
// 插入排序 (遍历0~i的元素，若i-1位置的元素>i位置元素，则交换，最小元素放到最前。一次遍历后保证0~i有序)
```

### 7、**二分法**的详解与扩展

- 1）在一个有序数组中，找某一个数是否存在

- 2）在一个有序数组中，找>=某个数最左侧的位置   int mid = L + ((R - L) >> 1) // 中点

- 3）局部最小值问题（无序，相邻数一定不相等） -- 不有序，也可以二分

### 8、**对数器**

用容易实现的方法b，来测试想要测的方法a。两个方法跑相同的随机样本，查看结果是否一致。

## P4 认识O(NlogN)的排序

### 1、递归行为和递归行为时间复杂度的估算

题目7. 用递归方法找一个数组中的最大值？（可以拆分一下递归图--视频讲解）

> **master公式**：T(N) = a * T(N/b) + O(N ^ d)  -- 子问题等规模的递归，可以用该公式求解时间复杂度。T(N)：母过程时间复杂度；a：子过程调用次数；T(N/b)：子过程时间复杂度；O(N ^ d)：除去子过程外其他过程时间复杂度。
>
> 1）log(b, a) > d  -> 复杂度为O(N ^ log(b, a))   b为底
>
> 2）log(b, a) == d -> 复杂度为O(N ^ d * log N)
>
> 3）log(b, a) < d -> 复杂度为O(N ^ d)

### 2、**归并排序**

- 1）整体就是一个简单递归，左边排好序、右边排好序、让其整体有序
- 2）让其整体有序的过程里用了排外序方法（排序的过程拷贝到外排序再拷贝回来）
- 3）利用master公式来求解时间复杂度
- 4）归并排序的实质   时间复杂度：O(N * log N)，额外空间复杂度O(N)       

### 3、**归并排序的扩展**

- 1）小和问题：一个数组中，每一个数左边比当前数小的数累加起来，叫做这个数组的小和。

  思路：换成当前数m右边有几个(n)比该数大，则小和+= m*n。可以深度改编归并排序实现，每次左右merge的时候求一次小和。

- 2）逆序对问题：在一个数组中，左边的数如果比右边的数大，则这两个数构成一个逆序对。

  思路：小和问题反过来。（右边小于左边）

### 4、荷兰国旗问题

- 1）问题1：给定一个数组arr和一个数num，把小于等于num的数放在数组的左边，大于num的数放在数组的右边。要求：额外空间复杂度O(1)，时间复杂度O(N)。

- 2）问题2：荷兰国旗问题--小于放左边，等于放中间，大于放右边。

### 5、快速排序

思路：

1、先从数组中取一个数作为基准数；2、分区过程，将大于基准数的数全放到它的右边，小于基准数的数全放到它的左边；3、再对左右区间重复第二步，直到各个区间只有一个数。

> - 1.0版本：取最后一个数为num，将数组分为两部分，<=num在左边，>num在右边，num与大于区域第一个数交换。该步骤重复左区域和右区域。
> - 2.0版本：取最后一个数为num，分小于num区域，等于num区域，大于num区域三个区域。（小于num）（等于num）（大于num）
> -  1.0和2.0版本时间复杂度都是O(N^2)。2.0版本比1.0版本相对更快，1次排序好一批数（等于num的），1.0版本一次只排序好一个数。
> - 3.0版本（**随机快速排序**）：随机取一个数作为num。可能导致最差情况，可能导致最好情况，基于概论计算，时间复杂度为O(N*logN)
>
> 分析：划分值越靠近两侧，复杂度越高；划分值越靠近中间，复杂度越低。
>
> 空间复杂度：最好O(logN)，最差O(N) -- **递归需要空间**

## P5 详解桶排序以及排序内容大总结

> - 堆结构就是用数组实现的完全二叉树结构
> - 完全二叉树中如果每颗子树的最大值都在顶部就是**大根堆**
> - 完全二叉树中如果每颗子树的最小值都在顶部就是**小根堆**
> - 堆结构的heapInsert与heapify操作
> - 堆结构的增大与减少
> - 优先级队列结构，就是堆结构

### 1、完全二叉树索引关系

一个数组从0出发可以用完全二叉树表示。

> **i位置代表当前元素的下标。左孩子：2i + 1；右孩子：2i + 2；当前元素的父：(i-1) / 2。**
>
> 第i层树可以容纳的元素个数：(i - 1) ^ 2。  

### 2、heapInsert

每次往数组里面放一个数，要构成大根堆。（从下往上）

> 1）如果这个数比父节点(i-1)/2值大，则两者交换。
>
> 2）直到不比父节点值大或到达0索引位置，循环结束。

### 3、heapify

从（大根堆）数组中取最大值（移除），再重构大根堆。（从上往下）

> 1）直接取头位置0号索引值返回；
>
> 2）将树的最后一个节点值拷贝到0位置，同时heapsize - 1。（heapsize是堆的大小）
>
> 3）从头节点0位置开始，与左孩子（2i+1）和右孩子（2i+2）PK。如果孩子中有比头节点大的最大值，则与父节点交换。
>
> 4）直到当前位置没有子节点，或者当前位置比所有子节点的值都大，循环结束。

【注】heapify也可以构建大根堆（从最后 一个元素开始）。时间复杂度：N/2 + N/4 * 2（查找1步+heapify的1步=2） + N/8 * 3 + N/16 * 4 + ... = Nlog(N)

### 4、堆排序

> 1）先heapInsert将数组构建成大根堆；
>
> 2）将0号索引元素（最大值）与最后元素交换，排好一个元素，heapSize-1；
>
> 3）执行heapIfy，重新构建大根堆；
>
> 4）循环2、3步骤，直到heapSize == 0；

### 5、堆排序扩展题目

已知一个几乎有序的数组，几乎有序是指，如果把数组排好顺序的话，每个元素移动的距离可以不超过k，并且k相对于数组来说比较小。请选择一个合适的排序算法针对这个数据进行排序。

解法：假设k=6，使用小根堆（找出k+1范围内最小值）。  复杂度：O(N*logK)

> 1）将前7个数（索引值0-6）构建成小根堆，则第0位数肯定是最小值。
>
> 2）将0位置数排除，将索引1-7的数构建成小根堆，则第1位数肯定是最小值。
>
> 3）依次类推，重复步骤2...

【注】系统提供的优先级队列（堆结构），如果想修改里面某个位置的值，可能手写的堆结构会更快。黑盒API虽然方便，但是不支持修改后高效恢复。

### 6、比较器的使用

> 1）比较器的实质就是重载比较运算符
>
> 2）比较器可以很好的应用在特殊标注的排序上
>
> 3）比较器可以很好的应用在根据特殊标准排序的结构上

### 7、桶排序

不基于比较的排序，需要基于数据的状况进行定制的排序。

#### **1）计数排序**

> 1）基于数据设置xx个桶；
>
> 2）遍历一遍数据，得到每个桶承载的数据频次；
>
> 3）基于桶的数据频次还原，即得到排序后的数据。

时间复杂度：O(N)。

#### **2）基数排序**

举例：[17, 13, 25, 100, 72]

解法过程：

> 1）基于最长的数位补齐各个数，得到[017，013，025，100，072]；
>
> 2）准备桶（可以是队列、数组、栈），本次使用队列；准备0，1，2，3，5，7号5个桶；
>
> 3）先基于个位数字，将每个数放到对应的桶；
>
> 4）将所有桶中的数字依顺序倒出来（先进先出）；
>
> 5）基于十位数字，将每个数放到对应的桶；
>
> 6）重复4步骤；
>
> 7）基于百位数字，...
>
> 最终得到13，17，25，72，100

相比计数排序更好，但要求数据是xx进制数。只要数据是十进制就准备10个桶，三进制准备3个桶。

**【具体实现过程简述】**

获取最大位数，最大有多少位则进出桶多少次--for循环次数。一次进出桶的过程如下：

- 1）申请桶，遍历生成count数组
- 2）将count处理成前缀和（重要！）count[i]代表<=i的数的频次
- 3）从右往左遍历arr，基于count前缀和数组进桶，刷新count
- 4）出桶

## P6 链表

### 1、排序算法的稳定性及其汇总

#### 1）排序算法稳定性定义

同样值的个体之间，如果不因为排序而改变相对次序，这个排序就是有稳定性的，否则没有。

#### 2）不具备稳定性的排序

选择排序、快速排序、堆排序。

#### 3）具备稳定性的排序

冒泡排序、插入排序、归并排序、一切桶排序思想下的排序。



希尔排序就是多轮的插入排序？

【注】目前没有找到时间复杂度O(N*logN)，额外空间复杂度O(1)，又稳定的排序。

