// accepted submission
// https://atcoder.jp/contests/practice2/submissions/16824169

#include <atcoder/twosat>
#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, d;
    cin >> n >> d;

    atcoder::two_sat sat(n * 2);
    vector<int> x(n), y(n);

    for (int i = 0; i < n; i++) {
        cin >> x[i] >> y[i];
        sat.add_clause(i, false, n + i, false);
        sat.add_clause(i, true, n + i, true);
    }

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (i == j) continue;
            if (abs(x[i] - x[j]) < d) {
                sat.add_clause(i, false, j, false);
            }
            if (abs(x[i] - y[j]) < d) {
                sat.add_clause(i, false, n + j, false);
            }
            if (abs(y[i] - x[j]) < d) {
                sat.add_clause(n + i, false, j, false);
            }
            if (abs(y[i] - y[j]) < d) {
                sat.add_clause(n + i, false, n + j, false);
            }
        }
    }

    bool b = sat.satisfiable();

    if (b) {
        cout << "Yes\n";
        auto ans = sat.answer();
        for (int i = 0; i < n; i++) {
            if (ans[i]) {
                cout << x[i] << "\n";
            } else {
                cout << y[i] << "\n";
            }
        }
    } else {
        cout << "No\n";
    }
    return 0;
}