#include <stdio.h>
#include <stdlib.h>

typedef struct Link {
    int value;
    struct Link *next;
} Link;

int sll_indexOf_recur(Link* sll, int value) {
    
    if (sll==NULL)
        return -1;
    else if (sll->value==value)
        return 1;
    else
    {
        int pos=sll_indexOf_recur(sll->next, value);
        if (pos<0)
            return -1;
        else
            return 1+pos;
    }   
}

int main()
{
    Link *newLink=(Link *)malloc(sizeof(Link));
    newLink->next=NULL;
    newLink->value=1;
    Link *newLink2=(Link *)malloc(sizeof(Link));
    newLink2->value=2;
    newLink2->next=NULL;
    newLink->next=newLink2;
    Link *newLink3=(Link *)malloc(sizeof(Link));
    newLink3->value=3;
    newLink3->next=NULL;
    newLink2->next=newLink3;

    printf("%d\n",sll_indexOf_recur(newLink,2));
    printf("%d\n",sll_indexOf_recur(newLink,4));

    return 0;
}