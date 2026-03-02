#include<iostream>
#include<vector>
#include<unordered_set>
#include<set>
#include<map>

using namespace std;
/*主函数找出重复元素*/
set<int> result1;
set<int> result2;

int arr[] = {4,1,2,1,2};

unordered_set<int> s1;
unordered_set<int> s2;

/*找出不重复元素*/
int single_number(const int* arr, size_t n)
{
    map<int,int>m1;
    for(int i = 0; i<n; ++i)
    {
        m1[arr[i]]++;

    }

    for(auto v:m1)
    {
        if(v.second==1)
        {
            result2.insert(v.first);
        }
    }

    for(auto v:result2)
    {
        cout<<v<<endl;
    }

    return result2.size();

}

int main()
{
    for(int i = 0; i<5; ++i)
    {
        if(s1.count(arr[i])>0)
        {
            result1.insert(arr[i]);
        }
        s1.insert(arr[i]);

    }


    for(auto v: result1)
    {
        cout<<v<<endl;
    }

    cout<<"=========================="<<endl;
    single_number(arr,5);
    
    
}
