#include <stdio.h>
#define n_productos 10

int main()
{
    char nombres[n_productos][100] = {0};
    float precios[n_productos] = {0.0};
    int stock[n_productos] = {0};
    float promediostock = 0;
    char itemcaro = 0;
    char itembarato = 0;
    int opc = 0;
    int opc1 = 0;
    int contproductos = 0;

    do
    {
        printf("Seleccione una opcion:\n");
        printf("1. Registrar productos:\n");
        printf("2. Mostrar productos\n");
        printf("3. Mostrar informacion de la tienda\n");
        printf(">> ");
        scanf("%d", &opc1);
        switch (opc1)
        {
        case 1:
            float totalstockglobal = 0;
            if (contproductos <= n_productos)
            {
                printf("Ingrese el nombre del producto %d: \n", contproductos);
                scanf("%s", nombres[contproductos]);
                printf("Ingrese el precio del producto %d: \n", contproductos);
                scanf("%f", &precios[contproductos]);
                printf("Ingrese el stock del producto %d: \n", contproductos);
                scanf("%d", &stock[contproductos]);
                contproductos++;
                
                for (int i = 0; i <contproductos; i++)
                {
                    totalstockglobal += precios[i] * stock[i];
                }

                promediostock = totalstockglobal / contproductos;
            }
            else
            {
                printf("No se pueden registrar mas productos\n");
                break;
            }

            for (int i = 0; i < contproductos; i++)
            {
                if (precios[i] > precios[itemcaro])
                {
                    itemcaro = i;
                }
                if (precios[i] < precios[itembarato])
                {
                    itembarato = i;
                }
            }

            break;
        case 2:
            int productosregistrados = 0;
            printf("Productos registrados:\n");
            for (int i = 0; i < contproductos; i++)
            {
                printf("%d. %s \n", i + 1, nombres[i]);
            }
            printf("Seleccione el producto que desea ver: \n");
            scanf("%d", &productosregistrados);
            for (int i = 0; i < contproductos; i++)
            {
                if (productosregistrados == i + 1)
                {
                    printf("Nombre: %s\n", nombres[i]);
                    printf("Precio: %.2f $\n", precios[i]);
                    printf("Stock: %d\n", stock[i]);
                    printf("Total: %.2f $\n", precios[i] * stock[i]);
                }
            }
            if (productosregistrados < 1 || productosregistrados > contproductos)
            {
                printf("No existe el producto\n");
            }
            break;
        case 3:
            printf("Informacion de la tienda:\n");
            printf("Total de productos: %d\n", contproductos);
            printf("Promedio de stock: %.2f $\n", promediostock);
            printf("Producto mas caro: %s\n", nombres[itemcaro]);
            printf("Producto mas barato: %s\n", nombres[itembarato]);
            printf("Total de stock global: %.2f $\n", totalstockglobal);
            break;
        default:
            printf("No existe la opcion\n");
            break;
        }
        if (opc != 3)
        {
            printf("Desea seleccionar otra opcion? 1.Si/2.No: \n");
            scanf("%d", &opc);
        }
    } while (opc == 1);
}