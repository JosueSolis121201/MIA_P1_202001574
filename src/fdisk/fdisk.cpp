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


    int numAdd = 0;
    if(this->StringIgual("",disco->add)){
        cout<<"ADD no fue definido"<<endl;

    }else{
      numAdd=stoi(disco->add);
      cout<<"ADD DE : "<<numAdd<<endl;
    }

    // comprobando path


    char* fileName = &disco->path[0];
    FILE * archivo;
    archivo= fopen(fileName,"rb+");
    if(archivo == 0x0){
        std::cout<<"Archivo no existe en la ruta:  "<<fileName<<std::endl;
        return;
    }
    struct MBR mbr;
    fread(&mbr,sizeof(struct MBR),1,archivo);
    fclose(archivo);
    //------------------------agregando nombre a la particion----------------------------------
    if(this->StringIgual("full",disco->borrar)){
        for(int i=0;i<4;i++){
              std::string comp = this->ArregloCharAString(mbr.mbr_partitions[i].part_name,16);

              if(this->StringIgual(disco->name,comp)){
                    mbr.mbr_partitions[i]=this->CrearPartition();
                    cout<<"Se elimino la particion con exito: "<<i<<endl;
                    archivo= fopen(fileName,"rb+");
                    //fseek(archivo,sizeof(struct MBR),SEEK_SET);
                    fwrite(&mbr,sizeof(struct MBR),1,archivo);
                    fclose(archivo);
                    return;
              }
            }
        cout<<"No se encontro la particion buscada"<<endl;
        return;
    }

    // comprobando size
    if(size <= 0){
        std::cout<<"size es negativo --ERROR"<<std::endl;
        return;
    }

    for(int i=0;i<4;i++){
        std::string partitionName = this->ArregloCharAString(mbr.mbr_partitions[i].part_name,16);
        if(this->StringIgual(partitionName,disco->name)){
            std::cout<<"Particion con nombre repetido"<<std::endl;
            return;
        }
    }



    for(int i=0;i<4;i++){
        std::string partitionName = this->ArregloCharAString(mbr.mbr_partitions[i].part_name,16);
        bool cond = this->StringIgual(partitionName,"");
        if(cond){
            this->LlenarArray(mbr.mbr_partitions[i].part_name,16,disco->name);

            // comprobando unit
            if (this->StringIgual(disco->unit,"m") ){
                disco->size=disco->size*1024*1024;
                numAdd=numAdd*1024*1024;
            }else if(this->StringIgual(disco->unit,"b")){
                disco->size=disco->size;
                numAdd=numAdd;
            }else if(this->StringIgual(disco->unit,"k")|| this->StringIgual(disco->unit,"")){
                disco->size=disco->size*1024;
                numAdd=numAdd*1024;
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

            // comprobando FIT********************************************************************
            if (this->StringIgual(disco->fit,"bf")){
                mbr=this->OrdenarParticionesActivasDondeEmpiezan(mbr);
                mbr=this->OrdenarParticionesActivasEInactivas(mbr);
                if(this->NoHayParticiones(mbr)){
                    mbr.mbr_partitions[0].part_start = sizeof(mbr);
                    mbr.mbr_partitions[0].part_status='1';
                    mbr.mbr_partitions[0].part_fit=disco->fit[0];
                    cout<<"NO SE ENCONTRAROR PARTICIONES ANTERIORES"<<endl;
                }else if(this->noParticionesDisponibles(mbr)){
                        cout<<"No hay espacio"<<endl;
                }else{
                  mbr=this->ParticionBestFit(mbr,numAdd);
                  mbr.mbr_partitions[0].part_fit=disco->fit[0];
                    std::cout<<"---------------------------------------Usando algoritmo bestfit-----------------------------"<<std::endl;
                }

            }else if( this->StringIgual(disco->fit,"wf")||this->StringIgual(disco->fit,"")){

                mbr=this->OrdenarParticionesActivasDondeEmpiezan(mbr);
                mbr=this->OrdenarParticionesActivasEInactivas(mbr);
                if(this->NoHayParticiones(mbr)){
                    mbr.mbr_partitions[0].part_start = sizeof(mbr);
                    mbr.mbr_partitions[0].part_status='1';
                    mbr.mbr_partitions[0].part_fit=disco->fit[0];
                    cout<<"NO SE ENCONTRAROR PARTICIONES ANTERIORES"<<endl;
                }else if(this->noParticionesDisponibles(mbr)){
                        cout<<"No hay espacio"<<endl;
                }else{
                  mbr=this->ParticionWorstFit(mbr,numAdd);
                  mbr.mbr_partitions[0].part_fit=disco->fit[0];
                    std::cout<<"--------------------------------Usando algoritmo worstFit ---------------------------------"<<std::endl;
                }
                mbr.mbr_partitions[i].part_fit='w';
            }else if( this->StringIgual(disco->fit,"ff")){
                mbr=this->OrdenarParticionesActivasDondeEmpiezan(mbr);
                mbr=this->OrdenarParticionesActivasEInactivas(mbr);
                if(this->NoHayParticiones(mbr)){
                    mbr.mbr_partitions[0].part_start = sizeof(mbr);
                    mbr.mbr_partitions[0].part_status='1';
                    mbr.mbr_partitions[0].part_fit=disco->fit[0];
                    cout<<"NO SE ENCONTRAROR PARTICIONES ANTERIORES"<<endl;
                }else if(this->noParticionesDisponibles(mbr)){
                        cout<<"No hay espacio"<<endl;
                }else{
                  mbr=this->ParticionFirstFit(mbr,numAdd);
                  mbr.mbr_partitions[0].part_fit=disco->fit[0];
                    std::cout<<"--------------------------------Usando algoritmo FirstFit---------------------------------"<<std::endl;
                }
                mbr.mbr_partitions[i].part_fit='f';
            }else{
                cout<<"fit no aceptado" << disco->fit<<endl;
            }

            //break termino fdisk particion encontrada
            archivo= fopen(fileName,"rb+");
            //fseek(archivo,sizeof(struct MBR),SEEK_SET);
            fwrite(&mbr,sizeof(struct MBR),1,archivo);
            fclose(archivo);
            return;
    }
    }
    std::cout<<"No se pudo completar FDISK"<<std::endl;
}
