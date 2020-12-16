#include<iostream>
#include<time.h>
#include <fstream>
#include <sstream>
#include "MinHeap.h"
#include <vector>
#include <queue>

using namespace std;



// A class for Min Heap


MinHeap::MinHeap(int cap)
{
    currentSize = 0;
    capacity = cap;
    heap = new patient[1000]; //store the data
    heap2 = new patient[1000];//oprrate the data
}

MinHeap::~MinHeap()
{
    delete [] heap;
}

void MinHeap::buildheap()
{
  int count = 0;
    string line;
    string patients;

    ifstream instream;
    instream.open("patientData2270.csv");

    string firstline;
    getline(instream,firstline,'\r');

    while(getline(instream,line,'\r'))
    {
        stringstream ss(line);
         //string pregent;
         getline(ss, patients,',');
         heap[count].name = patients;
         //cout<<heap[count].name<<endl;
         getline(ss, patients,',');
         int priority=stoi(patients);
         heap[count].prinum = priority;

         getline(ss, patients,',');
         int treatment=stoi(patients);
         heap[count].treatment = treatment;

         count++;

    }

    //successful by here
}

void MinHeap::smallmain()
{

  //cout<<heap[0].name;
  for (int i =0; i<capacity; i++)
  {
    push(heap[i]);
  }

  for (int i=0; i<capacity; i++)
  {
    heap[i] = pop();
  }





  //cout<<heap2[0].treatment;
  //successful by here
}

void MinHeap::printqueue()
{
  for (int i=0; i<capacity; i++)
  {
    cout<<heap[i].name<<" "<<heap[i].prinum<<" "<<heap[i].treatment<<endl;
  }

}

void MinHeap::dequeue()
{
     for (int i = 0; i<capacity-1; i++)
    {
        heap[i] = heap[i+1];

    }
    capacity --;
}

void MinHeap::push(patient &heap)
{
    if (currentSize == capacity)
    {
        cout << "At capacity, cannot insert key." << endl;
    }

    else {
        currentSize++;
        int i = currentSize - 1;
        heap2[i] = heap; // we can insert at currentSize b/c we ignore 0

        // Fix the min heap property if it is violated
        while (i != 0 &&( heap2[parent(i)].prinum > heap2[i].prinum || (heap2[parent(i)].prinum == heap2[i].prinum && heap2[parent(i)].treatment > heap2[i].treatment )))
        {

           swap(&heap2[i], &heap2[parent(i)]);
           i = parent(i);
        }
    }
}


 void MinHeap::swap(patient *x, patient *y)
{
    patient temp = *x;
    *x = *y;
    *y = temp;
}


// for now, just return -1 if there's nothing to pop
patient MinHeap::pop()
{
    //if (currentSize <= 0)
    //  return ;
    if (currentSize == 1)
    {
        currentSize--;
        return heap2[0];
    }

    patient poppedVal = heap2[0];
    heap2[0] = heap2[currentSize-1];
    currentSize--;
    MinHeapify(0);

    return poppedVal;
}

// This method assumes that the subtrees are already heapified
void MinHeap::MinHeapify(int i)
{
    int leftChild = left(i);
    int rightChild = right(i);
    int smallest = i;

    /*
if (leftChild < currentSize && heap2[leftChild].prinum == heap2[i].prinum)
        {
          if (heap2[leftChild].treatment < heap2[i].treatment)
            smallest = leftChild;
        }

    if (rightChild < currentSize && heap2[rightChild].prinum == heap2[i].prinum)
    {
        if (heap2[rightChild].treatment < heap2[i].treatment)
          smallest = rightChild;
    }
    */
    if (leftChild < currentSize && heap2[leftChild].prinum <= heap2[smallest].prinum)
    {
        if (heap2[leftChild].prinum == heap2[smallest].prinum)
        {
          if (heap2[leftChild].treatment < heap2[smallest].treatment)
          {
              smallest = leftChild;
          }
        }

        else
          smallest = leftChild;
    }


    if (rightChild < currentSize && heap2[rightChild].prinum <= heap2[smallest].prinum)
     {
        if (heap2[rightChild].prinum == heap2[smallest].prinum)
        {
            if (heap2[rightChild].treatment < heap2[smallest].treatment)
            {
              smallest = rightChild;
            }
        }

        else
          smallest = rightChild;
     }



    if (smallest != i)
    {
        swap(&heap2[i], &heap2[smallest]);
        MinHeapify(smallest);
    }
}


/*
void MinHeap::printHeap() {
    cout << "The heap array is currently {";
    for (int i = 0; i < currentSize; i++)
    {
        cout << heap[i];
        if (i < currentSize-1) {
            cout << ", ";
        }
    }
    cout << "}" << endl;


}

*/
