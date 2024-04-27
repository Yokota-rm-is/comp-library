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

    bool operator== (const Coordinate &other) {
        return y == other.y and x == other.x;
    }

    bool operator!= (const Coordinate &other) {
        return y != other.y or x != other.x;
    }

    bool operator< (const Coordinate &other) {
        if (y == other.y) {
            return x < other.x;
        }
        else return y < other.y;
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

    T& operator() (size_t i, size_t j) {
        return vv[i][j];
    }

    T& operator() (const Coordinate& p) {
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

    vector<bool>::reference operator() (size_t i, size_t j) {
        return vv[i][j];
    }

    vector<bool>::reference operator() (const Coordinate& p) {
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
        rep(i, grid.H) {
            os << grid[i] << endl;
        }
        return os;
    }
};

struct Field {
    long long H;
    long long W;
    vector<string> vs;
    char obj = '#';
    char excl = '!';

    Field(long long h, long long w) :H(h), W(w), vs(h, string(w, '.')) {}
    Field(vector<string>& A) : H(A.size()), W(A.front().size()), vs(A) {}

    char& operator() (size_t y, size_t x) {
        return vs[y][x];
    }

    char& operator() (const Coordinate& p) {
        return vs[p.y][p.x];
    }

    bool is_obj(size_t y, size_t x) {
        return vs[y][x] == obj;
    }

    bool is_obj(const Coordinate& p) {
        return vs[p.y][p.x] == obj;
    }

    bool is_excl(size_t y, size_t x) {
        return vs[y][x] == excl;
    }

    bool is_excl(const Coordinate& p) {
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

struct GridDFS {
    long long H, W;
    Field field;
    Grid<bool> seen;
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
    vector<char> path;

    char s = 's';
    char g = 'g';
    char t = 't';
    char obs = '#';
    char excl = '!';
    Coordinate start = Coordinate(-1, -1), goal = Coordinate(-1, -1);
    long long inf = INF64 / 2;
    long long group;

    GridDFS(long long n) : H(n), W(n), field(n, n) {
        init();
    };

    GridDFS(long long h, long long w) : H(h), W(w), field(h, w) {
        init();
    };

    GridDFS(vector<string> vs) : H(vs.size()), W(vs.front().size()), field(vs) {
        init();
    };

    void init() {
        group = 0;
        seen.assign(H, W, false);
    }

    void input() {
        rep(y, H) cin >> field[y];
        
        rep(y, H) rep(x, W) {
                char c = field(y, x);
                if (c >= 'A' and c <= 'Z') c = c - 'A' + 'a';
                if (c < 'a' or c > 'z') continue;

                if (c == s) {
                    start = Coordinate(y, x);
                }
                if (c == g or c == t) {
                    goal = Coordinate(y, x);
                }
            }
    }

    long long dfs_all() {
        rep(y, H) rep(x, W) {
            Coordinate now(y, x);

            if (seen(now)) continue;
            if (field.is_obj(now)) continue;

            dfs(now);
            ++group;
        }

        return group;
    }

    void dfs() {
        assert(start.y != -1);
        dfs(start);
    }

    void dfs(Coordinate now) {
        seen(now) = true;

        rep(i, dirs.size()) {
            Coordinate next = now + dirs[i];

            if (field.is_out(next)) continue;
            if (field.is_obj(next)) continue;
            if (seen(next)) continue;

            path.push_back(dirs[i].dir2char());
            dfs(next);
            path.push_back(dirs[(i + 2) % 4].dir2char());
        }
    }

    vector<Coordinate> spiral_search() {
        Coordinate now(0, 0);
        ll idx = 0;
        Coordinate dir = dirs[idx];
        vector<Coordinate> ret;

        rep(i, H * W) {
            seen(now) = true;
            ret.push_back(now);

            // 処理をここに書く

            Coordinate next = now + dir;
            if (field.is_out(next) or seen(next)) {
                ++idx;
                idx %= 4;
                dir = dirs[idx];
            }
            now += dir;
        }
        return ret;
    }

    bool reach_goal() {
        return reach(goal);
    }

    bool reach(Coordinate to) {
        return seen(to);
    }

    bool operator== (GridDFS &other) {
        if (H != other.H or W != other.W) return false;

        rep(y, min(H, other.H)) rep(x, min(W, other.W)) {
            if (field(y, x) != other.field(y, x)) return false;
        }

        return true;
    }

    friend ostream& operator << (ostream &os, GridDFS& grid) {
        return os << grid.field << endl;
    }
};