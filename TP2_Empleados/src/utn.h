/*
 * utn.h
 *
 *  Created on: 10 may. 2021
 *      Author: operador
 */

#ifndef UTN_H_
#define UTN_H_

int utn_getChar(char* caracter,char* mensaje,char* errorMensaje,char min,char max,int intentos);
int utn_getString(char array[],int tamanio,char mensaje[],char errorMensaje[],char min,int intentos);
int esNumerica(char* cadena);
int myGets(char* cadena,int longitud);
int getInt(int *pResultado);
int getFloat(float *pResultado);
int utn_getNumero(int* pResultado,char* mensaje,char* mensajeError,int minimo,int maximo,int reintentos);
int utn_getFloat(float* pResultado,char* mensaje,char* mensajeError,float minimo,float maximo,int reintentos);
int utn_menu(int *opcion, char *mensaje, char *mensajeError, int min, int max,int salir);
int esNumericoFlotante(char str[]);



#endif /* UTN_H_ */
