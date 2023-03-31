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
    printf("\n");
}

// Ekrana tüm node'ların adres değerlerini yazdıran bir fonksiyon
void adresYazdir(node *r)
{
    while (r != NULL)
    {
        printf("%p ", r);
        r = r->next;
    }
    printf("\n");
}

// Aldığı x sayısı kadar eleman ekleyen bir fonksiyon
void ekle(node *n, int x)
{
    for (int i = 1; i < x + 1; i++)
    {
        n->next = (node *)malloc(sizeof(node));
        n = n->next;
        n->x = i * 10;
        n->next = NULL;
    }
}


// Silme fonksiyonunu node* döndürecek şekilde yazdım çünkü eğer root silinirse yeni root belirlenmesi gerekecek.
node *sil(node *r, int sira)
{
    node *temp = r;
    node *iter = r;

    // Root silinmek istenirse burası çalışacak
    if (sira == 0)
    {
        temp = r;
        r = r->next;
        free(temp);
        return r;
    }

    // Silinmek istenen düğüme kadar ilerlemesi için:
    for (int i = 0; iter != NULL && i < sira - 1; i++)
    {
        iter = iter->next;
    }

    // Eğer var olmayan bir düğüm silinmeye çalışılırsa error almayalım diye
    if (iter == NULL || iter->next == NULL)
    {
        printf("Düğüm bulunamadı.\n");
        return r;
    }

    // Bu da artık silme işlemi
    temp = iter->next;
    iter->next = iter->next->next;
    free(temp);
    return r;
}

int main()
{
    node *root;
    root = (node *)malloc(sizeof(node));
    root->x = 0; // root'un x değerine 0 verdim anlaşılması için

    node *iter;  // Bir iterator tanımlamama gerek yoktu root da gönderebilirdim
    iter = root; // ancak iter göndermek daha mantıklı geldi

    ekle(iter, 9);
    yazdir(root);
    adresYazdir(root);
    root = sil(root, 20);
    yazdir(root);
    return 0;
}

/*
    Sonuç olarak şunları gözlemledim:
        Root ile ikinci değer arasında 64 bit'lik bir fark söz konusu iken diğer node'lar arasında 16'bitlik farklar bulunuyor. Sebebini bilmiyorum :D
 */