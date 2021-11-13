#### 并查集(union_find)

##### 1.概念_实现思想

​	并查集是一种树型的数据结构，用于处理一些不相交集合（Disjoint Sets）的合并及查询问题。常常在使用中以森林来表示。集就是让每个元素构成一个单元素的集合，也就是按一定顺序将属于同一组的元素所在的集合合并。

​		Find：确定元素属于哪一个子集。它可以被用来确定两个元素是否属于同一子集合

​		union：将两个子集合并成一个集合		

##### 2.经典例题解析

###### a.通畅工程

**Problem Description**：某省调查城镇交通状况，得到现有城镇道路统计表，表中列出了每条道路直接连通的城镇。省政府“畅通工程”的目标是使全省任何两个城镇间都可以实现交通（但不一定有直接的道路相连，只要互相间接通过道路可达即可）。问最少还需要建设多少条道路？

**Input**：测试输入包含若干测试用例。每个测试用例的第1行给出两个正整数，分别是城镇数目N ( < 1000 )和道路数目M；随后的M行对应M条道路，每行给出一对正整数，分别是该条道路直接连通的两个城镇的编号。当N为0时，输入结束，该用例不被处理。

**Output**：对每个测试用例，在1行里输出最少还需要建设的道路数目。 

```
4 2
1 3
4 3
3 3
1 2
1 3
2 3
5 2
1 2
3 5
999 0
0
```

```c++
#include <iostream>

//算法思想：创建存储数组，初始化数组，若该城市的与另一城市有道路相连，则将该两者index位(城市)的标志号(info[index])设为一致，

using namespace std;

//存储城市信息数组，index代表城市编号，从1开始遍历
//info[index]代表该城市的当前标志号(属于哪一个城市群，连通后的城市标志为一个城市群，且标志号相同)
int info[1010];

//n为城市个数，N为道路个数
int M,N;

//初始化数组，即每一个城市都是自己独立的城市群
void init(){
    for(int i=1;i<=N;i++)
        info[i]=i;
}

//给定一个城市，查询其隶属于哪一个城市群，即查询其根节点(一个城市群的标志号由根节点决定)
int FindRoot(int city){
    int root = city;
    //找到该城市最终的root
    while(info[root]!=root) //当前的城市不是根城市，继续向上找
        root=info[root];
  
  	//优化路径，将info的值全部设置为根节点，简化树的层数，便于查询
  	int i = city, box;
  	while(i != root){
      	box = info[i];//暂存i的上级节点
      	info[i] = root;//将当前节点的info改为root
      	i = box;//将i设置为原i存储的上一节点(目的为继续循环，更新全部的节点info)
    }
    return root;
}
//添加路径，若两城市的隶属的城市群(info[index])不同，则变为相同
void Union(int x,int y){
    int rootx=FindRoot(x);
    int rooty=FindRoot(y);
    if(rootx!=rooty)
        info[rootx]=rooty;
}

int main(){
    cin>>N;
    while(N != 0 ){
        init();

        for(cin>>M ; M>0 ; M--){
            int x,y;
            cin>> x >> y ;
            Union(x,y);
        }
        
        int count=0;
        for(int i=1;i<=N;i++)
            if(info[i]==i)
                ++count;
        cout << count-1 <<endl;
        cin >> N;
    }

}
```

***关于C++的输入输出**

```
#include<iostream>

using namespace std;

int main(){
		string str = "CPP";
		
		cout << "hello " << str;
}
```

###### b.maze

**Problem description:**上次Gardon的迷宫城堡小希玩了很久，现在她也想设计一个迷宫让Gardon来走。但是她设计迷宫的思路不一样，首先她认为所有的通道都应该是双向连通的，就是说如果有一个通道连通了房间A和B，那么既可以通过它从房间A走到房间B，也可以通过它从房间B走到房间A，为了提高难度，小希希望任意两个房间有且仅有一条路径可以相通（除非走了回头路）。小希现在把她的设计图给你，让你帮忙判断她的设计图是否符合她的设计思路。比如下面的例子，前两个是符合条件的，但是最后一个却有两种方法从5到达8。

<img src="/Users/zyh/Library/Application Support/typora-user-images/image-20210915090438080.png" alt="image-20210915090438080" style="zoom:50%;" />

**Input:**输入包含多组数据，每组数据是一个以0 0结尾的整数对列表，表示了一条通道连接的两个房间的编号。房间的编号至少为1，且不超过100000。每两组数据之间有一个空行。
整个文件以两个-1结尾。

```
6 8  5 3  5 2  6 4 5 6  0 0

8 1 7 3  6 2  8 9  7 5 7 4  7 8  7 6  0 0

3 8  6 8  6 4 5 3  5 6  5 2  0 0

-1 -1
```

**Output:**对于输入的每一组数据，输出仅包括一行。如果该迷宫符合小希的思路，那么输出"Yes"，否则输出"No"

**实现思想：并查集**

​		有且仅有一条通路即可以有两种情况分析该题

​				全部节点为一个连通分量，即为一个子集；连通分量中不存在环。

**实现：**

