#pragma once
#include "../base.cpp"

template<class T = __int128_t>
struct BinaryIndexedTree {
    long long N, _N, height;
    vector<T> bit0, bit1, bit2;

    BinaryIndexedTree(long long n): _N(n) {
        init();
    }

    BinaryIndexedTree(const vector<T> &A): _N(A.size()) {
        init();
        rep(i, _N) add(i, A[i]);
    }

    BinaryIndexedTree(long long n, T a): _N(n) {
        init();
        add(0, n, a);
    }

    void init() {
        N = 1;
        height = 1;
        while (N < (_N + 1)) {
            N *= 2;
            ++height;
        }

        bit0.assign(N + 1, 0);
        bit1.assign(N + 1, 0);
        bit2.assign(N + 1, 0);
    }

    // 位置p (0-indexed)にxを加える
    void add(long long p, T x) {
        assert(0 <= p and p < _N);
        x *= 2;
        add(bit0, p, x);
    }

    // 半開区間[l, r) (0-indexed)にxを加える
    void add(long long l, long long r, T x) {
        assert(0 <= l and l <= r and r <= _N);
        if (l == r) return;

        x *= 2;
        add(bit0, l, -x * l);
        add(bit0, r, x * r);
        add(bit1, l, x);
        add(bit1, r, -x);
    }

    // 半開区間[l, l+1, l+2, ..., r) (0-indexed)に[al, al+d, al+2d, ..., al+d(r-l))を加える
    void add(long long l, long long r, T al, T d) {
        assert(0 <= l and l <= r and r <= _N);
        if (l == r) return;

        add(bit0, l, d * l * l + d * l - 2 * al * l);
        add(bit0, r, d * r * r + (2 * al - 2 * d * l - d) * r);
        add(bit1, l, 2 * al - 2 * d * l - d);
        add(bit1, r, -2 * al + 2 * d * l + d);
        add(bit2, l, d);
        add(bit2, r, -d);
    }

    void add_circular(long long l, long long r, T x, T d = 0) {
        assert(0 <= l and l <= _N and 0 <= r and r <= 2 * _N);
        if (l <= r and r <= _N) {
            add(l, r, x, d);
            return;
        }
        
        if (r > _N) r -= _N;
        
        add(l, _N, x, d);
        add(0, r, x + d * (_N - l), d);
    }

    // 位置p (0-indexed)をxにする
    void set(long long p, T x) {
        assert(0 <= p and p < _N);

        add(p, x - get(p));
    }

    // 半開区間[0, r) (0-indexed)の総和を求める
    T sum(long long r) {
        assert(0 <= r and r <= _N);

        return (sum(bit0, r) + sum(bit1, r) * r + sum(bit2, r) * r * r) / 2;
    }

    // 半開区間[l, r) (0-indexed)の総和を求める
    T sum(long long l, long long r) {
        assert(0 <= l and l <= r and r <= _N);

        if (l == r) return 0;
        else return sum(r) - sum(l);
    }

    T sum_circular(long long l, long long r) {
        assert(0 <= l and l <= _N and 0 <= r and r <= 2 * _N);
        if (l <= r and r <= _N) return sum(l, r);
        
        if (r > _N) r -= _N;
        
        return sum(l, _N) + sum(0, r);
    }

    // 半開区間[p, p + 1) (0-indexed)の値を求める
    T get(long long p) {
        assert(0 <= p and p < _N);
        
        return sum(p + 1) - sum(p);
    }

    // 半開区間[0, r) (0-indexed)の総和がx以上となる最小のrを求める
    long long lower_bound(T x) {
        assert(x >= 0);

        ll right = 0;
        T sum0 = 0, sum1 = 0, sum2 = 0;

        for (long long len = N; len > 0; len >>= 1) {
            ll idx = right + len;
            if (idx < _N && sum0 + bit0[idx] + (sum1 + bit1[idx]) * idx + (sum2 + bit2[idx]) * idx * idx < x * 2) {
                right += len;
                sum0 += bit0[right];
                sum1 += bit1[right];
                sum2 += bit2[right];
            }
        }

        return right + 1;
    }  

