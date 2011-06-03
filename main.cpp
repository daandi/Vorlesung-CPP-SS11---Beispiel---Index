/* 
 * File:   main.cpp
 * Author: andi
 *
 * Created on 2. Juni 2011, 18:53
 */


#include <iostream>
#include "Text.h"

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    
    setlocale(LC_ALL, "");
    
    Text a = Text("test.txt");
    a.printOnTerminal();
    Text b = Text("String als Text", L"Hallo, hier ein Test.");
    b.printOnTerminal();
    
    a.find(L"und");
    
}

