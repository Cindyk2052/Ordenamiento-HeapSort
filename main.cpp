#include <iostream>
#include <fstream>
using namespace std;

void heapSort(int b[], int n);
ofstream archivo;

int main() {
  string nombre;
  cout << "Ingrese el nombre del archivo: ";
  getline (cin, nombre);
  archivo.open(nombre.c_str (), ios::app);
  archivo << "\t Ordenamiento HeapSort" << endl;
  
  int a[100], n;
  cout << "Ingresa la cantidad de elementos: ";
  cin >> n;
  for (int i = 1; i <= n; i++){
    cin >> a[i];
  }
  archivo <<"\nArreglo antes: ";
  for(int i = 1; i < n; i++){
    archivo << "|" << a[i] << "|";
  }
  heapSort(a, n);
  archivo <<"\nArreglo despues: ";
  for (int i = 1; i <= n; i++){
    cout << " " << a[i];
    archivo << " " << a[i];
  }
  return 0;
}

void heapSort(int b[], int n){
  int valor, temp, a;
  for(int i = n; i > 0; i--){
    for(int j = 1; j <= i; j++){
      valor = b[j];
      a = j / 2;
      while(a > 0 & b[a] < valor){
        b[j] = b[a];
        j = a;
        a = a / 2;
      }
      b[j] = valor;
     }
    temp = b[1];
    b[1] = b[i];
    b[i] = temp;
  }
}