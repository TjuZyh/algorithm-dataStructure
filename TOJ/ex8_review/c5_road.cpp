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
    if(parent[x] == x){
        return x;
    }else{
        return parent[x] = findRoot(parent[x]);
    }
}

int main(){
    while(cin >> n >> m){
        init();
        for(int i = 1 ; i <= m ; i++){
            int x , y;
            cin >> x >> y;
            int xRoot = findRoot(x);
            int yRoot = findRoot(y);
            if(xRoot != yRoot){
                parent[xRoot] = yRoot;
            }
        }
        int cnt = 0;
        for(int i = 1 ; i <= n ; i++){
            if(parent[i] == i){
                cnt++;
            }
        }
        cout << cnt-1 << endl;
    }
    return 0;

}

