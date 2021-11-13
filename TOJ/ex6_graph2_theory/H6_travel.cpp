#include <iostream>
#include <algorithm>

using namespace std;

const int INF=0x3f3f3f;

/*
6 2 3
1 3 5
1 4 7
2 8 12
3 8 4
4 9 12
9 10 2
1 2
8 9 10
 */

/*floyd算法思想，求至少经过三个城市的最短环*/

//记录最短路径
int dis[1010][1010];
//记录初始各边权值
int map[1010][1010];

void init(){
    for(int i = 0 ; i < 1000 ; i++){
        for(int j = 0 ; j < 1000 ; j++){
            if(i==j){
                map[i][j] = 0;
            }else{
                map[i][j] = INF;
            }
        }
    }
}

void Floyd(){
    for(int i = 0 ; i < 1000 ; i++){
        for(int j = 0 ; j < 1000 ; j++){
            dis[i][j] = map[i][j];
        }
    }
    //floyd插点
    for(int k = 0 ; k < 1000 ; k++){
        for(int i = 0 ; i < 1000 ; i++){
            for(int j = 0 ; j < 1000 ; j++) {
                dis[i][j] = min(dis[i][j] , dis[i][k] + dis[k][j]);
            }
        }

    }
}

int main(){
    int roadNum , connectCityNum , wantCityNum;
    int connectionCity , wantCity;
    cin >> roadNum >> connectCityNum >> wantCityNum;
    int from , to , val;
    init();
    for(int i = 1 ; i <= roadNum ; i++){
        cin >> from >> to >> val;
        if(val < map[from][to]){
            map[from][to] = map[to][from] = val;
        }
    }
    for(int i = 1 ; i <= connectCityNum ; i++){
        cin >> connectionCity;
        map[0][connectionCity] = map[connectionCity][0] = 0;
    }
    Floyd();
    int min = INF;
    for(int i = 1 ; i <= wantCityNum ; i++){
        cin >> wantCity;
        if(dis[0][wantCity] < min){
            min = dis[0][wantCity];
        }
    }
    cout << min << endl;
    return 0;
}

