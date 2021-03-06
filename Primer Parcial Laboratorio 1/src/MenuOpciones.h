/*
 * MenuOpciones.h
 *
 *  Created on: 15 may. 2022
 *      Author: Juan
 */

#ifndef MENUOPCIONES_H_
#define MENUOPCIONES_H_




/// @fn int menuIngreso(int*)
/// @brief imprime un menu pidiendo opciones y retorna la opcion solicitada
/// @param opcionIngresada puntero donde se guarda la opcion ingresada
/// @return retorna 0 si no pudo guardar dato y 1 si lo guardo correctamente
int menuIngreso(int * opcionIngresada);

/// @fn int menuUsuario(int*)
/// @brief imprime un menu pidiendo opciones y retorna la opcion solicitada
/// @param opcionIngresada puntero donde se guarda la opcion ingresada
/// @return retorna 0 si no pudo guardar dato y 1 si lo guardo correctamente
int menuUsuario(int * opcionIngresada);


/// @fn int menuAdmin(int*)
/// @brief imprime un menu pidiendo opciones y retorna la opcion solicitada
/// @param opcionIngresada puntero donde se guarda la opcion ingresada
/// @return retorna 0 si no pudo guardar dato y 1 si lo guardo correctamente
int menuAdmin(int * opcionIngresada);


#endif /* MENUOPCIONES_H_ */
