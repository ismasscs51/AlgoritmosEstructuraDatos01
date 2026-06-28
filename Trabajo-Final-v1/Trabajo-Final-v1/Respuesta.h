#pragma once
#include <string>
using namespace std;

class Respuesta {
private:
    int id;
    string pregunta;
    char respuestaUsuario;
    char respuestaCorrecta;
    bool correcta;
    int puntosGanados;

public:
    Respuesta() {
        id = 0;
        pregunta = "";
        respuestaUsuario = ' ';
        respuestaCorrecta = ' ';
        correcta = false;
        puntosGanados = 0;
    }

    Respuesta(int id, string pregunta, char respuestaUsuario, char respuestaCorrecta, bool correcta, int puntosGanados) {
        this->id = id;
        this->pregunta = pregunta;
        this->respuestaUsuario = respuestaUsuario;
        this->respuestaCorrecta = respuestaCorrecta;
        this->correcta = correcta;
        this->puntosGanados = puntosGanados;
    }

    string mostrarRespuesta() {
        string texto = "";

        texto += "Pregunta: " + pregunta + "\n";
        texto += "Respuesta del usuario: ";
        texto += respuestaUsuario;
        texto += "\n";

        texto += "Respuesta correcta: ";
        texto += respuestaCorrecta;
        texto += "\n";

        texto += "Resultado: ";
        texto += correcta ? "Correcto" : "Incorrecto";
        texto += "\n";

        texto += "Puntos ganados: " + to_string(puntosGanados) + "\n";

        return texto;
    }
};