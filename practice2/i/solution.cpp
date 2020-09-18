// accepted submission
// https://atcoder.jp/contests/practice2/submissions/16824211

#include <atcoder/string>
#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    string s;
    cin >> s;

    ll n = s.size();

    auto sa = atcoder::suffix_array(s);

    auto lcp = atcoder::lcp_array(s, sa);

    ll ans = n * (n + 1) / 2;

    for (auto x : lcp) {
        ans -= x;
    }

    cout << ans << endl;

    return 0;
}