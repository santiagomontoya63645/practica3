#include <fstream>
#include <iostream>
#include <string>
#include <math.h>
using namespace std;
//ojo para que funcione bien este codigo debe estar guardado en una carpeta llamada practica3parte1 y esta carpeta debe de tener una carpeta llamada BD
void leer_archivo(char *contenido);
void convertircadena(int *entero,char *contenido);
void siste_binario(char *binario,int *entero);
void metodo1(char *binario, int );
void metodo2(char *binario,int );
void deco_metodo1(int);
void deco_metodo2(int);

int main(){
  int opcion=0,semilla=0;
  char contenido[10000]={};
  int entero[10000]={};
  char binario[80000]={};
 // leer_archivo(contenido);
 // convertircadena(entero,contenido);
 // siste_binario(binario,entero);

  cout<<endl<<"ingrese 1 para el metodo1"<<endl<< "ingrese 2 para el metodo 2."<<endl<<"ingrese 3 para decodificar metodo 1."<<endl<<"ingrese 4 para decodificar metodo 2."<<endl<<"ingrese 5 para salir."<<endl;
  while(opcion!=5){
      cin>>opcion;;

      char contenido[10000]={};
      int entero[10000]={};
      char binario[80000]={};
      cout<<"ingrese la semilla con la que quiere codificar o decodificar el archivo: ";
      cin>>semilla;
        switch (opcion) {
        case 1:

             leer_archivo(contenido);
             convertircadena(entero,contenido);
             siste_binario(binario,entero);
             metodo1(binario,semilla);
             break;
         case 2:
             leer_archivo(contenido);
             convertircadena(entero,contenido);
             siste_binario(binario,entero);
             metodo2(binario,semilla);
             break;
         case 3:
            deco_metodo1(semilla);
            break;
         case 4:
            deco_metodo2(semilla);
            break;
      }
      cout<<endl<<"ingrese 1 para el metodo1"<<endl<< "ingrese 2 para el metodo 2."<<endl<<"ingrese 3 para decodificar metodo 1."<<endl<<"ingrese 4 para decodificar metodo 2."<<endl<<"ingrese 5 para salir."<<endl;
  }
}

