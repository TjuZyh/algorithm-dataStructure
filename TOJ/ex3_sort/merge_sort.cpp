#include <iostream>

using namespace std;

//将有二个有序数列a[first...mid]和a[mid+1...last]合并。
void mergeOrderArray(int a[], int first, int mid, int last, int temp[])
{
    //在形参中定义了一个暂存数组temp[]
    int i = first, j = mid + 1;
    int m = mid,   n = last;
    int k = 0;
    //同时遍历两个数组中的记录，将小的记录赋值给temp[]
    while (i <= m && j <= n){
        if (a[i] <= a[j]){
            temp[k++] = a[i++];
        }else{
            temp[k++] = a[j++];
        }
    }
    //如果其中一个数组遍历结束，则将剩余记录赋值给temp[]
    while (i <= m){
        temp[k++] = a[i++];
    }
    while (j <= n){
        temp[k++] = a[j++];
    }
    //将temp[]复制给a[]
    for (i = 0; i < k; i++){
        a[first + i] = temp[i];
    }
}
//递归将序列划分为只有一个元素的子序列, 然后逐次对子序列进行合并
void merge_sort(int a[], int first, int last, int temp[]){
    if (first < last){
        int mid = (first + last) / 2;
        merge_sort(a, first, mid, temp);    //左边有序
        merge_sort(a, mid + 1, last, temp); //右边有序
        mergeOrderArray(a, first, mid, last, temp); //再将二个有序数列合并
    }
}

//再封装一层函数(用户友好度)
void mergeSort(int a[], int n)
{
    //动态数组，申请n个大小为int的内存
    int *p = new int[n];
    merge_sort(a, 0, n - 1, p);
}

int main(){
    int a[9]={2,1,3,8,5,7,4,6,9};
    mergeSort(a,9);
    for(int i=0;i<9;i++){
        cout << a[i] << " ";
    }
    return 0;
}