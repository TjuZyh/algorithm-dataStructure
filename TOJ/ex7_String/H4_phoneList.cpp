#include <iostream>
#include <algorithm>

using namespace std;

/*
2
3
911
97625999
91125426
5
113
12340
123440
12345
98346
 */

int cases;
int num;
string phone[10010];
int flag;

bool cmp(string str1 , string str2){
    int len1 = str1.length();
    int len2 = str2.length();
    return len1 < len2;
}

int main(){
    cin >> cases;
    while(cases--){
        flag = 1;
        cin >> num;
        for(int i = 0 ; i < num ; i++){
            cin >> phone[i];
        }
        sort(phone , phone + num , cmp);
        for(int i = 0 ; i < num ; i++){
            int len = phone[i].length();
            for(int j = i+1 ; j < num ; j++){
                if(phone[j].substr(0 , len) == phone[i]){
                    flag = 0;
                }
            }
        }
        if(flag){
            cout << "YES" << endl;
        }else{
            cout << "NO" << endl;
        }
    }
    return 0;

}