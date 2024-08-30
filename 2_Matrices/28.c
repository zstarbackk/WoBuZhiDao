/*2.8 Un consorcio desea controlar la cobranza de las expensas en un edificio de 5 pisos donde existen 15
departamentos en cada piso. El valor de las expensas es de $ 1000. Para registrar la cobranza se ingresa el
número de piso (1 a 5) y el número de departamento (correlativo de 1 a 15 en cada piso). El ingreso finaliza
con un piso igual a 99.
Al finalizar mostrar el dinero total recaudado y una tabla con una X indicando aquellos departamentos
deudores de la siguiente manera:
TOTAL RECAUDADO
DEPARTAMENTOS DEUDORES
PISO   DPTO 1 DPTO2 … DPTO 15
PISO 1   X
PISO 2          X        X
PISO 3   X
PISO 4   X      X
PISO 5   X      X           */
#include <stdio.h>
int validar(int, int, int);

int main(){
    char MPagos[5][15];
    int sum = 0, piso, dpto, i , j;
    printf("##CARGA DE PAGOS##");
    printf("\nPISO(99 para terminar): ");
    piso = validar(1, 5, 99);
    while(piso!=99){
        printf("\nDPTO: ");
        dpto = validar(1, 15, 2);
        if(MPagos[piso-1][dpto-1]!=' '){
            MPagos[piso-1][dpto-1]= 'X';
            printf("\nINGRESO EXITOSO...\n");
        }
        else{
            printf("\nYA PAGO>>>");
        }
        printf("\nPiso(99 para terminar): ");
        piso = validar(1, 5, 99);
    }
    printf("\nDPTO    ");
    for(i = 0; i < 15; i++){
        printf("%-2d ", i+1);
    }
    for(i = 0; i < 5; i++){
        printf("\nPISO %-2i ", i+1);
        for(j = 0;j < 15; j++){
            if(MPagos[i][j]!= 'X')
                printf("%-2s ", "  ");
            else{
                printf("%-2s ","X ");
                sum += 1000;
            }
        }
    }
    printf("\n\nRECAUDADO:  %d", sum);
}
int validar(int min, int max, int ex){
    int aux;
    do{
        scanf("%i", &aux);
        if((aux< min || aux > max) && aux != ex){
            printf("\nDato invalido: ");
        }
    }while((aux < min || aux > max)&& aux != ex);
    return aux;
}