#include <iostream>
#include "Estructuras/ArbolAVL.h"
#include "Estructuras/Articulo.h"
#include "Estructuras/leerCSV.h" //Lee Archivo CSV y Muestra CantArtTotal o CantArtTotalDif
#include "Estructuras/minmaxstock.h"
using namespace std;


int main(){
    string nombre_archivo = "CSV/prueba.csv";
    vector<vector<string>> datos = leerArchivoCSV(nombre_archivo);

    int opcion;
    int cantTotalArt = cantidadTotalArticulos(datos);
    int cantTotalArtDif = cantidadTotalArticulosDiferentes(datos);
    do {
        // Mostrar el menú
        cout << "Menu:" << endl;
        cout << "1. Mostrar Datos" << endl;
        cout << "2. Cantidad Total" << endl;
        cout << "3. Cantidad Total Diferente" << endl;
        cout << "4. Salir" << endl;
        cout << "Ingrese su eleccion (1-4): ";
        cin >> opcion;
        cout << endl;

        // Procesar la elección del usuario
        switch (opcion) {
            case 1:
                cout << endl;
                mostrarDatosCSV(datos);
                cout << endl;
                break;
            case 2:
                cout << endl;
                cout<<"Cantidad total articulos "<< cantTotalArt << endl;
                cout << endl;
                break;
            case 3:
                cout << endl;
                cout<<"Cantidad total Articulos diferente "<< cantTotalArtDif << endl;
                cout << endl;
                break;
            case 4:
                cout << "Saliendo del programa. ¡Hasta luego!" << endl;
                cout << endl;
                break;
            default:
                cout << "Opción no válida. Por favor, ingrese un número del 1 al 4." << endl;
        }
    } while (opcion != 4);

    return 0;
}
