#include <iomanip>
#include <iostream>
#include <utility>

using namespace std;

const int CAPACIDAD = 100;

bool cargar(int v[], int n, int i) {
    if (i == n) return true;
    if (!(cin >> v[i])) return false;
    return cargar(v, n, i + 1);
}

void mostrar(const int v[], int n, int i, const char* separador) {
    if (i == n) return;
    if (i > 0) cout << separador;
    cout << v[i];
    mostrar(v, n, i + 1, separador);
}

void mostrarLista(const int v[], int n) {
    cout << '[';
    mostrar(v, n, 0, ", ");
    cout << "]\n";
}

void mostrarInverso(const int v[], int i) {
    if (i < 0) return;
    cout << v[i];
    if (i > 0) cout << ' ';
    mostrarInverso(v, i - 1);
}

long long sumar(const int v[], int n, int i) {
    if (i == n) return 0;
    return v[i] + sumar(v, n, i + 1);
}

int contarPares(const int v[], int n, int i) {
    if (i == n) return 0;
    return (v[i] % 2 == 0) + contarPares(v, n, i + 1);
}

void contarSignos(const int v[], int n, int i, int& positivos, int& negativos, int& ceros) {
    if (i == n) return;
    if (v[i] > 0) positivos++;
    else if (v[i] < 0) negativos++;
    else ceros++;
    contarSignos(v, n, i + 1, positivos, negativos, ceros);
}

double promedio(const int v[], int n) {
    return static_cast<double>(sumar(v, n, 0)) / n;
}

int contarMultiplos(const int v[], int n, int i, int k) {
    if (i == n) return 0;
    return (static_cast<long long>(v[i]) % k == 0) + contarMultiplos(v, n, i + 1, k);
}

int mayor(const int v[], int n, int i) {
    if (i == n - 1) return v[i];
    int mayorResto = mayor(v, n, i + 1);
    if (v[i] > mayorResto) return v[i];
    return mayorResto;
}

int posicionMenor(const int v[], int n, int i) {
    if (i == n - 1) return i;
    int posicionResto = posicionMenor(v, n, i + 1);
    if (v[i] <= v[posicionResto]) return i;
    return posicionResto;
}

int buscar(const int v[], int n, int i, int x) {
    if (i == n) return -1;
    if (v[i] == x) return i;
    return buscar(v, n, i + 1, x);
}

int contarRepeticiones(const int v[], int n, int i, int x) {
    if (i == n) return 0;
    return (v[i] == x) + contarRepeticiones(v, n, i + 1, x);
}

void reemplazar(int v[], int n, int i, int x, int y) {
    if (i == n) return;
    if (v[i] == x) v[i] = y;
    reemplazar(v, n, i + 1, x, y);
}

void invertir(int v[], int izquierda, int derecha) {
    if (izquierda >= derecha) return;
    swap(v[izquierda], v[derecha]);
    invertir(v, izquierda + 1, derecha - 1);
}

bool estaOrdenado(const int v[], int n, int i) {
    if (i + 1 >= n) return true;
    if (v[i] > v[i + 1]) return false;
    return estaOrdenado(v, n, i + 1);
}

void sumarPorIndice(const int v[], int n, int i, long long& pares, long long& impares) {
    if (i == n) return;
    if (i % 2 == 0) pares += v[i];
    else impares += v[i];
    sumarPorIndice(v, n, i + 1, pares, impares);
}

void desplazar(int v[], int n, int i) {
    if (i + 1 == n) return;
    v[i] = v[i + 1];
    desplazar(v, n, i + 1);
}

void eliminarPosicion(int v[], int& n, int posicion) {
    desplazar(v, n, posicion);
    n--;
}

void ordenarSeleccion(int v[], int n, int i) {
    if (i + 1 >= n) return;
    int menor = posicionMenor(v, n, i);
    swap(v[i], v[menor]);
    ordenarSeleccion(v, n, i + 1);
}

