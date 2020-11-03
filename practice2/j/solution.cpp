// accepted submission
// https://atcoder.jp/contests/practice2/submissions/17562918

#include <atcoder/segtree>
#include <bits/stdc++.h>

using namespace std;

int mx(int x, int y) {
    return max(x, y);
}

int e() {
    return -1;
}

int main() {
    int n, q;
    cin >> n >> q;

    atcoder::segtree<int, mx, e> st(n);

    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        st.set(i, a);
    }

    while (q--) {
        int t, a, b;
        cin >> t >> a >> b;
        a--;
        if (t == 1) {
            st.set(a, b);
        } else if (t == 2) {
            cout << st.prod(a, b) << "\n";
        } else {
            auto f = [&](int x) { return x < b; };
            cout << st.max_right(a, f) + 1 << "\n";
        }
    }

    return 0;
}