#include<iostream>
#include<stack>

//算法思想：
//数据结构：用栈作为暂存数据栈，用于比对数组中的车序号;用数组存储已到站的车次顺序
//创建一个游标用于遍历数组，一个自增变量c代表当前遍历的车序号
//从1号车(c=1)开始遍历数组，若比对上，则数组的游标后移，车次号加一；若数组当前遍历到数组的位置与栈顶元素相等，则出栈，游标下移；若比对不成功，则将当前车次push入栈，车序号+1；若上述情况未将栈清空，则证明顺序错误
using namespace std;

//已经到站的车次顺序
int ordered[1000];
stack<int> s;

int main()
{
    int n;
    cin >> n ;

    //进行大循环的判断，不为零则进行整组数据的输入
    while(n != 0){
        int m ;
        cin >> m;

        //本组循环是否结束的判断
        //上面的m已经读入了一个字符，则下面读该组剩下的数据
        while(m != 0){
            //c为车序号，j遍历数组游标
            int c = 1, j = 1;
            //将提前读入的字符赋值
            ordered[1] = m;
            //遍历剩余的数据
            for(int i = 2;i <= n ; i++){
                cin >> ordered[i];
            }
            int flag = 1;
            while(j <= n)
            {
                //若匹配，则继续遍历下一个位置
                if(c == ordered[j]){
                    c++;
                    j++;
                    //若栈内不为空，并且栈顶元素与数组当前遍历位置相等则出栈，继续数组游标后移
                }else if(!s.empty() && s.top() == ordered[j]){
                    s.pop();
                    j++;
                    //没有匹配，则将i号车push入栈
                }else if(c <= n){
                    s.push(c);
                    c++;
                }else{
                    flag = 0;
                    break;
                }
            }
            if(flag == 1){
                cout << "Yes" << endl;
            }else{
                cout << "No" << endl;
            }
            cin >> m;
        }
        cin >> n;
        cout << endl;
    }
    return 0;
}

