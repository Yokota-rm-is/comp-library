#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=0560"

#include "../../../other/cumulative-sum-2d.cpp"

int main() {
    ll M, N, K;
    cin >> M >> N >> K;

    vector<string> S(M);
    rep(i, M) cin >> S[i];

    CumulativeSum2D<ll> cs_j(M, N), cs_o(M, N), cs_i(M, N);
    rep(i, M) rep(j, N) {
        if (S[i][j] == 'J') cs_j.add(i, j, 1);
        else if (S[i][j] == 'O') cs_o.add(i, j, 1);
        else if (S[i][j] == 'I') cs_i.add(i, j, 1);
    }

    cs_j.build();
    cs_o.build();
    cs_i.build();

    rep(i, K) {
        ll a, b, c, d;
        cin >> a >> b >> c >> d;
        --a, --b;

        cout << cs_j.sum(a, b, c, d) << " " << cs_o.sum(a, b, c, d) << " " << cs_i.sum(a, b, c, d) << endl;
    }

    return 0;
} 
