/* 
 * File:   Wort.h
 * Author: andi
 *
 * Created on 2. Juni 2011, 19:22
 */

#ifndef WORT_H
#define	WORT_H

#include <string>

class Wort {
public:
    Wort(std::wstring);
    int laenge();
    const std::wstring asString();
private:
    std::wstring text;
};

#endif	/* WORT_H */

