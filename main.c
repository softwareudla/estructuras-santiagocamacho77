#include <stdio.h>
#include <string.h>
#include "funciones.h"
 
 
int main() {
    struct Libro biblioteca[20];
    int cantidadLibros = 0, opcion;
 
    // Inicializar la biblioteca con valores predeterminados
    for (int i = 0; i < 20; i++) {
        biblioteca[i].id = 0;
        strcpy(biblioteca[i].titulo, "");
        strcpy(biblioteca[i].autor, "");
        biblioteca[i].anio = 0;
        strcpy(biblioteca[i].estado, "Disponible");
    }
 
    do {
        opcion = mostrarMenu();
        switch (opcion) {
            case 1:
                agregarLibro(biblioteca, cantidadLibros);
                cantidadLibros++;
                break;
            case 2:
                mostrarListaLibros(biblioteca, cantidadLibros);
                break;
            case 3:
                buscarPorId(biblioteca);
                break;
            case 4:
                buscarPorTitulo(biblioteca);
                break;
            case 5:
                actualizarEstadoLibro(biblioteca);
                break;
            case 6:
                cantidadLibros = eliminarLibro(biblioteca, cantidadLibros);
                break;
            case 7:
                printf("Adios!");
                break;
            default:
                printf("Opcion no valida. Intentalo de nuevo.\n");
        }
    } while (opcion != 7);
 
    return 0;
}