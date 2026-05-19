#include<iostream>
#include<unordered_set>
#include<map>
#include<unordered_map>
using namespace std;

int a[5] = {1,2,3,4,5};
int b[4]={1,2,3,1};
int arr[] = {4,1,2,1,2};

template<size_t N1, size_t N2>
int has_common_element(const int (&arr1)[N1], const int (&arr2)[N2])
{
    unordered_set<int>m1(arr1, arr1+N1);
    
    for(int i = 0; i<N2;++i)
    {
        if(m1.count(arr2[i])>0)
        {
            return true;
        }
        m1.insert(arr2[i]);
    }

    return 0;
}

int has_duplicate(const int *arr, int n)
{
    unordered_set<int>m2;

    for(int i = 0;i<n;++i)
    {
        m2.insert(arr[i]);
        if(m2.count(arr[i])>1)
        {
            return true;
        }
    }

    return 0;
}

int single_num(const int *arr, int n)
{
    unordered_map<int,int>m3;
    for(int i =0;i<n;++i)
    {
        m3[arr[i]]++;
    }

    for(auto v:m3)
    {
        if(v.second==1)
        {
            return v.first;
        }
    }

    return 0;
}

int main()
{
    cout << boolalpha;
    cout << "是否有共同元素: " << has_common_element(a,b) << endl;  // 输出 true
    cout << "a是否有重复元素: " << has_duplicate(a,5) << endl;
    cout << "a不重复的元素是: " << single_num(arr,5) << endl;
}


