#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>
#include <bits/stdc++.h>
#define REP(i, n) for (int i = 0; (i) < (int)(n); ++ (i))
#define REP3(i, m, n) for (int i = (m); (i) < (int)(n); ++ (i))
#define REP_R(i, n) for (int i = (int)(n) - 1; (i) >= 0; -- (i))
#define REP3R(i, m, n) for (int i = (int)(n) - 1; (i) >= (int)(m); -- (i))
#define ALL(x) ::std::begin(x), ::std::end(x)
using namespace std;


int main(){
  int n;
  cin >> n;
  vector<int>a(n);
  for(int i=0;i<n;i++)cin >> a[i];

  map<int,vector<int>>d;
  for(int i=0;i<n;i++)d[a[i]].push_back(i);

  long long s=accumulate(a.begin(),a.end(),0LL);
  vector<long long>ans(n);
  for(auto[v,i_list]:d){
    s-=(long long)v*i_list.size();
    for(auto i:i_list)ans[i]=s;
  }

  for(auto x:ans)cout << x << ' ';
}