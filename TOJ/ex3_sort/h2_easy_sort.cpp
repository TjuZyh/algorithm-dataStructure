#include <iostream>

using namespace std;

/*
2
3 2 1 3
9 1 4 7 2 5 8 3 6 9
*/

void selectionSort(int arr[], int length)
{
    for (int i = 0; i < length; i++){
        int index = i;
        for (int j = i+1; j < length; j++){
            if (arr[j] < arr[index]){
                index = j;
            }
        }
        if (index == i){
            continue;
        }else{
            int temp;
            temp = arr[index];
            arr[index] = arr[i];
            arr[i] = temp;
        }
    }
}

int main(){
    int m;
    cin >> m;
    while(m--){
        int n ;
        int arr[1010];
        cin >> n;
        for(int i = 0 ; i < n ; i++){
            cin >> arr[i];
        }
        selectionSort(arr , n);
        for(int i = 0 ; i < n-1 ; i++){
            cout << arr[i] << " ";
        }
        cout << arr[n-1] << endl;
    }
    return 0;
}

