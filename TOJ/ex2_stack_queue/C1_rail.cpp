#include <iostream>
#include <stack>

using namespace std;

/*
5
1 2 3 4 5
5 4 1 2 3
0
6
6 5 4 3 2 1
0
0
 */

int ordered[1010];
stack<int> s;

int main(){
    int n;
    cin >> n;

    while(n != 0){
        int m;
        cin >> m;
        while(m != 0){
            //c为车序号，j遍历数组游标
            int c = 1 , j = 1;
            ordered[1] = m;
            for(int i = 2 ; i <= n ; i++){
                cin >> ordered[i];
            }
            int flag = 1;

            while(j <= n){
                if(c == ordered[j]){
                    j++;
                    c++;
                }else if(!s.empty() && s.top() == ordered[j]){
                    s.pop();
                    j++;
                }else if(c <= n){
                    s.push(c);
                    c++;
                }else{
                    flag = 0;
                    break;
                }
            }
            if(flag == 1){
                cout << "Yes" << endl;
            }else{
                cout << "No" << endl;
            }
            cin >> m;
        }
        cin >> n;
        cout << endl;
    }
    return 0;
}
