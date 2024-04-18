#include "../base.cpp"

template <typename T>
struct List : public list<T> {
    using list<T>::list;

    auto insert_before(auto it, T v) {
        return list<T>::insert(it, v);
    }

    auto insert_after(auto it, T v) {
        return list<T>::insert(next(it), v);
    }

    friend constexpr ostream& operator << (ostream &os, const List<T>& lst) noexcept {
        for (auto it = lst.begin(); it != lst.end(); ++it) {
            os << *it;
            if (it != prev(lst.end())) os << " ";
        }
        return os;
    }
};