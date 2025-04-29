#define IGNORE
#define PROBLEM "https://atcoder.jp/contests/typical90/tasks/typical90_aq"
// https://atcoder.jp/contests/typical90/submissions/65236918

#include "../../../grid/grid-bfs.cpp"

int main() {
    ll H, W;
    cin >> H >> W;

    ll rs, cs;
    cin >> rs >> cs;

    ll rt, ct;
    cin >> rt >> ct;

    GridBFS grid(H, W);
    grid.input();

    auto gen_trans = [&](const Field& field, Coordinate now) {
        vector<pair<Coordinate, ll>> trans;
        vector<Coordinate> dirs = {Coordinate(1, 0), Coordinate(0, 1), Coordinate(-1, 0), Coordinate(0, -1)};

        rep(i, 4) {
            Coordinate next = now + dirs[i];

            while (true) {
                if (field.is_out(next)) break;
                if (field.is_hash(next)) break;

                trans.push_back({next, 1});

                next += dirs[i];
            }
        }

        return trans;
    };

    grid.bfs01(Coordinate(rs - 1, cs - 1), gen_trans);

    cout << grid.get_dist({rt - 1, ct - 1}) - 1 << endl;

    return 0;
}