#include "analizador.h"
#include <iostream>
#include <stdio.h>
#include <string.h>
#include "../mkdisk/mkdisk.h"
#include "../execute/execute.h"
#include "../fdisk/fdisk.h"
#include "../rep/rep.h"
#include "rmdisk.h"
#include "mount.h"
#include "unmount.h"
#include "mkfs.h"
#include "login.h"
#include "logout.h"
#include "mkgrp.h"
#include "rmgrp.h"
#include "mkusr.h"
#include "rmusr.h"

//mkdisk >size=5 >unit=M >path="/home/mis discos/Disco3.dsk"

/*Funcione s que devuelven el tipo y el valor de un parametro en strings ya en lowercase */
string get_tipo_parametro(string parametro){
    //Iteramos hasta obtener el tipo del parametro
    string tipo = "";
    for(int i = 0; i < parametro.length(); i++){
        if(parametro.at(i) == '=') break;
        char caracter = tolower(parametro.at(i));
        tipo = tipo + caracter;
    }
    //devolvemos el string
    return tipo;
}
string get_valor_parametro(string parametro){
    //Iteramos hasta obtener el tipo del parametro
    string valor = "";
    bool concatenar = false;
    for(int i = 0; i < parametro.length(); i++){
        if(concatenar){
            char caracter = parametro.at(i);
            valor = valor + caracter;
        }
        if(parametro.at(i) == '=') concatenar = true;
    }
    //devolvemos el string
    return valor;
}

/*Funcion para analizar el comando de mkdisk*/
void analizar_mkdisk(char *parametros){
    //Pasamos a la siguiente posicion
    parametros = strtok(NULL, " ");
    //Inicializamos nuestro disco
    mkdisk *disco = new mkdisk();
    std::string concatenar = "";
    bool concatenarBolean = false;
    while(parametros != NULL){   
        //Obtenemos el tipo y el valor del parametro actual
        string tmpParam = parametros;
        std::string str = tmpParam;
            char c = '"';
            if (str.find(c) != std::string::npos) {
                concatenar = concatenar + tmpParam+" ";
                concatenarBolean=true;
            }

        string tipo = get_tipo_parametro(tmpParam);
        string valor = get_valor_parametro(tmpParam);
        //Verificamos cual parametro es para inicializar el objeto (los parametros ya vienen en lowercase)
        if(tipo == ">size"){
            disco->size = stoi(valor);
        } else if (tipo == ">path"){
            disco->path = valor;
        } else if (tipo == ">unit"){
            disco->unit = valor;
        } else if (tipo == ">fit"){
            disco->fit = valor;
        }else {
            cout << "Parametro no aceptado en 'mkdisk': " << valor << endl;
        }
        parametros = strtok(NULL, " ");
    }
    //si es true se concatena con comillas
    if(concatenarBolean){
        disco->path = concatenar;
    }
    //Creamos el disco
    disco->make_mkdisk(disco);
}


void analizar_execute(char *parametros){
    //Pasamos a la siguiente posicion
    parametros = strtok(NULL, " ");
    //Inicializamos nuestro disco
    execute *disco = new execute();
    while(parametros != NULL){
        //Obtenemos el tipo y el valor del parametro actual
        string tmpParam = parametros;
        string tipo = get_tipo_parametro(tmpParam);
        string valor = get_valor_parametro(tmpParam);
        //Verificamos cual parametro es para inicializar el objeto (los parametros ya vienen en lowercase)
        if (tipo == ">path"){
            disco->path = valor;
        } else {
            cout << "Parametro no aceptado en 'execute': " << valor << endl;
        }
        parametros = strtok(NULL, " ");
    }
    //Creamos el disco
    disco->make_execute(disco);
}

void analizar_unmount(char *parametros){
    //Pasamos a la siguiente posicion
    parametros = strtok(NULL, " ");
    //Inicializamos nuestro disco
    unmount *disco = new unmount();
    while(parametros != NULL){
        //Obtenemos el tipo y el valor del parametro actual
        string tmpParam = parametros;
        string tipo = get_tipo_parametro(tmpParam);
        string valor = get_valor_parametro(tmpParam);
        //Verificamos cual parametro es para inicializar el objeto (los parametros ya vienen en lowercase)
        if (tipo == ">id"){
            disco->id = valor;
        } else {
            cout << "Parametro no aceptado en 'unmount': " << valor << endl;
        }
        parametros = strtok(NULL, " ");
    }
    //Creamos el disco
    disco->make_unmount(disco);
}

