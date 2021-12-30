#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "graph.h"






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
    // p_d_node d= NULL;
    // int i=0;
    // make_D(&d, &pn);
    // per(&d, 3, 0);
    int num = c_tsp(&pn);
    return 0;
}