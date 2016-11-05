#include <stdio.h>
#include "libreria.h" //cuando uso comillas busca la librería en el mismo directorio donde está el ejecutable
#include <stdlib.h>	
#include <string.h>
#include <math.h>
#include <ctype.h>

int main(int argc, char *argv[]){
	//Verficación de Argumentos: [Sintaxis de ejecución .. $ ./ejecutable nombre_programa -N]
	//Donde N representa el número de argumentos
	if (argc == 3){
		//Válido para las funciones head() y tail()
		if (1 < argc && argv[2][0] == '-' && isdigit (argv[2][1])){ //Verifica si el argumento cumple la sintaxis y contiene un entero
				//Identifica el tipo de función a ejecutar
				if (strcmp(argv[1], "head")==0){	
						head(atoi(argv[2]+1));
				} else if (strcmp(argv[1], "tail")==0){
					tail(atoi(argv[2]+1));
				} else if(strcmp(argv[1], "longlines")==0){
					longlines(atoi(argv[2]+1));
				}else{
					//la función no es reconocida
					printf("\n[ ERROR: Función no incluida en la librería ]\n");
					printf("[ USO [ head() tail() longlines() ]: $ %s nombre_programa -N ]\n\n", argv[0]);
					return 1;
				}
		}else{	
			//La sintaxis del argumento no es correcta			
			printf("\n[ ERROR: introducción de argumento N incorrecta ]\n");
			printf("[ USO [ head tail longlines ]: $ %s nombre_programa -N ]\n\n", argv[0]);
			return 5;
			}
	}else if (argc == 2){
		//Sólo las funciones head() y tail () disponen de argumento predeterminado (10)
			if (strcmp(argv[1], "head")==0){
				head(10);
			} else if (strcmp(argv[1], "tail")==0){
				tail(10);
			} else if (strcmp(argv[1], "longlines")==0){
				printf("\n[ ERROR: por favor, esta función necesita un argumento de tipo entero ]\n");
				printf("[ USO [ head tail longlines ]: $ %s longlines -N ]\n\n", argv[0]);
				return 2;
			}else{
				printf("\n[ ERROR: Función no incluida en la librería ]\n");
				printf("[ USO [ head tail longlines ]: $ %s nombre_programa -N ]\n\n", argv[0]);
				return 3;
			}
	}else{
		//la ejecución no contiene los argumentos correctos
		printf("\n[ ERROR: Número de argumentos incorrectos ]\n");
		printf("[ USO_1 [ head tail longlines ]: $ %s head -N ]\n", argv[0]);
		printf("[ USO_2 [ head tail longlines ]: $ %s tail -N ]\n", argv[0]);
		printf("[ USO_3 [ head tail longlines ]: $ %s longlines -N ]\n\n", argv[0]);
		return 4;
	}


















	/*if(argc==1){
		printf("¿Qué función quiere ejecutar?\n");
		printf("1: head\n2: tail\n3: longlines\n");
		fgets (buf, 1024, stdin);
		if (atoi(buf)==1){
			printf("\n[ Introduzca el argumento de la función head()... ]\nNOTA: Si no introduce argumento, por defecto este será 10.\n");
			fgets (buf, 1024, stdin);
			head(atoi(buf));
			return 1;
		}else if(atoi(buf)==2){
			//ejecuta tail
			printf("\n[ Introduzca el argumento de la función tail()... ]\nNOTA: Si no introduce argumento, por defecto este será 10.\n");
			fgets (buf, 1024, stdin);
			tail(atoi(buf));
		}else if(atoi(buf)==3){
			int correcto=0;
			printf("\n[ Introduzca el argumento de la función longlines()... ]\nNOTA: Es OBLIGATORIO introducir un argumento.\n");
			while (correcto==0){
				fgets (buf, 1024, stdin);
				longlines(atoi(buf));
				correcto=1;
			}
			
			//ejecuta longlines
		}else{
			printf("Error: Respuesta no contemplada");
			return 1;
		}
	}else{
		printf("El ejecutable test.c no requiere argumentos, ejecútelo de la siguiente forma: ./test.c");
		return 1;
	}*/
	
	



}