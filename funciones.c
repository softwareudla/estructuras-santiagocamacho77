#include <stdio.h>
#include <string.h>
#include "funciones.h"
 
 
int mostrarMenu() {
    int opcion;
    printf("\n--- Menu Principal ---\n");
    printf("1. Agregar un libro\n");
    printf("2. Mostrar todos los libros\n");
    printf("3. Buscar libro por ID\n");
    printf("4. Buscar libro por titulo\n");
    printf("5. Actualizar el estado de un libro\n");
    printf("6. Eliminar libro\n");
    printf("7. Salir\n");
    printf("Elige una opcion: ");
 
    scanf("%d", &opcion);  
    getchar();  
 
    return opcion;
}
 
 
void agregarLibro(struct Libro biblioteca[], int cantidad) {
    if (cantidad >= 20) {
        printf("No puedes agregar mas libros. Limite alcanzado.\n");
        return;
    }
 
    printf("ID del libro: %d\n", cantidad + 1);
 
    printf("Ingresa el titulo del libro: ");
    fgets(biblioteca[cantidad].titulo, 50, stdin);
    biblioteca[cantidad].titulo[strcspn(biblioteca[cantidad].titulo, "\n")] = 0;
 
    printf("Ingresa el autor: ");
    fgets(biblioteca[cantidad].autor, 50, stdin);
    biblioteca[cantidad].autor[strcspn(biblioteca[cantidad].autor, "\n")] = 0;
 
    printf("Ingresa el año de publicacion: ");
    int anio;
    scanf("%d", &anio);  
    getchar();
 
 
    biblioteca[cantidad].id = cantidad + 1;
    biblioteca[cantidad].anio = anio;
    strcpy(biblioteca[cantidad].estado, "Disponible");
 
    printf("Libro agregado correctamente.\n");
}
 
void mostrarListaLibros(struct Libro biblioteca[], int cantidad) {
    printf("\nLista de libros en la biblioteca:\n");
    printf("ID\t\tTitulo\t\tAutor\t\tAño\t\tEstado\n");
 
    for (int i = 0; i < cantidad; i++) {
        printf("%d\t\t%s\t\t%s\t\t%d\t\t%s\n",
               biblioteca[i].id,
               biblioteca[i].titulo,
               biblioteca[i].autor,
               biblioteca[i].anio,
               biblioteca[i].estado);
    }
}
 
void buscarPorId(struct Libro biblioteca[]) {
    int idBuscar = 0;
    printf("Ingresa el ID del libro a buscar: ");
    scanf("%d", &idBuscar);  
    getchar();
 
    for (int i = 0; i < 20; i++) {
    if (biblioteca[i].id == idBuscar) {
        printf("Libro encontrado:\n");
        printf("ID: %d\nTitulo: %s\nAutor: %s\nAño: %d\nEstado: %s\n",
               biblioteca[i].id,
               biblioteca[i].titulo,
               biblioteca[i].autor,
               biblioteca[i].anio,
               biblioteca[i].estado);
        return;
    }
}
 
    printf("No se encontro un libro con ese ID.\n");
}
 
void buscarPorTitulo(struct Libro biblioteca[]) {
    char titulo[50];
    printf("Ingresa el titulo del libro a buscar: ");
    fgets(titulo, 50, stdin);
    titulo[strcspn(titulo, "\n")] = 0;
 
    for (int i = 0; i < 20; i++) {
        if (strcmp(biblioteca[i].titulo, titulo) == 0) {
            printf("Libro encontrado:\n");
            printf("ID: %d\nTitulo: %s\nAutor: %s\nAño: %d\nEstado: %s\n",
                   biblioteca[i].id,
                   biblioteca[i].titulo,
                   biblioteca[i].autor,
                   biblioteca[i].anio,
                   biblioteca[i].estado);
            return;
        }
    }
 
    printf("No se encontro un libro con ese titulo.\n");
}
 
void actualizarEstadoLibro(struct Libro biblioteca[]) {
    int idBuscar = 0;
    printf("Ingresa el ID del libro para actualizar el estado: ");
    scanf("%d", &idBuscar);  
    getchar();
 
    for (int i = 0; i < 20; i++) {
        if (biblioteca[i].id == idBuscar) {
            if (strcmp(biblioteca[i].estado, "Disponible") == 0) {
                strcpy(biblioteca[i].estado, "Prestado");
                printf("El estado del libro con ID %d se ha cambiado a 'Prestado'.\n", idBuscar);
            } else {
                strcpy(biblioteca[i].estado, "Disponible");
                printf("El estado del libro con ID %d se ha cambiado a 'Disponible'.\n", idBuscar);
            }
            return;  
        }
    }
 
    printf("No se encontro ningun libro con ese ID.\n");
}
 
int eliminarLibro(struct Libro biblioteca[], int cantidad) {
    int idEliminar = 0;
    printf("Ingresa el ID del libro a eliminar: ");
    scanf("%d", &idEliminar);  
    getchar();
 
    int encontrado = 0;
    
    for (int i = 0; i < cantidad; i++) {
        if (biblioteca[i].id == idEliminar) {
            
            for (int j = i; j < cantidad - 1; j++) {
                biblioteca[j] = biblioteca[j + 1];
            }
 
           
            cantidad--;
 
            printf("Libro con ID %d eliminado correctamente.\n", idEliminar);
            encontrado = 1;
            break;
        }
    }
 
    if (!encontrado) {
        printf("No se encontro un libro con ese ID.\n");
    }
 
    return cantidad;  
}