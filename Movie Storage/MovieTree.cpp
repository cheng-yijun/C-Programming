#include <iostream>
#include <string>
#include <fstream>
#include<sstream>
using namespace std;
#include "MovieTree.hpp"

MovieTree::MovieTree()
{
    root = nullptr;
}

MovieTree::~MovieTree()
{
    DeleteAll(root);
}

void MovieTree::addMovieNode(int ranking, string title, int releaseYear, int quantity) {

    char let = title[0];
    if (root == NULL)
    {
        root = new MovieNodeBST(let);
        root->head = new MovieNodeLL(ranking, title, releaseYear, quantity);
    }
    else if(root != NULL)
    {
        MovieNodeBST* tmpNode = root;
	    MovieNodeBST* curparent = NULL;
        while (tmpNode != NULL)
        {
            curparent = tmpNode;
            if (tmpNode->letter == let)
            {
                MovieNodeLL *newnew = new MovieNodeLL(ranking, title, releaseYear, quantity);
                MovieNodeLL *cur = tmpNode->head;
                MovieNodeLL *dcur = tmpNode->head;
                //MovieNodeLL *daoshudier = tmpNode->head;
                MovieNodeLL *curcur = tmpNode->head;
                int k = 1;
                int j = 1;

                while (title[k]==tmpNode->head->title[k])
                {
                    k++;
                }
                while(cur->next != NULL)
                {
                    cur = cur -> next;
                }
                while (title[j]==cur->title[j])
                {
                    j++;
                }
                if (title[k]<tmpNode->head->title[k])
                {

                    newnew->next = tmpNode->head;
                    tmpNode->head = newnew;
                    break;
                }

                else if (title[j]>cur->title[j])
                {

                    cur ->next = newnew;
                    break;
                }

                else
                {
                    while(curcur  != NULL)
                    {
                        int z = 1;
                        while (title[z]==curcur->title[z])
                        {
                            z++;
                        }
                        if (title[z]>curcur->title[z])
                        {
                            dcur = curcur;
                            curcur = curcur ->next;
                        }
                        else
                        {
                            dcur->next = newnew;
                            newnew->next = curcur;
                            break;
                        }
                    }


                }
                break;
            }
            else
            {
			    if (let < tmpNode->letter)
			    {
			        //cout<<"aaa";
				    tmpNode = tmpNode->leftChild;
			    }
			    else
			    {
			        //cout<<"hhhhh";
				    tmpNode = tmpNode->rightChild;
			    }
		    }
		}

        if (let < curparent -> letter)
        {
            //cout<<"sss";
            curparent -> leftChild = new MovieNodeBST(let);
            curparent-> leftChild -> head = new MovieNodeLL(ranking, title, releaseYear, quantity);
            curparent->leftChild->parent = curparent;
        }
        else if (let > curparent -> letter)
        {
            //cout<<"jjjjj";
            curparent -> rightChild = new MovieNodeBST(let);
            curparent->rightChild -> head = new MovieNodeLL(ranking, title, releaseYear, quantity);
            curparent->rightChild->parent = curparent;
        }
    }
}


void MovieTree::printMovieInventory()
{
    printMovieInventory(root);
}

void MovieTree::DeleteAll(MovieNodeBST * node)
{
    if(node != NULL)
    {
        MovieNodeLL *cur = node->head;
        DeleteAll( node->leftChild);
        DeleteAll( node->rightChild);
        while(cur!=NULL)
        {
            MovieNodeLL *tmp = cur;
            cout<<"Deleting: "<<cur->title<<endl;
            cur=cur->next;
            delete tmp;
        }
    }
}

void MovieTree::rentMovie(string title) {
    int aa =0;
    MovieNodeBST *minfo = searchBST(root, title);
    if (minfo != NULL){
        MovieNodeLL *cur = minfo->head;
        while (cur != NULL)
        {
            if (cur->title == title)
            {
                cur->quantity = cur->quantity - 1;
                cout<<"Movie has been rented."<<endl;
                cout<<"Movie Info:"<<endl;
                cout<<"==========="<<endl;
                MovieNodeLL *tofind = cur;
                cout<<"Ranking:"<<tofind->ranking<<endl;
                cout<<"Title:"<<tofind->title<<endl;
                cout<<"Year:"<<tofind->year<<endl;
                cout<<"Quantity:"<<tofind->quantity<<endl;
                aa = 1;
                if(cur->quantity == 0)
                {
                    deleteMovieNode(cur->title);
                }
                break;
            }
            else
            {
                cur = cur -> next;
            }
        }
}
    if(minfo == NULL || aa == 0)
    {
        cout<<"Movie not found."<<endl;
    }

}
void MovieTree::findMovie(string title) {
    int aa = 0;
    MovieNodeBST *minfo = searchBST(root, title);

    //cout<<minfo->parent->letter<<endl;
    //cout<<minfo->rightChild->letter<<endl;
    //cout<<minfo->leftChild->letter<<endl;

    if (minfo != NULL){
        MovieNodeLL *cur = minfo->head;
        while (cur != NULL)
        {
            if (cur->title == title)
            {
                cout<<"Movie Info:"<<endl;
                cout<<"==========="<<endl;
                MovieNodeLL *tofind = cur;
                cout<<"Ranking:"<<tofind->ranking<<endl;
                cout<<"Title:"<<tofind->title<<endl;
                cout<<"Year:"<<tofind->year<<endl;
                cout<<"Quantity:"<<tofind->quantity<<endl;
                aa = 1;
                break;
            }
            else
            {
                cur = cur -> next;
            }
        }
}
    if(minfo == NULL || aa == 0)
    {
        cout<<"Movie not found."<<endl;
    }
}

