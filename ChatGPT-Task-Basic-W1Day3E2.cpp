#include<iostream>
#include<vector>
#include <algorithm>
using namespace std;

// int max_sum(const int *arr, int size,int k)
// {
   

//     vector<int>result ;

//     for(int i = 0; i <size-k+1;++i)
//     {
//         int sum = 0;
//         for (int j = 0;j<k;++j)
//         {
         
//             sum +=arr[i+j];
//         }
//         result.push_back(sum);


//     }
 
//     // for(auto const &v : result)
//     // {
//     //     cout<<v<<endl;
//     // }
//     int maxSum = *max_element(result.begin(), result.end());

//     return maxSum;
// }

int max_sum(const int* arr, int size, int k)
{
    if (k <= 0 || size < k) return 0;

    int sum = 0;
    for (int i = 0; i < k; ++i)
        sum += arr[i];

    int max_num = sum;   // ✅ 关键：包含第一个窗口

    int left = 0;
    for (int j = k; j < size; ++j)
    {
        sum += arr[j] - arr[left];
        ++left;
        max_num = std::max(max_num, sum);
    }

    return max_num;
}
int main()
{
    int arr[5] = {1,2,3,4,5};
    cout<<max_sum(arr, 5,3);

}