#include <iostream>

using namespace std;

/*
fixprefisuffix
 */

int main(){
    string str;
    cin >> str;
    string ans = "fdfdfdfdfdfd";
    int flag = 0;
    for(int i = 1 ; i < str.length() ; i++){
        if(str.substr(0 , i) == str.substr(str.length() - i , str.length())){
            ans = str.substr(0 , i);
            //cout << ans << ans.length() << endl ;
        }
        if(i > ans.length()  && str.substr(i , ans.length()) == ans && (i < str.length() - ans.length() - 1)){
            //cout << i << endl;
            flag = 1;
        }
    }
    if(flag){
        cout << ans << endl;
    }else{
        cout << "Just a legend" << endl;
    }
    return 0;

}

