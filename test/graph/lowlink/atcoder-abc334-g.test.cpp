#define IGNORE
#define PROBLEM "https://atcoder.jp/contests/abc334/tasks/abc334_g"
// https://atcoder.jp/contests/abc334/submissions/68510231

#include "../../../graph/lowlink.cpp"

int main() {
    ll H, W;
    cin >> H >> W;

    vector<string> S(H);
    rep(i, H) cin >> S[i];
    
    LowLink graph(H * W);
    ll green = 0, red = 0;
    rep(i, H) rep(j, W) {
        if (S[i][j] == '.') {
            red++;
            continue;
        }
        
        green++;
        if (i + 1 < H and S[i + 1][j] == '#') {
            graph.connect(i * W + j, (i + 1) * W + j);
        }
        if (j + 1 < W and S[i][j + 1] == '#') {
            graph.connect(i * W + j, i * W + j + 1);
        }
    } 

    graph.build();

    vvll cc(H, vll(W, 0));

    rep(i, H) rep(j, W) {
        if (S[i][j] == '.') continue;

        cc[i][j] = graph.count_cc_if_removed_vertex(i * W + j) - red;
    }

    ll MOD = 998244353;
    ll base = modinv(green, MOD);

    ll ans = 0;
    rep(i, H) rep(j, W) {
        ans += cc[i][j] * base;
        ans %= MOD;
    }

    cout << ans << endl;

    return 0;
} 
