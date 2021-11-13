#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

/*
yeshowmuchiloveyoumydearmotherreallyicannotbelieveit
yeaphowmuchiloveyoumydearmother
*/

int main() {
    string str1,str2;
    cin >> str1 >> str2;
    if (str1.size()>str2.size())swap(str1,str2);
    int ans = 0;
    for (int i = 0; i < str1.size()-1; ++i) {
        string substr1 = str1.substr(i,2);
        string temp = str2;
        int it = temp.find(substr1);
        while (it!=string::npos){
            string x = str1.substr(i);
            string y = str2.substr(it);
            int findfirst = 0;
            while (findfirst<x.size() && findfirst < y.size() && x[findfirst]==y[findfirst])findfirst++;
            ans = ans < findfirst?findfirst:ans;
            if (it+1>temp.size()) temp = y.substr(it+1);
            else break;
            it = temp.find(substr1);
        }
    }
    cout << ans;
    return 0;
}