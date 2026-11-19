/******************************************************************************

Welcome to GDB Online.
  GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
  C#, OCaml, VB, Perl, Swift, Prolog, Javascript, Pascal, COBOL, HTML, CSS, JS
  Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Books {
    int id;
    char title[100];
    int price;
} book_t;

void total_price(book_t books[], int n) {
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += books[i].price;
    }
    printf("書籍總價錢：%d\n", sum);
}

void list_books(book_t books[], int n) {
    printf("=== 書籍資料 ===\n");
    for (int i = 0; i < n; i++) {
        printf("編號: %d | 書名: %s | 價錢: %d\n", books[i].id, books[i].title, books[i].price);
    }
}

int main() {
    int n = 3;
    book_t books[3] = {
        {1, "C Programming Language", 550},
        {2, "Operating System Concepts", 780},
        {3, "Computer Networks", 650}
    };

    list_books(books, n);
    total_price(books, n);

    FILE *fp = fopen("Book.bin", "wb");
    if (fp == NULL) {
        printf("無法開啟 Book.bin\n");
        return 1;
    }
    fwrite(&n, sizeof(int), 1, fp);
    fwrite(books, sizeof(book_t), n, fp);
    fclose(fp);

    return 0;
}