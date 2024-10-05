#include <iostream>
#include <vector>
using namespace std;

constexpr int nmax = 200200;
int N, M;
int A[nmax], B[nmax];
vector<int> g[nmax];
int X[nmax];
int bipartite = true;

void dfs(int c, int x) {
  X[c] = x;
  for (auto& d : g[c]) {
    if (X[d] == -1) {
      dfs(d, 1 - x);
    } else if (X[d] == X[c]) {
      bipartite = false;
    }
  }
}

int main() {
  cin >> N >> M;
  for (int i = 0; i < M; i++) cin >> A[i], A[i]--;
  for (int i = 0; i < M; i++) cin >> B[i], B[i]--;
  for (int i = 0; i < M; i++) {
    g[A[i]].push_back(B[i]);
    g[B[i]].push_back(A[i]);
  }

  for (int i = 0; i < N; i++) X[i] = -1;
  for (int i = 0; i < N; i++) {
    if (X[i] == -1) dfs(i, 0);
  }
  cout << (bipartite ? "Yes" : "No") << endl;
}