#### 图论

参考：https://blog.csdn.net/u011815404/article/details/80313879

##### 1.理论基础

**定义：**由顶点的有穷非空集合和顶点之间边的集合组成，通常表示为：G=(V,E)，其中 V 是非空有限集合， 代表顶点，E 是可以为空的有限集合，代表边。

若顶点 vi 和 vj 间的边没有方向，则称这条边为**无向边**，用无序偶对 (vi,vj) 表示；

若顶点 vi 和 vj 间的边有方向，则称这条边为**有向边（弧）**，用有序偶对 <vi,vj> 表示，其中 vi 称为**弧头**，vj 称为**弧尾**。

若图的任意两个顶点之间的边都是无向边，则称该图为**无向图**；若图的任意两个顶点之间的边都是有向边，则称该图为**有向图**。

<img src="/Users/zyh/Library/Application Support/typora-user-images/image-20211020150111693.png" alt="image-20211020150111693" style="zoom:50%;" />

##### 2.基本术语

**简单图：**在一个图中，不存在顶点到其自身的边，且同一条边不重复出现

**临接点：**

- 在一个无向图中，对于任意两个顶点 vi 和顶点 vj，若存在边 (vi,vj)，则称**顶点 vi 和顶点 vj 互为邻接点**，同时称边 (vi,vj) 依附于顶点 vi 和顶点 vj
- 在一个有向图中，对于任意两个顶点 vi 和顶点 vj，若存在弧 <vi,vj>，则称**顶点 vi 邻接到顶点 vj，顶点 vj 邻接自顶点 vi**，同时称弧 <vi,vj> 依附于顶点 vi 和顶点 vj

**完全图：**

- 在一个无向图中，如果任意两个顶点之间都存在边，则称该图为**无向完全图**，其有 n*(n-1)/2 条边
- 在一个有向图中，如果任意两个顶点之间都存在方向相反的两条弧，则称该图为**有向完全图**，其有 n*(n-1) 条边

**稀疏图/稠密图**：

- 一个边数接近完全图的图称为**稠密图**，一个边数远远少于完全图的图称为**稀疏图**

**度：**

- 在无向图中，依附于顶点 v 的边数称为**顶点的度**，记为 TD(v)，在 n 个顶点 m 条边的无向图中，所有点的度的和为 2m
- 在有向图中：
  - 以顶点 v 为弧头的弧的数目称为**顶点的入度**，记为 ID(v)，在 n 个顶点 m 条边的有向图中，所有点的入度和为 m
  - 以顶点 v 为弧尾的弧的数目称为**顶点的出度**，记为 OD(v)，在 n 个顶点 m 条边的有向图中，所有点的出度和为 m

**权、网、有向网图、无向网图：**

​	对边赋予的有意义的数值量称为**权（权值）**，边上带权的图，称为**网（带权图）**，根据图是无向图或有向图，分为**有向网图**、**无向网图**

**路径：**

