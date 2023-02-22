#include "rmdisk.h"
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <ctime>
#include <unistd.h>
#include <iostream>
#include "../analizador/analizador.h"

rmdisk::rmdisk(){}

void rmdisk::make_rmdisk(rmdisk *disco){
    //instrucciones del "rmdisk"
    cout << "path: " << disco->path << endl;
}
