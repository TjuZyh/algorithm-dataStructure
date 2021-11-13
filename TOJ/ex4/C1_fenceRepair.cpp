#include<iostream>
#include<algorithm>
#include<queue>
#include<vector>

using namespace std;

/*
3
8
5
8
 */

int main(){
    int n , l;
    int sum=0;
    cin >> n ;
    //定义有限数组， 小顶堆
    priority_queue<int, vector<int>, greater<int> > queue;
    for (int i = 0 ; i < n ; i++){
        cin >> l;
        queue.push(l);
    }

    while(queue.size() > 1){
        int l1 , l2;
        l1 = queue.top();
        queue.pop();
        l2 = queue.top();
        queue.pop();

        sum += l1 + l2;
        queue.push(l1 + l2);
    }
    cout << sum << endl;
    return 0;
}