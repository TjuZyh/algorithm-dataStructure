#include <iostream>

using namespace std;

/*
3 3 -4 2
4 0 1 2 -3
0
*/

struct Arr{
    //原值
    int a;
    //绝对值
    int b;
};


void BubbleSort(Arr arr[] , int len){
    for(int i = 0 ; i < len ; i++){
        for(int j = 0 ; j < len - i - 1 ; j++){
            if(arr[j].b < arr[j+1].b){
                Arr temp;
                temp = arr[j+1];
                arr[j+1] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

int main(){
    int m ;
    int n;
    cin >> m;
    while(m != 0){
        Arr arr[110];
        //初始化结构体数组
        for(int i = 0 ; i < m ; i++){
            arr[i].a = 0;
            arr[i].b = 0;
        }
        //将数据存入数组
        for(int i = 0 ; i < m ; i++){
            cin >> n;
            //本身值
            arr[i].a = n;
            if(n < 0){
                n = -n;
            }
            //绝对值
            arr[i].b = n;
        }

        BubbleSort(arr , m);
        for(int i = 0 ; i < m-1 ; i++){
            cout << arr[i].a << " " ;
        }
        cout << arr[m-1].a << endl;
        cin >> m;
    }
}
