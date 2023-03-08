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

/*
// tamaño de mdr
  // tamaño del archivo

  Libreria* lib = new Libreria();

  struct MBR mbr = lib->CrearMBR();

  int tamañoArchivo=1000;

  mbr.mbr_partitions[0].part_start = 0;
  mbr.mbr_partitions[0].part_s = 100;
  mbr.mbr_partitions[0].part_status='1';

  mbr.mbr_partitions[3].part_start = 201;
  mbr.mbr_partitions[3].part_s = 100;
  mbr.mbr_partitions[3].part_status='1';

  mbr.mbr_partitions[2].part_start = 400;
  mbr.mbr_partitions[2].part_s = 200;
  mbr.mbr_partitions[2].part_status='1';

  mbr.mbr_partitions[1].part_start = 0;
  mbr.mbr_partitions[1].part_s = 100;
  mbr.mbr_partitions[1].part_status='0';



  Partition aux;

    //primer ordenamiento
  //ordenamienton por valor
  for(int i=0; i<3;i++){
          for(int j=0; j<3-i; j++){
              if(mbr.mbr_partitions[j].part_start >= mbr.mbr_partitions[j+1].part_start){
                  aux=mbr.mbr_partitions[j];
                  mbr.mbr_partitions[j]=mbr.mbr_partitions[j+1];
                  mbr.mbr_partitions[j+1]=aux;

          }
      }
  }

    //segundo ordenamiento
  //ordenamienton por activacion
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

  //SABER SI ESTA LLENO O VACIO
  bool noHayParticiones=false;
  bool noParticionesDisponibles=false;
  int contadorDisponibles=0;
  int contadorNoDisponibles=0;
  for(int i=0; i<4;i++){
      if(mbr.mbr_partitions[i].part_status=='0'){
          contadorDisponibles=contadorDisponibles+1;
      }else{
            contadorNoDisponibles=contadorNoDisponibles+1;

      }
  }
  if(contadorDisponibles==4){
     noHayParticiones = true;
  }else if(contadorNoDisponibles==4){
      noParticionesDisponibles=true;
  }


  //WF -----------------------------------------------------------------------------------------------

  int espacioEncontrado=0;

  int Inicial=0;
  int Final=0;


    int tamañoRequerido=100;
    int espacioMasAmplio=0;
    int espacioActual=0;
    int seEncontroEn=0;

    bool primero=true;
    for(int i=0; i<4;i++){
        if(noParticionesDisponibles){
            cout<<"Todas las particiones estan siendo usadas, no se puede agregar otra"<<endl;
            break;
        }
        //No hay ninguna
        if(noHayParticiones){
            mbr.mbr_partitions[0].part_start = 0;
            mbr.mbr_partitions[0].part_s = tamañoRequerido;
            mbr.mbr_partitions[0].part_status='1';
            cout<<"SE COLOCO EN 0"<<endl;
            break;
        }
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
                 if(espacioActual>espacioMasAmplio){
                      espacioMasAmplio=espacioActual;
                      cout<<espacioMasAmplio<<"-----"<<espacioActual<<endl;
                      seEncontroEn=0;
                 }
                 cout<<"SE USO EL PRIMERO INICIO"<<endl;

            }else if(Final<tamañoRequerido&&Final+tamañoRequerido<=tamañoArchivo){
                espacioActual=tamañoArchivo-Final;
                if(espacioActual>espacioMasAmplio){
                     espacioMasAmplio=espacioActual;
                     cout<<espacioMasAmplio<<"-----"<<espacioActual<<endl;
                     seEncontroEn=Final;
                }
                cout<<"SE USO EL PRIMERO FINAL"<<endl;

            }

            cout<<"SE USO EL PRIMERO PASANDO AL SIGUIENTE"<<endl;
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
             cout<<"*****************************************************"<<endl;

            if(mbr.mbr_partitions[i+1].part_status=='1'&&i<3){
                 cout<<"*****************************************************"<<endl;
                inicialDer=mbr.mbr_partitions[i+1].part_start;
                finalDer=mbr.mbr_partitions[i+1].part_start+mbr.mbr_partitions[i+1].part_s;
                cout<<inicialDer<<"finalIZ " <<finalDer<<endl;

            }

            espacioEncontrado=inicialDer-Final;
              cout<<espacioEncontrado<<"SE ENCONTRO UN ESPACIO ENTRE PARTICIONES DE " <<finalDer<<endl;
            if(espacioEncontrado>tamañoRequerido){
                espacioActual=espacioEncontrado;
                if(espacioActual>espacioMasAmplio){
                     espacioMasAmplio=espacioActual;
                     cout<<espacioMasAmplio<<"-----"<<espacioActual<<endl;
                     seEncontroEn=Final;
                }
                cout<<"SE USO EL EL ESPACIO ENTRE PARTICION"<<endl;

            }
            cout<<"SE USO EL EL ESPACIO ENTRE PASANDO AL SIGUIENTE"<<endl;
        }

        // si el espacio esta al final
        if(mbr.mbr_partitions[i].part_status=='1'&&i==3){
            Inicial=mbr.mbr_partitions[i].part_start;
            Final=mbr.mbr_partitions[i].part_start+mbr.mbr_partitions[i].part_s;
            cout<<tamañoArchivo<<"-----"<<Final<<"-----"<<i<<endl;

            if(tamañoRequerido<=(tamañoArchivo-Final)){
                espacioActual=tamañoArchivo-Final;
                if(espacioActual>espacioMasAmplio){
                     espacioMasAmplio=espacioActual;
                     cout<<espacioMasAmplio<<"-----"<<espacioActual<<endl;
                     seEncontroEn=Final;
                }
                cout<<"SE USO EL EL ESPACIO ULTIMO"<<endl;

            }

        }
   cout<<"S%%%%%%%%%%%%%%%%%%%%%%%%% "<<i<<endl;
    }
   cout<<"Se encontr el espacio mas amplio de: "<<espacioMasAmplio<<"En la posicion: "<<seEncontroEn<<" TAMAÑO REQUERIDO DE:"<<tamañoRequerido<<endl;
   if(espacioMasAmplio>tamañoRequerido){
       mbr.mbr_partitions[0].part_start = seEncontroEn;
       mbr.mbr_partitions[0].part_s = tamañoRequerido;
       mbr.mbr_partitions[0].part_status='1';
       cout<<"SE EJECUTO CORRECTAMENTE "<<endl;
   }else if(espacioMasAmplio<=tamañoRequerido){
       cout<<"EL ESPACIO ENCONTRADO ES INSUFICIENTE PARA LA PARTICION"<<endl;

   }







  //BF -----------------------------------------------------------------------------------------------

    int espacioMenosAmplio=tamañoArchivo;
    int espacioActual=0;
    int seEncontroEn=0;
    int espacioEncontrado=0;

    int Inicial=0;
    int Final=0;


    int tamañoRequerido=1000;


    bool primero=true;
    for(int i=0; i<4;i++){
        //todas llenas
        if(noParticionesDisponibles){
            cout<<"Todas las particiones estan siendo usadas, no se puede agregar otra"<<endl;
            break;
        }
        //No hay ninguna
        if(noHayParticiones){
            mbr.mbr_partitions[0].part_start = 0;
            mbr.mbr_partitions[0].part_s = tamañoRequerido;
            mbr.mbr_partitions[0].part_status='1';
            cout<<"SE COLOCO EN 0"<<endl;
            break;
        }
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
                      cout<<espacioMenosAmplio<<"-----"<<espacioActual<<endl;
                      seEncontroEn=0;
                 }
                 cout<<"SE USO EL PRIMERO INICIO"<<endl;

            }else if(Final<tamañoRequerido&&Final+tamañoRequerido<=tamañoArchivo){
                espacioActual=tamañoArchivo-Final;
                if(espacioActual<espacioMenosAmplio&&espacioActual>tamañoRequerido){
                     espacioMenosAmplio=espacioActual;
                     cout<<espacioMenosAmplio<<"-----"<<espacioActual<<endl;
                     seEncontroEn=Final;
                }
                cout<<"SE USO EL PRIMERO FINAL"<<endl;

            }

            cout<<"SE USO EL PRIMERO PASANDO AL SIGUIENTE"<<endl;
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
             cout<<"*****************************************************"<<endl;

            if(mbr.mbr_partitions[i+1].part_status=='1'&&i<3){
                 cout<<"*****************************************************"<<endl;
                inicialDer=mbr.mbr_partitions[i+1].part_start;
                finalDer=mbr.mbr_partitions[i+1].part_start+mbr.mbr_partitions[i+1].part_s;
                cout<<inicialDer<<"finalIZ " <<finalDer<<endl;

            }

            espacioEncontrado=inicialDer-Final;
              cout<<espacioEncontrado<<"SE ENCONTRO UN ESPACIO ENTRE PARTICIONES DE " <<finalDer<<endl;
            if(espacioEncontrado>tamañoRequerido){
                espacioActual=espacioEncontrado;
                if(espacioActual<espacioMenosAmplio&&espacioActual>tamañoRequerido){
                     espacioMenosAmplio=espacioActual;
                     cout<<espacioMenosAmplio<<"-----"<<espacioActual<<endl;
                     seEncontroEn=Final;
                }
                cout<<"SE USO EL EL ESPACIO ENTRE PARTICION"<<endl;

            }
            cout<<"SE USO EL EL ESPACIO ENTRE PASANDO AL SIGUIENTE"<<endl;
        }

        // si el espacio esta al final
        if(mbr.mbr_partitions[i].part_status=='1'&&i==3){
            Inicial=mbr.mbr_partitions[i].part_start;
            Final=mbr.mbr_partitions[i].part_start+mbr.mbr_partitions[i].part_s;
            cout<<tamañoArchivo<<"-----"<<Final<<"-----"<<i<<endl;

            if(tamañoRequerido<=(tamañoArchivo-Final)){
                espacioActual=tamañoArchivo-Final;
                if(espacioActual<espacioMenosAmplio&&espacioActual>tamañoRequerido){
                     espacioMenosAmplio=espacioActual;
                     cout<<espacioMenosAmplio<<"-----"<<espacioActual<<endl;
                     seEncontroEn=Final;
                }
                cout<<"SE USO EL EL ESPACIO ULTIMO"<<endl;

            }

        }
   cout<<"S%%%%%%%%%%%%%%%%%%%%%%%%% "<<i<<endl;
   cout<<"espacio menos amplio de: "<<espacioMenosAmplio<<"posicion: "<<seEncontroEn<<endl;
    }
   cout<<"Se encontr el espacio menos amplio de: "<<espacioMenosAmplio<<"En la posicion: "<<seEncontroEn<<endl;
   if(espacioMenosAmplio==tamañoArchivo){
       cout<<"No se encontro espacio suficente par ala nueva particion"<<endl;
       return 0;
   }
   else if(espacioMenosAmplio>tamañoRequerido){
       mbr.mbr_partitions[0].part_start = seEncontroEn;
       mbr.mbr_partitions[0].part_s = tamañoRequerido;
       mbr.mbr_partitions[0].part_status='1';

   }




  //FF -----------------------------------------------------------------------------------------------

  int espacioEncontrado=0;

  int Inicial=0;
  int Final=0;


  int tamañoRequerido=100;
  bool esPrimero=true;

  for(int i=0; i<4;i++){
      //todas llenas
      if(noParticionesDisponibles){
          cout<<"Todas las particiones estan siendo usadas, no se puede agregar otra"<<endl;
          break;

      }
      //No hay ninguna
      if(noHayParticiones){
          mbr.mbr_partitions[0].part_start = 0;
          mbr.mbr_partitions[0].part_s = tamañoRequerido;
          mbr.mbr_partitions[0].part_status='1';
          break;
      }
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
              cout<<"no se encontro espacio entre particiones"<<endl;
          }

          espacioEncontrado=inicialIZQ-Final;

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
      if(mbr.mbr_partitions[i].part_status=='1'&&i==3){
          Inicial=mbr.mbr_partitions[i].part_start;
          Final=mbr.mbr_partitions[i].part_start+mbr.mbr_partitions[i].part_s;

          if(tamañoRequerido<=(-Final+tamañoArchivo)){
              mbr.mbr_partitions[0].part_start = Final;
              mbr.mbr_partitions[0].part_s = tamañoRequerido;
              mbr.mbr_partitions[0].part_status='1';
              cout<<"SE USO EL EL ESPACIO ULTIMO"<<endl;
              break;
          }
        cout<<"NO SE USO NINGUNO ESTO NO DEBERIA DE PASAR"<<endl;
      }


  }

  cout<<noHayParticiones<<endl;





















  return 0;

*/




  char comando[400];
  bool repetir = true;
  do{
    //Pedimos el comando
    cout<< "> ";
    //scanf(" %[^\n]",comando);
    string entrada = "mkdisk >size=3000 >unit=k >path=/home/ubuntu/ARCHIVOS/Disco1.dsk \n fdisk >size=300 >unit=K >path=/home/ubuntu/ARCHIVOS/Disco1.dsk >name=Particion1 >fit=ff \n fdisk >size=300 >unit=b >path=/home/ubuntu/ARCHIVOS/Disco1.dsk >name=Particion4 >fit=ff \n fdisk >size=500 >unit=b >path=/home/ubuntu/ARCHIVOS/Disco1.dsk >name=Particion2 >fit=ff";
    //string entrada = "fdisk >size=300 >unit=b >path=/home/ubuntu/ARCHIVOS/Disco1.dsk >name=Particion4 >fit=bf";
    //string entrada = "fdisk >delete=full >name=Particion1 >path=/home/ubuntu/ARCHIVOS/Disco1.dsk";


    //string entrada = "rmdisk >path=/home/ubuntu/ARCHIVOS/Disco1.dsk";
    //Ahora analizamos
    analizarCadena(&entrada[0]);
  } while(repetir && false);
  cout<<"=============FIN DEL PROGRAMA============="<<std::endl;
  return 0;
}
