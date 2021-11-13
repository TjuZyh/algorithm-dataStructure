#### 凸包算法_Graham扫描法

##### 1.概念

​	凸包是一个计算几何中的概念，在一个实数向量空间V中，对于给定集合X，所有包含X的凸集的交集S被称为X的凸包。

​	简单来讲，给定二维平面上的点集，凸包就是将最外层的点连接起来构成的凸多边型，它能包含点集中所有的点。

<img src="/Users/zyh/Library/Application Support/typora-user-images/image-20211008201726613.png" alt="image-20211008201726613" style="zoom:50%;" />

​	假设平面上有p0~p12共13个点，过某些点作一个多边形，使这个多边形能把所有点都“包”起来。当这个多边形是凸多边形的时候，就称之为“凸包”。

##### 2.算法思路及步骤

​	**Graham扫描法：时间复杂度O(nlogn)**

​	**算法思路：**Graham扫描的思想是先找到凸包上的一个点，然后从那个点开始按逆时针方向逐个找凸包上的点，实际上就是进行极角排序，然后对其查询使用。

<img src="/Users/zyh/Library/Application Support/typora-user-images/image-20211008202354843.png" alt="image-20211008202354843" style="zoom:50%;" />

​	**算法实现步骤：**

​	**准备步骤：**

​	**利用叉积作为判断向量间左转的依据，即cross>0 为 向量ab到向量ac需要左转**

​	叉积公式：cross =  (b.x-a.x)*(c.y-a.y)-(c.x-a.x)*(b.y-a.y)

<img src="/Users/zyh/Library/Application Support/typora-user-images/image-20211008222127861.png" alt="image-20211008222127861" style="zoom:33%;" />

​	1.把所有点放在二维坐标系中，将纵坐标最小的 P0 作为原点。

​	2.计算各个点相对于 P0 的幅角(PXP0向量) α ，按从小到大的顺序对各个点排序。当 α 相同时，距离 P0 比较近的排在前面

​	**求解凸包（Graham扫描法）：**

​	创建存放凸包上点的数组a[];

​	既然排好序，就已经确定凸包上的第一个点为P0、第二个点为P1，将其存入数组a中。

​	创建遍历凸包数组a的游标top；

​	判断当前点p(i)与数组a中前两个点a[top-1],a[top]之间关系，若为左转关系( **即 向量a[top-1]a[top] 到向量 a[top-1]p(i) 需要左转**  )则为凸包上的点，将其记录到a中（**暂时记录，通过下面的N个点才可以判断这个点到底是不是凸包上的点，有可能回溯！**）；若为右转关系，则判定当前点p(i)与确定凸包上的前前两个点a[top-2],a[top-1]的关系，直到判断关系为左转，将当前点替代原本凸包中的点。

<img src="/Users/zyh/Library/Application Support/typora-user-images/image-20211008223218171.png" alt="image-20211008223218171" style="zoom:33%;" />

<img src="/Users/zyh/Library/Application Support/typora-user-images/image-20211008223240828.png" alt="image-20211008223240828" style="zoom:33%;" />

##### 3.算法实现

