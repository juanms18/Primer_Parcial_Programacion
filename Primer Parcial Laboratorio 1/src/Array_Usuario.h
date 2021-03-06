/*
 * Array_Usuario.h
 *
 *  Created on: 14 may. 2022
 *      Author: Juan
 */

#ifndef ARRAY_USUARIO_H_
#define ARRAY_USUARIO_H_
#include "Input.h"

#include "MenuOpciones.h"
#include "Array_Poducto.h"
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>

#define ADMIN 1
#define USUARIO 2
#define FULL 1
#define EMPTY 0
#define BAJA 2
#define CANCELADO -2
#define ENTREGADO -3
#define ENVIAJE -1
#define EMPTYTRACKING -4

typedef struct{
	int idUsuario;
	short int isEmpty;
	short int tipo;
	char correo [40];
	char direccion[50];
	char password[25];
	int codPostal;
}Usuario;

int ingresarComoUsuarioOAdmin(Usuario * eUsuario , int len , Producto * listProducto , int lenProducto , Tracking * listaTracking , int lenTracking);

int buscarCorreoExistenteYPassCorrecta(Usuario * eUsuario , int len , int* indice, int*tipo , int *id);

int initUsuario( Usuario* Usuarios ,int len);

int BuscarPrimerEspacioLibre ( Usuario* listaUsuarios ,int len);

Usuario registrarUnUsuario(int * retorno);

int registrarNuevoUsuario(Usuario * eUsuario , int len);

void hardcodeoUsuarios(Usuario* listaUsuario, int len);

void mostrarUsuario(Usuario listaUsuario);

int printUsuarios (Usuario *list, int len);

void remplazoEstadoPorArrayUsuario(int valor , char * array);

int validarCantidadComprada(int indice , Producto * listaProducto , int lenProducto, Usuario * listaUsuario , int lenUsuario , Tracking * listaTracking , int lenTracking , int idUSUARIO);

int calculoKM(Usuario * listaUsuario , int lenUsuario , Producto * listaProducto , int lenProducto, Tracking * listaTracking , int lenTracking , int indiceProducto , int *km);

void comprar(Producto * listaProductos , int lenProductos , Usuario * listaUsuarios , int lenUsuarios , Tracking * listaTracking , int lenTracking , int idUSUARIO );

int lecturaMenuUsuario(Producto * list , int len , int  idDelUsu , Usuario * listaUsuarios , int lenUsuarios , Tracking * listaTracking , int lenTracking);

long int calculoDeLlegada(int distanciaKM);

void estadoDeCompras(Tracking * listaTracking , int lenTracking, Producto * listaProducto, int lenProducto , int idDelUsuario);

void mostrarUnTracking(int idTracking,  char nombreProducto[] , int estado);

int opcionEstadoDeCompra(Tracking * listaTracking , int lenTracking  );

void listadoDeVentasFinalizadas(Tracking * listaTracking , int lenTracking, Producto * listaProducto, int lenProducto , int idDelUsuario);

void remplazoEstadoPorArrayUsuario(int valor , char * array);

int buscarUsuarioPorID(Usuario * listaUsuario , int lenUsuaio);

void bajaUsuario(Usuario * listaUsuario , int lenUsuaio);

int printUsuariosActivos (Usuario *list, int len);

int inicioMenuAdmin (Usuario * listaUsuario, int lenUsuario , Producto * listaProductos , int lenProducto, Tracking * listaTracking , int lenTracking , int idUsuario );

void mostrarUnTracking2(int idTracking,  int idComprador , int estado , int idVendedor);




#endif /* ARRAY_USUARIO_H_ */