void leer_archivo(char *contenido){
char nombre_arch[200]={"../practica3parte1/BD/"};
char linea[10000]={};
int posicion=0;
char prueba[200]={};
int contprueba=0;
cout<<"ingrese nombre del archivo fuente para codificar: ";
cin>>prueba;
while(prueba[contprueba]!='\0') contprueba++;
for(int i=0;i<=contprueba;i++){
    nombre_arch[22+i]=prueba[i];
}
ifstream leer;
         leer.open(nombre_arch);
         if(leer.is_open()){
             while(!leer.eof()){ //si llega a fin del archivo me retorna false
             int sizelinea=0;
             leer.getline(linea,100);//Solo me esta leyendo la ultima linea
             while (*(linea+sizelinea)!='\0') sizelinea++;
             for (int i=posicion, b=0;i<posicion+sizelinea;i++,b++) {
                 *(contenido+i)=*(linea+b);                  //concactenamos liea por linea en el chart
             }
             *(contenido+posicion+sizelinea)='\n';
             posicion+=sizelinea+1;
             }
         }
         else {
             cout<<"el archivo no existe."<<endl;
         }
        leer.close();
}
void convertircadena(int *entero,char *contenido){
   int k=0;
   char *p=contenido;
   while (*(p++)!='\0')k++;	//longitud de la cadena
   for (int i=0;i<k;i++){
       *(entero+i)=*(contenido+i);	//conversion a entero
   }
}
void siste_binario(char *binario,int *entero){
    int dividendo=0, resto=0, divisor = 2,i=7,k=0,aux=0,iaux=7;
    int *p=entero;
    while (*(p++)!='\0')k++;	//longitud de la cadena
    for (int j=0;j<k;j++){
        dividendo = entero[j];
        aux=dividendo;
        while(dividendo >= divisor){ //Mientras el dividendo sea mayor o igual que el divisor, es decir, mayor o igual que 2.
            resto = dividendo % 2;
            if(resto == 1){
                 *(binario+i)= 49; //Si el resto es igual a 1 concatenamos 1 a la variable char llamada binario
            }
            else{
                *(binario+i)= 48; // Sino concatemanos 0
            }

              dividendo = dividendo/divisor; // Actualizamos el valor del dividendo dividiendolo entre 2.
              i--;
        }
             if(dividendo == 1){
              *(binario+i)= 49; // Por último sí el valor final del dividendo es 1 concatenamos 1 sino concatenamos 0.
             }
             else {
              *(binario+i)= 48;
             }
             for(int c=0;c<8;c++){
                 if(aux<pow(2,c)){
                     i--;           //primero cambio la posicion para poder agregar los ceros faltantes
                     aux=0;
                     *(binario+i)= 48;    //for para agregar los primeros ceros en binario de cada caracter
                 }
             }
             iaux+=8; // variable auxiliar para conservar el valor inicial de i
             i=iaux;// varaiable que inicia des de primera posicion del numero binario
   }
}
void metodo1(char *binario, int semilla){
    int contador=0,k=0,ceros=0,unos=0,pos=0,pos2=0;
    int cantid_ceros[10000]={};
    int cantid_unos[10000]={};
    char  salida[200]={"../practica3parte1/BD/"};
    char bloques_bits[1000]={};
    char codificado [100000]={};
    char *p=binario;
    while (*(p++)!='\0')k++;	// k es la longitud de la cadena
    while(contador<k){
        for(int i=contador; i<semilla+contador;i++){ //-----------------******-----------------
            if(*(binario+i)=='0'){
                ceros+=1;
            }
            else {
                unos+=1;                      //se cuenta las cantida de ceros y unos que hay en cada bloque
            }
        }
        *(cantid_ceros+pos)=ceros;
        *(cantid_unos+pos)=unos;
        pos+=1;
        contador+=semilla;
        ceros=0;
        unos=0;                             //-----------------******-----------------
    }
    for(int k=0;k<semilla;k++){
        if(*(binario+k)=='0'){
             *(codificado+k)='1';
        }
        else {                       //codificamos el primer bloque de bits
            *(codificado+k)='0';
        }

    }
    contador=semilla;
     for(int i=0; i<k/semilla;i++){
         int pos1=0;
        for(int j=contador; j<semilla+contador;j++){ //-----------------******-----------------
            if(*(binario+j)=='0'){
                *(bloques_bits+pos1)='0';
            }
            else {                                     //apartir del segundo bloque de bits copiuamos los bloques
                *(bloques_bits+pos1)='1';
            }
            pos1++;
        }
        for(int j=0; j<semilla;j++){
            if(*(cantid_ceros+pos2)==*(cantid_unos+pos2)){ //-----------------******-----------------
                if(*(bloques_bits+j)=='0'){
                    *(bloques_bits+j)='1';
                }
                else {                                    //ceros igual a unos
                    *(bloques_bits+j)='0';
                }
            }
            if(*(cantid_ceros+pos2)>*(cantid_unos+pos2)){  //-----------------******-----------------
                if((j+1)%2==0){
                    if(*(bloques_bits+j)=='0'){
                        *(bloques_bits+j)='1';
                    }
                    else {
                        *(bloques_bits+j)='0';          //cros mayor que unos
                    }
                }
             }                                      //-----------------******-----------------
            if(*(cantid_ceros+pos2)<*(cantid_unos+pos2)){
                if((j+1)%3==0){
                    if(*(bloques_bits+j)=='0'){
                        *(bloques_bits+j)='1';
                    }
                    else {
                        *(bloques_bits+j)='0';          //cros menor que unos
                    }
                }
             }                                      //-----------------******-----------------
        }
        int s=0;
        int s_aux=0;
        for(s=contador;s<semilla+contador;s++){
           *(codificado+s)=*(bloques_bits+ s_aux);    //guardamos los bits codificados
           s_aux++;
        }
        pos2++;                //para ingresar a las posiciones de cantidad de ceros y unos
        contador+=semilla;
    }
     char prueba[200]={};
     int contprueba=0;
     cout<<"ingrese el nombre del archivo de salida: ";
     cin>>prueba;
     while(prueba[contprueba]!='\0') contprueba++;
     for(int i=0;i<=contprueba;i++){
         salida[22+i]=prueba[i];
     }

     ofstream escribir;
     escribir.open(salida);
     for (int i=0;i<k;i++) {
     escribir<<*(codificado+i);
     }
     escribir.close();
     cout<<"archivo original:     ";for(int i=0;i<k;i++) cout<<*(binario+i);
     cout<<endl;
     cout<<"archivo codificado:   ";for(int i=0;i<k;i++) cout<<*(codificado+i);
     cout<<endl;
   }

