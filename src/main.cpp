#include <stdio.h>
#include <fstream>
#include "./analizador/analizador.h"
using namespace std;
#include <QCoreApplication>

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
    scanf(" %[^\n]",comando);
    //Ahora analizamos
    analizar(comando);
  } while(repetir);
  return 0;
}
