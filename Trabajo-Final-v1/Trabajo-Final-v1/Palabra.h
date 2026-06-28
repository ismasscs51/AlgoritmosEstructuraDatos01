#pragma once
#include <string>
using namespace std;

class Palabra {
private:
    string ingles;
    string espanol;
    string categoria;

public:
    Palabra() {
        ingles = "";
        espanol = "";
        categoria = "";
    }

    Palabra(string ingles, string espanol, string categoria) {
        this->ingles = ingles;
        this->espanol = espanol;
        this->categoria = categoria;
    }

    string getIngles() {
        return ingles;
    }

    string getEspanol() {
        return espanol;
    }

    string getCategoria() {
        return categoria;
    }

    string mostrarPalabra() {
        string texto = "";
        texto += ingles + "  ->  " + espanol + "\n";
        texto += "Categoria: " + categoria + "\n";
        return texto;
    }
};