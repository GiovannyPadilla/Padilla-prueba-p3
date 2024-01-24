#include <stdio.h>
#include <stdlib.h>

struct Producto
{
    char codigo[25];
    char nombreP[50];
    char descripcion[50];
    int cantidad;
    float preciocomp;
};

void Datosprodu(struct Producto *producto);
void resultadosp(struct Producto *producto);
void archivo(struct Producto *productos);

int main()
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
        printf("\n");
        printf("Escoja una opcion:\n");
        printf("\n");
        printf("1. Mostrar los datos del producto\n");
        printf("\n");
        printf("2. Imprimir datos en el archivo de texto\n");
        printf("\n");
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
            printf("Datos guardados en el archivo\n");
            break;

        case 3:
            printf("Finalizando \n");
            break;

        default:
            printf("Opción no valida.\n");
        }

    } while (opc != 3);

    return 0;
}

void Datosprodu(struct Producto *producto)
{
    printf("Codigo:\n");
    scanf("%s", producto->codigo);

    printf("Nombre del producto:\n");
    scanf("%s", producto->nombreP);

    printf("Descripcion:\n");
    scanf("%s", producto->descripcion);

    printf("Cantidad:\n");
    scanf("%d", &producto->cantidad);

    printf("Precio de compra:\n");
    scanf("%f", &producto->preciocomp);
}

void resultadosp(struct Producto *producto)
{
    printf("Codigo: %s\n", producto->codigo);
    printf("Nombre del producto: %s\n", producto->nombreP);
    printf("Descripcion: %s\n", producto->descripcion);
    printf("Cantidad: %d\n", producto->cantidad);
    printf("Precio de compra: %.2f\n", producto->preciocomp);
}

int num;
void archivo(struct Producto *productos)
{
    FILE *archivo;
    archivo = fopen("productos.txt", "w");

    if (archivo == NULL)
    {
        printf("Error al abrir el archivo.\n");
        
    }
    
    for (int i = 0; i < num; i++)
    {
        fprintf(archivo, "********************************\n");
        fprintf(archivo, "Datos del producto %d:\n", i + 1);
        fprintf(archivo, "Codigo del producto: %s\n", productos[i].codigo);
        fprintf(archivo, "Nombre del producto: %s\n", productos[i].nombreP);
        fprintf(archivo, "Descripcion del producto: %s\n", productos[i].descripcion);
        fprintf(archivo, "Cantidad de producto: %d\n", productos[i].cantidad);
        fprintf(archivo, "Precio de la compra: %.2f\n", productos[i].preciocomp);
    }

    fclose(archivo);
}
