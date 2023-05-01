
// https://leetcode.com/discuss/interview-question/380650/Bloomberg-or-Phone-Screen-or-Candy-Crush-1D


#include <bits/stdc++.h>
using namespace std;
#define ll long long
// HII
// this is dsqure
int main()
{
    string s = "";
    cin >> s;
    stack<pair<char, int>> st;
    for (int i = 0; i < s.size(); ++i)
    {
        if(st.empty())
        {
            st.push({s[i], 1});
            continue;
        }
        pair<char, int> x = st.top();
        if (x.first == s[i])
        {
            
            st.pop();
            x.second++;
            if (x.second != 3)
                st.push({s[i], x.second});
        }
        else
        {
            st.push({s[i], 1});
        }
    }
    string x = "";
    while (!st.empty())
    {
        x = st.top().first + x;
        st.pop();
    }
    cout<<x;
    return 0;
}
