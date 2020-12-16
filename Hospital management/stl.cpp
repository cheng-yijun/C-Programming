#include<iostream>
#include<time.h>
#include <fstream>
#include <sstream>
#include "stl.h"
#include <vector>
#include <queue>

using namespace std;


stl::stl(int cap)
{
	capacity = cap;
	arr = new patient3[1000];
    for (int i=0; i<capacity; i++)
    {
        patname[i]="";
        priarr[i]=0;
        treatarr[i]=0;
    }
}

stl::~stl()
{

}

void stl::buildarr()
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

         count++;
	}
}

void stl::putinqueue()
{

    int index=0;
    int distin[400];// the unique priority number
    int cont=0;

    priority_queue<int, vector<int>, greater<int> > Q;
    for (int i=0; i < capacity; i ++)
    {
        Q.push(arr[i].prinum);
    }

    distin[0]=Q.top();


    while (!Q.empty())
    {
        if (distin[cont] != Q.top())
        {
            cont++;
            distin[cont] = Q.top();
        }
        priarr[index]=Q.top();
        Q.pop();
        index++;
    }


    int index2 = 0;

    for (int i=0; i<=cont; i++)
    {
        priority_queue<int, vector<int>, greater<int> > Q2;
        for (int j =0; j<capacity; j++)
        {
            if (arr[j].prinum == distin[i])
            {
                Q2.push(arr[j].treatment);
            }
        }

        while (!Q2.empty())
        {
            treatarr[index2] = Q2.top();
            Q2.pop();
            index2++;
        }

    }


    for (int i=0; i<capacity; i++)
    {
        for (int j=0; j<capacity;j++)
        {
            if (arr[j].prinum == priarr[i] && arr[j].treatment == treatarr[i])
            {
                patname[i] = arr[j].name;
            }
        }

    }


//successful by here

}

void stl::dequeue()
{
    for (int i = 0; i<capacity-1; i++)
    {
        patname[i] = patname[i+1];
        priarr[i] = priarr[i+1];
        treatarr[i] = treatarr[i+1];
    }
    capacity --;
}


void stl::printqueue()
{
    for (int i=0; i<capacity; i++)
    {
        cout<<patname[i]<<" "<<priarr[i]<<" "<<treatarr[i]<<endl;
    }
}


