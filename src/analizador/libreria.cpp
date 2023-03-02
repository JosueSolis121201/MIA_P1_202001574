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
    mbr.mbr_tamano=0;
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


bool Libreria::NoHayParticiones(struct MBR mbr){
    bool noHayParticiones=false;

    int contadorDisponibles=0;

    for(int i=0; i<4;i++){
        if(mbr.mbr_partitions[i].part_status=='0'){
            contadorDisponibles=contadorDisponibles+1;
        }
    }
    if(contadorDisponibles==4){
       noHayParticiones = true;
    }else{
        std::cout<<"No hay ninguna particion, la nueva particion se colocara en posicion 0"<<std::endl;
    }

    return noHayParticiones;
}

bool Libreria::noParticionesDisponibles(struct MBR mbr){ //SABER SI ESTA LLENO O VACIO

    bool noParticionesDisponibles=false;

    int contadorNoDisponibles=0;
    for(int i=0; i<4;i++){
        if(mbr.mbr_partitions[i].part_status=='1'){
            contadorNoDisponibles=contadorNoDisponibles+1;
        }
    }
    if(contadorNoDisponibles==4){
        noParticionesDisponibles=true;
    }else{
        std::cout<<"Todas las particiones estan siendo usadas, no se puede agregar otra"<<std::endl;
    }
    return noParticionesDisponibles;
}

void Libreria::ParticionBestFit(struct MBR mbr){
    int tamañoArchivo = mbr.mbr_tamano;
    int espacioMenosAmplio=tamañoArchivo;
    int espacioActual=0;
    int seEncontroEn=0;
    int espacioEncontrado=0;

    int Inicial=0;
    int Final=0;


    int tamañoRequerido=1000;


    bool primero=true;
    for(int i=0; i<4;i++){

        //caso si es el espacio esta en primera posicion
        if(mbr.mbr_partitions[i].part_status=='1'&&primero){
            primero=false;
            //definiendo limites
            Inicial=mbr.mbr_partitions[i].part_start;
            Final=mbr.mbr_partitions[i].part_start+mbr.mbr_partitions[i].part_s;
            //usando limites

            if(tamañoRequerido<Inicial){
                //insertando
                 espacioActual=Inicial;
                 if(espacioActual<espacioMenosAmplio&&espacioActual>tamañoRequerido){
                      espacioMenosAmplio=espacioActual;
                      std::cout<<espacioMenosAmplio<<"-----"<<espacioActual<<std::endl;
                      seEncontroEn=0;
                 }
                std::cout<<"SE USO EL PRIMERO INICIO"<<std::endl;

            }else if(Final<tamañoRequerido&&Final+tamañoRequerido<=tamañoArchivo){
                espacioActual=tamañoArchivo-Final;
                if(espacioActual<espacioMenosAmplio&&espacioActual>tamañoRequerido){
                     espacioMenosAmplio=espacioActual;
                     std::cout<<espacioMenosAmplio<<"-----"<<espacioActual<<std::endl;
                     seEncontroEn=Final;
                }
                std::cout<<"SE USO EL PRIMERO FINAL"<<std::endl;

            }

            std::cout<<"SE USO EL PRIMERO PASANDO AL SIGUIENTE"<<std::endl;
        }

        //si el espacio esta entre particiones
        if(mbr.mbr_partitions[i].part_status=='1'&&i<3){
            int inicialDer=0;
            int finalDer=0;
            //definiendo limites
            //particion a la izquierda
            Inicial=mbr.mbr_partitions[i].part_start;
            Final=mbr.mbr_partitions[i].part_start+mbr.mbr_partitions[i].part_s;

            //particion a la derecha
             std::cout<<"*****************************************************"<<std::endl;

            if(mbr.mbr_partitions[i+1].part_status=='1'&&i<3){
                 std::cout<<"*****************************************************"<<std::endl;
                inicialDer=mbr.mbr_partitions[i+1].part_start;
                finalDer=mbr.mbr_partitions[i+1].part_start+mbr.mbr_partitions[i+1].part_s;
                std::cout<<inicialDer<<"finalIZ " <<finalDer<<std::endl;

            }

            espacioEncontrado=inicialDer-Final;
              std::cout<<espacioEncontrado<<"SE ENCONTRO UN ESPACIO ENTRE PARTICIONES DE " <<finalDer<<std::endl;
            if(espacioEncontrado>tamañoRequerido){
                espacioActual=espacioEncontrado;
                if(espacioActual<espacioMenosAmplio&&espacioActual>tamañoRequerido){
                     espacioMenosAmplio=espacioActual;
                     std::cout<<espacioMenosAmplio<<"-----"<<espacioActual<<std::endl;
                     seEncontroEn=Final;
                }
                std::cout<<"SE USO EL EL ESPACIO ENTRE PARTICION"<<std::endl;

            }
            std::cout<<"SE USO EL EL ESPACIO ENTRE PASANDO AL SIGUIENTE"<<std::endl;
        }

        // si el espacio esta al final
        if(mbr.mbr_partitions[i].part_status=='1'&&i==3){
            Inicial=mbr.mbr_partitions[i].part_start;
            Final=mbr.mbr_partitions[i].part_start+mbr.mbr_partitions[i].part_s;
            std::cout<<tamañoArchivo<<"-----"<<Final<<"-----"<<i<<std::endl;

            if(tamañoRequerido<=(tamañoArchivo-Final)){
                espacioActual=tamañoArchivo-Final;
                if(espacioActual<espacioMenosAmplio&&espacioActual>tamañoRequerido){
                     espacioMenosAmplio=espacioActual;
                     std::cout<<espacioMenosAmplio<<"-----"<<espacioActual<<std::endl;
                     seEncontroEn=Final;
                }
                std::cout<<"SE USO EL EL ESPACIO ULTIMO"<<std::endl;

            }

        }
   std::cout<<"S%%%%%%%%%%%%%%%%%%%%%%%%% "<<i<<std::endl;
   std::cout<<"espacio menos amplio de: "<<espacioMenosAmplio<<"posicion: "<<seEncontroEn<<std::endl;
    }
   std::cout<<"Se encontr el espacio menos amplio de: "<<espacioMenosAmplio<<"En la posicion: "<<seEncontroEn<<std::endl;
   if(espacioMenosAmplio==tamañoArchivo){
       std::cout<<"No se encontro espacio suficente para la nueva particion"<<std::endl;

   }else if(espacioMenosAmplio>tamañoRequerido&&espacioMenosAmplio!=tamañoArchivo){
       mbr.mbr_partitions[0].part_start = seEncontroEn;
       mbr.mbr_partitions[0].part_s = tamañoRequerido;
       mbr.mbr_partitions[0].part_status='1';

   }


}

