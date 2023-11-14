#ifndef MAXMINSTOCK_H
#define MAXMINSTOCK_H
#include <iostream>
#include <sstream>
#include <fstream>
//#include "Articulo.h"
#include "ArbolAVL.h"
#include "Lista.h"

using namespace std;
struct Producto {
    string grupo;                           // Operadores de comparación para poder ordenar
    string codigoBarras;                    // y comparar productos.
    string nombre;
    vector<int> depositos;
};

void MinStock(const Lista<Producto>& productos, int n) {
    Nodo<Producto>* nodo = productos.getInicio();
    Lista<Producto> productosConMenorStock;

    while (nodo != nullptr) {
        Producto producto = nodo->getDato();
        int stockTotal = 0;

        // Calcular el stock total sumando el stock de todos los depósitos
        for (int stock : producto.depositos) {
            stockTotal += stock;
        }

        // Agregar el producto a la lista si el stock total es menor o igual a n
        if (stockTotal <= n) {
            productosConMenorStock.insertarUltimo(producto);
        }

        nodo = nodo->getSiguiente();
    }

    // Mostrar los productos con stock igual o menor a n
    Nodo<Producto>* nodoResultado = productosConMenorStock.getInicio();
    while (nodoResultado != nullptr) {
        Producto productoResultado = nodoResultado->getDato();
        int stockTotal = 0;  // Declarar stockTotal aquí
        for (int stock : productoResultado.depositos) {
            stockTotal += stock;
        }
        cout << "Nombre: " << productoResultado.nombre << ", Stock total: " << stockTotal << endl;
        nodoResultado = nodoResultado->getSiguiente();
    }
}

void listarArticulosMaxStock(const Lista<Producto>& productos, int maxStock) {
    Nodo<Producto>* nodo = productos.getInicio();

    while (nodo != nullptr) {
        Producto producto = nodo->getDato();
        int stockTotal = 0;

        // Calcular el stock total sumando el stock de todos los depósitos
        for (int stock : producto.depositos) {
            stockTotal += stock;
        }

        // Mostrar el artículo si el stock total es igual o supera maxStock
        if (stockTotal >= maxStock) {
            cout << "Nombre: " << producto.nombre << ", Stock total: " << stockTotal << endl;
        }

        nodo = nodo->getSiguiente();
    }
}


// Función para listar artículos con cantidad n o menos de stock según un depósito y nombre de artículo.
void listarArticulosMinimoStockDeposito(const Lista<Producto>& productos, int n, int depositoDeseado) {
    Nodo<Producto>* nodo = productos.getInicio();

    while (nodo != nullptr) {
        Producto producto = nodo->getDato();
        int cantidadEnDeposito = 0;

        // Verificar si hay suficientes depósitos en el producto
        if (producto.depositos.size() > depositoDeseado) {
            int stockDeposito = producto.depositos[depositoDeseado-1];
            if (stockDeposito == n) {
                cantidadEnDeposito = n;  // Establecer la cantidad si el stock es igual a n
            }
        }

        // Mostrar el producto si la cantidad en el depósito deseado es la requerida
        if (cantidadEnDeposito > 0) {
            cout << "Nombre: " << producto.nombre << ", Stock en depósito " << depositoDeseado << ": " << cantidadEnDeposito << " productos" << endl;
        }

        nodo = nodo->getSiguiente();
    }
}

// Función para obtener el stock total del artículo en la lista
int stockArticulo(const Lista<Producto>& productos, const std::string& nombreArticulo) {
    Nodo<Producto>* nodo = productos.getInicio();
    int stockTotal = 0;

    while (nodo != nullptr) {
        Producto producto = nodo->getDato();
        if (producto.nombre == nombreArticulo) {
            // Sumar el stock de todos los depósitos
            for (int stock : producto.depositos) {
                stockTotal += stock;
            }
        }
        nodo = nodo->getSiguiente();
    }

    return stockTotal;
}

// Función para obtener el stock del artículo en un depósito específico en la lista
int stockArticuloDeposito(const Lista<Producto>& productos, const string& nombreArticulo, int deposito) {
    Nodo<Producto>* nodo = productos.getInicio();
    int stockDeposito = 0;

    while (nodo != nullptr) {
    Producto producto = nodo->getDato();
    //cout << "Nombre del producto: " << producto.nombre << endl;  // Agrega esta línea

    if (producto.nombre == nombreArticulo) {
        if (deposito >= 1 && deposito <= producto.depositos.size()) {
            stockDeposito = producto.depositos[deposito-1];
            //cout << "Encontrado en el depósito " << deposito << ". Stock: " << stockDeposito << endl;  // Agrega esta línea
        }
    }
    nodo = nodo->getSiguiente();
}

    return stockDeposito;
}



#endif //