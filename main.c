#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "graph.h"



int short_path(pnode* head, int src, int dst);
int * reversNUm(int curr, int size)
{
    int t = curr;
    int sum_of_digit = 0;
    while(t > 0)
    {
        t = t/10;
        sum_of_digit++;
    }
    int * arr = (int *)malloc(sizeof(int)*size);
    if(size > sum_of_digit)
    {
        int w = curr;
        arr[size -1] =0;
        for (int i=0;i<size-1;i++)
        {
            arr[i] = w%10;
            w=w/10;
        }
        return arr;
    }else{
        int w = curr;
        for (int i=0;i<size;i++)
        {
            arr[i] = w%10;
            w=w/10;
        }
        return arr;
    }
}
int TSP(pnode *head, int cur, int count)
{
    int sum =0;
    int *arr = reversNUm(cur,count);
    for(int i=0; i<count-1;i++)
    {
        sum += short_path(head, arr[i], arr[i+1]);
    }
    free(arr);
    return sum;
}
void per (pnode *q,p_d_node * head, int size, int num,int count, int* min)
{
    if(size==0)
    {
        printf("%d\n", num);
        TSP(q,num, size);
    }
    p_d_node p = *head;
    while(p)
    {
        if(p->visit==0)
        {
            p->visit =1;
            per(q, head, size-1, num*10 + p->node_id,count+1, min);
            p->visit =0;
        }
        p = p->next;
    }
}
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
        pnode temp;
        temp->id = p->id;
        pedge * t = &(find_node(my_id, *head)->edges);
        temp->edges =*t;
        temp->next = p;
        p = temp;
    }
    make_D(&d, &p);
    per(head,&d, size, 0, 0,min);
}


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