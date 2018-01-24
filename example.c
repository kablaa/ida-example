#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#define MAX_NAME_LEN 20
#define MAX_BOOK_TILE_LEN 100
#define MAX_NUM_USERS 10



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
void clearstdin();

//globals
int g_numUsers=0;

int main(int argc, const char *argv[])
{
    char selection;
    int id = 0;
    User *userList[MAX_NUM_USERS];
    while(selection != 'q'){
    printMenue();
    selection = getchar();
    clearstdin();
        if(selection == 'a'){
            if(g_numUsers < MAX_NUM_USERS){
                User * newUser = createUser();
                userList[g_numUsers] = newUser;
                puts("----------------------------------");
                puts("new user added to database : ");
                printUser(newUser);
            }else
                puts("database is at capacity");
        }else if(selection == 'l'){
            puts("enter id: ");
            id = getchar() - '0';
            clearstdin();
            if(id > 0 && id <= g_numUsers )
                printUser(userList[id ]);
            else
                puts("invalid user id");
        }
    }
    
    return 0;
}
void clearstdin(){
    char c;
    while ((c = getchar()) != '\n' && c != EOF) { }
}
void printMenue(){
    puts("----------------------------------");
    puts("a: add new user (max of 10 users)");
    puts("l: list user by id");
    puts("q: Quit");
    puts("----------------------------------");
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
    clearstdin();
    return newBook;
}
User* createUser() {
    printf("user name (max len %d): ",MAX_NAME_LEN);
    fflush(stdout);
    User *newUser = malloc(sizeof(User));
    g_numUsers +=1;
    newUser -> id = g_numUsers;
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
