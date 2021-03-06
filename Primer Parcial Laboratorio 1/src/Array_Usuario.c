/*
 * Array_Usuario.c
 *
 *  Created on: 14 may. 2022
 *      Author: Juan
 */



#include "Array_Usuario.h"


static int obtenerID(void);

static int obtenerID(void)
{

	static int idIncremental = 1010; //poner el numero de id teniendo en cuenta los id hardcodeados
	return idIncremental++;
}


int ingresarComoUsuarioOAdmin(Usuario * eUsuario , int len , Producto * listProducto , int lenProducto , Tracking * listaTracking , int lenTracking)
{

	int indice;
	int tipo;
	int retorno=0;
	int opcionAdmin;
	int llamaFuncion;
	int idDelUsuario;
	if(eUsuario != NULL && len > 0 )
	{
		llamaFuncion=buscarCorreoExistenteYPassCorrecta(eUsuario, len, &indice, &tipo,&idDelUsuario);

		if(llamaFuncion==1)
		{
			if(tipo==USUARIO)
			{

				lecturaMenuUsuario(listProducto, lenProducto, idDelUsuario, eUsuario, len, listaTracking, lenTracking);
			}
			if(tipo==ADMIN)
			{
              inicioMenuAdmin(eUsuario, len, listProducto, lenProducto, listaTracking, lenTracking, idDelUsuario);
			}
			retorno=1;
		}

	}
	return retorno;
}

int buscarCorreoExistenteYPassCorrecta(Usuario * eUsuario , int len , int* indice, int*tipo , int *id)
{
	int i;
	int retorno=0;
	int tomarMail;
	int tomarPass;
	char auxMail[40];
	char auxPassword[25];
	int validarMail=-1;
	int validarPass=-1;


	if(eUsuario != NULL && len > 0 )
	{
		tomarMail=getEmail("Ingrese correo electronico.\n", "ERROR, Ingreso un caracter desconocido\n", "ERROR, Correo demasiado largo\n", auxMail,30, 4);
		tomarPass=getStringAlfanumerico("Ingrese contraseņa.\n", auxPassword, "Contraseņa Incorrecta!!\n", "Contraseņa Incorrecta!!\n", 5, 25);
		if(tomarMail==1 && tomarPass==1)
		{
			for(i=0 ; i<len ; i++)
			{
				validarMail=strcmp(eUsuario[i].correo,auxMail);
				validarPass=strcmp(eUsuario[i].password,auxPassword);
				if(validarMail==0 && validarPass==0)
				{
					*tipo=eUsuario[i].tipo;
					*id=eUsuario[i].idUsuario;
					*indice=i;
					retorno= 1;
					break;
				}
			}

			if(validarMail!=0 && validarPass!=0)
			{
				printf("ERROR al ingresar correo o contraseņa!! Vuelva a intentar!\n");
				system("pause");
			}
		}
	}
	return retorno;
}



int initUsuario( Usuario* listaUsuarios ,int len)
{
   	int retorno = -1;
    int i;

   	if(listaUsuarios != NULL && len > 0)
   	{
   	 retorno=0;
	 for ( i = 0; i < len; i++)
	    {
	     listaUsuarios[i].isEmpty = EMPTY;
	    }
   	}
	return retorno;
}

int BuscarPrimerEspacioLibre ( Usuario* listaUsuarios ,int len)
{
	 int i;
	  int retorno;

	  retorno = -1;

	  if(listaUsuarios != NULL && len > 0)
	  {
	  for (i = 0; i < len; i++)
	    {
		 if (listaUsuarios[i].isEmpty == EMPTY)
		{
		  retorno = i;
		  break;
		}
	    }
	  }
	  return retorno;
}

