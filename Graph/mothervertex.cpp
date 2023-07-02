
// https://thejoboverflow.com/problem/241/



#include <bits/stdc++.h>
using namespace std;
void  dsa(int n, vector<int> &v, vector<vector<int>> &g)
{
   v[n] = 1;
   for(auto c : g[n])
   {
     if(v[c]) continue;
     dsa(c,v,g);
   }
   
}
  int main() {

    int n,e;
    cin >> n >> e;
    vector<int> v1(e), v2(e); 
    for(int i = 0; i < e; ++i) cin >> v1[i];
    for(int i = 0; i < e; ++i) cin >> v2[i];
    vector<vector<int>> gp(n+10);;
    for(int i = 0; i < e; ++i) gp[v1[i]].push_back(v2[i]);
    vector<int> visi(n+10, 0);
    int v = 1;
    for(int i = 1; i <= n; ++i) if(!visi[i]) 
    {
      dsa(i, visi, gp);
      v = i;
    }
    for(int i = 0; i < n+1; ++i) visi[i] = 0;
    dsa(v, visi, gp);
    int ok =  1;
    for(int i = 1; i <= n; ++i) ok &= visi[i];
    if(ok) cout<<1;
    else cout<<0;
    return 0;

  }







