/*
 * MenuOpciones.c
 *
 *  Created on: 15 may. 2022
 *      Author: Juan
 */

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>

#include "Input.h"

int menuIngreso(int * opcionIngresada)

{
	int leerOpcion;
    int retorno=0;
    int datoIngresado;
  	puts("***************************");
	puts("** 1er EXAMEN LAB I - H ***");
	puts("***************************\n");
	puts("1) INGRESAR");
	puts("2) REGISTRARSE\n");
	puts("0) SALIR");

	leerOpcion = getInt(&datoIngresado, "Ingrese  una opcion del menu.\n",	"Cuidado!! --> La opcion ingresada no es valida!!\n", 0, 2, 3);

	if(leerOpcion==0)
	{
		puts("ERROR! Opcion  mal ingresada!!\n");
		system("pause");
	}
	if(leerOpcion==1)
	{
		*opcionIngresada=datoIngresado;
		retorno=1;
	}
	return retorno;
}

int menuUsuario(int * opcionIngresada)
{
	int leerOpcion;
	int retorno=0;
	int datoIngresado;
	puts("***************************");
	puts("** 1er EXAMEN LAB I - H ***");
	puts("********* USUARIO *********");
	puts("***************************\n");
	puts("1) COMPRAR");
	puts("2) VENDER");
	puts("3) ESTADO DE COMPRAS");
	puts("4) ESTADO DE VENTAS\n");
	puts("0) SALIR\n");

	leerOpcion = getInt(&datoIngresado, "Ingrese  una opcion del menu.\n",	"Cuidado!! --> La opcion ingresada no es valida!!\n", 0, 4, 3);

	if(leerOpcion==0)
	{
		puts("ERROR! Opcion  mal ingresada!!\n");
		system("pause");
	}
	if(leerOpcion==1)
	{
		*opcionIngresada=datoIngresado;
		retorno=1;
	}
	return retorno;
}


int menuAdmin(int * opcionIngresada)
{
	int leerOpcion;
	int retorno=0;
	int datoIngresado;
	puts("***************************");
	puts("** 1er EXAMEN LAB I - H ***");
	puts("********* *ADMIN* *********");
	puts("***************************\n");
	puts("1) LISTAR ESTADO DE TODOS LOS USUARIOS");
	puts("2) LISTAR TODOS LOS PRODUCTOS POR CATEGORIA");
	puts("3) BAJA DE UN PRODUCTO");
	puts("4) BAJA DE UN USUARIO");
	puts("5) VER TRACKING GLOBAL");
	puts("6) FILTRAR POR NOMBRE DE PRODUCTO\n");
	puts("0) SALIR\n");

	leerOpcion = getInt(&datoIngresado, "Ingrese  una opcion del menu.\n",	"Cuidado!! --> La opcion ingresada no es valida!!\n", 0, 6, 3);

	if(leerOpcion==0)
	{
		puts("ERROR! Opcion  mal ingresada!!\n");
		system("pause");
	}
	if(leerOpcion==1)
	{
		*opcionIngresada=datoIngresado;
		retorno=1;
	}
	return retorno;
}
