#include <iostream>

using namespace std;
int n;
//f[i]表示i个数的全部可能性
int f[20];

/*
 * 设x为当前出栈序列的最后一个，则x有n种取值由于x是最后一个出栈的，所以可以将已经出栈的数分成两部分
    1、比x小
    2、比x大
 * 比x小的数有x-1个，所以这些数的全部出栈可能为f[x-1]，比x大的数有n-x个，所以这些数的全部出栈可能为f[n-x]，
 * 一个x的取值能够得到的所有可能性为f[x-1] * f[n-x]
 *
 * 递推公式：ans = f[0]*f[n-1] + f[1]*f[n-2] + ... + f[n-1]*f[0];
 * */

int main()
{
    //递推实现卡特兰数
    cin >> n;
    f[0] = 1, f[1] = 1;
    for(int i=2; i<=n; i++)
        for(int j=0; j<i; j++)
            //递推公式
            f[i] += f[j] * f[i-j-1];
    cout << f[n] << endl;
    return 0;
}