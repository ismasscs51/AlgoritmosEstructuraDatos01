#pragma once
#include <string>
#include "Usuario.h"
#include "ListaEnlazada.h"
#include "Cola.h"
#include "Ejercicio.h"
#include "Pila.h"
#include "Respuesta.h"
#include "HashTable.h"
#include "Arbol.h"
#include "Palabra.h"
using namespace std;

class Duolingo {
private:
    ListaEnlazada<Usuario> usuarios;
    Usuario* usuarioActual;
    int contadorUsuarios;
    Cola<Ejercicio> colaEjercicios;
    Ejercicio ejercicioActual;
    int numeroPregunta;
    int totalPreguntas;
    int correctas;
    int incorrectas;
    Pila<Respuesta> historialRespuestas;
    int contadorRespuestas;
    HashTable<Usuario*> tablaUsuarios;
    AVL<Usuario> rankingUsuarios;
    AVL<Palabra> diccionarioPalabras;

public:
    Duolingo() {
        usuarioActual = nullptr;
        contadorUsuarios = 1;
        numeroPregunta = 0;
        totalPreguntas = 0;
        correctas = 0;
        incorrectas = 0;
        contadorRespuestas = 1;
    }

    bool registrarUsuario(string nombre, string correo, string clave) {
        if (tablaUsuarios.existe(correo)) {
            return false;
        }

        Usuario nuevoUsuario(contadorUsuarios, nombre, correo, clave);

        Usuario* usuarioGuardado = usuarios.insertarYObtener(nuevoUsuario);

        tablaUsuarios.insertar(correo, usuarioGuardado);

        contadorUsuarios++;

        return true;
    }

    bool iniciarSesion(string correo, string clave) {
        Usuario* encontrado = tablaUsuarios.obtener(correo);

        if (encontrado != nullptr && encontrado->validarClave(clave)) {
            usuarioActual = encontrado;
            return true;
        }

        return false;
    }

    void cerrarSesion() {
        usuarioActual = nullptr;
    }

    void iniciarLeccionSaludos() {
        colaEjercicios.limpiar();

        colaEjercicios.encolar(Ejercicio(
            1,
            "Como se dice Hola en ingles?",
            "Hello",
            "Bye",
            "Thanks",
            'A'
        ));

        colaEjercicios.encolar(Ejercicio(
            2,
            "Como se dice Gracias en ingles?",
            "Good night",
            "Thanks",
            "House",
            'B'
        ));

        colaEjercicios.encolar(Ejercicio(
            3,
            "Como se dice Adios en ingles?",
            "Water",
            "Dog",
            "Bye",
            'C'
        ));

        numeroPregunta = 0;
        totalPreguntas = 3;
        correctas = 0;
        incorrectas = 0;

        cargarSiguientePregunta();
    }

    bool cargarSiguientePregunta() {
        if (colaEjercicios.estaVacia()) {
            return false;
        }

        ejercicioActual = colaEjercicios.desencolar();
        numeroPregunta++;

        return true;
    }

    Ejercicio getEjercicioActual() {
        return ejercicioActual;
    }

    int getNumeroPregunta() {
        return numeroPregunta;
    }

    int getTotalPreguntas() {
        return totalPreguntas;
    }

    bool responderEjercicioActual(char respuestaUsuario) {
        bool esCorrecta = ejercicioActual.validarRespuesta(respuestaUsuario);
        int puntosGanados = 0;

        if (esCorrecta) {
            correctas++;
            puntosGanados = 10;

            if (usuarioActual != nullptr) {
                usuarioActual->sumarPuntos(puntosGanados);
            }
        }
        else {
            incorrectas++;
        }

        Respuesta nuevaRespuesta(
            contadorRespuestas,
            ejercicioActual.getPregunta(),
            respuestaUsuario,
            ejercicioActual.getRespuestaCorrecta(),
            esCorrecta,
            puntosGanados
        );

        historialRespuestas.apilar(nuevaRespuesta);
        contadorRespuestas++;

        return esCorrecta;
    }

