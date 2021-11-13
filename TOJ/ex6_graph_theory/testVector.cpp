#include <iostream>
#include <vector>

using namespace std;

struct Rect{
    int id;
    int length;
    int width;
};

int main(){
    vector<int> vec;
    //向vec数组中压入数据
    vec.push_back(1);
    vec.push_back(2);
    for(int i = 0 ; i < vec.size() ; i++){
        cout << vec[i] << " " ;
    }
    cout << endl;
    //清空vec
    vec.clear();
    //利用vector实现二维数组
    vector<int> vecArr[110];
    //向vector[0]位置上push两个元素"1231"和"4343"
    //vector[0][index],通过index访问
    //vector[0][0] = 1231
    //vector[0][1] = 4343
    vecArr[0].push_back(1231);
    vecArr[0].push_back(4343);
    cout << vecArr[0][0] << endl;
    cout << vecArr[0][1] << endl;

    vector<Rect> vec1;
    vec1.push_back({2,2,3});
    vec1.push_back({1,6,9});
    vec1.push_back({3,3,1});

    for(int i = 0 ; i < vec1.size() ; i++){
        cout << vec1[i].id << " " << vec1[i].length << " " << vec1[i].width <<  endl ;
    }
}
