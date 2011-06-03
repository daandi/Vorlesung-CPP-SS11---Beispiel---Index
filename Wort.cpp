/* 
 * File:   Wort.cpp
 * Author: andi
 * 
 * Created on 2. Juni 2011, 19:22
 */

#include "Wort.h"

using namespace std;

Wort::Wort(wstring text) {
    this -> text = text;
}

int Wort::laenge() {
    return this -> text.length();
}

const wstring Wort::asString() {
    return this -> text ;
}


