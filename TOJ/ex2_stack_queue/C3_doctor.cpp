#include <iostream>
#include <vector>
#include <string.h>
#include <algorithm>
using namespace std;

/*
 * 创建vector数组存储每一位医生所需治疗病人的信息(信息用结构体表示，分别代表病人的序号以及优先级)
 * 输入数据，分别将病人push入对应的医生数组中，在进行看病时，排序数组中病人的优先程度(优先级/序号)，
 * 将优先级最高的病人放在最后准备出栈
 * */


//创建结构体用于存储并病人的序号以及优先级
typedef struct {
    int num;
    int pre;
}Sick;

vector<Sick> doctor1,doctor2,doctor3;

//定义比较规则
//需要将优先级高或者序号小(先来的)的排在后面
//因为数组为vector，只能在栈尾进行数据的添加和删除
bool cmp(Sick s1 , Sick s2){
    if(s1.pre != s2.pre){
        return s1.pre < s2.pre;
    }
    if(s1.num != s2.num){
        return s1.num > s2.num;
    }
}

int main() {
    int cases;
    int doctor,sickPre;
    int num;
    char operate[10];
    while(cin >> cases){
        num = 1;
        doctor1.clear();
        doctor2.clear();
        doctor3.clear();
        for(int i = 1 ; i <= cases ; i++){
            cin >> operate;
            if(strcmp(operate , "IN") == 0){
                cin >> doctor >> sickPre;
                if(doctor == 1){
                    doctor1.push_back({num++ , sickPre});
                }else if(doctor == 2){
                    doctor2.push_back({num++ , sickPre});
                }else if(doctor == 3){
                    doctor3.push_back({num++ , sickPre});
                }
            }else if(strcmp(operate , "OUT") == 0){
                cin >> doctor;
                if(doctor == 1){
                    if (doctor1.size() == 0){
                        cout << "EMPTY" << endl;
                    }else{
                        //按上面cmp方法指定的规则进行排序病人的看病顺序
                        sort(doctor1.begin(), doctor1.end(), cmp);
                        //先输出
                        cout << doctor1[doctor1.size() - 1].num << endl;
                        //将当前的病人出栈
                        doctor1.pop_back();
                    }
                }else if(doctor == 2){
                    if (doctor2.size() == 0){
                        cout << "EMPTY" << endl;
                    }else{
                        //按上面cmp方法指定的规则进行排序病人的看病顺序
                        sort(doctor2.begin(), doctor2.end(), cmp);
                        //先输出
                        cout << doctor2[doctor2.size() - 1].num << endl;
                        //将当前的病人出栈
                        doctor2.pop_back();
                    }
                }else if(doctor == 3){
                    if (doctor3.size() == 0){
                        cout << "EMPTY" << endl;
                    }else{
                        //按上面cmp方法指定的规则进行排序病人的看病顺序
                        sort(doctor3.begin(), doctor3.end(), cmp);
                        //先输出
                        cout << doctor3[doctor3.size() - 1].num << endl;
                        //将当前的病人出栈
                        doctor3.pop_back();
                    }
                }
            }
        }
    }
    return 0;
}


