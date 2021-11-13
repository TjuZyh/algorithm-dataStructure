#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

/*
3
10.000 10.000 50.000 10.000
40.000 10.000 50.000 10.000
40.000 40.000 50.000 10.000
2
30.000 30.000 30.000 20.000
40.000 40.000 40.000 20.000
5
5.729 15.143 3.996 25.837
6.013 14.372 4.818 10.671
80.115 63.292 84.477 15.120
64.095 80.924 70.029 14.881
39.472 85.116 71.369 5.553
0
 */

/*将坐标进行处理，后计算最小生成树即可*/

const int maxN=105;

int n,tot;

int parent[maxN];

double ans;

struct Point{
    double x , y , z;
    double r;
};

Point point[maxN];

struct Edge{
    int from , to;
    double val;
};

Edge edge[maxN*maxN];

void init(){
    ans=0;
    tot=0;
    for(int i = 0 ; i < maxN ; i++){
        parent[i] = i;
    }
}

int findRoot(int x){
    return parent[x]==x? x : parent[x] = findRoot(parent[x]);
}

double Distance(Point a , Point b){
    double dis = 0;
    double xx = a.x-b.x;
    double yy = a.y-b.y;
    double zz = a.z-b.z;
    //两个空间站的距离可能重叠，即小于0
    dis = max(dis , sqrt(xx * xx + yy * yy + zz * zz)-a.r-b.r);
    return dis;
}

bool cmp(Edge a , Edge b){
    return a.val < b.val;
}

int main(){
    while(scanf("%d",&n) != EOF && n){
        init();
        for(int i = 1 ; i <= n ; i++){
            cin >> point[i].x >> point[i].y >> point[i].z >> point[i].r ;
        }
        //建立空间站之间的关系
        for(int i = 1 ; i <= n ; i++){
            for(int j = i + 1 ; j <= n ; j++){
                edge[tot].from=i;
                edge[tot].to=j;
                edge[tot].val=Distance(point[i],point[j]);
                tot++;
            }
        }
        sort(edge ,edge + tot , cmp);
        //Kruskal Algorithm
        for(int i = 0 ; i < tot ; i++){
            int fromRoot = findRoot(edge[i].from);
            int toRoot = findRoot(edge[i].to);
            if(fromRoot != toRoot){
                parent[toRoot] = fromRoot;
                ans += edge[i].val;
            }
        }
        printf("%.3f\n",ans);
    }
    return 0;
}
