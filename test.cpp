#include<iostream>
#include<vector>

using namespace std;

string s1="abcabcbb";
string s2="bbbbb";
string s3="pwwkew";   

int length_of_longest_substring(const std::string& s)
{
    std::vector<int> last(256,-1);

    int ans = 0;
    int left = 0;
    int right = 0;

    for(int i = 0; i<s.size();++i)
    { 
        unsigned char c = (int)s[i];

        if(last[c]>=left)
        {
            left=last[c]+1;
        }
        last[c] = right;
        right++;

        ans = right-left ;
    } 

    return ans;
}

int main()
{
    std::cout<<length_of_longest_substring(s3);

}