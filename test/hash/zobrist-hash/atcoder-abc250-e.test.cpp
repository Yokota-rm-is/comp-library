#define PROBLEM "https://atcoder.jp/contests/abc250/tasks/abc250_e"

#include "../../../hash/zobrist-hash.cpp"

int main() {
    ll N;
    cin >> N;

    vll A(N), B(N);
    rep(i, N) cin >> A[i];
    rep(i, N) cin >> B[i];

    vector<ZobristHash<false>> hashA(N + 1), hashB(N + 1);
    setll setA, setB;
    rep(i, N) {
        hashA[i + 1] = hashA[i];
        if (!setA.contains(A[i])) {
            hashA[i + 1].insert(A[i]);
            setA.insert(A[i]);
        }

        hashB[i + 1] = hashB[i];
        if (!setB.contains(B[i])) {
            hashB[i + 1].insert(B[i]);
            setB.insert(B[i]);
        }
    }

    ll Q;
    cin >> Q;
    
    rep(i, Q) {
        ll x, y;
        cin >> x >> y;

        ZobristHash hash_x = hashA[x];
        ZobristHash hash_y = hashB[y];

        if (hash_x == hash_y) cout << "Yes" << endl;
        else cout << "No" << endl;
    }

    return 0;
} 