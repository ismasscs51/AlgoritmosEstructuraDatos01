#pragma once
#include <functional>
using namespace std;

template <typename T>
class AVL {
private:
    struct Nodo {
        int clave;
        T dato;
        Nodo* izquierda;
        Nodo* derecha;
        int altura;

        Nodo(int clave, T dato) {
            this->clave = clave;
            this->dato = dato;
            this->izquierda = nullptr;
            this->derecha = nullptr;
            this->altura = 1;
        }
    };

    Nodo* raiz;
    int cantidad;

    int obtenerAltura(Nodo* nodo) {
        if (nodo == nullptr) {
            return 0;
        }

        return nodo->altura;
    }

    int mayor(int a, int b) {
        if (a > b) {
            return a;
        }

        return b;
    }

    int obtenerBalance(Nodo* nodo) {
        if (nodo == nullptr) {
            return 0;
        }

        return obtenerAltura(nodo->izquierda) - obtenerAltura(nodo->derecha);
    }

    Nodo* rotarDerecha(Nodo* y) {
        Nodo* x = y->izquierda;
        Nodo* temp = x->derecha;

        x->derecha = y;
        y->izquierda = temp;

        y->altura = mayor(obtenerAltura(y->izquierda), obtenerAltura(y->derecha)) + 1;
        x->altura = mayor(obtenerAltura(x->izquierda), obtenerAltura(x->derecha)) + 1;

        return x;
    }

    Nodo* rotarIzquierda(Nodo* x) {
        Nodo* y = x->derecha;
        Nodo* temp = y->izquierda;

        y->izquierda = x;
        x->derecha = temp;

        x->altura = mayor(obtenerAltura(x->izquierda), obtenerAltura(x->derecha)) + 1;
        y->altura = mayor(obtenerAltura(y->izquierda), obtenerAltura(y->derecha)) + 1;

        return y;
    }

    Nodo* insertarRecursivo(Nodo* nodo, int clave, T dato) {
        if (nodo == nullptr) {
            cantidad++;
            return new Nodo(clave, dato);
        }

        if (clave < nodo->clave) {
            nodo->izquierda = insertarRecursivo(nodo->izquierda, clave, dato);
        }
        else if (clave > nodo->clave) {
            nodo->derecha = insertarRecursivo(nodo->derecha, clave, dato);
        }
        else {
            nodo->dato = dato;
            return nodo;
        }

        nodo->altura = 1 + mayor(obtenerAltura(nodo->izquierda), obtenerAltura(nodo->derecha));

        int balance = obtenerBalance(nodo);

        if (balance > 1 && clave < nodo->izquierda->clave) {
            return rotarDerecha(nodo);
        }

        if (balance < -1 && clave > nodo->derecha->clave) {
            return rotarIzquierda(nodo);
        }

        if (balance > 1 && clave > nodo->izquierda->clave) {
            nodo->izquierda = rotarIzquierda(nodo->izquierda);
            return rotarDerecha(nodo);
        }

        if (balance < -1 && clave < nodo->derecha->clave) {
            nodo->derecha = rotarDerecha(nodo->derecha);
            return rotarIzquierda(nodo);
        }

        return nodo;
    }

    void recorrerDescendenteRecursivo(Nodo* nodo, function<void(T)> accion) {
        if (nodo != nullptr) {
            recorrerDescendenteRecursivo(nodo->derecha, accion);
            accion(nodo->dato);
            recorrerDescendenteRecursivo(nodo->izquierda, accion);
        }
    }

    void recorrerAscendenteRecursivo(Nodo* nodo, function<void(T)> accion) {
        if (nodo != nullptr) {
            recorrerAscendenteRecursivo(nodo->izquierda, accion);
            accion(nodo->dato);
            recorrerAscendenteRecursivo(nodo->derecha, accion);
        }
    }

    void limpiarRecursivo(Nodo* nodo) {
        if (nodo != nullptr) {
            limpiarRecursivo(nodo->izquierda);
            limpiarRecursivo(nodo->derecha);
            delete nodo;
        }
    }

public:
    AVL() {
        raiz = nullptr;
        cantidad = 0;
    }

    ~AVL() {
        limpiar();
    }

    void insertar(int clave, T dato) {
        raiz = insertarRecursivo(raiz, clave, dato);
    }

    void recorrerDescendente(function<void(T)> accion) {
        recorrerDescendenteRecursivo(raiz, accion);
    }

    void recorrerAscendente(function<void(T)> accion) {
        recorrerAscendenteRecursivo(raiz, accion);
    }

    bool estaVacio() {
        return raiz == nullptr;
    }

    int getCantidad() {
        return cantidad;
    }

    void limpiar() {
        limpiarRecursivo(raiz);
        raiz = nullptr;
        cantidad = 0;
    }
};