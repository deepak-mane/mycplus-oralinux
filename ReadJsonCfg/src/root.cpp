/*
 * root.cpp
 *
 *  Created on: Sep 5, 2018
 *      Author: psadm2
 */

#include "root.h"

Root::Root(const std::string & filename) : m_json(filename, std::ifstream::binary)
// Is std::ifstream::binary ok to put it in here like this ^?
// It's working, but would that be good practice?
{
    m_json >> m_root;
    m_json.close();  // Do I need .close() here?

}
Root::~Root(){}