Usuario registrarUnUsuario(int * retorno)
{

	Usuario auxUsuario;
	int control1;
	int control2;
	int control3;
	int control4;

	{
		control1=getEmail("Ingrese correo electronico.\n", "ERROR, Ingreso un caracter desconocido\n", "ERROR, Correo demasiado largo\n", auxUsuario.correo,40, 4);
		control2=getStringAlfanumerico("Ingrese contraseņa.\n", auxUsuario.password, "Contraseņa Incorrecta!!\n", "Contraseņa Incorrecta!!\n", 5, 25);
		control3=getStringAlfanumerico("Ingrese su direccion.\n", auxUsuario.direccion, "ERROR! Caracteres ingresados no validos!\n", "ERROR! Direccion demasiado extensa!\n", 3, 30);
		control4=getInt(&auxUsuario.codPostal, "Ingrese su codigo postal.\n", "ERROR! Ingrese solo numeros! \n", 0, 10000, 3);

		if(control1==0 || control2==0 || control3 ==0 || control4==0)
		{
			*retorno = 0;
		}
		if(control1==1 && control2==1 && control3==1 && control4==1)
		{
			*retorno=1;
		}
	}
	return auxUsuario;
}

int registrarNuevoUsuario(Usuario * eUsuario , int len)
{
	Usuario auxUsuario;
	int retorno=0;
	int index;
	int validacion;

	index=BuscarPrimerEspacioLibre(eUsuario, len);
	if(index!=-1)
	{
		auxUsuario=registrarUnUsuario(&validacion);
		if(validacion==1)
		{
          auxUsuario.idUsuario=obtenerID();
          auxUsuario.isEmpty=FULL;
          auxUsuario.tipo=USUARIO;
          eUsuario[index]=auxUsuario;
          printf("Usuario cargado con exito!!\nEl numero de ID asignado es:%d\n",eUsuario[index].idUsuario);
          system("pause");
          retorno=1;
		}
		if(validacion==0)
		{
			puts("ERROR AL CARGAR LOS DATOS!!");
			system("pause");
		}
	}
return retorno;
}


