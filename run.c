#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "graph.h"

void com_a(pnode * head)
{
    int size;
    if(scanf("%d", &size)==1);
    return;
}
char com_n(pnode * head)
{
    printf("insert new block \n");
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
    if( scanf("%d", &dst));
    int res = short_path(head, src, dst);
    if(res ==inf)
    {
        printf("%d", -1);
    }
    printf("%d", res);
}
void com_t(pnode * head)
{
    char c;
    int res = c_tsp(head);
    printf("%d", res);
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
            f =1;
            com_t(head);
            continue;
        }
    }
}