#include "mkgrp.h"
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <ctime>
#include <unistd.h>
#include <iostream>
#include "../analizador/analizador.h"

mkgrp::mkgrp(){}

void mkgrp::make_mkgrp(mkgrp *disco){
    //instrucciones del "mkgrp"
    cout << "name: " << disco->name << endl;

}
