#define PROBLEM "https://atcoder.jp/contests/abc113/tasks/abc113_c"

#include "../../../other/compressor.cpp"

int main() {
    ll N, M;
    cin >> N >> M;
    
    vll P(M), Y(M);
    rep(i, M) cin >> P[i] >> Y[i];

    vvll A(N + 1);
    rep(i, M) {
        A[P[i]].push_back(Y[i]);
    }

    vector<Compressor<ll>> comp(N + 1);

    rep(i, N + 1) {
        comp[i].init(A[i]);
    }

    rep(i, M) {
        ll p = P[i];
        ll y = Y[i];
        ll y_comp = comp[p].compress(y);

        cout << zero_padding(p, 6) << zero_padding(y_comp + 1, 6) << endl;
    }

    return 0;
}