#include <iostream>

using namespace std;

const int LIMITE = 20;

bool cargar(int m[][LIMITE], int filas, int columnas, int i, int j) {
    if (i == filas) return true;
    if (j == columnas) return cargar(m, filas, columnas, i + 1, 0);
    if (!(cin >> m[i][j])) return false;
    return cargar(m, filas, columnas, i, j + 1);
}

void mostrar(const int m[][LIMITE], int filas, int columnas, int i, int j) {
    if (i == filas) return;
    if (j == columnas) {
        cout << '\n';
        mostrar(m, filas, columnas, i + 1, 0);
        return;
    }
    if (j > 0) cout << ' ';
    cout << m[i][j];
    mostrar(m, filas, columnas, i, j + 1);
}

long long sumar(const int m[][LIMITE], int filas, int columnas, int i, int j) {
    if (i == filas) return 0;
    if (j == columnas) return sumar(m, filas, columnas, i + 1, 0);
    return m[i][j] + sumar(m, filas, columnas, i, j + 1);
}

int contarPares(const int m[][LIMITE], int filas, int columnas, int i, int j) {
    if (i == filas) return 0;
    if (j == columnas) return contarPares(m, filas, columnas, i + 1, 0);
    return (m[i][j] % 2 == 0) + contarPares(m, filas, columnas, i, j + 1);
}

int mayor(const int m[][LIMITE], int filas, int columnas, int i, int j, int maximo) {
    if (i == filas) return maximo;
    if (j == columnas) return mayor(m, filas, columnas, i + 1, 0, maximo);
    if (m[i][j] > maximo) maximo = m[i][j];
    return mayor(m, filas, columnas, i, j + 1, maximo);
}

void encontrarMenor(const int m[][LIMITE], int filas, int columnas,
                    int i, int j, int& filaMenor, int& columnaMenor) {
    if (i == filas) return;
    if (j == columnas) {
        encontrarMenor(m, filas, columnas, i + 1, 0, filaMenor, columnaMenor);
        return;
    }
    if (m[i][j] < m[filaMenor][columnaMenor]) {
        filaMenor = i;
        columnaMenor = j;
    }
    encontrarMenor(m, filas, columnas, i, j + 1, filaMenor, columnaMenor);
}

void contarSignos(const int m[][LIMITE], int filas, int columnas, int i, int j,
                  int& positivos, int& negativos, int& ceros) {
    if (i == filas) return;
    if (j == columnas) {
        contarSignos(m, filas, columnas, i + 1, 0, positivos, negativos, ceros);
        return;
    }
    if (m[i][j] > 0) positivos++;
    else if (m[i][j] < 0) negativos++;
    else ceros++;
    contarSignos(m, filas, columnas, i, j + 1, positivos, negativos, ceros);
}

bool buscar(const int m[][LIMITE], int filas, int columnas, int& i, int& j, int x) {
    if (i == filas) return false;
    if (j == columnas) {
        i++;
        j = 0;
        return buscar(m, filas, columnas, i, j, x);
    }
    if (m[i][j] == x) return true;
    j++;
    return buscar(m, filas, columnas, i, j, x);
}

long long sumarFila(const int m[][LIMITE], int columnas, int i, int j) {
    if (j == columnas) return 0;
    return m[i][j] + sumarFila(m, columnas, i, j + 1);
}

void mostrarSumasFilas(const int m[][LIMITE], int filas, int columnas, int i) {
    if (i == filas) return;
    cout << "Fila " << i << ": " << sumarFila(m, columnas, i, 0) << '\n';
    mostrarSumasFilas(m, filas, columnas, i + 1);
}

long long sumarColumna(const int m[][LIMITE], int filas, int i, int j) {
    if (i == filas) return 0;
    return m[i][j] + sumarColumna(m, filas, i + 1, j);
}

void mostrarSumasColumnas(const int m[][LIMITE], int filas, int columnas, int j) {
    if (j == columnas) return;
    cout << "Columna " << j << ": " << sumarColumna(m, filas, 0, j) << '\n';
    mostrarSumasColumnas(m, filas, columnas, j + 1);
}

long long diagonalPrincipal(const int m[][LIMITE], int n, int i) {
    if (i == n) return 0;
    return m[i][i] + diagonalPrincipal(m, n, i + 1);
}

long long diagonalSecundaria(const int m[][LIMITE], int n, int i) {
    if (i == n) return 0;
    return m[i][n - 1 - i] + diagonalSecundaria(m, n, i + 1);
}

