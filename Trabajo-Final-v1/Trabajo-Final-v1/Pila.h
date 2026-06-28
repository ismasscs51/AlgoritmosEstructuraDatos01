#pragma once
#include <functional> // Permite usar lambdas en recorrer()

using namespace std;

template <typename T>
class Pila {
private:
    struct Nodo {
        T dato;
        Nodo* siguiente;

        Nodo(T dato) {
            this->dato = dato;
            this->siguiente = nullptr;
        }
    };

    Nodo* cima;
    int cantidad;

public:
    Pila() {
        cima = nullptr;
        cantidad = 0;
    }

    ~Pila() {
        limpiar();
    }

    void apilar(T dato) {
        Nodo* nuevo = new Nodo(dato);
        nuevo->siguiente = cima;
        cima = nuevo;
        cantidad++;
    }

    T desapilar() {
        if (cima == nullptr) {
            return T();
        }

        Nodo* temp = cima;
        T dato = temp->dato;

        cima = cima->siguiente;

        delete temp;
        cantidad--;

        return dato;
    }

    T verCima() {
        if (cima == nullptr) {
            return T();
        }

        return cima->dato;
    }

    bool estaVacia() {
        return cima == nullptr;
    }

    int getCantidad() {
        return cantidad;
    }

    void recorrer(function<void(T)> accion) {
        Nodo* actual = cima;

        while (actual != nullptr) {
            accion(actual->dato);
            actual = actual->siguiente;
        }
    }

    void limpiar() {
        while (cima != nullptr) {
            Nodo* temp = cima;
            cima = cima->siguiente;
            delete temp;
        }

        cantidad = 0;
    }
};