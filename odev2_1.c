#include <stdio.h>
#include <stdlib.h>

// Struct tanımı
struct n
{
    int x;
    struct n *next;
};
typedef struct n node;

// Düğüm ekleme fonksiyonu
void ekle(node *r, int x)
{
    node *iter = r;

    // Root'u gösteren düğüme kadar ilerletir
    while (iter->next != r)
    {
        iter = iter->next;
    }
    iter->next = (node *)malloc(sizeof(node));
    iter->next->x = x;
    iter->next->next = r;
}

void yazdir(node *r)
{
    node *iter = r;

    do // do-while kullanmamın sebebi, ilk adımda iter'in root'u göstermesi
    {
        printf("%d ", iter->x);
        iter = iter->next;
    } while (iter != r);
}

int main()
{
    node *root = (node *)malloc(sizeof(node));
    root->next = root;
    root->x = 0;
    int i;

    for (i = 1; i < 10; i++)
    {
        ekle(root, i * 10);
    }

    printf("Dairesel Bağlı Liste: ");
    yazdir(root);

    return 0;
}
