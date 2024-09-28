#define PROBLEM "https://judge.yosupo.jp/problem/point_add_rectangle_sum"

#include "../../../structure/dynamic-binary-indexed-tree-2d.cpp"
#include "../../../other/compressor.cpp"

int main() {
    ll N, Q;
    cin >> N >> Q;

    vector<ll> X, Y, W;

    rep(i, N) {
        ll x, y, w;
        cin >> x >> y >> w;

        X.push_back(x);
        Y.push_back(y);
        W.push_back(w);
    }

    vector<vll> query;

    rep(q, Q) {
        ll t;
        cin >> t;

        if (t == 0) {
            ll x, y, w;
            cin >> x >> y >> w;

            query.push_back({0, x, y, w});
            X.push_back(x);
            Y.push_back(y);
        }
        else {
            ll l, d, r, u;
            cin >> l >> d >> r >> u;

            query.push_back({1, l, d, r, u});
        }
    }

    Compressor<ll> comp_x(X), comp_y(Y);

    DynamicBinaryIndexedTree2D<ll> bit(comp_x.size() + 1, comp_y.size() + 1);

    rep(i, N) {
        ll x = comp_x.find(X[i]);
        ll y = comp_y.find(Y[i]);
        ll w = W[i];

        bit.add(x, y, w);
    }

    rep(q, Q) {
        ll t = query[q][0];

        if (t == 0) {
            ll x = comp_x.find(query[q][1]);
            ll y = comp_y.find(query[q][2]);
            ll w = query[q][3];

            bit.add(x, y, w);
        }
        else {
            ll l = comp_x.lower_bound(query[q][1]);
            ll d = comp_y.lower_bound(query[q][2]);
            ll r = comp_x.lower_bound(query[q][3]);
            ll u = comp_y.lower_bound(query[q][4]);

            cout << bit.sum(l, r, d, u) << endl;
        }
    }

    return 0;
}
