#include "mkdisk.h"
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <ctime>
#include <unistd.h>
#include <iostream>
#include "../analizador/analizador.h"
#include <boost/filesystem.hpp>

mkdisk::mkdisk(){}

void mkdisk::make_mkdisk(mkdisk *disco){
    //instrucciones del "mkdisk"
    cout << "unit: " << disco->unit << endl;
    cout << "path: " << disco->path << endl;
    cout << "size: " << disco->size << endl;


    //Creando la ruta
    boost::filesystem::create_directories(disco->path);
    //Obtenemos la unidaddel archivo
    std::string fileUnit=disco->unit;
    // Creando pathing donde se enviara el archivo creado
    std::string path = disco->path;

    FILE *archivo = fopen(path.c_str(), "wb");
    cout << "pruebaaaaaaaaaa: " << path.c_str() << endl;

    fseek(archivo, 0, SEEK_SET);
    char cantidad[disco->size];
    fwrite(&cantidad,0,1,archivo);
    fclose(archivo);
    std::cout << "Creando archivo binario nuevo"<< std::endl;
}

    
