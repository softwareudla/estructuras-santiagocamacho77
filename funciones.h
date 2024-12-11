struct Libro {
    int id;
    char titulo[100];
    char autor[50];
    int anio;
    char estado[12];
};
 
 
int mostrarMenu();
void agregarLibro(struct Libro biblioteca[], int cantidad);
void mostrarListaLibros(struct Libro biblioteca[], int cantidad);
void buscarPorId(struct Libro biblioteca[]);
void buscarPorTitulo(struct Libro biblioteca[]);
void actualizarEstadoLibro(struct Libro biblioteca[]);
int eliminarLibro(struct Libro biblioteca[], int cantidad);