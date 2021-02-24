#include "../lib/Procesos.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_PRODUCTOS 50
#define MAX_ARTICULOS 50

//Declaracion de funciones
	void anadirCanasta(); //103
	void mostarProductos(int, int); //110
	void verCanasta(); //131
	void eliminarCanasta(); //151
	void canastaVacia(); //188
	void procesarCompra(); //326
	void pedirDatosUsuario(char *, char *, char *, char *, char *, int *); //395
	void procesarPago(); //422
	void datosTarjeta(); //455
	void pagoTransferencia(); //484
    void pagoOxxo(); //549
    void paypal(); //562
	//menus
	void menuGeneral(); //197
	void menuCategorias(); //240
	void menuSecundario(); //292

/*-------------------------------------------------------------------------------------------------------------------------
										Lista de productos de la tienda*/

const char *nombreProductos[NUM_PRODUCTOS]=
		//libros de estudio
{"LOGICA DE PROGRAMACION",
"JAVA 2 CURSO DE PROGRAMACION",
"PROGRAMACION EN JAVA 6",
"COMO PROGRAMAR EN C++",
"INTELIGENCIA MATEMATICA",
"EL ARTE DE LAS MATEMATICAS",
"MECANICA DE MATERIALES",
"INGENIERIA MECANICA. DINAMICA",
"INGENIERIA MECANICA ESTATICA",
"INTELIGENCIA ARTIFICIAL",
		//libros de ciencia ficcion
"RASTRO",
"SOLO ES UN RUMOR",
"WALLUM",
"LEGEND",
"CIELO ROJO",
"DESPUES DE LA NIEVE",
"PLAY 1",
"REVELACIONES",
"ENCLAVE",
"SUBTERRANEOS",
		//libros clasicos
"EL PRINCIPITO",
"LA ODISEA",
"EL LAZARILLO DE TORMES",
"FRANKENSTEIN",
"ROMEO Y JULIETA",
"HAMLET",
"ROBIN HOOD",
"EL DIARIO DE ANA FRANK",
"EL QUIJOTE DE LA MANCHA",
"LA ILIADA",
		//libros de terror y misterio
"EL MUNDO HOBBIT",
"EL ROSTRO DE SARA",
"FIESTA DE FANTASMAS",
"ZOMBIS",
"POPOL VUH",
"EVERFOUND",
"ANA VESTIDA DE SANGRE",
"BEOWULF",
"SEVERIANA",
"JUEGO MORTAL",
		//libros de romance
"PERO A TU LADO",
"TEMBLOR",
"DELIRIUM",
"LEGEND",
"SI ESTUVIERAS AQUI",
"LA ULTIMA LAGRIMA",
"EL CHICO MALO",
"SOLO ESCUCHA",
"FANGIRL",
"AFTER"};

/*-------------------------------------------------------------------------------------------------------------------------
										Precios de los productos*/
										
const int precioProductos[NUM_PRODUCTOS]= {495,473,501,1093,356,525,378,304,320,302, 222, 119, 174, 297, 109, 262, 299, 375, 285, 183, 77, 29, 61, 44, 105,43, 128,
    104, 120, 69, 143, 168,228, 169, 428, 254, 236, 125, 241, 320, 268, 159, 384, 164, 249, 254, 124, 312, 276, 165};
    

/*-------------------------------------------------------------------------------------------------------------------------
											Codigos Postales*/
											
const int codigosPostales[10]= {10580, 10630, 52374, 78526, 41259, 74126, 32598, 23658, 45698, 12357};

/*------------------------------------------------------------------------------------------------------------------------
								Inicializacion de la lista de articulos*/				
int listaArticulos[MAX_ARTICULOS]={0};

/*------------------------------------------------------------------------------------------------------------------------
										Añadir articulo a canasta*/
void anadirCanasta()
{
    addBasket(listaArticulos);
}

/*------------------------------------------------------------------------------------------------------------------------
									Mostrar los productos de la tienda*/
void mostarProductos(int incioCategoria, int finCategoria)
{
    int numElementos,i=0;
    system("cls");
    showProducts(nombreProductos,precioProductos,incioCategoria,finCategoria);

    printf("Indica cuantos articulos te gustaria agregar a tu canasta o -1 para no agregar ningun articulo: ");
    scanf(" %d", &numElementos);

    while(i<numElementos)
	{
        printf("Ingresa numero del articulo: ");
        anadirCanasta();
        i++;
    }
    menuSecundario();
}

