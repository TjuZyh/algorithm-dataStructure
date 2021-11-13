#include <iostream>
#include <algorithm>

using namespace std;

const int INF=0x3f3f3f;
const int maxN = 110;

/*
5 5
1 3 4
4 3 2
1 2 3
5 4 2
3 5 6
 */

/*
    前期变量准备：
        map[][]:用于存储图，临街矩阵
        dis[][]:用于存放floyd遍历后，更新的最小值
 */

//记录最短路径
int dis[maxN][maxN];
//记录初始各边权值
int map[maxN][maxN];
int node , edge;

void init(){
    for(int i = 1 ; i <= node ; i++){
        for(int j = 1 ; j <= node ; j++){
            if(i==j){
                map[i][j] = 0;
            }else{
                map[i][j] = INF;
            }
        }
    }
}

void Floyd(){
    //初始化最短路径数组
    for(int i = 1 ; i <= node ; i++){
        for(int j = 1 ; j <= node ; j++){
            dis[i][j] = map[i][j];
        }
    }
    //遍历k点,进行floyd插点
    for(int k = 1 ; k <= node ; k++){
        for(int i = 1 ; i <= node ; i++){
            for(int j = 1 ; j <= node ; j++) {
                dis[i][j] = min(dis[i][j] , dis[i][k] + dis[k][j]);
            }
        }
    }
}

int main(){
    cin >> node >> edge;
    int x , y , val;
    init();
    for(int i = 1 ; i <= edge ; i++){
        cin >> x >> y >> val;
        if(val < map[x][y]){
            map[x][y] = map[y][x] = val;
        }
    }
    Floyd();
    for(int i = 1 ; i <= node ; i++){
        for(int j = 1 ; j <= node; j++){
            cout << dis[i][j] << " ";
        }
        cout << endl;
    }

}



