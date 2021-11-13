#include <iostream>
#include <algorithm>

using namespace std;

/*
3
13 312 343
 */

/*重构cmp，str1 + str2 > str2 + str1*/
bool cmp(string str1 , string str2){
    return str1 + str2 > str2 + str1;
}

int main(){
    int n ;
    string str[110];
    cin >> n;
    for(int i = 0 ; i < n ; i++){
        cin >> str[i];
    }
    sort(str , str + n , cmp);
    string ans;
    for(int i = 0; i < n ; i++){
        ans += str[i];
    }
    cout << ans << endl;
    return 0;

}

