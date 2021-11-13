#include <stdio.h>
#include <iostream>
#include <string.h>

using namespace std;

/*
5 5
1 2 20
2 3 30
3 4 20
4 5 20
1 5 100
 */

#define MAX 0x3fffffff

const int Max_N = 1010;
int map[Max_N][Max_N];
int low[Max_N];
int vis[Max_N];

int dijkstra(int n){
    memset(vis , 0 , sizeof(vis));
    int min, i, j, k;
    vis[1] = 1;
    for(i = 1; i < n; ++ i){
        min = MAX;
        k = 1;
        for(j = 1; j <= n; ++ j){
            if(!vis[j] && min > low[j]){
                min = low[j];
                k = j;
            }
        }
        vis[k] = 1;
        for(j = 1; j <= n; ++ j){
            if(!vis[j] && low[j] > low[k] + map[k][j]){
                low[j] = low[k] + map[k][j];
            }
        }
    }
    return low[n];
}

int main(){
    int n, m, i, j;
    int x, y, c;
    while(scanf("%d %d", &n, &m)!=EOF){
        for(i = 1; i <= m; i++){
            map[i][i] = 0;
            for(j = 1; j < i; j++){
                map[i][j] = map[j][i] = MAX;
            }
        }
        for(i = 1; i <= n; ++ i){
            cin >> x >> y >> c;
            //可能有多条路，只记录最短的
            if(c < map[x][y])
                map[x][y] = map[y][x] = c;
        }
        for(i = 1; i <= m; ++ i){
            low[i] = map[1][i];
        }
        int ans = dijkstra(m);
        cout << ans << endl;
    }
    return 0 ;
}



