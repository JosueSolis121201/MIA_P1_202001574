#include "mkfs.h"
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <ctime>
#include <unistd.h>
#include <iostream>
#include "../analizador/analizador.h"

mkfs::mkfs(){}

void mkfs::make_mkfs(mkfs *disco){
    //instrucciones del "mkfs"
    cout << "id: " << disco->id << endl;
    cout << "type------------: " << disco->type << endl;
    cout << "fs : " << disco->fs << endl;
}
