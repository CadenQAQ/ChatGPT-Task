#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int subarray_sum(const vector<int>& nums, int target_sub_sum) { 
    unordered_map<int, int> prefix_counts;
    prefix_counts[0] = 1; // 历史前缀和为 0 的出现了一次
    
    int current_sum = 0;
    int total_intervals_found = 0;

    for (int x : nums) {
        current_sum += x; 

        // 终点刻度 - 目标跨度 = 我们需要的历史起点刻度
        int required_history_sum = current_sum - target_sub_sum; 
        
        // 去历史记录里找这个“需要的起点”
        if (prefix_counts.find(required_history_sum) != prefix_counts.end()) {
            total_intervals_found += prefix_counts[required_history_sum]; //如果全是正数可以用total_intervals_found+=1
        }

        // 记录当前的刻度
        prefix_counts[current_sum]++;
    }

    return total_intervals_found;
}

int main() {
    vector<int> v1 = {1, 2, 3, 1, 2};
    // 预期结果：3 (分别是 [1,2], [3], [1,2])
    cout << "Count: " << subarray_sum(v1, 3) << endl;
    return 0;
}