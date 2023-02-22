#include "mount.h"
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <ctime>
#include <unistd.h>
#include <iostream>
#include "../analizador/analizador.h"

mount::mount(){}

void mount::make_mount(mount *disco){
    //instrucciones del "mount"
    cout << "path: " << disco->path << endl;
    cout << "name------------: " << disco->name << endl;
}
