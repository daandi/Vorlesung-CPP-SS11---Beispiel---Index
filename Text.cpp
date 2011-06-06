/* 
 * File:   Text.cpp
 * Author: andi
 * 
 * Created on 2. Juni 2011, 18:53
 */

#include "Text.h"

using namespace std;

// Constructor
Text::Text() {
}

/*
 Text aus einer Datei erstellen.
 */
Text::Text(string filename) {
    this -> name = filename;
    wifstream file(filename.c_str());
    readWordsfromFile(file) ;
}

/*
 Text aus einem String erstellen. Name des Textes ist das erste Argument.
 */
Text::Text(string name, wstring textAsString) {
    this -> name = name;
    readWordsFromString(textAsString);
    
}

/*
 Wörter aus eine FileStream lesen.
 */

void Text::readWordsfromFile(wifstream & file) {
    file.imbue(locale("de_DE.UTF-8"));
    if (file.good()) {
        readWordsFromStream(file);
    }
    else {
        wcout << "Problem mit der Datei" << endl;
    }
}

/*
 Wörter aus einem StringStream lesen.
 */

void Text::readWordsFromString(wstring & textString) {
    wistringstream stringAsStream(textString);
    wstring wortString;
    readWordsFromStream(stringAsStream);
}

/*
 Wörter von einem Stream lesen
 */

void Text::readWordsFromStream(wistream & inStream) {
    wstring wortString;
    while (inStream >> wortString) {
        text.push_back( Wort(wortString) );
    }
    buildPositionsMap(text);
}

/*
 Container Map mit Wortpositionen für Konkordanz erstellen.
 */
void Text::buildPositionsMap(vector<Wort> & words) {
    vector<Wort>::iterator i; 
    
    for ( i= words.begin(); i != words.end(); i++ ) {
        wstring wortString = i ->asString();
        int iteratorPos =  distance(words.begin(),i);
        
        // Es gibt schon einen Eintrag
        if (wordPositions.find( wortString ) != wordPositions.end()) {
            // Vector dereferenzieren
            wordPositions.at(wortString).push_back( iteratorPos );
        }
        // Es gibt noch keinen Eintrag
        else {
            vector<int> v;
            v.push_back(iteratorPos);
            
            wordPositions.insert( map< wstring,vector<int> >::value_type(wortString,v) );
        }
        
    }
    
}

/*
 Wort innerhalb des Textes finden. und Position ausgeben.
 */

void Text::findAndPrint(wstring wortString) {
    if( wordPositions.find(wortString) != wordPositions.end()) {
        vector<int> v = wordPositions.at(wortString);
        vector<int>::iterator i;
        
        for (i = v.begin() ;i != v.end(); i++) {
            wcout << L"\t" << wortString <<": gefunden an Position ->   " << * i << L":   ";
            printConcordance(* i, 3);
        }
        
    }
    else {
        wcout <<  L"Wort: " << wortString << L" ist in Text: ";
        cout << name;
        wcout << L" nicht enthalten."<< endl;
    }
}

bool Text::find(wstring wortString) {
    if( wordPositions.find(wortString) != wordPositions.end()) {
        return true;
    }
    else {
        return false;
    }
}

string Text::getName() {
    return this -> name;
}

/*
 Konkordanz drucken.
 */
void Text::printConcordance(int textPosition, int windowSize) {
    int begin   = textPosition - windowSize;
    int end     = textPosition + windowSize;
    
    if (textPosition - windowSize < 0) {
        begin = 0 ;
    }
    
    if ( textPosition + windowSize >= text.size() ) {
        end = text.size() -1 ;
    }
    
    while (begin <= end) {  
        if (begin != textPosition) {
            wcout << text.at(begin).asString() << " ";
        }
        else {
            wcout << L"\t>" << text.at(begin).asString() << L"<\t";
        }
        begin++;
    }
    wcout << endl;
    
}

Text &  Text::operator=(Text other) {
    this -> text = other.text;
    this -> name = other.name;
    return * this;
}

/*
 Ganzen Text auf Terminal ausgeben
 */
void Text::printOnTerminal() {
    
    cout << "Text: \"" << name << "\"" << endl;
    
    vector<Wort>::iterator i = text.begin();
    while (i != text.end() ) {
        wcout << i -> asString() << L" ";
        i++;
    }
    
    wcout << endl << endl;
}
