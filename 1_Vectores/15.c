#include <stdio.h>
int posBuscar(int [], int, int);
void carga(int [], int);
void ordenarAscendente(int [], int);
void ordenarDescendente(int [], int [], int);
void ventas(int [], int[], int []);
int validar(int, int, int);

int main(){
    int vecCod[15], vecCant[15], vecSellers[5] = {0},i;
    carga(vecCod, 15);
    ordenarAscendente(vecCod, 15);
    ventas(vecCod, vecCant, vecSellers);
    ordenarDescendente(vecCod, vecCant, 15);
    printf("\n\na>>>\n");
    printf("\n%-4s  |  %-6s", "CANT", "CODIGO");
    for(i = 0; i < 15; i++){
        printf("\n%-4i  |  %-6i", vecCant[i], vecCod[i]);
    }
    printf("\n\nb>>>>\n");
    printf("\n%-8s  |  %-6s", "VENDEDOR", "VENTAS");
    for(i = 0; i<5; i++){
        printf("\n%-8i  |  %-6i", 1001+i, vecSellers[i]);
    }
} 
int posBuscar(int v[], int x, int tam){
    int i = 0, pos = -1;
    while(pos == -1 && i < tam){
        if(v[i] == x){
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
        if((aux < min || aux > max) && aux != ex)
            printf("\nIngresar dato valido:  ");
    }while((aux < min || aux > max) && aux != ex);
    return aux;
}
void carga(int vecCod[], int tam){
    int i, pos, cod;
    printf("\nIngresar codigo:  ");
    cod = validar(100, 999, 100);
    vecCod[0] = cod;
    for(i = 1; i < tam; i++){
        printf("\nIngresar codigo:  ");
        do{
            cod = validar(100, 999, 100);
            pos = posBuscar(vecCod, cod, i);
            if(pos != -1)
                printf("\nDato repetido");
        }while(pos !=-1);
        vecCod[i] = cod;
    }
}
void ordenarAscendente(int veCod[], int  tam){
    int i, aux, limite = tam -1, desordenado;
    do{
        desordenado = 0;
        for(i = 0; i<limite; i++){
            if(veCod[i]> veCod[i+1]){
                aux = veCod[i];
                veCod[i] = veCod[i+1];
                veCod[i+1] = aux;
                desordenado = i;
            }
        }
        limite = desordenado;
    }while(desordenado);
}
void ordenarDescendente(int vcod[], int vcant[], int tam){
    int i, limite = tam -1, desordenado, aux;
    do{
        desordenado = 0;
        for(i = 0; i< limite; i++){
            if(vcant[i] < vcant[i+1]){
                aux = vcant[i];
                vcant[i] = vcant[i+1];
                vcant[i+1] = aux;
                aux = vcod[i];
                vcod[i] = vcod[i+1];
                vcod[i+1] = aux;
                desordenado = i;
            }
        }
        limite = i;
    }while(desordenado);
}
void ventas(int vcod[], int vcant[], int vsellers[]){
    int cod, cant, sellers;
    printf("\nIngrese codigo de vendedor:");
    sellers = validar(1001, 1005, 0);
    while(sellers != 0){
        printf("\nIngrese codigo de producto:  ");
        do{
            scanf("%i", &cod);
            cod = posBuscar(vcod, cod, 15);
            if(cod == -1)
                printf("\nIngrese codigo valido");
        }while(cod == -1);
        printf("\nIngrese cantidad vendida:");
        cant = validar(0, 1000, 12);
        vcant[cod] += cant;
        switch (sellers)
        {
        case 1001:
            vsellers[0]++;
            break;
        case 1002:
            vsellers[1]++;
            break;
        case 1003:
            vsellers[2]++;
            break;
        case 1004:
            vsellers[3]++;
            break;
        case 1005:
            vsellers[4]++;
            break;
        }
        printf("\nIngrese codigo de vendedor:");
        sellers = validar(1001, 1005, 0);
    } 
}