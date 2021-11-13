#include <vector>
#include <algorithm>
#include <string>
#include <iostream>
using namespace std;

int main(){

    string n;
    while (cin >> n){
        string input;

        getchar();
        int p = 0;
        getline(cin,input);

        transform(n.begin(),n.end(),n.begin(),::tolower);

        for (int i = 0; i < input.size(); ++i) {
            if (input[i]>='A' && input[i]<='Z'){
                input[i] = input[i] + 'a' - 'A';
            }
        }

        int location = -1;
        int times = 0;
        while (p<input.size()){
            int first,last;
            while (p<input.size() && input[p]==' ')p++;
            first = p;
            while (p<input.size() && input[p]!=' ')p++;
            last = p;
            string word = input.substr(first,last-first);
            transform(word.begin(),word.end(),word.begin(),::tolower);
            if (word == n){
                if (location==-1)location = first;
                times++;
                //cout << times << endl;

            }

        }
        if (location!=-1){
            cout << times << " " <<location << endl ;
        }else cout << "-1" << endl;
        cout << endl;

    }


    return 0;
}
