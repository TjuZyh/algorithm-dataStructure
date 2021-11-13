#include <iostream>

using namespace std;

/*
5 8
1 2 3
1 3 7
2 3 10
2 4 4
2 5 8
3 4 6
3 5 2
4 5 17
 */
const int MAX_N = 1001;
int map[MAX_N][MAX_N];
int low[MAX_N];
int visit[MAX_N];
int cnt, N, M;

int Prim(){
    int max, k;
    for(int i = 1; i <= N; i ++){
        low[i] = map[1][i];
        visit[i] = 0;
    }
    low[1] = 0;
    visit[1] = 1;
    for(int i = 1; i < N; i ++){
        k = -1;
        max = 0;
        for(int j = 1; j <= N; j ++){
            if(visit[j] == 0 && low[j] > max){
                max = low[k = j];
            }
        }
        if(k == -1){
            return -1;
        }
        visit[k] = 1;
        cnt += max;
        for(int j = 1; j <= N; j ++){
            if(visit[j] == 0 && low[j] < map[k][j]){
                low[j] = map[k][j];
            }
        }
    }
    return cnt;
}

int main(){
    int x, y, c;
    cin >> N >> M;
    for(int i = 0; i < M; i ++){
        cin >> x >> y >> c;
        if(c > map[x][y]){
            map[x][y] = map[y][x] = c;
        }
    }
    int maxCost = Prim();
    cout << maxCost << endl;
    return 0;
}

