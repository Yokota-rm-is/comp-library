#define IGNORE
#define PROBLEM "https://atcoder.jp/contests/arc005/tasks/arc005_3"
// https://atcoder.jp/contests/arc005/submissions/52537951

#include "../../../grid/grid-bfs.cpp"

int main() {
    ll H, W;
    cin >> H >> W;

    GridBFS grid(H, W);
    grid.input();

    auto gen_trans = [&](const Field& field, Coordinate now) {
        vector<Coordinate> dirs = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
        vector<pair<Coordinate, ll>> trans;
        rep(i, 4) {
            Coordinate next = now + dirs[i];
            if (field.is_out(next)) continue;
            ll c = field.is_hash(next) ? 1 : 0;

            trans.push_back({next, c});
        }

        return trans;
    };

    grid.bfs01(grid.start, gen_trans);
    ll ans = (grid.get_dist(grid.goal) <= 2);

    cout << YESNO(ans) << endl;

    return 0;
}