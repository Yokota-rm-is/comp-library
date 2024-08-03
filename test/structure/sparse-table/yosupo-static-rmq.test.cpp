#define PROBLEM "https://judge.yosupo.jp/problem/staticrmq"

#include "../../../structure/sparse-table.cpp"


int main() {
    ll N, Q;
    cin >> N >> Q;

    vector<ll> a(N);
    rep(i, N) cin >> a[i];

    SparseTable<ll> st(a);

    while (Q--) {
        ll l, r;
        cin >> l >> r;

        cout << st.query_min(l, r) << endl;
    }

    return 0;
}