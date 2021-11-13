#include <iostream>
#include <string.h>

using namespace std;

/*
3
BAPC
BAPC
AZA
AZAZAZA
VERDI
AVERDXIVYERDIAN
 */

int main(){
    int n;
    cin >> n;
    while(n--){
        char str1[20010] , str2[2000010];
        memset(str1, 0, sizeof(str1));
        memset(str2, 0, sizeof(str2));
        scanf("%s%s",str1,str2);
        char str2Copy[20010];
        int len1 = strlen(str1) , len2 = strlen(str2);
        int cnt = 0;
        for(int i = 0 ; i < len2 - len1 + 1 ; i++){
            memset(str2Copy, 0, sizeof(str2Copy));
            strncpy(str2Copy , str2+i , len1);
            if(strcmp(str1 , str2Copy) == 0){
                cnt++;
            }
        }
        cout << cnt << endl;
    }
    return 0;
}