/*-------------------------------------------------------------------------------------------------------------------------
												Ver Carrito*/
void verCanasta()
{
    
    if(getContadorProductos()==0)
	{
        system("cls");
        canastaVacia();
    }
    else
	{
        system("cls");
        showBasket(nombreProductos, precioProductos, listaArticulos);
    }
        
        system("pause");
        menuSecundario();
}

/*--------------------------------------------------------------------------------------------------------------------------
										Eliminar elemmento del carrito*/
void eliminarCanasta()
{
    int eliminar;
    char respuesta;
    do
	{
	    system("cls");
	    
	    if(getContadorProductos()==0)
		{
        	canastaVacia();
    	}
		else
		{
        	showBasket(nombreProductos, precioProductos, listaArticulos);
	        printf("\n\tQue articulo te gustaria eliminar: ");
    	    scanf("%d", &eliminar);

       		if(removeBasket(listaArticulos, eliminar)>=1)
       		{
       			printf("\n\tArticulo eliminado exitosamente\n\n");
			}
        	else
        	{
        		printf("\n\tEl elemento no se encuentra en tu lista\n\n");
			}
    	}
        system("pause");
        system("cls");
    	showBasket(nombreProductos, precioProductos, listaArticulos);
        printf("\n\tTe gustaria eliminar otro articulo? (S/N): ");
        scanf(" %c", &respuesta);
    } while(respuesta=='s');
    
    menuSecundario();
}

/*-------------------------------------------------------------------------------------------------------------------------
												Carrito Vacio*/
void canastaVacia()
{
    printf("\n\tTu Canasta esta vacia, agrega algunos articulos\n\n");
    system("pause");
    menuGeneral();
}

/*------------------------------------------------------------------------------------------------------------------------
												Menu Principal*/
void menuGeneral()
{
    int opc;
    system("cls");
    
    printf("\n\t\tBienvenido a 'Libreria Gringotts'\n\n");
    printf("\t1. Visitar la tienda\n");
    printf("\t2. Ver carrito de compras\n");
    printf("\t3. Remover articulo\n");
    printf("\t4. Procesar compra\n");
    printf("\t5. Salir de la tienda\n\n");
    printf("\tIngresa la opcion deseada: ");
    
    scanf("%d",&opc);

    while(opc<0 || opc>5)
	{
    	printf("\tIngresa una opcion valida: ");
    	scanf("%d",&opc);
    }

    switch(opc)
	{
        case 1:
            menuCategorias();
            break;
        case 2:
            verCanasta(); 
            break;
        case 3:
            eliminarCanasta();
            break;
        case 4:
            procesarCompra();
            break;
        case 5:
            exit(1);
            break;
    }
}

/*-------------------------------------------------------------------------------------------------------------------------
														Categorias*/
void menuCategorias()
{
    int opc;
    system("cls");
    
    printf("\n\t\tCategorias\n\n");
    printf("\t ¿Que estas buscando?\n");
    printf("\t1. Libros de estudio\n");
    printf("\t2. Libros de ciencia ficcion\n");
    printf("\t3. Libros clasicos\n");
    printf("\t4. Libros de terror y misterio\n");
    printf("\t5. Libros de romance\n\n");
    printf("\tIngresa la opcion deseada: ");

    scanf("%d",&opc);
    
    while(opc<0 || opc>5)
	{
   		printf("\tIngresa una opcion valida: ");
   		scanf("%d",&opc);
    }

    switch(opc)
	{
        case 1:
            printf("\n\t\tLibros de estudio\n\n");
            mostarProductos(0,10);
            break;
        case 2:
            printf("\n\t\tLibros de ciencia ficcion\n\n");
            mostarProductos(10,20);
            break;
        case 3:
            printf("\n\t\tLibros clasicos\n\n");
            mostarProductos(20,30);
            break;
        case 4:
            printf("\n\t\tLibros de terror y misterio\n\n");
            mostarProductos(30,40);
            break;
        case 5:
            printf("\n\t\tLibros de romance\n\n");
            mostarProductos(40,50);
            break;
        default: 
            printf("\n\tCategoria no encontrada\n");
            break;
    }
}

/*-------------------------------------------------------------------------------------------------------------------------
												Menu secundario */
