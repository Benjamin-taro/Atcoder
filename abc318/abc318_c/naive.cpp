#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#define REP(i, n) for (int i = 0; (i) < (int)(n); ++ (i))
#define REP3(i, m, n) for (int i = (m); (i) < (int)(n); ++ (i))
#define REP_R(i, n) for (int i = (int)(n) - 1; (i) >= 0; -- (i))
#define REP3R(i, m, n) for (int i = (int)(n) - 1; (i) >= (int)(m); -- (i))
#define ALL(x) ::std::begin(x), ::std::end(x)

using namespace std;

int main() {
  int n,d,k;
  long long p;
  cin>>n>>d>>p;

  vector<long long>f(n),s(n);
  for(int i=0;i<n;i++)cin>>f[i];
  
  sort(f.begin(),f.end());
  s[0]=f[0];
  for(int i=0;i<n-1;i++)s[i+1]=s[i]+f[i+1];

  k=(n+d-1)/d;
  long long ans=p*k;
  for(int i=0;i<k;i++){
    ans=min(ans,s[n-1-(i*d)]+(p*i));
  }

  cout<<ans<<endl;
	return 0;
}

