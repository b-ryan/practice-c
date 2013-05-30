typedef struct List* t_list;

/* Construction and deletion */
t_list   list_new      ();
void     list_free     (t_list list);

/* Inserting and removing */
void     list_append   (t_list list, int data);

/* Counting and getting */
int      list_count    (t_list list);
int      list_find     (t_list list, int data);
int      list_get      (t_list list, int index);
