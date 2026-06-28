#pragma once
#include <functional>
using namespace std;

template <typename T>
class Grafo {
private:
    T* vertices;
    bool** matrizAdyacencia;
    int cantidad;
    int capacidad;

    void recorrerDFSRecursivo(int indice, bool* visitado, function<void(T)> accion) {
        if (indice < 0 || indice >= cantidad) {
            return;
        }

        if (visitado[indice]) {
            return;
        }

        visitado[indice] = true;
        accion(vertices[indice]);

        for (int i = 0; i < cantidad; i++) {
            if (matrizAdyacencia[indice][i] == true && visitado[i] == false) {
                recorrerDFSRecursivo(i, visitado, accion);
            }
        }
    }

public:
    Grafo(int capacidad = 20) {
        this->capacidad = capacidad;
        this->cantidad = 0;

        vertices = new T[capacidad];

        matrizAdyacencia = new bool* [capacidad];

        for (int i = 0; i < capacidad; i++) {
            matrizAdyacencia[i] = new bool[capacidad];

            for (int j = 0; j < capacidad; j++) {
                matrizAdyacencia[i][j] = false;
            }
        }
    }

    ~Grafo() {
        for (int i = 0; i < capacidad; i++) {
            delete[] matrizAdyacencia[i];
        }

        delete[] matrizAdyacencia;
        delete[] vertices;
    }

    int agregarVertice(T dato) {
        if (cantidad >= capacidad) {
            return -1;
        }

        vertices[cantidad] = dato;
        cantidad++;

        return cantidad - 1;
    }

    void agregarArista(int origen, int destino) {
        if (origen >= 0 && origen < cantidad && destino >= 0 && destino < cantidad) {
            matrizAdyacencia[origen][destino] = true;
        }
    }

    bool existeArista(int origen, int destino) {
        if (origen >= 0 && origen < cantidad && destino >= 0 && destino < cantidad) {
            return matrizAdyacencia[origen][destino];
        }

        return false;
    }

    void recorrerDFS(int inicio, function<void(T)> accion) {
        bool* visitado = new bool[cantidad];

        for (int i = 0; i < cantidad; i++) {
            visitado[i] = false;
        }

        recorrerDFSRecursivo(inicio, visitado, accion);

        delete[] visitado;
    }

    int getCantidad() {
        return cantidad;
    }

    void limpiar() {
        cantidad = 0;

        for (int i = 0; i < capacidad; i++) {
            for (int j = 0; j < capacidad; j++) {
                matrizAdyacencia[i][j] = false;
            }
        }
    }
};