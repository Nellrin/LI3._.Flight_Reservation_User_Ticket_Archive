#ifndef BTREE_H
#define BTREE_H
////////////////////////////////////////////////////////


////////////////////////////////////////////////////////
typedef struct btree BTree;
////////////////////////////////////////////////////////


////////////////////////////////////////////////////////
BTree *createNode(void *data);
void insert(BTree **root, void *data, int (*compare)(const void *, const void *));
void free_tree(BTree *root);
////////////////////////////////////////////////////////


////////////////////////////////////////////////////////
double exists(const void * info);
////////////////////////////////////////////////////////


////////////////////////////////////////////////////////
BTree *search(BTree *root, char *key, int (*compare)(const void *, const char *));
double do_something(BTree *root, double (*f)(const void *));
double money_trees(BTree *root, char * start, char * end, double (*f)(const void *, char *, char *));
void get_tlines(BTree * root, char *** list_id,char *** list_dates, int * n, void (*f)(void *, char ***,char ***, int *));
void get_prefix(FILE * file,BTree * root, char * prefix, int * n,char F, void (*f)(FILE *, void *, int *,char, char *), short (*g)(void*,char*));
void get_every_node(FILE * file,BTree * root, int * n,char F, void (*f)(FILE * file,void *, int *, char));
////////////////////////////////////////////////////////

#endif