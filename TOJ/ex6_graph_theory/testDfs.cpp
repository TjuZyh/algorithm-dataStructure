#include <iostream>
#include <string.h>

using namespace std;

/*
so
soon
river
goes
them
got
moon
begin
big
0
 */
string str[110];
int t = 0;
int vis[110];
int flag = 0;

void dfs(char findStr){
    if(findStr == 'm'){
        flag = 1;
    }else{
        for(int i = 0 ; i < t-1 ; i++){
            if(str[i][0] == findStr && vis[i] == 0){
                vis[i] = 1;
                dfs(str[i][str[i].length()-1]);
            }
        }
    }
}

int main(){
    while(cin >> str[t++]){
        memset(vis , 0 , sizeof(vis));
        if(str[t-1][0] == '0'){
            dfs('b');
            if(flag){
                cout << "Yes" << endl;
            }else{
                cout << "No" << endl;
            }
        }
    }


}

