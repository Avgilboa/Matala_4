#include <stdio.h>
#include <stdlib.h>
#include "graph.h"



int short_path(pnode* head, int src, int dst);
void build_graph_cmd(pnode *pn)
/// *pn->id ||(**pn).id || pn =other_pn
{

}
int per(pnode * head, int* per)
{
    
}

int TSP(pnode *head, int* per, int count)
{
    int sum =0;
    for(int i=0; i<count-1;i++)
    {
        sum += short_path(head, count[i], count[i+1]);
    }
    return sum;
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
    short_path(&pn, 0,2);
    return 0;
}