#include <iostream>

using namespace std;

struct Comp{
    int x;
    int y;
};

Comp comp[200000];

int openCom[200010];
int parent[200010];

//利用平方的方式比较距离，不需要求出具体的距离
int distance(Comp a , Comp b){
    return (a.x - b.x) * (a.x - b.x) + (a.y -b.y) * (a.y -b.y);
}

void init(){
    for(int i = 1 ; i <= 200010 ; i++){
        openCom[i] = 0;
    }
    for(int i = 1 ; i <= 200010 ; i++){
        parent[i] = i;
    }
}

int findRoot(int x){
    return x == parent[x] ? x : findRoot(parent[x]);
}

void unionCom(int a , int b){
    int c1 = findRoot(a);
    int c2 = findRoot(b);
    if(c1 != c2){
        parent[c2] = c1 ;
    }
}

int main(){
    int n , dist;
    cin >> n >> dist;
    char opt;
    int c1 , c2;
    int com;
    for(int i = 1 ; i <= n ; i++){
        cin >> comp[i].x >> comp[i].y;
    }
    init();
    getchar();
    opt = getchar();

    while(opt != EOF){
        if(opt == 'O'){
            cin >> com;
            openCom[com] = 1;
            //遍历数组将距离小于dist且打开的计算机全部相连
            for(int i = 1 ; i <= 20010 ; i++){
                if(openCom[i] && (distance(comp[com] , comp[i]) <= dist * dist)){
                    unionCom(com , i);
                }
            }
        }else if(opt == 'S'){ //检查两个计算机是否相连
            cin >> c1 >> c2 ;
            //若为同一连通分量，一定可以连通
            if(findRoot(c1) == findRoot(c2)){
                cout << "SUCCESS" << endl;
            }else{
                cout << "FAIL" << endl;
            }
        }
        getchar();
        opt = getchar();
    }
    return 0;
}