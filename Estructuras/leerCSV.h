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