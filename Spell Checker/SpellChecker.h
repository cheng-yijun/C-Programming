#include <iostream>
#ifndef SPELLCHECKER_H
#define SPELLCHECKER_H

using namespace std;

class SpellChecker {
    public:
        string language;
        SpellChecker();
        SpellChecker(string a);
        SpellChecker(string a, string filename, string filename1);
        bool loadValidWords(string filename);
        bool loadMisspelledWords(string filename);
        void setBeginMarker(char begin);
        void setEndMarker(char end);
        char getBeginMarker();
        char getEndMarker();
        string fixUp(string sentence);

    private:

        char begin_mark;
        char end_mark;
        int vcounter =0; // valid word counter
        int mcounter =0; // misspelled word counter

        string validWords[10000];
        string correctedWords[10000][2];

};


#endif
