#include<iostream>
#include<algorithm>

using namespace std;

int min_len_subarray_sum_at_least(int target, const int* arr, int size)
{
    int left = 0;
    int sum = 0;
    int ans = size + 1; // 代表“还没找到”

    for (int right = 0; right < size; ++right)
    {
        sum += arr[right];

        while (sum >= target)
        {
            ans = std::min(ans, right - left + 1);
            sum -= arr[left];
            ++left;
        }
    }

    return (ans == size + 1) ? 0 : ans;
}

int main()
{
    int nums[]={2,3,1,2,4,3};
    int target = 7;

    cout<<min_len_subarray_sum_at_least(target,nums,6)<<endl;

}