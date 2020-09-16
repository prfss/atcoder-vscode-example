// accepted submission
// https://atcoder.jp/contests/practice2/submissions/16770106

#include <atcoder/mincostflow>
#include <bits/stdc++.h>

using namespace std;
using namespace atcoder;
using ll = long long;

const ll X = 1'000'000'000;
ll n, k;
ll a[50][50];

mcf_graph<ll, ll> g;

int main() {
    cin >> n >> k;

    g = mcf_graph<ll, ll>(2 * n + 2);

    int s = 2 * n, t = 2 * n + 1;

    g.add_edge(s, t, n * k, X);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
            g.add_edge(i, n + j, 1, X - a[i][j]);
        }
    }

    for (int i = 0; i < n; i++) {
        g.add_edge(s, i, k, 0);
        g.add_edge(n + i, t, k, 0);
    }

    ll total = n * k * X - g.flow(s, t, n * k).second;

    vector<string> ans(n, string(n, '.'));

    for (auto [from, to, cap, flow, cost] : g.edges()) {
        if (from != s and to != t and flow != 0) {
            //cout << from << " " << to << " " << flow << endl;
            ans[from][to - n] = 'X';
        }
    }

    cout << total << endl;
    for (auto s : ans) {
        cout << s << endl;
    }
}