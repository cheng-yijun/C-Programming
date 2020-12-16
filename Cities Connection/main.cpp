#include <iostream>
#include <fstream>
#include <sstream>
#include "Graph.hpp"

using namespace std;
int main(int argc, char * argv[])
{
    Graph gg;
    string headline;
    string lines;
    string itemArray[20][20];
    ifstream inFile;
    inFile.open(argv[1]);
    if(!inFile.eof())
    {
        getline(inFile,headline);
        while(getline(inFile,lines))
        {
            int m,n=0;
            stringstream ss(lines);
            string obj;
            //cout<<"ss";
            while(getline(ss,obj,','))
            {
                itemArray[m][n]=obj;
                n+=1;
            }
            m+=1;
        }
    }

    for(int x=0;x<15;x++)
    {
        gg.addVertex(itemArray[x][0]);
    }

    for(int i=0;i<15;i++)
    {
        for(int j=0;j<15;j++)
        {
            if(itemArray[i][j+1]!="-1"&&itemArray[i][j+1]!="0")
            {
                gg.addEdge(itemArray[i][0],itemArray[j][0],atoi(itemArray[i][j+1].c_str()));
            }
        }
    }

    string snum = "0";

    while(snum == "0")
    {
        cout << "======Main Menu======" << endl;
        cout << "1. Print vertices" << endl;
        cout << "2. Find districts" << endl;
        cout << "3. Find shortest path" << endl;
        cout << "4. Find shortest weighted path" << endl;
        cout << "5. Quit" << endl;
        cin>>snum;
        if(snum == "1")
        {
            gg.displayEdges();
            snum = "0";
        }
        else if(snum == "2")
        {
            gg.assignDistricts();
            snum = "0";
        }
        else if(snum == "3")
        {
            string starting;
            string end;
            cin.ignore();
            cout << "Enter a starting city:" << endl;
            getline(cin,starting);
            cout << "Enter an ending city:" << endl;
            getline(cin,end);
            gg.shortestPath(starting,end);
            snum = "0";
        }
        else if(snum == "4")
        {
            string starting,end;
            cin.ignore();
            cout << "Enter a starting city:" << endl;
            getline(cin,starting);
            cout << "Enter an ending city:" << endl;
            getline(cin,end);
            gg.shortestWeightedPath(starting,end);
            snum = "0";
        }
        else if(snum == "5")
        {
            cout << "Goodbye!" << endl;
            return 0;
        }
    }
    return 0;
}

*/
