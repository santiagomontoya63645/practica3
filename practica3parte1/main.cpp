#include <fstream>
#include <iostream>
#include <string>
#include <math.h>
#include "cod_y_decod.h"
using namespace std;
//ojo para que funcione bien este codigo debe estar guardado en una carpeta llamada practica3parte1 y esta carpeta debe de tener una carpeta llamada BD
// para el ingreso del nombre de la funcion debes ser  nombre.txt

int main(){
  int opcion=0,semilla=0;
  int condicion=0;

  string nombreEntrada={};
  string nombresalida={};


  cout<<"ingrese 1 si desea codificar o 2 si desea decodificar ";
  cin>>condicion;
  if(condicion==1){
      cout<<"ingrese la semilla con la que quiere codificar  el archivo: ";
      cin>>semilla;
      cout<<"ingrese metodo de codifiacion"<<endl;
      cin>>opcion;
      cout<<"ingrese nombre de archivo que desea codificar: "<<endl;
      cin>> nombreEntrada;
      cout<<"ingrese nombre de archivo de salida: "<<endl;
      cin>> nombresalida;
      codificar(semilla,opcion,nombreEntrada,nombresalida);
  }
  else{
      if(condicion==2){
          cout<<"ingrese la semilla con la que quiere decodificar el archivo: ";
          cin>>semilla;
          cout<<"ingrese metodo de decodifiacion"<<endl;
          cin>>opcion;
          cout<<"ingrese nombre de archivo que desea decodificar: "<<endl;
          cin>> nombreEntrada;
          cout<<"ingrese nombre de salida: "<<endl;
          cin>> nombresalida;
          decodificar(semilla,opcion,nombreEntrada,nombresalida);
      }
 }
}