void analizar_rmdisk(char *parametros){
    //Pasamos a la siguiente posicion
    parametros = strtok(NULL, " ");
    //Inicializamos nuestro disco
    rmdisk *disco = new rmdisk();
    std::string concatenar = "";
    bool concatenarBolean = false;
    while(parametros != NULL){
        cout << "Parametro no aceptadoadasdasdsadassdda en 'rmdisk': " << parametros << endl;
        //Obtenemos el tipo y el valor del parametro actual
        string tmpParam = parametros;
        std::string str = tmpParam;
            char c = '"';
            if (str.find(c) != std::string::npos) {
                concatenar = concatenar + tmpParam+" ";
                concatenarBolean=true;
            }

        string tipo = get_tipo_parametro(tmpParam);
        string valor = get_valor_parametro(tmpParam);
        //Verificamos cual parametro es para inicializar el objeto (los parametros ya vienen en lowercase)
        if(tipo == ">path"){
             disco->path = valor;
        }else {
            cout << "Parametro no aceptado en 'rmdisk': " << valor << endl;
        }
        parametros = strtok(NULL, " ");
    }
    //si es true se concatena con comillas
    if(concatenarBolean){
        disco->path = concatenar;
    }
    //Creamos el disco
    disco->make_rmdisk(disco);
}


void analizar_fdisk(char *parametros){
    //Pasamos a la siguiente posicion
    parametros = strtok(NULL, " ");
    //Inicializamos nuestro disco
    fdisk *disco = new fdisk();
    std::string concatenar = "";
    bool concatenarBolean = false;
    bool concatenarPath = false;
    int contador=0;

    while(parametros != NULL){
        //Obtenemos el tipo y el valor del parametro actual
        string tmpParam = parametros;
        std::string str = tmpParam;
            char c = '"';
            if (str.find(c) != std::string::npos&& contador<2) {
                concatenar = concatenar + tmpParam+" ";
                concatenarBolean=true;
                contador++;

            }

        string tipo = get_tipo_parametro(tmpParam);
        string valor = get_valor_parametro(tmpParam);
        //Verificamos cual parametro es para inicializar el objeto (los parametros ya vienen en lowercase)
        if(tipo == ">size"){
            disco->size = stoi(valor);
        } else if (tipo == ">path"){
            concatenarPath=true;
            disco->path = valor;
        } else if (tipo == ">name"){
            disco->name = valor;
        } else if (tipo == ">unit"){
            disco->unit = valor;
        }else if (tipo == ">type"){
            disco->type = valor;
        } else if (tipo == ">fit"){
            disco->fit = valor;
        } else if (tipo == ">borrar"){
            disco->borrar = valor;
        }else if (tipo == ">add"){
            disco->add = valor;
        }else {
            cout << "Parametro no aceptado en 'fdisk': " << valor << endl;
        }
        parametros = strtok(NULL, " ");
        }
    if(concatenarBolean){
        if(concatenarPath){
            disco->path = concatenar;
            concatenarPath=false;
        }

    }
    //Creamos el disco
    disco->make_fdisk(disco);
//fdisk >add=-500 >size=10 >unit=K >path="/home/mis discos/Disco4.dsk" >name="Particion4"
    //fdisk >size=1 >type=L >unit=M >fit=bf >path="/mis discos/Disco3.dsk" >name="Particion3"
}




void analizar_mount(char *parametros){
    //Pasamos a la siguiente posicion
    parametros = strtok(NULL, " ");
    //Inicializamos nuestro disco
    mount *disco = new mount();
    std::string concatenar = "";
    bool concatenarBolean = false;
    bool concatenarPath = false;
    int contador=0;

    while(parametros != NULL){
        //Obtenemos el tipo y el valor del parametro actual
        string tmpParam = parametros;
        std::string str = tmpParam;
            char c = '"';
            if (str.find(c) != std::string::npos&& contador<2) {
                concatenar = concatenar + tmpParam+" ";
                concatenarBolean=true;
                contador++;

            }

        string tipo = get_tipo_parametro(tmpParam);
        string valor = get_valor_parametro(tmpParam);
        //Verificamos cual parametro es para inicializar el objeto (los parametros ya vienen en lowercase)
         if (tipo == ">path"){
            concatenarPath=true;
            disco->path = valor;
        } else if (tipo == ">name"){
            disco->name = valor;
        } else {
            cout << "Parametro no aceptado en 'mount': " << valor << endl;
        }
        parametros = strtok(NULL, " ");
        }
    if(concatenarBolean){
        if(concatenarPath){
            disco->path = concatenar;
            concatenarPath=false;
        }

    }
    //Creamos el disco
    disco->make_mount(disco);
//fdisk >add=-500 >size=10 >unit=K >path="/home/mis discos/Disco4.dsk" >name="Particion4"
    //fdisk >size=1 >type=L >unit=M >fit=bf >path="/mis discos/Disco3.dsk" >name="Particion3"
}


