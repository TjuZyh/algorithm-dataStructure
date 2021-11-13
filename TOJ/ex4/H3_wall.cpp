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

struct P{
    int x ;
    int y ;
};

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
    return sqrt((long long)(p2.x - p1.x) * (p2.x - p1.x) + (p2.y - p1.y) * (p2.y - p1.y));
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