- 在无向图 G=(V,E) 中，对于一个满足 ![(v_{ij-1},v_{ij})\in E(1\leqslant j\leqslant m)](https://private.codecogs.com/gif.latex?%28v_%7Bij-1%7D%2Cv_%7Bij%7D%29%5Cin%20E%281%5Cleqslant%20j%5Cleqslant%20m%29) 的顶点序列 ![\{v_p=v_{i_0},v_{i_1},v_{i_2},..., v_{i_m}=v_q\}](https://private.codecogs.com/gif.latex?%5C%7Bv_p%3Dv_%7Bi_0%7D%2Cv_%7Bi_1%7D%2Cv_%7Bi_2%7D%2C...%2C%20v_%7Bi_m%7D%3Dv_q%5C%7D)，称为**从顶点 vp 到顶点 vq 之间的路径**，若 G 是有向图，则 G 的路径是有方向的
- 在路径序列中，起点和终点相同的路径称为**回路（环）**
- 在路径序列中，顶点不重复出现的路径称为**简单路径**
- 在路径序列中，除起点终点外，其余顶点不重复出现的回路称为**简单回路**

- 对于一个非带权图，路径上边的个数称为**路径长度**，对于一个带权图，路径上各边权的和称为**路径长度**

**连通图：**

- 在无向图中，如果从一个顶点 vi 到另一个顶点 vj(i≠j) 有路径，则称**顶点 vi 和 vj 是连通的**，如果图中任意两个顶点都是连通的，则称该图是**连通图**
- 非连通图的极大连通子图称为**连通分量**，其中，**极大**是指包括所有连通的顶点及这些顶点相关联的所有边

- 在有向图中，对图中任意一对顶点 vi 和 vj(i≠j)，若从顶点 vi 到顶点 vj 和从顶点 vj 到顶点 vi 均有路径，则称该有向图是**强连通图**，非强连通图的极大强连通子图称为**强连通分量**

  下图绿框内为强连通分量

<img src="/Users/zyh/Library/Application Support/typora-user-images/image-20211020205435041.png" alt="image-20211020205435041" style="zoom:40%;" />

**子图：**

- 对于图 G=(V,E) 和 G'=(V',E')，若 ![V'\subseteq V,E'\subseteq E](https://private.codecogs.com/gif.latex?V%27%5Csubseteq%20V%2CE%27%5Csubseteq%20E)，则称 G' 为 G 的**子图**，一个图可以有多个子图

##### 3.图的存储结构

###### a.邻接矩阵

​	图的邻接矩阵存储也称数组表示法，其方法是用一个一维数组存储图中的顶点，用一个二维数组存储图中的所有的边，存储顶点之间邻接关系的二维数组称为**邻接矩阵**。

​	设图 G=(V,E) 具有 n 个顶点，则其邻接矩阵是一个 n*n 的方阵，定义为：

![G[i][j]=\left\{\begin{matrix}1,(v_i,v_j)\in E\:\:or\:\:<v_i,v_j>\in E \\ 0, (v_i,v_j)\notin E\:\:and\:\:<v_i,v_j>\notin E \end{matrix}\right.](https://private.codecogs.com/gif.latex?G%5Bi%5D%5Bj%5D%3D%5Cleft%5C%7B%5Cbegin%7Bmatrix%7D1%2C%28v_i%2Cv_j%29%5Cin%20E%5C%3A%5C%3Aor%5C%3A%5C%3A%3Cv_i%2Cv_j%3E%5Cin%20E%20%5C%5C%200%2C%20%28v_i%2Cv_j%29%5Cnotin%20E%5C%3A%5C%3Aand%5C%3A%5C%3A%3Cv_i%2Cv_j%3E%5Cnotin%20E%20%5Cend%7Bmatrix%7D%5Cright.)

若 G 是网图，则有：

![G[i][j]=\left\{\begin{matrix}w_{ij},(v_i,v_j)\in E\:\:or\:\:<v_i,v_j>\in E \\ INF , (v_i,v_j)\notin E\:\:and\:\:<v_i,v_j>\notin E \end{matrix}\right.](https://private.codecogs.com/gif.latex?G%5Bi%5D%5Bj%5D%3D%5Cleft%5C%7B%5Cbegin%7Bmatrix%7Dw_%7Bij%7D%2C%28v_i%2Cv_j%29%5Cin%20E%5C%3A%5C%3Aor%5C%3A%5C%3A%3Cv_i%2Cv_j%3E%5Cin%20E%20%5C%5C%20INF%20%2C%20%28v_i%2Cv_j%29%5Cnotin%20E%5C%3A%5C%3Aand%5C%3A%5C%3A%3Cv_i%2Cv_j%3E%5Cnotin%20E%20%5Cend%7Bmatrix%7D%5Cright.)

​	其中 ![w_{ij}](https://private.codecogs.com/gif.latex?w_%7Bij%7D) 是边 (vi,vj) 或 弧 <vi,vj> 上的权值，INF 代表一极大的数，其大于所有边的权值。

<img src="/Users/zyh/Library/Application Support/typora-user-images/image-20211020212000665.png" alt="image-20211020212000665" style="zoom:33%;" />

​	其对确定边操作效率高，但由于其过高的空间复杂度，对稀疏图来说造成了极大的浪费，且由于二维数组可开的空间范围有限，因此邻接矩阵一般适用于**点较少的图**。

```c++
int n;
int G[N][N];
void init(){
    memset(G,0,sizeof(G));//图的初始化
    cin>>n;//读入数据个数
    while(n--){
        cin>>i>>j>>w;//读入两个顶点序号及权值
        G[i][j]=w;//对于不带权的图，可令g[i][j]=1
        G[j][i]=w;//无向图的对称性，若是有向图，没有此句
    }
}
```

###### b.邻接表

​	邻接表是一种顺序存储与链接存储相结合的存储方法，类似于树的孩子链表表示法。

​	对于图 G 的每个顶点 vi，将所有邻接于 vi 的顶点链成一个单链表，称为 vi 的**边表**，若图 G 是一有向图，则称为 vi 的**出边表**。

​	为方便对所有边表的头指针进行存储操作，使用顺序存储，这样，存储边表头指针的数组和存储顶点信息的数组构成了邻接表的表头数组，称为**顶点表**。 

<img src="/Users/zyh/Library/Application Support/typora-user-images/image-20211020213259521.png" alt="image-20211020213259521" style="zoom:40%;" />

​	相较于邻接矩阵，其由数组转链表，由定长转不定长，内存利用率高，能较好的处理稀疏图，对不确定的边操作较为方便，但由于存储方式的问题，其对重边不好处理，且对确定边处理效率并不高。

```c++
struct Edge{//边表
    int pos;//位置域，存放该顶点的邻接点在顶点表中的下标
    int dis;//数据域，对于网图，增设一存取边上信息的域
    Edge *next;//指针域，指向边表中下一结点
};
struct Node{//顶点表
    int pos;//位置域，存放顶点信息
    Edge *firstEdge;//指针域，指向边表中的第一个结点
}node[N];
int n,m;
void init(){
    for(int i=0;i<n;i++){//n个点
        cin>>node[i].pos;
        node[i].firstEdge=NULL;
    }
    for(int i=0;i<m;i++){//m条边
        int x,y;
        cin>>x>>y;//边所依附的两点编号
        Edge *p;//边表结点
        //添边x->y
        p->pos=y;
        p->next=node[x].firstEdge;
        node[x].firstEdge=p;
        //添边y->x
        p->pos=x;
        p->next=node[y].firstEdge;
        node[y].firstEdge=p;
    }
}
```

###### c.前向星

​	对于邻接矩阵来说，其方便但效率低，对于邻接表来说，其虽效率较高但实现较为困难，而前向星就是一个介于两者之间的较为中庸的结构，其虽然好写，但效率较邻接表来说较低，且其不能直接用顶点进行定位，对重边不好处理，只能与邻接表一样遍历判重。

​	前向星以储存边的方式来存储图，其通过读入每条边的信息，将边存放在数组中，把数组中的边按照起点顺序排序进行构造。

​	常用于具有多个点或两点间具有多条弧的情况，其缺点是不能直接用顶点进行定位。

```c++
int n,m;
vector<int> edge[N];
void init(){
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int x,y;
        cin>>x>>y;//边所依附的两点编号
        edge[x].push_back(y);//添边x->y
        edge[y].push_back(x);//添边y->x
    }
}
```

###### d.链式前向星

###### e.十字链表

###### f.邻接多重表

##### 4.图的遍历

###### a.概述

​	根据搜索方法的不同，分为深度优先遍历（DFS）、广度优先遍历（BFS），两者时间复杂度都是 O(N*N)，通常采用深度优先遍历。	

###### b.深度优先遍历

**深度优先遍历的基本过程：**

​	1.从图中某个顶点 v0 出发，首先访问 v0

​	2.访问结点 v0 的第一个邻接点，以这个邻接点 vt 作为一个新节点，访问 vt 所有邻接点，直到以 vt 出发的所有节点都被访问
​	3.回溯到 v0 的下一个未被访问过的邻接点，以这个邻结点为新节点，重复步骤 2，直到图中所有与 v0 相通的所有节点都被访问
​	4.若此时图中仍有未被访问的结点，则另选图中的一个未被访问的顶点作为起始点，重复步骤 1，直到图中的所有节点均被访问

<img src="/Users/zyh/Library/Application Support/typora-user-images/image-20211021091728169.png" alt="image-20211021091728169" style="zoom:50%;" />

​	例如上图深度优先遍历的次序为：ABCFEGDHI

**深度优先遍历框架**

```c++
bool vis[N];
void dfs(int i) {
    for(所有i的邻接点j) {
        if(!vis[j]) {
            if(j == 目标状态)
                return true;
            vis[j]=true;
            dfs(j);
        }
    }
}
```

###### 经典例题

**Input**

```
so
soon
river
goes
them
got
moon
begin
big
0
```

**output:如果存在b -> m的路径，则输出yes，例如book，kept，them（单词间可以传递）**

```
Yes
```

**思路：DFS以b开头的单词的结尾字符，直到遍历的单词末尾为m**

```c++
#include <iostream>
#include <string.h>

using namespace std;

/*
so
soon
river
goes
them
got
moon
begin
big
0
 */
string str[110];
int t = 0;
int vis[110];
int flag = 0;

void dfs(char findStr){
    if(findStr == 'm'){
        flag = 1;
    }else{
        for(int i = 0 ; i < t-1 ; i++){
            if(str[i][0] == findStr && vis[i] == 0){
                vis[i] = 1;
                dfs(str[i][str[i].length()-1]);
            }
        }
    }
}

int main(){
    while(cin >> str[t++]){
        memset(vis , 0 , sizeof(vis));
        if(str[t-1][0] == '0'){
            dfs('b');
            if(flag){
                cout << "Yes" << endl;
            }else{
                cout << "No" << endl;
            }
        }
    }
}
```

###### c.广度优先遍历

**广度优先遍历的基本过程：**

1. 从图中某个顶点 v0 出发，首先访问 v0，将 v0 加入队列
2. 将队首元素的未被访问过的邻接点加入队列，访问队首元素并将队首元素出队，直到队列为空
3. 若此时图中仍有未被访问的结点，则另选图中的一个未被访问的顶点作为起始点，重复步骤 1，直到图中的所有节点均被访问过。

<img src="/Users/zyh/Library/Application Support/typora-user-images/image-20211021092411326.png" alt="image-20211021092411326" style="zoom:50%;" />

​	上图优先遍历的次序为：ABDECGFHI

**广度优先遍历框架**

```c++
bool vis[N];
void BFS(int start) {
    queue<int> Q;
    Q.push(start);
    vis[s]=true;
    while(!Q.empty()) {
        int x=Q.front();
        Q.pop();
        if(x==目标状态) {
            ...
        }
        for(所有i的邻接点j) {
            if(!vis[j]) {
                Q.push(j);
                vis[j]=true;
            }
        }
    }
}
```

###### d.奇偶剪枝

对于给出的字符矩阵，在搜索过程中，利用奇偶剪枝能极大的降低时间复杂度。

**内容：**假设起点为（sx,sy），终点为（ex,ey），给定 t 步恰好走到终点，如图所示（“|”竖走，“—”横走，“+”转弯），易证 abs(ex-sx)+abs(ey-sy) 为此问题类中任意情况下，起点到终点的最短步数，记做 step，此处 step1=8；

<img src="/Users/zyh/Library/Application Support/typora-user-images/image-20211021094648226.png" alt="image-20211021094648226" style="zoom:50%;" />

为一般情况下非最短路径的任意走法举例，step2=14；step2-step1=6，偏移路径为 6

<img src="/Users/zyh/Library/Application Support/typora-user-images/image-20211021094724545.png" alt="image-20211021094724545" style="zoom:50%;" />

**若 t-[abs(ex-sx)+abs(ey-sy)] 结果为奇数，则无法在 t 步恰好到达，返回 false；反之，若结果为偶数，则可以在 t 步恰好到达，返回 true。**

##### 5.图的遍历

**定义**:图的遍历问题是从图中某一顶点出发，系统地访问图中所有顶点，使每个顶点恰好被访问一次。

**分类：**

目前，图的遍历问题分为四类：

1. 欧拉通路与欧拉回路问题：遍历完所有的边而不能有重复，即一笔画问题
2. 中国邮递员问题：遍历完所有的边而可以有重复
3. 哈密尔顿问题：遍历完所有的顶点而没有重复
4. 旅行推销员问题：遍历完所有的顶点而可以重复

**技巧：**

为避免重复访问某个顶点，通常设置一个标志数组 vis[N]，未访问时值为 false，访问后改为 true

##### 6.最小生成树

​	由于最小生成树本身是一棵生成树，所以需要时刻满足以下两点：

- 生成树中任意顶点之间有且仅有一条通路，也就是说，生成树中不能存在回路；
- 对于具有 n 个顶点的连通网，其生成树中只能有 n-1 条边，这 n-1 条边连通着 n 个顶点。

###### a.Kruskal算法

​	从边的角度的最小生成树，时间复杂度为O(eloge)。适合求稀疏的网的最小生成树。

​	对于任意一个连通网的最小生成树来说，在要求总的权值最小的情况下，最直接的想法就是将连通网中的所有边按照权值大小进行升序排序，从小到大依次选择。

**具体思路：**

​	将所有边按照权值的大小进行升序排序，然后从小到大一一判断，条件为：如果这个边不会与之前选择的所有边组成回路，就可以作为最小生成树的一部分；反之，舍去。直到具有 n 个顶点的连通网筛选出来 n-1 条边为止。筛选出来的边和所有的顶点构成此连通网的最小生成树。

​	可以用利用并查集的思想实现。

**生成过程：**

<img src="/Users/zyh/Library/Application Support/typora-user-images/image-20211029223642195.png" alt="image-20211029223642195" style="zoom:50%;" />

**实现：**

```c++
#include <iostream>
#include <algorithm>

using namespace std;

/*
3 3
1 2 1
2 3 2
3 1 3
 */

/*
 前期变量准备：
    一个结构体数组：因为涉及到边val排序，需要存储关系
    parent数组：存储根节点
 */

int n,m;
int parent[110];

struct Edge{
    int from;
    int to;
    int val;
};
Edge edge[110 * 110];

bool cmp(Edge node1 , Edge node2){
    return node1.val < node2.val ;
}

int findRoot(int x){
    if(parent[x] == x){
        return x;
    }else{
        return parent[x] = findRoot(parent[x]);
    }
}

bool unionNode(int node1 , int node2){
    int root1 = findRoot(node1);
    int root2 = findRoot(node2);
    if(root1 != root2){
        parent[root1] = root2;
        return true;
    }
    return false;
}

void init(){
    for(int i = 0; i <= n; i ++){
        parent[i] = i;
    }
}

int Kruskal(){
    sort(edge , edge + m , cmp);
    int cnt = 0;
    int sum = 0;
    init();
    for(int i = 0; i < m; i ++){
        if(unionNode(edge[i].from ,edge[i].to)){
            sum += edge[i].val ;
            cnt ++;
        }
        if(cnt == n-1){
            break;
        }
    }
    return sum;
}

int main(){
    cin >> n >> m;
    for(int i = 0; i < m; i ++){
        cin >> edge[i].from >> edge[i].to >> edge[i].val;
    }
    int minLen = Kruskal();
    cout << minLen << endl;
    return 0;
}
```

###### b.Prim算法

**核心思想：**普里姆算法在找最小生成树时，将顶点分为两类，一类是在查找的过程中已经包含在树中的（假设为 A 类），剩下的是另一类（假设为 B 类）。

​	对于给定的连通网，起始状态全部顶点都归为 B 类。在找最小生成树时，选定任意一个顶点作为起始点，并将之从 B 类移至 A 类；然后找出 B 类中到 A 类中的顶点之间权值最小的顶点，将之从 B 类移至 A 类，如此重复，直到 B 类中没有顶点为止。所走过的顶点和边就是该连通图的最小生成树。

```c++
#include <stdio.h>
#include <iostream>
#include <string.h>

using namespace std;

/*
4
0 4 9 21
4 0 8 17
9 8 0 16
21 17 16 0
 */
const int MAX_N = 110;
const int inf = 0x7fffffff;
//构造邻接矩阵
int map[MAX_N][MAX_N];
//low数组:保存与已加入树中的顶点相连的边
int low[MAX_N];
//记录该顶点是否已加入树中
int visit[MAX_N];
int n;

int prim(){
    int pos , Min , result=0;
    memset(visit,0,sizeof(visit));
    //首先找的是1这个顶点，加入图中
    visit[1] = 1 , pos = 1;
    for(int i = 1 ; i <= n ; i++){
        if(i != pos){
            //与1顶点相连的边地权值
            low[i] = map[pos][i];
        }
    }
    //每次加入一条边，n个顶点加入n-1条边，循环n-1次就可以了
    for(int i = 1; i < n ; i++){
        Min = inf;
        for(int j = 1 ; j <= n ; j++){
            if(!visit[j] && Min > low[j]){
                Min = low[j];//Min找到的是与已加入图中的顶点相连的边的最小值
                pos = j;//该顶点为j
            }
        }
        result += Min;//加上最小边
        visit[pos] = 1;//新的顶点位置
        for(int j = 1 ; j <= n ; j++)
            if(!visit[j] && low[j] > map[pos][j])
                low[j]=map[pos][j];//更新low[]值，新的与图中已有的点相连的边，如果比原来小的，就更新
    }
    return result;
}
int main(){
    while(scanf("%d",&n) != EOF){
        for(int i = 1 ; i <= n ; i++){
            for(int j = 1 ; j <= n ; j++){
                cin >> map[i][j];
                map[j][i] = map[i][j];
            }
        }
        int MinR = prim();
        cout << MinR << endl;
    }
    return 0;
}
```

##### 7.单源点最短路径

###### a.Floyd算法

对于网中的任意两个顶点（例如顶点 A 到顶点 B）来说，之间的最短路径不外乎有 2 种情况：

1. 直接从顶点 A 到顶点 B 的弧的权值为顶点 A 到顶点 B 的最短路径；
2. 从顶点 A 开始，经过若干个顶点，最终达到顶点 B，期间经过的弧的权值和为顶点 A 到顶点 B 的最短路径。

**核心思想：**插点

​	对于从顶点 A 到顶点 B 的最短路径，拿出网中所有的顶点进行如下判断：

```
Dis（A，K）+ Dis（K，B）< Dis（A，B）
```

​	判断经过顶点 K 是否存在一条可行路径比直达的路径的权值小，如果式子成立，说明确实存在一条权值更小的路径，此时只需要更新记录的权值和即可。

**实现：**

```c++
#include <iostream>
#include <algorithm>

using namespace std;

const int INF=0x3f3f3f;
const int maxN = 110;

/*
5 5
1 3 4
4 3 2
1 2 3
5 4 2
3 5 6
 */

/*
    前期变量准备：
        map[][]:用于存储图，临街矩阵
        dis[][]:用于存放floyd遍历后，更新的最小值
 */

//记录最短路径
int dis[maxN][maxN];
//记录初始各边权值
int map[maxN][maxN];
int node , edge;

void init(){
    for(int i = 1 ; i <= node ; i++){
        for(int j = 1 ; j <= node ; j++){
            if(i==j){
                map[i][j] = 0;
            }else{
                map[i][j] = INF;
            }
        }
    }
}

void Floyd(){
    //初始化最短路径数组
    for(int i = 1 ; i <= node ; i++){
        for(int j = 1 ; j <= node ; j++){
            dis[i][j] = map[i][j];
        }
    }
    //遍历k点,进行floyd插点
    for(int k = 1 ; k <= node ; k++){
        for(int i = 1 ; i <= node ; i++){
            for(int j = 1 ; j <= node ; j++) {
                dis[i][j] = min(dis[i][j] , dis[i][k] + dis[k][j]);
            }
        }

    }
}

int main(){
    cin >> node >> edge;
    int x , y , val;
    init();
    for(int i = 1 ; i <= edge ; i++){
        cin >> x >> y >> val;
        if(val < map[x][y]){
            map[x][y] = map[y][x] = val;
        }
    }
    Floyd();
    for(int i = 1 ; i <= node ; i++){
        for(int j = 1 ; j <= node; j++){
            cout << dis[i][j] << " ";
        }
        cout << endl;
    }

}
```

##### 8.强连分量算法

###### a.tarjan算法

[讲解连接](https://www.bilibili.com/video/BV19J411J7AZ?p=5)

**核心变量概念：**

​	dfn[] : DFS中，x点被访问的时间点

​	low[] : x通过有向边回溯到的最早的时间点 

​	time : 当前的时间戳，记录当前访问的时间点

**tarjan模板**

```c++
#include <iostream>
#include <stack>

using namespace std;

/**********************************************
    3 → 4 ← 6 → 2
    ↑↓  ↓ ↗ ↓ ↙↑
    7 → 5 → 0 → 1
**********************************************/
#define V (8)
int g[V][V] =
        { // 0 1 2 3 4 5 6 7
            {0,1,0,0,0,0,0,0},
            {0,0,1,0,0,0,0,0},
            {1,0,0,0,0,0,0,0},
            {0,0,0,0,1,0,0,1},
            {0,0,0,0,0,1,0,0},
            {1,0,0,0,0,0,1,0},
            {1,0,1,0,1,0,0,0},
            {0,0,0,1,0,1,0,0}
        };
int cnt = 0;

void tarjan_dfs(int x, int dfn[], int low[], stack<int>& s, bool in_stack[])
{
    static int time = 1;
    dfn[x] = low[x] = time++;
    s.push(x);
    in_stack[x] = true;

    for(int y = 0; y < V; y++)
    {
        if(g[x][y])
        {
            if(0 == dfn[y])
            {
                tarjan_dfs(y, dfn, low, s, in_stack);
                low[x] = min(low[x], low[y]);
            }
            else if(in_stack[y])
                low[x] = min(low[x], dfn[y]);
        }
    }

    if(dfn[x] == low[x])
    {
        cnt++;
        int tmp;
        cout << "第" << cnt << "个连通分量 : " ;
        do
        {
            tmp = s.top(); s.pop();
            in_stack[tmp] = false;
            cout<<tmp<<"-";
        }while(tmp != x);
        cout<<endl;
    }
}

void scc_tarjan()
{
    int dfn[V] = {0}, low[V] = {0};
    bool in_stack[V] = {false};
    stack<int> s;
    for(int i = 0; i < V; i++)
        if(!dfn[i])
            tarjan_dfs(i, dfn, low, s, in_stack);
}

int main()
{
    scc_tarjan();
    cout << "强连通分量个数 : "<< cnt << endl;
    return 0;
}


```

