#include <stdio.h>
#include <stdlib.h>
void password();
void heading();
void mainManue();
void addBook();
void viewBookList();
void Searchbook();
void editBook();
void deleteBook();
void  Help();
void Exit();
struct book_info{
 int id;
 char name[20];
 char author[20];
 int quantity;
 int rack;
 char catagory[20];

};
struct book_info a; //a.id, a.name
FILE *file,*file2;
void addBook(){

    int ID, count=0;
printf ("\n\n\t\t*************Add Book***************\n");
file=fopen("book.dat", "ab+");
printf("\t\t Enter ID:");
scanf("%d", &ID);


rewind(file);
while(fread(&a, sizeof(a),1,file)==1)
if(ID==a.id){

    printf("\n\n \t\t this book is already in library");
    count=1;
}

if (count==1){
 fflush(stdin);
    getchar();
  mainManue();
}
a.id=ID;
printf("\n\t\t Enter name:");
scanf("%s",a.name);
printf("\n\t\t Enter Author:");
scanf("%s",a.author);
printf("\n\t\t Enter quatitty:");
scanf("%d",&a.quantity);
printf("\n\t\t Enter rack:");
scanf("%d",&a.rack);
printf("\n\t\t Enter catagory:");
scanf("%s",a.catagory);

fseek(file,0,SEEK_END);
fwrite(&a,sizeof(a),1,file);
fclose(file);
printf("\n\n\t\t\t Book added successfully!");
fflush(stdin);
    getchar();
    mainManue();
}
void viewBookList(){
    printf("\n\n\t\t\t********************View Book***********************\n");
    printf("\n\t\t Book list in library\n\n");
    printf("\t\tID\t\tName\t\tAuthor\t\t\Quant\t\tRack\t\tcatagory\n");

    file=fopen("book.dat","rb");
    while(fread(&a,sizeof(a),1,file)){

        printf("\t\t%d", a.id);
        printf("\t\t%s", a.name);
        printf("\t\t%s", a.author);
        printf("\t\t%d", a.quantity);
        printf("\t\t%d", a.rack);
        printf("\t\t%s", a.catagory);
        printf("\n");
    }
    fclose(file);
fflush(stdin);
printf("Enter any key to go main Manue Again");
    getchar();
    mainManue();
}

