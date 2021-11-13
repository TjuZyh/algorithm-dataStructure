#include <iostream>
#include <string.h>
#include <stdio.h>

using namespace std;
/*
8 7
0 1
1 2
2 3
3 4
4 5
5 6
6 7
8 8
0 1
1 2
2 3
3 4
4 5
5 6
6 7
7 0
 */

/*算法思想：利用dijkstra算法，判断两点之间的最短距离，如果超过7就不符合六度分离理论*/
const int MAX = 0x3f3f3f3f;
int people[105][105];
int vis[105] , dis[105];
int n , m;
void dijkstra(int t) {
    memset(vis,0,sizeof(vis));
    memset(dis,MAX,sizeof(dis));
    dis[t] = 0;
    for(int l = 0; l < n; l++) {
        int k , tp = MAX;
        for(int i = 0 ; i < n ; i++) {
            if(!vis[i] && dis[i] < tp) {
                tp = dis[i];
                k = i;
            }
        }
        vis[k] = 1;
        for(int j = 0; j < n ; j++) {
            if(!vis[j] && dis[j] > dis[k] + people[k][j]) {
                dis[j] = dis[k] + people[k][j];
            }
        }
    }
}

int main(){
    while(scanf("%d%d", &n , &m)!=EOF) {
        //初始化矩阵
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < n ; j++){
                if(i == j){
                    people[i][j] = 0;
                }else{
                    people[i][j] = MAX;
                }
            }
        }
        int x,y;
        for(int i = 0 ; i < m ; i++) {
            cin >> x >> y;
            people[x][y] = people[y][x] = 1;
        }
        int flag = 1;
        for(int i = 0; i < n; i++) {
            dijkstra(i);
            for(int j = 0; j < n; j++) {
                if(dis[j] > 7)
                    flag = 0;
            }
        }
        if(!flag){
            cout << "No" << endl;
        }else{
            cout << "Yes" << endl;
        }
    }
    return 0;
}
