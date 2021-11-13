#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string.h>
using namespace std;

/*
4 4
1 2 3 4
4 5
5 3 6 4
 */

int N,M;
int num[3005];
//N*(N-1)/2
int tmp[5000000];
//从大到小排序
bool cmp(int x,int y){
    return x>y;
}
int main(){
    while(scanf("%d%d",&N,&M)!=EOF){
        memset(num,0,sizeof(num));
        memset(tmp,0,sizeof(tmp));
        for(int i = 0 ; i < N ; i++){
            cin >> num[i];
        }
        int t = 0;
        for(int i = 0 ; i < N ; i++)
            //存放两两相加的和
            for(int j = i+1 ; j < N ; j++){
                tmp[t++]=(num[i]+num[j]);
            }
        sort(tmp,tmp + t,cmp);
        for(int i = 0 ; i < M-1 ; i++){
            cout << tmp[i] << " ";
        }
        cout << tmp[M-1] << endl;
    }
    return 0;
}


