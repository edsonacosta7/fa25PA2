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
        // Insert at the end
        data[size] = idx;
        size++;
        // Restore heap property from bottom up
        upheap(size - 1, weightArr);
    }

    int pop(int weightArr[]) {
        if (size == 0) return -1;

        // Store the root (smallest element)
        int minIdx = data[0];

        // Replace root with last element
        data[0] = data[size - 1];
        size--;

        // Restore heap property from top down
        if (size > 0) {
            downheap(0, weightArr);
        }

        return minIdx;
    }

    void upheap(int pos, int weightArr[]) {
        // Move element up while it's smaller than its parent
        while (pos > 0) {
            int parent = (pos - 1) / 2;

            // Compare weights of the nodes at these positions
            if (weightArr[data[pos]] < weightArr[data[parent]]) {
                // Swap with parent
                int temp = data[pos];
                data[pos] = data[parent];
                data[parent] = temp;
                pos = parent;
            } else {
                break;
            }
        }
    }

    void downheap(int pos, int weightArr[]) {
        // Move element down while it's larger than its children
        while (pos < size) {
            int leftChild = 2 * pos + 1;
            int rightChild = 2 * pos + 2;
            int smallest = pos;

            // Find the smallest among parent and children
            if (leftChild < size && weightArr[data[leftChild]] < weightArr[data[smallest]]) {
                smallest = leftChild;
            }
            if (rightChild < size && weightArr[data[rightChild]] < weightArr[data[smallest]]) {
                smallest = rightChild;
            }

            // If the smallest is not the current position, swap and continue
            if (smallest != pos) {
                int temp = data[pos];
                data[pos] = data[smallest];
                data[smallest] = temp;
                pos = smallest;
            } else {
                break;
            }
        }
    }
};

#endif