/*
 ============================================================================
 Name        : Ejercicio1.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* string_concat(const char* concat_prefijo, const char* concat_sufijo){
	/*
	*   Retorna un String nuevo que es la concatenación
	*   de los dos Strings pasados por parámetro
	*   Ejemplo:
	*   char* nombre = "Ritchie";
	*   char* saludo = string_concat("Hola ", nombre);
	*   =>
	*   saludo = "Hola Ritchie"
	*/
	char* concatenada = malloc(strlen(concat_prefijo)+strlen(concat_sufijo)+1);
	memccpy(concatenada,concat_prefijo,strlen(concat_prefijo),strlen(concat_prefijo)+1);
	memccpy(concatenada + strlen(concat_prefijo),concat_sufijo,strlen(concat_sufijo),strlen(concat_sufijo)+1);
	//Podria haber usado strcat, pero queria probar memccpy
	return concatenada;
};

void string_concat_dinamyc(const char*str_prefijo, const char*str_sufijo, char**str_concatenada){
	/*
	*   Asigna en el tercer parámetro, la concatenación
	*   de los primeros dos Strings
	*   Ejemplo:
	*   char* nombre = "Ritchie";
	*   char* saludo;
	*   string_concat("Hola ", nombre, &saludo);
	*   =>
	*   saludo = "Hola Ritchie"
	*/
	*str_concatenada=malloc(strlen(str_prefijo)+strlen(str_sufijo)+1);
	strcat(*str_concatenada,str_prefijo);
	strcat(*str_concatenada,str_sufijo);
};


	void mail_split(const char* mail, char** user, char** dominio){
		/*
			*   Separa el mail en un usuario y un dominio.
			*   Ejemplo:
			*   char* mail = "ritchie@ansic.com.ar";
			*   char* user;
			*   char* dominio;
			*   mail_split(mail, &user, &dominio);
			*   =>
			*   user = "ritchie"
			*   dominio = "ansic.com.ar"
			*/

	*dominio = malloc(strlen(mail)+1);
	*user = malloc(strlen(mail)+1);

	*dominio = strchr(mail,'@')+1;
	memcpy(*user,mail,strlen(mail)-strlen(*dominio)-1);

	}



int main(void) {

//	char* nombre = "Ritchie";
//	char* saludo = string_concat("Hola ", nombre);
//	puts(saludo);

	char* nombre = "Ritchie";
	char* saludo;
	string_concat_dinamyc("Hola ", nombre, &saludo);
	puts(saludo);

	char* mail = "ritchie@ansic.com.ar";
	char* user;
	char* dominio;
	mail_split(mail, &user, &dominio);

	puts(user);
	puts(dominio);

//	free(nombre);
//	free(saludo);
//	free(mail);
//	free(user);
//	free(dominio);
	return EXIT_SUCCESS;
}
