#include "mkdisk.h"
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <ctime>
#include <unistd.h>
#include <iostream>
#include "../analizador/analizador.h"



mkdisk::mkdisk(){}

void mkdisk::make_mkdisk(mkdisk *disco){
    //instrucciones del "mkdisk"

    cout << "unit: " << disco->unit << endl;
    cout << "path: " << disco->path << endl;
    cout << "size: " << disco->size << endl;
    cout << "fit: " << disco->fit << endl;
    if(size <= 0){
        std::cout<<"size es negativo --ERROR"<<std::endl;
        return;
    }

    if (this->StringIgual(disco->unit,"m") || this->StringIgual(disco->unit,"")){
        disco->size=disco->size*1024;
    }else if(!this->StringIgual(disco->unit,"k")){
        cout<<"Unidad no aceptada"<<endl;
        return;
    }

    std::string nombreDirectorio= this->DireccionArchivo(disco->path);
    std::string nombreArchivo= this->NombreArchivo(disco->path);

    this->CrearDirectorio(nombreDirectorio);

    this->CrearArchivo(disco->path,disco->size);

    FILE * archivo;
    struct MBR mbr = this->CrearMBR();
    archivo= fopen(&disco->path[0],"wb+");
    fwrite(&mbr,sizeof(struct MBR),1,archivo);
    fclose(archivo);

}

    
