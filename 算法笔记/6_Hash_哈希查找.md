#### 哈希查找

##### 1.哈希表

​	哈希表又称散列表，是一种存储结构，通常用于存储多个元素。

​	和其它存储结构（线性表、树等）相比，哈希表查找目标元素的效率非常高。每个存储到哈希表中的元素，都配有一个唯一的标识（又称“索引”或者“键”），用户想查找哪个元素，凭借该元素对应的标识就可以直接找到它，无需遍历整个哈希表。

​	一般利用数组实现哈希表，可以直接将数组下标当做已存储元素的索引，不再需要为每个元素手动配置索引，极大简化了构建哈希表的难度。

##### 2.哈希函数

​	各个元素并不从数组的起始位置依次存储，它们的存储位置由专门设计的函数计算得出。使得到的哈希地址尽可能均匀地分布在n个连续内存单元地址上，同时使计算过程尽可能简单以达到尽可能高的时间效率。

​	**a. 直接定址法：**以关键字k的某个函数作为哈希地址的方法	

```
h(k) = ak + c
```

​	这种哈希函数计算简单，并且不可能有冲突发生。当关键字的分布基本连续时,可用直接定址法的哈希函数；否则,若关键字分布不连续将造成内存单元的大量浪费。

​	**b.数字分析法：**提取关键字中取值较均匀的数字位作为哈希地址的方法；适合于所有关键字值都已知的情况，并需要对关键字中每一位的取值分布情况进行分析。

```
arr = [92317602,92326875,92739628,92343634,92706816,92774638,92381262,92394220]
//分析发现每个关键字从左到右的第1、2、3位和第6位取值较集中，不宜作为哈希函数，剩余的第4、5、7和8位取值较分散
//取最后两位作为哈希地址
hash = [2,75,28,34,16,38,62,20]
```

​	**c.除留余数法：**用关键字k除以某个不大于哈希表长度m的数p所得的余数作为哈希地址的方法（最常用的哈希函数）

```
h(k)=k mod p  (mod为求余运算，p≤m ，p最好为素数)  
```

##### 3.哈希冲突

​	对于两个关键字ki和kj（i≠j），有ki≠kj（i≠j），但h(ki)=h(kj)。

​	**哈希冲突的解决办法：**

​	**a.开放定址法：**开放定址法是一类以发生冲突的哈希地址为自变量，通过某种哈希冲突函数得到一个新的空闲的哈希地址的方法。 

​		**1.线性探测法：**从发生冲突的地址（设为d）开始，依次探测d的下一个地址（当到达下标为m-1的哈希表表尾时，下一个探测的地址是表首地址0），直到找到一个空闲单元为止（当m≥n时一定能找到一个空闲单元）。

```
d[0]=h(k) 
d[i]=(d[i-1]+1) mod m  (1≤i≤m-1)
```

​		**2.平方探测法：**设发生冲突的地址为d，则平方探测法的探测序列为：d±1^2 ， d±2^2，…。

​	**b.拉链法：**拉链法是把所有的同义词用单链表链接起来的方法。

<img src="/Users/zyh/Library/Application Support/typora-user-images/image-20211016154251497.png" alt="image-20211016154251497" style="zoom:30%;" />

##### 4.代码实现

```c++
#include <stdio.h>
#define N 10   //指定哈希表的长度
//自定义哈希函数
int hash(int value) {
    return value % 10;
}
//创建哈希表
void creatHash(int arr[5], int hashArr[N]) {
    int i,index;
    //将序列中每个元素存储到哈希表
    for (i = 0; i < 5; i++) {
        index = hash(arr[i]);
        while(hashArr[index % N] != 0) {
            index++;
        }
        hashArr[index] = arr[i];
    }
}

//实现哈希查找算法，hashArr 表示哈希表，value 为要查找的目标元素
int hash_search(int* hashArr, int value) {
    int hashAdd = hash(value);             //查找目标元素所在的索引
    while (hashArr[hashAdd] != value) {    // 如果索引位置不是目标元素，则发生了碰撞
        hashAdd = (hashAdd + 1) % N;       // 根据线性探测法，从索引位置依次向后探测
        //如果探测位置为空，或者重新回到了探测开始的位置（即探测了一圈），则查找失败
        if (hashArr[hashAdd] == 0 || hashAdd == hash(value)) {
            return -1;
        }
    }
    //返回目标元素所在的数组下标
    return  hashAdd;
}

int main()
{  
    int hashAdd;
    int hashArr[N] = { 0 };
    int arr[5] = {  };
    creatHash(arr, hashArr);

    hashAdd = hash_search(hashArr, 50);
    //如果返回值为 -1，表明查找失败，反之则返回目标元素所在的位置
    if (hashAdd == -1) {
        printf("查找失败\n");
    }
    else {
        printf("查找成功，目标元素所在哈希表中的下标为：%d", hashAdd);
    }
    return 0;
}
```

##### 5.例题实现

###### 1.Crazy Search

**Input:**

​	The first line of input consists of two numbers, N and NC, separated by exactly one space. This is followed by the text where the search takes place. You may assume that the maximum number of substrings formed by the possible set of characters does not exceed 16 Millions.

```
1

3 4
daababac
```

**Outout:**

​	The program should output just an integer corresponding to the number of different substrings of size N found in the given text.The first line of a multiple input is an integer N, then a blank line followed by N input blocks. Each input block is in the format indicated in the problem description. There is a blank line between input blocks.

The output format consists of N output blocks. There is a blank line between output blocks.	

```
5
```

**Solve:**

​	1、创建hash表，用于存储出现过的子串，出现过则置为true

​	2、将字符串转换为数字进行存储，即用数值的和来代表子串

​	3、移动游标，依次遍历长度为N的子串将数值存储到hash表中

```c++
#include<iostream>
#include<string.h>
using namespace std;

/*
1 

3 4
daababac
 */

int n,nc,sum,tot,ans,m[257];
char s[1000000];
bool hashs[16000005];

int main(){
    int t;
    cin >> t;
    while(t--){
        cin >> n >> nc >> s;
        //将字符转成数字进行存储
        for(int i = 0 ; '\0' != s[i] ; i++){
            if(!m[s[i]])
                m[s[i]]=++tot;
            if(tot == nc) break;
        }
        int len = strlen(s);
        for(int i = 0 ; i <= len - n ; i++){
            sum = 0;
            //基于字符对应的值进行n位子串的数值相加
            for(int j = 0 ; j < n ; j++){
                sum = sum * nc + m[s[i+j]] - 1;
            }
            //数值不存在则子串数++
            if(!hashs[sum])
                hashs[sum] = true , ans++;
        }
        cout << ans;
    }
    return 0;
}
```

