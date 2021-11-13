#include <stdio.h>
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

bool ans = false;
char str[1000][1000];
int vis[1000];
int t = 0;
void dfs(char curStr) {
    if(curStr == 'm'){
        ans = true;
    }else {
        for(int i = 0 ; i < t ; i++) {
            //匹配词首字符
            if(str[i][0] == curStr && vis[i] == 0){
                vis[i] = 1;
                int len = strlen(str[i]);
                //继续搜索词末字符
                dfs(str[i][len-1]);
            }
        }
    }
}

int main() {
    while(scanf("%s",str[t++]) != EOF) {
        memset(vis,0,sizeof(vis));
        if(str[t-1][0]=='0') {
            dfs('b');
            if(ans){
                cout << "Yes" << endl;
            }else{
                cout << "No" << endl;
            }
        }
    }
    return 0;
}