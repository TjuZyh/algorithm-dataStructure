#include <iostream>
#include <string.h>
#include <algorithm>

using namespace std;

/*
3
0 990 692
990 0 179
692 179 0
1
1 2
 */
/*并查集 + 最小生成树*/
struct Road{
    int start;
    int end;
    int value;
};
Road road[10010];
int parent[110];

void init(){
    for(int i = 1 ; i <= 110 ; i++){
        parent[i] = i;
    }
}

int findRoot(int x){
    if(x == parent[x]){
        return x;
    }else{
        return findRoot(parent[x]);
    }
}

void unionRoad(int road1 , int road2){
    int root1 = findRoot(road1);
    int root2 = findRoot(road2);
    parent[root1] = root2;
}

bool sameRoot(int road1 , int road2){
    return findRoot(road1) == findRoot(road2);
}

bool cmp(Road road1 , Road road2){
    return road1.value < road2.value;
}

int main(){
    int village , value;
    int roadNo = 1;
    cin >> village;
    for(int i = 1 ; i <= village ; i++){
        for(int j = 1 ; j <= village ; j++){
            cin >> value;
            road[roadNo].start = i;
            road[roadNo].end = j;
            road[roadNo].value = value;
            roadNo++;
        }
    }

    init();
    sort(road + 1 , road + roadNo + 1 , cmp);

    //合并已有道路
    int connectionNum = village;
    int relationNum;
    int a , b;
    cin >> relationNum;
    for(int i = 1 ; i <= relationNum; i++){
        cin >> a >> b;
        //不连通
        if(!sameRoot(a , b)){
            unionRoad(a , b);
            connectionNum--;
        }
    }

    int len = 0;
    for(int i = 1 ; connectionNum > 1 && i <= roadNo ; i++){
        a = road[i].start;
        b = road[i].end;
        //不为一个连通分量，并且未修建道路
        if(!sameRoot(a,b)){
            len += road[i].value;
            unionRoad(a,b);
            connectionNum--;
        }
    }
    cout << len << endl;
}

