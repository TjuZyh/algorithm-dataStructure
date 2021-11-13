#include <iostream>
using namespace std;
int father[2010];

//找根节点并把寻找距离压缩到三层以内
int findRoot(int x){
    //while中条件判定何时结束剪枝，即挂到二层节点以及三层节点就停止
    while(father[x]!=father[father[x]] && father[father[father[x]]]!=father[father[x]]){
        father[x] = father[father[father[x]]];
    }
    return father[father[x]];
}

int main(){
    ios::sync_with_stdio(0);
    int cases;
    int output = 1;
    cin >> cases;
    while (cases--){
        for (int i = 0; i < 2010; ++i) {father[i] = i;}
        bool flag = true;
        int n ,m;
        cin >> n >> m;
        for (int i = 0; i < m; ++i) {
            int a, b;
            cin >> a >> b;
            int x = findRoot(a);
            int y = findRoot(b);
            if (x!=y) {
                father[b] = a;
            }
                //不同层：如果a在第一层并且b在第三层 如果a在第一层并且b在第三层
            else if((father[a] == a && father[b]!=a) || (father[b] == b && father[a]!=b)  ){
                flag = false;
            }
                //同层：如果都在第二层 、 如果都在第三层
            else if((father[a]==y && father[b]==y && a!=y && b!=y)||(father[a]!=y && father[b]!=y)){
                flag = false;
            }
        }
        if (flag){
            cout << "Scenario #"<< output++<<":\n"
                 <<"No suspicious bugs found!\n" << endl;
        } else{
            cout << "Scenario #"<< output++ <<":\n"
                 << "Suspicious bugs found!\n" << endl;
        }
    }
    return 0;
}