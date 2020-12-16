#include<iostream>
#include<time.h>
#include <fstream>
#include <sstream>
#include "linklist.h"
#include <vector>
#include <queue>

using namespace std;

linklist::linklist(int cap)
{
	currentSize = 0;
	capacity = cap;
	arr = new patient2[1000];
	head = NULL;

}


linklist::~linklist()
{};


void linklist::buildarr()
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
         arr[count].name = patients;
         //cout<<heap[count].name<<endl;
         getline(ss, patients,',');
         int priority=stoi(patients);
         arr[count].prinum = priority;

         getline(ss, patients,',');
         int treatment=stoi(patients);
         arr[count].treatment = treatment;

         arr[count].next = NULL;
         arr[count].parent = NULL;
         count++;

    }
}

void linklist::putinqueue()
{
	for (int i=0; i<capacity; i++)
	{
		Q.push(&arr[i]);
	}

}



void linklist::buildll()
{

	patient2 *x = Q.front();
	Q.pop();
	head = x;
	patient2 *cur = head;
	patient2 *curprev = NULL;
	while (!Q.empty())
	{
		x=Q.front();
		Q.pop();
		cur = head;
		while (cur !=NULL)
		{
			if (x->prinum > cur->prinum || (x->prinum == cur->prinum && x->treatment > cur->treatment))
			{
				curprev = cur;
				cur = cur -> next;
			}
			else
			{
					if (cur == head)
					{
						cur->parent = x;
						x->next = cur;
						head = x;
					}
					else
					{
						cur->parent->next = x;
						x->next = cur;
						x->parent = cur->parent;
						cur->parent = x;
					}
				break;

			}
		}

		if (cur == NULL)
		{
			curprev -> next = x;
			x->parent = curprev;
		}
	}


}


void linklist::dequeue()
{
    if (head->next != NULL){
	patient2 *cur = head;
	head = head -> next;
	head->parent = NULL;
	cur -> next = NULL;

    }
    else{
        head = NULL;

    }

}

void linklist::printqueue()
{
	patient2 *cur = head;
	while (cur != NULL)
	{
		cout <<cur->name<<" "<<cur->prinum<<" "<<cur->treatment<<" " <<endl;
		cur = cur->next;
	}
}























