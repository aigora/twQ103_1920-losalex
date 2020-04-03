#include <stdio.h>
#include <string.h>

#define MAXCHARS 80  


struct letrabanner
{
	char letra;
	char matriz[7][7];
};

struct letrabanner cadenadebanners[MAXCHARS]; //defino una vector de estructuras para almacenar las letras y su representación en banner

int main()
{
	//PRESENTACIÓN DEL PROGRAMA
	printf("Este programa muestra un texto en grande dibujando cada letra con una matriz 6x6.\n\n");

	int opcion, opcion2, i, j;
	char texto[MAXCHARS];
	char tipograf;
		do
	{
			printf("\nSeleccione una opcion: \n");
		printf("1-Elegir tipografia\n");
		printf("2-Mostrar banner\n");
		printf("3-Salir del programa\n");
	printf("Opcion: ");
		
		scanf("%d", &opcion);
		while (getchar() != '\n');
		printf("\n");

		switch (opcion)
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
			
			 
			printf("\tIntroduzca el texto:"); 
			gets(texto);    // usamos la función gets porque coge espacios
			
			if (strlen(texto) >= 30)
			{
				printf("\n\tEl texto debe ser menor de 30 caracteres.\n");
			}

			else
			{
				for (i = 0; i < strlen(texto); i++)  
				{                                    


					if (texto[i] >= 'A' && texto[i] <= 'Z')     //Me aseguro de que la letra que trato es una mayuscula entre la A y la Z
					{
						cadenadebanners[i].letra = texto[i];   // Le doy una posición en el banner a cada letra del texto 
					

					}
					else if (texto[i] >= 'a' && texto[i] <= 'z')
					{
						//convierte primero la letra a mayuscula restandole 32 (códigos ASCII)

						cadenadebanners[i].letra = texto[i] - 32;
						
					}
					

				}


				
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


				        if (texto[i] >= 'A' && texto[i] <= 'Z')     l
					{
						cadenadebanners[i].letra = texto[i];  
					}
					else if (texto[i] >= 'a' && texto[i] <= 'z')
					{
						

						cadenadebanners[i].letra = texto[i] - 32;
					}
					

				}


				
			}

			break;
			
		case 3:  //Salir del programa 
			break;

		default:
			printf("Opcion incorrecta\n");
		}

	} while (opcion != 3);


	system("pause");



}




