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



  char comando[400];
  bool repetir = true;
  do{
    //Pedimos el comando
    cout<< "> ";
    //scanf(" %[^\n]",comando);
    string entrada = "fdisk >size=300 >path=/home/ubuntu/ARCHIVOS/Disco1.dsk >name=Particion2";
    //mkdisk >size=3000 >unit=K >path=/home/ubuntu/ARCHIVOS/Disco1.dsk \n
    //string entrada = "rmdisk >path=/home/ubuntu/ARCHIVOS/Disco1.dsk";
    //Ahora analizamos
    analizarCadena(&entrada[0]);
  } while(repetir && false);
  cout<<"=============FIN DEL PROGRAMA============="<<std::endl;
  return 0;
}