void Libreria::ParticionFirstFit(struct MBR mbr){
    int espacioEncontrado=0;
    int Inicial=0;
    int Final=0;
    int tamañoRequerido=0;
    int tamañoArchivo = mbr.mbr_tamano;
    bool esPrimero=true;
    //obteniendo el tamaño requerido
    for(int i=0; i<4;i++){
        if(mbr.mbr_partitions[i].part_status=='0'){
            tamañoRequerido=mbr.mbr_partitions[i].part_s;
            break;
        }
    }
    for(int i=0; i<4;i++){
        //todas llenas
        //caso si es el espacio esta en primera posicion
        if(mbr.mbr_partitions[i].part_status=='1'&&esPrimero){
            //definiendo limites
            Inicial=mbr.mbr_partitions[i].part_start;
            Final=mbr.mbr_partitions[i].part_start+mbr.mbr_partitions[i].part_s;
            //usando limites
            std::cout<<Final<<"----"<<mbr.mbr_partitions[i].part_status<<i<<std::endl;
            if(tamañoRequerido<Inicial){
                //insertando
                 mbr.mbr_partitions[0].part_start = 0;
                 mbr.mbr_partitions[0].part_s = tamañoRequerido;
                 mbr.mbr_partitions[0].part_status='1';
                 std::cout<<"SE USO EL PRIMERO INICIO"<<std::endl;
                 break;
            }else if(Final<tamañoRequerido&&Final+tamañoRequerido<=tamañoArchivo){
                mbr.mbr_partitions[0].part_start = Final+tamañoRequerido;
                mbr.mbr_partitions[0].part_s = tamañoRequerido;
                mbr.mbr_partitions[0].part_status='1';
                std::cout<<"SE USO EL PRIMERO FINAL"<<std::endl;
                break;
            }
            esPrimero=false;
            std::cout<<"SE USO EL PRIMERO PASANDO AL SIGUIENTE"<<std::endl;
        }

        //si el espacio esta entre particiones
        if(mbr.mbr_partitions[i].part_status=='1'&&i<3){
            int inicialIZQ=0;
            int finalIZQ=0;
            //definiendo limites
            //particion a la izquierda
            Inicial=mbr.mbr_partitions[i].part_start;
            Final=mbr.mbr_partitions[i].part_start+mbr.mbr_partitions[i].part_s;

            //particion a la derecha
            if(mbr.mbr_partitions[i+1].part_status=='1'&&i<4){
                inicialIZQ=mbr.mbr_partitions[i+1].part_start;
                finalIZQ=mbr.mbr_partitions[i+1].part_start+mbr.mbr_partitions[i+1].part_s;
            }else{
                std::cout<<"no se encontro espacio entre particiones"<<std::endl;
            }

            espacioEncontrado=inicialIZQ-Final;

            if(espacioEncontrado>tamañoRequerido){
                mbr.mbr_partitions[0].part_start = Final;
                mbr.mbr_partitions[0].part_s = tamañoRequerido;
                mbr.mbr_partitions[0].part_status='1';
                std::cout<<"SE USO EL EL ESPACIO ENTRE PARTICION"<<std::endl;
                break;
            }
            std::cout<<"SE USO EL EL ESPACIO ENTRE PASANDO AL SIGUIENTE"<<std::endl;
        }

        // si el espacio esta al final
        if(mbr.mbr_partitions[i].part_status=='1'&&i==3){
            Inicial=mbr.mbr_partitions[i].part_start;
            Final=mbr.mbr_partitions[i].part_start+mbr.mbr_partitions[i].part_s;

            if(tamañoRequerido<=(-Final+tamañoArchivo)){
                mbr.mbr_partitions[0].part_start = Final;
                mbr.mbr_partitions[0].part_s = tamañoRequerido;
                mbr.mbr_partitions[0].part_status='1';
                std::cout<<"SE USO EL EL ESPACIO ULTIMO"<<std::endl;
                break;
            }
          std::cout<<"NO SE ENCONTRO ESPACIO PARA LA PARTICION"<<std::endl;
        }

    }
}