```c++
#include <iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
using namespace std;

int n;
int top;

//定义结构体数组存储点
//point[]为输入点的集合
//need[]为凸包上点的集合
struct Point{
    int x;
    int y;
}point[110],need[110];

//距离公式
double dis(Point a,Point b){
    return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}

//叉积公式
//向量ab与向量ac的叉积
//>0 左转 <0 右转
double cross(Point a,Point b,Point c){
    return (b.x-a.x)*(c.y-a.y)-(c.x-a.x)*(b.y-a.y);
}

//找极点point[0]
void find_miny(){
    Point tmp=point[0];
    int flag=0;
    for(int i=1;i<n;i++){
        if(point[i].y < tmp.y || (point[i].y == tmp.y && point[i].x < tmp.x)){
            tmp=point[i]; flag=i;
        }
    }
    if(flag) swap(point[0],point[flag]);
}

//基于point[0]的幅角进行点的排序
bool cmp(Point a,Point b){
    double n = cross(point[0],a,b);
    //n>0 a点的极角小于b点极角；若极角相同则判断到极点的距离
    if(n > 0||(n==0 && dis(point[0],a) < dis(point[0],b)))
        return true;
    return false;
}

//Graham扫描法
void Graham(){
    top=-1;
    //初始化，0、1点已经确定在凸包中
    need[++top]=point[0];
    need[++top]=point[1];
    for(int i=2 ; i<n ; i++){
        //以top-1为基准点(向量起点)，判断当前点与前面点的叉积，若左转则退出循环记录到凸包数组中；若右转则继续判断与前前两点叉积，直到判断出左转
        while(top && cross(need[top-1],need[top],point[i]) < 0)
            top--;
        need[++top] = point[i];
    }
}

/*
9
12 7
24 9
30 5
41 9
80 7
50 87
22 9
45 1
50 7
0
*/

int main()
{
  	cin >> n;
    while(n){
        for(int i=0;i<n;i++){
          	ccin >> point[i].x >> point[i].y;
        }
        if(n==1) {
            cout >> "just one point!" >> endl ;
            continue;
        }
        if(n==2) {
            cout >> "just two point!" >> endl ;
            continue;
        }
        //确定基准点point[0]
        find_miny();
        //基于叉积对输入的点进行排序
        sort(point+1,point+n,cmp);
        //graham算法
        Graham();
        for(int i = 0 ; i < top ; i++){
            cout << need[i].x << " " << need[i].y << endl;
        }
    }
    return 0;
}
```

##### 4.算法实战

###### a. surround the trees

**problem description:**

There are a lot of trees in an area. A peasant wants to buy a rope to surround all these trees. So at first he must know the minimal required length of the rope. However, he does not know how to calculate it. Can you help him?
The diameter and length of the trees are omitted, which means a tree can be seen as a point. The thickness of the rope is also omitted which means a rope can be seen as a line.

<img src="/Users/zyh/Library/Application Support/typora-user-images/image-20211009083941823.png" alt="image-20211009083941823" style="zoom:50%;" />



**Input**:

The input contains one or more data sets. At first line of each input data set is number of trees in this data set, it is followed by series of coordinates of the trees. Each coordinate is a positive integer pair, and each integer is less than 32767. Each pair is separated by blank.

Zero at line for number of trees terminates the input for your program.

```
9
12 7
24 9
30 5
41 9
80 7
50 87
22 9
45 1
50 7
0
```

**Output:**

The minimal length of the rope. The precision should be 10^-2.

```
243.06
```

**Solve：**

​	利用凸包算法，找出凸包上的点集，按逆时针的顺序进行边的相加即可。

```c++
#include <iostream>
#include<algorithm>
#include<cmath>
#include <iomanip>

using namespace std;

/*
9
12 7
24 9
30 5
41 9
80 7
50 87
22 9
45 1
50 7
0
 */

int n;
int top;
double ans;

//定义结构体数组存储点
//point[]为输入点的集合
//need[]为最终的外侧点集合
struct Point{
    int x;
    int y;
}point[110],need[110];

//求两点距离
double dis(Point a,Point b){
    return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}

//向量ab与向量ac的叉积
//>0 左转 <0 右转
double cross(Point a,Point b,Point c){
    return (b.x-a.x)*(c.y-a.y)-(c.x-a.x)*(b.y-a.y);
}

//找point[0]
void find_miny(){
    Point tmp=point[0];
    int flag=0;
    for(int i=1;i<n;i++){
        if(point[i].y < tmp.y || (point[i].y == tmp.y && point[i].x < tmp.x)){
            tmp=point[i]; flag=i;
        }
    }
    if(flag) swap(point[0],point[flag]);
}

//基于point[0]进行点的排序
bool cmp(Point a,Point b){
    double n = cross(point[0],a,b);
    //n>0 a点的极角小于b点极角；若极角相同则判断到极点的距离
    if(n > 0||(n==0 && dis(point[0],a) < dis(point[0],b)))
        return true;
    return false;
}

//Graham扫描法
//每次判断三个点，即两个向量
void Graham(){
    top=-1;
    //0、1点已经在need中
    need[++top]=point[0];
    need[++top]=point[1];
    for(int i=2 ; i<n ; i++){
        //以top-1为基准点(向量起点)，判断top是否需要加入need[]
        while(top && cross(need[top-1],need[top],point[i]) < 0)
            top--;
        need[++top] = point[i];
    }
}

//求凸包的周长
void sum(){
    ans=0;
    need[++top]=point[0];
    for(int i=0;i<top;i++){
        ans+=dis(need[i],need[i+1]);
    }
}

int main(){
    cin >> n;
    while(n){
        for(int i=0;i<n;i++){
            cin >> point[i].x >> point[i].y;
        }
        if(n==1) {
            cout << "0.00" << endl;
            continue;
        }
        if(n==2) {
            cout << fixed << setprecision(2) << dis(point[0],point[1]) << endl;
            continue;
        }
        //确定基准点
        find_miny();
        //基于叉积对输入的点进行排序
        sort(point+1,point+n,cmp);
        //graham算法
        Graham();
        sum();
        
        cout << fixed << setprecision(2) << ans << endl;
        cin >> n;
    }
    return 0;
}
```

