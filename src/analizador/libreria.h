#ifndef LIBRERIA_H
#define LIBRERIA_H
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>


struct Partition{
  char part_status;
  char part_type;
  char part_fit;
  int part_start;
  int part_s;
  char part_name[16];
} ;

struct MBR{

  struct Partition mbr_partitions[4];
} ;


class Libreria
{
public:
    Libreria();
    void CrearDirectorio(std::string path);
    void CrearArchivo(std::string path,int tamanio);
    void IniciarArray(char *charArray, int arregloTamanio, char caracter);
    void LlenarArray(char* charArray,int arregloTamanio,std::string path);
    std::string NombreArchivo(std::string path);
    std::string DireccionArchivo(std::string path);

    bool StringIgual(std::string a, std::string b);

    struct MBR CrearMBR();
    struct Partition CrearPartition();
};

#endif // LIBRERIA_H
