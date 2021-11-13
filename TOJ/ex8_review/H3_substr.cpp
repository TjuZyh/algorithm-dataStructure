#include<iostream>
#include<stdio.h>
#include<string.h>
using namespace std;
char a[3000050];
char b[1000050];
int nex[3000050];
int lenA,lenB;
void set_next(){
    int i=0,j=-1;
    nex[0]=-1;
    while(i<lenB){
        if(j==-1||b[i]==b[j]){
            i++; j++;
            nex[i]=j;
        }else{
            j=nex[j];
        }
    }
}
int kmp(){
    int i=0,j=0;
    set_next();
    while(i<lenA){
        if(j==-1||a[i]==b[j]){
            i++;j++;
        }
        else
            j=nex[j];
        if(j==lenB)
            return 1;
    }
    return 0;
}
int main(){
    int n;
    while(cin >> n){
        int ans=0;
        cin >> b;
        lenB = strlen(b);
        for(int w = 2 ; w <= 16 ; w++){
            lenA=0;
            for(int i=1;i<=n;i++){
                int cnt=0;
                int tmp=i;
                int num[100];
                while(tmp){
                    num[cnt++]=tmp%w;
                    tmp/=w;
                }
                for(int j=cnt-1;j>=0;j--){
                    if(num[j]<10)
                        a[lenA++]=num[j]+'0';
                    else a[lenA++]=num[j]-10+'A';
                }
            }
            ans=max(ans,kmp());
            if(ans>0)break;
        }
        if(ans>0)printf("yes\n");
        else printf("no\n");
    }
}