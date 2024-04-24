#define IGNORE
#define PROBLEM "https://atcoder.jp/contests/abc350/tasks/abc350_e"

#include "../../../search/memoization.cpp"

ll A, X, Y;

struct F : Memoization<long long, double> {
    F() {};

    double f(long long key) {
        if (key <= 0) return 0;

        double ret = (double)inf64;
        chmin(ret, X + get(floor(key, A)));
        double cost = 0;
        rep(i, 2, 7) cost += (double)Y * 1.2 + get(floor(key, i));
        cost /= 5;
        chmin(ret, cost); 

        return ret;
    }
};

int main() {
    ll N;
    cin >> N >> A >> X >> Y;

    F f;
    cout << fixed << setprecision(10);
    cout << f.f(N) << endl;
}