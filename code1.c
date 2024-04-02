#include <stdio.h>
#include <stdlib.h>

// Definisi struktur node
typedef struct Node {
    char alphabet;
    struct Node* link;
} Node;

// Definisi struktur stack
typedef struct {
    Node* top;
} Stack;

// Fungsi untuk membuat stack baru
Stack* createStack() {
    Stack* stack = (Stack*)malloc(sizeof(Stack));
    stack->top = NULL;
    return stack;
}

// Fungsi untuk mengecek apakah stack kosong
int isEmpty(Stack* stack) {
    return (stack->top == NULL);
}

// Fungsi untuk menambahkan elemen baru ke dalam stack
void push(Stack* stack, char data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->alphabet = data;
    newNode->link = stack->top;
    stack->top = newNode;
}

// Fungsi untuk menghapus dan mengembalikan elemen teratas dari stack
char pop(Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty. Cannot pop.\n");
        return '\0';
    }
    Node* temp = stack->top;
    char poppedValue = temp->alphabet;
    stack->top = temp->link;
    free(temp);
    return poppedValue;
}

// Fungsi untuk mencetak string "INFORMATIKA" dari stack jika ditemukan
void printInformatika(Node* start) {
    // Definisikan string yang ingin dicari
    char* word = "INFORMATIKA";
    int word_length = 11;

    // Mencari huruf pertama dari string di linked list
    while (start != NULL && start->alphabet != 'I') {
        start = start->link;
    }

    // Jika huruf 'I' tidak ditemukan di linked list
    if (start == NULL) {
        printf("String 'INFORMATIKA' not found.\n");
        return;
    }

    // Membuat stack baru untuk menampung huruf yang ditemukan
    Stack* stack = createStack();

    // Memasukkan huruf-huruf yang ditemukan ke dalam stack
    while (start != NULL) {
        if (start->alphabet == *word) {
            push(stack, start->alphabet);
            word++;
            // Jika seluruh huruf "INFORMATIKA" sudah ditemukan, cetak string tersebut dari stack
            if (*word == '\0') {
                // Menyimpan huruf-huruf dari stack ke dalam array
                char output[word_length];
                int i = 0;
                while (!isEmpty(stack)) {
                    output[i++] = pop(stack);
                }
                // Mencetak huruf-huruf yang tersimpan dalam array secara terbalik
                for (int j = i - 1; j >= 0; j--) {
                    printf("%c", output[j]);
                }
                printf("\n");
                return;
            }
        }
        start = start->link;
    }

    // Jika tidak semua huruf "INFORMATIKA" ditemukan dalam linked list
    printf("String 'INFORMATIKA' not found.\n");
}



int main() {
    // Inisialisasi node-node l1 hingga l9
    Node l1, l2, l3, l4, l5, l6, l7, l8, l9;

    // Inisialisasi linked list
    l1.link = NULL;
    l1.alphabet = 'F';
    l2.link = NULL;
    l2.alphabet = 'M';
    l3.link = NULL;
    l3.alphabet = 'A';
    l4.link = NULL;
    l4.alphabet = 'I';
    l5.link = NULL;
    l5.alphabet = 'K';
    l6.link = NULL;
    l6.alphabet = 'T';
    l7.link = NULL;
    l7.alphabet = 'N';
    l8.link = NULL;
    l8.alphabet = 'O';
    l9.link = NULL;
    l9.alphabet = 'R';

    // Hubungkan node-node sesuai dengan panah arahnya
    l7.link = &l1;
    l1.link = &l8;
    l8.link = &l2;
    l2.link = &l5;
    l5.link = &l3;
    l3.link = &l6;
    l6.link = &l9;
    l9.link = &l4;
    l4.link = &l7;

    // Tentukan node awal (starting point) ke l3
    Node* current = &l3;

    // Cetak "INFORMATIKA" jika ditemukan
    printInformatika(current);

    return 0;
}
