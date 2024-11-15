#include <stdio.h>

// Filtro para checar se os números são diferentes entre si dentro da combinação gerada!
int sem_repeticao (int a, int b, int c, int  d, int e, int f)    
{
if (a < b && b < c && c < d && d < e && e < f)
    {
        return 0;  
    }
   else
    { 
        return 1;                 
    }
}  

// Dada uma combinação e quatro ou mais números sejam da mesma dezena, a jogada será invalidada.
int quatro_mesma_dezena (int a, int b, int c, int d, int e, int f)
{
  // Verificar se a,b,c,d pertencem a mesma dezena.

  if (a >=  1 && d <= 9)
  {
    return 1;
  }
  if (a >= 10 && d <= 19)
  {
    return 1;
  }
  if (a >= 20 && d <= 29)
  {
    return 1;
  }
  if (a >= 30 &&  d <= 39)
  {
    return 1;
  }
  if (a >= 40 && d <= 49)
  {
    return 1;
  }
   if (a >= 50 && d <= 59)
  {
    return 1;
  }

  // Verificar se b,c,d,e pertencem a mesma dezena.
  if (b >=  1 && e <= 9)
  {
    return 1;
  }
  
  if (b >= 10 && e <= 19)
  {
    return 1;
  }
  
  if (b >= 20 && e <= 29)
  {
    return 1;
  }
  
  if (b >= 30 && e <= 39)
  {
    return 1;
  }
  
  if (b >= 40 && e <= 49)
  {
    return 1;
  }
 
  if (b >= 50 && e <= 59)
  {
    return 1;
  } 

  //Verificar se c,d,e,f pertencem a mesma dezena.
  if (c >=  1 && f <= 9)
  {
    return 1;
  }
  
  if (c >= 10 && f <= 19)
  {
    return 1;
  }
  
  if (c >= 20 && f <= 29)
  {
    return 1;
  }
  
  if (c >= 30 && f <= 39)
  {
    return 1;
  }
  
  if (c >= 40 && f <= 49)
  {
    return 1;
  }
 
  
  if (c >= 50 && f <= 59)
  {
    return 1;
  }
  
  else
  {
    return 0;
  }
  

}


int elimina_consecutivos (int a, int b, int c, int d, int e, int f)
{
    if ((a+1 == b && b+1 == c) ||
         (b+1 == c && c+1 == d)  ||
         (c+1 == d && d+1 == e) ||
           (d+1 == e && e+1 == f )) 
    {
        return 1;  
    }

        return 0; 

} 

// Elimina jogadas de acordo com o site oficial da Mega Sena
// que contenham algum dos quatro números listados como "Dezenas mais atrasdas".
// Dezenas á mais de vinte concursos sem serem sorteadas!

int dezenas_mais_atrasadas (int a, int b, int c, int d, int e, int f)

{
  if ( a == 12 || b == 12 || c == 12 || d == 12 || e == 12 || f == 12 ||
       a == 15 || b == 15 || c == 15 || d == 15 || e == 15 || f == 15 ||
       a == 41 || b == 41 || c == 41 || d == 41 || e == 41 || f == 41 ||
       d == 60 || e == 60 || f == 60 ) 
       
    		
    	return 1;

    	else 
      {
    		return 0;
    	}
    }
    
              
// Não permite contabilizar combinações que contenham dezenas que terminam com o mesmo algarismo,
 int termina_igual(int a, int b, int c, int d, int e, int f)
 {
  if ((a % 10) == (b % 10) && (b % 10) == (c % 10) && (c %10) == (d % 10)
       && (d % 10) == (e % 10) &&  (e % 10) == (f % 10))
  {
    return 1;
  }
  else
  {
    return 0;
  }
 } 

//Eliminar números primos consecutivos.
int verifica_primo (int x)
{
  if (x < 2)
    return 0;
  
  for ( int i = 2; i * i <= x; i++) 
  {
    if ( x % i == 0)
    {
      return 0;
    }
  }
     return 1; 
}
   



int sao_todos_primos(int a,int b,int c,int d,int e,int f)
// Se o retorno da função " verifica_primo " for == 0, então temos uma jogada boa, 
// pois eliminaremos combinações que contenham todas as seis dezenas sendo números primos.
{
if ((verifica_primo(a) == 1) && (verifica_primo(b) == 1) && (verifica_primo(c) == 1) && (verifica_primo(d) == 1) && (verifica_primo(e) == 1) && (verifica_primo(f) == 1))

    {
      return 1;  
    }
    else 
    {
    return 0; 
    }
}

