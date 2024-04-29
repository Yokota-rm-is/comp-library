#pragma once
#include "../base.cpp"

template <typename T>
struct List : public list<T> {
    using iterator = typename list<T>::iterator;

    // リストの先頭に要素を追加し、その要素のイテレータを返す
    iterator push_front(const T& val) {
        list<T>::push_front(val);
        return this->begin();
    }

    // リストの末尾に要素を追加し、その要素のイテレータを返す
    iterator push_back(const T& val) {
        list<T>::push_back(val);
        return prev(this->end());
    }

    // 指定されたイテレータの前に値を挿入し、新しい要素のイテレータを返す
    iterator insert_before(iterator pos, const T& val) {
        return this->insert(pos, val);
    }

    // 指定されたイテレータの後に値を挿入し、新しい要素のイテレータを返す
    iterator insert_after(iterator pos, const T& val) {
        iterator nextPos = next(pos);
        return this->insert(nextPos, val);
    }   

    friend constexpr ostream& operator << (ostream &os, const List<T>& lst) noexcept {
        for (auto it = lst.begin(); it != lst.end(); ++it) {
            os << *it;
            if (it != prev(lst.end())) os << " ";
        }
        return os;
    }
};