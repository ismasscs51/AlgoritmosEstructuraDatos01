#pragma once
#include <string>
using namespace std;

class Leccion {
private:
    int id;
    string nombre;
    string descripcion;
    bool desbloqueada;

public:
    Leccion() {
        id = 0;
        nombre = "";
        descripcion = "";
        desbloqueada = false;
    }

    Leccion(int id, string nombre, string descripcion, bool desbloqueada) {
        this->id = id;
        this->nombre = nombre;
        this->descripcion = descripcion;
        this->desbloqueada = desbloqueada;
    }

    int getId() {
        return id;
    }

    string getNombre() {
        return nombre;
    }

    string getDescripcion() {
        return descripcion;
    }

    bool estaDesbloqueada() {
        return desbloqueada;
    }

    string mostrarLeccion() {
        string texto = "";

        texto += nombre + "\n";
        texto += descripcion + "\n";

        if (desbloqueada) {
            texto += "Estado: Disponible\n";
        }
        else {
            texto += "Estado: Bloqueada\n";
        }

        return texto;
    }
};