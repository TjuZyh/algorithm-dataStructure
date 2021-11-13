#include <iostream>

using namespace std;

//N : Number of friends ; M : Number of case
int M,N;

int info[25];

void init(){
    for(int i = 1 ; i <= N ; i++){
        info[i] = i;
    }
}

int findRoot(int flag){
    int root = flag;
    while (info[root] != root){
        root = info[root];
    }
    return root;
}

void UnionFriend(int x , int y){
    int flagX = findRoot(x);
    int flagY = findRoot(y);
    if(flagX != flagY){
        info[flagX] = flagY;
    }
}

int main(){
    int testCount;
    cin >> testCount;
    while(testCount){
        cin >> N;
        init();
        for(cin>>M ; M>0 ; M--){
            int x,y;
            cin>> x >> y ;
            UnionFriend(x,y);
        }
        int count=0;
        for(int i=1;i<=N;i++)
            if(info[i]==i)
                ++count;
        cout << count;
        testCount--;
    }
    return 0;

}
