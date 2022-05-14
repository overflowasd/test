#include <iostream>

int main(int argc, char* argv[]){
    int i = 1; 
    int n = atoi(argv[1]);
    int m = atoi(argv[2]);

    do {

        std::cout << ((i == 0) ? n : i);
        
        i=(i+m-1)%n;    

        } while (i!=1);
}