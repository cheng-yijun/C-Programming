#ifndef MINHEAP_H
#define MINHEAP_H
#include <iostream>
#include <vector>
using namespace std;

struct patient
{
    string name;
    int prinum;
    int treatment;
};


class MinHeap
{
    public:
        MinHeap(int capacity);
        ~MinHeap();
        void push( patient &heap);
        patient pop();
        patient peek() { return heap[1]; }
        void printHeap();
        void buildheap();
        void smallmain();
        void printqueue();
        void dequeue();
    private:
        patient *heap; // pointer to array of elements in heap
        patient *heap2;
        int capacity; // maximum possible size of min heap
        int currentSize; // Current number of elements in min heap
        void MinHeapify(int index);
        int parent(int i) { return (i-1)/2; }
        int left(int i) { return (2*i+1); }
        int right(int i) { return (2*i + 2); }
        void swap(patient *x, patient *y);
};

#endif
