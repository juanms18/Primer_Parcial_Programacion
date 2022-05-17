/*
 * Array_Poducto.h
 *
 *  Created on: 14 may. 2022
 *      Author: Juan
 */

#ifndef ARRAY_PODUCTO_H_
#define ARRAY_PODUCTO_H_


#include "Array_Tracking.h"


#define FULL 1
#define EMPTY 0
#define BAJA 2
#define ELECTRODOMESTICOS 1
#define ELECTRONICA 2
#define CELULARES 3
#define AUDIO 4


typedef struct{
	int idProducto;
	short int isEmpty;
    int idUsuario;
	char nombreProducto[25];
	float precio;
	short int categoria;
	int stock;
}Producto;


void hardcodeoProductos(Producto* listaProductos, int len);

int initProductos( Producto* listaProductos,int len);

void mostrarProducto(Producto listaProductos);

int printPrductosporUsuario(Producto *list, int len, int idUsuario);

int printPrductos(Producto *list, int len);

void ordenarPorCategoria(Producto *list, int len);

void remplazaOrden(Producto* list , int posicionA , int posicionB);

void remplazoCategoriaAStr(int valor , char * array);

int buscarPorID(Producto * list , int len);

int BuscarPrimerEspacioLibreProducto (Producto *list,int len);

int altaProducto(Producto * listaProducto , int lenProducto , int idDelUsiario);

Producto altaUnProducto(int * retorno);

#endif /* ARRAY_PODUCTO_H_ */
