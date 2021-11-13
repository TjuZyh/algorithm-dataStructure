#include <iostream>

using namespace std;

/*
3 3 -4 2
4 0 1 2 -3
4 1 2 3 -4
0
*/

bool cmp(int a , int b){
    if(a <= 0 && b <= 0){
        return -a > -b;
    }else if(a <= 0 && b >= 0){
        return -a > b;
    }else if(a >= 0 && b <= 0){
        return a > -b;
    }else {
        return a > b;
    }
}

int main(){
    int n;
    int arr[11];
    cin >> n;
    while(n != 0){
        for(int i = 0 ; i < n ; i++){
            cin >> arr[i];
        }
        sort(arr , arr + n , cmp);
        for(int i = 0 ; i < n ; i++){
            cout << arr[i] << " ";
        }
        cout << endl;
        cin >> n;
    }
    return 0;

}

