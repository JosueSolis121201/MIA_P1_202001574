#include "rmusr.h"
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <ctime>
#include <unistd.h>
#include <iostream>
#include "../analizador/analizador.h"

rmusr::rmusr(){}

void rmusr::make_rmusr(rmusr *disco){
    //instrucciones del "rmusr"
    cout << "user: " << disco->user << endl;
}