void metodo2(char *binario,int semilla){
    char bloques_bits[20]={};
    char codificado [50000]={};
    char prueba[200]={};
    int contprueba=0;
    int k=0;
    char salida2[200]={"../practica3parte1/BD/"};
    char *p=binario;
    while (*(p++)!='\0')k++;	//k es la longitud de la cadena

    char temporal;
    for (int i=0;i<k;i=i+semilla) {//recorremos el binario sin codificar con saltos del valor de la semilla
        for (int e=i,a=0;e<i+semilla;e++,a++) {//Para ir separando los bloques y guardarlos en bloques_bits
            *(bloques_bits+a)=*(binario+e);
        }
        for (int b=semilla-1;b>0;b--) {//Para mover una posicion a la derecha cada bit y el ultimo quede a la izquierda del bloque
            if(*(bloques_bits+b)!='\0'){//Si un valor del bloque es '\0' no cambie posiciones
                temporal=*(bloques_bits+b); //bit que va ir en la primera posicion
                *(bloques_bits+b)=*(bloques_bits+b-1);
                *(bloques_bits+b-1)=temporal;// se guarda el bit temporal en la primera posicion
            }
        }
        for (int a=i,b=0;a<i+semilla;a++,b++) {//Iremos guardando los bloques codificados en el arreglo codificado
            *(codificado+a)=*(bloques_bits+b);
        }
    }
    cout<<endl<<"ingrese el nombre del archivo de salida: ";

    cout<<"ingrese el nombre del archivo de salida: ";
    cin>>prueba;
    while(prueba[contprueba]!='\0') contprueba++;
    for(int i=0;i<=contprueba;i++){
        salida2[22+i]=prueba[i];
    }
    ofstream escribir;
    escribir.open(salida2);
    escribir<<codificado;
    escribir.close();
    cout<<"archivo original:              ";for(int i=0;i<k;i++) cout<<*(binario+i);
    cout<<endl;
    cout<<"archivo binario codificado:    ";for(int i=0;i<k;i++) cout<<*(codificado+i);
    cout<<endl;

}

