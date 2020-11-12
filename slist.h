#include<stdint.h>
#ifndef SLIST_H_INCLUDED
#define SLIST_H_INCLUDED

typedef struct _node_ Node;

struct  _node_{
int32_t  data;
Node     *next;
Node     *prev;
};

//location where the first node is present

typedef struct _slist_ Slist;
struct _slist_ {
Node   *head;
Node   *tail; //minimize the traversal time
uint32_t  length;

};


typedef struct _dlist_ Dlist;
struct _dlist_ {
Node   *head;
uint32_t  length;
};

Slist     slist_new();   //initializes single linked list
uint8_t   slist_lookup(const Slist *list, int32_t key);  //to check whether a particular element is present in the readable list or no
uint32_t  slist_length (const Slist *list);
Slist*    slist_addnode_head(Slist *list,int32_t value); //add head at the first postion not a readable list we need editable list
Slist*    slist_addnode_head(Slist *list,int32_t value);
Slist*    slist_delnode_head(Slist *list);//del the node
Slist*    slist_delnode_tail(Slist *list);
int32_t   maxmin(Slist *list);
Slist*    slist_addnode_middle(Slist *list,int32_t value,int pos);
Slist*    slist_delnode_middle(Slist *list,int pos);
Slist*    slist_reverse(Slist *list);
Slist*    slist_unique(Slist *list,int32_t value);
uint8_t   areIdentical(Slist *list1, Slist *list2);
Slist*    slist_union(Slist *list1,Slist *list2);
Slist*    slist_intersection(Slist *list,Slist *list1);
Dlist     dlist_new();
Dlist*    dlist_addnode_head(Dlist *list,int32_t value);
uint8_t   dlist_lookup(const Dlist  *list, int32_t  key);




#endif // SLIST_H_INCLUDED
