// accepted submission
// https://atcoder.jp/contests/practice2/submissions/16634719

#include <atcoder/math>
#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    int t;
    cin >> t;
    while (t--) {
        ll n, m, a, b;
        cin >> n >> m >> a >> b;
        cout << atcoder::floor_sum(n, m, a, b) << "\n";
    }

    return 0;
}