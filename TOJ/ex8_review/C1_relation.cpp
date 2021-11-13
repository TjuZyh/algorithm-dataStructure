#include <iostream>

using namespace std;

/*
6 5 3
1 2
1 5
3 4
5 2
1 3
1 4
2 3
5 6
 */
int parent[5010];
int n , m , p;

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


int main() {
    cin >> n >> m >> p;
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
    for(int i = 1 ; i <= p ; i++){
        int a , b;
        cin >> a >> b;
        if(findRoot(a) == findRoot(b)){
            cout << "Yes" << endl;
        }else{
            cout << "No" << endl;
        }
    }
    return 0;
}
