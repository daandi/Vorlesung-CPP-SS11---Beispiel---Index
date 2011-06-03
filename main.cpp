/* 
 * File:   main.cpp
 * Author: andi
 *
 * Created on 2. Juni 2011, 18:53
 */


#include <iostream>
#include "Index.h"

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    
    setlocale(LC_ALL, "");
    
    Index myIndex;
    
    Text a = Text("test.txt");
    Text b = Text("String als Text", L"Hallo, hier ein Test.");
    Text c = Text("String als Text 2", L"Ist das denn nötig?");
    
    myIndex.add(a);
    myIndex.add(b);
    myIndex.add(c);
    
    myIndex.find(L"ein");
    myIndex.find(L"der");
    
    

    
}

