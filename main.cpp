#include <iostream>
#include "Estructuras/ArbolAVL.h"

#include "Estructuras/leerCSV.h" //Lee Archivo CSV y Muestra CantArtTotal o CantArtTotalDif
#include "Estructuras/stock.h"
using namespace std;


int main(){
    string nombre_archivo = "CSV/prueba.csv";
    vector<vector<string>> datos = leerArchivoCSV(nombre_archivo);
   
    Lista<Producto> listaProductos;
    int n,deposito;
    // Llenar la lista de productos con los datos del archivo CSV
    for (const vector<string>& fila : datos) {
        if (fila.size() >= 8) {  // Asegúrate de que haya al menos 8 elementos en la fila
            Producto producto;
            producto.grupo = fila[0];
            producto.codigoBarras = fila[1];
            producto.nombre = fila[2];

            // Llenar el vector de depósitos
            for (int i = 3; i <= 7; ++i) {
                if (esEnteroValido(fila[i])) {
                    int stock = convertir_a_entero(fila[i]);
                    if (stock != -1) {
                        producto.depositos.push_back(stock);
                    }
                }
            }

            listaProductos.insertarUltimo(producto);
        }
    }

    /*cout << "Ingrese el valor n: " << endl;
    cin >> n;
    cout << "Ingrese el valor deposito: " << endl;
    cin >> deposito;
    // Procesar argumentos
    //procesarArgumentos(argc, argv, datos);
    //Funcion para comprobar los datos del archivo.csv  
    //mostrarDatosCSV(datos);
    
    //Funcion 
    //MinStock(listaProductos, n);
    
    //Funciona
    //listarArticulosMaxStock(listaProductos,n);
    
    //Funciona
    listarArticulosMinimoStockDeposito(listaProductos,n,deposito);

    return 0;
*/


















   /*
    int opcion;
    int cantTotalArt = cantidadTotalArticulos(datos);
    int cantTotalArtDif = cantidadTotalArticulosDiferentes(datos);
   
    do {
        // Mostrar el menú
        cout << "Procesador De Inventario:" << endl;
        cout << "1. Mostrar Datos" << endl;
        cout << "2. Cantidad Total" << endl;
        cout << "3. Cantidad Total Diferente" << endl;
        cout << "4. Stock Minino Productos [n]" << endl;
        cout << "5. Stock Minino Productos Depositos [n],[deposito]" << endl;
        cout << "6. Stock Productos [nombre]" << endl;
        cout << "7. Stock Minino Productos Depositos [nombre],[deposito]" << endl;
        cout << "8. Stock Maximo Productos [n]" << endl;
        cout << "9. Salir" << endl;
        cout << "Ingrese su eleccion (1-9): ";
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
                cout << "Ha seleccionado la Opción 4." << endl;
                break;
            case 5:
                cout << "Saliendo del programa. ¡Hasta luego!" << endl;
                cout << endl;
                break;
            case 6:
                cout << "Saliendo del programa. ¡Hasta luego!" << endl;
                cout << endl;
                break;
            case 7:
                cout << "Saliendo del programa. ¡Hasta luego!" << endl;
                cout << endl;
                break;
            case 8:
                cout << "Saliendo del programa. ¡Hasta luego!" << endl;
                cout << endl;
                break;                      
            case 9:
                cout << "Saliendo del programa. ¡Hasta luego!" << endl;
                cout << endl;
                break;    
            default:
                cout << "Opción no válida. Por favor, ingrese un número del 1 al 9." << endl;
        }
    } while (opcion != 9);

    return 0;*/
}
