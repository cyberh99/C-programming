//Nos enfrentamos al caso de que no sabemos concretamente el size del vector, para ello lo asignaremos durante ejecucion

#include <stdio.h>
#include <time.h>
#include <stdlib.h>

//Creamos el vector, en funcion del tamaño que le pasamos por referencia
float* crear_vector(int* tamano){

  float* puntero_al_vector;

  puntero_al_vector = (float *) calloc(tamano, sizeof(float));

  return puntero_al_vector;

}

//Para comprobar que estamos creando el vector y escribiendolo correctamente lo llenamos de valores aleatorios
void rellenar_vector(float* vector,int tamano){

    srand(time(NULL));
    for (int i = 0; i<tamano;i++){
        int a = rand();
        *(vector+i) = a;

    }
}

int main(int argc, char const *argv[]) {

  int tamano;
  float *p;
  printf("Introduce el tamaño del vector que quieres crear \n");
  scanf("%i\n",&tamano );

  p = crear_vector(tamano);

  printf("Vector creado correctamente en %p\n",p );
  //Recorremos el vector
  for (int i = 0; i<tamano;i++){
    printf("%f\n",*p+i );
  }
  printf("VECTOR RELLENO\n");
  //Llenamos el vector y lo Recorremos
  //PASAMOS EL VECTOR COMO REFERENCIA (PUNTERO DONDE COMIENZA Y LONGITUD)
  rellenar_vector(p,tamano);
  for (int i = 0; i<tamano;i++){

    printf("%f\n",*p+i );
  }

  //Al final de la ejecucion de cualquier programa tenemos que liberar la memoria usada
  free(p);
  return 0;
}
