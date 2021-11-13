#include <iostream>
#include <algorithm>

using namespace std;

/*
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
 */

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
bool cmp(Info info1 , Info info2){
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
        sort(info+1 , info+1+line , cmp);
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




