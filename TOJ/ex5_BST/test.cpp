#include <iostream>

using namespace std;

struct Stu{
    int stuNo;
    string stuName;
};

int main(){
    //指针
    int a = 5 ;
    int *p = &a;
    cout << "a的地址： " << p << endl;
    cout << "p的地址： " << &p << endl;
    cout << "p指向变量的值： " << *p << endl;

    //指针变量
    char* str = "hello";
    cout << &str << endl;

    Stu stu;
    stu.stuName = "zyh";
    stu.stuNo = 2123;

    cout << stu.stuName << " : " << stu.stuNo << endl;

    return 0;

}

