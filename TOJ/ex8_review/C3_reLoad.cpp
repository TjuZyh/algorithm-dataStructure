#include <iostream>

using namespace std;

/*
4
4 3 2 1
*/

int cnt = 0;
void BubbleSort(int arr[] , int len){
    for(int i = 0 ; i < len ; i++){
        for(int j = 0 ; j < len - i - 1 ; j++){
            if(arr[j] > arr[j + 1]){
                int temp;
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
                cnt++;
            }
        }
    }
}

int main(){
    int n ;
    int arr[10010];
    cin >> n;
    for(int i = 0 ; i < n ; i++){
        cin >> arr[i];
    }

    BubbleSort(arr , n);
    cout << cnt << endl;
    return 0;
}