void sumarRegiones(const int m[][LIMITE], int n, int i, int j,
                   long long& encima, long long& debajo) {
    if (i == n) return;
    if (j == n) {
        sumarRegiones(m, n, i + 1, 0, encima, debajo);
        return;
    }
    if (i < j) encima += m[i][j];
    if (i > j) debajo += m[i][j];
    sumarRegiones(m, n, i, j + 1, encima, debajo);
}

bool esBorde(int filas, int columnas, int i, int j) {
    return i == 0 || j == 0 || i == filas - 1 || j == columnas - 1;
}

void mostrarBorde(const int m[][LIMITE], int filas, int columnas, int i, int j) {
    if (i == filas) return;
    if (j == columnas) {
        mostrarBorde(m, filas, columnas, i + 1, 0);
        return;
    }
    if (esBorde(filas, columnas, i, j)) {
        if (i != 0 || j != 0) cout << ' ';
        cout << m[i][j];
    }
    mostrarBorde(m, filas, columnas, i, j + 1);
}

long long sumarBorde(const int m[][LIMITE], int filas, int columnas, int i, int j) {
    if (i == filas) return 0;
    if (j == columnas) return sumarBorde(m, filas, columnas, i + 1, 0);
    int valor = 0;
    if (esBorde(filas, columnas, i, j)) valor = m[i][j];
    return valor + sumarBorde(m, filas, columnas, i, j + 1);
}

void mostrarTranspuesta(const int m[][LIMITE], int filas, int columnas, int i, int j) {
    if (j == columnas) return;
    if (i == filas) {
        cout << '\n';
        mostrarTranspuesta(m, filas, columnas, 0, j + 1);
        return;
    }
    if (i > 0) cout << ' ';
    cout << m[i][j];
    mostrarTranspuesta(m, filas, columnas, i + 1, j);
}

int mayorFila(const int m[][LIMITE], int columnas, int i, int j) {
    if (j == columnas - 1) return m[i][j];
    int resto = mayorFila(m, columnas, i, j + 1);
    if (m[i][j] > resto) return m[i][j];
    return resto;
}

void mostrarMayoresFilas(const int m[][LIMITE], int filas, int columnas, int i) {
    if (i == filas) return;
    cout << "Fila " << i << ": " << mayorFila(m, columnas, i, 0) << '\n';
    mostrarMayoresFilas(m, filas, columnas, i + 1);
}

bool esSimetrica(const int m[][LIMITE], int n, int i, int j) {
    if (i == n) return true;
    if (j == n) return esSimetrica(m, n, i + 1, i + 1);
    if (m[i][j] != m[j][i]) return false;
    return esSimetrica(m, n, i, j + 1);
}

void mostrarRotada(const int m[][LIMITE], int n, int i, int j) {
    if (i == n) return;
    if (j == n) {
        cout << '\n';
        mostrarRotada(m, n, i + 1, 0);
        return;
    }
    if (j > 0) cout << ' ';
    cout << m[n - 1 - j][i];
    mostrarRotada(m, n, i, j + 1);
}

void mostrarTramo(const int m[][LIMITE], int i, int j, int pasoFila,
                  int pasoColumna, int cantidad, bool& primero) {
    if (cantidad <= 0) return;
    if (!primero) cout << ' ';
    cout << m[i][j];
    primero = false;
    mostrarTramo(m, i + pasoFila, j + pasoColumna, pasoFila, pasoColumna,
                 cantidad - 1, primero);
}

void mostrarEspiral(const int m[][LIMITE], int arriba, int abajo,
                    int izquierda, int derecha, bool& primero) {
    if (arriba > abajo || izquierda > derecha) return;
    mostrarTramo(m, arriba, izquierda, 0, 1, derecha - izquierda + 1, primero);
    mostrarTramo(m, arriba + 1, derecha, 1, 0, abajo - arriba, primero);
    if (abajo > arriba) {
        mostrarTramo(m, abajo, derecha - 1, 0, -1, derecha - izquierda, primero);
    }
    if (derecha > izquierda) {
        mostrarTramo(m, abajo - 1, izquierda, -1, 0, abajo - arriba - 1, primero);
    }
    mostrarEspiral(m, arriba + 1, abajo - 1, izquierda + 1, derecha - 1, primero);
}

bool esTriangularSuperior(const int m[][LIMITE], int n, int i, int j) {
    if (i == n) return true;
    if (j == i) return esTriangularSuperior(m, n, i + 1, 0);
    if (m[i][j] != 0) return false;
    return esTriangularSuperior(m, n, i, j + 1);
}

bool esMinimoFila(const int m[][LIMITE], int columnas, int i, int j, int valor) {
    if (j == columnas) return true;
    if (m[i][j] < valor) return false;
    return esMinimoFila(m, columnas, i, j + 1, valor);
}

