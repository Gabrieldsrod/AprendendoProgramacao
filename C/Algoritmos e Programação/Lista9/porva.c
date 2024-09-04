#include <stdio.h>

 

int main(){

            int x = 4, y = 19;

 

 

            while( x < 16 && y < 27)

            {

                        printf("%i ", y + x );

            

                        x = x + 2;

                        y = y + 2;

            }

 

            return 0;

}