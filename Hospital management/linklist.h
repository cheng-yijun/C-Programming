#ifndef LINKLIST_H
#define LINKLIST_H
#include <iostream>
#include <queue>
using namespace std;

struct patient2
{
    string name;
    int prinum;
    int treatment;
    patient2 *next ;
    patient2 *parent ;
};

class linklist
{
	public:
		linklist(int capacity);
		~linklist();
		void buildarr();
		void putinqueue();
		void buildll();
		void dequeue();
		void printqueue();

	private:
		patient2 *arr;
		queue<patient2*> Q;
		int capacity; // maximum possible size of min heap
        int currentSize;

        patient2 *head;
};

#endif