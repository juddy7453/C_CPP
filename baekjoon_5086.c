#include <stdio.h>

int main()
{
    int n = 0;
    int m = 0;
    
    do{
        scanf("%d" , &n);
        scanf("%d", &m);
        
        if (n == 0 && m == 0)
            break;

        else if(n <= m){
            if(m % n == 0){
                printf("factor\n");
            }
            else{
                printf("neither\n");
            }
        }
        else{
            if(n % m == 0){
                printf("multiple\n");
            }
            else{
                printf("neither\n");
            }
        }
    }while(n != 0 || m != 0);
    
    return 0;
    
}
