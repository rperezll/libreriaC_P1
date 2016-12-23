#include <stdio.h>
#include "libreria.h"
#include <stdlib.h>	
#include <string.h>


	char ** ordenarCadena ( char ** cadenasAux, int contador);


	int head (int N){
		int cuenta = 0;
		char buf[1024];
		while((cuenta < N) && (fgets(buf, 1024, stdin) != NULL)){	//fgets devuelve un char* (Si vale null significa que no tiene mas lineas que leer) | CRL+D para la ejecucion de stdin 
		//fgets(buf, 1024, stdin) Espera a que el usuario introduzca una linea para comenzar la iteración, stdin es como el scanner de java (entrada por teclado)
			printf("%s", buf); 
			cuenta++;  
		}
		return 0;	
	}


	int tail(int N) {
		int total=0;
		int  elemento1;
		char buf[1024];
		char *tokens;
		void *p1; //Puntero genérico apuntado a null
		p1 = malloc(512*sizeof(char)); //Reservo memoria mediante función malloc
		char *p1_char = (char *)p1;

		while((fgets(buf, 1024, stdin) != NULL))	//fgets devuelve un char* (Si vale null significa que no tiene 
													//mas lineas que leer) | CRL+D parar la ejecucion de stdin 
													//fgets(buf, 1024, stdin) Espera a que el usuario introduzca una 
													//linea para comenzar la iteración, stdin es como el scanner de java (entrada por teclado)
		{
			strcat(p1_char,buf); 
			total++;
		}

		elemento1 = total - N;	//Obtenemos la posición desde la cual queremos imprimir nuetra salida
		tokens = strtok(p1_char,"\n");
		int contadorTokens=0;
		printf("\n\nRESULTADO\n\n");
		while (tokens) { //Mientras tokens siga siendo distinto de null
			if (tokens != NULL) {
				if (elemento1 <= contadorTokens) {	 //Si str no se ha acabado == tokens!=NULL
					printf("%s\n", tokens);
				}
			}
			tokens=strtok(NULL,"\n"); //Para seguir en el siguiente elemento de la cadena separada por : usamos NULL como primer argumento
			contadorTokens++;
		}

		return 0;
	}


	int longlines (int  N){
		int i=0;
		int cont=0;
		char buf[1024];
		char **cadenas;

		//Reservamos memoria mediante malloc
		cadenas = (char **) malloc (1024*sizeof(char *));
		while (i<1024){
			cadenas[i]= (char *) malloc (1024*sizeof(char));
			i++;
		}

		while (fgets(buf,1024,stdin)!=NULL){	//El usuario introduce cadenas
			    strcpy(cadenas[cont],buf);	//la cadena se introduce en la posición cont de nuestro array cadenas
			    cont++;   
		}

		cadenas=ordenarCadena(cadenas, cont); //llamamos al método auxiliar que ordena cadenas. Una vez ordenado, sobrescribimos la estructura cadenas.

		printf("\n\n**RESULTADO**\n\n");
		//imprimimos el resultado
		int iPrint=0;
		for(int iPrint = 0; iPrint < N; iPrint++) {
			printf("%s\n",cadenas[iPrint]); 	
		}
		//liberamos la memoria reservada mediante la función free.
		int indiceFree=0;
		while (indiceFree<N){
			free(cadenas[indiceFree]);
			indiceFree++;
		}
		free(cadenas);
		return 0;
	}


	char ** ordenarCadena ( char ** cadenasAux, int contador){
		//ordena cadenas (que en este caso pasa a ser cadenasAux) de mayor a menor longitud de líneas
		//Usado algoritmo de la burbuja
		char buffer[1024];
		int indice=0,indiceAux=0;
		int longC,longCAux;
		while (indice<(contador-1)){
				while (indiceAux<(contador-1)){
					//calculamos la longitud de las cadenas a comprar
					longC=strlen(cadenasAux[indiceAux]);
					longCAux=strlen(cadenasAux[indiceAux+1]);
					if (longC<longCAux){
						strcpy(buffer,cadenasAux[indiceAux]);	//copiamos la cadena en un bufer
						strcpy(cadenasAux[indiceAux],cadenasAux[indiceAux+1]);	//sustituimos la posición 
						strcpy(cadenasAux[indiceAux+1],buffer); //volvemos a colocar el elemento sustituido
					}
				indiceAux++;
				}
			indiceAux=0;	//importante! inicializar el indice para volver a entrar en el while interior
			indice++;	
		}
		return cadenasAux; //devolvemos la cadena ordenada de mayor a menor
	}