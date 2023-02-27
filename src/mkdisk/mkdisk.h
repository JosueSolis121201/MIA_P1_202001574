#ifndef MKDISK_H
#define MKDISK_H

#include <iostream>
#include "../analizador/libreria.h"

class mkdisk : public Libreria
{
public:
    mkdisk();
    int size=0;
    std::string path="";
    std::string unit="";
    std::string fit="";
    void make_mkdisk(mkdisk *disco);
};

#endif // MKDISK_H
