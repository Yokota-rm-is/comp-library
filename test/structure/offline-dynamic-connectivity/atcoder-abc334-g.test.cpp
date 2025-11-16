#define IGNORE
#define PROBLEM "https://atcoder.jp/contests/abc334/tasks/abc334_g"
// https://atcoder.jp/contests/abc334/submissions/68503442

#include "../../../structure/offline-dynamic-connectivity.cpp"

int main() {
    ll H, W;
    cin >> H >> W;

    vector<string> S(H);
    rep(i, H) cin >> S[i];

    using T = ll;
    auto op = [](T a, T b) { return a + b; };
    auto inv = [](T a) { return -a; };
    OfflineDynamicConnectivity<false, T, op, inv> odc(H * W);
    ll green = 0, red = 0;
    rep(i, H) rep(j, W) {
        if (S[i][j] == '.') {
            ++red;
            continue;
        }
        ++green;
        if (i + 1 < H and S[i + 1][j] == '#') {
            odc.link(i * W + j, (i + 1) * W + j);
        }
        if (j + 1 < W and S[i][j + 1] == '#') {
            odc.link(i * W + j, i * W + j + 1);
        }
    } 

    rep(i, H) rep(j, W) {
        if (S[i][j] == '.') continue;
        if (i + 1 < H and S[i + 1][j] == '#') {
            odc.cut(i * W + j, (i + 1) * W + j);
        }
        if (j + 1 < W and S[i][j + 1] == '#') {
            odc.cut(i * W + j, i * W + j + 1);
        }
        if (i - 1 >= 0 and S[i - 1][j] == '#') {
            odc.cut(i * W + j, (i - 1) * W + j);
        }
        if (j - 1 >= 0 and S[i][j - 1] == '#') {
            odc.cut(i * W + j, i * W + j - 1);
        }
        odc.query(0);
        if (i + 1 < H and S[i + 1][j] == '#') {
            odc.link(i * W + j, (i + 1) * W + j);
        }
        if (j + 1 < W and S[i][j + 1] == '#') {
            odc.link(i * W + j, i * W + j + 1);
        }
        if (i - 1 >= 0 and S[i - 1][j] == '#') {
            odc.link(i * W + j, (i - 1) * W + j);
        }
        if (j - 1 >= 0 and S[i][j - 1] == '#') {
            odc.link(i * W + j, i * W + j - 1);
        }
    }

    odc.build();
    vll cc = odc.run([](UndoUnionFind<T, op, inv>& uf, int v) {
        return uf.cc_size;
    });

    ll MOD = 998244353;
    ll base = modinv(green, MOD);

    ll ans = 0;
    rep(i, cc.size()) {
        ans += (cc[i] - red - 1) * base;
        ans %= MOD;
    }

    cout << ans << endl;

    return 0;
} 
