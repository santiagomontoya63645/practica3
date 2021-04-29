#include <fstream>
#include <iostream>
#include <string>
#include <math.h>
#include "cod_y_decod.h"
using namespace std;
//ojo para que funcione bien este codigo y la libreria debe estar guardado en una carpeta llamada practica3parte1 y esta carpeta debe de tener una carpeta llamada BD
// para el ingreso del nombre del archivo debes agregarle la extension en caso de que se llame nombre y es .txt debes ingresar nombre.txt
// todos los archivos de salida estaran guardados en la carpeta BD que estara dentro de la carpeta practica3parte1
//tenga en cuenta al momento de decodificar de ingresar el metodo de decodificacion y l asemilla con el que elarchivo se codifico inicialmente
//si sale el mensaje el archivo no existe es porque te equivocastes en el nombre del archivo de entrad recuerde agregar la extension en qu eeste el archivo
//en la libreria se invoca principalmente las funciones codificar y decodificar las cuales reciven codificar(semilla,opcion,nombreEntrada,nombresalida);
//primero una variable tipo entero que indica la semilla de codificacion o decodificacion, opcion que recive el valor 1 para metodo 1 o 2 para metodo2 explicados en clase
//una variable string nombre de entrada que recive el nombre de entrada del archivo que debe de estar enla carpeta BD de practica3parte1
//y una variable tipo string que  indica el nombre de salida del archivo el cual queda guardado en la carpeta BD
//cuando se codifique algo te mostrara en el serial el contenido del archivo codificado
// ojo tiene que ser un documento sin tildes el que se desea codificar y decodificar
// el texto debe de tener menos de 300 lineas y menos de 2331 caracteres
//recuerde que el .h debe de estar tambien en la carpeta practica3parte1
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

