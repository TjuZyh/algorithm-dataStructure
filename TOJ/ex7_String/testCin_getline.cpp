#include <iostream>

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

/*
 * 注意cin与getline的区别
 *      cin读取规则：从第一个非空白字符开始到下一个空白字符结束
 *          所以cin不会读取一个含有空格的整体字符串
 *      getline读取规则：可以读空格，直接读一行数据
 * */

int main(){
    string str1;
    string str2;
    while(getline(cin , str1)){
        if(!str1.length()){
            break;
        }
        cout << str1 << " ";
    }
    cout << endl;
    cout << "str2 : " << endl;
    while(cin >> str2){
        cout << str2 << " ";
    }
    return 0;

}

