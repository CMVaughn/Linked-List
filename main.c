#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TITLE_LENGTH 32
#define MAX_AUTHOR_LENGTH 32


struct Books {
  char title[MAX_TITLE_LENGTH];
  char author[MAX_AUTHOR_LENGTH];
  unsigned int ISBN;
};

struct Library {
  struct Books* book;
  struct Library* next;
} library;

int init_books (struct Books* book, char* title, char* auth, unsigned int ISBN)
{
  strcpy(book->author, auth);
  strcpy(book->title, title);
  book->ISBN = ISBN;

  if (book->title != NULL)
  {
    return 1;
  }
  
  return 0;
}

struct Library* init_library(struct Books* book)
{
  struct Library* library = (struct Library*)malloc(sizeof(struct Library));
  library->book = book;
  library->next = NULL;
  return library;
}

void addBook (struct Library* library, struct Books* book)
{
  struct Library* activeNode = library->next;
  struct Library* prevNode = library;

  while (activeNode != NULL)
  {
    activeNode = activeNode->next;
    prevNode = prevNode->next;
  }

  activeNode = (struct Library*)malloc(sizeof(struct Library));
  activeNode->book = book;
  activeNode->next = NULL;
  prevNode->next = activeNode;

}

void printLibrary(struct Library* library)
{
  struct Library* activeNode = library;

  while (activeNode != NULL)
  {
    printf("Title: %s\nAuthor: %s\nISBN: %d\n\n", activeNode->book->title, activeNode->book->author, activeNode->book->ISBN);
    activeNode = activeNode->next;
  }
}

int main()
{
  struct Books book1, book2, book3, book4, book5;
  init_books(&book1, "Ender's Game", "Orson Scott Card", 812550706);
  init_books(&book2, "Speaker for the Dead", "Orson Scott Card", 812550757); 
  init_books(&book3, "Xenocide", "Orson Scott Card", 123456789);
  init_books(&book4, "Children of the Mind", "Orson Scott Card", 812522397);
  init_books(&book5, "Ender in Exile", "Orson Scott Card", 765344157);

  struct Library* library = init_library(&book1);
  addBook(library, &book2);
  addBook(library, &book3);
  addBook(library, &book4);
  addBook(library, &book5);

  printLibrary(library);


  
  
}