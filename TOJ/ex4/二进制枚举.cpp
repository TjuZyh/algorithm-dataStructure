#include <iostream>
using namespace std;
int main(){
    int n;
    cin >> n;
    //遍历0～2^n-1个状态，即i的取值有2^n-1个
    for(int i = 1; i < (1<<n); i++){
        cout << "Case " << i << ": ";
        //j代表遍历到进制数的第j位
        //j用于生成第i个状态下枚举出来的子集
        for(int j = 0; j < n; j++){
            //与第i个二进制数进行位运算
            //判断二进制第j位是否存在
            if(i & (1 << j)){
                //如果存在输出j，即该状态下枚举出子集中的元素
                cout << j << " ";
            }
        }
        cout << endl;
    }
    return 0;
}

