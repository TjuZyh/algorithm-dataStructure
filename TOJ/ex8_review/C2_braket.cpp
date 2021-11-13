#include <iostream>
#include <stack>

using namespace std;

/*
(2*(x+y)/(1-x)@
 */

int main(){
    string str;
    stack<int> s;
    int flag = 1;
    cin >> str;
    for(int i = 0 ; i < str.length() ; i++){
        if(str[i] == '('){
            s.push(1);
        }else if(str[i] == ')'){
            if(s.empty()){
                flag = 0;
            }else{
                s.pop();
            }
        }else{
            continue;
        }
    }
    if(!s.empty()){
        flag = 0;
    }
    if(flag){
        cout << "YES" << endl;
    }else{
        cout << "NO" << endl;
    }

}

