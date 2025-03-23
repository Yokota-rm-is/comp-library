#define PROBLEM "https://yukicoder.me/problems/no/198"

#include "../../../search/minimize.cpp"

int main() {
    ll B, N;
    cin >> B >> N;

    vll C(N);
    rep(i, N) cin >> C[i];

    auto f = [&](ll x) {
        ll ret = 0;
        rep(i, N) {
            ret += abs(C[i] - x);
        }
        return ret;
    };

    ll right = (accumulate(C) + B) / N;

    ll x = minimize(f, 0ll, right);

    cout << f(x) << endl;

    return 0;
} 
