#define IGNORE
#define PROBLEM "https://atcoder.jp/contests/abc387/tasks/abc387_f"
// https://atcoder.jp/contests/abc387/submissions/62011824

#include "../../../graph/functional-graph.cpp"
#include "../../../other/cumulative-sum.cpp"
#include "../../../math/modint.cpp"

using mint = mint998;

int main() {
    ll N, M;
    cin >> N >> M;

    vll A(N);
    rep(i, N) cin >> A[i];
    --A;

    FunctionalGraph fg(N);
    rep(i, N) {
        fg.connect(i, A[i]);
    }

    fg.build();
    auto namoris = fg.namoris;

    mint ans = 1;

    fore(namori, namoris) {
        unordered_map<ll, CumulativeSum<mint>> dp;
        mint cycle_sum = 0;

        fore(x, namori.get_topo_from_leaves()) {
            if (namori.is_cycle(x)) {
                rep(i, M) {
                    mint sum = 1;
                    fore(y, namori.get_prev_cycle()) {

                        sum *= dp[y].sum(0, i + 1);
                    }
                    cycle_sum += sum;
                }
                break;
            }
            else if (namori.is_leaf(x)) {
                rep(i, M) dp[x].push_back(1);
            }
            else {
                rep(i, M) {
                    mint sum = 1;
                    fore(y, namori.get_prev(x)) {
                        sum *= dp[y].sum(0, i + 1);
                    }
                    dp[x].push_back(sum);
                }
            }
        }

        ans *= cycle_sum;
    }

    cout << ans << endl;

    return 0;
} 
