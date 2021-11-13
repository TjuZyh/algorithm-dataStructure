#include <iostream>
#include <queue>

using namespace std;

/*
GET
PUT msg1 10 5
PUT msg2 10 4
GET
GET
GET
 */

/*对优先队列的优先级进行重载,按照指令输出即可*/

struct MInfo{
    string info;
    int value , pre , id;
    friend bool operator < (MInfo info1 , MInfo info2){
        if(info1.pre != info2.pre){
            return info1.pre > info2.pre;
        }else{
            return info1.id > info2.id;
        }
    }
};

priority_queue<MInfo> pq;

int main(){
    string op;
    MInfo mInfo;
    int id = 0;
    while(cin >> op){
        if(op == "PUT"){
            cin >> mInfo.info >> mInfo.value >> mInfo.pre;
            mInfo.id = ++id;
            pq.push(mInfo);
        }else{
            if(pq.empty()){
                cout << "EMPTY QUEUE!" << endl;
            }else{
                cout << pq.top().info << " " << pq.top().value << endl;
                pq.pop();
            }
        }
    }
    return 0;
}

