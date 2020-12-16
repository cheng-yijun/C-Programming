#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <queue>
#include <time.h>
#include "priorityheap.cpp"
#include "linklist.cpp"
#include "stl.cpp"
#include <vector>
#include <queue>
#include <stack>
#include <math.h>

using namespace std;

int main()
{	//mh.printqueue();




	//cout<<" The mean runtime for the linked list implementation processing 880 patients after 500 times is: "<<meantime2<<endl;



	//ll.dequeue();//delete element
	//ll.printqueue();


	//cout<<" The mean runtime for the STL implementation processing 880 patients after 500 times is: "<<meantime3<<endl;


	//st.dequeue();
	//st.printqueue();


    int num = 1;

    int linenum[8] = {100,200,300,400,500,600,700,880};
    MinHeap mhz(880);
    linklist llz(880);
    stl stz(880);
    while (num != 13)
    {
    cout<<"1.Build Heap priority queue."<<endl;
    cout<<"2.Build LL priority queue."<<endl;
    cout<<"3.Build STL priority queue."<<endl;
    cout<<"4. Build Heap priority queue 8 times and show runtime."<<endl;
    cout<<"5. Build LL priority queue 8 times and show runtime."<<endl;
    cout<<"6. Build STL priority queue 8 times and show runtime."<<endl;
    cout<<"7.dequeue Heap priority queue."<<endl;
    cout<<"8.dequeue LL priority queue."<<endl;
    cout<<"9.dequeue STL priority queue."<<endl;
    cout<<"10.print Heap priority queue."<<endl;
    cout<<"11.print LL priority queue."<<endl;
    cout<<"12.print STL priority queue."<<endl;
    cout<<"13. Quit"<<endl;


        cin>>num;

        if (num == 1)
        {
            mhz.buildheap();
            mhz.smallmain();
        }

        if (num == 2)
        {
            llz.buildarr();
            llz.putinqueue();
            llz.buildll();
        }
        if (num == 3)
        {
             stz.buildarr();
             stz.putinqueue();
        }



        if (num == 4)
        {

            for(int j=0; j<8;j++)
            {
                double times1[500];
                for (int i=0; i< 500; i++)
                {
                    int t1;
                    int t2;
                    t1 = clock();
                    MinHeap mh(linenum[j]);
                    mh.buildheap();
                    mh.smallmain();

                    t2 = clock();
                    times1[i]= (double)(t2-t1)/CLOCKS_PER_SEC;
                    //cout<<times1[i]<<endl;
                }

                double totaltime1 = 0;
                for (int i=0; i<500; i++)
                {
                    totaltime1 += times1[i];
                }

                double meantime1 = totaltime1 / 500;
                double ss = 0;
                for (int k=0; k<500; k++)
                {
                    ss = ss + (times1[k]-meantime1)*(times1[k]-meantime1);
                }
                ss=ss/500;
                ss = sqrt(ss);
                cout<<"In heap implementation, The Runtime of reading "<< linenum[j]<<" rows is: "<<meantime1<<" And its standard deviation is: "<<ss<<endl;
            }

        }

        if (num == 5)
        {
            for (int j=0;j<8;j++)
            {
                double times2[500];
                for (int i=0; i< 500; i++)
                {
                    int t4;
                    int t5;
                    t4 = clock();
                    linklist ll(linenum[j]);
                    ll.buildarr();
                    ll.putinqueue();
                    ll.buildll();

                    t5 = clock();
                    times2[i] = (double)(t5-t4)/CLOCKS_PER_SEC;
                    //cout<<times2[i]<<endl;
                }

                double totaltime2 = 0;
                for (int i=0; i<500; i++)
                {
                    totaltime2 += times2[i];
                }

                double meantime2 = totaltime2 / 500;
                 double ss2 = 0;
                for (int k=0; k<500; k++)
                {
                    ss2 = ss2 + (times2[k]-meantime2)*(times2[k]-meantime2);
                }
                ss2=ss2/500;
                ss2 = sqrt(ss2);
                cout<<"In LL implementation, The Runtime of reading "<< linenum[j]<<" rows is: "<<meantime2<<" And its standard deviation is: "<<ss2<<endl;
            }
        }

        if (num == 6)
        {
            for (int j=0;j<8;j++)
            {
                double times3[500];
                for (int i=0; i< 500; i++)
                {
                    int t7;
                    int t8;
                    t7 = clock();

                    stl st(linenum[j]);
                    st.buildarr();
                    st.putinqueue();

                    t8 = clock();
                    times3[i] = (double)(t8-t7)/CLOCKS_PER_SEC;
                    //cout<<times3[i]<<endl;
                }
                double totaltime3 = 0;
                for (int i=0; i<500; i++)
                {
                    totaltime3 += times3[i];
                }
                double meantime3 = totaltime3 / 500;
                 double ss3 = 0;
                for (int k=0; k<500; k++)
                {
                    ss3 = ss3 + (times3[k]-meantime3)*(times3[k]-meantime3);
                }
                ss3=ss3/500;
                ss3 = sqrt(ss3);
                cout<<"In STL implementation, The Runtime of reading "<< linenum[j]<<" rows is: "<<meantime3<<" And its standard deviation is: "<<ss3<<endl;
            }

        }

        if (num == 7)
        {
            mhz.dequeue();
        }

        if (num == 8)
        {
            llz.dequeue();
        }
        if (num == 9)
        {
            stz.dequeue();
        }
        if (num == 10)
        {
            mhz.printqueue();
        }
        if (num == 11)
        {
            llz.printqueue();
        }
        if (num == 12)
        {
            stz.printqueue();
        }


    }

    cout<<"Goodbye"<<endl;



	return 0;


}
