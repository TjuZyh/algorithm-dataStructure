#include <iostream>
#include <queue>
#include <algorithm>
#define LL long long
using namespace std;

/*
20 5 3
3 5
5 6
8 7
10 6
15 10
 */

const int maxN = 1e5+32;
struct Bag{
    LL val,cost;
    bool operator <(const Bag& p) const{
        if(val == p.val){
            return cost < p.cost;
        }
        return val < p.val;
    }
}bag[maxN];
LL n,m,v;
int dp1[maxN];
int dp2[maxN];
int main(){
    cin >> v >> n >> m;
    for(int i = 1; i <= n ; i++){
        cin >> bag[i].val >> bag[i].cost;
    }
    sort(bag+1 ,bag+n+1);
    priority_queue<LL> pq;
    if(m % 2){
        LL sum = 0;
        int cnt = m/2;
        for(int i = 1;i<=n;i++){
            dp1[i] = sum;
            pq.push(bag[i].cost);
            sum+=bag[i].cost;
            if(pq.size() > cnt){
                LL tmp = pq.top();
                pq.pop();
                sum -= tmp;
            }
        }
        while(pq.size()){
            pq.pop();
        }
        sum = 0;
        for(int i = n ; i >= 1 ; i--){
            dp2[i] = sum;
            pq.push(bag[i].cost);
            if(pq.size()>cnt){
                LL tmp =  pq.top();
                pq.pop();
                sum -= tmp;
            }
            sum+=bag[i].cost;
        }
        for(int i = n-cnt ; i>cnt ; i--){
            if(dp1[i]+dp2[i]+bag[i].cost<=v){
                cout << bag[i].val <<endl;
                return 0;
            }
        }
    }
    else{
        LL sum = 0;
        int cnt = m/2;
        for(int i = 1;i<=n;i++){
            pq.push(bag[i].cost);
            sum+=bag[i].cost;

            if(pq .size()>cnt){
                LL tmp = pq.top();
                pq.pop();
                sum -= tmp;
            } dp1[i] = sum;
        }
        while(pq.size()) pq.pop();
        sum = 0;
        for(int i = n;i>=1;i--){
            pq.push(bag[i].cost);
            sum+=bag[i].cost;

            if(pq.size()>cnt){
                LL tmp =  pq.top();
                pq.pop();
                sum -= tmp;
            } dp2[i] = sum;
        }
        for(int i = n-cnt;i>=cnt;i--){
            if(dp1[i]+dp2[i+1]<=v){
                cout<<(bag[i].val + bag[i+1].val)/2<<endl;
                return 0;
            }
        }
    }
}


