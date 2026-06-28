#pragma once
#include <string>
using namespace std;

class DatasetGenerator {
public:

    static int getCantidadUsuarios() {
        return 5;
    }

    static string getNombreUsuario(int indice) {
        switch (indice) {
        case 0: return "Ana";
        case 1: return "Carlos";
        case 2: return "Maria";
        case 3: return "Luis";
        case 4: return "Sofia";
        default: return "Usuario";
        }
    }

    static string getCorreoUsuario(int indice) {
        switch (indice) {
        case 0: return "ana@test.com";
        case 1: return "carlos@test.com";
        case 2: return "maria@test.com";
        case 3: return "luis@test.com";
        case 4: return "sofia@test.com";
        default: return "usuario@test.com";
        }
    }

    static string getClaveUsuario(int indice) {
        return "123";
    }

    static int getPuntosUsuario(int indice) {
        switch (indice) {
        case 0: return 40;
        case 1: return 90;
        case 2: return 20;
        case 3: return 70;
        case 4: return 120;
        default: return 0;
        }
    }
};