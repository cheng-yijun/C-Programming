#include <iostream>
#include <sstream>
#include "WordCounts.h"

using namespace std;


WordCounts::WordCounts(){
  num = 0;
  for (int i = 0; i < 10000; i++){
    words[i] = "";
    counts[i] = 0;
  }
}


int WordCounts::getCount(string word) {
    int count = 0;
    for(int i = 0; i < num; i++) {
        if(words[i] == word) {
            count =  counts[i];
        }
    }
    return count;
}

void WordCounts::resetCounts() {
    for(int i = 0; i < num; i++) {
        counts[i] = 0;
    }
    num = 0;
}



void WordCounts::sort() {
    bool sorted = false;
    while(!sorted) {
        sorted = true;
        for(int i = 0; i < num - 1; i++) {
            if (counts[i] < counts[i+1]) {
                // swap names
                string tempWord = words[i];
                words[i] = words[i+1];
                words[i+1] = tempWord;

                // swap scores
                int tempCount = counts[i];
                counts[i] = counts[i+1];
                counts[i+1] = tempCount;

                sorted = false;
            }
        }
    }

}

int WordCounts::mostCommon(string commonWords[], int wordCount[], int n){
    sort();

    int numCopied = 0;
    for(int idx = 0; idx < n; idx++) {
        if(words[idx] == "") break;
        commonWords[idx] = words[idx];
        wordCount[idx] = counts[idx];
        numCopied++;
    }

    return numCopied;
}


void WordCounts::countWords(string sentence) {
    string word;
    stringstream ss(sentence);

    while (getline(ss, word, ' ')) {

        // strip 
        char fc = word[0];

        if (!(fc  >= 'A' && fc <= 'z')) {
            word = word.substr(1, word.length());
        }


        char lc = word[word.length() -1];

        if (!(lc  >= 'A' && lc <= 'z')) {
            word = word.substr(0, word.length() - 1);
        }

        string result = "";
        for(int i = 0; i < word.length(); i++) {
            result += tolower(word[i]);

        }
        word = result; 

        // check if it's unique 
        int idx = 0;
        bool found = false;
        while(idx < num && !found) {
            if(words[idx] == word) {
                found = true;
                counts[idx]++;
            }
            idx++;
        }

        // if not in the list, add to the list 
        if(found == false) {
            words[num] = word;
            counts[num] = 1;
            num++;
        }
    }
}