###### b.wall

**problem description:**

Once upon a time there was a greedy King who ordered his chief Architect to build a wall around the King's castle. The King was so greedy, that he would not listen to his Architect's proposals to build a beautiful brick wall with a perfect shape and nice tall towers. Instead, he ordered to build the wall around the whole castle using the least amount of stone and labor, but demanded that the wall should not come closer to the castle than a certain distance. If the King finds that the Architect has used more resources to build the wall than it was absolutely necessary to satisfy those requirements, then the Architect will loose his head. Moreover, he demanded Architect to introduce at once a plan of the wall listing the exact amount of resources that are needed to build the wall. 

Your task is to help poor Architect to save his head, by writing a program that will find the minimum possible length of the wall that he could build around the castle to satisfy King's requirements. 

The task is somewhat simplified by the fact, that the King's castle has a polygonal shape and is situated on a flat ground. The Architect has already established a Cartesian coordinate system and has precisely measured the coordinates of all castle's vertices in feet.

**input:**

The first line of the input file contains two integer numbers N and L separated by a space. N (3 <= N <= 1000) is the number of vertices in the King's castle, and L (1 <= L <= 1000) is the minimal number of feet that King allows for the wall to come close to the castle. 

Next N lines describe coordinates of castle's vertices in a clockwise order. Each line contains two integer numbers Xi and Yi separated by a space (-10000 <= Xi, Yi <= 10000) that represent the coordinates of ith vertex. All vertices are different and the sides of the castle do not intersect anywhere except for vertices.

```
9 100
200 400
300 400
300 300
400 300
400 400
500 400
500 200
350 200
200 200
```

**output:**

Write to the output file the single number that represents the minimal possible length of the wall in feet that could be built around the castle to satisfy King's requirements. You must present the integer number of feet to the King, because the floating numbers are not invented yet. However, you must round the result in such a way, that it is accurate to 8 inches (1 foot is equal to 12 inches), since the King will not tolerate larger error in the estimates.

```
1628
```

**solve：**

<img src="/Users/zyh/Library/Application Support/typora-user-images/image-20211009091053379.png" alt="image-20211009091053379" style="zoom:33%;" />

​		两点之间直线最短，对于凹进去的部分，肯定有最短的直线可以包含它，可以忽略，所以是求凸包。

   	考虑L，对于求出的凸多边形，对于它的顶点X，可以证明每个X附近需要增加一定的圆弧来保证顶点到圆弧的距离大于等于L，

​    所有X的圆弧角度之和为Pi，将凸包平移与圆弧连接成封闭图案，**最终 ans=凸包+2\*Pi\*L。**

