#ifndef FDISK_H
#define FDISK_H

#include <iostream>
using namespace std;

class fdisk
{
public:
    fdisk();
    int size=0;
    string path="";
    string name="";
    string unit="";
    string type="";
    string fit="";
    string full="";
    string borrar="";
    string add="";
    void make_fdisk(fdisk *disco);
};

#endif // FDISK_H
