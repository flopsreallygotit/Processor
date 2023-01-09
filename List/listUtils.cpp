#include <malloc.h>

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

#include "listUtils.h"

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

label *labelConstructor (char *name, size_t label_ip)
{
    label *Label = (label *) calloc (1, sizeof(label));

    CHECKERROR(Label != NULL && 
               "Can't allocate memory for label.", 
               NULL);

    Label->name     = name;
    Label->label_ip = label_ip;
    Label->next     = NULL;

    return Label;
}

void labelDestructor (label *Label)
{
    if (Label == NULL)
        return;

    free(Label->name);
    Label->name = NULL;

    Label->label_ip = 0;

    free(Label);
    Label = NULL;

    return;
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

list *listConstructor ()
{
    list *List = (list *) calloc (1, sizeof(list));

    List->head = NULL;
    List->tail = NULL;
    List->size = 0;

    return List;
}

static void recursiveDestructor (label *Label)
{
    if (Label == NULL)
        return;

    recursiveDestructor(Label->next);

    labelDestructor(Label);

    return;
}

void listDestructor (list *List)
{
    if (List == NULL)
        return;
    
    recursiveDestructor(List->tail);

    List->size = 0;

    free(List);
    List = NULL;

    return;
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

void listDumpFunction (list *List, const char *name, 
                       const char *file, 
                       int line, const char *function)
{
    if (List == NULL)
        return;

    printf(BOLD MAGENTA 
           "\nList dump of list %s[%p] "
           "(Birth at %s:%d in %s)\n" 
           RESET,
           name, List, 
           file, line, function);

    printf(BOLD 
           "List tail: %p\n"
           "List head: %p\n"
           "List size: %lu\n" 
           RESET,
           List->tail, 
           List->head, 
           List->size);
    
    printf("{\n");

    label *Label = List->tail;

    for (size_t label_idx = 0; label_idx < List->size; label_idx++)
    {
        printf("    [%lu]: \"%s\" | %lu\n", label_idx, Label->name, Label->label_ip);

        Label = Label->next;
    }

    printf("}\n\n");

    return;
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

ISERROR listPush (list *List, char *name, size_t label_ip)
{
    CHECKERROR(List != NULL &&
               "Can't dump nullpointer.",
               NULLPOINTER);

    label *Label = labelConstructor(name, label_ip);

    CHECKERROR(Label != NULL &&
               "Can't create label.", 
               ALLOCATIONERROR);

    if (List->tail == NULL)
        List->tail = Label;
    
    if (List->head != NULL)
        List->head->next = Label;

    List->head = Label;
    List->size++;
        
    return NOTERROR;
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
