#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

int main(){
  int n,m;
  cin>>n>>m;
  
  //n頂点のグラフgを用意する
  dsu g(n);
  
  for(int i=0;i<m;i++){
    int a,b;
    cin>>a>>b;
    
    //入力の1がgでの0に対応
    a--;b--;
    
    //辺を追加する
    g.merge(a,b);
  }
 
  //連結成分の数-1が答え
  int ans=g.groups().size()-1;
  
  cout<<ans<<endl;
}
