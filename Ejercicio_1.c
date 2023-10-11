/*
 * Este programa se encarga de realizar una busqueda de un valor introducido por usuario dentro del array y mostrarle al usuario un mensaje si el valor exite y en que posicion dentro del array se encuentra, de lo contrario mostrara un mensaje de no exitencia del  valor. Se emplearan tres tipos de busquedas: lineal, binaria y binaria usando recursividad.   
 *
 *
 * */


#include <stdio.h>
#include <unistd.h>


// Funcion de busqueda lineal

int busqueda_lineal(int array[], int size, int valor) {
    for (int i = 0; i < size; i++){
        if(array[i] == valor){
            return i + 1;	

	}
    }
    return -1;
}


// Funcion de busqueda binaria

int busqueda_binaria(int array[], int size, int valor){
    int inicio = 0;
    int fin = size - 1;

    while(inicio <= fin){
        int medio = inicio + (fin - inicio) / 2;
	if (array[medio] == valor){
	    return medio + 1;
	}
        if (array[medio] < valor){
	    inicio = medio + 1;	
	}
       	else {
            fin = medio - 1;
	}
    }
    return -1;
}




// Funcion de busqueda binaria recursiva

int busqueda_binaria_recursiva(int array[], int inicio, int fin, int valor){
    
    if (inicio > fin) {  
        return -1;
    }
     
    int medio = inicio + (fin - inicio) / 2;
   

    if (array[medio] == valor) {
        return medio + 1; 
    }
    
    if (array[medio] < valor){
        return busqueda_binaria_recursiva(array, medio + 1, fin, valor);
    } else {
        return busqueda_binaria_recursiva(array, inicio, medio - 1, valor);
    
    }
}


// Funcion de main. Llama a las demas funciones. 

int main () {
 
    int array[] = {2, 4, 6, 23, 56, 79};
    int size = sizeof(array) / sizeof(array[0]);

    int valor;
    printf("Ingrese un valor entero:\n ");
    scanf("%d", &valor);

    int posicion_lineal = busqueda_lineal(array, size, valor);
    int posicion_binaria_recursiva = busqueda_binaria_recursiva(array, 0, size - 1, valor);
    int posicion_binaria = busqueda_binaria(array, size, valor);


    if (posicion_lineal, posicion_binaria, posicion_binaria_recursiva != -1) {
        printf("Búsqueda lineal: El valor %d fue encontrado en la posición %d.\n", valor, posicion_lineal);
	sleep(2);
	printf("Búsqueda binaria recursiva: El valor %d fue encontrado en la posición %d.\n", valor, posicion_binaria_recursiva);
	sleep(2);
        printf("Búsqueda binaria iterativa: El valor %d fue encontrado en la posición %d.\n", valor, posicion_binaria);

    } else {
        printf("Búsqueda lineal: El valor %d no fue encontrado.\n", valor);
	sleep(2);
        printf("Búsqueda binaria iterativa: El valor %d no fue encontrado.\n", valor);
	sleep(2);
        printf("Búsqueda binaria recursiva: El valor %d no fue encontrado.\n", valor);
    }

    return 0;
}
