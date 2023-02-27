#include "fdisk.h"
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <ctime>
#include <unistd.h>
#include <iostream>
#include "../analizador/analizador.h"


fdisk::fdisk(){}

void fdisk::make_fdisk(fdisk *disco){
    //instrucciones del "fdisk"
    cout << "name: " << disco->name << endl;
    cout << "path: " << disco->path << endl;
    cout << "size: " << disco->size << endl;
    cout << "unit: " << disco->unit << endl;
    cout << "type: " << disco->type << endl;
    cout << "fit: " << disco->fit << endl;
    cout << "delete: " << disco->borrar << endl;
    cout << "add: " << disco->add << endl;

    // comprobando size
    if(size <= 0){
        std::cout<<"size es negativo --ERROR"<<std::endl;
        return;
    }
    // comprobando path

    struct MBR mbr;
    char* fileName = &disco->path[0];
    FILE * archivo;
    archivo= fopen(fileName,"rb+");
    if(archivo == 0x0){
        std::cout<<"Archivo no existe en la ruta:  "<<fileName<<std::endl;
        return;
    }
    fread(&mbr,sizeof(struct MBR),1,archivo);
    fclose(archivo);
    //------------------------agregando nombre a la particion----------------------------------

/*
    for(int0){

        this->StringIgual(mbr.mbr_partitions[i].part_name,disco->name)
    }
*/


    for(int i=0;i<4;i++){

        if(this->StringIgual(string(mbr.mbr_partitions[i].part_name),"")){
            this->LlenarArray(mbr.mbr_partitions[i].part_name,16,disco->name);

            // comprobando unit
            if (this->StringIgual(disco->unit,"m") ){
                disco->size=disco->size*1024*1024;
            }else if(this->StringIgual(disco->unit,"b")){
                disco->size=disco->size;
            }else if(this->StringIgual(disco->unit,"k")|| this->StringIgual(disco->unit,"")){
                disco->size=disco->size*1024;
            }else{
                cout<<"Unidad no aceptada"<<endl;
                return;
            }
            mbr.mbr_partitions[i].part_s=disco->size;

            // comprobando type
            if (this->StringIgual(disco->type,"p") ){
                mbr.mbr_partitions[i].part_type=disco->type[0];
            }

            //*****comprobando si ya hay alguna particion extendida****
            bool extendida=true;
            for(int j=0;j<4;j++){
                if(mbr.mbr_partitions[j].part_type=='e'||mbr.mbr_partitions[j].part_type=='E'){
                    extendida=false;
                }
            }
            if(this->StringIgual(disco->type,"e")||extendida){
                mbr.mbr_partitions[i].part_type=disco->type[0];
            }else if(!this->StringIgual(disco->type,"l")||!extendida){
                mbr.mbr_partitions[i].part_type=disco->type[0];
            }else{
                cout<<"Type no aceptado o no cumple con los requisitos" << disco->type<<endl;
            }




            // comprobando FIT
            if (this->StringIgual(disco->fit,"bf") || this->StringIgual(disco->fit,"wf") || this->StringIgual(disco->fit,"ff")){
                mbr.mbr_partitions[i].part_fit=disco->fit[0];
            }else if( this->StringIgual(disco->fit,"")){
                mbr.mbr_partitions[i].part_fit='w';
            }else{
                cout<<"fit no aceptado" << disco->fit<<endl;
            }
            //break termino fdisk particion encontrada
            archivo= fopen(fileName,"rb+");
            fwrite(&mbr,sizeof(struct MBR),1,archivo);
            fclose(archivo);
            break;
    }else{
            cout<<"Particion con nombre repetido"<<endl;
        }
    }



    }
