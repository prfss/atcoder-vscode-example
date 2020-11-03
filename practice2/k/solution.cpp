// accepted submission
// https://atcoder.jp/contests/practice2/submissions/17562756

#include <atcoder/lazysegtree>
#include <atcoder/modint>
#include <bits/stdc++.h>

using namespace std;
using namespace atcoder;

using mint = modint998244353;

struct S {
    int len;
    mint v;
};

S op(S l, S r) {
    return S { l.len + r.len, l.v + r.v };
}

S e() { return S { 1, 0 }; }

struct F {
    mint b, c;
};

S mapping(F f, S s) {
    return S { s.len, f.b * s.v + f.c * s.len };
}

F composition(F l, F r) {
    return F { l.b * r.b, l.b * r.c + l.c };
}

F id() {
    return F { 1, 0 };
}

int main() {
    int n, q;
    cin >> n >> q;

    vector<S> a(n);
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        a[i] = { 1, x };
    }

    lazy_segtree<S, op, e, F, mapping, composition, id> seg(a);

    for (int i = 0; i < q; i++) {
        int t;
        cin >> t;
        if (t == 0) {
            int l, r, c, d;
            cin >> l >> r >> c >> d;
            seg.apply(l, r, F { c, d });
        } else {
            int l, r;
            cin >> l >> r;
            cout << seg.prod(l, r).v.val() << endl;
        }
    }
}
