#include <stdio.h>
#include <stdlib.h>

int Greedy(int distAB, int m,int n, int postos[]){
    
    int paradas[n], distMAX, distB,i=0,k;
    
    distMAX = m;           //Máxima distancia que o carro alcança sem parar no posto
    distB = distAB;          //distâncaia do carro até B
    
    for(k=1;k<=n;k++){
       
        if (distB <= distMAX){
            k=n;                    //Termina o laço
        }
        else if (postos[k] > distMAX){      //Se o carro não chega
                                            //no posto k, o posto 
            paradas[i] = postos[k-1];       //k+1 é adicionado ao
                                            //vetor de paradas e o            
            i++;                            //e enche o tanque
            distMAX = m + postos[k-1];
        }

    }
    
    
    if (distMAX<distB){             // se não chegar em B
        printf ("Você não consegue chegar em B");
    }
    else{
        for (k=0;k<i;k++){          // Se chegar em B as paradas são printadas
           printf("%d ", paradas[k]);
        }
    }
    
    
    return 0;
}

int main (){
    
    int distAB,m,n,k;
    
    scanf("%d", &distAB);   //distância  entre as cidades
    scanf("%d", &m);        //autonomia do carro
    scanf("%d", &n);        //número de postos pelo caminho
    
    int postos[n];          // distancias dos postos até A
    
    for(k=0;k<n;k++){         //Pega as distâncias dos postos
        scanf("%d", &postos[k]); 
    }
    
    postos[n] = distAB;     // Adiciona a cidade B como se fosse o posto mais distante
    
    Greedy(distAB,m,n,postos);
    
    return 0;
}