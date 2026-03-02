#include<iostream>
#include<vector>

using namespace std;

string s1="abcabcbb";
string s2="bbbbb";
string s3="pwwkew";   

int length_of_longest_substring(const std::string& s)
{
    std::vector<int> last(256, -1);
    int left = 0;
    int ans = 0;

    for (int right = 0; right < (int)s.size(); ++right)
    {
        unsigned char c = (unsigned char)s[right];

        /*last[i] 表示：ASCII 值为 i 的字符，上次出现的位置
        为什么写成 unsigned char？unsigned char 范围是：
        0 到 255
        last[c]永远是合法下标。
        */

        if (last[c] >= left)
            left = last[c] + 1;

        last[c] = right;
        ans = std::max(ans, right - left + 1);
    }

    return ans;
}