typedef struct List* t_list;

#ifndef LIST_ITEM_TYPE

  #define LIST_ITEM_TYPE int
  #define LIST_ITEM_FREE(item) /* noop */

#endif

/* Construction and deletion */
t_list              list_new      ();
void                list_free     (t_list list);

/* Inserting and removing */
void                list_append   (t_list list, LIST_ITEM_TYPE data);

/* Counting and getting */
int                 list_count    (t_list list);
int                 list_find     (t_list list, LIST_ITEM_TYPE data);
LIST_ITEM_TYPE      list_get      (t_list list, int index);
