#include <iostream>

using namespace std;

/*
1
4 2
4 2 3
 */

// 快速排序
void quickSort(int arr[], int start, int end)
{
    if (start >= end)
        return;
    int i = start;
    int j = end;
    // 基准数
    int baseVal = arr[start];
    while (i < j)
    {
        // 从右向左找比基准数小的数
        while (i < j && arr[j] >= baseVal)
        {
            j--;
        }
        if (i < j)
        {
            arr[i] = arr[j];
            i++;
        }
        // 从左向右找比基准数大的数
        while (i < j && arr[i] < baseVal)
        {
            i++;
        }
        if (i < j)
        {
            arr[j] = arr[i];
            j--;
        }
    }
    // 把基准数放到i的位置
    arr[i] = baseVal;
    // 递归
    quickSort(arr, start, i - 1);
    quickSort(arr, i + 1, end);
}

int main(){
    int n ;
    cin >> n ;
    while(n--){
        int m ,k;
        int arr[100000];
        cin >> m >> k ;
        int num;
        for(int i = 0 ; i < m-1 ; i++){
            cin >> num;
            num += 1;
            arr[i] = num;
        }

        quickSort(arr , 0 , m-2);
        long sum = 0 ;
        for(int i = 0 ; i < m - k ; i++){
            sum += arr[i];
        }
        for(int i = 0 ; i < k ; i++){
            sum += 1;
        }
        cout << sum << endl;
    }
    return 0;
}

