#include <stdio.h>
#include <fstream>
#include "./analizador/analizador.h"
using namespace std;
#include <QCoreApplication>

#include "./analizador/libreria.h"


int main(int argc, char *argv[])
{
  cout << "*****************************************" << endl;
  cout << "***** JOSUE DANIEL SOLIS OSORIO ********" << endl;
  cout << "********* SISTEMA DE ARCHIVOS ***********" << endl;
  cout << "*********** PROYECTO 1, MIA *************" << endl;
  cout << "************** 202001574 ****************" << endl;
  cout << "*****************************************" << endl;


// tamaño de mdr
  // tamaño del archivo

  Libreria* lib = new Libreria();

  struct MBR mbr = lib->CrearMBR();

  int tamañoArchivo=6000;

  mbr.mbr_partitions[0].part_start = 600;
  mbr.mbr_partitions[0].part_s = 1000;
  mbr.mbr_partitions[0].part_status='1';

  mbr.mbr_partitions[3].part_start = 1700;
  mbr.mbr_partitions[3].part_s = 1300;
  mbr.mbr_partitions[3].part_status='1';

  mbr.mbr_partitions[2].part_start = 3500;
  mbr.mbr_partitions[2].part_s = 1000;
  mbr.mbr_partitions[2].part_status='1';

  mbr.mbr_partitions[1].part_start = 0;
  mbr.mbr_partitions[1].part_s = 1200;
  mbr.mbr_partitions[1].part_status='0';



  Partition aux;


  //ordenamiento
  for(int i=0; i<3;i++){
          for(int j=0; j<3-i; j++){
              if(mbr.mbr_partitions[j].part_start > mbr.mbr_partitions[j+1].part_start){
                  aux=mbr.mbr_partitions[j];
                  mbr.mbr_partitions[j]=mbr.mbr_partitions[j+1];
                  mbr.mbr_partitions[j+1]=aux;

          }
      }
  }


  //FF

  int espacioEncontrado=0;

  int Inicial=0;
  int Final=0;


  int tamañoRequerido=1200;


  //CANTIDAD DE ITERACIONES
  /*int contador=0;
  for(int i=0; i<4;i++){
      if(mbr.mbr_partitions[i].part_status=='1'){
          contador=contador+1;
      }else{
          cout<<"se deve de salta la particion"<<i<<endl;
      }
  }*/

  //FF
  bool esPrimero=true;
  for(int i=0; i<4;i++){
      //caso si es el espacio esta en primera posicion
      if(mbr.mbr_partitions[i].part_status=='1'&&esPrimero){
          //definiendo limites
          Inicial=mbr.mbr_partitions[i].part_start;
          Final=mbr.mbr_partitions[i].part_start+mbr.mbr_partitions[i].part_s;
          //usando limites
          cout<<Final<<"----"<<mbr.mbr_partitions[i].part_status<<i<<endl;
          if(tamañoRequerido<Inicial){
              //insertando
               mbr.mbr_partitions[0].part_start = 0;
               mbr.mbr_partitions[0].part_s = tamañoRequerido;
               mbr.mbr_partitions[0].part_status='1';
               cout<<"SE USO EL PRIMERO INICIO"<<endl;
               break;
          }else if(Final<tamañoRequerido&&Final+tamañoRequerido<=tamañoArchivo){
              mbr.mbr_partitions[0].part_start = Final+tamañoRequerido;
              mbr.mbr_partitions[0].part_s = tamañoRequerido;
              mbr.mbr_partitions[0].part_status='1';
              cout<<"SE USO EL PRIMERO FINAL"<<endl;
              break;
          }
          esPrimero=false;
          cout<<"SE USO EL PRIMERO PASANDO AL SIGUIENTE"<<endl;
      }

      //si el espacio esta entre particiones
      if(mbr.mbr_partitions[i].part_status=='1'){
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
              cout<<"no se encontro espacio entre particiones"<<endl;
          }

          espacioEncontrado=Final-inicialIZQ;

          if(espacioEncontrado>tamañoRequerido){
              mbr.mbr_partitions[0].part_start = Final;
              mbr.mbr_partitions[0].part_s = tamañoRequerido;
              mbr.mbr_partitions[0].part_status='1';
              cout<<"SE USO EL EL ESPACIO ENTRE PARTICION"<<endl;
              break;
          }
          cout<<"SE USO EL EL ESPACIO ENTRE PASANDO AL SIGUIENTE"<<endl;
      }

      // si el espacio esta al final
      if(mbr.mbr_partitions[i].part_status=='1'||i==3){
          Inicial=mbr.mbr_partitions[i].part_start;
          Final=mbr.mbr_partitions[i].part_start+mbr.mbr_partitions[i].part_s;

          if(tamañoRequerido<=(Final-tamañoArchivo)){
              mbr.mbr_partitions[0].part_start = Final;
              mbr.mbr_partitions[0].part_s = tamañoRequerido;
              mbr.mbr_partitions[0].part_status='1';
              cout<<"SE USO EL EL ESPACIO ULTIMO"<<endl;
              break;
          }

      }

  }

  return 0;










  char comando[400];
  bool repetir = true;
  do{
    //Pedimos el comando
    cout<< "> ";
    //scanf(" %[^\n]",comando);
    string entrada = "mkdisk >size=3000 >unit=K >path=/home/ubuntu/ARCHIVOS/Disco1.dsk \n fdisk >size=300 >path=/home/ubuntu/ARCHIVOS/Disco1.dsk >name=Particion1";

    //string entrada = "rmdisk >path=/home/ubuntu/ARCHIVOS/Disco1.dsk";
    //Ahora analizamos
    analizarCadena(&entrada[0]);
  } while(repetir && false);
  cout<<"=============FIN DEL PROGRAMA============="<<std::endl;
  return 0;
}
