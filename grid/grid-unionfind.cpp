#pragma once
#include "../base.cpp"

struct Coordinate {
    long long y, x;

    Coordinate(long long y_ = 0, long long x_ = 0) : y(y_), x(x_) {};

    double euclid() {
        return sqrt(pow(y, 2) + pow(x, 2));
    }

    double euclid_from(const Coordinate &other) {
        return Coordinate(y - other.y, x - other.x).euclid();
    }

    long long manhattan() {
        return abs(y) + abs(x);
    }

    long long manhattan_from(const Coordinate &other) {
        return Coordinate(y - other.y, x - other.x).manhattan();
    }

    Coordinate char2dir(char c) {
        assert(c == 'R' or c == 'L' or c == 'U' or c == 'D');
        Coordinate ret(y, x);

        if (c == 'D') ++ret.y;
        if (c == 'U') --ret.y;
        if (c == 'R') ++ret.x;
        if (c == 'L') --ret.x;

        return ret;
    }

    char dir2char() {
        assert(manhattan() == 1);

        char ret;
        if (x > 0) ret = 'R';
        if (x < 0) ret = 'L';
        if (y > 0) ret = 'D';
        if (y < 0) ret = 'U';

        return ret;
    }

    char dir2char(Coordinate next) {
        Coordinate dir = next - *this;
        return dir.dir2char();
    }

    Coordinate& operator= (pair<long long, long long>& other) {
        y = other.first;
        x = other.second;
        return *this;
    }

    Coordinate operator- () {
        return Coordinate(y, x) *= -1;
    }

    Coordinate operator+ (const Coordinate &other) {
        return Coordinate(y, x) += other;
    }

    Coordinate operator- (const Coordinate &other) {
        return Coordinate(y, x) -= other;
    }

    Coordinate operator+ (const long long &a) {
        return Coordinate(y, x) += a;
    }

    Coordinate operator- (const long long &a) {
        return Coordinate(y, x) -= a;
    }

    Coordinate operator* (const long long &a) {
        return Coordinate(y, x) *= a;
    }

    Coordinate operator/ (const long long &a) {
        return Coordinate(y, x) /= a;
    }

    Coordinate operator% (const long long &a) {
        return Coordinate(y, x) %= a;
    }

    Coordinate& operator+= (Coordinate other) {
        this->y += other.y;
        this->x += other.x;
        return *this;
    }

    Coordinate& operator-= (Coordinate other) {
        this->y -= other.y;
        this->x -= other.x;
        return *this;
    }

    Coordinate& operator+= (long long a) {
        this->y += a;
        this->x += a;
        return *this;
    }

    Coordinate& operator-= (long long a) {
        this->y -= a;
        this->x -= a;
        return *this;
    }

    Coordinate& operator*= (long long a) {
        this->y *= a;
        this->x *= a;
        return *this;
    }

    Coordinate& operator/= (long long a) {
        this->y /= a;
        this->x /= a;
        return *this;
    }

    Coordinate& operator%= (long long a) {
        this->y %= a;
        this->x %= a;
        return *this;
    }

    friend bool operator== (const Coordinate &l, const Coordinate &r) {
        return l.y == r.y and l.x == r.x;
    }

    friend bool operator!= (const Coordinate &l, const Coordinate &r) {
        return l.y != r.y or l.x != r.x;
    }

    friend bool operator< (const Coordinate &l, const Coordinate &r) {
        if (l.y == r.y) {
            return l.x < r.x;
        }
        else return l.y < r.y;
    }

    friend bool operator> (const Coordinate &l, const Coordinate &r) {
        if (l.y == r.y) {
            return l.x > r.x;
        }
        else return l.y > r.y;
    }

    friend ostream& operator << (ostream &os, const Coordinate& p) {
        return os << "(" << p.y << ", " << p.x << ")";
    }
};

template<typename T>
struct Grid {
    long long H;
    long long W;
    vector<vector<T>> vv;

