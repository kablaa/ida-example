#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#define MAX_NAME_LEN 20
#define MAX_BOOK_TILE_LEN 100


//globals
int g_numUsers=0;

//structures
typedef struct Book{
    char * title;
    int numPages;
}Book;

typedef struct User{
    int id;
    char *name;
    Book *favBook;
} User;

//funciton prototypes
User* createUser();
void printUser(User *user);
void printMenue();
Book *createBook();

int main(int argc, const char *argv[])
{
    User * newUser = createUser();
    printUser(newUser);
    
    return 0;
}
void printMenue(){
    puts("a: add new user");
    puts("l: list user by id");
    puts("q: Quit");
}

Book *createBook(){
    printf("Book Title (Max len %d): ", MAX_BOOK_TILE_LEN);
    fflush(stdout);
    Book *newBook = malloc(sizeof(Book));
    newBook -> title = malloc(sizeof(char)*MAX_BOOK_TILE_LEN +1);
    memset(newBook -> title, 0, MAX_BOOK_TILE_LEN);
    read(0,newBook ->title,MAX_BOOK_TILE_LEN);

    puts("how many pages?");
    scanf("%d",&newBook -> numPages);
    return newBook;
}
User* createUser() {
    printf("user name (max len %d): ",MAX_NAME_LEN);
    fflush(stdout);
    User *newUser = malloc(sizeof(User));
    newUser -> id = g_numUsers;
    g_numUsers +=1;
    newUser->name = malloc(sizeof(char)*MAX_NAME_LEN + 1);
    memset(newUser ->name, 0, MAX_NAME_LEN);
    read(0,newUser -> name, MAX_NAME_LEN);
    newUser -> favBook = createBook();
    return newUser;
}

void printUser(User *user){
    printf("ID: %d\n", user -> id);
    printf("name: %s", user->name);
    if(!user -> favBook){
        puts("user does not have a favorite book");
    }else{
        printf("Favorite Book: %s", user->favBook -> title) ;
        printf("number of pages: %d\n", user -> favBook -> numPages);
    }

}
