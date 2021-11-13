#include <iostream>
#include <algorithm>
#include <map>
using namespace std;
/*
1
3 3 2
1 1 1
2 2 2
5
3 1 1
1 1 2
2 1 2
3 1 1
3 2 2
 */
int main(){
    int cases;
    int n,m,k;
    int Q;
    int cas=1,lc,lr,x,y;
    int a,b,c;
    cin >> cases;
    while(cases--){
        cin >> n >> m >> k;
        lc = lr = 0;
        map<int,map<int,int> > mat;
        map<int,int> row,col;
        for(int i = 0 ; i < k ; i++){
            cin >> a >> b >> c;
            if(!row[a]){
                row[a]=++lr;
                x=lr;
            }else{
                x=row[a];
            }
            if(!col[b]){
                col[b]=++lc;
                y=lc;
            }else{
                y=col[b];
            }
            mat[x][y]=c;
        }
        cin >> Q;
        cout << "Case #" << cas++ << ":" << endl;
        while(Q--){
            cin >> a >> b >> c;
            if(a==1)
                swap(row[b],row[c]);
            else if(a==2)
                swap(col[b],col[c]);
            else if(a==3)
                cout << mat[row[b]][row[c]] << endl;
        }
    }
    return 0;
}