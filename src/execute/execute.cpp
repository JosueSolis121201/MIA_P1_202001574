#include "execute.h"
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <ctime>
#include <unistd.h>
#include <iostream>
#include "../analizador/analizador.h"

execute::execute(){}

void execute::make_execute(execute *disco){
    //instrucciones del "execute"
    cout << "path: " << disco->path << endl;
}