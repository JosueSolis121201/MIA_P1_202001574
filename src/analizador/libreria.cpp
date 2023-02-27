#include "libreria.h"
#include <iostream>
#include <bits/stdc++.h>
#include <boost/algorithm/string.hpp>
Libreria::Libreria()
{

}

struct MBR Libreria::CrearMBR(){
    struct MBR mbr;
    for(int i=0;i<4;i++){
        mbr.mbr_partitions[i] = this->CrearPartition();
    }
    return mbr;
}

struct Partition Libreria::CrearPartition(){
    struct Partition part;
    part.part_status = '0';
    part.part_type='0';
    part.part_fit='0';
    part.part_start=0;
    part.part_s=0;
    this->IniciarArray(part.part_name,16,' ');

    return part;
}

void Libreria::IniciarArray(char charArray[], int arregloTamanio, char caracter){
for (int i = 0; i < arregloTamanio; i++) {
            charArray[i] = caracter;
    }
}

void Libreria::LlenarArray(char *charArray, int arregloTamanio, std::string path){
    int stringTamanio = path.size();
    for (int i = 0; i < arregloTamanio; i++) {
         if(i<stringTamanio){
            charArray[i] = path[i];
       }
    }
}

bool Libreria::StringIgual(std::string a, std::string b){

        std::string compararA = a;
        std::string compararB = b;

        boost::trim(compararA);
        boost::trim(compararB);

        unsigned int sz = a.size();
        if (b.size() != sz)
            return false;
        for (unsigned int i = 0; i < sz; ++i)
            if (tolower(a[i]) != tolower(b[i]))
                return false;
        return true;

}

void Libreria::CrearArchivo(std::string path,int tamanioKB){

    char* fileName = &path[0];
    FILE * file = fopen(fileName,"wb+");
    char carac[1024] = {0};
    for(int i=0; i< tamanioKB;i++){
        fwrite(&carac,1,sizeof(char[1024]), file);
    }
    std::cout << "MKDISK "<< path <<" creado"<< std::endl;
    fclose(file);
}


void Libreria::CrearDirectorio(std::string path){
    int check;
    char* dirname = &path[0];
    check = mkdir(dirname,0777);
    if (!check)
        std::cout << "Directorio creado"<< std::endl;
    else {
        std::cout << "No se pudo crear directorio" << std::endl;       
    }
}

std::string Libreria::DireccionArchivo(std::string path){
    char str[path.length() + 1];
    std::strcpy(str, path.c_str());
    char * pch;

    pch = strtok (str,"/");

    std::string dirreccion="";

    while (pch != NULL)
    {

      const char *cinput;
      cinput = pch;


      pch = strtok (NULL, "/");
      if(pch!=NULL){
          dirreccion =dirreccion+"/"+std::string(cinput);
      }

    }

    return dirreccion;


}

std::string Libreria::NombreArchivo(std::string path){

    char str[path.length() + 1];
    std::strcpy(str, path.c_str());
    char * pch;

    pch = strtok (str,"/");

    std::string  nombreArchivo="";

    while (pch != NULL)
    {
      const char *cinput;
      cinput = pch;
      nombreArchivo=std::string(cinput);


      pch = strtok (NULL, "/");
    }
    return nombreArchivo;
}

