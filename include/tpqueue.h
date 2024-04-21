// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TPQUEUE_H_
#define INCLUDE_TPQUEUE_H_
#include <string>

template<typename T, int size>
class TPQueue {
 private:
    T *arr;
    int begin, end, count;

 public:
    TPQueue() : begin(0), end(0), count(0), arr(new T[size]) {}
    void push(const T& item) {
        if (count >= size) {
            throw std::string("Full");
        }
        int now = end;
        count++;
        for (int i = begin; i < end; i++) {
            if (arr[i].prior < item.prior) {
                now = i;
                break;
            }
        }
        for (int i = end; i > now; i--) {
            arr[(i % size)] = arr[((i - 1) % size)];
        }
        arr[(now % size)] = item;
        end++;
    }
    T pop() {
        if (count == 0) {
            throw std::string("Empty");
        }
        count--;
        T result = arr[begin];
        begin = (begin + 1) % size;
        return result;
    }
};
struct SYM {
  char ch;
  int prior;
};
#endif  // INCLUDE_TPQUEUE_H_
