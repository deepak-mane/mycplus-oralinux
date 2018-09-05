/*
 * root.h
 *
 *  Created on: Sep 5, 2018
 *      Author: psadm2
 */

#ifndef ROOT_H_
#define ROOT_H_
// Should header files always be included in root.h as opposed to root.cpp?
#include <fstream>
#include <string>   // Seems like I do not need to include this string container, why?
                    //is it because json/json.h contains it?


#include "json/json.h" // Would I ever create a class with a dependency like this one?
                       // jsoncpp.sourceforge.net/annotated.html

class Root
{
private:
    std::ifstream m_json;

public:
    Json::Value m_root;
    Json::Value m_query;

    Root(const std::string&);
    ~Root();
};




#endif /* ROOT_H_ */