void deco_metodo1(int semilla){
    string codificado;
    string decodificado;
    string bloques, nombre;
    int longitud=0,pos=0,contador=0,cantid_ceros=0,cantid_unos=0,i=0;
    string prueba="../practica3parte1/BD/";
    string auxprueba=prueba;
    string nombresalida;

    cout<<"ingrese el nombre del archivo codificado: ";
    cin>>nombre;
    prueba+=nombre;
    ifstream leer;
    leer.open(prueba);
    if(leer.is_open()){
        getline(leer,codificado);
    }
    else {
        cout<<"el archivo no existe"<<endl;
        }
   leer.close();
   longitud=codificado.length();
   for(int k=0;k<semilla;k++){
       if(codificado[k]=='0'){
            decodificado+='1';
       }
       else {                       //codificamos el primer bloque de bits
            decodificado+='0';
       }

   }
   pos=semilla;
    for(i=0; i<longitud/semilla;i++){
        for (int i=contador;i<semilla+contador;i++){
                    if(decodificado[i]=='0')
                        cantid_ceros++;
                    else
                        cantid_unos++;
                }
       bloques=codificado.substr(pos,semilla);
       for(int j=0; j<semilla;j++){
           if(cantid_ceros==cantid_unos){ //-----------------******-----------------
               if(bloques[j]=='0'){
                   bloques[j]='1';
               }
               else {                                    //ceros igual a unos
                   bloques[j]='0';
               }
           }
           if(cantid_ceros>cantid_unos){  //-----------------******-----------------
               if((j+1)%2==0){
                   if(bloques[j]=='0'){
                       bloques[j]='1';
                   }
                   else {
                       bloques[j]='0';          //cros mayor que unos
                   }
               }
            }                                      //-----------------******-----------------
           if(cantid_ceros<cantid_unos){
               if((j+1)%3==0){
                   if(bloques[j]=='0'){
                       bloques[j]='1';
                   }
                   else {
                       bloques[j]='0';          //cros menor que unos
                   }
               }
            }                                      //-----------------******-----------------
       }
       decodificado+=bloques;    //guardamos los bits codificados
       pos=pos+semilla;
       contador+=semilla;
       cantid_unos=0;
       cantid_ceros=0;
   }
    //Vamos a cambiar de binario a ascii

    string texto=decodificado;//Creo otro string donde se guardara los caracteres
    int size=longitud;
    for (int i=0,a=0;i<size;i=i+8,a++) {
        bloques=decodificado.substr(i,8);
        int expdos=1,sum=0;
        for (int e=7;e>=0;e--) {
            if(bloques[e]=='1'){
                sum=sum+expdos;
            }
            expdos=expdos*2;
        }
        texto[a]=sum;
    }

    texto.resize(size/8);//Redefinimos el tamaño del texto donde me quede solo los caracteres ya que hay size/8 caracteres
    //prueba+="decodificado.txt";
    cout<<"ingrese nombre del archivo de salida"<<endl;
    cin>>nombresalida;
    auxprueba+=nombresalida;
    ofstream escribir;//Enviamos lo decodificado al archivo fuente2.txt
    escribir.open(auxprueba);
    escribir<<texto;
    escribir.close();
}


void deco_metodo2(int semilla){
    string codificado;
    string bloques, nombre,nombresalida;
    string prueba="../practica3parte1/BD/";
    string auxprueba=prueba;
    cout<<"ingrese el nombre del archivo codificado: ";
    cin>>nombre;
    prueba+=nombre;
    ifstream leer;
    leer.open(prueba);
    if(leer.is_open()){
        getline(leer,codificado);
    }
    else {
        cout<<"el archivo no existe"<<endl;
        }
   leer.close();

   string decodificado=codificado;
   int size=codificado.length();
   char chartem;

   for (int i=0;i<=size-semilla;i=i+semilla) {
       bloques=codificado.substr(i,semilla);//Extrae del string codificado los #semilla primeros caracteres desde la posicion i
       for (int b=0;b < semilla-1;b++){//El primer valor del bloque queda al final y los otros se corren a la izquierda
           chartem=bloques[b];
           bloques[b]=bloques[b+1];
           bloques[b+1]=chartem;
       }
       for (int b=i,c=0;b < i+semilla;c++,b++) {
           decodificado[b]=bloques[c];
       }
   }

   //Vamos a cambiar de binario a ascii

   string texto=decodificado;//Creo otro string donde se guardara los caracteres

   for (int i=0,a=0;i<size;i=i+8,a++) {
       bloques=decodificado.substr(i,8);
       int expdos=1,sum=0;
       for (int e=7;e>=0;e--) {
           if(bloques[e]=='1'){
               sum=sum+expdos;
           }
           expdos=expdos*2;
       }
       texto[a]=sum;
   }

   texto.resize(size/8);//Redefinimos el tamaño del texto donde me quede solo los caracteres ya que hay size/8 caracteres
   cout<<"ingrese nombre del archivo de salida"<<endl;
   cin>>nombresalida;
   auxprueba+=nombresalida;
   ofstream escribir;//Enviamos lo decodificado al archivo fuente2.txt
   //prueba+="decodificado.txt";
   escribir.open(auxprueba);
   escribir<<texto;
   escribir.close();

}
