#include <iostream>
#include <algorithm>

using namespace std;

/*
4 1
1 1 2 3
 */
int n ,c;
int arr[1010];

int main(){
    cin >> n >> c;
    for(int i = 0 ; i < n ; i++){
        cin >> arr[i];
    }
    sort(arr , arr + n);
    int cnt = 0;
    for(int i = 0 ; i < n ; i++){
        for(int j = i + 1 ; j < n ; j++){
            if(arr[j] - arr[i] == 1){
                cnt++;
            }
        }
    }
    cout << cnt << endl;
    return 0;
}
