/*
 * Array_Producto.c
 *
 *  Created on: 14 may. 2022
 *      Author: Juan
 */
#include "Array_Poducto.h"


static int obtenerIDProducto(void);

static int obtenerIDProducto(void)
{

	static int idIncremental = 110; //poner el numero de id teniendo en cuenta los id hardcodeados
	return idIncremental++;
}

void hardcodeoProductos(Producto* listaProductos, int len)
{
   listaProductos[0].idProducto = 100;
   listaProductos[1].idProducto = 101;
   listaProductos[2].idProducto = 102;
   listaProductos[3].idProducto = 103;
   listaProductos[4].idProducto = 104;
   listaProductos[5].idProducto = 105;
   listaProductos[6].idProducto = 106;
   listaProductos[7].idProducto = 107;
   listaProductos[8].idProducto = 108;
   listaProductos[9].idProducto = 109;

   listaProductos[0].isEmpty = FULL;
   listaProductos[1].isEmpty = FULL;
   listaProductos[2].isEmpty = FULL;
   listaProductos[3].isEmpty = FULL;
   listaProductos[4].isEmpty = FULL;
   listaProductos[5].isEmpty = FULL;
   listaProductos[6].isEmpty = FULL;
   listaProductos[7].isEmpty = FULL;
   listaProductos[8].isEmpty = FULL;
   listaProductos[9].isEmpty = FULL;

   listaProductos[0].idUsuario = 1003;
   listaProductos[1].idUsuario = 1004;
   listaProductos[2].idUsuario = 1001;
   listaProductos[3].idUsuario = 1003;
   listaProductos[4].idUsuario = 1002;
   listaProductos[5].idUsuario = 1005;
   listaProductos[6].idUsuario = 1005;
   listaProductos[7].idUsuario = 1005;
   listaProductos[8].idUsuario = 1007;
   listaProductos[9].idUsuario = 1001;

   strcpy(listaProductos[0].nombreProducto , "CAFETERA");
   strcpy(listaProductos[1].nombreProducto , "LICUADORA");
   strcpy(listaProductos[2].nombreProducto , "NOKIA 1100");
   strcpy(listaProductos[3].nombreProducto , "CAFETERA");
   strcpy(listaProductos[4].nombreProducto , "BATIDORA");
   strcpy(listaProductos[5].nombreProducto , "TV LED 32");
   strcpy(listaProductos[6].nombreProducto , "SAMSUNG S22");
   strcpy(listaProductos[7].nombreProducto , "MONITOR 22");
   strcpy(listaProductos[8].nombreProducto , "CAFETERA");
   strcpy(listaProductos[9].nombreProducto , "AURICULARES");

   listaProductos[0].precio = 2542.25 ;
   listaProductos[1].precio = 1356.40;
   listaProductos[2].precio =  1200;
   listaProductos[3].precio = 8501.32;
   listaProductos[4].precio = 5300.65;
   listaProductos[5].precio = 7400;
   listaProductos[6].precio = 9809.99;
   listaProductos[7].precio = 3500;
   listaProductos[8].precio = 9900;
   listaProductos[9].precio = 1000;

   listaProductos[0].categoria = ELECTRODOMESTICOS ;
   listaProductos[1].categoria = ELECTRODOMESTICOS;
   listaProductos[2].categoria = CELULARES;
   listaProductos[3].categoria = ELECTRONICA;
   listaProductos[4].categoria = ELECTRODOMESTICOS;
   listaProductos[5].categoria = ELECTRONICA;
   listaProductos[6].categoria = CELULARES;
   listaProductos[7].categoria = ELECTRONICA;
   listaProductos[8].categoria = CELULARES;
   listaProductos[9].categoria = AUDIO;

   listaProductos[0].stock = 10;
   listaProductos[1].stock = 15;
   listaProductos[2].stock = 12;
   listaProductos[3].stock = 4;
   listaProductos[4].stock = 15;
   listaProductos[5].stock = 8;
   listaProductos[6].stock = 120;
   listaProductos[7].stock = 132;
   listaProductos[8].stock = 12;
   listaProductos[9].stock = 300;

}

int initProductos( Producto* listaProductos,int len)
{
   	int retorno = -1;
    int i;

   	if(listaProductos != NULL && len > 0)
   	{
   	 retorno=0;
	 for ( i = 0; i < len; i++)
	    {
	     listaProductos[i].isEmpty = EMPTY;
	    }
   	}
	return retorno;
}




int printPrductos(Producto *list, int len)
{
	int retorno = -1;
	puts("**********************************************************************************************************************\n");
	puts("*******************************************LISTADO DE PRODUCTOS*******************************************************\n");
	puts("**********************************************************************************************************************\n");
	puts ("|ID|\t\t|NOMBRE DEL PRODUCTO|\t|PRECIO|\t|CATEGORIA|\t\t|STOCK|\t\n");

	if(list != NULL && len > 0){
		for (int i = 0; i < len; i++)
		{
			if (list[i].isEmpty == FULL)
			{
				mostrarProducto(list[i]);

				retorno = 0;
			}
		}
	}
	system("pause");
	return retorno;
}

