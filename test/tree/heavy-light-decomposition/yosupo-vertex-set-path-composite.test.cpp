#define PROBLEM "https://judge.yosupo.jp/problem/vertex_set_path_composite"

#include "../../../tree/heavy-light-decomposition.cpp"
#include "../../../structure/segment-tree-abstract.cpp"
#include "../../../math/modint.cpp"

using mint = mint998;

int main() {
    ll N, Q;
    cin >> N >> Q;

    HeavyLightDecomposition hld(N);
    
    using S = pair<mint, mint>;
    auto op1 = [](S a, S b) { 
        return make_pair(a.first * b.first, a.second * b.first + b.second);
    };
    auto op2 = [](S a, S b) { 
        return make_pair(a.first * b.first, a.first * b.second + a.second);
    };
    auto e = []() {
        return S(1, 0);
    };
    using F = S;
    auto mapping = [](S x, F f) {
        if (f.first == 0) return x;
        return f;
    };
    SegmentTree<S, op1, e, F, mapping> tree1(2 * N - 1);
    SegmentTree<S, op2, e, F, mapping> tree2(2 * N - 1);

    vll a(N), b(N); 
    rep(i, N) {
        cin >> a[i] >> b[i];
    }

    rep(i, N - 1) {
        ll u, v;
        cin >> u >> v;
        hld.connect(u, v);
    }

    hld.build(0);

    rep(i, N) {
        tree1.apply(hld.get_vertex_index(i), {a[i], b[i]});
        tree2.apply(hld.get_vertex_index(i), {a[i], b[i]});
    }

    while (Q--) {
        ll t;
        cin >> t;

        if (t == 0) {
            ll p, c, d;
            cin >> p >> c >> d;
            tree1.apply(hld.get_vertex_index(p), {c, d});
            tree2.apply(hld.get_vertex_index(p), {c, d});
        }
        else {
            ll u, v, x;
            cin >> u >> v >> x;

            mint ans = x;
            auto prod = [&](ll l, ll r) {
                if (l <= r) {
                    auto node = tree1.prod(l, r);
                    ans = ans * node.first + node.second;
                }
                else {
                    auto node = tree2.prod(r, l);
                    ans = ans * node.first + node.second;
                }
            };
            hld.path_noncommutative_query(u, v, prod);

            cout << ans << endl;
        }
    }

    return 0;
}