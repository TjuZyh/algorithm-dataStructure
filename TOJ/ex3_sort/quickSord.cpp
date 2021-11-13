#include <iostream>

using namespace std;

void quickSort(int arr[], int low, int high){
    if (low >= high){
        return;
    }
    int i = low;
    int j = high;
    //基准数，一般初始化为第一个记录
    int baseVal = arr[low];
    //当i >= j 时结束本次遍历交换
    while (i < j){
        //从右向左找比基准数小的数
        while (i < j && arr[j] >= baseVal){
            j--;
        }
        if (i < j){
            arr[i] = arr[j];
            i++;
        }
        // 从左向右找比基准数大的数
        while (i < j && arr[i] < baseVal){
            i++;
        }
        if (i < j){
            arr[j] = arr[i];
            j--;
        }
    }
    //把基准数放到i的位置
    arr[i] = baseVal;
    //递归剩余的序列
    quickSort(arr, low, i - 1);
    quickSort(arr, i + 1, high);
}

int main(){
    int arr[] = {30,40,60,10,20,50};
    int len = sizeof(arr)/sizeof(arr[0]);
    quickSort(arr , 0 , len -1);
    for(int i = 0 ; i < 6 ; i++){
        cout << arr[i] << " ";
    }
    return 0;
}

