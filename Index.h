/* 
 * File:   Index.h
 * Author: andi
 *
 * Created on 3. Juni 2011, 15:52
 */

#ifndef INDEX_H
#define	INDEX_H

#include "Text.h";

class Index {
public:
    Index();
    void add(Text);
    bool find(std::wstring);
private:
    std::vector<Text> texts;

};

#endif	/* INDEX_H */

