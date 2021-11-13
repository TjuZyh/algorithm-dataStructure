#include <iostream>

using namespace std;

/*
3 3 1 2
1 2 3
2 3 4
1 3 5
 */
const int MAX = 99999999;
int map[1010][1010];
int dis[1010][1010];

int n , m , a , b;
int from , to , val;

void init(){
    for(int i = 1 ; i <= n ; i++){
        for(int j = 1 ; j <= n ; j++){
            if(i == j){
                map[i][j] = 0 ;
            }else{
                map[i][j] = MAX;
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
            for(int j = 1 ; j <= n ; j++){
                dis[i][j] = min(dis[i][j] , dis[i][k] + dis[k][j]);
            }
        }
    }

}

int main(){
    cin >> n >> m >> a >> b;
    init();
    for(int i = 1 ; i <= m ; i++){
        cin >> from >> to >> val;
        if(val < map[from][to]){
            map[from][to] = val;
        }
    }
    Floyd();
    cout << dis[a][b] << endl;
    return 0;
}

