#include<iostream>
#include<unordered_set>
#include<map>
#include<unordered_map>
using namespace std;

/*
题 1：判断数组中是否存在重复元素

输入：

[1,2,3,4,5]
[1,2,3,1]

要求：
返回 true / false

⚠️ 不写完整程序
⚠️ 只写函数
⚠️ 优先用 unordered_set
*/
int a[5] = {1,2,3,4,5};
int b[4]={1,2,3,1};
int arr[] = {4,1,2,1,2};

template<size_t N1, size_t N2>
bool has_common_element(int (&arr1)[N1], int (&arr2)[N2])
{
    unordered_set<int> s1(arr1, arr1 + N1);
    
    for(auto v: arr2)
    {
        if (s1.count(v) > 0)  // 如果arr2中的元素在s1中存在
        {
            return true;       // 发现有共同元素
        }
    }
    
    return false;  // 没有共同元素
}

bool has_duplicate(const int* arr, size_t n)
{
    unordered_set<int> s1;

    for(size_t i = 0;i<n;++i)
    {
        if(s1.count(arr[i])>0)
        {return true;}

        s1.insert(arr[i]);
    }
    return false;
}

int single_num(const int *arr, size_t n)
{
    int result=0;
    unordered_map<int, int>m1;
    for(size_t i =0;i<n;++i)
    {
        m1[arr[i]]++;
    }

    for(const auto &v: m1)
    {
        if (v.second==1)
        result = v.first;
    }
    

    return result;
}

int main()
{
    cout << boolalpha;
    cout << "是否有共同元素: " << has_common_element(a,b) << endl;  // 输出 true
    cout << "a是否有重复元素: " << has_duplicate(a,5) << endl;
    cout << "a不重复的元素是: " << single_num(arr,5) << endl;
}