#ifndef MOUNT_H
#define MOUNT_H

#include <iostream>
using namespace std;

class mount
{
public:
    mount();
    string path="";
    string name="";
    void make_mount(mount *disco);
};

#endif // MOUNT_H
