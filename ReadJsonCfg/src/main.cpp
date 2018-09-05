//============================================================================
// Name        : ReadJsonCfg.cpp
// Author      : Deepak Mane
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "root.h"

int main()
{

    Root rate("test.json");
    rate.m_query = rate.m_root["query"]["items"]; // Is it ok to assign member to a member like so,
                                                  // as opposed to just a variable?

    // How can I instantiate my object like the line below?
    // Root rate("test.json", ["query"]["results"]["rate"]);
    // Syntax does not have to match precisely?


    for(const auto & it : rate.m_query)
    {
        std::cout << it << std::endl;
    }
}
