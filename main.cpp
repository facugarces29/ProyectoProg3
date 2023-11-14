#include <iostream>
#include "Estructuras/ProcesadorArgumentos.h" //Procesa los argumentos por consolo  
using namespace std;


int main(int argc, char* argv[]) {
    /*clock_t begin;
    cout<< "Comenzando a medir tiempo"<<endl;
    begin = clock();
    */
    string nombreArchivo = "CSV/Inventariado_Fisico.csv";
    vector<vector<string>> datos = leerArchivoCSV(nombreArchivo);
    procesarArgumentos(argc, argv, datos);
    
    /*clock_t end = clock();

    double time = (double(end - begin) / CLOCKS_PER_SEC);

    cout << " Tiempo de ejecucion: " << time << endl;
    */
    return 0;

}