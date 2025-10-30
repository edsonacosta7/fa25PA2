//
// Created by Manju Muralidharan on 10/19/25.
//

#ifndef HEAP_H
#define HEAP_H

#include <iostream>
using namespace std;

struct MinHeap {
    int data[64];
    int size;

    MinHeap() { size = 0; }

    void push(int idx, int weightArr[]) {
        // TODO: implement in next commit
        data[size] = idx;
        size++;
    }

    int pop(int weightArr[]) {
        // TODO: implement in next commit
        if (size == 0) return -1;
        int result = data[0];
        size--;
        return result;
    }

    void upheap(int pos, int weightArr[]) {
        // TODO: implement in next commit
    }

    void downheap(int pos, int weightArr[]) {
        // TODO: implement in next commit
    }
};

#endif