#include <iostream>
#include <stack>
#include <queue>
#include <string.h>
/*
2
4
push 1
push 3
pop
push 5
1
pop
*/
using namespace std;
queue<int> q;
stack<int> s;
int main() {
    int cases;
    char opt[10];
    int num;
    cin >> cases;
    while(cases--){
        int t;
        int len = 0;
        int flag = 1;
        cin >> t;
        while(t--){
            cin >> opt;
            if(strcmp(opt , "push") == 0){
                cin >> num;
                q.push(num);
                s.push(num);
                len++;
            }else if(strcmp(opt , "pop") == 0){
                if(q.empty() || s.empty()){
                    flag = 0;
                }
                if(!q.empty()){
                    q.pop();
                }
                if(!s.empty()){
                    s.pop();
                }
                len--;
            }
        }
        //输出栈内元素以及队列元素
        if(flag){
            for(int i = 1 ; i <= len-1 ; i++){
                cout << q.front() << " ";
                q.pop();
            }
            cout << q.front() << endl;
            q.pop();
            //对栈进行处理
            int arr[160];

            for(int i = 1 ; i <= len ; i++){
                arr[i] = s.top();
                s.pop();
            }
            for(int i = len ; i >= 2 ; i--){
                cout << arr[i] << " ";
            }
            cout << arr[1] << endl;

        }else{
            cout << "error" << endl;
            cout << "error" << endl;
        }
    }
    return 0;
}