void MovieTree::deleteMovieNode(std::string title) {
    MovieNodeBST *node = searchBST(root , title);
    if (node == NULL){
        cout<<"Movie not found."<<endl;
    }
    else
    {
        MovieNodeLL *pre = node->head;
        MovieNodeLL *cur = node->head;
        while (cur != NULL)
        {
            if (cur->title == title)
                break;
            else{
                pre = cur;
                cur = cur->next;
            }
        }
        if (cur == NULL) // cannot find the movie
        {
            cout<<"Movie not found."<<endl;
        }
        else if (cur != NULL)// find the movie.
        {
            //cout<<"find the movie";

            if (node->head->next != NULL)
            {
               if(node->head->title == title)
               {
                    MovieNodeLL *tmp=node->head;
                   node->head = node->head->next;
                   delete tmp;
               }
               else
               {
                   pre->next = cur->next;
                   delete cur;
               }
            }
            else// delete the BST node..................
            {
                //cout<<"delete node bst";
                if (node -> rightChild != NULL)
                {
                    //cout<<"rrrr"<<endl;
                    MovieNodeBST *min = treeMinimum(node -> rightChild);
                    if (min->rightChild != NULL)
                    {
                        min->rightChild->parent = min->parent;
                        min->parent->rightChild = min->rightChild;
                    }
                    else
                    {
                        //********need to add a justifing if min = node->rightChild
                        min->parent->rightChild = NULL;
                    }
                    node->letter = min->letter;
                    node->head = min->head;
                    delete min;
                    //cout<<node->letter<<endl;
                }
                else if (node->leftChild != NULL)
                {
                    //cout<<"lllll";
                    MovieNodeBST *max = node->leftChild;
                    while (max->rightChild != NULL)
                    {
                        max = max->rightChild;
                    }
                    if (max->leftChild != NULL)
                    {
                        max->leftChild->parent = max->parent;
                        max->parent->leftChild = max->leftChild;
                    }
                    else
                        max->parent->rightChild = NULL;
                    node->letter = max->letter;
                    node->head = max->head;
                    delete max;
                }
                else // node has no child
                {
                    if(node->letter == root->letter)
                    {
                        //cout<<node->letter<<endl;
                        delete root;
                    }
                    else
                    {
                        if(node->letter > node->parent->letter)
                            node->parent->rightChild = NULL;
                        else
                            node->parent->leftChild = NULL;
                    }
                }
            }
        }
    }
}


MovieNodeBST * MovieTree::treeMinimum(MovieNodeBST * node) {
    MovieNodeBST *cur = node;
    while (cur->leftChild != NULL)
    {
        cur = cur->leftChild;
    }
    return cur;
}


MovieNodeBST* MovieTree::searchBST(MovieNodeBST *node, string value) {
    char itemToFind = value[0];
    MovieNodeBST *startNode = node;
        if (startNode != nullptr) {
		if (itemToFind < startNode->letter && startNode->leftChild != nullptr) {
			return searchBST(startNode->leftChild, value);
		}
		else if (itemToFind > startNode->letter && startNode->rightChild != nullptr) {
			return searchBST(startNode->rightChild, value);
		}
		else if (itemToFind == startNode->letter) {
			return startNode;
		}
		else {
			//item not in tree
			return nullptr;
		}
	}
	else {
		return nullptr;

    }
}

int MovieTree::countMovieNodes()
{
    int c=0;
    countMovieNodes(root, &c);
    return c;
}

void MovieTree::countMovieNodes(MovieNodeBST *node, int *c)
{
   if(node!=NULL)
   {
       countMovieNodes(node->leftChild,  c);
       MovieNodeLL* cur = node->head;
       while(cur != NULL)
       {
            *c = *c + 1;
            cur = cur->next;
       }
       countMovieNodes(node->rightChild,  c);
   }
}

MovieNodeLL* MovieTree::searchLL(MovieNodeLL* head, string title)
{
    if(head == NULL)
    {
        cout<<"movie not found"<<endl;
        return NULL;
    }
    else
    {
        MovieNodeLL *cur = head;
        while (cur != NULL)
        {
            if(cur->title == title)
                return cur;
            else
                cur = cur->next;

        }
    }
    return NULL;
}

void MovieTree::printMovieInventory(MovieNodeBST * node)
{

    if(node != nullptr)
    {
            MovieNodeLL *cur = node->head;
            printMovieInventory( node->leftChild);
            while(cur!=NULL)
            {
                cout<<"Movie: "<<cur->title<<" "<<cur->quantity<<endl;
                cur=cur->next;
            }
            printMovieInventory( node->rightChild);
     }
}