void Searchbook() {
int name[20];
int count=0;
printf("\n\n\t\t\t********************Search Book***********************\n");

 file= fopen("book.dat","rb");
 printf("Enter Book name to Search:");
scanf("%s",name);
printf("\n\t\t Searching**************\n\n");
while(fread(&a,sizeof(a),1,file)==1){

    if(strcmp(a.name,name)==0){
            printf("\t\t\t************Your searched Book is found**************\n");
    printf("\t\tID\t\tName\t\tAuthor\t\t\Quant\t\tRack\t\t catagory\n");

        printf("\t\t%d", a.id);
        printf("\t\t%s", a.name);
        printf("\t\t%s", a.author);
        printf("\t\t%d", a.quantity);
        printf("\t\t%d", a.rack);
        printf("\t\t%s", a.catagory);
        printf("\n");
        count=1;

    }
}

if( count==0){
       printf("\t\t\t Opps! No book with this name in Library.....Try later\n");

   }
   fflush(stdin);
   getchar();
   mainManue();

}
void editBook(){
    int id;
    int count=0;
printf("\n\n\t\t\t********************Edit Book Book***********************\n");

 file= fopen("book.dat","rb+");
 printf("Enter Book id to Edit:");
 scanf("%d",&id);

while(fread(&a,sizeof(a),1,file)==1){
        if(id==a.id){
            printf("\t\tYour Entered Book is Available**** \n");
            printf("\t\t Enter ID:");
            scanf("%d", &id);
            printf("\n\t\t Enter name:");
            scanf("%s",a.name);
printf("\n\t\t Enter Author:");
scanf("%s",a.author);
printf("\n\t\t Enter quantity:");
scanf("%d",&a.quantity);
printf("\n\t\t Enter rack:");
scanf("%d",&a.rack);
printf("\n\t\t Enter catagory:");
scanf("%s",a.catagory);
fseek(file,ftell(file)-sizeof(a),0);
fwrite(&a,sizeof(a),1,file);
fclose(file);
fflush(stdin);
printf("Enter any key");
   getchar();
   mainManue();



        }


}

}
deleteBook(){

system("cls");
int d,count;
printf("\n\n\t\t\t**************delete Book**********************");
printf("\n\n\t\tEnter id for delete book:");
scanf("%d",&d);

file= fopen("book.dat","rb+");

rewind(file);
while(fread(&a,sizeof(a),1,file)==1)
{

    if(d==a.id)
        {
            printf("\n\n\t\tBook is available\n");
            printf("\n\n\t\tBook name is :%s",a.name);
            printf("\t\t rack no: %d", a.rack);
            count =1;

        }
}
        if(count==0)
        {
            printf("\n\n\t\tBook is not available\n");
        }
        else{
                file2 =fopen("text.dat","wb+");
                rewind(file);
        while(fread(&a,sizeof(a),1,file)==1){
                if(d!=a.id){
                fseek(file2, ftell(file2)-sizeof(a),0);
                fwrite(&a,sizeof(a),1,file2);
            }
        }
        fclose(file);
        fclose(file2);
        remove("book.dat");
        rename("text.dat","book.dat");
        file=fopen("book.dat","rb");
        fclose(file);
        printf("  has been deleted\n");
        }
        fflush(stdin);
        getchar();
        mainManue();
    }
  Help(){

  printf("/t /t 1.It's a simple library management System \n");
  printf("/t /t 2.Password is = nazninShohagi \n");
  printf("/t /t 3.To exit press 7 \n");

fflush(stdin);
        getchar();
        mainManue();




  }






Exit(){
system("cls");
printf("THANK YOU \n");
printf("Closing...........\n");
for(int i;i<1e9;i++){

}
exit(0);






}







int main()
{
   password();

   fflush(stdin);
    getchar();
}

mainManue(){
    int n;
    printf("\t\t\t\t");
    for(int i=1;i<30;i++){

        printf(" %c",3);
    }

 printf("\n\n\t\t\t\t\t***********MAIN MANUE***********\n");
   printf("\t\t\t\t\t 1. Add Book\n");
printf("\t\t\t\t\t 2. View Book List\n");
printf("\t\t\t\t\t 3. Search Book\n");
printf("\t\t\t\t\t 4. Edit Book\n");
printf("\t\t\t\t\t 5. delete Book\n");
printf("\t\t\t\t\t 6. Help\n");
printf("\t\t\t\t\t 7. Exit\n");
printf("\t\t\t\t*********************************************\n");
printf("\t\t\t\t\t Enter your choice:");
scanf("%d", &n);

if(n==1){
    addBook();

}
else if(n==2){
    viewBookList();

}
else if(n==3){
  Searchbook();

}
else if(n==4){

    editBook();
}
else if(n==5){

    deleteBook();
}
else if(n==6){
    Help();

}
else if(n==7){
    Exit();

}
else {
    printf(" Please enter your choice from 1 to 7 ");
 mainManue();
}




}
void heading(){

system("cls");
printf("\t\t\t\t");
    for(int i=1;i<30;i++){

        printf(" %c",3);
    }
printf("\n\n\t\t\t\t\t***********LIBRARY MANAGEMENT SYSTEM***********\n");



}
void password(){

heading();
char password1[20]="nazninshohagi";
char password2[20];
printf("\t\t\t\t\t\tEnter password:");
scanf("%s",&password2);


if(strcmp(password1,password2)==0){
        printf("\t\t\t\t\tPassword Matched. nice! you are logged in!\n");

}
 else{
    printf("\t\t\t\t\t wrong password! Try again\n");
    fflush(stdin);
    getchar();
    password();
}

    mainManue();

}
