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
    scanf("%s",u.email);
    printf("enter contact number:");
    scanf("%s",u.contact);
    printf("enter password:");
    scanf("%s",u.password);
    fprintf(fp,"%d %s %s %s %s\n",u.id,u.name,u.email,u.contact,u.password);
    fclose(fp);
    printf("user Registered successfully\n");
}
void viewUsers(){
    struct User u;
    FILE *fp = fopen("store.txt","r");
    while(fscanf(fp,"%d %s %s %s %s",&u.id,u.name,u.email,u.conctact,u.password)!=EOF)
    {
        printf("ID:%d Name:%s Email:%s Contact:%s\n",u.id,u.name,u.email,u.contact);
    }
    fclose(fp);
}
void loginUser(){
    struct User u;
    int id;
    char pass[20];
    int found =0;
    FILE *fp=fopen("store.txt","r");
    printf("Enter User ID:");
    scanf("%d",&id);
    printf("Enter Password:");
    scanf("%s",pass);
    while(fscanf(fp,"%d %s %s %s %s",&u.id,u.name,u.email,u.contact,u.password)!=EOF){
        if(u.id==id&&strcmp(u.password,pass)==0){
            printf("Login Successfull!\n");
            found=1;
            break;
        }
    }
    if(!found)
    printf("Invalid ID or Password\n");
    fclose(fp);
 }
 void upadateUser()
 {
    struct User u;
    int id;
    FILE *fp=fopen("store.txt","r");
    FILE *temp=fopen("temp.txt","w");
    printf("Enter User ID to updates:");
    scanf("%d",&id);
    while(fscanf(fp,"%d %s %s %s %s",&u.id,u.name,u.email,u.contact,u.password)1=EOF){
        if(u.id==id){
            printf("Enter New Name:");
            scanf("%s",u.name);
            printf("Enter New Email:");
            scanf("%s",u.email);
            printf("Enter New Contact:");
            scanf("%s",u.contact);
            printf("Enter New Password:");
            scanf("%s",u.password);
            printf("User Updated !\n");
        }
        fprintf(temp,"%d %s %s %s %s\n",u.id,u.name,u.email,u.contact,u.password);

    }
    fclose(fp);
    fclose(temp);
    remove("store.txt");
    rename("temp.txt","store.txt");

 }
 void deleteUser(){
    struct User u;
    int id;
    FILE *fp=fopen("store.txt","r");
    FILE *temp=fopen("temp.txt","w");
    printf("Enter User ID to delete :");
    scanf("%d",&id);
    while(fscanf(fp,"%d %s %s %s %s ",&u.id,u.name,u.email,u.contact,u.password)!=EOF)
    {
        if(u.id!=id)
        {
            fprintf(temp,"%d %s %s %s %s\n",&u.id,u.name,u.email,u.contact,u.password);
        }
    }
    fclose(fp);
    fclose(temp);
    remove("store.txt");
    rename("temp.txt","store.txt");
    printf("User Deleted Successful\n");

 }
 int main(){
    int choice ;
    while(1)
    {
        printf("\nUser Management System \n");
        printf("1.Resgister User\n");
        printf("2.View Users\n");
        printf("3.Login\n");
        printf("4.Upadate User \n");
        printf("5.Delete User\n");
        printf("6.Exit\n");
        printf("Enter choice:");
        scanf("%d",&choice);
        switch(choice){
            case 1:registerUser();
            break;
            case 2:viewUser();
            break;
            case 3:loginUser();
            break;
            case 4:updateUser();
            break;
            case 5:deleteUser();
            break;
            case:exit(0);
            default:printf("Invalid Choice \n");
        }
    }
    return 0;
 }