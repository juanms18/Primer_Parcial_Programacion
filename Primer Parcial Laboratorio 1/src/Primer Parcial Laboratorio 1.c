/*
 ============================================================================
 Name        : Primer.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>

#include "Input.h"
#include "MenuOpciones.h"
#include "Array_Poducto.h"
#include "Array_Tracking.h"
#include "Array_Usuario.h"
#define CANTIDADDEUSUARIOS 1000
#define CANTIDADDEPRODUCTOS 1000
#define CANTIDADDETRACKING 5

int main(void) {
	setbuf (stdout, NULL);

	int opcionMenuIngreso;

	Usuario Usuarios[CANTIDADDEUSUARIOS];
	Producto Productos[CANTIDADDEPRODUCTOS];
	Tracking eTracking[CANTIDADDETRACKING];

	initTracking(eTracking, CANTIDADDETRACKING);
	initUsuario(Usuarios, CANTIDADDEUSUARIOS);
	initProductos(Productos, CANTIDADDEPRODUCTOS);
	hardcodeoUsuarios(Usuarios, CANTIDADDEUSUARIOS);
	hardcodeoProductos(Productos, CANTIDADDEPRODUCTOS);
	 hardcodeoDatosTrack(eTracking, CANTIDADDETRACKING);




	if(menuIngreso(&opcionMenuIngreso)==1)
	{
		while(opcionMenuIngreso!=0)
		{
			if(opcionMenuIngreso==1)
			{
				ingresarComoUsuarioOAdmin(Usuarios, CANTIDADDEUSUARIOS, Productos, CANTIDADDEPRODUCTOS, eTracking, CANTIDADDETRACKING);
				menuIngreso(&opcionMenuIngreso);
			}
			if(opcionMenuIngreso==2)
			{
				registrarNuevoUsuario(Usuarios, CANTIDADDEUSUARIOS);
				menuIngreso(&opcionMenuIngreso);
			}
		}

	}

	return EXIT_SUCCESS;

}
