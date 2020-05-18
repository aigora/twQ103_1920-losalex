//COMANDO BANNER 
//Alejandro Martín Herreros 54389
//Alexandra Mancilla Ávila 53466

#include <stdio.h>
#include <string.h>

struct letrabanner
{
	char letra;
	char matriz[7][7];
};

void LeerTextoDeBanner(int posicion, struct letrabanner cadenadebanners[100]);
void transformarletra(int posicion, struct letrabanner cadenadebanners[100], char tipograf);
void escritorenfichero(char texto[80], struct letrabanner cadenadebanners[100], int cont);


int main()
{
	//PRESENTACIÓN DEL PROGRAMA
	printf("Este programa realiza un comando banner.\nMuestra un texto en grande dibujando cada letra con una matriz 6x6 elegida por el usuario.\n\n");

	int opcion1, opcion2, i, j ,k, o, p;
	char texto[80];
	char tipograf;
	int cont=1;
	struct letrabanner cadenadebanners[100];
	FILE *fentrada;
	FILE *pg;
	char space[7], space2[7], space3[7], space4[7];
	int i2;
	int lineasnovalidas;

	do
	{
	printf("\nSeleccione una opcion: \n");
	printf("1-Elegir tipografia\n");
	printf("2-Mostrar banner\n");
	printf("3-Salir del programa\n");
	printf("Opcion: ");
		
		scanf("%d", &opcion1);
		while (getchar() != '\n');
		printf("\n");

		switch (opcion1)
		{
		case 1:
			printf("\n\tSeleccione una opcion de tipografia: \n");
			printf("\t\t1-Hashtag\n");
			printf("\t\t2-Ampersand\n");
			printf("\t\t3-Dolares\n");
			printf("\t\tOpcion: ");
			scanf("%d", &opcion2);
			while (getchar() != '\n');
			printf("\n");

			if (opcion2 == 1) tipograf = '#';
			else if (opcion2 == 2) tipograf = '&';
			else if (opcion2 == 3) tipograf = '$';
			else printf("\tValor incorrecto, se mantiene la tipografía existente\n");
			
			//PONEMOS AQUI LA OPCION DOS DEL SWITCH PARA CONSEGUIR QUE PIDA EL TEXTO DESPUES DE ELEGIR LA TIPOGRAFIA SIN TENER QUE REPETIR EL MENU PRINCIPAL. 
			printf("\tIntroduzca el texto (en minuscula) que quiere variar:"); 
			gets(texto);    // usamos la función gets porque coge espacios
			
			if (strlen(texto) >= 25)
			{
				printf("\n\tEl texto debe ser menor de 25 caracteres.\n");
			}

			else
			{
				for (i = 0; i < strlen(texto); i++)  //Este es un bucle donde se trata cada letra del texto
				{                                    



					if (texto[i] == ' ')
					{    // si la letra es un espacio, se rellena las 6 lineas de la matriz con "      ".
						cadenadebanners[i].letra = ' ';
						for (j = 0; j < 6; j++)
							strcpy(cadenadebanners[i].matriz[j], "      ");
					}

					else if (texto[i] >= 'A' && texto[i] <= 'Z')     //Me aseguro de que la letra que trato es una mayuscula entre la A y la Z
					{
						cadenadebanners[i].letra = texto[i];   // Le doy una posición en el banner a cada letra del texto 
						
					fentrada = fopen("Hashtag.txt", "r");
						if (fentrada == NULL){ //no existe el fichero y aviso al usuario
							printf("\t\tNo existe el fichero Hashtag.txt");
							}	
						else{ //leo lineas que no me interesan hasta la linea donde empieza la palabra
							lineasnovalidas = (cadenadebanners[i].letra - 'A') * 6;
							for (j = 0; j < lineasnovalidas; j++){
						   	fgets(space, 7, fentrada); //Space es para leer del fichero el espacio que hay al final de cada fila de cada matriz de letra
							fgets(space, 2, fentrada);
							}
							for (j = 0; j < 6; j++){   //leo las seis filas de la letra que me interesa
							fgets(cadenadebanners[i].matriz[j], 7, fentrada);
							fgets(space, 2, fentrada);
							}
						}
						fclose(fentrada);
						
						for (i2 = 0; i2 < 7; i++){
							for (j = 0; j < 7; j++){
								if (cadenadebanners[i].matriz[i2][j] == '#'){
									
								}
								
							}
						}
						
					}
					else if (texto[i] >= 'a' && texto[i] <= 'z')
					{
						//convierte primero la letra a mayuscula restandole 32 (códigos ASCII)

						cadenadebanners[i].letra = texto[i] - 32;
						
						fentrada = fopen("Hashtag.txt", "r");
						if (fentrada == NULL){ //no existe el fichero y aviso al usuario
							printf("\t\tNo existe el fichero Hashtag.txt que debe de contener los banners de las letras");
							}	
						else{ //leo lineas que no me interesan hasta la linea donde empieza la palabra
						    lineasnovalidas = (cadenadebanners[i].letra - 'A') * 6;
							for (j = 0; j < lineasnovalidas; j++){
							fgets(space2, 7, fentrada);
							fgets(space2, 2, fentrada);
							}
							for (j = 0; j < 6; j++){   //leo las seis filas de la letra que me interesa
							fgets(cadenadebanners[i].matriz[j], 7, fentrada);
							fgets(space2, 2, fentrada);
							}
						}
						fclose(fentrada);
						
						for (i2 = 0; i2 < 7; i2++){
							for (j = 0; j < 7; j++){
								if (cadenadebanners[i].matriz[i2][j] == '#'){
									
								}
								
							}
						}
		
					}
					else
					{ // no es letra ni espacio y lo rellenamos con una matriz 6x6 con la tipografia seleccionada
						cadenadebanners[i].letra = texto[i];
						for (j = 0; j < 6; j++)
							for (k = 0; k < 6; k++)
								cadenadebanners[i].matriz[j][k] = tipograf;
						
						for (i2 = 0; i2 < 7; i2++){
							for (j = 0; j < 7; j++){
								if (cadenadebanners[i].matriz[i2][j] == '#')
									cadenadebanners[i].matriz[i2][j] = tipograf;
							}
						}
					}
					transformarletra(i, cadenadebanners, tipograf);
				}

			}


				// Imprimir texto en HORIZONTAL:

			for (j = 0; j < 6; j++)	{
				for (i = 0; i < strlen(texto); i++)	{
					printf("%s ", cadenadebanners[i].matriz[j]);
				}
				printf("\n"); // Para que cambie de línea al escribir la primera fila de todas las matrices.
			}
			if(cont>1){
				FILE *pg;
				pg=fopen("Ficheroresultante.txt", "a"); // Utilizamos el modo "a" para que los datos nuevos se añadan al final del fichero.Si el fichero no existe, se crea
				fprintf(pg,"\n\n");

				for (p = 0; p < 6; p++){
					for (o = 0; o < strlen(texto); o++){
						fprintf(pg,"%s ", cadenadebanners[o].matriz[p]);
				}
				fprintf(pg, "\n"); // Para que cambie de línea al escribir la primera fila de todas las matrices.
				}
				cont++;

				fclose(pg);
				}
	
			if(cont==1){
				FILE *pg;
				pg=fopen("Ficheroresultante.txt", "w");
				fprintf(pg,"\n\n");

				for (p = 0; p < 6; p++){
					for (o = 0; o < strlen(texto); o++){
					fprintf(pg,"%s ", cadenadebanners[o].matriz[p]);
					}
				fprintf(pg, "\n"); 
				}
				cont++;

				fclose(pg);
			}
				
			break;


		case 2:
			
            printf("\tIntroduzca el texto:"); 
			gets(texto);    
			
			if (strlen(texto) >= 25)
			{
				printf("\n\tEl texto debe ser menor de 25 caracteres.\n");
			}

			else
			{
				for (i = 0; i < strlen(texto); i++)  
				{                                    



					if (texto[i] == ' ')
					{    
						cadenadebanners[i].letra = ' ';
						for (j = 0; j < 6; j++)
							strcpy(cadenadebanners[i].matriz[j], "      ");
					}

					else if (texto[i] >= 'A' && texto[i] <= 'Z')
					{
						cadenadebanners[i].letra = texto[i];   
						
						fentrada = fopen("Hashtag.txt", "r");
						if (fentrada == NULL){ 
							printf("\t\tNo existe el fichero Hashtag.txt que debe de contener los banners de las letras");
							}	
						else{ 
							lineasnovalidas = (cadenadebanners[i].letra - 'A') * 6;
							for (j = 0; j < lineasnovalidas; j++){
							fgets(space3, 7, fentrada);
							fgets(space3, 2, fentrada);
							}
							for (j = 0; j < 6; j++){   
							fgets(cadenadebanners[i].matriz[j], 7, fentrada);
							fgets(space3, 2, fentrada);
							}
						}
						fclose(fentrada);
						
						for (i2 = 0; i2 < 7; i2++){
							for (j = 0; j < 7; j++){
								if (cadenadebanners[i].matriz[i2][j] == '#'){
									
								}
								
							}
						}

					}
					else if (texto[i] >= 'a' && texto[i] <= 'z')
					{
					
						cadenadebanners[i].letra = texto[i] - 32;
						fentrada = fopen("Hashtag.txt", "r");
						if (fentrada == NULL){ 
							printf("\t\tNo existe el fichero Hashtag.txt que debe de contener los banners de las letras");
							}	
						else{ 
							lineasnovalidas = (cadenadebanners[i].letra - 'A') * 6;
							for (j = 0; j < lineasnovalidas; j++){
							fgets(space4, 7, fentrada);
							fgets(space4, 2, fentrada);
							}
							for (j = 0; j < 6; j++){  
							fgets(cadenadebanners[i].matriz[j], 7, fentrada);
							fgets(space4, 2, fentrada);
							}
						}
						fclose(fentrada);
						
						for (i2 = 0; i2 < 7; i2++){
							for (j = 0; j < 7; j++){
								if (cadenadebanners[i].matriz[i2][j] == '#'){
									
								}
								
							}
						}
					}
					else
					{ 
						cadenadebanners[i].letra = texto[i];
						for (j = 0; j < 6; j++)
							for (k = 0; k < 6; k++)
								cadenadebanners[i].matriz[j][k] = tipograf;
						
						for (i2 = 0; i2 < 7; i++){
							for (j = 0; j < 7; j++){
								if (cadenadebanners[i].matriz[i2][j] == '#'){
									
								}
								
							}
						}		
						for (i2 = 0; i2 < 7; i2++){
							for (j = 0; j < 7; j++){
								if (cadenadebanners[i].matriz[i2][j] == '#')
									cadenadebanners[i].matriz[i2][j] = tipograf;
							}
						}
					}
						transformarletra(i, cadenadebanners, tipograf);
					}

				}


				// Imprimir texto en HORIZONTAL:

				for (j = 0; j < 6; j++)
				{
					for (i = 0; i < strlen(texto); i++)
					{
						printf("%s ", cadenadebanners[i].matriz[j]);
					}
					printf("\n"); // Para que cambie de línea al escribir la primera fila de todas las matrices.
				}
				if(cont>1){
					FILE *pg;
					pg=fopen("Ficheroresultante.txt", "a");
					fprintf(pg,"\n\n");

					for (p = 0; p < 6; p++){
						for (o = 0; o < strlen(texto); o++){
							fprintf(pg,"%s ", cadenadebanners[o].matriz[p]);
						}
					fprintf(pg, "\n"); 
					}
					cont++;

					fclose(pg);
				}
	
				if(cont==1){
					FILE *pg;
					pg=fopen("Ficheroresultante.txt", "w");
					fprintf(pg,"\n\n");

					for (p = 0; p < 6; p++){
						for (o = 0; o < strlen(texto); o++){
							fprintf(pg,"%s ", cadenadebanners[o].matriz[p]);
						}
					fprintf(pg, "\n"); // Para que cambie de línea al escribir la primera fila de todas las matrices.
					}
					cont++;

					fclose(pg);
				}

			break;



		case 3:  //Salir del programa 
		
			
			break;

		default:
			printf("Opcion incorrecta\n");
		}

	} while (opcion1 != 3);


	system("pause");



}

	//FUNCIONES

	void LeerTextoDeBanner(int posicion, struct letrabanner cadenadebanners[100])

		//La posición nos indica donde va cada letra seleccionada del fichero

	{
		FILE *fentrada;

		char space5[7]; 
		int i;
		int lineasnovalidas;  //nºde lineas invalidas que hay en el fichero hasta llegar a la linea de la matriz de cada letra

		fentrada = fopen("Hashtag.txt", "r");

		if (fentrada == NULL)

		{ 
			printf("\t\tNo existe el fichero Hashtag.txt");
			
		}

		else
		{ //leo lineas que no me interesan hasta la linea donde empieza la palabra
			lineasnovalidas = (cadenadebanners[posicion].letra - 'A') * 6;

				for (i = 0; i < lineasnovalidas; i++)
				{
					fgets(space5, 7, fentrada);
					fgets(space5, 2, fentrada);
				}

				for (i = 0; i < 6; i++)   //leo las seis filas de la letra que me interesa
				{
					fgets(cadenadebanners[posicion].matriz[i], 7, fentrada);
					fgets(space5, 2, fentrada);
				}
			
		}
		fclose(fentrada);

	}

	void transformarletra(int posicion, struct letrabanner cadenadebanners[100], char tipograf)

		//Transformo la tipografía de la letra en la posición de la cadena de banners
    {
		int i, j;

		for (i = 0; i < 7; i++)
		{
			for (j = 0; j < 7; j++)
			{
				if (cadenadebanners[posicion].matriz[i][j] == '#')
					cadenadebanners[posicion].matriz[i][j] = tipograf;
			}
		}
	}
void escritorenfichero(char texto[80], struct letrabanner cadenadebanners[100], int cont){
	
	int o, p;
	
	if(cont>1){
		FILE *pg;
	pg=fopen("Ficheroresultante.txt", "a");
	fprintf(pg,"\n\n");

	for (p = 0; p < 6; p++)
	{
		for (o = 0; o < strlen(texto); o++)
		{
			fprintf(pg,"%s ", cadenadebanners[o].matriz[p]);
		}
		fprintf(pg, "\n"); // Para que cambie de línea al escribir la primera fila de todas las matrices.
	}
	cont++;

	fclose(pg);
	}
	
	if(cont==1){
		FILE *pg;
	pg=fopen("Ficheroresultante.txt", "w");
	fprintf(pg,"\n\n");

	for (p = 0; p < 6; p++)
	{
		for (o = 0; o < strlen(texto); o++)
		{
			fprintf(pg,"%s ", cadenadebanners[o].matriz[p]);
		}
		fprintf(pg, "\n"); // Para que cambie de línea al escribir la primera fila de todas las matrices.
	}
	cont++;

	fclose(pg);
	}
	
}

