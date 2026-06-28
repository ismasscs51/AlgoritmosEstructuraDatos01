#pragma once

template <typename T>
class Cola {
private:
    struct Nodo {
        T dato;
        Nodo* siguiente;

        Nodo(T dato) {
            this->dato = dato;
            this->siguiente = nullptr;
        }
    };

    Nodo* frente;
    Nodo* final;
    int cantidad;

public:
    Cola() {
        frente = nullptr;
        final = nullptr;
        cantidad = 0;
    }

    ~Cola() {
        limpiar();
    }

    void encolar(T dato) {
        Nodo* nuevo = new Nodo(dato);

        if (frente == nullptr) {
            frente = nuevo;
            final = nuevo;
        }
        else {
            final->siguiente = nuevo;
            final = nuevo;
        }

        cantidad++;
    }

    T desencolar() {
        if (frente == nullptr) {
            return T();
        }

        Nodo* temp = frente;
        T dato = temp->dato;

        frente = frente->siguiente;

        if (frente == nullptr) {
            final = nullptr;
        }

        delete temp;
        cantidad--;

        return dato;
    }

    bool estaVacia() {
        return frente == nullptr;
    }

    int getCantidad() {
        return cantidad;
    }

    void limpiar() {
        while (frente != nullptr) {
            Nodo* temp = frente;
            frente = frente->siguiente;
            delete temp;
        }

        final = nullptr;
        cantidad = 0;
    }
};