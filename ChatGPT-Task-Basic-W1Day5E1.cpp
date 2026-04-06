#include<iostream>
#include<stack>

using namespace std;

int calculate(string s)
{
    stack<int> st;
    int num = 0;
    char sign = '+';

    for(int i = 0; i < s.size(); i++)
    {
        char c = s[i];

        if(isdigit(c))
        {
            num = num * 10 + (c - '0');
        }

        if(!isdigit(c) || i == s.size()-1)
        {
            // TODO 根据 sign push
            if(sign=='+')
            {
                st.push(num);
            }
            if(sign=='-')
            {   
                st.push(-num);
           }
           sign = c;
           num = 0;
        }
    }

    int result = 0;

    while(!st.empty())
    {
        result += st.top();
        st.pop();
    }

    return result;
}

int main()
{
    string s = "53+3-2";
    cout<<calculate(s)<<endl;
}