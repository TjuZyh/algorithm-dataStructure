#include <iostream>
#include <queue>
#include <vector>
#include <string.h>
using namespace std;
/*
8
I 1
I 2
I 3
Q 3
I 5
Q 3
I 4
Q 3
 */

//创建小顶堆
priority_queue <int, vector<int> , greater<int>> q;

int main(){
    int n , k;
    char str[5];
    int num;
    cin >> n;
    while(n--){
        cin >> str;
        if(strcmp(str , "I") == 0){
            cin >> num;
            q.push(num);
        }else if(strcmp(str , "Q") == 0){
            cin >> k;
            //始终保持优先队列中有K个数，队首即为第k个最大的数
            while(q.size() > k){
                q.pop();
            }
            cout << q.top() << endl;
        }
    }
    return 0 ;
}



