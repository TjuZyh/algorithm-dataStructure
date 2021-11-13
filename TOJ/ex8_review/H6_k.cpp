#include<iostream>
#include<algorithm>

using namespace std;

/*
7 5
10 3 4 2 2 9 8
 */

int vis[100010];
int arr[100010];
int main(){
    int N , K;
    cin >> N >> K;
    int sum = 0;
    int len = 0;
    for(int i = 1 ; i <= K ; i++){
        vis[i] = N;
    }
    for(int i = 1 ; i <= N ; i++){
        cin >> arr[i];
        sum = (sum + arr[i]) % K;
        len = max(len , i-vis[sum]);
        if(vis[sum] == N){
            vis[sum] = i;
        }
    }
    cout << len << endl;
}