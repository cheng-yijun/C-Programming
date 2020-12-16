#include <iostream>
#include <fstream>
#include <sstream>
#include "Graph.hpp"
#include <vector>
#include <queue>
#include <stack>

using namespace std;

Graph::Graph() {
    // Your code here //
}

Graph::~Graph()
{}

vertex* Graph::findVertex(string name) {
    int i = 0;
    while (i <vertices.size()) {
        if (vertices[i].name == name) {
            return &vertices[i];
        }
        i++;
    }
    return nullptr;
}

void Graph::addVertex(std::string name)
{
    // Your code here
     bool found = false;
    for(int i = 0; i < vertices.size(); i++){
        if(vertices[i].name == name){
            found = true;
            cout<<vertices[i].name<<" already in the graph."<<endl;
        }
    }
    if(found == false){
        vertex v;
        v.name = name;
        v.districtID=-1;
        vertices.push_back(v);

    }
}

void Graph::DFSLabel(string startingCity, int distID)
{
    queue<vertex*> q;
    for(int i = 0; i < vertices.size(); i++)
    {
        vertices[i].visited = false;
    }
    for(int i = 0; i < vertices.size(); i++)
    {
        if (vertices[i].name == startingCity)
        {
          // set current vertex to be visited.
          // add code here
            vertices[i].visited = true;
            q.push(&vertices[i]);
            vertices[i].districtID = distID;
            break;
        }
}
}



void Graph::addEdge(std::string v1, std::string v2, int distance)
{
    // Your code here
    for(int i = 0; i < vertices.size(); i++){
        if(vertices[i].name == v1){
            for(int j = 0; j < vertices.size(); j++){
                if(vertices[j].name == v2 && i != j){
                    adjVertex av;
                    av.v = &vertices[j];
                    av.weight = distance;
                    vertices[i].adj.push_back(av);
                    //another vertex for edge in other direction
                    //adjVertex av2;
                    //av2.v = &vertices[i];
                    //av2.weight = distance;
                    //vertices[j].adj.push_back(av2);
                }
            }
        }
    }
}

void Graph::assignDistricts()
{
    int count = 0;
    std::queue<vertex*> queue;
    for(int i = 0 ; i < vertices.size() ; i++)
    {
        if(vertices[i].districtID < 0)
        {
            count ++;
            queue.push(& vertices[i]);
            while(!queue.empty())
            {
                vertex *x = queue.front();
                x -> districtID = count;
                queue.pop();
                for(int j = 0 ; j < x->adj.size() ; j++)
                {
                    if(x -> adj[j].v ->districtID < 0)
                    {
                        queue.push(x-> adj[j].v);
                    }
                }

            }
        }
    }
}

void Graph::shortestPath(string startingCity, string endingCity)
{
     int aa = 0;
     int bb = 0;
     int dis1 = 0;
     int dis2 = 0;
     for (int i=0; i<vertices.size(); i++)
     {
         vertices[i].unweightedDistance=99999;
     }
     for (int i=0; i<vertices.size(); i++)
     {
         if(vertices[i].name == startingCity)
         {
            aa = 1;
            dis1 = vertices[i].districtID;
         }
         if (vertices[i].name == endingCity)
         {
             bb = 1;
             dis2 = vertices[i].districtID;
         }
     }
     if (aa == 0||bb==0)
     {
         cout<<"One or more cities doesn't exist"<<endl;
     }
     if (aa== 1&&bb==1&&dis1 != dis2)
     {
         cout<<"No safe path between cities"<<endl;
     }
    vertex *start;
    for (int i = 0; i < (int)vertices.size(); i++) {
        vertices[i].visited = false;
        if (vertices[i].name == startingCity) {
            start = &vertices[i];
        }
    }

    queue<vertex*> queue;
    queue.push(start);
    start->visited = true;
    vertex* end = NULL;
    start->unweightedDistance=0;
    start->parent =NULL;
    while(!queue.empty())
     {

         vertex* x=queue.front();
         queue.pop();
         for(unsigned int i=0; i<x->adj.size(); i++)
         {
             if(x->adj[i].v->visited ==false)
             {
                x->adj[i].v->unweightedDistance=x->unweightedDistance+1;
                 x->adj[i].v->parent=x;
                 x->adj[i].v->visited = true;
                 if(x->adj[i].v->name == endingCity)
                 {
                     end = x->adj[i].v;
                     break;
                 }
                 queue.push(x->adj[i].v);
             }
         }
     }
     int count = 0;
     string cityname[10];
     for (int i=0; i<10; i++)
     {
         cityname[i]="";
     }
     int j = 0;
     while(end)
     {
        cityname[j]=end->name;
        count++;
        end=end->parent;
        j++;
     }
    count--;
    if (aa==1&&bb==1&&dis1==dis2)
        cout<<count;
    for (int i =count; i>=0;i--)
    {
        cout<<", "<<cityname[i];
    }
    // Your code here
    cout<<endl;
}


