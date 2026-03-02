#include<iostream>
#include<unordered_set>
using namespace std;

bool has_duplicate_char(const std::string& s)
{
    unordered_set<char>s1;
    for(const auto &v:s)
    {
        if(s1.count(v)>0)
        {
            return true;
        }
        s1.insert(v);
        
    }
    return false;
}

int main()
{
    string s = "abcdefg";
    cout<<has_duplicate_char(s);
}
