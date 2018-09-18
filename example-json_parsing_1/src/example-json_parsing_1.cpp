//============================================================================
// Name        : example-json_parsing_1.cpp
// Author      : Deepak Mane
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <json/value.h>
#include <jsoncpp/json/json.h>
#include <fstream>

void
displayCfg(const Json::Value &cfg_root);

int
main()
{
    Json::Reader reader;
    Json::Value cfg_root;
    std::ifstream cfgfile("cfg.json");
    cfgfile >> cfg_root;

    std::cout << "______ cfg_root : start ______" << std::endl;
    std::cout << cfg_root << std::endl;
    std::cout << "______ cfg_root : end ________" << std::endl;

    displayCfg(cfg_root);
}

void
displayCfg(const Json::Value &cfg_root)
{
    std::string serverIP = cfg_root["Config"]["server-ip"].asString();
    std::string serverPort = cfg_root["Config"]["server-port"].asString();
    unsigned int bufferLen = cfg_root["Config"]["buffer-length"].asUInt();

    std::cout << "______ Configuration ______" << std::endl;
    std::cout << "server-ip     :" << serverIP << std::endl;
    std::cout << "server-port   :" << serverPort << std::endl;
    std::cout << "buffer-length :" << bufferLen<< std::endl;
}
