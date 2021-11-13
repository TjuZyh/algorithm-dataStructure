#include<iostream>
#include<algorithm>
using namespace std;

/*
a
ahat
hat
hatword
hziee
word
 */

/*利用substr分割成两块暴力查找*/
string word[50010] = {};
int n = 1, num = 1;
int tire[50000][30] = {};
int vis[500009] = {};
void insert(string str){
    int len = str.length();
    //初始化根节点
    int nd = 0;
    for(int i = 0; i < len; i++){
        int k = str[i] - 'a';
        //子节点为空
        if (!tire[nd][k]){
            tire[nd][k] = num;
            num++;
        }
        nd = tire[nd][k];
    }
    //结束标识
    vis[nd] = 1;
}
int search(string str){
    int len = str.length();
    int nd = 0;
    for(int i = 0; i < len; i++){
        int k = str[i] - 'a';
        if (!tire[nd][k]){
            return 0;
        }
        nd = tire[nd][k];
    }
    if (vis[nd] == 1){
        return 1;
    }else{
        return 0;
    }
}
int main(){
    while(cin >> word[n]){
        //建立trie树
        insert(word[n]);
        n++;
    }
    for(int i = 1; i <= n; i++){
        for (int j = 1; j < word[i].length(); j++){
            string s1, s2;
            //将单词分割两部分，搜索trie树即可
            s1 = word[i].substr(0, j);
            s2 = word[i].substr(s1.length(), word[i].length()-s1.length());
            if (search(s1) && search(s2)){
                cout << word[i] << endl;
                break;
            }else{
                continue;
            }
        }
    }
    return 0;
}