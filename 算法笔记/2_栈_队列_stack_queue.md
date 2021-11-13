#### 栈_队列(stack_queue)

##### 1.定义、思想、c++STL

​	**栈：**先进后出(FILO)，删除元素均在栈顶操作

```c++
#include<stack>
//声明一个栈,数据类型可以为任意数据结构
stack<int> a;
//栈操作
a.empty()  //如果栈为空返回true，否则返回false  
a.size()   //返回栈中元素的个数  
a.pop()    //删除栈顶元素但不返回其值  
s.top()    //返回栈顶的元素，但不删除该元素  
s.push()   //在栈顶压入新元素  
```

​	**队列：**先进先出(FIFO)，在队头出队，在队尾入队

​	一般题目给出需要按照优先级输出可以使用队列

```c++
#include<queue>
//声明一个队列，数据类型可以为任意数据类型
queue<int> q;
//队列操作
q.empty()  //如果队列为空返回true，否则返回false  
q.size()   //返回队列中元素的个数  
q.pop()    //删除队列首元素但不返回其值  
q.front()  //返回队首元素的值，但不删除该元素  
q.push()   //在队尾压入新元素  
q.back()   //返回队列尾元素的值，但不删除该元素  
```

​	**优先队列：**priority_queue

```c++
#include<queue>

//priority_queue<Type, Container, Functional>
//Type 就是数据类型，Container 就是容器类型（Container必须是用数组实现的容器，比如vector,deque等等，但不能用 list。STL里面默认用的是vector），Functional 就是比较的方式
//默认优先队列为大顶堆
//input:0 1 2 3 4
//output:4 3 2 1 0
priority_queue<int> pq;
//等价于 
priority_queue<int, vector<int>, less<int> > pq;
//小顶堆
priority_queue<int, vector<int>, greater<int> > c;  

//对于自定义类型(struct)
struct tmp //运算符重载<
{
    int x,y;
    friend bool operator < (tmp a , tmp b){
      	//依据规则执行优先级规则
      	if(a.x != b.x){
          	rerturn a.x > b.x;
        }
      	if(a.y != b.y){
          	rerturn a.y > b.y;
        }
    }
};
```

##### 	2.经典例题解析：

###### a.Message queue

**problem description:**Message queue is the basic fundamental of windows system. For each process, the system maintains a message queue. If something happens to this process, such as mouse click, text change, the system will add a message to the queue. Meanwhile, the process will do a loop for getting message from the queue according to the priority value if it is not empty. **Note that the less priority value means the higher priority.** In this problem, you are asked to simulate the message queue for putting messages to and getting message from the message queue.

**Input:**There's only one test case in the input. Each line is a command, "GET" or "PUT", which means getting message or putting message. If the command is "PUT", there're one string means the message name and two integer means the parameter and priority followed by. There will be at most 60000 command. Note that one message can appear twice or more and if two messages have the same priority, the one comes first will be processed first.(i.e., FIFO for the same priority.) Process to the end-of-file.

```
GET
PUT msg1 10 5
PUT msg2 10 4
GET
GET
GET
```

**Output:**For each "GET" command, output the command getting from the message queue with the name and parameter in one line. If there's no message in the queue, output "EMPTY QUEUE!". There's no output for "PUT" command.

```
EMPTY QUEUE!
msg2 10
msg1 10
EMPTY QUEUE!
```

实现：

```c++
#include <iostream>
#include <queue>
#include <string.h>

//实现思路：创建结构体，接受指令集的信息，利用优先队列，对优先队列的优先级进行重载，基于题中信息进行比对出队入队即可
//难点：自定义类型的重载运算符，实现按需求优先级的排列
using namespace std;

//定义结构体存储指令信息
struct vInfo{
    char info[10];
    int value,pre,id;
    //重载运算符，重新执行优先级规则，即有限级
    friend bool operator < (vInfo a, vInfo b) {
        if(a.pre != b.pre){
            //a优先数大则向后排
            return a.pre > b.pre;
        }else{
            //a序号大则向后排
            return a.id > b.id;
        }
    }
};
//定义优先队列，优先队列中的优先级规则在重载中已定义
priority_queue<vInfo> pQue;

int main() {
    char opt[10];
    vInfo vinfo;
    int id = 0;//当前输入指令的序号
    while(cin >> opt){
        if(strcmp(opt , "PUT") == 0){
            id++;
            cin >> vinfo.info >> vinfo.value >> vinfo.pre;
            vinfo.id = id;
            pQue.push(vinfo);
        }else{
            if(pQue.empty()){
                cout << "EMPTY QUEUE!" << endl;
            }else{
                cout << pQue.top().info << " " << pQue.top().value << endl;
                pQue.pop();
            }
        }
    }
    return 0;
}

```

###### b.rails

**背景简介：**

<img src="/Users/zyh/Library/Application Support/typora-user-images/image-20210919221905682.png" alt="image-20210919221905682" style="zoom:40%;" />

