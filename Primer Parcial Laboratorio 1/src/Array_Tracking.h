/*
 * Array_Tracking.h
 *
 *  Created on: 14 may. 2022
 *      Author: Juan
 */



#ifndef ARRAY_TRACKING_H_
#define ARRAY_TRACKING_H_

#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>


#define EMPTYTRACKING -4
#define CANCELADO -2
#define ENTREGADO -3
#define ENVIAJE -1
typedef struct{
	int idTracking;
	int idPoducto;
	int idUsusario;//vendedor
	int idComprador;
	short int isEmpty;
	int cantidad;
	int distanciaKM;
	long int horaLlegada;
}Tracking;

int initTracking( Tracking *  lista,int len);

int BuscarPrimerEspacioLibreTracking (Tracking * list,int len);

int altaTracking(Tracking * lista , int len, int idProducto , int idUsuario , int cantidadComprada , int km ,int long horaLlegada,int idVendedor);

int buscarTrackigPorID(Tracking * listaTracking , int lenTracking);

void remplazoEstadoPorArray(int valor , char * array);

void hardcodeoDatosTrack(Tracking * listaTracking , int lenTracking);

//void verTrackingGlobal(Tracking * listaTracking , int lenTracking);

#endif /* ARRAY_TRACKING_H_ */
