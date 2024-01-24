#include <stdio.h>
#include <stdlib.h>

struct Producto
{
    char codigo[25];
    char nombreP[50];
    char descrip[50];
    int cantidad;
    float preciocomp;
};

void Datosproducto(struct Producto *product);
void resultadosproducto(struct Producto *product);
void archivo(struct Producto *producto);

int main(int argc, char const *argv[])
{
    int n;
    printf("Indique la cantidad de productos que desea ingresar:\n");
    scanf("%d", &n);

    struct Producto producto[n];

    for (int i = 0; i < n; i++)
    {
        printf("\nIngrese los datos del producto %d:\n", i + 1);
        Datosprodu(&producto[i]);
    }

    int opc;
    do
    {
        printf("----------MENU----------\n");
        printf("Escoja una opcion:\n");
        printf("1. Mostrar los datos del producto\n");
        printf("2. Imprimir datos en el archivo de texto\n");
        printf("3. Finalizar\n");
        scanf("%d", &opc);

        switch (opc)
        {
        case 1:
            for (int i = 0; i < n; i++)
            {
                printf("Los datos del producto %d son:\n", i + 1);
                resultadosp(&producto[i]);
            }
            break;

        case 2:
            archivo(producto);
            printf("Los datos han sido guardados con exito\n");
            break;

        case 3:
            printf("Cerrando el programa\n");
            break;

        default:
            printf("Opción no válida\n");
        }

    } while (opc != 3);

    return 0;
}
