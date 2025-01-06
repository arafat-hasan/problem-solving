//accepted
#include <stdio.h>

int main(){
    
    int i,count=0;
    char array[100000];
    
    scanf("%s", array);
    for(i = 0; ; i++){
        if(array[i] == '\0')
            break;
        
        if(array[i] >= 'A' && array[i] <= 'Z')
            count++;       
        
    }
    
    printf("%i\n", count+1);
    
    return 0;
}
