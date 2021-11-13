#include <iostream>
#include <map>

using namespace std;

/*
banana
band
bee
absolute
acm

ba
b
band
abc
 */

/*利用map离散存储单词的全部前缀，直接输出对应前缀即可*/

int main(){
    map<string,int> map;
    string word;
    string question;
    map.clear();
    while(getline(cin,word)){
        int len = word.size();
        if(len == 0) break;
        for(int i = 1 ; i <= len ; i++){
            //离散存储单词的前缀个数
            map[word.substr(0,i)]++;
        }
    }
    while(cin >> question){
        cout << map[question] << endl;
    }
    return 0;

}
