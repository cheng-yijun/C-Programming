#include <iostream>
#ifndef WORDCOUNTS_H
#define WORDCOUNTS_H
using namespace std;
class WordCounts {
    public:
        WordCounts();
        void countWords(string sentence);
        int getCount(string);
        void resetCounts();
        int mostCommon(string words[], int counts[], int n);

    private:
        int counts[10000];
        string words[10000];
        int num; // number of unique qords
        void sort();
};

#endif
