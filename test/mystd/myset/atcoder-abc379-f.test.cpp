#define IGNORE
#define PROBLEM "https://atcoder.jp/contests/abc379/tasks/abc379_f"

#include "../../../mystd/myset.cpp"

namespace segtree {
    #include "../../../structure/segment-tree.cpp"
}

int main() {
    ll N, Q;
    cin >> N >> Q;

    vector<ll> H(N);
    rep(i, N) cin >> H[i];

    vll L(Q), R(Q);
    rep(i, Q) {
        cin >> L[i] >> R[i];
        --L[i]; --R[i];
    }

    RedBlackTree<ll, false> st;

    vector<array<ll, 3>> query(Q);
    rep(i, Q) query[i] = {R[i], L[i], i};
    sort(query);

    segtree::PointSetRangeMax<ll, ll> seg(H);

    vector<ll> ans(Q, -1);

    repd(i, N) {
        while (not query.empty() and query.back()[0] == i) {
            auto [r, l, idx] = query.back();
            query.pop_back();

            ll max_lr = seg.prod(l + 1, r + 1);
            ll n_r = st.count_greater_than_or_equal(max_lr);

            ans[idx] = n_r;
        }

        st.erase(st.begin(), st.upper_bound(H[i]));
        st.insert(H[i]);
    }

    rep(i, Q) cout << ans[i] << endl;

    return 0;
} 
