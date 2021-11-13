# include <iostream>
# include <string.h>
# include <stdio.h>
# include <stack>
# include <stdlib.h>

using namespace std;
/*
 * 算法思路：
 *      1、读取一行字符串，去除空格后遍历该字符串数组，
 *          若遇到数字则将其暂存到数组中；
 *          若遇到符号，则将数组中暂存的数字入栈操作(+ 直接压入、- 压入负数 、 * 将暂存数字与栈顶元素相乘后压入、/ 将暂存数字与栈顶元素相乘后压入)；
 * */

/*
4 * 9 - 8 * 7 + 9
1 + 8 / 2 - 2
11 - 10 * 1
 */

int main(){
    char str[210],num[210];
    char sym[4]={'*','/','+','-'};
    int len;
    stack<double> cal;
    //cin.getline允许读取包含空格的字符串
    while(cin.getline(str,210))
    {
        len = strlen(str);
        if(len==1&&str[0]=='0') break;
        int flag = 2,count=-1;
        for(int i = 0;i < len;i++)
        {
            int flag2=0;//帮助判断是否是数字并存入num
            //题目中整数和运算符用空格分隔，去掉空格
            if(str[i]==' ') continue;
            //是数字，暂存num中
            if(str[i]>='0'&&str[i]<='9')
            {
                count++;
                num[count]=str[i];
                flag2 = 1;
            }
            //是字符，若处理到最后一位需要进行栈内计算了
            if(flag2==0||i==len-1)
            {
                //处理多位数字，atoi方法：将字符串转为整形
                //处理完当前数字后，初始化num
                num[count+1]='\0';
                double n = atoi(num);
                count=-1;

                if(flag==0) //乘法 相乘后放入栈
                {
                    double m=cal.top();
                    n *= m;
                    cal.pop();
                    cal.push(n);
                }
                else if(flag==1) //除法  相除后放入栈
                {
                    double m=cal.top();
                    n = m/n;
                    cal.pop();
                    cal.push(n);
                }
                else if(flag==3) //减法 存为负数放入栈
                {
                    cal.push(-n);
                }
                else if(flag==2) //加法  直接放入栈
                {
                    cal.push(n);
                }
                //判断算数符号
                for(int j = 0 ; j < 4 ; j++)
                {
                    if(str[i]==sym[j]) flag=j;
                }
            }

        }
        double countSum = 0;
        //乘除已经处理完毕，只需要将栈中的元素相加即可
        while(!cal.empty()){
            countSum += cal.top();
            cal.pop();
        }
        printf("%.2lf\n",countSum);
    }
    return 0;
}