    bool quedanPreguntas() {
        return !colaEjercicios.estaVacia();
    }

    void reconstruirRankingUsuarios() {
        rankingUsuarios.limpiar();

        usuarios.recorrer([this](Usuario usuario) {
            int claveRanking = usuario.getPuntos() * 10000 + usuario.getId();
            rankingUsuarios.insertar(claveRanking, usuario);
            });
    }

    int generarClavePalabra(string texto) {
        int clave = 0;

        for (int i = 0; i < texto.length(); i++) {
            clave = clave * 31 + (int)texto[i];
        }

        if (clave < 0) {
            clave = clave * -1;
        }

        return clave;
    }

    void cargarDiccionarioPalabras() {
        diccionarioPalabras.limpiar();

        diccionarioPalabras.insertar(generarClavePalabra("Hello"), Palabra("Hello", "Hola", "Saludos"));
        diccionarioPalabras.insertar(generarClavePalabra("Bye"), Palabra("Bye", "Adios", "Saludos"));
        diccionarioPalabras.insertar(generarClavePalabra("Thanks"), Palabra("Thanks", "Gracias", "Saludos"));
        diccionarioPalabras.insertar(generarClavePalabra("Good morning"), Palabra("Good morning", "Buenos dias", "Saludos"));
        diccionarioPalabras.insertar(generarClavePalabra("Good night"), Palabra("Good night", "Buenas noches", "Saludos"));

        diccionarioPalabras.insertar(generarClavePalabra("Water"), Palabra("Water", "Agua", "Basico"));
        diccionarioPalabras.insertar(generarClavePalabra("House"), Palabra("House", "Casa", "Basico"));
        diccionarioPalabras.insertar(generarClavePalabra("Dog"), Palabra("Dog", "Perro", "Animales"));
        diccionarioPalabras.insertar(generarClavePalabra("Cat"), Palabra("Cat", "Gato", "Animales"));
    }

    string obtenerDiccionarioPalabras() {
        cargarDiccionarioPalabras();

        if (diccionarioPalabras.estaVacio()) {
            return "No hay palabras registradas.";
        }

        string resultado = "";

        diccionarioPalabras.recorrerAscendente([&resultado](Palabra palabra) {
            resultado += palabra.mostrarPalabra();
            resultado += "-------------------------\n";
            });

        return resultado;
    }

    string obtenerRankingUsuarios() {
        reconstruirRankingUsuarios();

        if (rankingUsuarios.estaVacio()) {
            return "No hay usuarios registrados.";
        }

        string resultado = "";

        int posicion = 1;

        rankingUsuarios.recorrerDescendente([&resultado, &posicion](Usuario usuario) {
            resultado += to_string(posicion) + ". ";
            resultado += usuario.getNombre();
            resultado += " - ";
            resultado += to_string(usuario.getPuntos());
            resultado += " puntos\n";

            posicion++;
            });

        return resultado;
    }

    string obtenerResumenLeccion() {
        string resumen = "LECCION FINALIZADA\n\n";
        resumen += "Correctas: " + to_string(correctas) + "\n";
        resumen += "Incorrectas: " + to_string(incorrectas) + "\n";
        resumen += "Puntos ganados: " + to_string(correctas * 10) + "\n";

        return resumen;
    }

    Usuario* getUsuarioActual() {
        return usuarioActual;
    }

    string obtenerProgresoActual() {
        if (usuarioActual == nullptr) {
            return "No hay usuario con sesion iniciada.";
        }

        string progreso = "MI PROGRESO\n\n";
        progreso += usuarioActual->mostrarDatos();

        return progreso;
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

    string obtenerHistorialRespuestas() {
        if (historialRespuestas.estaVacia()) {
            return "No hay respuestas registradas.";
        }

        string resultado = "HISTORIAL DE RESPUESTAS\n\n";

        historialRespuestas.recorrer([&resultado](Respuesta respuesta) {
            resultado += respuesta.mostrarRespuesta();
            resultado += "-------------------------\n";
            });

        return resultado;
    }
};