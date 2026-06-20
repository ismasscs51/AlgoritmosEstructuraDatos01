#pragma once
#include <string>
#include "Usuario.h"
#include "ListaEnlazada.h"
using namespace std;

class Duolingo {
private:
    ListaEnlazada<Usuario> usuarios;
    Usuario* usuarioActual;
    int contadorUsuarios;

public:
    Duolingo() {
        usuarioActual = nullptr;
        contadorUsuarios = 1;
    }

    bool registrarUsuario(string nombre, string correo, string clave) {
        Usuario* encontrado = usuarios.buscar([correo](Usuario usuario) {
            return usuario.getCorreo() == correo;
            });

        if (encontrado != nullptr) {
            return false;
        }

        Usuario nuevoUsuario(contadorUsuarios, nombre, correo, clave);
        usuarios.insertar(nuevoUsuario);
        contadorUsuarios++;

        return true;
    }

    bool iniciarSesion(string correo, string clave) {
        Usuario* encontrado = usuarios.buscar([correo](Usuario usuario) {
            return usuario.getCorreo() == correo;
            });

        if (encontrado != nullptr && encontrado->validarClave(clave)) {
            usuarioActual = encontrado;
            return true;
        }

        return false;
    }

    void cerrarSesion() {
        usuarioActual = nullptr;
    }

    Usuario* getUsuarioActual() {
        return usuarioActual;
    }

    string listarUsuarios() {
        string resultado = "";

        usuarios.recorrer([&resultado](Usuario usuario) {
            resultado += usuario.mostrarDatos();
            resultado += "\n----------------------\n";
            });

        if (resultado == "") {
            resultado = "No hay usuarios registrados.";
        }

        return resultado;
    }
};