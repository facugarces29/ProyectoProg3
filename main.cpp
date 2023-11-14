#include <iostream>
#include "Estructuras/ArbolAVL.h"
#include "Estructuras/Articulo.h"
#include "Estructuras/leerCSV.h"
#include "Estructuras/minmaxstock.h"

using namespace std;

int main(){
    string nombre_archivo = "CSV/prueba.csv";
    vector<vector<string>> datos = leerArchivoCSV(nombre_archivo);

    mostrarDatosCSV(datos);
    return 0;
}
