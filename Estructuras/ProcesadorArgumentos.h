#include <iostream>
#include "leerCSV.h" //Lee Archivo CSV y Muestra CantArtTotal o CantArtTotalDif
#include "stock.h" //Resto de funciones MinStock, stock, maxstock, y su respectivo 

using namespace std;
//procesa los argumentos que son ingresados por consola y los redirije hacia la funcion que sea solicitada
void procesarArgumentos(int argc, char* argv[], const vector<vector<string>>& datos) {
    if (argc < 3) {
        cerr << "Uso: " << argv[0] << " [Argumentos] Inventariado_Fisico.csv" << endl;
        return;
    }

    Lista<Producto> listaProductos;
    int n, deposito;
    string nombreArticuloBuscado;
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
    string operacion = argv[1];
    string archivoCSV = argv[2];

     if (operacion == "-total_art_dif") {
        int cantDif = cantidadTotalArticulosDiferentes(datos);
        cout << "Cantidad Total de Articulos Diferentes: "<< cantDif<< endl;
    } 
    else if (operacion == "-total_art") {
    
        int cantTotal = cantidadTotalArticulos(datos);
        cout << "Cantidad Total de Articulos: "<< cantTotal<< endl;
    
    } 
    else if (operacion == "-MinStock") {
    
        cout<<"ingrese cantidad de producto"<<endl;
        cin>> n;
        MinStock(listaProductos,n);
    
    } 
    else if (operacion == "-listarArticulosMinimoStockDeposito") {
    
        cout<<"ingrese cantidad de producto"<<endl;
        cin>> n;
        cout<<"ingrese deposito"<<endl;
        cin>>deposito;
        listarArticulosMinimoStockDeposito(listaProductos,n,deposito);
    
    }
    else if (operacion == "-stockArticulo") {
    
        cout << "Ingrese Nombre del articulo"<< endl;
        cin >> nombreArticuloBuscado;
        int SA = stockArticulo(listaProductos, nombreArticuloBuscado);
        cout << "Stock Total "<< SA << endl;
    
    }
    else if (operacion == "-stockArticuloDeposito") {
    
        cout << "Ingrese Nombre del articulo"<< endl;
        cin >> nombreArticuloBuscado;
        cout << "ingrese numero de deposito"<<endl;
        cin >> deposito;
        int SAP = stockArticuloDeposito(listaProductos, nombreArticuloBuscado, deposito);
        cout << " "<<nombreArticuloBuscado<<" en el deposito "<<deposito<<" :"<< SAP<< endl;
    
    }
    else if (operacion == "-listarArticulosMaxStock") {
    
        cout<<"ingrese cantidad de producto"<<endl;
        cin>> n;
        listarArticulosMaxStock(listaProductos,n);
    } 
    else {
     
        cerr << "Operación no válida." << endl;
        
    }
}

