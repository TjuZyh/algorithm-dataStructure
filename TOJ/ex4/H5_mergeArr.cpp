#include <iostream>
#include <string.h>

using namespace std;
/*
2
2 2
1 2
3 4
3 2
3 4 5
1 4
*/

void mergeArr(int a[] , int a_len, int b[] ,int b_len, int temp[]){
    //在形参中定义了一个暂存数组temp[]
    int i = 0, j = 0;
    int k = 0;
    //同时遍历两个数组中的记录，将小的记录赋值给temp[]
    while (i < a_len && j < b_len){
        if (a[i] < b[j]){
            temp[k++] = a[i++];
        }else{
            temp[k++] = b[j++];
        }
    }
    //如果其中一个数组遍历结束，则将剩余记录赋值给temp[]
    while (i < a_len){
        temp[k++] = a[i++];
    }
    while (j < b_len){
        temp[k++] = b[j++];
    }
}

int main(){
    int cases;
    cin >> cases;
    while(cases--){
        int m , n;
        cin >> m >> n;
        int a[1010] , b[1010];
        memset(a , 0 , sizeof(a));
        memset(b , 0 , sizeof(b));
        for(int i = 0 ; i < m ; i++){
            cin >> a[i];
        }
        for(int j = 0 ; j < n ; j++){
            cin >> b[j];
        }
        int p[1010];
        memset(p , 0 , sizeof(p));

        mergeArr(a ,m ,b ,n ,p);

        for(int i = 0 ; i < m+n-1 ; i++){
            cout << p[i] << " ";
        }
        cout << p[m+n-1] << endl;
    }
    return 0;
}

