#include <iostream>

using namespace std;

/*
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
 */

int n , m;
int parent[1010];

void init(){
    for(int i = 1 ; i <= n ; i++){
        parent[i] = i;
    }
}

int findRoot(int x){
    if(parent[x] = x){
        return x;
    }else{
        //路径压缩
        return parent[x] = findRoot(parent[x]);
    }
}

void Union(int x , int y){
    int Rx = findRoot(x);
    int Ry = findRoot(y);
    if(Rx != Ry){
        parent[Rx] = Ry;
    }
}


int main(){
    int x ,y;
    cin >> n;
    while(n != 0){
        cin >> m;
        init();
        for(int i = 1 ; i <= m ; i++){
            cin >> x >> y;
            Union(x , y);
        }
        int cnt = 0;
        for(int i = 1 ; i <= n ; i++){
            if(parent[i] == i){
                cnt++;
            }
        }
        cout << cnt-1 <<endl;
        cin >> n ;
    }
    return 0;
}

