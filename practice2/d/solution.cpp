// accepted submission
// https://atcoder.jp/contests/practice2/submissions/16635566

#include <atcoder/maxflow>
#include <bits/stdc++.h>

using namespace std;

int n, m;
string grid[100];

int enc(int i, int j) {
    return i * m + j;
}

pair<int, int> dec(int x) {
    return make_pair(x / m, x % m);
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> grid[i];
    }

    int s = n * m;
    int t = s + 1;

    atcoder::mf_graph<int> g(n * m + 2);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == '#') continue;

            int k = enc(i, j);

            if ((i + j) % 2) {
                g.add_edge(s, k, 1);
            } else {
                g.add_edge(k, t, 1);
            }

            if ((i + j) % 2 == 0) continue;

            if (i > 0 and grid[i - 1][j] == '.') {
                g.add_edge(k, enc(i - 1, j), 1);
            }

            if (i < n - 1 and grid[i + 1][j] == '.') {
                g.add_edge(k, enc(i + 1, j), 1);
            }

            if (j > 0 and grid[i][j - 1] == '.') {
                g.add_edge(k, enc(i, j - 1), 1);
            }

            if (j < m - 1 and grid[i][j + 1] == '.') {
                g.add_edge(k, enc(i, j + 1), 1);
            }
        }
    }

    int ans = g.flow(s, t);

    for (auto [from, to, cap, flow] : g.edges()) {
        if (from == s or to == t or flow != 1) continue;

        auto [i1, j1] = dec(from);
        auto [i2, j2] = dec(to);

        if (i1 != i2) {
            grid[i1][j1] = 'v';
            grid[i2][j2] = '^';
            if (i2 < i1) swap(grid[i1][j1], grid[i2][j2]);
        } else {
            grid[i1][j1] = '>';
            grid[i2][j2] = '<';
            if (j2 < j1) swap(grid[i1][j1], grid[i2][j2]);
        }
    }

    cout << ans << endl;
    for (int i = 0; i < n; i++) {
        cout << grid[i] << "\n";
    }

    return 0;
}