#include <iostream>
#include <string.h>
#include <algorithm>
#include <cstdio>

using namespace std;
/*
4
10
20
30
04
5
2
3
4
3
4
6
1
2
5
2
3
2
 */
/*求数组中相同数字出现的次数*/
long long a[3010];

int main(){
    int n;
    while(scanf("%d" , &n) != EOF){
        memset(a , 0 , sizeof(a));
        for(int i = 0 ; i < n ; i++){
            cin >> a[i];
        }
        sort(a , a+n);
        int maxT = 1 , temp ;
        /*2 3 3 4 4*/
        for(int i = 0 ; i < n ; i++){
            //查询当前元素出现的次数
            temp = 1;
            for(int j = i + 1 ; j < n ; j++){
                if(a[i] == a[j]){
                    temp++;
                }else{
                    break;
                }
                if(temp > maxT){
                    maxT = temp;
                }
            }
            /*temp = upper_bound(a,a+n,a[i])-lower_bound(a,a+n,a[i]);
            if(temp > maxT){
                maxT = temp;
            }*/
        }
        cout << maxT << endl;
    }
    return 0;
}