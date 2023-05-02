// https://www.codingninjas.com/codestudio/problems/1062679?topList=striver-sde-sheet-problems&leftPanelTab=0
double ans(double n, long long m)
{
   double res = 1;
   for(int i = 1; i <= m; ++i)
   {
      res = res * n;
   }
   return res;
}
int NthRoot(long long n, long  long m) {
  double low = 1;
  double high = m;
  double eps = 1e-7; 
  while((high-low) > eps)
  {
     double mid = (low+high)/(2*1.0);
     double ans1 = ans(mid, n);
     if(ans1>m) high = mid;
     else low = mid;
  }
  long long a = high;
  long long  k = 1;
  for(int i = 1; i  <= n; ++i)
  {
    k = k * a;
  }
  if(k == m) return a;
  return -1;
}
