#include "universalUtils.h"

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

typedef struct label
{
    char *name;
    size_t label_ip;

    label *next;
} label;

typedef struct list
{
    label *tail;
    label *head;

    size_t size;
} list;

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

/// @brief Constructs label.
/// @param name Name of label;
/// @param label_ip Ip of label.
label *labelConstructor (char *name, size_t label_ip);

/// @brief Destructs label.
/// @param Label Pointer to label.
void labelDestructor (label *Label);

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

/// @brief Constructs list.
list *listConstructor ();

/// @brief Destructs list.
/// @param List Pointer to list.
void listDestructor (list *List);

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

#define listDump(List) listDumpFunction(List, #List, __FILE__, __LINE__, __PRETTY_FUNCTION__)

/// @brief Dumps list.
/// @param List Pointer to list.
/// @param name Name of list.
/// @param file File where dump was called.
/// @param line Line where dump was called.
/// @param function Function where dump was called.
void listDumpFunction (list *List, const char *name,
                       const char *file, 
                       int line, const char *function);

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

/// @brief Pushes label to list.
/// @param List Pointer to list.
/// @param name Name of label.
/// @param label_ip Ip of label. 
ISERROR listPush (list *List, char *name, size_t label_ip);

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
