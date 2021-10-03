// accepted submission:
// https://atcoder.jp/contests/practice2/submissions/26327504

#include <atcoder/lazysegtree>
#include <bits/stdc++.h>

using namespace std;

struct S {
    long long zero, one, inv;
};

S op(S l, S r) {
    return S {
        l.zero + r.zero,
        l.one + r.one,
        l.inv + r.inv + l.one * r.zero
    };
}

S e() {
    return S { 0, 0, 0 };
}

using F = bool;
S mapping(F f, S s) {
    long long zero = f ? s.one : s.zero;
    long long one = f ? s.zero : s.one;
    long long inv = f ? (s.zero * s.one - s.inv) : s.inv;
    return S { zero, one, inv };
}

F composition(F f, F g) {
    return f ^ g;
}

F id() {
    return false;
}

using stree = atcoder::lazy_segtree<S, op, e, F, mapping, composition, id>;

int main() {
    int n, q;
    cin >> n >> q;

    stree st(n);

    for (int i = 0; i < n; i++) {
        long long x;
        cin >> x;
        st.set(i, S { x == 0, x == 1, 0 });
    }

    while (q--) {
        int t, l, r;
        cin >> t >> l >> r;
        l--;
        if (t == 1) {
            st.apply(l, r, true);
        } else {
            cout << st.prod(l, r).inv << "\n";
        }
    }

    return 0;
}