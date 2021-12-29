#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "graph.h"



int short_path(pnode* head, int src, int dst);

// void per (p_d_node * head, int size, int num, int* min)
// {
//     if(size==0)
//     {
//         printf("%d\n", num);
//     }
//     p_d_node p = *head;
//     while(p)
//     {
//         if(p->visit==0)
//         {
//             p->visit =1;
//             per(head, size-1, num*10 + p->node_id);
//             p->visit =0;
//         }
//         p = p->next;
//     }
// }

int c_tsp(pnode* head)
{
    int * min;
    *min = inf;
    int size;
    p_d_node d = NULL;
    pnode p =NULL;
    int my_id;
    if(scanf("%d", &size));
    for (int i=0; i<size; i++)
    {
        if(scanf("%d", &my_id));
        p = find_node(my_id, *head);

    }
}
void com_a(pnode * head)
{
    int size;
    if(scanf("%d", &size)==1);
    return;
}
char com_n(pnode * head)
{
    printf("imsert new block \n");
    pnode p = addNode(head);
    remove_all(&(p->edges));
    char c;
    int d;
    int w;
    do{
        if(add_edge(head, &p)==NULL)
        {
            c = getchar();
            return c;
        }
    } while(1);
}
char com_b(pnode * head)
{
    return ('n');
}
void com_d(pnode *head)
{
    pnode p = addNode(head);
    /// find the adress of this node
    remove_all(&(p->edges));
    /// remove all the edges from this node
    remove_to_id(head, p->id);
    /// remove edges to this node
    delete_node_byid(head, p->id);
    // delete this node after we free each edges/
}
void com_s(pnode * head)
{
    int src;
    int dst;
    if( scanf("%d", &src));
    if( scanf("%d", &sdst));
    int res = short_path(head, src, dst);
    printf("%d", res);
}
char com_t(pnode * head)
{
    int res = c_tsp(head);
    c =getchar();
    printf("%d", res);
    return c;
}
void cmd(pnode * head)
{
    char c;
    int call;
    int f =1;
    while(1)
    {
        printf("welcome");
        if(f==1)
        {
            if(scanf("%d", &call)!=1)
        {
            c = getchar();
        }
        }
        if(c=='A')
        {
            f=1;
            com_a(head);
            continue;
        }
        if(c=='B')
        {
            f =0;
            c= com_b(head);
            continue;
        }
        if(c=='n')
        {
            f =0;
            c = com_n(head);
            continue;
        }
        if(c=='D')
        {
            f =1;
            com_d(head);
            continue;
        }
        if(c=='S')
        {
            f =1;
            com_s(head);
            continue;
        }
        if(c=='T')
        {
            f =0;
            c= com_t(head);
            continue;
        }
    }
}

int main()
{
    pnode pn =NULL;
    // pnode s1 = addNode(&pn); //0
    // pnode s2 = addNode(&pn);  ///1
    // pnode s3= addNode(&pn);   //2
    // // pnode s4 = addNode(&pn);   //3
    // // add_edge(&pn, &s1);
    // // add_edge(&pn, &s1);
    // // add_edge(&pn, &s2);
    // // add_edge(&pn, &s3);
    // // add_edge(&pn, &s4);
    // p_d_node d= NULL;
    // int i=0;
    // make_D(&d, &pn);
    // per(&d, 3, 0);
    cmd(&pn);

    return 0;
}