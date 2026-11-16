# Recursividad con vectores y matrices

Práctica de Programación I en C++. Cada programa ejecuta un ejercicio por vez. El código usa arreglos de tamaño fijo y los recorridos avanzan mediante llamadas recursivas.

| Archivo | Ejercicios | Capacidad |
| --- | --- | --- |
| vectores.cpp | 1 a 25 | 100 elementos |
| matrices.cpp | 26 a 50 | 20 filas y 20 columnas |

## Compilar en Windows

Con un compilador g++ disponible, abre PowerShell en la carpeta de los archivos y ejecuta:

    g++ -std=c++11 -Wall -Wextra vectores.cpp -o vectores.exe
    g++ -std=c++11 -Wall -Wextra matrices.cpp -o matrices.exe

Cada archivo tiene su propio main y se compila por separado. En Linux o macOS se pueden usar los mismos comandos quitando la extensión .exe.

## Probar un ejercicio

Los datos se pueden escribir separados por espacios o saltos de línea.

- Vectores recibe el número de ejercicio, el tamaño, los elementos y, si corresponde, el dato extra. Para el 22, la última entrada es K.
- Matrices recibe el número de ejercicio, la cantidad de filas, la cantidad de columnas y los elementos en orden por filas. Para una matriz cuadrada, escribe la misma dimensión dos veces.

```powershell
'22 5 1 2 3 4 5 2' | .\vectores.exe
'50 3 3 5 1 2 4 8 3 1 9 6' | .\matrices.exe
```

El ejercicio 22 imprime el vector rotado [4, 5, 1, 2, 3]. El 50 imprime una suma de 32 y el camino 5 -> 4 -> 8 -> 9 -> 6.

## Para revisar la recursión

- En el ejercicio 4, sumar devuelve 0 al llegar a i == n. Las llamadas anteriores agregan su elemento al regresar.
- En el ejercicio 18, posicionMenor halla el mínimo del tramo que falta ordenar. Después de intercambiarlo, ordenarSeleccion avanza al siguiente índice.
- En el ejercicio 45, mostrarEspiral imprime los lados del borde y repite con el rectángulo interior. Cada tramo se imprime también con recursividad.
- En el ejercicio 50, calcularCamino guarda la mejor suma desde cada casilla hasta la meta. mostrarCamino usa esas sumas para decidir entre derecha y abajo. En caso de empate elige derecha.

## Subir a GitHub

En el repositorio que uses para la entrega, sube vectores.cpp, matrices.cpp y README.md. Los ejecutables generados en tu computadora no hacen falta para la entrega.
