/*
 * utn_calculos.h
 *
 *  Created on: 5 abr. 2021
 *      Author: operador
 */

#ifndef UTN_CALCULOS_H_
#define UTN_CALCULOS_H_

int utn_menu (int* opcion, char* mensaje,char* mensajeError, int min, int max, int salir);
int utn_getSuma (int operador1, int operador2, int*resultado,char*mensaje);
int utn_getResta (int operador1, int operador2, int*resultado,char*mensaje);
int utn_getMultiplicar (int operador1, int operador2, int*resultado,char*mensaje);
float utn_getDividir (int operador1, int operador2, float* retorno);
int utn_getFactorial (int operador1, int operador2, char*mensaje);

#endif /* UTN_CALCULOS_H_ */
