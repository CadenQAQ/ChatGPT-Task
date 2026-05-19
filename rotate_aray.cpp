#include <iostream>
#include <vector>

using namespace std;

/**
 * @brief 在旋转排序数组中搜索
 * 时间复杂度: O(log N)
 * 空间复杂度: O(1)
 */
int rotated_sorted_array_search(const vector<int>& nums, int target) {
    if (nums.empty()) return -1; // 边界防御：空检查

    int left = 0;
    int right = static_cast<int>(nums.size()) - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (nums[mid] == target) return mid;

        // 判断哪一半是有序的
        if (nums[left] <= nums[mid]) { 
            // 左半部分有序
            // 注意这里的 <=，确保覆盖边界
            if (nums[left] <= target && target < nums[mid]) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        } else { 
            // 右半部分有序
            if (nums[mid] < target && target <= nums[right]) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
    }
    return -1;
}

int main() {
    // 使用花括号初始化 (C++11 风格)
    const vector<int> nums = {4, 5, 6, 7, 8, 9, 1, 2, 3};
    int target = 7;
    
    int result = rotated_sorted_array_search(nums, target);
    
    if (result != -1) {
        cout << "Found target " << target << " at index: " << result << endl;
    } else {
        cout << "Target not found." << endl;
    }

    return 0;
}