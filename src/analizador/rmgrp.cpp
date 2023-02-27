#include "rmgrp.h"
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <ctime>
#include <unistd.h>
#include <iostream>
#include "../analizador/analizador.h"

rmgrp::rmgrp(){}

void rmgrp::make_rmgrp(rmgrp *disco){
    //instrucciones del "rmgrp"
    cout << "name: " << disco->name << endl;
}