bool esMaximoColumna(const int m[][LIMITE], int filas, int i, int j, int valor) {
    if (i == filas) return true;
    if (m[i][j] > valor) return false;
    return esMaximoColumna(m, filas, i + 1, j, valor);
}

bool buscarSilla(const int m[][LIMITE], int filas, int columnas, int& i, int& j) {
    if (i == filas) return false;
    if (j == columnas) {
        i++;
        j = 0;
        return buscarSilla(m, filas, columnas, i, j);
    }
    int valor = m[i][j];
    if (esMinimoFila(m, columnas, i, 0, valor) && esMaximoColumna(m, filas, 0, j, valor)) {
        return true;
    }
    j++;
    return buscarSilla(m, filas, columnas, i, j);
}

bool hayIguales(const int m[][LIMITE], int filas, int columnas, int i, int j,
                int pasoFila, int pasoColumna, int k, int valor) {
    if (k == 0) return true;
    if (i >= filas || j < 0 || j >= columnas || m[i][j] != valor) return false;
    return hayIguales(m, filas, columnas, i + pasoFila, j + pasoColumna,
                      pasoFila, pasoColumna, k - 1, valor);
}

bool buscarSecuencia(const int m[][LIMITE], int filas, int columnas, int i, int j, int k) {
    if (i == filas) return false;
    if (j == columnas) return buscarSecuencia(m, filas, columnas, i + 1, 0, k);
    int valor = m[i][j];
    if (hayIguales(m, filas, columnas, i, j, 0, 1, k, valor) ||
        hayIguales(m, filas, columnas, i, j, 1, 0, k, valor) ||
        hayIguales(m, filas, columnas, i, j, 1, 1, k, valor) ||
        hayIguales(m, filas, columnas, i, j, 1, -1, k, valor)) return true;
    return buscarSecuencia(m, filas, columnas, i, j + 1, k);
}

// Guarda la mejor suma desde cada casilla para reutilizarla al reconstruir el camino.
long long calcularCamino(const int m[][LIMITE], int filas, int columnas,
                         int i, int j, long long sumas[][LIMITE], bool calculado[][LIMITE]) {
    if (calculado[i][j]) return sumas[i][j];
    long long resto = 0;
    if (i + 1 < filas && j + 1 < columnas) {
        long long derecha = calcularCamino(m, filas, columnas, i, j + 1, sumas, calculado);
        long long abajo = calcularCamino(m, filas, columnas, i + 1, j, sumas, calculado);
        resto = derecha >= abajo ? derecha : abajo;
    } else if (j + 1 < columnas) {
        resto = calcularCamino(m, filas, columnas, i, j + 1, sumas, calculado);
    } else if (i + 1 < filas) {
        resto = calcularCamino(m, filas, columnas, i + 1, j, sumas, calculado);
    }
    sumas[i][j] = m[i][j] + resto;
    calculado[i][j] = true;
    return sumas[i][j];
}

void mostrarCamino(const int m[][LIMITE], const long long sumas[][LIMITE],
                   int filas, int columnas, int i, int j) {
    cout << m[i][j];
    if (i == filas - 1 && j == columnas - 1) return;
    cout << " -> ";
    if (j + 1 < columnas && (i + 1 == filas || sumas[i][j + 1] >= sumas[i + 1][j])) {
        mostrarCamino(m, sumas, filas, columnas, i, j + 1);
    } else {
        mostrarCamino(m, sumas, filas, columnas, i + 1, j);
    }
}

