#define PROBLEM "https://judge.yosupo.jp/problem/staticrmq"

#include "../../../structure/sparse-table.cpp"

int main() {
    ll N, Q;
    cin >> N >> Q;

    vector<ll> a(N);
    rep(i, N) cin >> a[i];

    using S = ll;
    auto op = [](S a, S b) { return min(a, b); };
    SparseTable<S, op> st(a);

    while (Q--) {
        ll l, r;
        cin >> l >> r;

        cout << st.prod(l, r) << endl;
    }

    return 0;
}