void menuSecundario()
{
    system("cls");
    int opc;
    
    printf("\n\t\t ¿Que te gustaria hacer?\n\n");
    printf("\t1. Regresar al menu principal\n");
    printf("\t2. ver mas libros\n");
    printf("\t3. Procesar compra\n\n");
    printf("\tIngresa la opcion deseada: ");
    scanf("%d",&opc);

    while(opc<0 || opc>3)
	{
    	printf("\tIngresa una opcion valida: ");
    	scanf("%d",&opc);
    }

    switch(opc)
	{
        case 1:
            menuGeneral();
            break;
        case 2:
            menuCategorias();
            break;
        case 3:
            procesarCompra();
            break;
    }
}

/*-------------------------------------------------------------------------------------------------------------------------
												Procesar Compra*/
void procesarCompra()
{
    char nombreCliente[40],direccion[30], colonia[30], estado[30], ciudad[30];
    int cp, totalApagar=0, i;
    float iva;
    char respuesta;
    
    system("cls");
    
    if(getContadorProductos()==0)
	{
        system("cls");
        canastaVacia();
    }
	else
	{
        pedirDatosUsuario(nombreCliente, direccion, colonia, estado, ciudad, &cp);

        if(buscarArreglo(codigosPostales, cp)>=1)
	    {

            switch(cp){

                case 10580:
                case 10630:
                    totalApagar= 79;
                    break;
                case 52374:
                case 78526:
                    totalApagar= 89;
                    break;
                case 41259:
                case 74126:
                    totalApagar= 99;
                    break;
                case 32598: 
                case 23658:
                    totalApagar= 109;
                    break;
                case 45698:
                case 12357:
                    totalApagar= 119;
                    break;
            }
        }
        else
	    {
        printf("\tPor el momento no es posible hacer envios en tu localidad\n\n");
        printf("\tTe gustaria ingresar otra direccion (S/N): ");
        scanf(" %c", &respuesta);
        if(respuesta=='s')
        {
         	procesarCompra();
		}
        else
		{
            printf("\n\tGracias por visitar Libreria Gringotts, vuelve pronto\n\n");
            system("pause");
            exit(1);
        }
    }
    system("cls");
        printf("\n\n\tArticulos en tu canasta\n\n");
	    showBasket(nombreProductos, precioProductos, listaArticulos);
	    
	    printf("\n\tEl total de tus productos: %d \n", totalCompra(precioProductos, listaArticulos));
        iva= totalCompra(precioProductos, listaArticulos) *0.16;
        printf("\tIVA: %.2f \n", iva);
	    printf("\tEl costo de envio a tu domicilio es: %d \n", totalApagar);
	    printf("\tTotal a pagar: %.2f \n\n", (totalCompra(precioProductos, listaArticulos)+totalApagar + iva));
	    
	    system("pause");
	    procesarPago();
	    system("cls");
	    printf("\n\n\tSe enviaran los siguientes articulos: \n\n");
	    
	    for(i=0;i<getContadorProductos();i++)
	    {
	    	printf("\t%d. %s \n",i+1,nombreProductos[listaArticulos[i]-1]);
		}
	
	    printf("\n\n\tSeran enviados a la siguiente direccion: \n\n");
	    printf("\tPara: %s \n \t%s \n \t%s \n \t%s \n \t%s \n \t%d \n", nombreCliente,direccion,colonia,estado,ciudad,cp);
	    printf("\n\tGracias %s por comprar en libreria Gringotts\n", nombreCliente);
	    printf("\tQue tengas una buena semana\n\n");
    }
    system("pause");
    exit(1);
}

/*-------------------------------------------------------------------------------------------------------------------------
											Datos para Envio*/
											
void pedirDatosUsuario(char *nombreCliente, char *direccion, char *colonia, char *estado, char *ciudad, int *cp)
{
    printf("\n\n\tIngresa los datos de envio\n\n");
    fflush(stdin);
    printf("\tNombre / Quien recibe: ");
    gets(nombreCliente);

    printf("\tDireccion (calle, numero de casa o interior, torre, empresa): ");
    gets(direccion);

    fflush(stdin);
    printf("\tColonia: ");
    gets(colonia);
    
    printf("\tEstado: ");
    gets(estado);

    fflush(stdin);
    printf("\tCiudad: ");
    gets(ciudad);

    printf("\tSe hacen envios a los siguientes codigos postales:\n 10580, 10630, 52374, 78526, 41259, 74126, 32598, 23658, 45698, 12357\n");
    printf("\tCP: ");
    scanf("%d", cp);
}

/*-------------------------------------------------------------------------------------------------------------------------
											Metodo de pago*/
