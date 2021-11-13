#include <iostream>
#include <string.h>

using namespace std;

/*
2
11
1 2 18 3 3 19 2 3 6 5 4
6
1 2 3 4 5 6
 */

int main(){
    int cases , n ;
    int num;
    int arr[1010];
    int hash[1010];
    cin >> cases;
    while(cases--){
        cin >> n;
        memset(hash , 0 , sizeof(hash));
        int k = 0;
        for(int i = 0 ; i < n ; i++){
            cin >> num;
            hash[num]++;
            if(hash[num] == 1){
                arr[k++] = num;
            }
        }
        for(int i = 0 ; i < k ; i++){
            cout << arr[i] << " ";
        }

    }

}