**input：**

```
5
1 2 3 4 5
5 4 1 2 3
0
6
6 5 4 3 2 1
0
0
```

**output：**

```
Yes
No

Yes
```

**实现**：

```c++
#include<iostream>
#include<stack>

//算法思想：
//数据结构：用栈作为暂存数据栈，用于比对数组中的车序号;用数组存储已到站的车次顺序
//创建一个游标用于遍历数组，一个自增变量c代表当前遍历的车序号
//从1号车(c=1)开始遍历数组，若比对上，则数组的游标后移，车次号加一；若数组当前遍历到数组的位置与栈顶元素相等，则出栈，游标下移；若比对不成功，则将当前车次push入栈，车序号+1；若上述情况未将栈清空，则证明顺序错误
using namespace std;

//已经到站的车次顺序
int ordered[1000];
stack<int> s;

int main()
{
    int n;
    cin >> n ;
  	
  	//进行大循环的判断，不为零则进行整组数据的输入
    while(n != 0){
        int m ;
        cin >> m;
      	
      	//本组循环是否结束的判断
      	//上面的m已经读入了一个字符，则下面读该组剩下的数据
        while(m != 0){
            //c为车序号，j遍历数组游标
            int c = 1, j = 1;
          	//将提前读入的字符赋值
            ordered[1] = m;
          	//遍历剩余的数据
            for(int i = 2;i <= n ; i++){
                cin >> ordered[i];
            }
            int flag = 1;
            while(j <= n)
            {
                //若匹配，则继续遍历下一个位置
                if(c == ordered[j]){
                    c++;
                    j++;
                //若栈内不为空，并且栈顶元素与数组当前遍历位置相等则出栈，继续数组游标后移
                }else if(!s.empty() && s.top() == ordered[j]){
                    s.pop();
                    j++;
                //没有匹配，则将i号车push入栈
                }else if(c <= n){
                    s.push(c);
                    c++;
                }else{
                    flag = 0;
                    break;
                }
            }
            if(flag == 1){
                cout << "Yes" << endl;
            }else{
                cout << "No" << endl;
            }
            cin >> m;
        }
        cin >> n;
        cout << endl;
    }
    return 0;
}

```

###### c.calculator

**题目描述：**

读入一个只包含 +, -, *, / 的非负整数计算表达式，计算该表达式的值。

**input：**

```
1 + 2
4 + 2 * 5 - 7 / 11
0
```

**output：**

```
3.00
13.36
```

**实现：**

```c++
# include <iostream>
# include <string.h>
# include <stdio.h>
# include <stack>
# include <stdlib.h>

using namespace std;
/*
 * 算法思路：
 *      1、读取一行字符串，去除空格后遍历该字符串数组，
 *          若遇到数字则将其暂存到数组中；
 *          若遇到符号，则将数组中暂存的数字进行操作(+ 直接压入、- 压入负数 、 * 将暂存数字与栈顶元素相乘后压入、/ 将暂存数字						与栈顶元素相乘后压入)；
 * */

int main()
{
    char str[210],num[210];
    char sym[4]={'*','/','+','-'};
    int len;
    stack<double> cal;
    //cin.getline允许读取包含空格的字符串
    while(cin.getline(str,210))
    {
        len = strlen(str);
        if(len==1&&str[0]=='0') break;
        int flag=2,count=-1;
        for(int i=0;i<len;i++)
        {
            int flag2=0;//帮助判断是否是数字并存入num
            //题目中整数和运算符用空格分隔，去掉空格
            if(str[i]==' ') continue;
            //存储数字
            if(str[i]>='0'&&str[i]<='9')
            {
                count++;
                num[count]=str[i];
                flag2=1;
            }
            //不是数字或遍历到最后一个字符
            if(flag2==0||i==len-1)
            {
                num[count+1]='\0';
                //读取当前输入数字，可能为二位数
                double n = atoi(num);
                count=-1;
                if(flag==0) //乘法 相乘后放入栈
                {
                    double m=cal.top();
                    n*=m;
                    cal.pop();
                    cal.push(n);
                }
                else if(flag==1) //除法  相除后放入栈
                {
                    double m=cal.top();
                    n = m/n;
                    cal.pop();
                    cal.push(n);
                }
                else if(flag==3) //减法 存为负数放入栈
                {
                    cal.push(-n);
                }
                else if(flag==2) //加法  直接放入栈
                {
                    cal.push(n);
                }
                //判断算数符号
                for(int j = 0 ; j < 4 ; j++)
                {
                    if(str[i]==sym[j]) flag=j;
                }
            }
        }
        double countSum=0;
        while(cal.empty()!=1)//栈内剩余数相加
        {
            countSum+=cal.top();
            cal.pop();
        }
        printf("%.2lf\n",countSum);

    }
    return 0;
}
```