int buscarBinaria(const int v[], int izquierda, int derecha, int x) {
    if (izquierda > derecha) return -1;
    int centro = izquierda + (derecha - izquierda) / 2;
    if (v[centro] == x) return centro;
    if (x < v[centro]) return buscarBinaria(v, izquierda, centro - 1, x);
    return buscarBinaria(v, centro + 1, derecha, x);
}

int quitarDuplicados(int v[], int n, int lectura, int escritura) {
    if (lectura == n) return escritura;
    if (buscar(v, escritura, 0, v[lectura]) == -1) {
        v[escritura] = v[lectura];
        escritura++;
    }
    return quitarDuplicados(v, n, lectura + 1, escritura);
}

void separarPares(int v[], int izquierda, int derecha) {
    if (izquierda >= derecha) return;
    if (v[izquierda] % 2 == 0) {
        separarPares(v, izquierda + 1, derecha);
    } else if (v[derecha] % 2 != 0) {
        separarPares(v, izquierda, derecha - 1);
    } else {
        swap(v[izquierda], v[derecha]);
        separarPares(v, izquierda + 1, derecha - 1);
    }
}

void rotarDerecha(int v[], int n, int k) {
    if (n == 0) return;
    k %= n;
    if (k < 0) k += n;
    if (k == 0) return;
    invertir(v, 0, n - 1);
    invertir(v, 0, k - 1);
    invertir(v, k, n - 1);
}

int longitudCreciente(const int v[], int n, int i, int actual, int mejor) {
    if (i == n) return mejor;
    if (v[i] > v[i - 1]) actual++;
    else actual = 1;
    if (actual > mejor) mejor = actual;
    return longitudCreciente(v, n, i + 1, actual, mejor);
}

int posicionSegundo(const int v[], int n, int i, int maximo, int candidato) {
    if (i == n) return candidato;
    if (v[i] != maximo && (candidato == -1 || v[i] > v[candidato])) candidato = i;
    return posicionSegundo(v, n, i + 1, maximo, candidato);
}

void maximoSegmento(const int v[], int n, int i, long long sumaActual, int inicioActual,
                    long long& mejor, int& inicioMejor, int& finMejor) {
    if (i == n) return;
    if (sumaActual < 0) {
        sumaActual = v[i];
        inicioActual = i;
    } else {
        sumaActual += v[i];
    }
    if (sumaActual > mejor) {
        mejor = sumaActual;
        inicioMejor = inicioActual;
        finMejor = i;
    }
    maximoSegmento(v, n, i + 1, sumaActual, inicioActual, mejor, inicioMejor, finMejor);
}

