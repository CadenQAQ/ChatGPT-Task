#include<iostream>
#include<unordered_map>



bool has_duplicate(const int *arr, size_t n)
{
    std::unordered_map<int,int> m1;
    for(size_t i = 0;i<n;++i)
    {
        m1[arr[i]]++;
    }

    for(const auto &v:m1)
    {
        if(v.second>1)
        {
            return true;
        }
    }

    return false;
}

int main()
{
    int arr[5] = {4,3,2,6};

    int num = sizeof(arr)/sizeof(arr[0]);

    std::cout<<has_duplicate(arr, num)<<std::endl;

}