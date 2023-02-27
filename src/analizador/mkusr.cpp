#include "mkusr.h"
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <ctime>
#include <unistd.h>
#include <iostream>
#include "../analizador/analizador.h"

mkusr::mkusr(){}

void mkusr::make_mkusr(mkusr *disco){
    //instrucciones del "mkusr"
    cout << "user: " << disco->user << endl;
    cout << "pass: " << disco->pass << endl;
    cout << "grp:" << disco->grp << endl;
}
