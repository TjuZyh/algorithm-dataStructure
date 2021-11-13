#include<stdio.h>
#include<iostream>
#include<string.h>
using namespace std;
const int maxn = 1e4+5;

int trie[maxn][26],sum[maxn],cnt;
char words[maxn][25],str[25];
void insert() {
    int len=strlen(str),root=0;
    for(int i=0; i<len; i++) {
        int id=str[i]-'a';
        if(!trie[root][id]) trie[root][id]=++cnt;
        sum[trie[root][id]]++;
        root=trie[root][id];
    }
}
void search() {
    string ss="";
    int len=strlen(str),root=0;
    for(int i=0; i<len; i++) {
        int id=str[i]-'a';
        root=trie[root][id];
        if(sum[root]!=1) ss+=str[i];
        else {
            ss+=str[i];
            cout<<str<<" "<<ss<<endl;
            return;
        }
    }
    cout<<str<<" "<<ss<<endl;
    return;
}
int main() {
    int cnt=0;
    while(~scanf("%s",words[cnt])) {
        int len=strlen(words[cnt]);
        for(int i=0; i<=len; i++)
            str[i]=words[cnt][i];
        cnt++;
        insert();
    }
    for(int i=0; i<cnt; i++) {
        int len=strlen(words[i]);
        for(int j=0; j<=len; j++)
            str[j]=words[i][j];
        search();
    }
    return 0;
}