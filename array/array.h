typedef struct Array* t_array;

/* Construction & deletion */
t_array      array_new       ();
void         array_free      (t_array array);

/* Insert & removing */
void         array_append    (t_array array, int value);

/* Getting & inspection */
int          array_count     (t_array array);
int          array_get       (t_array array, int index);
void         array_print     (t_array array);
