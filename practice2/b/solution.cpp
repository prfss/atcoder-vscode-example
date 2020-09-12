// accepted submission
// https://atcoder.jp/contests/practice2/submissions/16634458 (expanded)

#include <atcoder/all>
#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
    int n, q;

    cin >> n >> q;

    atcoder::fenwick_tree<ll> t(n);
    for (int i = 0; i < n; i++) {
        ll x;
        cin >> x;
        t.add(i, x);
    }

    while (q--) {
        int op, x, y;
        cin >> op >> x >> y;
        if (op == 0) {
            t.add(x, y);
        } else {
            cout << t.sum(x, y) << "\n";
        }
    }

    return 0;
}