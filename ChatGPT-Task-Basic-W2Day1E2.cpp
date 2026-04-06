#include <iostream>
#include <vector>

using namespace std;
/*有可能重复元素的，两次二分法*/

int find_first(vector<int>& nums, int target)
{
    int left = 0;
    int right = nums.size() - 1;

    while (left <= right)
    {
        int mid = left + (right - left) / 2;

        if (nums[mid] >= target)
            right = mid - 1;
        else
            left = mid + 1;
    }

    if (left < nums.size() && nums[left] == target)
        return left;

    return -1;
}

int find_last(vector<int>& nums, int target)
{
    int left = 0;
    int right = nums.size() - 1;

    while (left <= right)
    {
        int mid = left + (right - left) / 2;

        if (nums[mid] <= target)
            left = mid + 1;
        else
            right = mid - 1;
    }

    if (right >= 0 && nums[right] == target)
        return right;

    return -1;
}

vector<int> search_range(vector<int>& nums, int target)
{
    return {find_first(nums, target), find_last(nums, target)};
}

int main()
{
    vector<int> nums = {1,2,2,2,3};
    vector<int> result = search_range(nums, 2);

    for (auto v : result)
        cout << v << endl;
}