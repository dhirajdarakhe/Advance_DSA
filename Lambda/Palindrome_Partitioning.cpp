// https://www.codingninjas.com/codestudio/problems/799931?topList=striver-sde-sheet-problems&leftPanelTab=0
#include <bits/stdc++.h>
vector<vector<string>> partition(string s)
{
    vector<vector<string>> ans;
    vector<string> res;
    function<void(int)> f = [&](int i) -> void {
        auto p = [](string x) -> int
        {
            int i = 0;
            int j = x.size() - 1;
            while (i < j)
            {
                if (x[i] != x[j])
                    return 0;
                i++;
                j--;
            }
            return 1;
        };
        if (i >= s.size())
        {
            ans.push_back(res);
            return; // exit the function
        }
        for (int j = i; j < s.size(); ++j)
        {
            string x = s.substr(i, j - i + 1);
            if (p(x))
            {
                res.push_back(x);
                f(j + 1);
                res.pop_back();
            }
        }
    };

    f(0);
    return ans;
}
