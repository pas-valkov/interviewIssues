#pragma once


class Ring {
public:
    explicit Ring(size_t size);
    Ring(int size) = delete;
    bool Add(int val);
    bool Take(int& val);
    size_t Size();
    ~Ring();
    void Check();

private:
    size_t size_limit;
    size_t cur_size;
    size_t first;
    int last;
    int* data;
};