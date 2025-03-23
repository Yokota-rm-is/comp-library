#pragma once
#include "../base.cpp"

// 参考:https://natsugiri.hatenablog.com/entry/2016/10/10/035445

template<typename T> 
struct PriorityDeque {
    vector<T> heap;

    PriorityDeque() {}

    PriorityDeque(const vector<T>& A) : heap(A) {
	    make_heap();
    }

    template<class Iter> PriorityDeque(Iter first, Iter last) : heap(first, last) {
	    make_heap();
    }

    void push(const T &x) {
    	int k = heap.size();
	    heap.push_back(x);
	    sift_up(k);
    }

    void pop_min() {
        if (heap.size() < 3) {
            heap.pop_back(); 
        } 
        else {
            swap(heap[1], heap.back());
            heap.pop_back();
            int k = sift_down(1);
            sift_up(k);
        }
    }

    void pop_max() {
        if (heap.size() < 2) { 
            heap.pop_back();
        }
        else {
            swap(heap[0], heap.back()); 
            heap.pop_back();
            int k = sift_down(0);
            sift_up(k);
        }
    }

    const T& get_min() const {
	    return heap.size() < 2 ? heap[0] : heap[1];
    }

    const T& get_max() const {
	    return heap[0];
    }

    int size() const { 
        return heap.size(); 
    }

    bool empty() const { 
        return heap.empty(); 
    }

private:
    void make_heap() {
        for(int i = heap.size(); i--;) {
            if (i & 1 && heap[i - 1] < heap[i]) swap(heap[i - 1], heap[i]);
            int k = sift_down(i);
            sift_up(k, i);
        }
    }

    inline int parent(int k) const {
	    return ((k >> 1) - 1) & ~1;
    }

    int sift_down(int k) {
        int n = heap.size();
        if (k & 1) { // min heap
            while (2 * k + 1 < n) {
                int c = 2 * k + 3;
                if (n <= c || heap[c - 2] < heap[c]) c -= 2;
                if (c < n && heap[c] < heap[k]) { 
                    swap(heap[k], heap[c]);
                    k = c;
                }
                else break;
            }
        } 
        else { // max heap
            while (2 * k + 2 < n) {
                int c = 2 * k + 4;
                if (n <= c || heap[c] < heap[c - 2]) c -= 2;
                if (c < n && heap[k] < heap[c]) { 
                    swap(heap[k], heap[c]);
                    k = c;
                }
                else break;
            }
        }
        return k;
    }

    int sift_up(int k, int root=1) {
        if ((k | 1) < heap.size() && heap[k & ~1] < heap[k | 1]) {
            swap(heap[k & ~1], heap[k | 1]);
            k ^= 1;
        }

        int p;
        while (root < k && heap[p=parent(k)] < heap[k]) { // max heap
            swap(heap[p], heap[k]);
            k = p;
        }
        while (root < k && heap[k] < heap[p=parent(k)|1]) { // min heap
            swap(heap[p], heap[k]);
            k = p;
        }
        return k;
    }
};
