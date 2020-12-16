#ifndef STL_H
#define STL_H
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct patient3
{
    string name;
    int prinum;
    int treatment;
};

class stl
{
	public:
		stl(int cap);
		~stl();
		void buildarr();
		void putinqueue();
		void printqueue();
		void dequeue();



	private:
		patient3 *arr; 
        int capacity; // maximum possible size of min heap
        int currentSize;
        string patname[1000];
        int priarr[1000];
        int treatarr[1000];


};
#endif