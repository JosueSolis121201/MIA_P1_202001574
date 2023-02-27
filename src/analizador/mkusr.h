#ifndef MKUSR_H
#define MKUSR_H


#include <iostream>
using namespace std;

class mkusr
{
public:
    mkusr();
    string user="";
    string pass="";
    string grp="";
    void make_mkusr(mkusr *disco);
};

#endif // MKUSR_H