void Graph::shortestWeightedPath(string startingCity, string endingCity)
{
    int aa =1;
    int bb = 1;
     vertex *shortv = NULL;//store the tmp shortest vertex
     vertex *tmp = NULL;
    int dis1=0;
    int dis2=0;
    for (int i=0; i<vertices.size(); i++)
     {
         vertices[i].weightedDistance=99999;
         if (startingCity == vertices[i].name)
         {
             dis1 = vertices[i].districtID;
         }
         if (endingCity == vertices[i].name)
         {
             dis2 = vertices[i].districtID;
         }
     }
     if (dis1 == -1 ||dis2 == -1){
        cout<<"Please identify the districts before checking distances"<<endl;
        aa=0;
        }
     if (dis1>0&&dis2>0)
     {
         if (dis1!=dis2){
            cout<<"No safe path between cities"<<endl;
            bb=0;
        }
     }
     vertex *start=NULL;
     vertex *end=NULL;
     for (int i=0; i<(int)vertices.size(); i++)
     {
         vertices[i].visited = false;
         if (vertices[i].name == startingCity) {
            start = &vertices[i];
        }
        if (vertices[i].name == endingCity) {
            end = &vertices[i];
        }
     }
     start-> weightedDistance = 0;
     start-> visited = true;
     start->parent =NULL;
     vector <vertex*> q;
     q.push_back(start);
     vertex *parent = NULL;
     if (aa==1 && bb == 1){
     while (end->visited == false)
     {
         int disv = 0;// distance between each vertex and start
         int shortpath = 999999;//store the shortest path of each vertex to start
         shortv = NULL;
         //cout<<q.size();
         for (int i =0; i<q.size(); i++)
         {
             tmp = q[i];
             for (int j = 0; j < tmp->adj.size(); j++)
             {
                 if (tmp->adj[j].v->visited == false)
                 {
                     disv = tmp->weightedDistance+tmp->adj[j].weight;
                     if (disv < shortpath)
                     {
                         shortv = tmp->adj[j].v;
                         shortpath = disv;
                         parent = tmp;
                     }
                 }
             }
         }
         shortv->weightedDistance = shortpath;
         shortv->visited = true;
         shortv->parent = parent;
         q.push_back(shortv);
     }
     cout<<shortv->weightedDistance;
     string cityname[100];
     int count = 0;
     while (end)
     {
         cityname[count] = end->name;
         end = end->parent;
         count ++;
     }
     count --;
     for( int i=count; i>=0; i--)
     {
         cout<<", "<<cityname[i];
     }
     cout<<endl;
     }

    // Your code here
}


void Graph::displayEdges(){
    //loop through all vertices and adjacent vertices

    int j;
    for(int i = 0; i < vertices.size(); i++){
        cout<<vertices[i].districtID<<":"<<vertices[i].name<<"-->";
        if ( vertices[i].adj.size()>=1){
        for( j = 0; j < vertices[i].adj.size()-1; j++){
            cout<<vertices[i].adj[j].v->name<<"***";
        }
        cout<<vertices[i].adj[j].v->name;
        cout<<endl;
        }
        else
            cout<<endl;
        }
}
