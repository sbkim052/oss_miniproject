#include<stdio.h>

typedef struct{
    char name[20]; 
    int gram; 
    int price; 
    float price_gram;
    int star; 
} Snack;

int addSnack(Snack *s); 
void readSnack(Snack s); 
int updateSnack(Snack *s); 

void saveData(Snack *s[], int count); 
int loadData(Snack *s[]); 

void search(Snack *s[], int count); 
void search_Name(Snack *s[], int count); 
void search_Star(Snack *s[], int count); 
void search_Price(Snack *s[], int count);
