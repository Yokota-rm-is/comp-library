#pragma once
#include "../base.cpp"

template <typename T, typename U> struct Pair : public pair<T, U> {
    using pair<T, U>::pair;
    constexpr Pair<T, U> operator - () const noexcept {return {-this->first, -this->second};}
    template<typename S> constexpr Pair<T, U> operator + (const S& r) const noexcept { return Pair<T, U>(*this) += {r, r}; }
    template<typename S> constexpr Pair<T, U> operator - (const S& r) const noexcept { return Pair<T, U>(*this) -= {r, r}; }
    template<typename S> constexpr Pair<T, U> operator * (const S& r) const noexcept { return Pair<T, U>(*this) *= {r, r}; }
    template<typename S> constexpr Pair<T, U> operator / (const S& r) const noexcept { return Pair<T, U>(*this) /= {r, r}; }
    constexpr Pair<T, U> operator + (const Pair<T, U>& r) const noexcept { return Pair<T, U>(*this) += r; }
    constexpr Pair<T, U> operator - (const Pair<T, U>& r) const noexcept { return Pair<T, U>(*this) -= r; }
    constexpr Pair<T, U> operator * (const Pair<T, U>& r) const noexcept { return Pair<T, U>(*this) *= r; }
    constexpr Pair<T, U> operator / (const Pair<T, U>& r) const noexcept { return Pair<T, U>(*this) /= r; }
    template<typename S> constexpr Pair<T, U>& operator += (const S& r) noexcept { this->first += r; this->second += r; return *this;}
    template<typename S> constexpr Pair<T, U>& operator -= (const S& r) noexcept { this->first -= r; this->second -= r; return *this;}
    template<typename S> constexpr Pair<T, U>& operator *= (const S& r) noexcept { this->first *= r; this->second *= r; return *this;}
    template<typename S> constexpr Pair<T, U>& operator /= (const S& r) noexcept { this->first /= r; this->second /= r; return *this;}
    template<typename S> constexpr Pair<T, U>& operator %= (const S& r) noexcept { this->first %= r; this->second %= r; return *this;}
    constexpr Pair<T, U>& operator += (const Pair<T, U>& r) noexcept { this->first += r.first; this->second += r.second; return *this;}
    constexpr Pair<T, U>& operator -= (const Pair<T, U>& r) noexcept { this->first -= r.first; this->second -= r.second; return *this;}
    constexpr Pair<T, U>& operator *= (const Pair<T, U>& r) noexcept { this->first *= r.first; this->second *= r.second; return *this;}
    constexpr Pair<T, U>& operator /= (const Pair<T, U>& r) noexcept { this->first /= r.first; this->second /= r.second; return *this;}
    constexpr Pair<T, U>& operator %= (const Pair<T, U>& r) noexcept { this->first %= r.first; this->second %= r.second; return *this;}
};

using mypairll = Pair<ll, ll>;
