#include <iostream>
#include<cmath>
#include<vector>
#include<algorithm>
#include <iomanip>
#define eps 1e-7
#define inf 1<<30
//比较一个浮点数是否等于零，EPS是定义的一个非常小的数
#define zero(a) (fabs((double)(a))<eps)
using namespace std;

/*
6
0  0  8  3
1  4  3  2
2  1  7  1
4  1  2  3
3  5  4  6
2  3  9  8
3
3  0 10  2
5  5 20 25
7 -3 30 32
0
*/

struct Point{
    int x,y,v,l;
}p[15];

int n;
//存放没有被砍的树
vector<Point>a;

//叉积
int cross(Point p0,Point p1,Point p2){
    return (p1.x-p0.x)*(p2.y-p0.y)-(p1.y-p0.y)*(p2.x-p0.x);
}

//计算距离
double dist(Point p1,Point p2){
    return sqrt((double)(p2.x-p1.x)*(p2.x-p1.x)+(p2.y-p1.y)*(p2.y-p1.y));
}

//极角排序
bool cmp(Point p1,Point p2){
    if(cross(a[0],p1,p2)>0) return true;
    else if(zero(cross(a[0],p1,p2))&&dist(a[0],p1)<dist(a[0],p2)) return true;
    return false;
}

//Graham扫描法
double Graham(int len){
    //如果只剩下一棵树就不用围了
    if(a.size()==1){
        return len;
    }else if(a.size()==2){//如果只剩下两棵树，那就是二者距离和的2倍，注意是2倍，可以从样例中看出来
        return len-dist(a[0],a[1])*2;
    }
    for(int i=1;i<a.size();i++)
        if(a[i].y<a[0].y||(a[i].y==a[0].y&&a[i].x<a[0].x))
            swap(a[0],a[i]);
    sort(a.begin()+1,a.end(),cmp);
    vector<Point>s;
    s.push_back(a[0]);s.push_back(a[1]);s.push_back(a[2]);
    for(int i=3;i<a.size();i++){
        while(s.size()>=2&&cross(s[s.size()-2],s[s.size()-1],a[i])<eps)
            s.pop_back();
        s.push_back(a[i]);
    }
    s.push_back(s[0]);
    double ans=0;
    //求凸包周长
    for(int i=0;i<s.size()-1;i++)
        ans+=dist(s[i],s[i+1]);
    return len-ans;
}
int main(){
    int cas=0;
    cin >> n;
    while(n != 0){
        for(int i=0;i<n;i++){
            cin >> p[i].x >> p[i].y >> p[i].v >> p[i].l ;
        }
        //最优解的代价，砍掉树目的数量，最优状态
        int best_val=inf,best_num,best_state;
        //最优解剩下的木材
        double best_extra;
        //二进制枚举
        for(int i=1;i<(1<<n)-1;i++){
            int tmp_val=0,tmp_len=0;
            a.clear();
            for(int j=0;j<n;j++){
                if(!((1<<j)&i))
                    a.push_back(p[j]);
                else{
                    tmp_len+=p[j].l;
                    tmp_val+=p[j].v;
                }
            }
            //小小剪枝
            if(tmp_val>best_val)  continue;
            double extra=Graham(tmp_len);
            //如果extra<0说明不够用
            if(extra>=0){
                if(tmp_val<best_val){
                    best_val=tmp_val;
                    best_num=n-a.size();
                    best_state=i;
                    best_extra=extra;
                }
                else if(tmp_val==best_val&&n-a.size()<best_num){
                    best_num=n-a.size();
                    best_state=i;
                    best_extra=extra;
                }
            }
        }
        cout << "Forest " << ++cas <<endl;
        cout << "Cut these trees:";
        for(int i=0;i<n;i++)
            if((1<<i)&best_state){
                cout << " " << i+1 ;
            }
        cout << endl;
        cout << "Extra wood: " << fixed << setprecision(2) << best_extra << endl;
        cout << endl;
        cin >> n;
    }
    return 0;
}

