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
//need[]为凸包上的点
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
void findMinY(){
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
        findMinY();
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

