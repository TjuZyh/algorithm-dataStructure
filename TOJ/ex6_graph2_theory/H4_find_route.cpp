#include <stdio.h>
#include <iostream>
#include <algorithm>

using namespace std;

const int INF=0x3f3f3f;

/*
3 3
1 2 1
2 3 1
1 3 1
3 3
1 2 1
1 2 3
2 3 1
 */

/*floyd算法思想，求至少经过三个城市的最短环*/

int n,m;
//记录最短路径
int dis[101][101];
//记录初始各边权值
int map[101][101];
int ans;

void init(){
    for(int i = 1 ; i <= 100 ; i++){
        for(int j = 1 ; j <= 100 ; j++){
            if(i==j){
                map[i][j] = 0;
            }else{
                map[i][j] = INF;
            }
        }
    }
}

void Floyd(){
    for(int i = 1 ; i <= n ; i++){
        for(int j = 1 ; j <= n ; j++){
            dis[i][j] = map[i][j];
        }
    }
    for(int k = 1 ; k <= n ; k++){
        for(int i = 1 ; i <= n ; i++){
            for(int j = 1; j <= n ; j++){
                if(i != j && j != k && i != k){
                    //最小经过三个城市的最小环的权值和
                    ans = min(dis[i][j] + map[j][k] + map[k][i] , ans);
                }
            }
        }
        //floyd插点
        for(int i = 1 ; i <= n ; i++){
            for(int j = 1 ; j <= n ; j++) {
                dis[i][j] = min(dis[i][j] , dis[i][k] + dis[k][j]);
            }
        }
    }
}
int main(){
    while(scanf("%d %d",&n,&m) != EOF){
        init();
        while(m--){
            int from , to , val;
            cin >> from >> to >> val;
            if(val < map[from][to]){
                map[from][to] = map[to][from] = val;
            }
        }
        ans = INF;
        Floyd();
        if(ans == INF){
            cout << "It's impossible." << endl;
        }else{
            cout << ans << endl;
        }
    }
    return 0;
}