```c++
#include <algorithm>
#include <cmath>
#include <iostream>
using namespace std;

/*
9 100
200 400
300 400
300 300
400 300
400 400
500 400
500 200
350 200
200 200
*/

const int N = 1000;
const double Pi = M_PI;

typedef struct {
    int x ;
    int y ;
}P;

P list[N];
//存储凸包外侧的点
int stack[N];
//顶点
int top;

//计算叉积: 向量 p0p1 X p0p2
int cross(P p0, P p1, P p2) {
    return (p1.x - p0.x) * (p2.y - p0.y) - (p2.x - p0.x) * (p1.y - p0.y);
}

//计算 p1p2的 距离
double dis(P p1, P p2) {
    return sqrt((double)(p2.x - p1.x) * (p2.x - p1.x) + (p2.y - p1.y) * (p2.y - p1.y));
}

//利用极角排序，角度相同则距离小排前面
bool cmp(P p1, P p2) {
    int tmp = cross(list[0], p1, p2);
    if (tmp > 0)
        return true;
    else if (tmp == 0 && dis(list[0], p1) < dis(list[0], p2))
        return true;
    else
        return false;
}

//数据压入数组，并按极角进行排序
void init(int n) {
    int k = 0;
    cin >> list[0].x >> list[0].y;
    P p0 = list[0]; // 初始化list[0]
    //查找list[0]，x&y最小
    for (int i = 1; i < n ; ++i) {
        cin >> list[i].x >> list[i].y;
        if (p0.y > list[i].y || (p0.y == list[i].y && p0.x > list[i].x))
            p0 = list[i], k = i;
    }
    list[k] = list[0];
    list[0] = p0;
    //基于list[0]进行排序
    sort(list + 1, list + n, cmp);
}

//Graham扫描法
void Graham(int n) {
    int i;
    if (n == 1){
        top = 0, stack[0] = 0;
    }
    if (n == 2){
        top = 1, stack[0] = 0, stack[1] = 1;
    }
    if (n > 2) {
        for (i = 0; i <= 1; i++){
            stack[i] = i;
        }
        top = 1;
        for (i = 2; i < n; i++) {
            while (top > 0 && cross(list[stack[top - 1]], list[stack[top]], list[i]) <= 0){
                top--;
            }
            top++;
            stack[top] = i;
        }
    }
}
int main() {
    int N, L;
    while (cin >> N >> L){
        //初始化点集
        init(N);
        Graham(N);
        //叉积求凸包周长
        double len = 0;
        for (int i = 0; i < top; i++){
            len += dis(list[stack[i]], list[stack[i + 1]]);
        }
        len += dis(list[stack[0]], list[stack[top]]);

        len += 2 * Pi * L;
        len = int(len + 0.5);
        cout << len << endl;
    }
}


```

###### c.cows

**Problem description:**

Your friend to the south is interested in building fences and turning plowshares into swords. In order to help with his overseas adventure, they are forced to save money on buying fence posts by using trees as fence posts wherever possible. Given the locations of some trees, you are to help farmers try to create the largest pasture that is possible. Not all the trees will need to be used.

However, because you will oversee the construction of the pasture yourself, all the farmers want to know is how many cows they can put in the pasture. It is well known that a cow needs at least 50 square metres of pasture to survive.

**Input:**

The first line of input contains a single integer, n (1 ≤ n ≤ 10000), containing the number of trees that grow on the available land. The next n lines contain the integer coordinates of each tree given as two integers x and y separated by one space (where -1000 ≤ x, y ≤ 1000). The integer coordinates correlate exactly to distance in metres (e.g., the distance between coordinate (10; 11) and (11; 11) is one metre).

```
4
0 0
0 101
75 0
75 101
```

**Output:**

You are to output a single integer value, the number of cows that can survive on the largest field you can construct using the available trees.

```
151
```

**Solve:**

给出n个点，求出点集的凸包，并求算出凸包的面积，每头牛生存空间为50，最后面积/50即可

**多边形面积求解：**

任意给出一个三角形ΔABC，设其顶点坐标分别为A（x1, y1），B（x2, y2），C（x3, y3），那么根据线性代数的知识，ΔABC的有向面积可表示为：

