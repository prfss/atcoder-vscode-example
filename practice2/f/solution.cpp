#include <atcoder/convolution>
#include <bits/stdc++.h>
// accepted submission
// https://atcoder.jp/contests/practice2/submissions/16788064

using namespace std;
using namespace atcoder;

using ll = long long;

int main() {
    int n, m;

    cin >> n >> m;
    vector<ll> a(n), b(m);

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    for (int i = 0; i < m; i++) {
        cin >> b[i];
    }

    vector<ll> ans = convolution(a, b);

    for (auto x : ans) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}