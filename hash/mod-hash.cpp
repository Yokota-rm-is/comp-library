#include "../base.cpp"

bool is_prime(long long N) {
    if (N < 2) return false;
    if (N == 2) return true;
    for (long long i = 3; i * i <= N; i += 2) {
        if (N % i == 0) return false;
    }
    return true;
}

vector<long long> set_mod(size_t size = 20) {
    random_device rd;
    mt19937_64 gen(rd());
    uniform_int_distribution<int> dist(inf32, INF32);
    set<long long> primes;

    while (true) {
        int m = dist(gen);
        if (!is_prime(m)) continue;
        if (primes.contains(m)) continue;

        primes.insert(m);
        if (primes.size() == size) break;
    };

    return vector<long long>(primes.begin(), primes.end());
}
static vector<long long> mods = set_mod();

struct ModHash {
    vector<long long> hash;
    size_t size;

    ModHash() : hash(mods.size()), size(mods.size()) {}
    ModHash(long long N) : hash(mods.size()), size(mods.size()) {construct(N);}
    ModHash(string S) : hash(mods.size()), size(mods.size()) { construct(S);}

    void construct(long long N) {
        rep(i, size) hash[i] = N % mods[i];
    }

    void construct(string S) {
        rep(i, size) {
            fore(c, S) {
                hash[i] *= 10;
                hash[i] += c - '0';
                hash[i] %= mods[i];
            }
        }
    }
    
    ModHash operator + (const ModHash& r) const noexcept { return ModHash(*this) += r; }
    ModHash operator - (const ModHash& r) const noexcept { return ModHash(*this) -= r; }
    ModHash operator * (const ModHash& r) const noexcept { return ModHash(*this) *= r; }
    ModHash operator / (const ModHash& r) const noexcept { return ModHash(*this) /= r; }
    ModHash& operator += (const ModHash& r) noexcept {
        rep(i, size) {
            hash[i] += r.hash[i];
            if (hash[i] >= mods[i]) hash[i] -= mods[i];
        }
        return *this;
    }
    constexpr ModHash& operator -= (const ModHash& r) noexcept {
        rep(i, size) {
            hash[i] -= r.hash[i];
            if (hash[i] < 0) hash[i] += mods[i];
        }
        return *this;
    }
    constexpr ModHash& operator *= (const ModHash& r) noexcept {
        rep(i, size) {
            hash[i] = hash[i] * r.hash[i] % mods[i];
        }
        return *this;
    }
    constexpr ModHash& operator /= (const ModHash& r) noexcept {
        rep(i, size) {
            hash[i] = hash[i] * r.hash[i] % mods[i];
            long long a = r.hash[i], b = mods[i], u = 1, v = 0;

            while (b) {
                long long t = a / b;
                a -= t * b; swap(a, b);
                u -= t * v; swap(u, v);
            }

            hash[i] = hash[i] * u % mods[i];
            if (hash[i] < 0) hash[i] += mods[i];
        }

        return *this;
    }
    constexpr bool operator == (const ModHash& r) const noexcept {
        bool ret = true;
        rep(i, size) {
            ret &= (hash[i] == r.hash[i]);
        }
        return ret;
    }
    constexpr bool operator != (const ModHash& r) const noexcept {
        bool ret = false;
        rep(i, size) {
            ret |= (hash[i] != r.hash[i]);
        }
        return ret;
    }
    constexpr bool operator< (const ModHash &r) const noexcept {
        rep(i, size - 1) {
            if (hash[i] == r.hash[i]) continue;
            return hash[i] < r.hash[i];
        }

        return hash[size - 1] < r.hash[size - 1];
    }
};