#include "login.h"
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <ctime>
#include <unistd.h>
#include <iostream>
#include "../analizador/analizador.h"

login::login(){}

void login::make_login(login *disco){
    //instrucciones del "login"
    cout << "user: " << disco->user << endl;
    cout << "pass: " << disco->pass << endl;
    cout << "id: " << disco->id << endl;
}
