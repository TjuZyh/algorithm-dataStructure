#include <iostream>
#include <stack>
#include <queue>
#include <string.h>


using namespace std;

/*
 * FIFO:代表队列 FILO：代表栈
 * */

stack<int> s;
queue<int> q;

int main() {
    int cases;
    int eachCases;
    cin >> cases;
    char operate[10];
    char type[10];
    int num;

    for(int i = 1 ; i <= cases ; i++){
        cin >> eachCases >> type;
        //判断是队列
        if(strcmp(type , "FIFO") == 0){
            for(int i = 1 ; i <= eachCases ; i++){
                cin >> operate;
                if(strcmp(operate,"IN") == 0){
                    cin >> num;
                    q.push(num);
                }else if(strcmp(operate,"OUT") == 0){
                    if(q.empty()){
                        cout << "None" << endl;
                    }else{
                        cout << q.front() << endl;
                        q.pop();
                    }
                }
            }
        }else if(strcmp(type , "FILO") == 0){//判断是栈
            for(int i = 1 ; i <= eachCases ; i++){
                cin >> operate;
                if(strcmp(operate,"IN") == 0){
                    cin >> num;
                    s.push(num);
                }else if(strcmp(operate,"OUT") == 0){
                    if(s.empty()){
                        cout << "None" << endl;
                    }else{
                        cout << s.top() << endl;
                        s.pop();
                    }
                }
            }

        }
    }

    return 0;
}
