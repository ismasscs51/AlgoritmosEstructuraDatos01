#pragma once
#include <string>
using namespace std;

class Usuario {
private:
    int id;
    string nombre;
    string correo;
    string clave;
    int puntos;

public:
    Usuario() {
        this->id = 0;
        this->nombre = "";
        this->correo = "";
        this->clave = "";
        this->puntos = 0;
    }

    Usuario(int id, string nombre, string correo, string clave) {
        this->id = id;
        this->nombre = nombre;
        this->correo = correo;
        this->clave = clave;
        this->puntos = 0;
    }

    int getId() {
        return id;
    }

    string getNombre() {
        return nombre;
    }

    string getCorreo() {
        return correo;
    }

    string getClave() {
        return clave;
    }

    int getPuntos() {
        return puntos;
    }

    void setNombre(string nombre) {
        this->nombre = nombre;
    }

    void setCorreo(string correo) {
        this->correo = correo;
    }

    void setClave(string clave) {
        this->clave = clave;
    }

    bool validarClave(string claveIngresada) {
        return this->clave == claveIngresada;
    }

    void sumarPuntos(int puntosGanados) {
        this->puntos += puntosGanados;
    }

    string mostrarDatos() {
        return "ID: " + to_string(id) +
            "\nNombre: " + nombre +
            "\nCorreo: " + correo +
            "\nPuntos: " + to_string(puntos);
    }
};