#include <stdio.h>
#include <iostream>
#include <string.h>

using namespace std;

/*
4
0 4 9 21
4 0 8 17
9 8 0 16
21 17 16 0
 */
const int MAX_N = 110;
const int inf = 0x7fffffff;
//构造邻接矩阵
int map[MAX_N][MAX_N];
//low数组:保存与已加入树中的顶点相连的边
int low[MAX_N];
//记录该顶点是否已加入树中
int visit[MAX_N];
int n;

int prim(){
    int pos,Min,result=0;
    memset(visit,0,sizeof(visit));
    //首先找的是1这个顶点，加入图中
    visit[1] = 1 , pos = 1;
    for(int i = 1 ; i <= n ; i++){
        if(i != pos){
            //与1顶点相连的边地权值
            low[i] = map[pos][i];
        }
    }
    //每次加入一条边，n个顶点加入n-1条边，循环n-1次就可以了
    for(int i = 1; i < n ; i++){
        Min = inf;
        for(int j = 1 ; j <= n ; j++){
            if(!visit[j] && Min > low[j]){
                Min = low[j];//Min找到的是与已加入图中的顶点相连的边的最小值
                pos = j;//该顶点为j
            }
        }
        result += Min;//加上最小边
        visit[pos] = 1;//新的顶点位置
        for(int j = 1 ; j <= n ; j++)
            if(!visit[j] && low[j] > map[pos][j])
                low[j]=map[pos][j];//更新low[]值，新的与图中已有的点相连的边，如果比原来小的，就更新
    }
    return result;
}

int main(){
    while(scanf("%d",&n) != EOF){
        for(int i = 1 ; i <= n ; i++){
            for(int j = 1 ; j <= n ; j++){
                cin >> map[i][j];
                map[j][i] = map[i][j];
            }
        }
        int MinR = prim();
        cout << MinR << endl;
    }
    return 0;
}