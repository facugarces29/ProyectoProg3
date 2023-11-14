#include<vector>
#include<fstream>
#include<sstream>
#include<string>
#include<iostream>
#include<algorithm>
#include<set>

using namespace std;

vector<vector<string>> leerArchivoCSV(const string& nombreArchivo) {
    vector<vector<string>> datos;

    ifstream archivo(nombreArchivo);
    if (!archivo.is_open()) {
        cerr << "Error al abrir el archivo." <<endl;
        return datos;
    }

    string linea, valor;        
    getline(archivo, linea); // Ignorar la primera línea

    while (getline(archivo, linea)) {
        // Reemplazar '/' y '-' en la línea
        replace(linea.begin(), linea.end(), '/', ' ');
        replace(linea.begin(), linea.end(), '-', ' ');
        replace(linea.begin(), linea.end(), '.',' ');

        // Verificar si la línea contiene la palabra "error"
        if (linea.find("error"||"ERROR") != string::npos) {
            continue; // Si contiene "error", se salta la línea
        }

        vector<string> fila;
        stringstream ss(linea);

        while (getline(ss, valor, ',')) {
            // Reemplazar celdas vacías con "null"
            if (valor.empty()) {
                valor = "null";
            }
            fila.push_back(valor);
        }

        datos.push_back(fila);
    }

    archivo.close();
    return datos;
}

//Funcion para validar los enteros
bool esEnteroValido(const std::string& str) {
    for (char c : str) {
        if (!std::isdigit(c)) {
            return false;
        }
    }
    return true;
}
//cConvierte los string al int
int convertir_a_entero(const string& str) {
    try {
        return stoi(str);
    } catch (const invalid_argument& e) {
        cerr << "Error al convertir a entero: " << e.what() << endl;
    } catch (const out_of_range& e) {
        cerr << "Error: Desbordamiento de rango. " << e.what() << endl;
    }
    return -1;
};

//Funcion para poder chequear los datos del .csv
void mostrarDatosCSV(const vector<vector<string>>& datos) {
    for (const vector<string>& fila : datos) {
        for (const string& valor : fila) {
            cout << valor << ",";
        }
        cout << endl;
    }
}

//Muestra la cantidad de articulos totales
//-total_art
int cantidadTotalArticulos(const vector<vector<string>>& datos) {
    int total = 0;
    for (const vector<string>& fila : datos) {
        if (fila.size() >= 5) { 
            for (int i = 3; i <= 7; ++i) {
                if (!fila[i].empty() && esEnteroValido(fila[i])) { 
                    int stock = convertir_a_entero(fila[i]); 
                    if (stock != -1) {
                        total += stock;
                    }
                }
            }
        } else {
            cerr << "Fila incompleta, no se pudo contar el stock." << endl;
        }
    }
    return total;
}

//Muestra la cantidad Diferentes de articulos
//-total_art_dif
int cantidadTotalArticulosDiferentes(const vector<vector<string>>& datos) {
    set<string> codigosBarras;

    for (const vector<string>& fila : datos) {
        if (fila.size() >= 3) { // Verificar que haya al menos 3 elementos en la fila (para obtener el código de barras)
            string codigoBarras = fila[1]; // Suponiendo que la columna del código de barras es la segunda (índice 1)
            codigosBarras.insert(codigoBarras);
        }
    }

    return codigosBarras.size();
};
