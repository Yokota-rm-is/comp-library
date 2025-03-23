#define PROBLEM "https://atcoder.jp/contests/abc300/tasks/abc300_c"

#include "../../../grid/grid-unionfind.cpp"

struct Rectangle {
    ll top, left, bottom, right;

    Rectangle(ll t = 0, ll l = 0, ll b = 0, ll r = 0) : top(t), left(l), bottom(b), right(r) {};
};

int main() {
    ll H, W;
    cin >> H >> W;

    GridUnionFind uf(H, W);
    uf.field.obj = uf.field.dot;
    uf.dirs = {
        Coordinate(1, 1),
        Coordinate(1, -1),
        Coordinate(-1, 1),
        Coordinate(-1, -1)
    };
    uf.input();

    map<Coordinate, Rectangle> mp;
    rep(y, H) rep(x, W) {
        if (uf.field(y, x) == '.') continue;

        Coordinate now(y, x);
        Coordinate par = uf.find(now);

        if (!mp.contains(par)) mp[par] = Rectangle(y, x, y, x);
        else {
            chmin(mp[par].top, y);
            chmin(mp[par].left, x);
            chmax(mp[par].bottom, y);
            chmax(mp[par].right, x);
        }
    }

    vll ans(min(H, W), 0);
    for (auto [p, r] : mp) {
        ll h = r.bottom - r.top + 1;
        ll w = r.right - r.left + 1;
        ll size = min(h, w) / 2;
        ++ans[size - 1];
    }

    cout << ans << endl;

    return 0;
} 