void Libreria::OrdenarParticionesActivasDondeEmpiezan(struct MBR mbr){
    Partition aux;
     //primer ordenamiento
    //ordenamienton por valor
    for(int i=0; i<3;i++){
            for(int j=0; j<3-i; j++){
                if(mbr.mbr_partitions[j].part_start > mbr.mbr_partitions[j+1].part_start){
                    aux=mbr.mbr_partitions[j];
                    mbr.mbr_partitions[j]=mbr.mbr_partitions[j+1];
                    mbr.mbr_partitions[j+1]=aux;
           }
        }
    }

}

void Libreria::OrdenarParticionesActivasEInactivas(struct MBR mbr){
    Partition aux;
    for(int i=0; i<3;i++){
            for(int j=0; j<3-i; j++){
                int A = (int)mbr.mbr_partitions[j].part_status;
                int B = (int)mbr.mbr_partitions[j+1].part_status;
                if(A > B){
                    aux=mbr.mbr_partitions[j];
                    mbr.mbr_partitions[j]=mbr.mbr_partitions[j+1];
                    mbr.mbr_partitions[j+1]=aux;

            }
        }
    }
}

std::string Libreria::ArregloCharAString(char charArray[], int arregloTamanio){
    std::string retorno = "";
    for (int i = 0; i < arregloTamanio; i++) {
            retorno = retorno + charArray[i];
    }
    return retorno;
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

bool Libreria::StringIgual(std::string entradaA, std::string entradaB){

        std::string compararA = entradaA;
        std::string compararB = entradaB;

        boost::trim(compararA);
        boost::trim(compararB);

        unsigned int sz = compararA.size();
        if (compararB.size() != sz)
            return false;
        for (unsigned int i = 0; i < sz; ++i)
            if (tolower(compararA[i]) != tolower(compararB[i]))
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

