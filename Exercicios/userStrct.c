#include <stdio.h>
#include <string.h>

struct user{
    int telefone;
    char nome[30];
    char email[50];
};

int main(){
    struct user user1;

    strcpy(user1.email, "alexandre@gmail.com");
    strcpy(user1.nome, "Alexandre");
    user1.telefone=555;

    printf("%s\n", user1.nome);
    printf("%s\n", user1.email);
    printf("%d\n", user1.telefone);

    return 0;
}