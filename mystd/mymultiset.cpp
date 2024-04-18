#include "../base.cpp"

template <typename T>
struct MultiSet : public map<T, long long> {
    long long N;

    explicit MultiSet() : N(0) {};

    long long insert(T x) {
        ++N;
        return ++(*this)[x];
    }

    long long erase(T x) {
        --N;
        --(*this)[x];

        if ((*this)[x] == 0) {
            map<T, long long>::erase(x);
            return 0;
        }
        else {
            return (*this)[x];
        }
    }

    T front() {
        return map<T, long long>::begin()->first;
    }

    T back() {
        return map<T, long long>::rbegin()->first;
    }

    void pop() {
        erase(front());
    }

    void pop_back() {
        erase(back());
    }

    long long count_all() {
        return N;
    }

    long long count(T x) {
        if (!map<T, long long>::contains(x)) return 0;
        return (*this)[x];
    }
};