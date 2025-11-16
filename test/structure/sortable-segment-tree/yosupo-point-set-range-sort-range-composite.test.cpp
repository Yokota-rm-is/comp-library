#define PROBLEM "https://judge.yosupo.jp/problem/point_set_range_sort_range_composite"

#include "../../../structure/sortable-segment-tree.cpp"
#include "../../../math/modint.cpp"

using mint = mint998;

int main() {
    ll N, Q;
    cin >> N >> Q;

    vll P(N), A(N), B(N);
    rep(i, N) cin >> P[i] >> A[i] >> B[i];

    using Key = long long;
    using S = pair<mint, mint>;
    auto op = [](S a, S b) { 
        return make_pair(a.first * b.first, a.second * b.first + b.second);
    };
    auto e = []() { return make_pair(mint(1), mint(0)); };
    using F = S;
    auto mapping = [](S a, F f) {
        return f;
    };
    SegmentTree<Key, S, op, e, F, mapping> seg;
    rep(i, N) seg.insert(i, P[i], make_pair(A[i], B[i]));

    while (Q--) {
        ll t;
        cin >> t;

        if (t == 0) {
            ll i, p, a, b;
            cin >> i >> p >> a >> b;
            seg.apply(i, p, S(a, b));
        }
        else if (t == 1) {
            ll l, r, x;
            cin >> l >> r >> x;
            S prod = seg.prod(l, r);
            cout << (prod.first * x + prod.second) << endl;
        }
        else if (t == 2) {
            ll l, r;
            cin >> l >> r;
            seg.sort(l, r, false);
        }
        else {
            ll l, r;
            cin >> l >> r;
            seg.sort(l, r, true);
        }
    }

    return 0;
} 