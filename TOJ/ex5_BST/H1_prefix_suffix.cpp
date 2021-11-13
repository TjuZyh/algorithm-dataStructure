#include <iostream>
#include <string.h>
using namespace std;

/*
clinton
homer
riemann
marjorie
 */

int main(){
    while(1){
        char str1[50010] , str2[50010];
        memset(str1, 0, sizeof(str1));
        memset(str2, 0, sizeof(str2));
        if (scanf("%s%s",str1,str2) == EOF) break;
        char str1Copy[50010] , str2Copy[50010];
        memset(str1Copy, 0, sizeof(str1Copy));
        memset(str2Copy, 0, sizeof(str2Copy));
        int len1 = strlen(str1) , len2 = strlen(str2);
        int flag = 0 ;
        int cases = 0;

        for(int i = 1 ; i <= min(len1 , len2) ; i++){
            cases++;
            strncpy(str1Copy , str1 , i);
            strncpy(str2Copy , str2+ len2 -i , i);
            if(strcmp(str1Copy , str2Copy) == 0){
                flag = 1;
                cout << str1Copy << " " << i << endl;
                break;
            }
        }
        if(flag == 0)
            cout << "0" <<endl;
    }
    return 0;
}