void analizar_rep(char *parametros){
    //Pasamos a la siguiente posicion
    parametros = strtok(NULL, " ");
    //Inicializamos nuestro disco
    rep *disco = new rep();
    
    disco->make_rep();

}


void analizar_mkfs(char *parametros){
    //Pasamos a la siguiente posicion
    parametros = strtok(NULL, " ");
    //Inicializamos nuestro disco
    mkfs *disco = new mkfs();
    while(parametros != NULL){
        //Obtenemos el tipo y el valor del parametro actual
        string tmpParam = parametros;
        string tipo = get_tipo_parametro(tmpParam);
        string valor = get_valor_parametro(tmpParam);
        //Verificamos cual parametro es para inicializar el objeto (los parametros ya vienen en lowercase)
        if (tipo == ">id"){
            disco->id = valor;
        } else if(tipo == ">type"){
            disco->type = valor;
        }else if(tipo == ">fs"){
            disco->fs = valor;
        } else {
            cout << "Parametro no aceptado en 'mkfs': " << valor << endl;
        }
        parametros = strtok(NULL, " ");
    }
    //Creamos el disco
    disco->make_mkfs(disco);
}

void analizar_login(char *parametros){
    //Pasamos a la siguiente posicion
    parametros = strtok(NULL, " ");
    //Inicializamos nuestro disco
    login *disco = new login();
    while(parametros != NULL){
        //Obtenemos el tipo y el valor del parametro actual
        string tmpParam = parametros;
        string tipo = get_tipo_parametro(tmpParam);
        string valor = get_valor_parametro(tmpParam);
        //Verificamos cual parametro es para inicializar el objeto (los parametros ya vienen en lowercase)
        if (tipo == ">user"){
            disco->user = valor;
        } else if(tipo == ">pass"){
            disco->pass = valor;
        }else if(tipo == ">id"){
            disco->id = valor;
        } else {
            cout << "Parametro no aceptado en 'login': " << valor << endl;
        }
        parametros = strtok(NULL, " ");
    }
    //Creamos el disco
    disco->make_login(disco);
}

void analizar_logout(char *parametros){
    //Pasamos a la siguiente posicion
    parametros = strtok(NULL, " ");
    //Inicializamos nuestro disco
    logout *disco = new logout();

    disco->make_logout();

}

void analizar_mkgrp(char *parametros){
    //Pasamos a la siguiente posicion
    parametros = strtok(NULL, " ");
    //Inicializamos nuestro disco
    mkgrp *disco = new mkgrp();
    while(parametros != NULL){
        //Obtenemos el tipo y el valor del parametro actual
        string tmpParam = parametros;
        string tipo = get_tipo_parametro(tmpParam);
        string valor = get_valor_parametro(tmpParam);
        //Verificamos cual parametro es para inicializar el objeto (los parametros ya vienen en lowercase)
        if (tipo == ">name"){
            disco->name = valor;

        } else {
            cout << "Parametro no aceptado en 'mkgrp': " << valor << endl;
        }
        parametros = strtok(NULL, " ");
    }
    //Creamos el disco
    disco->make_mkgrp(disco);
}

void analizar_rmgrp(char *parametros){
    //Pasamos a la siguiente posicion
    parametros = strtok(NULL, " ");
    //Inicializamos nuestro disco
    rmgrp *disco = new rmgrp();
    while(parametros != NULL){
        //Obtenemos el tipo y el valor del parametro actual
        string tmpParam = parametros;
        string tipo = get_tipo_parametro(tmpParam);
        string valor = get_valor_parametro(tmpParam);
        //Verificamos cual parametro es para inicializar el objeto (los parametros ya vienen en lowercase)
        if (tipo == ">name"){
            disco->name = valor;

        } else {
            cout << "Parametro no aceptado en 'rmgrp': " << valor << endl;
        }
        parametros = strtok(NULL, " ");
    }
    //Creamos el disco
    disco->make_rmgrp(disco);
}

