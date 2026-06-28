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
#include "Grafos.h"
#include "Leccion.h"
#include "Ordenamientos.h"
#include "DatasetGenerador.h"
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
    Grafo<Leccion> rutaLecciones;
    bool datasetCargado;

public:
    Duolingo() {
        usuarioActual = nullptr;
        datasetCargado = false;
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

    void iniciarLeccionNumeros() {
        colaEjercicios.limpiar();

        colaEjercicios.encolar(Ejercicio(
            1,
            "Como se dice Uno en ingles?",
            "One",
            "Two",
            "Three",
            'A'
        ));

        colaEjercicios.encolar(Ejercicio(
            2,
            "Como se dice Dos en ingles?",
            "Ten",
            "Two",
            "Five",
            'B'
        ));

        colaEjercicios.encolar(Ejercicio(
            3,
            "Como se dice Tres en ingles?",
            "Seven",
            "Four",
            "Three",
            'C'
        ));

        numeroPregunta = 0;
        totalPreguntas = 3;
        correctas = 0;
        incorrectas = 0;

        cargarSiguientePregunta();
    }

    void iniciarLeccionAnimales() {
        colaEjercicios.limpiar();

        colaEjercicios.encolar(Ejercicio(
            1,
            "Como se dice Perro en ingles?",
            "Dog",
            "Cat",
            "Bird",
            'A'
        ));

        colaEjercicios.encolar(Ejercicio(
            2,
            "Como se dice Gato en ingles?",
            "Horse",
            "Cat",
            "Fish",
            'B'
        ));

        colaEjercicios.encolar(Ejercicio(
            3,
            "Como se dice Pajaro en ingles?",
            "Cow",
            "Dog",
            "Bird",
            'C'
        ));

        numeroPregunta = 0;
        totalPreguntas = 3;
        correctas = 0;
        incorrectas = 0;

        cargarSiguientePregunta();
    }

    bool puedeIngresarLeccion(int numeroLeccion) {
        if (usuarioActual == nullptr) {
            return false;
        }

        if (numeroLeccion == 1) {
            return true;
        }

        if (numeroLeccion == 2) {
            return usuarioActual->getPuntos() >= 30;
        }

        if (numeroLeccion == 3) {
            return usuarioActual->getPuntos() >= 60;
        }

        return false;
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

    void cargarRutaLecciones() {
        rutaLecciones.limpiar();

        int puntos = 0;

        if (usuarioActual != nullptr) {
            puntos = usuarioActual->getPuntos();
        }

        bool leccion1 = true;
        bool leccion2 = puntos >= 30;
        bool leccion3 = puntos >= 60;
        bool leccion4 = puntos >= 90;

        int indice1 = rutaLecciones.agregarVertice(
            Leccion(1, "Leccion 1: Saludos", "Aprende Hello, Bye y Thanks.", leccion1)
        );

        int indice2 = rutaLecciones.agregarVertice(
            Leccion(2, "Leccion 2: Numeros", "Aprende numeros basicos en ingles.", leccion2)
        );

        int indice3 = rutaLecciones.agregarVertice(
            Leccion(3, "Leccion 3: Animales", "Aprende nombres de animales.", leccion3)
        );

        int indice4 = rutaLecciones.agregarVertice(
            Leccion(4, "Leccion 4: Frases basicas", "Aprende frases cortas de uso diario.", leccion4)
        );

        rutaLecciones.agregarArista(indice1, indice2);
        rutaLecciones.agregarArista(indice2, indice3);
        rutaLecciones.agregarArista(indice3, indice4);
    }

    void sumarPuntosAUsuario(string correo, int puntos) {
        Usuario* usuario = tablaUsuarios.obtener(correo);

        if (usuario != nullptr) {
            usuario->sumarPuntos(puntos);
        }
    }

    string cargarDatasetPrueba() {
        if (datasetCargado) {
            return "El dataset ya fue cargado anteriormente.";
        }

        int cantidad = DatasetGenerator::getCantidadUsuarios();

        for (int i = 0; i < cantidad; i++) {
            string nombre = DatasetGenerator::getNombreUsuario(i);
            string correo = DatasetGenerator::getCorreoUsuario(i);
            string clave = DatasetGenerator::getClaveUsuario(i);
            int puntos = DatasetGenerator::getPuntosUsuario(i);

            bool registrado = registrarUsuario(nombre, correo, clave);

            if (registrado) {
                sumarPuntosAUsuario(correo, puntos);
            }
        }

        datasetCargado = true;

        string resultado = "DATASET CARGADO CORRECTAMENTE\n\n";
        resultado += "Usuarios de prueba agregados: " + to_string(cantidad) + "\n";
        resultado += "Clave de todos los usuarios: 123\n\n";
        resultado += "Ahora puedes revisar el ranking AVL y QuickSort.";

        return resultado;
    }

    string obtenerRankingQuickSort() {
        int cantidadUsuarios = usuarios.getCantidad();

        if (cantidadUsuarios == 0) {
            return "No hay usuarios registrados.";
        }

        Usuario** arreglo = new Usuario * [cantidadUsuarios];

        int posicionArreglo = 0;

        usuarios.recorrer([this, &arreglo, &posicionArreglo](Usuario usuario) {
            Usuario* encontrado = tablaUsuarios.obtener(usuario.getCorreo());

            if (encontrado != nullptr) {
                arreglo[posicionArreglo] = encontrado;
                posicionArreglo++;
            }
            });

        if (posicionArreglo > 1) {
            Ordenamientos<Usuario*>::quickSort(
                arreglo,
                0,
                posicionArreglo - 1,
                [](Usuario* a, Usuario* b) {
                    if (a->getPuntos() == b->getPuntos()) {
                        return a->getId() < b->getId();
                    }

                    return a->getPuntos() < b->getPuntos();
                }
            );
        }

        string resultado = "";

        for (int i = 0; i < posicionArreglo; i++) {
            resultado += to_string(i + 1) + ". ";
            resultado += arreglo[i]->getNombre();
            resultado += " - ";
            resultado += to_string(arreglo[i]->getPuntos());
            resultado += " puntos\n";
        }

        delete[] arreglo;

        return resultado;
    }

    string obtenerRutaLecciones() {
        cargarRutaLecciones();

        string resultado = "";
        int contador = 1;

        rutaLecciones.recorrerDFS(0, [&resultado, &contador](Leccion leccion) {
            resultado += to_string(contador) + ". ";
            resultado += leccion.mostrarLeccion();
            resultado += "-------------------------\n";
            contador++;
            });

        return resultado;
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

        string progreso = "";
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

        string resultado = "";

        historialRespuestas.recorrer([&resultado](Respuesta respuesta) {
            resultado += respuesta.mostrarRespuesta();
            resultado += "-------------------------\n";
            });

        return resultado;
    }
};