#include <stdio.h>
int posbuscar(int [], int , int);
int cargarDNI(int [], int []);
void mostrarLista(int [], int [], int);
int validar(int, int, int);
float validarf(float, float, float);
void ordenar(int [], int [], int);


int main(){
    int vecDni[60] = {0}, vecNota[60] = {0}, cant;
    cant = cargarDNI(vecDni, vecNota);
    ordenar(vecDni, vecNota, cant);
    mostrarLista(vecDni, vecNota, cant);   
}

int cargarDNI(int vecDni[],int vecNota[]){
    int dni, i = 0, pos;
    float nota;
    printf("\nIngresar DNI:  ");
    dni = validar(18000000, 50000000, -1);
    while(dni != -1 && i<60){
        printf("\nIngresa nota:  ");
        nota = validarf(0, 10, 2);
        vecDni[i] = dni;
        vecNota[i] = nota;
        i++;
        if(i < 60){
            printf("\nIngresar DNI:  ");
            do{
                dni = validar(18000000, 50000000, -1);
                pos = posbuscar(vecDni, dni, i);
                if(pos != -1)
                    printf("\nIngrese dato valido:  ");
            }while(pos != -1);
        }
    }
    return i;
}

void ordenar(int vecDni[], int vecNota[], int tam){
    int i, limite = tam -1, aux, desordenado;
    do{
        desordenado = 0;
        for(i = 0; i < limite; i++){
            if(vecNota[i] > vecNota[i+1]){
                aux = vecNota[i];
                vecNota[i] = vecNota[i+1];
                vecNota[i+1] = aux;
                aux = vecDni[i];
                vecDni[i] =vecDni[i+1];
                vecDni[i+1] = aux;
                desordenado = i;
            }
        }
        limite = desordenado;
    }while(desordenado);   

}
void mostrarLista(int vecDni[], int vecNota[], int tam){
    int i;
    printf("\n\n%-8s |  %-4s\n", "DNI", "NOTA");
    for(i = 0; i< tam; i++){
        printf("%-8i |  %-4i\n", vecDni[i], vecNota[i]);
    }
}
int posbuscar(int vec[], int dni, int tam){
    int i = 0, pos = -1;
    while(pos==-1 && i <60){
        if(vec[i] == dni)
            pos = i;
        i++;
    }
    return pos;
}
int validar(int min, int max, int ex){
    int aux;
    do{
        scanf("%i", &aux);
        if((aux<min || aux > max) && aux != ex)
            printf("\nIngrese dato valido:  ");
    }while((aux< min || aux > max) && aux != ex);
    return aux;
}
float validarf(float min, float max, float ex){
    float aux;
    do{
        scanf("%f", &aux);
        if((aux<min || aux > max) && aux != ex)
            printf("\nIngrese dato valido:  ");
    }while((aux< min || aux > max) && aux != ex);
    return aux;
}