void hardcodeoUsuarios(Usuario* listaUsuario, int len)
{
  listaUsuario[0].idUsuario = 1000;
  listaUsuario[1].idUsuario = 1001;
  listaUsuario[2].idUsuario = 1002;
  listaUsuario[3].idUsuario = 1003;
  listaUsuario[4].idUsuario = 1004;
  listaUsuario[5].idUsuario = 1005;
  listaUsuario[6].idUsuario = 1006;
  listaUsuario[7].idUsuario = 1007;
  listaUsuario[8].idUsuario = 1008;
  listaUsuario[9].idUsuario = 1009;

  listaUsuario[0].isEmpty = FULL;
  listaUsuario[1].isEmpty = FULL;
  listaUsuario[2].isEmpty = FULL;
  listaUsuario[3].isEmpty = BAJA;
  listaUsuario[4].isEmpty = FULL;
  listaUsuario[5].isEmpty = FULL;
  listaUsuario[6].isEmpty = BAJA;
  listaUsuario[7].isEmpty = FULL;
  listaUsuario[8].isEmpty = FULL;
  listaUsuario[9].isEmpty = FULL;

  listaUsuario[0].tipo = 1;
  listaUsuario[1].tipo = 1;
  listaUsuario[2].tipo = 2;
  listaUsuario[3].tipo = 2;
  listaUsuario[4].tipo = 2;
  listaUsuario[5].tipo = 2;
  listaUsuario[6].tipo = 2;
  listaUsuario[7].tipo = 2;
  listaUsuario[8].tipo = 2;
  listaUsuario[9].tipo = 2;

  strcpy(listaUsuario[0].correo , "JUAN@HOTMAIL.COM");
  strcpy(listaUsuario[1].correo , "LUCAS12@GMAIL.COM");
  strcpy(listaUsuario[2].correo , "CINDY_@HOTMAIL.COM");
  strcpy(listaUsuario[3].correo , "PACO31@GMAIL.COM");
  strcpy(listaUsuario[4].correo , "LUCIA123@GMAIL.COM");
  strcpy(listaUsuario[5].correo , "MANUEL.-@HOTMAIL.COM");
  strcpy(listaUsuario[6].correo , "UTN12UTN@GMAIL.COM.AR");
  strcpy(listaUsuario[7].correo , "AGENCIA@GMAIL.COM");
  strcpy(listaUsuario[8].correo , "LAURA12_@HOTMAIL.COM");
  strcpy(listaUsuario[9].correo , "PABLO8923@GMAIL.COM");

  strcpy(listaUsuario[0].direccion , "BELGRANO 347");
  strcpy(listaUsuario[1].direccion , "MITRE 132");
  strcpy(listaUsuario[2].direccion , "9 DE JULIO 1487");
  strcpy(listaUsuario[3].direccion , "LAS FLORES 1456");
  strcpy(listaUsuario[4].direccion , "SOLIER 456");
  strcpy(listaUsuario[5].direccion , "PASCO 1245");
  strcpy(listaUsuario[6].direccion , "AV SAN JUAN 456");
  strcpy(listaUsuario[7].direccion , "INDEPENDENCIA 4657");
  strcpy(listaUsuario[8].direccion , "CORRIENTES 322");
  strcpy(listaUsuario[9].direccion , "SANTA FE 1234");

  strcpy(listaUsuario[0].password , "hola123");
  strcpy(listaUsuario[1].password , "lalala");
  strcpy(listaUsuario[2].password , "Manuel464");
  strcpy(listaUsuario[3].password , "utn4789");
  strcpy(listaUsuario[4].password , "programacion12");
  strcpy(listaUsuario[5].password , "python74");
  strcpy(listaUsuario[6].password , "ElMilaneso7456");
  strcpy(listaUsuario[7].password , "karen789");
  strcpy(listaUsuario[8].password , "pitui789");
  strcpy(listaUsuario[9].password , "golGol123");

  listaUsuario[0].codPostal = 1870 ;
  listaUsuario[1].codPostal = 2314 ;
  listaUsuario[2].codPostal = 55 ;
  listaUsuario[3].codPostal =  8012;
  listaUsuario[4].codPostal =  4567;
  listaUsuario[5].codPostal =  4566;
  listaUsuario[6].codPostal =  1872;
  listaUsuario[7].codPostal = 4562 ;
  listaUsuario[8].codPostal = 502 ;
  listaUsuario[9].codPostal =  5678;

}


void mostrarUsuario(Usuario listaUsuario)
{
	char cambio[15];

	 remplazoEstadoPorArrayUsuario(listaUsuario.isEmpty, cambio);

  printf("%d\t%s\t\t%s\n",listaUsuario.idUsuario  ,  listaUsuario.correo ,  cambio);
}


int printUsuarios (Usuario *list, int len)
{
	int retorno = -1;
	puts("**********************************************************************************************************************\n");
	puts("*******************************************LISTADO DE USUARIOS********************************************************\n");
	puts("**********************************************************************************************************************\n");
	puts ("|ID|\t|CORREO|\t\t\t|ESTADO| \n");

	if(list != NULL && len > 0){
		for (int i = 0; i < len; i++)
		{
			if (list[i].isEmpty == FULL || list[i].isEmpty==BAJA)
			{
				mostrarUsuario(list[i]);

				retorno = 0;
			}
		}
	}
	system("pause");
	return retorno;
}

int printUsuariosActivos (Usuario *list, int len)
{
	int retorno = -1;
	puts("**********************************************************************************************************************\n");
	puts("****************************************LISTADO DE USUARIOS ACTIVOS****************************************************\n");
	puts("**********************************************************************************************************************\n");
	puts ("|ID|\t|CORREO|\t\t\t|ESTADO| \n");

	if(list != NULL && len > 0){
		for (int i = 0; i < len; i++)
		{
			if (list[i].isEmpty == FULL)
			{
				mostrarUsuario(list[i]);

				retorno = 0;
			}
		}
	}
	system("pause");
	return retorno;
}