int main() {
    int ejercicio, filas, columnas;
    cout << "Ejercicio (26 a 50), filas y columnas (1 a " << LIMITE << "): ";
    if (!(cin >> ejercicio >> filas >> columnas) || ejercicio < 26 || ejercicio > 50 ||
        filas < 1 || filas > LIMITE || columnas < 1 || columnas > LIMITE) {
        cerr << "Ejercicio o dimensiones invalidas.\n";
        return 1;
    }
    if (filas != columnas && ((ejercicio >= 36 && ejercicio <= 38) ||
                              ejercicio == 43 || ejercicio == 44 ||
                              ejercicio == 46 || ejercicio == 47)) {
        cerr << "Este ejercicio requiere una matriz cuadrada.\n";
        return 1;
    }

    int m[LIMITE][LIMITE];
    cout << "Elementos de la matriz por filas: ";
    if (!cargar(m, filas, columnas, 0, 0)) {
        cerr << "Faltan elementos o hay un valor invalido.\n";
        return 1;
    }

    int i = 0, j = 0;
    switch (ejercicio) {
        case 26:
            cout << "Matriz cargada:\n";
            mostrar(m, filas, columnas, 0, 0);
            break;
        case 27:
            cout << '\n';
            mostrar(m, filas, columnas, 0, 0);
            break;
        case 28:
            cout << "Suma total: " << sumar(m, filas, columnas, 0, 0) << '\n';
            break;
        case 29: {
            int pares = contarPares(m, filas, columnas, 0, 0);
            cout << "Pares: " << pares << "; impares: " << filas * columnas - pares << '\n';
            break;
        }
        case 30:
            cout << "Mayor: " << mayor(m, filas, columnas, 0, 0, m[0][0]) << '\n';
            break;
        case 31:
            encontrarMenor(m, filas, columnas, 0, 0, i, j);
            cout << "Menor: " << m[i][j] << "; fila: " << i << "; columna: " << j << '\n';
            break;
        case 32: {
            int positivos = 0, negativos = 0, ceros = 0;
            contarSignos(m, filas, columnas, 0, 0, positivos, negativos, ceros);
            cout << "Positivos: " << positivos << "; negativos: " << negativos
                 << "; ceros: " << ceros << '\n';
            break;
        }
        case 33: {
            int x;
            cout << "X: ";
            if (!(cin >> x)) return 1;
            if (buscar(m, filas, columnas, i, j, x)) {
                cout << "Encontrado en fila " << i << ", columna " << j << '\n';
            } else {
                cout << "No encontrado\n";
            }
            break;
        }
        case 34:
            mostrarSumasFilas(m, filas, columnas, 0);
            break;
        case 35:
            mostrarSumasColumnas(m, filas, columnas, 0);
            break;
        case 36:
            cout << "Suma diagonal principal: " << diagonalPrincipal(m, filas, 0) << '\n';
            break;
        case 37:
            cout << "Suma diagonal secundaria: " << diagonalSecundaria(m, filas, 0) << '\n';
            break;
        case 38:
        case 47: {
            long long encima = 0, debajo = 0;
            sumarRegiones(m, filas, 0, 0, encima, debajo);
            if (ejercicio == 38) {
                cout << "Encima: " << encima << "; debajo: " << debajo << '\n';
            } else {
                long long diagonal = diagonalPrincipal(m, filas, 0);
                cout << "Triangulo superior: " << encima + diagonal
                     << "; triangulo inferior: " << debajo + diagonal << '\n';
            }
            break;
        }
        case 39:
            cout << "Borde por filas: ";
            mostrarBorde(m, filas, columnas, 0, 0);
            cout << '\n';
            break;
        case 40:
            cout << "Suma del borde: " << sumarBorde(m, filas, columnas, 0, 0) << '\n';
            break;
        case 41:
            cout << "Transpuesta (" << columnas << 'x' << filas << "):\n";
            mostrarTranspuesta(m, filas, columnas, 0, 0);
            break;
        case 42:
            mostrarMayoresFilas(m, filas, columnas, 0);
            break;
        case 43:
            cout << "Simetrica: " << (esSimetrica(m, filas, 0, 0) ? "Si" : "No") << '\n';
            break;
        case 44:
            cout << "Rotada:\n";
            mostrarRotada(m, filas, 0, 0);
            break;
        case 45: {
            bool primero = true;
            mostrarEspiral(m, 0, filas - 1, 0, columnas - 1, primero);
            cout << '\n';
            break;
        }
        case 46:
            cout << "Triangular superior: " << (esTriangularSuperior(m, filas, 0, 0) ? "Si" : "No")
                 << '\n';
            break;
        case 48:
            if (buscarSilla(m, filas, columnas, i, j)) {
                cout << "Punto de silla: valor " << m[i][j] << "; fila: " << i
                     << "; columna: " << j << '\n';
            } else {
                cout << "No hay punto de silla\n";
            }
            break;
        case 49: {
            int k;
            cout << "Longitud K: ";
            if (!(cin >> k) || k <= 0) {
                cerr << "K debe ser positivo.\n";
                return 1;
            }
            cout << "Existe la secuencia: " << (buscarSecuencia(m, filas, columnas, 0, 0, k) ? "Si" : "No")
                 << '\n';
            break;
        }
        case 50: {
            long long sumas[LIMITE][LIMITE];
            bool calculado[LIMITE][LIMITE] = {};
            long long mejor = calcularCamino(m, filas, columnas, 0, 0, sumas, calculado);
            cout << "Suma maxima: " << mejor << "; camino: ";
            mostrarCamino(m, sumas, filas, columnas, 0, 0);
            cout << '\n';
            break;
        }
    }
    return 0;
}