    Grid(long long h = 0, long long w = 0, T a = T()) : H(h), W(w), vv(h, vector<T>(w, a)) {}
    Grid(vector<vector<T>> A) : H(A.size()), W(A[0].size()), vv(A) {}

    bool is_out(long long y, long long x) {
        return y < 0 or y >= H or x < 0 or x >= W;
    }

    bool is_out(const Coordinate& p) {
        return p.y < 0 or p.y >= H or p.x < 0 or p.x >= W;
    }

    T& operator() (size_t i, size_t j) {
        assert(!is_out(i, j));
        return vv[i][j];
    }

    T& operator() (const Coordinate& p) {
        assert(!is_out(p));
        return vv[p.y][p.x];
    }

    void assign(long long h, long long w, T a) {
        H = h;
        W = w;
        vv.assign(h, vector<T>(w, a));
    }

    vector<T>& operator[] (size_t i) {
        return vv[i];
    } 

    friend ostream& operator << (ostream &os, Grid<T>& grid) {
        rep(i, grid.H) {
            os << grid[i] << endl;
        }
        return os;
    }
};

template<>
struct Grid<bool> {
    long long H;
    long long W;
    vector<vector<bool>> vv;

    Grid(long long h = 0, long long w = 0, bool a = false) : H(h), W(w), vv(h, vector<bool>(w, a)) {}
    Grid(vector<vector<bool>> A) : H(A.size()), W(A[0].size()), vv(A) {}

    bool is_out(long long y, long long x) {
        return y < 0 or y >= H or x < 0 or x >= W;
    }

    bool is_out(const Coordinate& p) {
        return p.y < 0 or p.y >= H or p.x < 0 or p.x >= W;
    }

    vector<bool>::reference operator() (size_t i, size_t j) {
        assert(!is_out(i, j));
        return vv[i][j];
    }

    vector<bool>::reference operator() (const Coordinate& p) {
        assert(!is_out(p));
        return vv[p.y][p.x];
    }

    void assign(long long h, long long w, bool a) {
        H = h;
        W = w;
        vv.assign(h, vector<bool>(w, a));
    }

    vector<bool>& operator[] (size_t i) {
        return vv[i];
    } 

    friend ostream& operator << (ostream &os, Grid<bool>& grid) {
        rep(y, grid.H) {
            rep(x, grid.W) {
                os << (grid[y][x] ? "true" : "false") << " ";
            }
        }
        return os;
    }
};

struct Field {
    long long H;
    long long W;
    vector<string> vs;
    char dot = '.';
    char hash = '#';
    char obj = hash;
    char excl = '!';

    Field(long long h, long long w) :H(h), W(w), vs(h, string(w, '.')) {}
    Field(vector<string>& A) : H(A.size()), W(A.front().size()), vs(A) {}

    char& operator() (size_t y, size_t x) {
        assert(!is_out(y, x));
        return vs[y][x];
    }

    char& operator() (const Coordinate& p) {
        assert(!is_out(p));
        return vs[p.y][p.x];
    }

    bool is_dot(size_t y, size_t x) {
        assert(!is_out(y, x));
        return vs[y][x] == dot;
    }

    bool is_dot(const Coordinate& p) {
        assert(!is_out(p));
        return vs[p.y][p.x] == dot;
    }

    bool is_hash(size_t y, size_t x) {
        assert(!is_out(y, x));
        return vs[y][x] == hash;
    }

    bool is_hash(const Coordinate& p) {
        assert(!is_out(p));
        return vs[p.y][p.x] == dot;
    }

    bool is_obj(size_t y, size_t x) {
        assert(!is_out(y, x));
        return vs[y][x] == obj;
    }

    bool is_obj(const Coordinate& p) {
        assert(!is_out(p));
        return vs[p.y][p.x] == obj;
    }

    bool is_excl(size_t y, size_t x) {
        assert(!is_out(y, x));
        return vs[y][x] == excl;
    }

    bool is_excl(const Coordinate& p) {
        assert(!is_out(p));
        return vs[p.y][p.x] == excl;
    }

