#include <iostream>
#include <fstream>
#include <sstream>
#include "SpellChecker.h"

using namespace std;

SpellChecker::SpellChecker() {
    language = "English";


}

SpellChecker::SpellChecker(string lang) {
    language = lang;        


}

SpellChecker::SpellChecker(string lang, string valid_words_filename, string misspelled_filename) {
    language = lang;        

    loadValidWords(valid_words_filename);
    loadMisspelledWords(misspelled_filename);

}

void SpellChecker::setBeginMarker(char begin){
    begin_mark = begin;
}

void SpellChecker::setEndMarker(char end){
    end_mark = end;
}

char SpellChecker::getBeginMarker(){
    return begin_mark;
}

char SpellChecker::getEndMarker(){
    return end_mark;
}


bool SpellChecker::loadValidWords(string filename){

	string line;
	ifstream ReadFile;
	ReadFile.open(filename.c_str());
	if(ReadFile.fail())
	{
		return false;
	}	
    while(getline(ReadFile, line)) {
        validWords[vcounter] = line;
        vcounter++;

        if(vcounter == 10000) {
			cout << "Out of range" << endl;
			break;
        }
	}
    

    return true;
}

bool SpellChecker::loadMisspelledWords(string filename){
    string line;
	ifstream ReadFile;
	ReadFile.open(filename.c_str());
	if(ReadFile.fail())
	{
		return false;
	}	
    while(getline(ReadFile, line)) {
        stringstream ss(line);
        string miss;
        string right;

        getline(ss, miss, '\t');
        getline(ss, right, '\n');
//lala	lal	la	l
        correctedWords[mcounter][0] = miss;
        correctedWords[mcounter][1] = right;

        mcounter++;

        if(mcounter == 10000) {
            cout << "Out of range" << endl;
            break;
        }
    }
    
    return true;
}



string SpellChecker::fixUp(string sentence){
    stringstream ss(sentence);

    string word;
    string new_sentence = "";

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

        // check if it's valid 
        bool valid = false;
        for(int idx = 0; idx < vcounter; idx++) {
            if(validWords[idx] == word) {
                valid = true;

            }
        }


        if(valid == true) {
            new_sentence = new_sentence + word + " ";

        } else {

            // check if it's in misspelled 
            bool isFound = false;
            int idx = 0;
            string correctedWord = "";

            while (idx < mcounter && !isFound) {
                if(correctedWords[idx][0] == word) {
                    correctedWord = correctedWords[idx][1];
                    isFound = true;
                }
                idx++;
            }
            if(!isFound) {
                correctedWord = begin_mark + word + end_mark;
            }


            new_sentence= new_sentence + correctedWord + " ";
        }
    }

    return new_sentence;
}




// end of SpellChecker
