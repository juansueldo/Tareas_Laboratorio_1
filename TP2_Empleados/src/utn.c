#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int utn_getChar(char* caracter,char* mensaje,char* errorMensaje,char min,char max,int intentos)
{
	int ret = -1;
	char aux;
	char buffer;
	int i;
	if(caracter != NULL &&  mensaje != NULL && errorMensaje != NULL &&  min <= max && intentos >= 0 )
	{

		printf("\n %s \t",mensaje);
		fflush(stdin);
		scanf("%c",&buffer);
		for (i = 0; i < intentos; ++i)
		{
			aux = isdigit(buffer);
			if(buffer >= min && buffer <= max && aux == 0)
			{

				*caracter = buffer;
				ret = 0;
				break;
			}
			else
			{
				printf("\n %s \t",errorMensaje);
				fflush(stdin);
				scanf("\n %c",&buffer);

			}



		}

	}

	return ret;

}
int utn_getString(char array[],int tamanio,char mensaje[],char errorMensaje[],char min,int intentos)
{
	int ret = -1;
	int aux;
	char buffer[tamanio];
	int i;
	if(array != NULL && tamanio > 0 &&  mensaje != NULL && errorMensaje != NULL &&  min <= tamanio && intentos >= 0 )
	{

		printf("\t %s",mensaje);
		printf("\t");
		fflush(stdin);
		gets(buffer);
		for (i = 0; i < intentos; ++i)
		{
			aux = strlen(buffer);

			if(aux >= min && aux <= tamanio)
			{
				strcpy(array,buffer);
				ret = 0;
				break;
			}
			else
			{
				printf("\n %s",errorMensaje);
				fflush(stdin);
				gets(buffer);

			}



		}

	}

	return ret;

}
int esNumerica(char* cadena)
{
	int i=0;
	int ret = 1;
	if(cadena != NULL && strlen(cadena) > 0)
	{
		while(cadena[i] != '\0')
		{
			if(cadena[i] < '0' || cadena[i] > '9')
			{
				ret = 0;
				break;
			}
			i++;
		}
	}
	return ret;
}
int esNumericoFlotante(char str[])
{
   int i=0;
   int cantidadPuntos=0;
   while(str[i] != '\0')
   {
       if (str[i] == '.' && cantidadPuntos == 0)
       {
           cantidadPuntos++;
           i++;
           continue;

       }
       if(str[i] < '0' || str[i] > '9')
           return 0;
       i++;
   }
   return 1;
}

int myGets(char* cadena,int longitud)
{
	if(cadena != NULL && longitud > 0 && fgets(cadena,longitud,stdin) == cadena)
	{
		fflush(stdin);
		if(cadena[strlen(cadena)-1] == '\n')
		{
			cadena[strlen(cadena)-1] = '\0';
		}
		return 0;
	}
	return -1;
}


int getInt(int *pResultado)
{
	int ret = -1;
	char buffer[64];
	if(pResultado != NULL)
	{
		if(myGets(buffer,sizeof(buffer)) == 0 && esNumerica(buffer))
		{
			*pResultado = atoi(buffer);
			ret = 0;
		}
	}
	return ret;
}
int getFloat(float *pResultado)
{
	int ret = -1;
	char buffer[64];
	if(pResultado != NULL)
	{
		if(myGets(buffer,sizeof(buffer)) == 0 && esNumericoFlotante(buffer))
		{
			*pResultado = atof(buffer);
			ret = 0;
		}
	}
	return ret;
}
int utn_getNumero(int* pResultado,char* mensaje,char* mensajeError,int minimo,int maximo,int reintentos)
{
	int bufferInt;
	int ret = -1;
	if(pResultado != NULL && mensaje != NULL && mensajeError != NULL && minimo <= maximo && reintentos > 0)
	{
		while(reintentos > 0)
		{
			reintentos--;
			printf("\n %s \t",mensaje);
			fflush(stdin);
			if(getInt(&bufferInt) == 0)
			{
				if(bufferInt >= minimo && bufferInt <= maximo)
				{
					*pResultado = bufferInt;
					ret = 0;
					break;
				}
			}
			printf("\n %s \t",mensajeError);
		}
	}


	return ret;

}
int utn_getFloat(float* pResultado,char* mensaje,char* mensajeError,float minimo,float maximo,int reintentos)
{
	float bufferFloat;
	int ret = -1;
	if(pResultado != NULL && mensaje != NULL && mensajeError != NULL && minimo <= maximo && reintentos > 0)
	{
		while(reintentos > 0)
		{
			reintentos--;
			printf("\n %s \t",mensaje);
			fflush(stdin);
			if(getFloat(&bufferFloat)==0)
			{
				if(bufferFloat >= minimo && bufferFloat <= maximo)
				{
					*pResultado = bufferFloat;
					ret = 0;
					break;
				}
			}
			printf("\n %s \t",mensajeError);
		}
	}


	return ret;

}
int utn_menu(int *opcion, char *mensaje, char *mensajeError, int min, int max,int salir)
{

	int retorno = -1;
	int bufferMenu;
	if (mensaje != NULL && mensajeError != NULL && min <= max && salir != 0) {
		printf("%s", mensaje);
		scanf("%d", &bufferMenu);

		if (bufferMenu >= min && bufferMenu <= max) {
			*opcion = bufferMenu;
			retorno = 0;
		} else {
			printf("%s", mensajeError);
		}
	}
	return retorno;
}
