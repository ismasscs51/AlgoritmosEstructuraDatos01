#pragma once
#include <functional>
using namespace std;

template <typename T>
class Ordenamientos {
private:
    static void intercambiar(T& a, T& b) {
        T temp = a;
        a = b;
        b = temp;
    }

public:
    static void quickSort(T arreglo[], int izquierda, int derecha, function<bool(T, T)> comparar) {
        int i = izquierda;
        int j = derecha;
        T pivote = arreglo[(izquierda + derecha) / 2];

        while (i <= j) {
            while (comparar(arreglo[i], pivote)) {
                i++;
            }

            while (comparar(pivote, arreglo[j])) {
                j--;
            }

            if (i <= j) {
                intercambiar(arreglo[i], arreglo[j]);
                i++;
                j--;
            }
        }

        if (izquierda < j) {
            quickSort(arreglo, izquierda, j, comparar);
        }

        if (i < derecha) {
            quickSort(arreglo, i, derecha, comparar);
        }
    }
};