#pragma once
#include <string>
using namespace std;

template <typename T>
class HashTable {
private:
    struct Nodo {
        string clave;
        T valor;
        Nodo* siguiente;

        Nodo(string clave, T valor) {
            this->clave = clave;
            this->valor = valor;
            this->siguiente = nullptr;
        }
    };

    Nodo** tabla;
    int tamanio;
    int cantidad;

    int funcionHash(string clave) {
        unsigned long hash = 7;

        for (int i = 0; i < clave.length(); i++) {
            int ascii = (int)clave[i];

            hash = hash * 31 + ascii * (i + 1);
            hash = hash ^ (hash >> 13);
            hash = hash + (hash << 7);
        }

        return hash % tamanio;
    }

public:
    HashTable() {
        tamanio = 101;
        cantidad = 0;

        tabla = new Nodo * [tamanio];

        for (int i = 0; i < tamanio; i++) {
            tabla[i] = nullptr;
        }
    }

    ~HashTable() {
        limpiar();
        delete[] tabla;
    }

    void insertar(string clave, T valor) {
        int indice = funcionHash(clave);

        Nodo* actual = tabla[indice];

        while (actual != nullptr) {
            if (actual->clave == clave) {
                actual->valor = valor;
                return;
            }

            actual = actual->siguiente;
        }

        Nodo* nuevo = new Nodo(clave, valor);
        nuevo->siguiente = tabla[indice];
        tabla[indice] = nuevo;

        cantidad++;
    }

    T obtener(string clave) {
        int indice = funcionHash(clave);

        Nodo* actual = tabla[indice];

        while (actual != nullptr) {
            if (actual->clave == clave) {
                return actual->valor;
            }

            actual = actual->siguiente;
        }

        return T();
    }

    bool existe(string clave) {
        int indice = funcionHash(clave);

        Nodo* actual = tabla[indice];

        while (actual != nullptr) {
            if (actual->clave == clave) {
                return true;
            }

            actual = actual->siguiente;
        }

        return false;
    }

    int getCantidad() {
        return cantidad;
    }

    int getTamanio() {
        return tamanio;
    }

    void limpiar() {
        for (int i = 0; i < tamanio; i++) {
            Nodo* actual = tabla[i];

            while (actual != nullptr) {
                Nodo* temp = actual;
                actual = actual->siguiente;
                delete temp;
            }

            tabla[i] = nullptr;
        }

        cantidad = 0;
    }
};