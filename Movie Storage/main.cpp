#include <iostream>
#include "MovieTree.cpp"
#include <sstream>
#include<string>
#include <fstream>
#include<stdlib.h>
using namespace std;

int main()
{
    MovieTree mt;
    int num = 0;
    ifstream instream;
    instream.open("Assignment6Movies.txt");
    string line;
    string ranking;
    string title;
    string year;
    string quan;
    int y;
    int r;
    int q;
    while(!instream.eof())
    {
        getline(instream,ranking,',');
        getline(instream,title,',');
        getline(instream,year,',');
        getline(instream,quan);
        r=stoi(ranking);
        y=stoi(year);
        q=stoi(quan);
         mt.addMovieNode( r,  title, y,  q);
    }
    while(num != 6)
    {
        cout<<"======Main Menu======"<<endl;
        cout<<"1. Find a movie"<<endl;
        cout<<"2. Rent a movie"<<endl;
        cout<<"3. Print the inventory"<<endl;
        cout<<"4. Delete a movie"<<endl;
        cout<<"5. Count the movies"<<endl;
        cout<<"6. Quit"<<endl;
        cin>>num;
        if (num == 1)
        {
            cout<<"Enter title:"<<endl;
            string title;
            cin.ignore();
            getline(cin,title);
            mt.findMovie(title);
        }
        if(num == 2)
        {
            cout<<"Enter title:"<<endl;
            string title;
            cin.ignore();
            getline(cin,title);
            mt.rentMovie(title);
        }
        if (num == 3)
        {
            mt.printMovieInventory();
        }
        if(num == 4)
        {
            cout<<"Enter title:"<<endl;
            string title;
            cin.ignore();
            getline(cin,title);
            mt.deleteMovieNode(title);
        }
        if (num ==5)
        {
            int cc=0;
            cc=mt.countMovieNodes();
            cout<<"Tree contains: "<<cc<<" movies."<<endl;
        }
    }
    cout<<"Goodbye!"<<endl;




    return 0;
}
