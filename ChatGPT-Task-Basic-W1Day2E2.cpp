#include<iostream>
#include<unordered_map>
using namespace std;

/*只有小写字母的字符串是否有重复字符*/
bool is_anagram(const std::string& s1, const std::string& s2)
{
    unordered_map<char,int> m1;

    if(s1.size()!=s2.size())
    {
        return false;
    }

    for(const auto &c: s1)
    {
        m1[c]++;
    }

    for(const auto &c: s2)
    {
        m1[c]--;
    }

    for(const auto &c:m1)
    {
        if (c.second!=0)
        return false;
    }
   
    return true;
}

int main()
{
    string a = "badc";
    string b ="abbd";
    cout<<is_anagram(a,b);
}
