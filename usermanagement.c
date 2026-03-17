#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct User {
    int id;
    char name[50];
    char email[50];
    char contact[50];
    char password[50];
}
void resgisterUser() {
    struct User u;
    FILE *fp =fopen("store.txt","a");
    printf("enter User ID:");
    scanf("%d",&u.id);
    printf("enter Name :");
    scanf("%s",u.name);
    printf("enter Email:");
    scanf("%s",email);
    printf("enter contact number:");
    scanf("%s",u.contact);
    printf("enter password:");
    scanf("%s",u.password);
    fprintf(fp,"%d %s %s %s %s\n",u.id,u.name,u.email,u.contact,u.password);
    fclose(fp);
    printf("user registered successfully\n");
}