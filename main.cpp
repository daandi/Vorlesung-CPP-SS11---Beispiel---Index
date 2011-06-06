/* 
 * File:   main.cpp
 * Author: andi
 *
 * Created on 2. Juni 2011, 18:53
 */


#include <iostream>
#include "Index.h"
#include "Text.h"

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    
    setlocale(LC_ALL, "");
    
    Index myIndex;
    
    // Text aus Datei
    Text a = Text("test.txt");
    // Text als String übergeben
    Text b = Text("String als Text", L"Hallo, hier ein Test.");
    Text c = Text("String als Text 2", L"Ist das denn nötig?");
    
    // Text auf Terminal ausgeben
    //a.printOnTerminal();
    
    // Texte zum Index hinzufügen
    myIndex.add(a);
    myIndex.add(b);
    myIndex.add(c);
    
    // Wörter im Index mit Konkordanz
    myIndex.find(L"ein");
    myIndex.find(L"der");
    myIndex.find(L"nötig?");
    myIndex.find(L"###");
    
    
    // geschachtelt.
    myIndex.add(Text("Doch im Index", L"### und noch ein paar ###"));
    myIndex.find(L"###");     
}