int lecturaMenuUsuario(Producto * list , int len , int idDelUsu , Usuario * listaUsuarios , int lenUsuarios , Tracking * listaTracking , int lenTracking)
{
	int retorno=0;
	int opcionUsuario;
	int resultado;
	int repoStock;
	int opcionMenu;
	if (list != NULL && len > 0)
	{
		do

		{
			menuUsuario(&opcionUsuario);
			switch (opcionUsuario)
			{

			case 1 :
				comprar(list, len, listaUsuarios, lenUsuarios, listaTracking, lenTracking , idDelUsu);
				break;

			case 2 :
				subMenuVender(list, len, idDelUsu, listaUsuarios, lenUsuarios, listaTracking, lenTracking);

				break;

			case 3 :
				estadoDeCompras(listaTracking, lenTracking, list, len, idDelUsu);
				break;

			case 4 :
                    getInt(&resultado, "Seleccione opcion deseada.\n\n1)LISTADO DE VENTAS FINALIZADAS.\n2)VER PRODUCTOS EN STOCK\n", "ERROR!!\N", 1,2, 3);
                    if(resultado==1)
                    {
                    	listadoDeVentasFinalizadas(listaTracking, lenTracking, list, len, idDelUsu);
                    }
                    if(resultado==2)
                    {
                    	printPrductosporUsuario(list, len, idDelUsu);
                    }
				break;

			}
		}while(opcionUsuario!=0);
	}
	return retorno;
}

int subMenuVender(Producto * list , int len , int idDelUsu , Usuario * listaUsuarios , int lenUsuarios , Tracking * listaTracking , int lenTracking)
{
	int retorno;
	int opcion1;
	int validarGet1;
	validarGet1=getInt(&opcion1, "Seleccione la opcion deseada!\n\n1)VENDER NUEVO PRODUCTO.\n2)REPONER STOCK DE UN PRODUCTO.", "ERROR!!! Dato mal ingresado! ", 1,2, 3);
	if(validarGet1==1)
	{
		if(opcion1==1)
		{
			altaProducto(list, len, idDelUsu);
		}
		if(opcion1==2)
		{
			reponerStock(list, len, idDelUsu);
		}
		retorno=1;
	}
	return retorno;
}


void comprar(Producto * listaProductos , int lenProductos , Usuario * listaUsuarios , int lenUsuarios , Tracking * listaTracking , int lenTracking , int idUSUARIO )
{
	int index;
	int validarCompra;

	printPrductosPorCategoria(listaProductos, lenProductos);
    index=buscarPorID(listaProductos, lenProductos);
    if(index==-1)
    {
    	puts("El ID no EXISTE");
    }
    if(index==-2)
    {
    	puts("El ID dado de BAJA");
    }
    if(index != -1 && index !=-2)
    {

     validarCompra=validarCantidadComprada(index, listaProductos, lenProductos, listaUsuarios, lenUsuarios, listaTracking, lenTracking , idUSUARIO  );
      {
    	  if(validarCompra==1)
    	  {
            puts("La compra fue generada correctamente!!");
            system("pause");

    	  }
      }

    }

}

