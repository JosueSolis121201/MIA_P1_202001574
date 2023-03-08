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
  int mbr_tamano;
  struct Partition mbr_partitions[4];
} ;


class Libreria
{
public:
    Libreria();
    std::string ArregloCharAString(char *charArray, int arregloTamanio);
    void CrearDirectorio(std::string path);
    void CrearArchivo(std::string path,int tamanio);
    void IniciarArray(char *charArray, int arregloTamanio, char caracter);
    void LlenarArray(char* charArray,int arregloTamanio,std::string path);

    struct MBR OrdenarParticionesActivasDondeEmpiezan(struct MBR particiones);
    struct MBR OrdenarParticionesActivasEInactivas(struct MBR particiones);
    struct MBR ParticionFirstFit(struct MBR particiones, int add);
    struct MBR ParticionBestFit(struct MBR particiones, int add);
    struct MBR ParticionWorstFit(struct MBR particiones, int add);
    struct Partition EliminarParticion(struct Partition mbr);


    std::string NombreArchivo(std::string path);
    std::string DireccionArchivo(std::string path);

    bool StringIgual(std::string a, std::string b);
    bool NoHayParticiones(struct MBR particiones);
    bool noParticionesDisponibles(struct MBR particiones);

    struct MBR CrearMBR();
    struct Partition CrearPartition();
};

#endif // LIBRERIA_H
