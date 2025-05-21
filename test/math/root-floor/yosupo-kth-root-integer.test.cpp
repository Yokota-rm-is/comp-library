#define PROBLEM "https://judge.yosupo.jp/problem/kth_root_integer"

#include "../../../math/root-floor.cpp"

int main() {
    ll T;
    cin >> T;

    while (T--) {
        ull A, K;
        cin >> A >> K;

        ull ans = root_floor(A, K);
        cout << ans << endl;
    }
    
    return 0;
} 
