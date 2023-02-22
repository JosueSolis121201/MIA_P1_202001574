#ifndef MKFS_H
#define MKFS_H


#include <iostream>
using namespace std;

class mkfs
{
public:
    mkfs();
    string id="";
    string type="";
    string fs="";
    void make_mkfs(mkfs *disco);
};

#endif // MKFS_H
