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
    char username[256];
    char password[256];
    printf("Enter username: ");
    scanf("%s", username);
    printf("Enter password: ");
    scanf("%s", password);
    if(strcmp(username, "Hondhii")==0&&strcmp(password, "sukiyaki")==0){
        succeeded();
    }else{
        failed();
    }

    return 0;
}
