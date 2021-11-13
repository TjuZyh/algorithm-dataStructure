#include <iostream>
#include <algorithm>

using namespace std;

/*
7
1 3 5 7 9 11 6
 */
int main(){
    int n;
    int arr[1010];
    cin >> n;
    for(int i = 0 ; i < n ; i++){
        cin >> arr[i];
    }
    for(int i = 1 ; i <= n ;){
        sort(arr , arr + i);
        cout << arr[i/2] << endl;
        i += 2;
    }
    return 0;

}

