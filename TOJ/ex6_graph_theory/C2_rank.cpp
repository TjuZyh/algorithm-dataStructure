#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;

/*
4 3
1 2
2 3
4 3
 */

//队伍的排名
int rankQ[510];
//记录队伍输的次数
int loseCnt[510];
//记录队伍之间的输赢关系
int relation[510][510];
int n,m;
int main(){
    int x,y;
    while(scanf("%d%d",&n,&m) != EOF){
        //初始化数组
        memset(rankQ,0,sizeof(rankQ));
        memset(relation,0,sizeof(relation));
        memset(loseCnt,0,sizeof(loseCnt));
        //根据队伍的关系初始化relation以及loseCnt
        for(int i = 0 ; i < m ; i++){
            cin >> x >> y;
            relation[x][y] = 1;
            loseCnt[y]++;
        }
        int num=0;
        for(int i = 0 ; i < n ; i++){

            for(int j = 1 ; j <= n ; j++){
                if(loseCnt[j]==0){
                    num=j;
                    break;
                }
            }
            loseCnt[num] = -1;
            rankQ[i] = num;
            for(int k = 1 ; k <= n; k++){
                //输过当前队伍的队伍都减一次输的次数
                if(relation[num][k]==1){
                    loseCnt[k]--;
                }
            }
        }

        for(int i = 0 ; i < n-1 ; i++){
            cout << rankQ[i] << " " ;
        }
        cout << rankQ[n-1] << endl;
    }
    return 0;
}


