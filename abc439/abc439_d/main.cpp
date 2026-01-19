#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<long long> a(n);
    for(int i=0;i<n;i++) cin >> a[i];

    unordered_map<long long, long long> right7, right3, left7, left3;
    right7.reserve(n*2);
    right3.reserve(n*2);
    left7.reserve(n*2);
    left3.reserve(n*2);

    // まず右側に全部入れる
    for(int i=0;i<n;i++){
        if(a[i]%7==0) right7[a[i]/7]++;
        if(a[i]%3==0) right3[a[i]/3]++;
    }

    long long ans = 0;

    for(int j=0;j<n;j++){
        // j自身を「右」から除外（右側は index>j だけにしたい）
        if(a[j]%7==0) right7[a[j]/7]--;
        if(a[j]%3==0) right3[a[j]/3]--;

        if(a[j]%5==0){
            long long x = a[j]/5;

            // j が最小：右側に i,k がある
            ans += right7[x] * right3[x];

            // j が最大：左側に i,k がある
            ans += left7[x] * left3[x];
        }

        // j自身を「左」に追加（次のjのため）
        if(a[j]%7==0) left7[a[j]/7]++;
        if(a[j]%3==0) left3[a[j]/3]++;
    }

    cout << ans << "\n";
}
