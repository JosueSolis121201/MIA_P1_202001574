#ifndef LOGIN_H
#define LOGIN_H


#include <iostream>
using namespace std;

class login
{
public:
    login();
    string user="";
    string pass="";
    string id="";
    void make_login(login *disco);
};

#endif // LOGIN_H
