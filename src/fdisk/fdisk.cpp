#include "fdisk.h"
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <ctime>
#include <unistd.h>
#include <iostream>
#include "../analizador/analizador.h"

fdisk::fdisk(){}

void fdisk::make_fdisk(fdisk *disco){
    //instrucciones del "fdisk"
    cout << "name: " << disco->name << endl;
    cout << "path: " << disco->path << endl;
    cout << "size: " << disco->size << endl;
    cout << "unit: " << disco->unit << endl;
    cout << "type: " << disco->type << endl;
    cout << "fit: " << disco->fit << endl;
    cout << "delete: " << disco->borrar << endl;
    cout << "add: " << disco->add << endl;
}
