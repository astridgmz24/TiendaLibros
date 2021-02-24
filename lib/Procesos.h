#include <stdio.h>
#include <string.h>
#include <locale.h> 
#include <stdlib.h>
//Declaracion de funciones
    void showProducts(const char **,const int *,int, int);
    void addBasket(int *);
    void showBasket(const char **,const int *,int *);
    int removeBasket(int *, int);
    int getContadorProductos();
    int totalCompra(const int *, int *);
    int buscarArreglo(const int *, int);
    int contadorProductos=0;
    int ConfiguraIdioma();
    int Portada();
/*------------------------------------------------------------------------------------------------------------------------*/
int Portada () 
{
	printf("				Universidad Nacional Aut�noma de M�xico \n");
	printf("				Facultad de Estudios Superiores Acatl�n \n");
	printf("				Lic. Matem�ticas Aplicadas y Computaci�n\n\n");
	
	printf("								Programaci�n I \n");
	printf("								1104	 MAC \n");
	printf("								Equipo No. 2 \n\n");
	
	
	
	printf("			    				Proyecto Final \n\n"); 
		printf(" 					Garc�a Soto Alejandro \n");
		printf(" 					G�mez Gonz�lez Astrid Yoatziry \n");
		printf(" 					Maldonado Escamilla Jennifer \n");
		printf(" 					Mej�a Espinosa Rub�n Alan \n");
		printf(" 					P�rez Romero Jonathan \n\n\n");
	system ("Pause"); 
}

/*-------------------------------------------------------------------------------------------------------------------------*/
int ConfiguraIdioma()
{
	//Cambia al idioma Espa�ol   
	struct lconv *lcPtr;
	setlocale(LC_ALL, "spanish");
	lcPtr = localeconv();

	//Configura cantidades para M�xico
	lcPtr->decimal_point = ".";
	lcPtr->thousands_sep = ",";
	lcPtr->grouping = "3";		
}

/*--------------------------------------------------------------------------------------------------------------------------
											Mostrar un producto*/
void showProducts(const char **nombreProducto, const int *precioProducto, int categoriaInicio, int categoriaFinal){
    int i;
    for(i=categoriaInicio; i<categoriaFinal;i++)
	{
        printf("\n\t %d) %s:",i+1,nombreProducto[i]);
        printf(" -- $ %d", precioProducto[i]);
    }

    printf("\n\n");
}

/*--------------------------------------------------------------------------------------------------------------------------
											A�adir al carrito*/
void addBasket(int *agregarCanasta)
{
    scanf("%d", &agregarCanasta[contadorProductos]);
    contadorProductos++;
}

/*--------------------------------------------------------------------------------------------------------------------------
											Mostrar Carrito*/
void showBasket(const char **nombreProducto,const int *precioProducto,int *productoAgregado)
{
        int i;
        for(i=0; i<contadorProductos;i++)
        {
        	printf("\t%d. %s - $ %d\n",i+1,nombreProducto[productoAgregado[i]-1], precioProducto[productoAgregado[i]-1]);
		}
}
            
/*-------------------------------------------------------------------------------------------------------------------------
										Eliminar articulo del carrito*/
int removeBasket(int *eliminarDeCanasta, int eliminarCarrito)
{
    int i;
    for(i=0; i<contadorProductos;i++)
	{
        if(i==eliminarCarrito-1)
		{
            while(i<contadorProductos)
			{
                eliminarDeCanasta[i]= eliminarDeCanasta[i+1];
                i++;
            }
        	contadorProductos=contadorProductos-1;
        	return 1;
        }
    }
    return -1;
}

/*--------------------------------------------------------------------------------------------------------------------------
												Total de productos*/
int getContadorProductos()
{
    return contadorProductos;
}

/*-------------------------------------------------------------------------------------------------------------------------
												Total Compra*/
int totalCompra(const int *precioProducto,int *productoAgregado)
{
    int i,total=0;
    for(i=0; i<getContadorProductos();i++)
	{
        total+= precioProducto[productoAgregado[i]-1];
    }
    return total;
}

int buscarArreglo(const int *codigosPostales, int clave)
{
    int i;
    for(i=0; i<10; i++)
	{
        if(codigosPostales[i]==clave)
        {
        	return 1;
        }
    }
    return -1;         
}
