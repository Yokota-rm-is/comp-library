#pragma once
#include "../base.cpp"

template <class T = long long>
struct RangeSet {
    T sum;
    set<pair<T, T>> st;

    RangeSet() {
        init();
    }

    void init() {
        sum = 0;
        st.clear();
        st.emplace(-inf64, -inf64);
        st.emplace(inf64, inf64);
    }

    // [l, r) is covered?
	bool covered(const T l, const T r) {
		assert(l <= r);
		if (l == r) return true;

		auto p = prev(st.upper_bound({l, inf64}));

		return p->first <= l and r <= p->second;
	}

	// [x, x + 1) is covered?
	bool covered(const T x) { 
        return covered(x, x + 1);
    }
    
	// return section which covers[l, r)
	// if not exists, return[-inf64, -inf64)
	std::pair<T, T> covered_by(const T l, const T r) {
		assert(l <= r);

		if (l == r) return {-inf64, -inf64};

		auto p = prev(st.upper_bound({l, inf64}));
		if (p->first <= l and r <= p->second) return *p;
		return {-inf64, -inf64};
	}

	// return section which covers[x, x + 1)
	// if not exists, return[-inf64, -inf64)
	std::pair<T, T> covered_by(const T x) {
        return covered_by(x, x + 1);
    }

	// insert[l, r), and return increment
	T insert(T l, T r) {
		assert(l <= r);

		if (l == r) return T(0);
        
		auto p = prev(st.upper_bound({l, inf64}));

		if (p->first <= l and r <= p->second) return T(0);

		T sum_erased = T(0);
		if (p->first <= l and l <= p->second) {
			l = p->first;
			sum_erased += p->second - p->first;
			p = st.erase(p);
		} 
        else p = next(p);

		while (r > p->second) {
			sum_erased += p->second - p->first;
			p = st.erase(p);
		}

		if (p->first <= r) {
			sum_erased += p->second - p->first;
			r = p->second;
			st.erase(p);
		}

		st.emplace(l, r);
		sum += r - l - sum_erased;
		return r - l - sum_erased;
	}

	// insert[x, x + 1), and return increment
	T insert(const T x) {
        return insert(x, x + 1);
    }

	// erase [l, r), and return decrement
	T erase(const T l, const T r) {
		assert(l <= r);

		if (l == r) return T(0);

		auto p = prev(st.upper_bound({l, inf64}));

		if (p->first <= l and r <= p->second) {
			if (p->first < l) st.emplace(p->first, l);
			if (r < p->second) st.emplace(r, p->second);
			st.erase(p);
			sum -= r - l;
			return r - l;
		}

		T ret = T(0);
		if (p->first <= l and l < p->second) {
			ret += p->second - l;
			if (p->first < l) st.emplace(p->first, l);
			p = st.erase(p);
		} 
        else p = next(p);

		while (p->second <= r) {
			ret += p->second - p->first;
			p = st.erase(p);
		}

		if (p->first < r) {
			ret += r - p->first;
			st.emplace(r, p->second);
			st.erase(p);
		}

		sum -= ret;
		return ret;
	}

	// erase [x, x + 1), and return decrement
	T erase(const T x) {
        return erase(x, x + 1);
    }

	int size() const {
        return (int)st.size() - 2;
    }

	T mex(const T x = 0) const {
		auto p = prev(st.upper_bound({x, inf64}));

		if (p->first <= x and x < p->second) return p->second;
		else return x;
	}

	T sum_all() const {
        return sum;
    }

	std::set<std::pair<T, T>> get() const {
		std::set<std::pair<T, T>> res;

		for (auto &p : st) {
			if (std::abs(p.first) == inf64) continue;
			res.emplace(p.first, p.second);
		}
		return res;
	}

    friend ostream& operator << (ostream& os, const RangeSet& rst) {
        os << '\n';
        for (auto &p : rst.st) {
            if (abs(p.first) == rst.inf64) continue;
            os << "[" << p.first << "," << p.second << "),";
        }

        return os;
    }
};