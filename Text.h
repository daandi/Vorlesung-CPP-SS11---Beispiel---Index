/* 
 * File:   Text.h
 * Author: andi
 *
 * Created on 2. Juni 2011, 18:53
 */

#ifndef TEXT_H
#define	TEXT_H

#include <vector>
#include <unordered_map>
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include "Wort.h"


class Text {
public:
    Text();
    Text(std::string);
    Text(std::string, const std::wstring);
    void printOnTerminal();
    std::vector<Wort> getText();
    std::string getName();
    Text & operator=(Text);
    bool find(std::wstring);
    void findAndPrint(std::wstring);
    

private:
    std::string name;
    std::vector<Wort> text;
    std::unordered_map< std::wstring, std::vector<int> > wordPositions;
    void readWordsfromFile( std::wifstream &);
    void readWordsFromString( std::wstring &);
    void readWordsFromStream( std::wistream &);
    void buildPositionsMap(std::vector<Wort> &);
    void printConcordance(int, int);

};

#endif	/* TEXT_H */

