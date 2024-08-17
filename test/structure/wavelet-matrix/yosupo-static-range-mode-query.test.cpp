#define IGNORE
#define PROBLEM "https://judge.yosupo.jp/problem/static_range_mode_query"

#include "../../../structure/wavelet-matrix.cpp"
#include "../../../other/compressor.cpp"

int main() {
    ll N, Q;
    cin >> N >> Q;

    vll a(N);
    rep(i, N) cin >> a[i];

    Compressor<ll> comp(a);
    vll b = comp.compressed;

    vll d;
    rep(i, N) d.push_back(comp.retrieve(b[i]));
    
    WaveletMatrix<ll> wm(b);

    auto c = [](const tuple<ull, ull, ull, ull, ll> &left, const tuple<ull, ull, ull, ull, ll> &right) {
        // width
        if (get<0>(left) != get<0>(right)) {
            return get<0>(left) < get<0>(right);
        }
        // depth
        if (get<3>(left) != get<3>(right)) {
            return get<3>(left) > get<3>(right);
        }
        // left
        if (get<1>(left) != get<1>(right)) {
            return get<1>(left) > get<1>(right);
        }
        return true;
    };

    rep(i, Q) {
        ll l, r;
        cin >> l >> r;

        auto ans = wm.top_k(l, r, 5, c);
        
        cout << comp.retrieve(ans[0].first) << " " << ans[0].second << endl;
    }
}