int validarCantidadComprada(int indice , Producto * listaProducto , int lenProducto, Usuario * listaUsuario , int lenUsuario , Tracking * listaTracking , int lenTracking , int idUSUARIO )
{
  	int retorno=0;
  	int cantidadSolicitada;
  	float precioTotal;
  	int cantKM;
  	long int horaDeLlegada;
  	int validarAltaTracking;

	if (listaProducto != NULL && lenProducto > 0 && listaUsuario !=NULL && lenUsuario >0 && listaTracking != NULL && lenTracking > 0 )
	{

		getInt(&cantidadSolicitada, "Ingresae la cantidad de productos que desea comprar.\n", "ERROR! Dato ingresado no valido!\n", 1, 10000, 3);

		if(cantidadSolicitada>listaProducto[indice].stock)
		{

			printf("ERROR! El stock actual del producto es:%d\n",listaProducto[indice].stock);
			system("pause");


		}

		if(cantidadSolicitada==listaProducto[indice].stock) // da de baja el produco 0 stock
		{
			calculoKM(listaUsuario, lenUsuario, listaProducto, lenProducto, listaTracking, lenTracking, indice, &cantKM);
			horaDeLlegada = calculoDeLlegada(cantKM);
			validarAltaTracking = altaTracking(listaTracking, lenTracking, listaProducto[indice].idProducto, idUSUARIO, cantidadSolicitada, cantKM, horaDeLlegada,listaProducto[indice].idUsuario );

			if(cantKM>0 && horaDeLlegada>0 && validarAltaTracking>0 )
			{
				precioTotal = cantidadSolicitada*listaProducto[indice].precio;
				listaProducto[indice].stock = listaProducto[indice].stock - cantidadSolicitada;
				listaProducto[indice].isEmpty = BAJA;
				printf("El precio total a abonar es:%.2f\n" , precioTotal);
				retorno=1;
			}
		}
		if(cantidadSolicitada < listaProducto[indice].stock)

		{

			calculoKM(listaUsuario, lenUsuario, listaProducto, lenProducto, listaTracking, lenTracking, indice, &cantKM);
			horaDeLlegada = calculoDeLlegada(cantKM);
			validarAltaTracking = altaTracking(listaTracking, lenTracking, listaProducto[indice].idProducto, idUSUARIO,  cantidadSolicitada, cantKM, horaDeLlegada , listaProducto[indice].idUsuario);

			if(cantKM>0 && horaDeLlegada>0 && validarAltaTracking>0 )
			{
				precioTotal = cantidadSolicitada*listaProducto[indice].precio;
				listaProducto[indice].stock = listaProducto[indice].stock - cantidadSolicitada;
				printf("El precio total a abonar es:%.2f\n" , precioTotal);
				retorno=1;
			}
		}




	}
	return retorno;
}

int calculoKM(Usuario * listaUsuario , int lenUsuario , Producto * listaProducto , int lenProducto, Tracking * listaTracking , int lenTracking , int indiceProducto , int *km)
{

	int i;
	int retorno=-1;
	int distancia1=20;
	int distancia2=30;
	int distancia3=50;
	int distancia4=80;
	int distancia5=150;


	if(listaProducto != NULL && lenProducto > 0 && listaUsuario != NULL && lenUsuario > 0 && listaTracking != NULL && lenTracking > 0 )
	{
		for(i=0 ; i < lenUsuario ; i++)
		{
			if(listaProducto[indiceProducto].idUsuario==listaUsuario[i].idUsuario)
			{
				retorno=i;
				if(listaUsuario[i].codPostal > 0 && listaUsuario[i].codPostal <= 1000)
				{
					*km = distancia1;
				}
				if(listaUsuario[i].codPostal > 1000 && listaUsuario[i].codPostal <= 3000)
				{
					*km = distancia2;
				}
				if(listaUsuario[i].codPostal > 3000 && listaUsuario[i].codPostal <= 5000)
				{
					*km = distancia3;
				}
				if(listaUsuario[i].codPostal > 5000 && listaUsuario[i].codPostal <= 8000)
				{
					*km = distancia4;
				}
				if(listaUsuario[i].codPostal > 8000 && listaUsuario[i].codPostal <= 9999)
				{
					*km = distancia5;
				}
				retorno = i; //indice del usuario

			}
		}
	}
	return retorno;
}


long int calculoDeLlegada(int distanciaKM)
{

	int segundosTranscurridos;
	long int tiempoDeEntrega;
	long int tiempoDeCompra;
	long int retorno=0;
	if(distanciaKM >= 1)
	{
		tiempoDeCompra = time(NULL);
		segundosTranscurridos = distanciaKM * 20;
		tiempoDeEntrega = tiempoDeCompra + segundosTranscurridos;
		retorno = tiempoDeEntrega;
	}
	return retorno;
}

