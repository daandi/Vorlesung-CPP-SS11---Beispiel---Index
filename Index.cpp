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

void Index::add(Text t) {
    texts.push_back(t);
}

bool Index::find(wstring wortString) {
    vector<Text>::iterator i;
    
    for (i = texts.begin(); i != texts.end(); i++) {
        if (i ->find(wortString) ) {
            cout << "Gefunden in Text:" << i->getName() << endl;
            i->findAndPrint(wortString);
        }
    
    }
}