int printPrductosporUsuario(Producto *list, int len, int idUsuario)
{
	int retorno = -1;
	puts("**********************************************************************************************************************\n");
	puts("*******************************************LISTADO DE PRODUCTOS*******************************************************\n");
	puts("**********************************************************************************************************************\n");
	puts ("|ID|\t\t|NOMBRE DEL PRODUCTO|\t|PRECIO|\t|CATEGORIA|\t\t|STOCK|\t\n");

	if(list != NULL && len > 0){
		for (int i = 0; i < len; i++)
		{
			if (list[i].isEmpty == FULL && list[i].idUsuario==idUsuario)
			{
				mostrarProducto(list[i]);

				retorno = 0;
			}
		}
	}
	system("pause");
	return retorno;
}



int printPrductosPorCategoria(Producto *list, int len)
{
	int retorno = -1;
	puts("**********************************************************************************************************************\n");
	puts("*******************************************LISTADO DE PRODUCTOS*******************************************************\n");
	puts("**********************************************************************************************************************\n");
	puts ("|ID|\t\t|NOMBRE DEL PRODUCTO|\t|PRECIO|\t  |CATEGORIA|\t\t|STOCK|\t\n");

	if(list != NULL && len > 0){
		for (int i = 0; i < len; i++)
		{
			if (list[i].isEmpty == FULL)
			{
				ordenarPorCategoria(list, len);
				mostrarProducto(list[i]);

				retorno = 0;
			}
		}
	}

	return retorno;
}


void ordenarPorCategoria(Producto *list, int len)
{
	int j;
	int estaOrdenado;
	int i;
	if (list != NULL && len > 0){
		do
		{
			estaOrdenado=0;
			j=0;
			for(i=0; i<len; i++)
			{
				if(list[i].isEmpty==FULL)
				{
					for(j=i+1; j<len; j++)
					{
						if(list[j].isEmpty==FULL)
						{

							if(list[i].categoria < list[j].categoria)
							{
								estaOrdenado=1;
								remplazaOrden(list, i, j);
								break;
							}
							else
							{
								if(list[i].categoria < list[j].categoria)
								{
									estaOrdenado=1;
									remplazaOrden(list, i, j);
									break;
								}
							}

						}
					}
				}
			}
			len--;
		}while (estaOrdenado==1);
	}
}



void remplazaOrden(Producto* list , int posicionA , int posicionB)
{
	Producto auxilarProducto;
	auxilarProducto = list[posicionA];
	list[posicionA]=list[posicionB];
	list[posicionB]=auxilarProducto;
}

void remplazoCategoriaAStr(int valor , char * array)

{
	if(valor==ELECTRODOMESTICOS)
	{
		strcpy(array,"ELECTRODOMESTICOS");

	}

	if(valor==ELECTRONICA)
	{
		strcpy(array,"ELECTRONICA       ");
	}

	if(valor==CELULARES)
	{
		strcpy(array,"CELULARES          ");
	}
	if(valor==AUDIO)
	{
		strcpy(array,"AUDIO              ");
	}


}




int buscarPorID(Producto * list , int len)
{
	int retorno=-1;
	int idSeleccionado;
	int i;
	if (list != NULL && len > 0)
	{
		getInt(&idSeleccionado, "Seleccione el ID del producto deseado\n", "ERROR!! Dato ingresado desconocido!\n",100, 10000, 3);

		for (i = 0; i < len; i++)
		{
			if (list[i].idProducto == idSeleccionado && list[i].isEmpty == FULL)
			{
				retorno=i;
				break;
			}
			if(list[i].idProducto == idSeleccionado && list[i].isEmpty == BAJA)
			{
				retorno=-2;
				break;
			}
		}

	}
	return retorno;
}



int BuscarPrimerEspacioLibreProducto (Producto *list,int len)
{
	  int i;
	  int retorno;

	  retorno = -1;

	  if(list != NULL && len > 0)
	  {
	  for (i = 0; i < len; i++)
	    {
		 if (list[i].isEmpty == EMPTY)
		{
		  retorno = i;
		  break;
		}
	    }
	  }
	  return retorno;
}

int altaProducto(Producto * listaProducto , int lenProducto , int idDelUsiario)
{
	Producto auxProducto;
	int retorno=0;
	int index;
	int validacion;

	index=BuscarPrimerEspacioLibreProducto(listaProducto, lenProducto);
	if(index!=-1)
	{
		auxProducto = altaUnProducto(&validacion);
		if(validacion==1)
		{
			auxProducto.idProducto=obtenerIDProducto();
			auxProducto.isEmpty=FULL;
			auxProducto.idUsuario=idDelUsiario;
			listaProducto[index]=auxProducto;
			printf("Poducto cargado con exito!! Listo para su venta!! \nEl numero de ID asignado es:%d\n",listaProducto[index].idProducto);
			system("pause");
			retorno=1;
		}
	}
}

