/* 
 * File:   Index.cpp
 * Author: andi
 * 
 * Created on 3. Juni 2011, 15:52
 */

#include "Index.h"

using namespace std;

Index::Index() {
}

/*
 Text zum Index hinzufügen.
 */
void Index::add(Text t) {
    texts.push_back(t);
}

/*
 Token in Text finden.
 */
bool Index::find(wstring wortString) {
    vector<Text>::iterator i;
 
    bool nicht_im_index = true;
    
    for (i = texts.begin(); i != texts.end(); i++) {
        if (i ->find(wortString) ) {
            wcout << endl << L"Gefunden in Text: " << i->getName() << endl;
            i->findAndPrint(wortString);
            nicht_im_index = false;
        }
    
    }
    
    if ( nicht_im_index) {
        wcout << endl << wortString << L": Nicht im Index!" << endl << endl;
    }
}