<img src="/Users/zyh/Library/Application Support/typora-user-images/image-20211009093822652.png" alt="image-20211009093822652" style="zoom:50%;" />

<img src="/Users/zyh/Library/Application Support/typora-user-images/image-20211009093932154.png" alt="image-20211009093932154" style="zoom:50%;" />

任意的多边形都可以分割成多个三角形，根据以上三角形面积公式就可以求出任意多边形的面积。如图2所示的六边形顶点坐标分别为O（x0, y0），A（x1, y1），B（x2, y2），C（x3, y3），D（x4, y4），E（x5, y5），则其面积可以表示为四个三角形面积之和：S=S∆OAB+S∆OBC+S∆OCD+S∆ODE

<img src="/Users/zyh/Library/Application Support/typora-user-images/image-20211009094036693.png" alt="image-20211009094036693" style="zoom:50%;" />

<img src="/Users/zyh/Library/Application Support/typora-user-images/image-20211009094056505.png" alt="image-20211009094056505" style="zoom:50%;" />

```c++
struct Point2d
{
    double x;
    double y;
    Point2d(double xx, double yy): x(xx), y(yy){}
};
 
//计算任意多边形的面积，顶点按照顺时针或者逆时针方向排列
double ComputePolygonArea(const vector<Point2d> &points)
{
    int point_num = points.size();
    if(point_num < 3)return 0.0;
    double s = 0;
    for(int i = 0; i < point_num; ++i)
        s += points[i].x * points[(i+1)%point_num].y - points[i].y * points[(i+1)%point_num].x;
    return fabs(s/2.0);
}
```

**问题求解：**

```c++
#include <iostream>
#include<algorithm>
#include<cmath>
using namespace std;

/*
4
0 0
0 101
75 0
75 101
 */

int n;
int top;
double ans;

//定义结构体数组存储点
//point[]为输入点的集合
//need[]为凸包上点的集合
struct Point{
    int x;
    int y;
}point[110],need[110];

//求两点距离
double dis(Point a,Point b){
    return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}

//向量ab与向量ac的叉积
//>0 左转 <0 右转
double cross(Point a,Point b,Point c){
    return (b.x-a.x)*(c.y-a.y)-(c.x-a.x)*(b.y-a.y);
}

//找point[0]
void find_miny(){
    Point tmp=point[0];
    int flag=0;
    for(int i=1;i<n;i++){
        if(point[i].y < tmp.y || (point[i].y == tmp.y && point[i].x < tmp.x)){
            tmp=point[i]; flag=i;
        }
    }
    if(flag) swap(point[0],point[flag]);
}

//基于point[0]进行点的排序
bool cmp(Point a,Point b){
    double n = cross(point[0],a,b);
    if(n > 0||(n==0 && dis(point[0],a) < dis(point[0],b)))
        return true;
    return false;
}

//Graham扫描法
//每次判断三个点，即两个向量
void Graham(){
    top=-1;
    //0、1点已经在need中
    need[++top]=point[0];
    need[++top]=point[1];
    for(int i=2 ; i<n ; i++){
        //以top-1为基准点(向量起点)，判断top是否需要加入need[]
        while(top && cross(need[top-1],need[top],point[i]) < 0)
            top--;
        need[++top] = point[i];
    }
}

//求凸包的面积
void area(){
    ans=0;
    need[++top]=point[0];
    double s = 0;
    for(int i = 0; i < top; ++i)
        s += need[i].x * need[(i+1) % top].y - need[i].y * need[(i+1)%top].x;
    ans = fabs(s/2.0);
}

int main(){
    while(cin >> n){
        for(int i=0;i<n;i++){
            cin >> point[i].x >> point[i].y;
        }
        if(n==1) {
            cout << 0 << endl;
            continue;
        }
        if(n==2) {
            cout << 0 << endl ;
            continue;
        }
        //确定基准点
        find_miny();
        //基于叉积对输入的点进行排序
        sort(point+1,point+n,cmp);
        //graham算法
        Graham();
        area();
        cout << (int)ans/50 << endl;
    }
    return 0;
}
```