int reponerStock(Producto * listaProducto , int lenProducto , int idDelUsuario)
{
	Producto auxProducto;
	int retorno=0;
	int index;
	int cantidadAReponer;
	int control;
	printPrductosporUsuario(listaProducto, lenProducto, idDelUsuario);
	index=buscarPorID(listaProducto, lenProducto);
	control=getInt(&cantidadAReponer, "Ingrese la cantida de Stock que desa reponer", "ERROR!!Dato mal ingresado!!\n", 1, 10000, 3);
	if(control==1)
	{
		listaProducto[index].stock = listaProducto[index].stock +  cantidadAReponer;
		retorno = 1;
	}
return retorno;
}

Producto altaUnProducto(int * retorno)
{
	Producto auxProducto;
	int control1;
	int control2;
	int control3;
	int control4;
	control1 = getInt(&auxProducto.categoria, "Ingrese la categoria correspondiente.\n1) ELECTRODOMESTICOS.\n2)ELECTRONICA\n3)CELULARES.\n4)AUDIO\n", "ERROR! Opcion incorrecta!\n", 1, 4, 3);
	control2 = getStringAlfanumerico("Ingrese nombre del producto.\n", auxProducto.nombreProducto, "ERROR! Caracter desconocido!\n", "ERROR! Nombre muy largo!\n", 3, 25);
	control3 = getStringNumerosFlotantes("Ingrese el precio del paroducto.\n", "ERROR! Precio desconocido!",&auxProducto.precio , 3);
	control4 = getInt(&auxProducto.stock, "Ingrese el stock del producto.\n", "ERROR! Caracteres desconocidos\n", 1, 10000, 3);
	if(control1==0 || control2==0 || control3 ==0 || control4==0)
			{
				*retorno = 0;
			}
			if(control1==1 && control2==1 && control3==1 && control4==1)
			{
				*retorno=1;
			}
			return  auxProducto;
		}


void bajaProducto(Producto * listaProducto , int lenProducto)
{
	int indice;
	indice = buscarPorID(listaProducto, lenProducto);
	if(indice==-2)
	{
		printf("EL PRODUCTO FUE DADO DE BAJA ANTERIORMENTE\n");
	}
	if(indice==-1)
	{
		printf("EL PRODUCTO NO EXISTE");
	}
	if(indice>=0)
	{
		listaProducto[indice].isEmpty=BAJA;
	}

}

int filtrarPorNombre(Producto * listaProducto, int lenProducto)
{
	char nombreIngresado[25];
	int i;
	int validarChar;
	int retorno=0;

	validarChar=getStringAlfanumerico("Ingrese el nombre del producto a buscar.\n", nombreIngresado, "ERROR!! Ingreso algun caracter desconocido!\n", "ERROR! Nombre demaciado largo.\n", 3, 25);

	if(validarChar==1)
	{
		ordenarPorStock(listaProducto, lenProducto);
		convertirEnMayuscula(nombreIngresado, 25);
		printf("| ID |\t\t| NOMBRE |\t\t| PRECIO |\t\t| STOCK DISPONIBLE|\n");
		for(i=0 ; i<lenProducto ; i++)
		{
			if(strcmp(listaProducto[i].nombreProducto , nombreIngresado)==0 )
			{
				mostrarProducto(listaProducto[i]);
				retorno=1;

			}
		}
	}
	system("pause");
	return retorno;
}

void mostrarProducto(Producto listaProductos)
{
	char categoria [20];
	remplazoCategoriaAStr(listaProductos.categoria, categoria);
	printf("%d\t\t%s\t\t%.2f\t\t%s\t%d\n",listaProductos.idProducto  , listaProductos.nombreProducto, listaProductos.precio,categoria , listaProductos.stock);
}

void ordenarPorStock(Producto *list, int len)
{
	int j;
	int estaOrdenado;
	int i;
	if (list != NULL && len > 0){
		do
		{
			estaOrdenado=0;
			j=0;
			for(i=0; i<len; i++)
			{
				if(list[i].isEmpty==FULL)
				{
					for(j=i+1; j<len; j++)
					{
						if(list[j].isEmpty==FULL)
						{

							if(list[i].stock < list[j].stock)
							{
								estaOrdenado=1;
								remplazaOrden(list, i, j);
								break;
							}
							else
							{
								if(list[i].stock < list[j].stock)
								{
									estaOrdenado=1;
									remplazaOrden(list, i, j);
									break;
								}
							}

						}
					}
				}
			}
			len--;
		}while (estaOrdenado==1);
	}
}
