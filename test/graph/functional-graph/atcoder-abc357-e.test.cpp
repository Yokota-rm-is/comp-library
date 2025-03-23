#define IGNORE
#define PROBLEM "https://atcoder.jp/contests/abc357/tasks/abc357_e"
// https://atcoder.jp/contests/abc357/submissions/61531542

#include "../../../graph/functional-graph.cpp"

int main() {
    ll N;
    cin >> N;

    vll a(N);
    rep(i, N) cin >> a[i];
    a--;

    FunctionalGraph fg(N);
    rep(i, N) fg.connect(i, a[i]);

    fg.build();

    ll ans = 0;
    fore(namori, fg.namoris) {
        fore(i, namori.ids) {
            ans += namori.depth[i];
            ans += namori.cycle_ids.size();
        }
    }

    cout << ans << endl;

    return 0;
} 