void estadoDeCompras(Tracking * listaTracking , int lenTracking, Producto * listaProducto, int lenProducto , int idDelUsuario)
{

	int indiceProducto;
	int indiceTracking;

	if(listaProducto != NULL && lenProducto > 0 && listaTracking != NULL && lenTracking > 0 )
	{
		printf("|ID TRACKING|\t|NOMBRE DEL PRODUCTO|\t\t|ESTADO DEL PRODUCTO|\n\n");
		for(indiceProducto=0; indiceProducto<lenTracking; indiceProducto++ )
		{
			for(indiceTracking=0; indiceTracking<lenTracking; indiceTracking++)
			{
				if(listaTracking[indiceTracking].idUsusario==idDelUsuario && listaTracking[indiceTracking].idPoducto==listaProducto[indiceProducto].idProducto)
				{
					mostrarUnTracking(listaTracking[indiceTracking].idTracking , listaProducto[indiceProducto].nombreProducto, listaTracking[indiceTracking].isEmpty );
				}

			}
		}
		opcionEstadoDeCompra(listaTracking, lenTracking);


	}
}

void mostrarUnTracking(int idTracking,  char nombreProducto[] , int estado)
{
	char charFinal[15];

	remplazoEstadoPorArray(estado,charFinal);

  	printf("%d\t\t\t%s\t\t%s\t\n",idTracking ,nombreProducto , charFinal);
}

int opcionEstadoDeCompra(Tracking * listaTracking , int lenTracking  )
{
	int opcion;
	int idTrackingSeleccionado;

	int retorno=0;
	printf("1)Dar de baja 1 producto que este en VIAJE.\n");
	printf("2) Salir.\n");
	getInt(&opcion,"Ingrese la opcion solicitada.\n" , "ERROR",1, 2, 3);

	if(opcion==2)
	{
		return opcion;
	}
	if(opcion==1)
	{
		idTrackingSeleccionado  =  buscarTrackigPorID(listaTracking, lenTracking);

		if( idTrackingSeleccionado >= 0   )
		{
			listaTracking[idTrackingSeleccionado].isEmpty=CANCELADO;
			printf("El Tracking fue cancelado correctamente!!\n");
			retorno = 1;

		}
		if(idTrackingSeleccionado==-4)
		{
			printf("El Tracking no Existe!!\n");
		}
		if(idTrackingSeleccionado==-2)
		{
			printf("El Tracking fue CANCELADO con anterioridad\n");
		}
		if(idTrackingSeleccionado==-3)
		{
			printf("El Tracking ya fue ENTREGADO");
		}

	}
return retorno;
}


int estadoDeVentas()
{

}

void listadoDeVentasFinalizadas(Tracking * listaTracking , int lenTracking, Producto * listaProducto, int lenProducto , int idDelUsuario)
{
	int indiceProducto;
	int indiceTracking;
	printf("|ID TRACKING|\t|NOMBRE DEL PRODUCTO|\t\t|ESTADO DEL PRODUCTO|\n\n");
	for(indiceProducto=0; indiceProducto<lenTracking; indiceProducto++ )
	{
		for(indiceTracking=0; indiceTracking<lenTracking; indiceTracking++)
		{
			if(listaTracking[indiceTracking].idComprador==idDelUsuario && listaTracking[indiceTracking].idPoducto==listaProducto[indiceProducto].idProducto && listaTracking[indiceTracking].isEmpty==CANCELADO &&  listaTracking[indiceTracking].isEmpty==ENTREGADO)
			{
				mostrarUnTracking(listaTracking[indiceTracking].idTracking , listaProducto[indiceProducto].nombreProducto, listaTracking[indiceTracking].isEmpty );
			}

		}
	}

}


