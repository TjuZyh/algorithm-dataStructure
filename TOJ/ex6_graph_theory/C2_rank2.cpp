#include <iostream>
#include <cstring>
#include <vector>
#include <stdio.h>
using namespace std;

/*
4 3
1 2
2 3
4 3

4 4
1 3
2 4

 */

const int N=510;

int vis[N];

vector<int> relative[N];
int rankQ[N];
int lose[N];
int n,m;
int main(){
    while(scanf("%d%d" , &n , &m) != EOF){
        for(int i = 1 ; i <= n ; ++i){
            relative[i].clear();
        }
        memset(rankQ,0,sizeof(rankQ));
        memset(lose,0,sizeof(lose));
        for(int i = 1 ; i <= m ; ++i){
            int x,y;
            cin >> x >> y;
            relative[x].push_back(y);
            lose[y]++;
        }
        for(int i = 1 ; i <= n ; ++i){
            int k = 1;
            //找出没有输的人
            while(lose[k] != 0){
                k++;
            }
            rankQ[i]=k;
            //排名后将输的次数置为-1，更新lose数组，
            lose[k]=-1;
            for(int j = 0 ; j < relative[k].size() ; ++j)
                lose[relative[k][j]]--;
        }
        for(int i = 1 ; i < n ; ++i)
            cout << rankQ[i] << ' ';
        cout << rankQ[n] << endl;
    }

    return 0;
}