int main() {
    int ejercicio, n;
    cout << "Ejercicio (1 a 25) y cantidad de elementos (0 a " << CAPACIDAD << "): ";
    if (!(cin >> ejercicio >> n) || ejercicio < 1 || ejercicio > 25 || n < 0 || n > CAPACIDAD) {
        cerr << "Ejercicio o cantidad invalida.\n";
        return 1;
    }
    if (n == 0 && (ejercicio == 7 || ejercicio == 9 || ejercicio == 10 ||
                   ejercicio == 17 || ejercicio == 24 || ejercicio == 25)) {
        cerr << "Este ejercicio requiere un vector no vacio.\n";
        return 1;
    }

    int v[CAPACIDAD];
    cout << "Elementos del vector: ";
    if (!cargar(v, n, 0)) {
        cerr << "Faltan elementos o hay un valor invalido.\n";
        return 1;
    }

    int x, y, k, posicion;
    int positivos = 0, negativos = 0, ceros = 0;
    long long sumaPares = 0, sumaImpares = 0;
    switch (ejercicio) {
        case 1:
            cout << "Vector cargado: ";
            mostrarLista(v, n);
            break;
        case 2:
            mostrar(v, n, 0, " ");
            cout << '\n';
            break;
        case 3:
            mostrarInverso(v, n - 1);
            cout << '\n';
            break;
        case 4:
            cout << "Suma total: " << sumar(v, n, 0) << '\n';
            break;
        case 5:
            cout << "Cantidad de pares: " << contarPares(v, n, 0) << '\n';
            break;
        case 6:
            contarSignos(v, n, 0, positivos, negativos, ceros);
            cout << "Positivos: " << positivos << "; negativos: " << negativos
                 << "; ceros: " << ceros << '\n';
            break;
        case 7:
            cout << fixed << setprecision(2) << "Promedio: " << promedio(v, n) << '\n';
            break;
        case 8:
            cout << "K (distinto de cero): ";
            if (!(cin >> k) || k == 0) {
                cerr << "K invalido.\n";
                return 1;
            }
            cout << "Multiplos de " << k << ": " << contarMultiplos(v, n, 0, k) << '\n';
            break;
        case 9:
            cout << "Mayor: " << mayor(v, n, 0) << '\n';
            break;
        case 10:
            posicion = posicionMenor(v, n, 0);
            cout << "Menor: " << v[posicion] << "; indice: " << posicion << '\n';
            break;
        case 11:
        case 12:
        case 19:
            cout << "X: ";
            if (!(cin >> x)) return 1;
            if (ejercicio == 11) {
                cout << "Primera posicion: " << buscar(v, n, 0, x) << '\n';
            } else if (ejercicio == 12) {
                cout << "Apariciones: " << contarRepeticiones(v, n, 0, x) << '\n';
            } else {
                if (!estaOrdenado(v, n, 0)) {
                    cerr << "La busqueda binaria requiere un vector ordenado.\n";
                    return 1;
                }
                cout << "Indice encontrado: " << buscarBinaria(v, 0, n - 1, x) << '\n';
            }
            break;
        case 13:
            cout << "X e Y: ";
            if (!(cin >> x >> y)) return 1;
            reemplazar(v, n, 0, x, y);
            cout << "Vector final: ";
            mostrarLista(v, n);
            break;
        case 14:
            invertir(v, 0, n - 1);
            cout << "Vector invertido: ";
            mostrarLista(v, n);
            break;
        case 15:
            cout << "Orden ascendente: " << (estaOrdenado(v, n, 0) ? "Si" : "No") << '\n';
            break;
        case 16:
            sumarPorIndice(v, n, 0, sumaPares, sumaImpares);
            cout << "Suma indices pares: " << sumaPares
                 << "; suma indices impares: " << sumaImpares << '\n';
            break;
        case 17:
            cout << "Posicion P: ";
            if (!(cin >> posicion) || posicion < 0 || posicion >= n) {
                cerr << "Posicion invalida.\n";
                return 1;
            }
            eliminarPosicion(v, n, posicion);
            cout << "N nuevo: " << n << "; vector logico: ";
            mostrarLista(v, n);
            break;
        case 18:
            ordenarSeleccion(v, n, 0);
            cout << "Vector ordenado: ";
            mostrarLista(v, n);
            break;
        case 20:
            n = quitarDuplicados(v, n, 0, 0);
            cout << "N nuevo: " << n << "; vector logico: ";
            mostrarLista(v, n);
            break;
        case 21:
            separarPares(v, 0, n - 1);
            cout << "Pares antes que impares: ";
            mostrarLista(v, n);
            break;
        case 22:
            cout << "Desplazamiento K: ";
            if (!(cin >> k)) return 1;
            rotarDerecha(v, n, k);
            cout << "Vector rotado: ";
            mostrarLista(v, n);
            break;
        case 23:
            cout << "Longitud maxima: " << (n == 0 ? 0 : longitudCreciente(v, n, 1, 1, 1)) << '\n';
            break;
        case 24: {
            int maximo = mayor(v, n, 0);
            int segundo = posicionSegundo(v, n, 0, maximo, -1);
            cout << "Mayor: " << maximo << "; segundo mayor distinto: ";
            if (segundo == -1) cout << "No existe\n";
            else cout << v[segundo] << '\n';
            break;
        }
        case 25: {
            long long mejor = v[0];
            int inicio = 0, fin = 0;
            maximoSegmento(v, n, 1, v[0], 0, mejor, inicio, fin);
            cout << "Suma maxima: " << mejor << "; segmento: ";
            mostrarLista(v + inicio, fin - inicio + 1);
            break;
        }
    }
    return 0;
}
