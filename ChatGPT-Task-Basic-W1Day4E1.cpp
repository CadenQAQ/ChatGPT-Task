#include<iostream>
#include<stack>
#include<vector>

using namespace std;

bool is_valid_parentheses(const string& s)
{
    stack<char> st;

    for(char c : s)
    {
        if(c == '(' || c == '[' || c == '{')
        {
            st.push(c);
        }
        else
        {
            if(st.empty())
                return false;

            char top = st.top();

            // TODO: 检查括号是否匹配
            if (c == ')')
            {
                if (top != '(') return false;
            }
            else if (c == ']')
            {
                if (top != '[') return false;
            }
            else if (c == '}')
            {
                if (top != '{') return false;
            }
            
            st.pop();

           
        }
    }

    return st.empty();
}

int main()
{
    string s1 = "{[()]}";
    cout <<is_valid_parentheses(s1)<<endl;
}