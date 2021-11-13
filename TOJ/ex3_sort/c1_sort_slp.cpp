#include <iostream>
#include <string.h>
using namespace std;

/*
0051231232050775
1525354
15253545
 * */

char str[1010];
int slp[1010];

void BubbleSort(int arr[] , int length){
    for (int i = 0; i < length; i++){
        for (int j = 0; j < length -  i - 1;  j++){
            if (arr[j] > arr[j + 1]){
                int temp;
                temp = arr[j + 1];
                arr[j + 1] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

int main(){
    while(scanf("%s", str) != EOF){
        memset(slp, 0, sizeof(slp));
        int len = strlen(str);
        str[len] = '5';
        int time = 0;
        for (int i = 0; i <=len; i++){
            while (str[i] == '5'){
                i++;
            }
            while (str[i] != '5'){
                slp[time] = slp[time] * 10 + str[i] - '0';
                i++;
            }
            time++;	//统计数字数量
        }
        if (str[len - 1] == '5'){
            time--;
        }

        BubbleSort(slp , time); //排序
        for (int i = 0; i < time - 1; i++)
        {
            cout << slp[i] << " ";
        }
        cout << slp[time - 1] << endl;
    }
    return 0;
}