int inicioMenuAdmin (Usuario * listaUsuario, int lenUsuario , Producto * listaProductos , int lenProducto, Tracking * listaTracking , int lenTracking , int idUsuario )
{
	int opcionAdmin;

	menuAdmin(&opcionAdmin);

	while(opcionAdmin!=0)
	{
		if(opcionAdmin==1)
		{
			printUsuarios(listaUsuario, lenUsuario);
			menuAdmin(&opcionAdmin);
		}
		if(opcionAdmin==2)
		{
			ordenarPorCategoria(listaProductos, lenProducto);
			printPrductosPorCategoria(listaProductos, lenProducto);
			system("pause");
			menuAdmin(&opcionAdmin);

		}
		if(opcionAdmin==3)
		{
			ordenarPorCategoria(listaProductos, lenProducto);
			printPrductosPorCategoria(listaProductos, lenProducto);
			system("pause");
			bajaProducto(listaProductos, lenProducto);
			menuAdmin(&opcionAdmin);
		}
		if(opcionAdmin==4)
		{

			printUsuariosActivos(listaUsuario, lenUsuario);
			bajaUsuario(listaUsuario, lenUsuario);
			menuAdmin(&opcionAdmin);
		}
		if(opcionAdmin==5)
		{
          listadoDeTrackingGlobal(listaTracking, lenTracking, listaProductos, lenProducto, idUsuario);
          menuAdmin(&opcionAdmin);
		}
		if(opcionAdmin==6)
		{
          filtrarPorNombre(listaProductos, lenProducto);
          menuAdmin(&opcionAdmin);
		}
	}
}

void remplazoEstadoPorArrayUsuario(int valor , char * array)

{
   if(valor==FULL)
   {
	   strcpy(array,"ACTIVO");
   }

   if(valor==BAJA)
   {
	   strcpy(array,"DADO DE BAJA");
   }
}

void bajaUsuario(Usuario * listaUsuario , int lenUsuaio)
{
	int indice;
	indice = buscarUsuarioPorID(listaUsuario, lenUsuaio);
	if(indice==-2)
	{
		printf("EL USUARIO FUE DADO DE BAJA ANTERIORMENTE\n");
	}
	if(indice==-1)
	{
		printf("EL PRODUCTO NO EXISTE");
	}
	if(indice>=0)
	{
		listaUsuario[indice].isEmpty=BAJA;
	}

}

int buscarUsuarioPorID(Usuario * listaUsuario , int lenUsuaio)
{
	int retorno=-1;
	int idSeleccionado;
	int i;
	if (listaUsuario != NULL && lenUsuaio > 0)
	{
		getInt(&idSeleccionado, "Seleccione el ID del usuario deseado\n", "ERROR!! Dato ingresado desconocido!\n",100, 10000, 3);

		for (i = 0; i < lenUsuaio; i++)
		{
			if (listaUsuario[i].idUsuario == idSeleccionado && listaUsuario[i].isEmpty == FULL)
			{
				retorno=i;
				break;
			}
			if(listaUsuario[i].idUsuario== idSeleccionado && listaUsuario[i].isEmpty == BAJA)
			{
				retorno=-2;
				break;
			}
		}

	}
	return retorno;
}

void listadoDeTrackingGlobal(Tracking * listaTracking , int lenTracking, Producto * listaProducto, int lenProducto , int idDelUsuario)
{
	int indiceProducto;
	int indiceTracking;
	printf("|ID TRACKING|\t|ID COMPRADOR|\t\t|ESTADO DEL PRODUCTO|\t\t|ID VENDEDOR|\n\n");
	for(indiceTracking=0; indiceTracking<lenTracking; indiceTracking++)
	{
		if(listaTracking[indiceTracking].isEmpty == ENTREGADO & listaTracking[indiceTracking].isEmpty == CANCELADO && listaTracking[indiceTracking].isEmpty == ENVIAJE);
		{
			mostrarUnTracking2(listaTracking[indiceTracking].idTracking , listaTracking[indiceTracking].idComprador, listaTracking[indiceTracking].isEmpty,listaTracking[indiceTracking].idUsusario );
		}

	}
	system("pause");
}


void mostrarUnTracking2(int idTracking,  int idComprador , int estado , int idVendedor)
{
	char charFinal[15];

	remplazoEstadoPorArray(estado,charFinal);

  	printf("%d\t\t\t%d\t\t%s\t\%d\n",idTracking , idComprador , charFinal , idVendedor);
}
