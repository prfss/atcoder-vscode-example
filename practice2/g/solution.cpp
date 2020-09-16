// accepted submission
// https://atcoder.jp/contests/practice2/submissions/16788073

#include <atcoder/scc>
#include <bits/stdc++.h>

using namespace std;
using namespace atcoder;

using ll = long long;

int main() {
    int n, m;
    cin >> n >> m;
    scc_graph g(n);

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        g.add_edge(a, b);
    }

    vector<vector<int>> ans = g.scc();

    cout << ans.size() << "\n";
    for (auto c : ans) {
        cout << c.size() << " ";
        for (auto v : c) {
            cout << v << " ";
        }
        cout << "\n";
    }

    return 0;
}