/*
 * Array_Tracking.c
 *
 *  Created on: 14 may. 2022
 *      Author: Juan
 *
 */

#include "Array_Tracking.h"


static int ObtenerIDTracking(void);


static int ObtenerIDTracking(void) {

	static int idIncremental = 6; //segun hardcodeo
	return idIncremental++;
}


int initTracking( Tracking *  lista,int len)
{
   	int retorno = -1;
    int i;

   	if(lista != NULL && len > 0)
   	{
   	 retorno=0;
	 for ( i = 0; i < len; i++)
	    {
	     lista[i].isEmpty = EMPTYTRACKING;
	    }
   	}
	return retorno;
}


int BuscarPrimerEspacioLibreTracking (Tracking * lista,int len)
{
	  int i;
	  int retorno=-1;

	  if(lista != NULL && len > 0)
	  {
	  for (i = 0; i < len; i++)
	    {
		 if (lista[i].isEmpty == EMPTYTRACKING)
		{
		  retorno = i;
		  break;
		}
	    }
	  }
	  return retorno;
}

int altaTracking(Tracking * lista , int len, int idProducto , int idUsuario , int cantidadComprada , int km ,int long horaLlegada , int idVendedor)
{
	int indice;
	int retorno=0;
	Tracking auxTracking;
	if(lista != NULL && len > 0)
	{
		indice=BuscarPrimerEspacioLibreTracking(lista, len);
		if(indice!=-1)
		{
			auxTracking.idTracking = ObtenerIDTracking();
			auxTracking.idPoducto = idProducto;
			auxTracking.isEmpty = ENVIAJE;
			auxTracking.cantidad = cantidadComprada;
			auxTracking.distanciaKM=km;
			auxTracking.horaLlegada=horaLlegada;
			auxTracking.idUsusario=idUsuario;
			auxTracking.idComprador=idVendedor;
			lista[indice]= auxTracking;
			printf("Tracking dado de alta correctamente!!El numero de ID asignado es:%d\n",lista[indice].idTracking);
			//printf("El numero de ID asignado es usuraior:%d\n",lista[indice].idUsusario);
			//printf("El numero de ID asignado esprdicdas:%d\n",lista[indice].idPoducto);
			retorno=1;

		}

 	}
return retorno;
}




int buscarTrackigPorID(Tracking * listaTracking , int lenTracking)
{
	int retorno=-5;
	int idSeleccionado;
	int i;
	if (listaTracking != NULL && lenTracking > 0)
	{
		getInt(&idSeleccionado, "Seleccione el ID del producto deseado\n", "ERROR!! Dato ingresado desconocido!\n",1, 10000, 3);

		for (i = 0; i < lenTracking; i++)
		{
			if (listaTracking[i].idTracking == idSeleccionado && listaTracking[i].isEmpty == ENVIAJE)
			{
				retorno=i;
				break;
			}
			if(listaTracking[i].idTracking == idSeleccionado && listaTracking[i].isEmpty == CANCELADO)
			{
				retorno=CANCELADO;
				break;
			}
			if(listaTracking[i].idTracking == idSeleccionado && listaTracking[i].isEmpty == ENTREGADO)
			{
				retorno=ENTREGADO;
			}

		}

	}
	return retorno;
}

void remplazoEstadoPorArray(int valor , char * array)

{



   if(valor==CANCELADO)
   {
	   strcpy(array,"CANCELADO");
   }

   if(valor==ENTREGADO)
   {
	   strcpy(array,"ENTREGADO");
   }

   if(valor==ENVIAJE)
   {
	   strcpy(array,"EN VIAJE A DESTINO");
   }


}

void hardcodeoDatosTrack(Tracking * listaTracking , int lenTracking)
{
	listaTracking[0].cantidad = 1;
	listaTracking[1].cantidad = 2;
	listaTracking[2].cantidad = 2;
	listaTracking[3].cantidad = 1;
	listaTracking[4].cantidad = 1;

	listaTracking[0].distanciaKM= 20;
	listaTracking[1].distanciaKM= 30;
	listaTracking[2].distanciaKM= 50;
	listaTracking[3].distanciaKM= 80;
	listaTracking[4].distanciaKM= 20;

	listaTracking[0].horaLlegada= 1231321321;
	listaTracking[1].horaLlegada= 1231321321;
	listaTracking[2].horaLlegada= 1231321321;
	listaTracking[3].horaLlegada= 1231321321;
	listaTracking[4].horaLlegada= 1231321321;

	listaTracking[0].idComprador= 1001;
	listaTracking[1].idComprador= 1001;
	listaTracking[2].idComprador= 1002;
	listaTracking[3].idComprador= 1004;
	listaTracking[4].idComprador= 1001;

	listaTracking[0].idPoducto= 102;
	listaTracking[1].idPoducto= 100;
	listaTracking[2].idPoducto= 100;
	listaTracking[3].idPoducto= 101;
	listaTracking[4].idPoducto= 103;

	listaTracking[0].idTracking = 5;
	listaTracking[1].idTracking = 1;
	listaTracking[2].idTracking = 2;
	listaTracking[3].idTracking = 3;
	listaTracking[4].idTracking = 4;

	listaTracking[0].idUsusario = 1001;
	listaTracking[1].idUsusario = 1000;
	listaTracking[2].idUsusario = 1002;
	listaTracking[3].idUsusario = 1001;
	listaTracking[4].idUsusario = 1000;

	listaTracking[0].isEmpty = CANCELADO;
	listaTracking[1].isEmpty = ENVIAJE;
	listaTracking[2].isEmpty = ENTREGADO;
	listaTracking[3].isEmpty = ENVIAJE;
	listaTracking[4].isEmpty = ENVIAJE;

}


/*void verTrackingGlobal(Tracking * listaTracking , int lenTracking)
{
	int i;
	printf("|ID TRACKING|\t\t|ESTADO|\t\t|ID COMPRADOR|\t\t|ID VENDEDOR|\n");
	for(i=0; i<lenTracking ; i++)
	{
		printf("%d\t\t%d\t\t%d\t\t%d\n",listaTracking[i].idTracking , listaTracking[i].isEmpty , listaTracking[i].idComprador , listaTracking[i].idUsusario);
	}
}*/