    // 半開区間[0, r) (0-indexed)の総和がxを超える最小のrを求める
    long long upper_bound(T x) {
        assert(x >= 0);

        ll right = 0;
        T sum0 = 0, sum1 = 0, sum2 = 0;

        for (long long len = N; len > 0; len >>= 1) {
            ll idx = right + len;
            if (idx < _N && sum0 + bit0[idx] + (sum1 + bit1[idx]) * idx + (sum2 + bit2[idx]) * idx * idx <= x * 2) {
                right += len;
                sum0 += bit0[right];
                sum1 += bit1[right];
                sum2 += bit2[right];
            }
        }

        return right + 1;
    }

    // 半開区間[l, r) (0-indexed)の総和がx以上となる最小のrを求める
    long long find_lower_right(T x, long long l) {
        assert(x >= 0);
        assert(0 <= l and l <= _N);

        T suml = sum(l);
        ll right = lower_bound(x + suml);

        return right;
    }

    // 半開区間[l, r) (0-indexed)の総和がxを超える最小のrを求める
    long long find_upper_right(T x, long long l) {
        assert(x >= 0);
        assert(0 <= l and l <= _N);

        T suml = sum(l);
        ll right = upper_bound(x + suml);

        return right;
    }

    // 半開区間[l, r) (0-indexed)の総和がx以上となる最大のlを求める
    // ない場合は-1を返す
    long long find_lower_left(T x, long long r) {
        assert(x >= 0);
        assert(0 <= r and r <= _N);

        T sumr = sum(r);
        ll left = upper_bound(sumr - x);
        return left - 1;
    }

    // 半開区間[l, r) (0-indexed)の総和がxを超える最大のlを求める
    // ない場合は-1を返す
    long long find_upper_left(T x, long long r) {
        assert(x >= 0);
        assert(0 <= r and r <= _N);

        T sumr = sum(r);
        ll left = lower_bound(sumr - x);
        return left - 1;
    }

    friend ostream& operator << (ostream& os, BinaryIndexedTree& bit) {
        os << "bit0" << endl;
        repd(h, bit.height) {
            for (long long i = (1 << h); i < (long long)bit.bit0.size(); i += (1 << (h + 1))) {
                os << bit.bit0[i] << " ";
            }
            os << endl;
        }
        os << endl;

        os << "bit1" << endl;
        repd(h, bit.height) {
            for (long long i = (1 << h); i < (long long)bit.bit1.size(); i += (1 << (h + 1))) {
                os << bit.bit1[i] << " ";
            }
            os << endl;
        }
        os << endl;

        os << "bit2" << endl;
        repd(h, bit.height) {
            for (long long i = (1 << h); i < (long long)bit.bit2.size(); i += (1 << (h + 1))) {
                os << bit.bit2[i] << " ";
            }
            os << endl;
        }
        os << endl;

        os << "value" << endl;
        rep(i, bit._N) {
            os << bit.get(i) << " ";
        }
        os << endl;

        return os;
    }

private:
    // 半開区間[0, r) (0-indexed)の総和を求める
    T sum(vector<T> &bit, long long r) {
        assert(0 <= r and r <= _N);

        if (r == 0) return 0;
        
        T ret = 0;
        for (int idx = r; idx > 0; idx -= (idx & -idx)) {
            ret += bit[idx];
        }
        return ret;
    }

    // 位置p (0-indexed)にxを加える
    void add(vector<T> &bit, long long p, T x) {
        assert(0 <= p and p <= _N);

        ++p; // 1-indexed

        for (int idx = p; idx < N; idx += (idx & -idx)) {
            bit[idx] += x;
        }
    }
};

// 転倒数を求める
long long calc_invension(const vector<long long> &A) {
    long long ret = 0;

    vector<long long> B = compress(A);

    long long maxB = 0;
    fore(b, B) chmax(maxB, b);

    BinaryIndexedTree<long long> tree(maxB + 1);

    rep(i, B.size()) {
        long long b = B[i];
        ret += i - tree.sum(b + 1);
        tree.add(b, 1);
    }

    return ret;
}

// [l, r)の配列に重なりがあるかを判定
bool is_overlapped(const vector<pair<long long, long long>> &A) {
    bool ret = false;
    
    long long maxA = 0;
    fore(a, A) chmax(maxA, a.second);
    BinaryIndexedTree<long long> tree(maxA + 1);

    rep(i, A.size()) {
        auto [l, r] = A[i];
        tree.add(l, 1);
        tree.add(r, -1);
    }

    rep(i, A.size()) {
        auto [l, r] = A[i];
        if (tree.sum(l, r + 1) == 0) continue;

        ret = true;
        break;
    }

    return ret;
}