```c++
#include<iostream>
#include<cstring>
using namespace std;

int x,y ;//当前并入子集的两个节点
int f[100010];//记录节点上级数组
//因为数组不是按顺序排列的，需要用一个数组来存储已访问的节点
int vis[100010];//访问数组，用于判定最后有几个连通分量，

//查询根节点
int findRoot(int x)
{
    if(f[x] == x){
        return x;
    }
    return f[x] = findRoot(f[x]);
}
//合并两个子集
void Union(int u,int v)
{
    int t1=findRoot(u);
    int t2=findRoot(v);
    if(t1!=t2)
        f[t2]=t1;
}
void Init()
{
    memset(vis,0,sizeof(vis));//将vis数组全部赋值为0
    for(int i=1; i<=100000; i++)
        f[i]=i;
}
int main()
{
    //最外层循环，用于程序-1退出以及只有00的情况
    while(cin>>x>>y)
    {
        if(x+y==-2)
            break;
        if(x+y==0)//若当前行输入只有0 0 ，也判定为yes
        {
            cout<<"Yes"<<endl;
            continue;
        }
        Init();
        vis[x]=vis[y]=1;
        int flag=1; //标志位flag=1代表yes无环；flag=0代表no有环
        Union(x,y);
        while(cin>>x>>y)//对于后续数据进行循环，从第二个数据开始
        {
            if(x+y==0)
                break;
            if(findRoot(x)==findRoot(y)) //并入子集时发现根节点相同，则证明有环，标志位改为0
                flag=0;
            else
            {
                Union(x,y);
                vis[x]=vis[y]=1;//记录已访问的节点，用于判断连通分量
            }
        }
        int sum=0;
        for(int i=1; i<=100000; i++)
        {
            if(vis[i])
            {
                if(f[i]==i)//本身为根节点的即自成一个连通分量，即为一个子集
                    sum++;
            }
        }
        if(sum!=1)//若有两个连通分量，不满足迷宫要求(有且仅有一条通路可以相通)
            flag=0;
        if(flag==0)
            cout<<"No"<<endl;
        else
            cout<<"Yes"<<endl;
    }
    return 0;
}

```

***对于输入格式为下述情况的，程序输入结构设计**

```C++
6 8  5 3  5 2  6 4 5 6  0 0

8 1 7 3  6 2  8 9  7 5 7 4  7 8  7 6  0 0

3 8  6 8  6 4 5 3  5 6  5 2  0 0

-1 -1
```

​		**多组数据进行输入时，需要先判断程序退出的条件，即判断x, y = -1,-1; 后进行每一组数据的输入，以条件 x, y = 0,0 作为该组数据的结束输入**

```c++
//第一次循环接受第一对数据，用于判断是否为程序退出条件
while(cin >> x >> y){
		//判断程序退出条件
		if(x+y = -2){
				break;
		}
  	if(x+y==0)//若当前行输入只有0 0 ,一定要根据需求判断这种情况
        {
            //代码块
            continue;
        }
        {
          //代码块,执行程序逻辑
        }
  	//若程序未退出则进行后面数据的输入(接收的数据从第二对数据开始)
  	while(cin >> x >> y){
      	if(x+y = 0){
          break;
        }
      	{
          //代码块,执行程序逻辑
        }
    }
}
```

​	***在程序需要根据条件输出多种结果时，利用flag标志位进行绑定条件，最后统一输出；在程序中尽量不要多用break、continue、goto语句，会使程序的逻辑很混乱**

###### c.最小生成树+并查集

**Problem Description：**
某省调查乡村交通状况，得到的统计表中列出了任意两村庄间的距离。省政府“畅通工程”的目标是使全省任何两个村庄间都可以实现公路交通（但不一定有直接的公路相连，只要能间接通过公路可达即可），并要求铺设的公路总长度为最小。请计算最小的公路总长度。

**Input**：
测试输入包含若干测试用例。每个测试用例的第1行给出村庄数目N ( < 100 )；随后的N(N-1)/2行对应村庄间的距离，每行给出一对正整数，分别是两个村庄的编号，以及此两村庄间的距离。为简单起见，村庄从1到N编号。
当N为0时，输入结束，该用例不被处理。

```
3
1 2 1
1 3 2
2 3 4
4
1 2 1
1 3 4
1 4 1
2 3 3
2 4 2
3 4 5
0
```

**output：**

对每个测试用例，在1行里输出最小的公路总长度

```
3
5
```

**实现**：

```c++
#include <iostream>
#include <algorithm>

using namespace std;

//实现思想：利用最小生成树-dijkstra + 并查集思想
//首先将相连的节点以及距离信息存入结构体数组，后定义排序规则对结构体数组进行距离的由小到大排序，后进行合并子集，并增加距离，若新加入的节点已经在子集中(即连成了环)则无需增加距离，继续遍历，直到遍历全部数据。

const int Max_par = 110;
//声明存储上级节点数组
int parent[Max_par];

//声明结构体存储输入的数据，即城市1、城市2、两者距离
typedef struct {
    int c1;
    int c2;
    int dis;
}Info;

Info info[5050];

void initArr(){
    for(int i = 1 ; i < Max_par ; i++ ){
        parent[i] = i;
    }
}

int findRoot(int x){
    if(x == parent[x])
        return x;
    return findRoot(parent[x]);
}

//定义排序方式
bool compare(Info info1 , Info info2){
    return info1.dis < info2.dis;
};

int main(){
    int N , line;
    while(cin >> N){
        if(N == 0){
            break;
        }
        int c1 , c2;
        int sum = 0;
        line = N * (N - 1) /2;
        initArr();
        for(int i = 1 ; i <= line ; i++ ){
            cin >> info[i].c1 >> info[i].c2 >> info[i].dis;
        }
        //将info数组按照distance进行从小到大排序
        sort(info+1 , info+1+line , compare);
        for(int i = 1 ; i < line ; i++){
            c1 = findRoot(info[i].c1);
            c2 = findRoot(info[i].c2);
            if(c1 == c2){//已经成环，不需要加总数，继续遍历下一组数据
                continue;
            }
            parent[c2] = c1;
            sum += info[i].dis;
        }
        cout << sum << endl;
    }

    return 0;
}
```

