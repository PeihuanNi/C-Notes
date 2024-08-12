#include <iostream>
#include <cstring>

void struct_func(struct Books books);

struct Books
    {
        char title[50];
        char author[50];
        int id; 
    };

int main(){
    
    Books books;
    books.id = 2;
    struct_func(books);
    return 0;
}

void struct_func(struct Books books){
    std::cout << books.id << std::endl;
}