#include <iostream>
#include <stack>
#include <string.h>
using namespace std;

/*
4
()
((((
(())
)(()))()
 */

int main(){
    int T;
    char str[11];
    stack<char> s;
    cin >> T;
    while(T--){
        //注意清空栈
        while(!s.empty()){
            s.pop();
        }
        cin >> str;
        int len = strlen(str);
        int sum = 0;
        for(int i = 0 ; i < len ; i++){
            if(str[i] == '('){
                s.push(i);
            }else if(str[i] == ')'){
                if(!s.empty()){
                    s.pop();
                    sum++;
                }
            }
        }
        cout << sum << endl;
    }
    return 0;
}

