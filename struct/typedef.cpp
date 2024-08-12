#include <iostream>
#include <cstring>

typedef struct Books
    {
        char title[50];
        char author[50];
        int id; 
    }Books;

void struct_func(Books books);

int main(){
    
    Books books;
    books.id = 2;
    struct_func(books);
    return 0;
}

void struct_func(Books books){
    std::cout << books.id << std::endl;
}