    bool is_out(long long y, long long x) {
        return y < 0 or y >= H or x < 0 or x >= W;
    }

    bool is_out(const Coordinate& p) {
        return p.y < 0 or p.y >= H or p.x < 0 or p.x >= W;
    }

    string& operator[] (size_t i) {
        return vs[i];
    }

    friend ostream& operator << (ostream &os, Field& field) {
        rep(i, field.H) {
            os << field[i] << endl;
        }
        return os;
    }
};

struct GridUnionFind {
    long long H, W;
    Field field;
    Grid<Coordinate> size;
    Grid<Coordinate> par;
    vector<Coordinate> dirs = {
        Coordinate(0, 1),
        Coordinate(1, 0),
        Coordinate(0, -1),
        Coordinate(-1, 0),
        // Coordinate(1, 1),
        // Coordinate(1, -1),
        // Coordinate(-1, 1),
        // Coordinate(-1, -1)
    };

    char s = 's';
    char g = 'g';
    char t = 't';
    Coordinate start = Coordinate(-1, -1), goal = Coordinate(-1, -1);
    long long inf = INF64 / 2;

    long long cc_size;

    GridUnionFind(long long n) : H(n), W(n), field(n, n) {
        init();
    };

    GridUnionFind(long long h, long long w) : H(h), W(w), field(h, w) {
        init();
    };

    GridUnionFind(vector<string> vs) : H(vs.size()), W(vs.front().size()), field(vs) {
        init();
        after_input();
    };

    void init() {
        cc_size = H * W;
        par.assign(H, W, {-1, -1});
        size.assign(H, W, 1);

        rep(y, H) rep(x, W) par(y, x) = {y, x};
    }

    void input() {
        rep(y, H) cin >> field[y];
        after_input();
    }

    void after_input() {
        rep(y, H) rep(x, W) {
            Coordinate now(y, x);

            char c = field(now);
            if (c >= 'A' and c <= 'Z') c = c - 'A' + 'a';
            if (c == s)  start = Coordinate(y, x);
            if (c == g or c == t) goal = Coordinate(y, x);

            if (field.is_obj(now)) {
                size(now) = 0;
                par(now) = {-1, -1};
                continue;
            }

            rep(i, dirs.size()) {
                Coordinate next = now + dirs[i];

                if (field.is_out(next)) continue;
                if (field.is_obj(next)) continue;

                unite(now, next);
            }
        }
    }

    long long to_index(Coordinate& p) {
        return p.y * W + p.x;
    }

    Coordinate to_coordinate(long long index) {
        return Coordinate(index / W, index % W);
    }

    Coordinate find(Coordinate x) {
        if (par(x) == x) return x;

        Coordinate rx = find(par(x));
        return par(x) = rx;
    }

    // xとyを連結
    bool unite(Coordinate x, Coordinate y) {
        Coordinate rx = find(x); //xの根をrx
        Coordinate ry = find(y); //yの根をry

        if (rx == ry) return false;

        --cc_size;

        // -parはサイズを返す
        // ryの方がサイズが大きければrxとrxを入れ替える
        if (size(rx) < size(ry)) {
            swap(rx, ry);
        }

        size(rx) += size(ry); // rxのサイズを変更
        par(ry) = rx; //xとyの根が同じでない(=同じ木にない)時：yの根ryをxの根rxにつける

        return true;
    }

    bool is_same(Coordinate x, Coordinate y) { 
        return find(x) == find(y);
    }

    bool can_reach_goal() {
        assert(start != Coordinate(-1, -1) and goal != Coordinate(-1, -1));
        return find(start) == find(goal);
    }

    bool operator== (GridUnionFind &other) {
        if (H != other.H or W != other.W) return false;

        rep(y, min(H, other.H)) rep(x, min(W, other.W)) {
            if (field(y, x) != other.field(y, x)) return false;
        }

        return true;
    }

    friend ostream& operator << (ostream &os, GridUnionFind& grid) {
        return os << grid.field << endl;
    }
};