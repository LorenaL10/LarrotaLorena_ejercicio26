#include <iostream>
#include <cmath>
#include <stdlib.h>

using std::cout;
using std::endl;
using std::cin;

/**Funciones para realizar el primer punto*/
void relleno(int l,float *a);
void imprimecabezas(int l,float *a);
void imprime(int l,float *a);

int main(){
/**pido un numero al usuario*/ 
cout<<"Escriba un numero del 3 al 11"<<endl;

int num;
cin>>num;
 
/**Declaro un arreglo de 1D*/
float *arreglo;
arreglo = new float [num];

if(num>=3 && num<=11){
    relleno(num,arreglo);

imprime(num,arreglo);

}


else{cout<<"El numero no esta en el rango valido"<<endl;
    }

return 0;

}


/**función que rellena el arreglo, usando como parámetros el tamaño del arreglo y el arreglo*/
void relleno(int l, float *a){
    int i;
    int fact;
    /**rellena el arreglo con el numero factorial del índice*/
    for(i=0; i<l; i++){
        /**relleno las dos primeras posiciones del arreglo con 0! y 1!*/
        if(i==0 || i==1){
            a[i]=1;
        }
        /**rellena el resto de posiciones usando el índice actual por el índice anterior*/
        else{
            fact=i*(i-1);
            a[i]+=fact;
        }
    }
}

/**Imprime el arreglo en pantalla*/
void imprime(int l,float *a){

for ( int i=0; i <l;i++) {

cout<<" "<<a[i]<<" ";

}

cout<<endl;

}

