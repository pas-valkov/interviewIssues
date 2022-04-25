#include <iostream>
#include "Ring.hpp"


Ring::Ring(size_t size) : size_limit(size), cur_size(0), first(0), last(0) {
    data = new int[size_limit];
}

Ring::~Ring() {
    delete[] data;
}

bool Ring::Add(int val) {
    if (cur_size == size_limit) {
        return false;
    }

    last = last % size_limit;
    data[last] = val;
    last++;
    cur_size++;

    return true;
}

bool Ring::Take(int &val) {
    if (cur_size == 0) {
        return false;
    }

    val = data[first];
    first = (first + 1 == size_limit) ? 0 : first + 1;
    cur_size--;

    return true;
}

size_t Ring::Size() {
    return cur_size;
}

// prints all elements from Ring in FIFO order
void Ring::Check() {
    if (cur_size != 0) {
        if (first <= last) {
            for (int i = first; i < last; ++i) {
                std::cout << data[i] << " ";
            }
        }
        else if (first > last) {
            for (int i = first; i < size_limit; ++i) {
                std::cout << data[i] << " ";
            }
            for (int i = 0; i < last; ++i) {
                std::cout << data[i] << " ";
            }
        }
    }
    std::cout << std::endl;
}