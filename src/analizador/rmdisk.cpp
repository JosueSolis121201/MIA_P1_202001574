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

    cout << "----------------RMDISK---------------------- "  << endl;
    const char * c = disco->path.data();
    if(remove(c) != 0 )
       cout<<"Error al borrar archivo!."<<endl;
     else
       cout<<"El archivo se borro con exito!"<<endl;
}
