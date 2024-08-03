#pragma once
#include "../base.cpp"

// エラトステネスの篩
// 計算量: O(N loglogN) (N <= 10^6)
struct Eratosthenes {
    long long N;
    // テーブル
    vector<bool> is_prime;

    // 整数 i を割り切る最小の素数
    vector<long long> min_factor;

    // メビウス関数値
    vector<long long> mobius;

    // コンストラクタで篩を回す
    explicit Eratosthenes(long long N) : N(N), is_prime(N + 1, true), min_factor(N + 1, -1), mobius(N + 1, 1) {
        // 1 は予めふるい落としておく
        is_prime[1] = false;
        min_factor[1] = 1;

        construct();
    }

    // O(N loglogN)
    void construct() {
        // 篩
        rep(p, 2, N + 1) {
            // すでに合成数であるものはスキップする
            if (!is_prime[p]) continue;

            // p についての情報更新
            min_factor[p] = p;
            mobius[p] = -1;

            // p 以外の p の倍数から素数ラベルを剥奪
            for (long long q = p * 2; q <= N; q += p) {
                // q は合成数なのでふるい落とす
                is_prime[q] = false;

                // q は p で割り切れる旨を更新
                if (min_factor[q] == -1) min_factor[q] = p;
                if ((q / p) % p == 0) mobius[q] = 0;
                else mobius[q] *= -1;
            }
        }
    }

    // 高速素因数分解 O(logN)
    // pair (素因子, 指数) の vector を返す
    vector<pair<long long, long long>> factorize(long long n) {
        vector<pair<long long, long long>> res;
        while (n > 1) {
            long long p = min_factor[n];
            long long exp = 0;

            // n で割り切れる限り割る
            while (min_factor[n] == p) {
                n /= p;
                ++exp;
            }
            res.emplace_back(p, exp);
        }
        return res;
    }

    // 高速約数列挙 O(sigma(n))
    vector<long long> divisors(long long n) {
        vector<long long> res = {1};

        // n を素因数分解 (メンバ関数使用)
        auto pf = factorize(n);

        // 約数列挙
        fore(p, pf) {
            rep(i, res.size()) {
                long long v = 1;
                rep(j, p.second) {
                    v *= p.first;
                    res.push_back(res[i] * v);
                }
            }
        }
        return res;
    }

    // 高速ゼータ変換
    // 入力 f が in-place に更新されて、F になる
    vector<long long> fast_zeta(vector<long long> f) {
        vector<long long> F(N);
        rep(i, N) F[i] = f[i];

        // 各素数 p 軸に対して
        // 大きい座標 (k * p) から小さい座標 (k) へと足し込む
        rep(p, 2, N) {
            if (!is_prime[p]) continue;

            // 座標が大きい方を起点として累積和をとる
            for (long long k = (N - 1) / p; k >= 1; --k) {
                F[k] += F[k * p];
            }
        }

        return F;
    }

    // 高速メビウス変換
    // 入力 F が in-place に更新されて、f になる
    vector<long long> fast_mobius(vector<long long> F) {
        vector<long long> f(N);
        rep(i, N) f[i] = F[i];

        // 各素数 p 軸に対して
        // 小さい座標 (k) から大きい座標 (k * p) を引いていく
        rep(p, 2, N) {
            if (!is_prime[p]) continue;

            // 座標が小さい方を起点として差分をとる
            for (long long k = 1; k * p < N; ++k) {
                f[k] -= f[k * p];
            }
        }

        return f;
    }

    // 添字 GCD 畳み込み
    vector<long long> gcd_conv(const vector<long long>& f, const vector<long long>& g) {
        vector<long long> F(N), G(N), H(N);

        // 高速ゼータ変換
        F = fast_zeta(f);
        G = fast_zeta(g);

        // H を求める
        rep(i, 1, N) H[i] = F[i] * G[i];

        // 高速メビウス変換
        fast_mobius(H);

        return H;
    }
};