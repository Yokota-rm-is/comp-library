#define PROBLEM "https://judge.yosupo.jp/problem/primality_test"

#include "../../../math/miller-rabin.cpp"

int main() {
    ll Q;
    cin >> Q;

    while (Q--) {
        ll N;
        cin >> N;

        cout << YesNo(is_prime(N)) << endl;
    }
    
    return 0;
} 