void procesarPago()
{
    int respuestaPago;
    system("cls");
    printf("\n\n\tMetodo de pago\n\n");
    printf("\t1. Pago con tarjeta de credito\n");
    printf("\t2. Pago con tarjeta de debito\n");
    printf("\t3. Pago en efectivo\n");
    printf("\t4. Paypal\n");
    printf("\t5. Pago en OXXO\n");
    printf("\t6. Transferencia bancaria\n");
    printf("\tSelecciona el metodo de pago: ");
    scanf("%d", &respuestaPago);
    
    while(respuestaPago<1 || respuestaPago>6)
	{
        printf("\tIngresa una opcion valida: ");
        scanf("%d", &respuestaPago);
    }

    switch(respuestaPago){

        case 1:
            datosTarjeta();
            printf("\n\tPago realizado con exito\n");
            break;
        case 2: 
            datosTarjeta();
            printf("\n\tPago realizado con exito\n");
            break;
        case 3:
            system("cls");
            printf("\n\tTu paquete sera enviado a tu domicilio, ten a la mano la cantidad exacta que pagaras\n\tya que nuestros repartidores no manejan efectivo\n");
            break;
        case 4:
        	paypal();
        	printf("\n\tPago realizado con exito\n");
            break;
        case 5:
            pagoOxxo();
            printf("\n\tTan pronto como sea recibido tu pago se procedera con el envio\n");
            break;
        case 6:
            pagoTransferencia();
            printf("\tTan pronto como sea recibido tu pago se procedera con el envio\n");
            break;
    }



    system("pause");

}

/*-------------------------------------------------------------------------------------------------------------------------
												Datos de la tarjeta*/
void datosTarjeta()
{
    char tarjeta[17];
    int mes,anio,codSeguridad;
    do
	{
	    system("cls");
	    printf("\n\n\tIngresa los 16 digitos de tu targeta (credito/debito): ");
	    fflush(stdin);
	    gets(tarjeta);
	    
	    if(strlen(tarjeta) !=16)
		{
	        printf("\tTarjeta invalida ");
	        system("pause");
	    }  
		 
    }while(strlen(tarjeta) !=16);

    fflush(stdin);
    printf("\tIngresa la fecha de vencimiento (MM): ");
    scanf("%d", &mes);
    printf("\tIngresa la fecha de vencimiento (YY): ");
    scanf("%d", &anio);

    printf("\tIngresa el codigo de seguridad: ");
    scanf("%d", &codSeguridad);
}

/*-------------------------------------------------------------------------------------------------------------------------
								Datos para transferencia Bancaria*/
void pagoTransferencia()
{
    system("cls");
    printf("\n\n\tBeneficiario: Libreria Gringotts S.A de C.V\n");
    printf("\tBanco: BBVA Bancomer\n");
    printf("\tNúmero de cuenta: 1542 7896 3215 7851\n");
    printf("\tNúmero de sucursal: 4638\n");
    printf("\tCuenta CLABE: 012 180 0044 3010597 1\n");
    printf("\tABB: BCMRMXMMPYM\n\n");
    printf("\tLos pagos por transferencia bancaria pueden tomar de 2 a 3 dias habiles\n");
}

/*-------------------------------------------------------------------------------------------------------------------------
								Datos para pago en OXXO*/
void pagoOxxo()
{
    printf("\n\n\tPago por OXXO");
    srand(time(NULL));
    system("cls");
    printf("\n\tDepositar a la siguiente cuenta bancaria: 1542 7896 3215 7851\n");
    int referenciaUsuario= 123654 + rand() % 12365478;
    printf("\tTu referencia para el pago es: %d\n\n", referenciaUsuario);
    printf("\tEsta ficha de pago tiene una vigencia de 3 dias apartir del dia de hoy\n\trecuerda que tus pagos en oxxo los podras realizar de 8am a 8pm todos los dias del año");
}

/*-------------------------------------------------------------------------------------------------------------------------
										Paypal*/
void paypal()
{
	char correo_pay[50], contra_pay[50];
	
	system("cls");
	printf("\n\n\tPago por Paypal");
	
	printf("\nIngresa tu correo electrónico: ");
	fflush(stdin);
	gets (correo_pay);
	
	printf("\nIngresa tu contraseña: ");
	fflush(stdin);
	gets(contra_pay);	
}

/*-------------------------------------------------------------------------------------------------------------------------
												MAIN*/
int main()
{
	ConfiguraIdioma();
	Portada();
    menuGeneral();
    system("pause");
    return 0;
}
