#include "utn.h"

int Validate_OnlyNumberInt(char *pData) {
	int rtn = 1;

	if (strlen(pData) > 0) {
		for (int i = 0; i < strlen(pData); i++) {
			if (isdigit(pData[i]) == 0) {
				if (i == 0) {
					if (pData[0] != '-') {
						rtn = 0;
						break;
					}
				} else {
					rtn = 0;
					break;
				}
			}
		}
	} else {
		rtn = 0;
	}

	return rtn;
}

int Validate_OnlyNumberFloat(char *pData) {
	int countSigno = 0;
	int rtn = 1;

	if (strlen(pData) > 0) {
		for (int i = 0; i < strlen(pData); i++) {

			if (pData[i] == '.' || pData[i] == ',') {
				countSigno++;
			} else {
				if (isdigit(pData[i]) == 0) {
					if (i == 0) {
						if (pData[0] != '-') {
							rtn = 0;
							break;
						}
					} else {
						rtn = 0;
						break;
					}
				}
			}
		}

		if (countSigno > 1) {
			rtn = 0;
		}
	} else {
		rtn = 0;
	}

	return rtn;
}

int Validate_OnlyAlphabet(char *pData) {
	int rtn = 1;

	if (strlen(pData) > 0) {
		for (int i = 0; i < strlen(pData); i++) {
			if (isalpha(pData[i]) == 0) {
				rtn = 0;
				break;
			}
		}
	} else {
		rtn = 0;
	}

	return rtn;
}

int Validate_OnlyAlphabetWithSpaces(char *pData) {
	int rtn = 1;

	if (strlen(pData) > 0) {
		for (int i = 0; i < strlen(pData); i++) {
			if (isalpha(pData[i]) == 0) {
				if (isspace(pData[i]) == 0) {
					rtn = 0;
					break;
				}
			}
		}
	} else {
		rtn = 0;
	}

	return rtn;
}
int utn_getTexto (char *pData)
{
	int rtn = 1;
	int i;
	if (strlen(pData) > 0)
	{
		for (i = 0; i < strlen(pData); i++)
		{
		if (isalpha(pData[i]) == 0)
		{
			rtn = 0;
			break;
		}
		}
	}
	else
	{
		rtn = 1;
	}

	return rtn;
}
int utn_getChar(char* caracter,char* mensaje,char* errorMensaje,char min,char max,int intentos)
{
	int ret = -1;
	char aux;
	char buffer;
	int i;
	if(caracter != NULL &&  mensaje != NULL && errorMensaje != NULL &&  min <= max && intentos >= 0 )
	{

		printf("\n %s",mensaje);
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
				printf("\n %s",errorMensaje);
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
		printf("\n%s",mensaje);
		fflush(stdin);
		gets(buffer);

		for (i = 0; i < intentos; ++i)
		{
			if(utn_getTexto (buffer) != 0)
			{
			aux = strlen(buffer);

			if(aux >= min && aux <= tamanio)
			{
				strcpy(array,buffer);
				ret = 0;
				break;
			}
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
int utn_getIsInt(char* cadena)
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
int utn_getIsFloat(char str[])
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


int utn_getEntero(int *pResultado)
{
	int ret = -1;
	char buffer[64];
	if(pResultado != NULL)
	{
		if(myGets(buffer,sizeof(buffer)) == 0 && utn_getIsInt(buffer))
		{
			*pResultado = atoi(buffer);
			ret = 0;
		}
	}
	return ret;
}
int utn_getNumFloat(float *pResultado)
{
	int ret = -1;
	char buffer[64];
	if(pResultado != NULL)
	{
		if(myGets(buffer,sizeof(buffer)) == 0 && utn_getIsFloat(buffer))
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
			printf("\n %s",mensaje);
			fflush(stdin);
			if(utn_getEntero(&bufferInt) == 0)
			{
				if(bufferInt >= minimo && bufferInt <= maximo)
				{
					*pResultado = bufferInt;
					ret = 0;
					break;
				}
			}
			printf("\n %s",mensajeError);
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
			printf("\n %s",mensaje);
			fflush(stdin);
			if(utn_getNumFloat(&bufferFloat)==0)
			{
				if(bufferFloat >= minimo && bufferFloat <= maximo)
				{
					*pResultado = bufferFloat;
					ret = 0;
					break;
				}
			}
			printf("\n %s",mensajeError);
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
int utn_getLower(char* letra)
{
	strlwr(letra);
	return 0;
}
int utn_getRespuesta (char* mensaje,char*mensajeError, int reintentos)
{
	int rtn = -1;
	char respuesta;
	while(reintentos > 0)
	{
		reintentos--;
	printf("%s",mensaje);
	fflush(stdin);
	scanf("%c",&respuesta);
	utn_getLower (&respuesta);
	while(respuesta != 's' && respuesta != 'n')
	{
		printf("%s",mensajeError);
	}
	if(respuesta == 's')
	{
		rtn = 0;
		break;
	}
	else if(respuesta == 'n')
	{
		rtn = -1;
		break;
	}
	}
	return rtn;
}
int utn_getMayusMin (char name[], int tam)
{
   strlwr(name);

   name[0] = toupper(name[0]);


   return 0;
}
int esCuit(char* cadena)
{
	int ret;
	int i;
	int contadorDigito=0;
	int contadorGuion=0;

	if(cadena!=NULL)
	{
		for(i=0;cadena[i]!='\0';i++)
		{
			if(isdigit(cadena[i])!=0)
			{
				contadorDigito++;
			}
			else
			{
				if(cadena[i]=='-')
				{
					contadorGuion++;
				}
				else
				{
					ret=-1;
					break;
				}
			}
		}
		if(contadorDigito==11 && contadorGuion==2)
		{
			ret=0;
		}
	}
	return ret;
}

int utn_getCuit(char input[],char mensaje[],char eMensaje[],int reintentos)
{
	int ret;
	char buffer[14];
	int i;
	int aux;

		if(input!=NULL && mensaje!= NULL && eMensaje!= NULL && reintentos>0)
		{
			for(i=reintentos;i>0;i--)
			{
				printf("\n %s",mensaje); //Se le pide el tipo de dato a ingresar al usuario
				fflush(stdin);
				fgets(buffer,14,stdin);
				aux=esCuit(buffer);
				if(aux==0)
				{
					if(buffer[2]=='-' && buffer[11]=='-')
					{
						strcpy(input,buffer);
						ret=0;
						break;
					}
				}
				else
				{
					printf("\n %s\n",eMensaje);
				}
			}
		}
		if(reintentos==0)
		{
			ret=-1;
		}
	return ret;
}
