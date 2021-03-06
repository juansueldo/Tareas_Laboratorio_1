#include "Informes.h"


void eRecaudacion_mostrarTipoEstado(eRecaudacion arrayRecaudacion[],int tam, eTipo arrayTipo[], int cantTipo, eEstado arrayEstado[], int cantEstado)
{
	char detalle[30];
	char detalleEstado[20];
	eRecaudacion_obtenerNombre (arrayTipo,cantTipo,arrayRecaudacion[tam].idTipo,detalle);
	eRecaudacion_obtenerNombreEstado (arrayEstado,cantEstado,arrayRecaudacion[tam].idEstado,detalleEstado);
	printf("\n**********************************************************************************\n");
	printf(" ID RECAUDACION        MES      IMPORTE      TIPO     ESTADO  ");
	printf("\n**********************************************************************************\n");
	printf("%d    %15d   %10.2f     %15s   %15s\n"
			,arrayRecaudacion[tam].idRecaudacion
			,arrayRecaudacion[tam].mes
			,arrayRecaudacion[tam].importe
			,detalle
			,detalleEstado);


}
int mostrarTodos(eRecaudacion arrayRecaudacion[],int tam, eContribuyente arrayContribuyente[], int cant, eTipo arrayTipo[], int cantTipo, eEstado arrayEstado[], int cantEstado)
{
	int rtn = -1;
	int i;
	int j;
	if(arrayRecaudacion != NULL && arrayContribuyente != NULL && arrayTipo != NULL && tam > 0 && cant > 0 && cantTipo > 0)
	{
		for(i = 0; i < cant; i++)
		{
			if(arrayContribuyente[i].isEmpty == 0)
			{
				printf("\n\n*************************************************************\n");
				printf(" ID    NOMBRE           APELLIDO               CUIL       ");
				printf("\n**************************************************************\n");
				eContribuyente_mostrarUno(arrayContribuyente,i);
			}

			for(j = 0; j < tam; j++)
			{
				if(arrayContribuyente[i].idContribuyente == arrayRecaudacion[j].idContribuyente && arrayRecaudacion[j].isEmpty ==0)
				{
					eRecaudacion_mostrarTipoEstado(arrayRecaudacion,j,arrayTipo,cantTipo,arrayEstado,cantEstado);
					rtn =0;
				}

				}
			}
		}
		return rtn;
}
int eRecaudacion_mostrarSaldados (eRecaudacion arrayRecaudacion[],int tam, eContribuyente arrayContribuyente[], int cant, eTipo arrayTipo[], int cantTipo, eEstado arrayEstado[], int cantEstado)
{
	int rtn = -1;
	int i;
	int j;
	if(arrayRecaudacion != NULL && arrayContribuyente != NULL && arrayTipo != NULL && tam > 0 && cant > 0 && cantTipo > 0)
	{
		for(i = 0; i < tam; i++)
		{
			if(arrayRecaudacion[i].isEmpty == 0 && arrayRecaudacion[i].idEstado == 2)
			{
				eRecaudacion_mostrarTipoEstado(arrayRecaudacion,i,arrayTipo,cantTipo,arrayEstado,cantEstado);

				for(j = 0; j < tam; j++)
				{
					if(arrayRecaudacion[i].idContribuyente == arrayContribuyente[j].idContribuyente && arrayContribuyente[j].isEmpty ==0)
					{
					printf("\n*************************************************************\n");
					printf("  ID    NOMBRE           APELLIDO               CUIL       ");
					printf("\n**************************************************************\n");
					eContribuyente_mostrarUno(arrayContribuyente,j);
					printf("\n\n");
					rtn = 0;
					}
				}
			}
		}
	}
	return rtn;
}

int baja_ContribuyenteRecaudaciones (eContribuyente arrayContribuyentes[], int tamanio, eRecaudacion arrayRecaudacion[], int cant)
{
	int rtn = -1;
	int idContribuyente;
	int index;
	int flag = 0;
	if(arrayContribuyentes != NULL && tamanio > 0 && arrayRecaudacion != NULL && cant > 0)
	{
	if(eContribuyente_isEmpty(arrayContribuyentes, tamanio)==0)
	{
		if (eContribuyente_mostrarTodos(arrayContribuyentes, tamanio) == 0)
		{
			flag = 1;
		}

		if (flag == 1)
		{
		printf("\n*****************************************************************\n");
		utn_getNumero(&idContribuyente,"\nINGRESE EL ID DEL CONTRIBUYENTE A DAR DE BAJA: ","ERORR. NO ES UN ID VALIDO",1000,1999,3);
		while (eContribuyente_buscarId(arrayContribuyentes, tamanio, idContribuyente) == -1)
		{
			utn_getNumero(&idContribuyente,"\nNO EXISTE ID. INGRESE EL ID DEL CONTRIBUYENTE A DAR DE BAJA:","ERORR. NO ES UN ID VALIDO",1000,1999,3);
		}
		index = eContribuyente_buscarId(arrayContribuyentes, tamanio, idContribuyente);
		if(eContribuyente_isEmpty (arrayContribuyentes,tamanio) == 0)
		{
			if(eContribuyente_bajaContribuyente (arrayContribuyentes, tamanio, &idContribuyente, &index)==0)
			{
				for(int i = 0; i < cant; i++)
				{
					if(idContribuyente == arrayRecaudacion[i].idContribuyente)
					{
						arrayRecaudacion[i].isEmpty = 1;

					}
				}
			}

		}
		}
		rtn = 0;
	}
	}
	else
	{
		rtn = -1;
	}
	return rtn;
}


