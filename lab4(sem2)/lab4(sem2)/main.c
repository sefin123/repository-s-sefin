#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Header.h"
//
//#define MAX_STRING_LENGTH 256
//#define NULL_STRING "NULL"
//
//#define UNUSED (void)
//
//typedef struct Node {
//    char word[MAX_STRING_LENGTH];
//    struct Node* left;
//    struct Node* right;
//} Node;
//
//Node* initNode(Node* self) {
//    *self = (Node){0};
//    return self;
//}
//
//Node* createNode(const char* word, Node* left, Node* right) {
//    Node* node = initNode(malloc(sizeof(*node)));
//    strcpy(node->word, word);
//    node->left = left;
//    node->right = right;
//    return node;
//}
//
//void Print(Node* root, int indent) {
//    if (root == NULL) {
//        printf("%*s%s\n", indent, "", NULL_STRING);
//        return;
//    }
//
//    printf("%*s%s\n", indent, "", root->word);
//    Print(root->left, indent + 2);
//    Print(root->right, indent + 2);
//}
//
//void serializeTree(Node* root, FILE* out) {
//    if (root == NULL) {
//        fprintf(out, "%s\n", NULL_STRING);
//        return;
//    }
//
//    fprintf(out, "%s\n", root->word);
//    serializeTree(root->left, out);
//    serializeTree(root->right, out);
//}
//
//char* lightTrimEnd(char* str) {
//    if (str == NULL) return NULL;
//
//    const size_t length = strlen(str);
//
//    size_t i = length; // str[length] == '\0'
//    while (i > 0 && isspace(str[i - 1])) i--;
//    str[i] = 0;
//
//    return str;
//}
//
//Node* deserializeTree(FILE *in) {
//    Node* node = initNode(malloc(sizeof(*node)));
//    if (fgets(node->word, 256, in) == NULL) return NULL; // end of file
//
//    lightTrimEnd(node->word);
//
//
//    if (strcmp(node->word, NULL_STRING) == 0) {
//        free(node);
//        return NULL;
//    }
//
//    node->left = deserializeTree(in);
//    node->right = deserializeTree(in);
//
//    return node;
//}
//
//Node* addNode(Node* root, char *buf) {
//    Node* new = malloc(sizeof(*new));
//    root->left = NULL;
//    root->right= NULL;
//    strcpy(root->word, buf);
//}
//
//void correctAnswersTree(Node* node) {
//    printf("\nWhat was that?\nName: ");
//    char answer[MAX_STRING_LENGTH];
//    while (getchar() != '\n');
//    fgets(answer, MAX_STRING_LENGTH, stdin);
//    answer[strcspn(answer, "\n")] = '\0';
//
//
//    printf("\nWhat question is better to ask?\nQuestion: ");
//    char question[MAX_STRING_LENGTH];
//    fgets(question, MAX_STRING_LENGTH, stdin);
//    question[strcspn(question, "\n")] = '\0';
//
//
//
//    node->left = createNode(node->word, NULL, NULL);
//    node->right = createNode(answer, NULL, NULL);
//
//    strcpy(node->word, question);
//}
//
//void gameAkinator(Node* root) {
//    printf("%s?\n1.yes//0.no\nchoose: ", root->word);
//    int choice;
//    (void)scanf("%d", &choice);
//    
//    if (!(root->right == NULL || root->left == NULL)) {
//        if (choice == 0)gameAkinator(root->left);
//        if (choice == 1)gameAkinator(root->right);
//    }
//
//    if (root->right == NULL && root->left == NULL) {
//        if (choice == 0) correctAnswersTree(root);
//        if (choice == 1) printf("\nEnd of the game\n");
//    }
//
//}

int main() {


    FILE* in = fopen("test.txt", "r");
    Node* root = deserializeTree(in);
    fclose(in);

    gameAkinator(root);

    serializeTree(root, fopen("test.txt", "w"));

    return 0;
}