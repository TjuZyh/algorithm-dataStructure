#include <iostream>
#include <queue>
#include <vector>
#include <string.h>
using namespace std;
/*
8 3
I 1
I 2
I 3
Q
I 5
Q
I 4
Q
 */

//创建小顶堆
priority_queue <int, vector<int> , greater<int>> q;

int main(){
    int n , k;
    char str[5];
    int num;
    cin >> n >> k;
    while(n--){
        cin >> str;
        if(strcmp(str , "I") == 0){
            cin >> num;
            q.push(num);
            //始终保持优先队列中有K个数，队首即为第k个最大的数
            if(q.size() > k){
                q.pop();
            }
        }else if(strcmp(str , "Q") == 0){
            cout << q.top() << endl;
        }
    }
    return 0 ;
}

