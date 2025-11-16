#define IGNORE
#define PROBLEM "https://atcoder.jp/contests/abc398/tasks/abc398_d"
// https://atcoder.jp/contests/abc398/submissions/66073368

#include "../../../other/rotatable-set-2d.cpp"

int main() {
    ll N, R, C;
    cin >> N >> R >> C;

    string S;
    cin >> S;

    RotatableSet2D<ll> rs;
    rs.insert(0, 0);

    string ans(N, '0');
    rep(i, N) {
        if (S[i] == 'N') rs.subtract_key_y(1);
        else if (S[i] == 'S') rs.add_key_y(1);
        else if (S[i] == 'W') rs.subtract_key_x(1);
        else if (S[i] == 'E') rs.add_key_x(1);

        rs.insert(0, 0);
        if (rs.contains(R, C)) ans[i] = '1';
    }

    cout << ans << endl;

    return 0;
} 