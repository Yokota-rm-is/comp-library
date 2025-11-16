#define IGNORE
#define PROBLEM "https://atcoder.jp/contests/abc398/tasks/abc398_d"
// https://atcoder.jp/contests/abc398/submissions/66073457

#include "../../../other/rotatable-map-2d.cpp"

int main() {
    ll N, R, C;
    cin >> N >> R >> C;

    string S;
    cin >> S;

    RotatableMap2D<ll, ll> rm;
    rm(0, 0) = 1;

    string ans(N, '0');
    rep(i, N) {
        if (S[i] == 'N') rm.subtract_key_y(1);
        else if (S[i] == 'S') rm.add_key_y(1);
        else if (S[i] == 'W') rm.subtract_key_x(1);
        else if (S[i] == 'E') rm.add_key_x(1);

        rm(0, 0) = 1;
        if (rm.contains(R, C)) ans[i] = '1';
    }

    cout << ans << endl;

    return 0;
} 