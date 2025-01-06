//accepted
#include <stdio.h>

int main(){

        int i, j, array[100], k, n, count;

        scanf("%i %i", &n, &k);

        for(i = 0; i < n; i++){
            
            scanf("%i", &array[i]);

        } 


        for(i = 0; i < n; i++){
            
            for(j = i+1; j < n; j++){
                
                if(!((array[i]+array[j]) % k))
                    count++;

            }

        }

        printf("%i\n", count);

        return 0;    

    }