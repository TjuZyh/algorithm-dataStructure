#include <iostream>
#include <set>
using namespace std;

/*
3
Alice Bob
Smith John
Alice Smith
5
a c
c d
d e
b e
a d
0
 */

/*利用set自动去重，产生冠军条件 ： 全部参加人员 - 失败者  = 1 */

int main(){
    set<string> all;
    set<string> loser;
    string str1,str2;
    int n;
    while(cin>>n&&n){
        //init
        all.clear();
        loser.clear();
        for(int i = 0 ; i < n ; i++){
            cin >> str1 >> str2;
            //全部参赛者
            all.insert(str1);
            all.insert(str2);
            //存储失败者
            loser.insert(str2);
        }
        if(all.size() - loser.size() == 1){
            cout<<"Yes"<<endl;
        }else{
            cout<<"No"<<endl;
        }
    }
    return 0;
}
