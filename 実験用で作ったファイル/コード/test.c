#include <stdio.h>
#include <string.h>

void succeeded(){
    puts("auth succeeded!");
}

void failed(){
    puts("auth failed");
}

int main(int argc, char const *argv[])
{
    char password[256];
    printf("Enter password: ");
    scanf("%s", password);
    if(strcmp(password, "Suk1yaki_i5_delici0us")==0){
        succeeded();
    }else{
        failed();
    }

    return 0;
}