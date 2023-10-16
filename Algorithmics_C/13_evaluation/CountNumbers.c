/*
Etant donné une chaîne de caractères « chaine », écrire une fonction qui permet de compter le nombre de chiffres pouvant éventuellement être présents dans « chaine ».
Tester votre fonction depuis le main et afficher le nombre de chiffres trouvés dans les chaînes : ''JAVA8'' , ''Bon courage'', et ''Joyeuses fêtes 2023''


*/

#include<stdio.h>
#include<string.h>
#include<ctype.h>

int countNumbers(char sentence[]){

    int nb=0;
    for (int i = 0; i < strlen(sentence);i++){
        if(isdigit(sentence[i])){
            nb++;
        }

    }
    return nb;
}

int main(){

    char sentence[] = "Bon courage";
    printf("%d", countNumbers(sentence));
}