#include <iostream>

using namespace std;


/*
6 8  5 3  5 2  6 4 5 6  0 0

8 1 7 3  6 2  8 9  7 5 7 4  7 8  7 6  0 0

3 8  6 8  6 4 5 3  5 6  5 2  0 0

-1 -1
 */

const int maxN = 100010;
int parent[maxN];
//由于点是离散的，需要用vis数组标识该点是否是题中的点，因为parent数组初始化会初始全部点
int vis[maxN];

void init(){
    for(int i = 1 ; i <= maxN ; i++){
        parent[i] = i;
        vis[i] = 0;
    }

}

int findRoot(int x){
    if(parent[x] == x){
        return x;
    }else{
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
    int x , y;
    while(cin >> x >> y){
        if(x == -1 && y == -1){
            break;
        }
        //特判
        if(x == 0 && y == 0){
            cout << "Yes" << endl;
            continue;
        }
        init();
        Union(x , y);
        vis[x] = vis[y] = 1;
        int flag = 1;

        while(cin >> x >> y){
            //一组case结束判断
            if(x == 0 && y == 0){
                break;
            }
            if(findRoot(x) == findRoot(y)){
                flag = 0;
            }
            Union(x , y);
            vis[x] = vis[y] = 1;
        }
        int cnt = 0;
        for(int i = 1 ; i <= maxN ;i++){
            if(vis[i]){
                if(parent[i] == i){
                    cnt++;
                }
            }
        }
        if(cnt > 1){
            flag = 0;
        }
        //output
        if(flag){
            cout << "Yes" << endl;
        }else{
            cout << "No" << endl;
        }
    }
    return 0 ;
}

