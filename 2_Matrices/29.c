/*2.9 Se desea contabilizar los votos recibidos en las elecciones de un club de fútbol. Existen 10 candidatos cada
uno representado por un número de lista diferente (número de 3 cifras no correlativo). La votación se realiza
en 15 sedes distintas codificadas del 1 al 15. Se ingresan los votos registrados en cada una de las sedes
registrando:
• Número de lista
• Número de sede
• Cantidad de votos
(Solo se informan candidatos que recibieron votos).
La carga de votos finaliza con un número de lista igual a 0
Mostrar:
a. Cantidad de votos recibidos por cada candidato en cada sede.
LISTA SEDE1 SEDE2   SEDE3   …    SEDE15
873      36    78    99     …      XX
735      XX    XX    XXX    …      XX     
b. Listado ordenado por cantidad de votos totales en formar decreciente, con el siguiente formato:
TOTAL DE VOTOS PORCENTAJE LISTA
       800         80%     873
       200         20%     735 
c. Candidatos que NO recibieron votos en la sede 5*/
#include <stdio.h>
int validar(int, int, int);
int posSearch(int [], int, int);
void cargarListas(int []);
void bubblesort(int [], int [], int);

int main(){
    int VListas[10], MCant[10][15] = {0}, optn, lista, pos,sede, cant;
    cargarListas(VListas);
    printf("\n#CARGAR LISTAS (LISTA = 0 para finalizar)#");
    do{
        lista = validar(100, 999, 0);
        pos = posSearch(VListas, lista, 10);
        if(pos==-1 && lista !=0){
            printf("\nLista inexistente:");
        }
    }while(pos == -1 && lista != 0);
    while(lista != 0){
        printf("\nSEDE: ");
        sede = validar(1, 15, 2);
        if(MCant[pos][sede-1] != 0){
            printf("0.Actualizar\n1.Cambiar lista y sede");
            scanf("%i", &optn);
            if(optn == 0){
                printf("\nCANT NUEVA: ");
                MCant[pos][sede-1] = validar(1, 1000, 2);
            }
        }
        else{
            printf("\nCANTIDAD: ");
            MCant[pos][sede-1] = validar(1, 1000, 2);
            printf("\nVOTOS INGRESADOS CORRECTAMENTE!...");
        }
        printf("\n\nLISTA: ");
        do{
            lista = validar(100, 999, 0);
            pos = posSearch(VListas, lista, 10);
            if(pos == -1 && lista != 0){
                printf("\nLista invalida: ");
            }
        }while(pos == -1 && lista != 0);
    }
    int i, j;
    printf("\n   SEDE   ");
    for(i = 0; i < 15; i++){
        printf("%-4d ", i+1);
    }
    for(i = 0; i < 10; i++){
        printf("\nLISTA %-3i ", VListas[i]);
        for(j = 0; j < 15; j++){
            printf("%-4d ", MCant[i][j]);
        }
    }
    int VCant[10]= {0}, total =0;
    for(i = 0; i < 10; i++){
        for(j  = 0; j < 15; j++){
            VCant[i]+= MCant[i][j];
            total += MCant[i][j];
        }
    }
    printf("\nLISTAS CON 0 VOTOS EN LA SEDE 5\n");
    for(i = 0; i < 10; i++){
        if(MCant[i][4] == 0){
            printf("\nLISTA %-3d", VListas[i]);
        }
    }
    bubblesort(VCant, VListas, 10);
    float aux;
    printf("\n\nVOTOS  PORCENTAJE  LISTA");
    for(i = 0; i < 10; i++){
        aux = (float) VCant[i] / total * 100;
        printf("\n%-4i   %-10f  %-3i", VCant[i], aux, VListas[i]);
    }
}
void cargarListas(int v[]){
    int i, aux, pos;
    printf("\n#INGRESO#\n");
    printf("1.LISTA: ");
    v[0] = validar(100, 999, 100);
    for(i = 1; i < 10; i++){
        printf("\n%i.LISTA: ", i+1);
        do{
            aux = validar(100, 999, 100);
            pos = posSearch(v,aux, i);
            if(pos !=-1){
                printf("\nLista repetida: ");
            }
        }while(pos != -1);
        v[i] = aux;
    }
}
void bubblesort(int vCant[], int vLista[], int tam){
    int aux, i, limite = tam -1, desordenado;
    do{
        desordenado = 0;
        for(i = 0; i < limite; i++){
            if(vCant[i] < vCant[i+1]){
                aux = vCant[i];
                vCant[i] = vCant[i+1];
                vCant[i+1] = aux;
                aux = vLista[i];
                vLista[i] = vLista[i+1];
                vLista[i+1] = aux;
                desordenado = i;    
            }
        }
        limite = desordenado;
    }while(desordenado);
}
int posSearch(int v[], int cod, int tam){
    int i = 0, pos = -1;
    while(i < tam && pos ==-1){
        if( v[i] == cod){
            pos = i;
        }
        i++;
    }
    return pos;
}
int validar(int min, int max, int ex){
    int aux;
    do{
        scanf("%i", &aux);
        if((aux< min || aux > max) && aux != ex){
            printf("\nDato invalido:  ");
        }
    }while((aux < min || aux > max) && aux != ex);
    return aux;
}