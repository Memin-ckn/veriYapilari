#include <stdlib.h>
#include <stdio.h>

// Sadece 1 veri ve sonraki node'un adresini tutan bir struct tanımladım
struct n
{
    int x;
    struct n *next;
};

typedef struct n node;

// Ekrana tüm node'ların x değerlerini yazdıran bir fonksyion
void yazdir(node *r)
{
    while (r != NULL)
    {
        printf("%d ", r->x);
        r = r->next;
    }
}

// Ekrana tüm node'ların adres değerlerini yazdıran bir fonksiyon
void adresYazdir(node *r)
{
    while (r != NULL)
    {
        printf("%p ", r);
        r = r->next;
    }
}

// Aldığı x sayısı kadar eleman ekleyen bir fonksiyon
void olustur(node *n, int x)
{
    for (int i = 1; i < x + 1; i++)
    {
        n->next = (node *)malloc(sizeof(node));
        n = n->next;
        n->x = i * 10;
        n->next = NULL;
    }
}

int main()
{
    node *root;
    root = (node *)malloc(sizeof(node));
    root->x = 0; // root'un x değerine 0 verdim anlaşılması için

    node *iter;  // Bir iterator tanımlamama gerek yoktu root da gönderebilirdim
    iter = root; // ancak iter göndermek daha mantıklı geldi

    olustur(iter, 9);
    yazdir(root);
    printf("\n");
    adresYazdir(root);

    return 0;
}

/*
    Sonuç olarak şunları gözlemledim:
        Root ile ikinci değer arasında 64 bit'lik bir fark söz konusu iken diğer node'lar arasında 16'bitlik farklar bulunuyor. Sebebini bilmiyorum :D
 */