void analizar_mkusr(char *parametros){
    //Pasamos a la siguiente posicion
    parametros = strtok(NULL, " ");
    //Inicializamos nuestro disco
    mkusr *disco = new mkusr();
    while(parametros != NULL){
        //Obtenemos el tipo y el valor del parametro actual
        string tmpParam = parametros;
        string tipo = get_tipo_parametro(tmpParam);
        string valor = get_valor_parametro(tmpParam);
        //Verificamos cual parametro es para inicializar el objeto (los parametros ya vienen en lowercase)
        if (tipo == ">user"){
            disco->user = valor;

        } else if (tipo == ">pass"){
            disco->pass = valor;

        }else if (tipo == ">grp"){
            disco->grp = valor;

        }else {
            cout << "Parametro no aceptado en 'mkusr': " << valor << endl;
        }
        parametros = strtok(NULL, " ");
    }
    //Creamos el disco
    disco->make_mkusr(disco);
}

void analizar_rmusr(char *parametros){
    //Pasamos a la siguiente posicion
    parametros = strtok(NULL, " ");
    //Inicializamos nuestro disco
    rmusr *disco = new rmusr();
    while(parametros != NULL){
        //Obtenemos el tipo y el valor del parametro actual
        string tmpParam = parametros;
        string tipo = get_tipo_parametro(tmpParam);
        string valor = get_valor_parametro(tmpParam);
        //Verificamos cual parametro es para inicializar el objeto (los parametros ya vienen en lowercase)
        if (tipo == ">user"){
            disco->user = valor;

        } else {
            cout << "Parametro no aceptado en 'rmusr': " << valor << endl;
        }
        parametros = strtok(NULL, " ");
    }
    //Creamos el disco
    disco->make_rmusr(disco);
}



void analizarCadena(std::string str){
    str=str+'\n';
    int strLength = str.length();

    string concatenacion ="";
    for(int i =0; i<strLength;i++){

        if(str[i]=='\n'){
            analizar(&concatenacion[0]);
            concatenacion="";

        }else{
            concatenacion=concatenacion+str[i];
        }




    }


}

/*Funcion que define que comando es el que hay que ejecutar (se recibe un puntero del comando)*/
void analizar(char *comando) {
    char *token = strtok(comando, " ");
    if(strcasecmp(token, "mkdisk") == 0){
        cout<<"----------------------MKDISK--------------------"<<endl;
        analizar_mkdisk(token);
    }else if(strcasecmp(token, "execute") == 0){
        cout<<"----------------------execute--------------------"<<endl;
        analizar_execute(token);
    }else if(strcasecmp(token, "fdisk") == 0){
        cout<<"----------------------fdisk--------------------"<<endl;
        analizar_fdisk(token);
    }else if(strcasecmp(token, "rep") == 0){
        cout<<"----------------------rep--------------------"<<endl;
        analizar_rep(token);
    } else if(strcasecmp(token, "rmdisk") == 0){
        cout<<"----------------------rmdisk--------------------"<<endl;
        analizar_rmdisk(token);
    }else if(strcasecmp(token, "mount") == 0){
        cout<<"----------------------mount--------------------"<<endl;
        analizar_mount(token);
    } else if(strcasecmp(token, "unmount") == 0){
        cout<<"----------------------unmount--------------------"<<endl;
        analizar_unmount(token);
    } else if(strcasecmp(token, "mkfs") == 0){
        cout<<"----------------------mkfs--------------------"<<endl;
        analizar_mkfs(token);
    }else if(strcasecmp(token, "login") == 0){
        cout<<"----------------------login--------------------"<<endl;
        analizar_login(token);
    }else if(strcasecmp(token, "logout") == 0){
        cout<<"----------------------logout--------------------"<<endl;
        analizar_logout(token);
    }else if(strcasecmp(token, "mkgrp") == 0){
        cout<<"----------------------mkgrp--------------------"<<endl;
        analizar_mkgrp(token);
    }else if(strcasecmp(token, "rmgrp") == 0){
        cout<<"----------------------rmgrp--------------------"<<endl;
        analizar_rmgrp(token);
    }else if(strcasecmp(token, "mkusr") == 0){
        cout<<"----------------------mkusr--------------------"<<endl;
        analizar_mkusr(token);
    }else if(strcasecmp(token, "rmusr") == 0){
        cout<<"----------------------rmusr--------------------"<<endl;
        analizar_rmusr(token);
    }else {
        cout << "Comando no aceptado :c" << endl;
    }
}
