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
        /*for(int i = 0 ; i < top ; i++){
            cout << need[i].x << " " << need[i].y << endl;
        }*/
        cout << (int)ans/50 << endl;
    }
    return 0;
}

