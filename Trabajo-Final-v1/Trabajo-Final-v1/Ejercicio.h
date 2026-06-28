#pragma once
#include <string>
using namespace std;

class Ejercicio {
private:
    int id;
    string pregunta;
    string opcionA;
    string opcionB;
    string opcionC;
    char respuestaCorrecta;

public:
    Ejercicio() {
        id = 0;
        pregunta = "";
        opcionA = "";
        opcionB = "";
        opcionC = "";
        respuestaCorrecta = 'A';
    }

    Ejercicio(int id, string pregunta, string opcionA, string opcionB, string opcionC, char respuestaCorrecta) {
        this->id = id;
        this->pregunta = pregunta;
        this->opcionA = opcionA;
        this->opcionB = opcionB;
        this->opcionC = opcionC;
        this->respuestaCorrecta = respuestaCorrecta;
    }

    int getId() {
        return id;
    }

    string getPregunta() {
        return pregunta;
    }

    string getOpcionA() {
        return opcionA;
    }

    string getOpcionB() {
        return opcionB;
    }

    string getOpcionC() {
        return opcionC;
    }

    char getRespuestaCorrecta() {
        return respuestaCorrecta;
    }

    bool validarRespuesta(char respuestaUsuario) {
        return respuestaUsuario == respuestaCorrecta;
    }
};