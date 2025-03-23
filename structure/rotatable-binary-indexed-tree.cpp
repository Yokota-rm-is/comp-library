#pragma once
#include "../base.cpp"

template<class T = long long>
struct RotatableBinaryIndexedTree {
    struct BinaryIndexedTree {
        long long N, _N, height;
        vector<T> bit0, bit1;

        BinaryIndexedTree(long long n): _N(n) {
            init();
        }

        BinaryIndexedTree(const vector<T> &A): _N(A.size()) {
            init();

            rep(i, _N) add(i, A[i]);
        }

        BinaryIndexedTree(long long n, T a): _N(n) {
            init();

            rep(i, _N) add(i, a);
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
        }

        // 位置p (0-indexed)にxを加える
        void add(long long p, T x) {
            assert(0 <= p and p < _N);

            add(bit0, p, x);
        }

        // 半開区間[l, r) (0-indexed)にxを加える
        void add(long long l, long long r, T x) {
            assert(0 <= l and l <= r and r <= _N);

            if (l == r) return;

            add(bit0, l, -x * l);
            add(bit0, r, x * r);
            add(bit1, l, x);
            add(bit1, r, -x);
        }

        void add_circular(long long l, long long r, T x) {
            assert(0 <= l and l <= _N and 0 <= r and r <= 2 * _N);
            if (l <= r and r <= _N) {
                add(l, r, x);
                return;
            }
            
            if (r > _N) r -= _N;
            
            add(l, _N, x);
            add(0, r, x);
        }

        // 位置p (0-indexed)をxにする
        void set(long long p, T x) {
            assert(0 <= p and p < _N);

            add(p, x - get(p));
        }

        // 半開区間[0, r) (0-indexed)の総和を求める
        T sum(long long r) {
            assert(0 <= r and r <= _N);

            return sum(bit0, r) + sum(bit1, r) * r;
        }

        // 半開区間[l, r) (0-indexed)の総和を求める
        T sum(long long l, long long r) {
            assert(0 <= l and l <= r and r <= _N);

            if (l == r) return 0;
            else return sum(r) - sum(l);
        }

        // 半開区間[p, p + 1) (0-indexed)の値を求める
        T get(long long p) {
            assert(0 <= p and p < _N);
            
            return sum(p + 1) - sum(p);
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

    BinaryIndexedTree bit;
    long long offset;

    RotatableBinaryIndexedTree(long long n): bit(n), offset(0) {}
    RotatableBinaryIndexedTree(const vector<T> &A): bit(A), offset(0) {}
    RotatableBinaryIndexedTree(long long n, T a): bit(n, a), offset(0) {}

    void init() {
        bit.init();
        offset = 0;
    }

    long long rotate_left(long long x) {
        offset += x;
        offset %= bit._N;
        return offset;
    }

    long long rotate_right(long long x) {
        offset += bit._N - x;
        offset %= bit._N;
        return offset;
    }

    template<bool unrotate = false>
    void add(long long p, T x) {
        if constexpr (!unrotate) p = (p + offset) % bit._N;
        bit.add(p, x);
    }

    template<bool unrotate = false>
    void add(long long l, long long r, T x) {
        if (l == r) return;

        if constexpr (!unrotate) {
            l = (l + offset) % bit._N;
            r = (r + offset) % bit._N;
        }

        if (l < r) bit.add(l, r, x);
        else {
            bit.add(l, bit._N, x);
            bit.add(0, r, x);
        }
    }

    template<bool unrotate = false>
    void set(long long p, T x) {
        if constexpr (!unrotate) p = (p + offset) % bit._N;
        bit.set(p, x);
    }

    template<bool unrotate = false>
    T sum(long long r) {
        return sum(0, r, unrotate);
    }

    template<bool unrotate = false>
    T sum(long long l, long long r) {
        if (l == r) return 0;

        if constexpr (!unrotate) {
            l = (l + offset) % bit._N;
            r = (r + offset) % bit._N;
        }

        if (l < r) return bit.sum(l, r);
        else return bit.sum(l, bit._N) + bit.sum(0, r);
    }

    template<bool unrotate = false>
    T get(long long p) {
        if constexpr (!unrotate) p = (p + offset) % bit._N;
        return bit.get(p);
    }

    friend ostream& operator << (ostream& os, RotatableBinaryIndexedTree& tree) {
        os << "offset: " << tree.offset << endl;
        os << "original: " << endl;
        rep(i, tree.bit._N) {
            os << tree.get<true>(i) << " ";
        }
        os << endl;
        os << "rotated: " << endl;
        rep(i, tree.bit._N) {
            os << tree.get<false>(i) << " ";
        }
        return os;
    }
};