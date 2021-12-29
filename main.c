#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "graph.h"



int short_path(pnode* head, int src, int dst);
void build_graph_cmd(pnode *pn)
/// *pn->id ||(**pn).id || pn =other_pn
{

}
void per(pnode* head, p_d_node *e, int cur, int size, int count, int* min)
{
    if(size==0)
    {
        int res = TSP(head, cur, count);
        if((*min) > res)
        {
            printf("sooo");
            *min = res;
        }
    }
    p_d_node d = *e;
    while(d)
    {
        if(d->visit==0)
        {
            d->visit =1;
            cur = cur*10 + (d->node_id);
            per(head, e, cur, size-1, count+1, min);
        }
        d->visit =0;
        d = d->next;
    }
}
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
    return sum;
}
int c_tsp(pnode  head)
{
    p_d_node d = NULL;
    pnode  l=NULL;
    pnode list = head;
    int size =0;
    int n;
    if(scanf("%d", &size));
    for( int i=0 ; i< size ;i++)
    {
        if(scanf("%d", &n));
        pnode temp = (pnode) malloc(sizeof(node));
        temp->id = n;
        temp->edges = find_node(n, head)->edges;
        temp->next = l;
        l = temp;
    }
    while(l)
    {
        l = (l)->next;
    }
    make_D(&d, &l);
    int* res = (int*) malloc(sizeof(int));
    *res = inf;
    per(&head, &d, 0, size, 0  ,res);
    return(*res);
}
int main()
{
    pnode pn =NULL;
    pnode s1 = addNode(&pn); //0
    pnode s2 = addNode(&pn);  ///1
    pnode s3= addNode(&pn);   //2
    pnode s4 = addNode(&pn);   //3
    add_edge(&pn, &s1);
    add_edge(&pn, &s1);
    add_edge(&pn, &s2);
    add_edge(&pn, &s3);
    add_edge(&pn, &s4);
    printf("%d", c_tsp(pn));
    return 0;
}