/*
 * Este programa se encarga de obtener los valores maximo y minimo de un arreglo de valores. La funcion de variables  se encarga de encontrar el valor maximo y la funcion de punteros de encontrar el maximo y minimo. 
 *
 * */


#include <stdio.h>

// Funcion del puntero para encontrar los valores minimos y maximos.

void encontrarMinMax(int *arreglo, int * minimo, int * maximo, int longitud) {
    *minimo = *arreglo;
    *maximo = *arreglo; 
    for (int i = 1; i < longitud; i++) {
        if(arreglo[i] > *maximo) {
	    *maximo = arreglo[i];
	}
        if(arreglo[i] < *minimo) {	
            *minimo = arreglo[i];
        }
    }
}



// Funcion encargada de recibir el arreglo y retornar el valor maximo y minimo.

int valorMax(int arreglo[], int longitud) {
    int maximo = arreglo[0];
    for (int i = 1; i < longitud; i++ ) {
        if (arreglo[i] > maximo) {
	    maximo = arreglo[i];
	}
    }
    return maximo;
}



// Funcion del  main. LLama a las demas funciones.

int main () {
    int arreglo[] = {21, 24, 65, 3, 56, 12, 35, 15};
    int size = sizeof(arreglo) / sizeof(arreglo[0]);
    int maximo = valorMax(arreglo, size); 
    

    int min, max;

    encontrarMinMax(arreglo, &min, &max, size);


    printf("Minimo y maximo utilizando punteros:");

   
    printf("El valor maximo del arreglo es:%d\n", max);
    printf("El valor minimo del arreglo es:%d\n", min);


    printf("Maximo usando variables:");

    
    printf("El valor maximo del arreglo es:%d\n", maximo);

    return 0;
}
