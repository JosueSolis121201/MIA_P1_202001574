#include "unmount.h"
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <ctime>
#include <unistd.h>
#include <iostream>
#include "../analizador/analizador.h"

unmount::unmount(){}

void unmount::make_unmount(unmount *disco){
    //instrucciones del "unmount"
    cout << "id: " << disco->id << endl;
}
