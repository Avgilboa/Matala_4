#include <stdio.h>
#include <stdlib.h>
#include "graph.h"

pnode find_node(int id, pnode head)
{
    while(head!=NULL)
    {
        if(head->id==id)
        {
            return head;
        }
        head = head->next;
    }
    return NULL;
}
pnode addNode (pnode *head)
// node =Null -> bulid graph ->(keyListener)get(n) -> addNod ->(keyListener) ('n' [addNode],'int' [function addEdge(int,int)])
{
    int id;
    if(scanf("%d",&id)==0)
    {
        return NULL;
    }
    pnode ptn= find_node(id, *head);
    if(ptn==NULL)
    {
        ptn = (pnode) malloc(sizeof(node));
        if(ptn==NULL)
        {
            printf("eroor");
            return ptn;
        }
        ptn->id =id;
        ptn->next = *head;
        *head =  ptn;
    }
    return ptn;
}
void delete_first_node(pnode * head)
{
    if(*head==NULL) {return;}
    pnode p = *head;
    *head = p->next;
    free(p);
}
void delete_node(pnode* prev)
{
    pnode p = (*prev)->next;
    (*prev)->next = (*prev)->next->next;
    free(p);
}
void delete_node_byid(pnode * head, int id)
{
    if(*head==NULL) { return;}
    if((*head)->id==id)
    {
        delete_first_node(head);
    }
    pnode p =(*head)->next;
    pnode prev = *head;
    while(p)
    {
        if(p->id==id)
        {
            delete_node(&prev);
        }
        p = p->next;
        prev =prev->next;
    }
}
void delete_all_node(pnode * head)
{
    while(*head)
    {
        delete_first_node(head);
    }
}