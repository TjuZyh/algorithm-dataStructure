#include <iostream>
#include <cstring>
#include <vector>
#include <stdio.h>
using namespace std;

/*
2 1
1 2
2 2
1 2
2 1
 */

const int N=10010;


vector<int> relative[N];
int rankQ[N];
int lessQ[N];
int n,m;
int flag = 1;

int main(){
    while(scanf("%d%d" , &n , &m) != EOF){
        for(int i = 1 ; i <= n ; ++i){
            relative[i].clear();
        }
        memset(rankQ,0,sizeof(rankQ));
        memset(lessQ,0,sizeof(lessQ));
        for(int i = 1 ; i <= m ; ++i){
            int x,y;
            cin >> x >> y;
            relative[x].push_back(y);
            lessQ[y]++;
        }
        for(int i = 1 ; i <= n ; ++i){
            int cnt = 0;
            for(int i = 1 ; i <= n ; i++){
                if(lessQ[i] == 0){
                    cnt ++;
                }
                if(cnt > 1){
                    flag = 0;
                }
            }

            int k = 1;
            while(lessQ[k] != 0){
                k++;
            }
            //数组中没有0出现
            if(k == n+1){
                flag = 0;
            }
            rankQ[i]=k;
            lessQ[k] = -1;
            for(int j = 0 ; j < relative[k].size() ; ++j)
                lessQ[relative[k][j]]--;
        }
        if(flag == 0){
            cout << "-1" << endl;
        }else{
            int moneyForOne = 888;
            int total;
            for(int i = 1 ; i <= n ; ++i){
                total += moneyForOne;
                moneyForOne++;
            }
            cout << total << endl;
        }
    }
    return 0;
}


