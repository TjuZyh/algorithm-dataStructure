#include<iostream>
#include<string.h>
using namespace std;

/*
1
3 4
daababac
 */

int n,nc,sum,tot,ans,m[257];
char s[1000000];
bool hashs[16000005];

int main(){
    int t;
    cin >> t;
    while(t--){
        cin >> n >> nc >> s;
        //将字符转成数字进行存储
        for(int i = 0 ; '\0' != s[i] ; i++){
            if(!m[s[i]])
                m[s[i]]=++tot;
            if(tot == nc) break;
        }
        int len = strlen(s);
        for(int i = 0 ; i <= len - n ; i++){
            sum = 0;
            //基于字符对应的值进行n位子串的数值相加
            for(int j = 0 ; j < n ; j++){
                sum = sum * nc + m[s[i+j]] - 1;
            }
            //数值不存在则子串数++
            if(!hashs[sum])
                hashs[sum] = true , ans++;
        }
        cout << ans;
    }
    return 0;
}