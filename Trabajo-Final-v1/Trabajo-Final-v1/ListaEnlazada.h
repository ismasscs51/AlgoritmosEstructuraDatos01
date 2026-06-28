#pragma once
#include <functional> // permite usar lambdas en buscar y recorrer si no tendiste pues investiga y latias deja de jugar valo

using namespace std;

template <typename T>
class ListaEnlazada {
private:

    struct Nodo {
        T dato;
        Nodo* siguiente;

        Nodo(T dato) {
            this->dato = dato;
            this->siguiente = nullptr;
        }
    };

    Nodo* cabeza;
    int cantidad;

public:

    ListaEnlazada() {
        cabeza = nullptr;
        cantidad = 0;
    }

    ~ListaEnlazada() {
        Nodo* actual = cabeza;

        while (actual != nullptr) {
            Nodo* temp = actual;
            actual = actual->siguiente;
            delete temp;
        }
    }

    void insertar(T dato) {
        Nodo* nuevo = new Nodo(dato);

        if (cabeza == nullptr) {
            cabeza = nuevo;
        }
        else {
            Nodo* actual = cabeza;

            while (actual->siguiente != nullptr) {
                actual = actual->siguiente;
            }

            actual->siguiente = nuevo;
        }

        cantidad++;
    }

    T* insertarYObtener(T dato) {
        Nodo* nuevo = new Nodo(dato);

        if (cabeza == nullptr) {
            cabeza = nuevo;
        }
        else {
            Nodo* actual = cabeza;

            while (actual->siguiente != nullptr) {
                actual = actual->siguiente;
            }

            actual->siguiente = nuevo;
        }

        cantidad++;

        return &(nuevo->dato);
    }

    T* buscar(function<bool(T)> criterio) {
        Nodo* actual = cabeza;

        while (actual != nullptr) {
            if (criterio(actual->dato)) {
                return &(actual->dato);
            }

            actual = actual->siguiente;
        }

        return nullptr;
    }

    void recorrer(function<void(T)> accion) {
        Nodo* actual = cabeza;

        while (actual != nullptr) {
            accion(actual->dato);
            actual = actual->siguiente;
        }
    }

    int getCantidad() {
        return cantidad;
    }

    bool estaVacia() {
        return cabeza == nullptr;
    }
};