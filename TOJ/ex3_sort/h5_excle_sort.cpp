#include <iostream>
#include<iomanip>
using namespace std;

/*
3 1
000007 James 85
000010 Amy 90
000001 Zoe 60
4 2
000007 James 85
000010 Amy 90
000001 Zoe 60
000002 James 98
4 3
000007 James 85
000010 Amy 90
000001 Zoe 60
000002 James 90
0 0
 */

typedef struct {
    int stuId;
    string stuName;
    int stuScore;
}Student;

//按学号排序
void BubbleSortById(Student arr[] , int length)
{
    for (int i = 0; i < length; i++)
    {
        for (int j = 0; j < length -  i - 1;  j++)
        {
            if (arr[j].stuId > arr[j + 1].stuId)
            {
                Student temp;
                temp = arr[j + 1];
                arr[j + 1] = arr[j];
                arr[j] = temp;
            }
        }
    }
}
//按姓名排序
void BubbleSortByName(Student arr[] , int length)
{
    for (int i = 0; i < length; i++)
    {
        for (int j = 0; j < length -  i - 1;  j++)
        {
            if (arr[j].stuName > arr[j + 1].stuName)
            {
                Student temp;
                temp = arr[j + 1];
                arr[j + 1] = arr[j];
                arr[j] = temp;
            }else if(arr[j].stuName == arr[j + 1].stuName){
                if(arr[j].stuId > arr[j + 1].stuId){
                    Student temp;
                    temp = arr[j + 1];
                    arr[j + 1] = arr[j];
                    arr[j] = temp;
                }
            }
        }
    }
}
//按分数排序
void BubbleSortByScore(Student arr[] , int length)
{
    for (int i = 0; i < length; i++)
    {
        for (int j = 0; j < length -  i - 1;  j++)
        {
            if (arr[j].stuScore > arr[j + 1].stuScore)
            {
                Student temp;
                temp = arr[j + 1];
                arr[j + 1] = arr[j];
                arr[j] = temp;
            }else if(arr[j].stuScore == arr[j + 1].stuScore){
                if(arr[j].stuId > arr[j + 1].stuId){
                    Student temp;
                    temp = arr[j + 1];
                    arr[j + 1] = arr[j];
                    arr[j] = temp;
                }
            }
        }
    }
}
int main (){
    int m , n;
    cin >> m >> n;
    int t = 1;
    while(m != 0 && n != 0){
        Student stu[100010];
        for(int i = 0 ; i < m ; i++){
            cin >> stu[i].stuId >> stu[i].stuName >> stu[i].stuScore;
        }
        if(n == 1){
            BubbleSortById(stu , m);
        }else if(n == 2){
            BubbleSortByName(stu , m);
        }else if(n == 3){
            BubbleSortByScore(stu , m);
        }

        cout << "Case " << t << ":" <<endl;
        for(int i = 0 ; i < m ; i++){

            cout << setfill('0')<<setw(6) << stu[i].stuId << " " << stu[i].stuName << " " << stu[i].stuScore << endl;
        }
        t++;
        cin >> m >> n ;
    }
    return 0;
}

