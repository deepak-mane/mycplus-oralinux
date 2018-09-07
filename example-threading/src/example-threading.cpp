//============================================================================
// Name        : example-threading.cpp
// Author      : Deepak Mane
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================
#include <thread>
#include <string>
#include <iostream>
//using namespace std;

class Class
{
public:
    Class(const std::string& s) : m_data(s) { }
    ~Class() { m_thread.join(); }
    void runThread() { m_thread = std::thread(&Class::print, this); }

private:
    std::string m_data;
    std::thread m_thread;
    void print() const { std::cout << m_data << '\n'; }
};

int main()
{
    Class c("Hello, world!");
    c.runThread();
}
