#include <fstream>
#include <iostream>
#include <string.h>
#include <cmath>
using namespace std; 

float * read_file(string filename, int *n_points);
void multiplicacion(float *x, float *y, int n_points);

int main(){
  float *x=NULL;
  float *y=NULL;
  int n_x=0;
  int n_y=0;

  x = read_file("valores_x.txt", &n_x);
  y = read_file("valores_y.txt", &n_y);
  
  multiplicacion(x, y, n_x);
  
  return 0;
}

float * read_file(string filename, int *n_points){
  int n_lines=0;
  ifstream infile; 
  string line;
  int i;
  float *array;

  /*cuenta lineas*/
  infile.open(filename); 
  getline(infile, line);
  while(infile){
    n_lines++;
    getline(infile, line);
  }
  infile.close();
  *n_points = n_lines;

  /*reserva la memoria necesaria*/
  array = new float[n_lines];

  /*carga los valores*/
  i=0;
  infile.open(filename); 
  getline(infile, line);  
  while(infile){
    array[i] = atof(line.c_str());
    i++;
    getline(infile, line);
  }
  infile.close();

  return array;
}

void multiplicacion(float *x, float *y, int n_points){
  int i;
  float a;
    ofstream outfile;
    /**Creo el archivo multiplicacion.dat*/
    outfile.open("multiplicacion.dat");

  /*Realizo el producto entre los dos arreglos*/
  for(i=0;i<n_points;i++){
      /*Multiplico las filas de los datos x, y*/
      a=x[i]*y[i];
      /*Guardo el resultado en el archivo .dat*/
      outfile << a<<endl;
  }   
    outfile.close();
}