// Não contabiliza combinações cuja distância entre os números sejam iguais,
// representando a eliminação de números dispostos nas diagonais da matriz com 60 dezenas
// De ordem 6x10
int tem_espacamento_igual (int a,int b,int c,int d,int e,int f)
{
   int x = b - a;
   if((c - b) == x && (d -c) == x && (e -d) == x && (f - e) == x){
      return 1;
   }
   else 
   {
      return 0; 
   }
}


int main () 
{
  long validas = 0;
  

    for (int a = 1; a <= 55; a++) 
    {    
      for (int b = 2; b <= 56; b++) 
       {
        for (int c = 3; c <= 57; c++)   
         {
          for (int d = 4; d <= 58; d++)  
           {
            for (int e = 5; e <= 59; e++) 
              {
                for (int f = 6; f <= 60; f++) 
                  {
                     if ((sem_repeticao(a,b,c,d,e,f)== 0) && 
                         (dezenas_mais_atrasadas (a,b,c,d,e,f) == 0) &&          
                         (elimina_consecutivos (a,b,c,d,e,f) == 0) &&
                         (termina_igual (a,b,c,d,e,f)== 0) &&
                         (tem_espacamento_igual (a,b,c,d,e,f) == 0) &&
                         (sao_todos_primos(a,b,c,d,e,f) == 0)  &&
                         (quatro_mesma_dezena (a,b,c,d,e,f) == 0))                           {
                          
                         validas += 1;
                           
                         if ((a == 10) && (b== 31) && (c == 35) && (d == 45) && (e == 50) && (f == 55))
		                     {
		                      printf("Concurso *2781* >> ENCONTRADO <<\n");
		                      }
		                     if ((a == 6) && (b== 11) && (c == 16) && (d == 25) && (e == 28) && (f == 45))
		                      {
		                       printf("Concurso *2782* >> ENCONTRADO <<\n");
		                      }
		                     if ((a == 7) && (b== 30) && (c == 38) && (d == 39) && (e == 43) && (f == 54))
		                      {
		                       printf("Concurso *2783* >> ENCONTRADO <<\n");
		                      }   
		                     if ((a == 27) && (b== 30) && (c == 35) && (d == 44) && (e == 57 )&& (f == 59))
		                      {
		                       printf("Concurso *2784* >> ENCONTRADO <<\n");
		                      } 
		                     if ((a == 20) && (b== 27) && (c == 48) && (d == 50) && (e == 57) && (f == 59))
		                      {
		                       printf("Concurso *2785* >> ENCONTRADO <<\n");
		                      }
		                     if ((a == 6) && (b== 11) && (c == 17) && (d == 20) && (e == 40) && (f == 51))
		                      {
		                       printf("Concurso *2786* >> ENCONTRADO <<\n");
		                      }
		                     if ((a == 8 )&& (b== 10) && (c == 23) && (d == 34) && (e == 36) && (f == 50))
		                      {
		                       printf("Concurso *2787* >> ENCONTRADO <<\n");
		                      }
		                     if ((a == 23) && (b== 37) && (c == 39) && (d == 47) && (e == 52) && (f == 56))
		                      {
		                       printf("Concurso *2788* >> ENCONTRADO <<\n");
		                      }
		                     if ((a == 3) && (b== 17) && (c == 18) && (d == 19) && (e == 20) && (f == 55))
		                      {
		                       printf("Concurso *2789* >> ENCONTRADO <<\n");
		                      }
		                     if ((a == 29 )&& (b== 32) && (c == 40) && (d == 42) && (e == 49) && (f == 58))
		                      {
		                      printf("Concurso *2790* >> ENCONTRADO <<\n");
		                      } 


                         }
                       }      
                    }         
                 }             
              }                 
           } 
    }                    

    printf ("\n *°*°*°*°*°*°*°*°*°°*°*°*°*°*°*°*°*°*°*°*°*\n");
    printf ("\n");
    printf (" >> MELHORES JOGADAS POSSÍVEIS: %li <<\n", validas);
    printf ("\n");


    return 0;
}

