#define PROBLEM "https://yukicoder.me/problems/no/843"

#include "../../../math/eratosthenes.cpp"

int main() {
    ll N;
    cin >> N;

    Eratosthenes era(N);
    vb is_prime = era.is_prime;
    vll primes;
    primes.push_back(2);

    ll ans = 0;
    rep(i, 3, N + 1, 2) if (is_prime[i]) primes.push_back(i);

    for (size_t i = 0; primes[i] * primes[i] <= 2 * N; ++i) {
        ll r2 = primes[i] * primes[i];

        for (size_t j = 0; j < primes.size() and primes[j] < r2; ++j) {
            ll p = primes[j];
            ll q = r2 - p;
            if (q > N) continue;
            if (is_prime[q]) ++ans;
        }
    }

    cout << ans << endl;

    return 0;
}