#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int binary_search(vector<int>& nums, int target)
{
    int left = 0;
    int right = nums.size()-1;
    int mid = 0;

    while(left<right)
    {
        mid = left+(right-left)/2;
        if(target<nums[mid])
        {
            right = mid-1;
          
        }
        else if(target>nums[mid])
        {
            left = mid+1;
        }
        else if(target==nums[mid])
        {
            return mid;
        }

    }
    return -1;
}


int main()
{
    vector<int>num = {1,5,6,8,22,29,30,45};
    
    cout<<binary_search(num, 30);

}


