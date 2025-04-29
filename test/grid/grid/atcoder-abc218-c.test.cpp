#define IGNORE
#define PROBLEM "https://atcoder.jp/contests/abc218/tasks/abc218_c"

#include "../../../grid/grid.cpp"

int main() {
    ll N;
    cin >> N;

    vector<string> S(N), T(N);
    rep(i, N) cin >> S[i];
    rep(i, N) cin >> T[i];

    Grid<char> gridS(S), gridT(T);
    rep(r, 4) {
        rep(i, N) {
            rep(j, N) {
                debug(gridS);
                if (gridS == gridT) {
                    cout << "Yes" << endl;
                    return 0;
                }
                gridS.translate({0, 1});
            }
            gridS.translate({1, 0});
        }
        gridS.rotate_90_clockwise();
    } 

    cout << "No" << endl;

    return 0;
}