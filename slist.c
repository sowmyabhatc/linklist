#include<stdlib.h> //we need to dynamically allocate a amemory
#include<assert.h>
#include "slist.h"


Slist      slist_new(){
Slist s1= {NULL,NULL, 0};
return s1;
}



uint32_t slist_length(const Slist *list){
assert (list!=NULL);
return list->length;
}



//helper function which is not visible outside
static Node*   _get_new_node_(int32_t val){
Node *newnode=(Node*)malloc(sizeof(Node));
newnode->data=val;
newnode->next=NULL;
return newnode;
}


//adding a node in the beggining
Slist*    slist_addnode_head(Slist *list,int32_t value){
assert (list!=NULL);
Node  *new_node=_get_new_node_(value);
new_node->next=list->head;
list->head=new_node;
if(list->tail ==NULL){
    list->tail=new_node;
}
++list->length;

assert((list->length ==1  && list->head == list->tail) ||
       (list->length > 1   && list->head != list->tail));

return list;

}


//adding a node in the end
Slist* slist_addnode_tail(Slist *list,int32_t  val){
 assert(list!=NULL);
 Node *new_node=_get_new_node_(val);
 if(list->tail!=NULL){
    list->tail->next=new_node;
    list->tail=new_node;
 }
 else{
    list->head=list->tail=new_node;
 }
 ++list->length;
 assert((list->length == 1 && list->head==list->tail )||
        (list->length> 1 && list->head !=list->tail));

return list;
}



//finding a particular element
 uint8_t  slist_lookup(const Slist  *list, int32_t  key){
 assert (list!=NULL);
 Node *cur=list->head;

 for (cur=list->head; cur!=NULL; cur=cur->next){
    if (cur->data ==key){
        break;
    }
 }
 return (cur!=NULL);

 }



//deleting the first node


Slist*    slist_delnode_head(Slist *list){

assert (list!=NULL);
Node* temp;
if(list->head!=NULL){
    temp=list->head;
    list->head=list->head->next;
    if(list->head==NULL){
        list->tail=NULL;
    }
    --list->length;
free(temp);
}

return list;

}



//deleting the last node
Slist* slist_delnode_tail(Slist *list){
 assert(list!=NULL);
 Node *last,*cur;
if(list->tail!=NULL){
    last=list->tail;
    if(list->head==list->tail){
        list->head=list->tail=NULL;
    }
    else{
        for(cur=list->head;cur->next!=last;cur=cur->next){
            list->tail=cur;
            cur->next=NULL;
        }

    }

    --list->length;
    free(last);


return list;
}
}




//calculate maximum and minimum element of a single linked list

int32_t maxmin(Slist *list){
int max;
int min;

  Node* cur=list->head;
  max=cur->data;
  min=cur->data;
  for(cur=list->head;cur!=NULL;cur=cur->next){

        if(max<cur->data){
            max=cur->data;

        }
        if(min >cur->data){
            min=cur->data;
        }

    }

return min;


}


//one can add a new element after any specified element.


Slist*    slist_addnode_middle(Slist *list,int32_t value,int pos){
int i=1;
assert (list!=NULL);
if(pos >! list->length){
Node* cur=list->head;
for(i=1;i<pos;i++){
  cur=cur->next;
}
Node  *new_node=_get_new_node_(value);
new_node->next=cur->next;
cur->next=new_node;
}
++list->length;


return list;

}



//delete any specified element from the list.

Slist*    slist_delnode_middle(Slist *list,int pos){
int i=1;
assert (list!=NULL);
Node* cur;
if(pos >! list->length){
cur=list->head;


for (i=1;i<pos-1;i++){
  cur=cur->next;

}
Node  *new_node=cur->next;
cur->next=new_node->next;
free(new_node);

}
--list->length;



return list;

}


//method to reverse the elements in the same list.

Slist* slist_reverse(Slist *list){
 assert(list!=NULL);
{
    Node* prev=NULL;
    list->tail=prev;
    Node* cur=list->head;
    Node* next_node=list->head;
while(next_node!=NULL){
    next_node=next_node->next;
    cur->next=prev;
    prev=cur;
    cur=next_node;
    }
list->head=prev;

return list;
}
}









//Create two separate single lists. Check two list are same.
//If the two lists have the same number of elements in the same order, then they are treated as same.



uint8_t areIdentical(Slist *list1, Slist *list2)
{
    Node *a=list1->head;
    Node *b=list2->head;
     while (a != NULL && b != NULL)
    {
        if (a->data != b->data)
            return 0;


        a = a->next;
        b = b->next;
    }


    return (a == NULL && b == NULL);
}




//Write a method which creates the union of elements from two lists.

Slist* slist_union(Slist *list1,Slist *list2){

        assert((list1 && list2) != NULL);
        Node *cur = list1->head;
        Node *cur2 = list2->head;
        for(cur=list1->head;cur->next!=NULL;cur=cur->next);

        while(cur2 != NULL){
            int res = slist_lookup(list1,cur2->data);
            if (!res){
            Node *new_node = _get_new_node_(cur2->data);
            cur->next = new_node;
            cur=cur->next;
            ++list1->length;
            }
            cur2 = cur2->next;
        }
            return list1;
}


//Write a method which creates the intersection of elements from two lists.

Slist* slist_intersection(Slist *list,Slist *list1){



        Slist s3 = slist_new();
        Slist *list2= &s3;
        Node *cur = list->head;
        for(cur=list->head;cur!=NULL;cur=cur->next){
            int res = slist_lookup(list1,cur->data);
            if(res==1){
                list2 = slist_addnode_tail(list2,cur->data);
            }
        }
        return list2;

}


//Create single list such that it should always contain unique elements. Care should be taken that,
//if element is already present in the list, you should not add it again.




Slist*    slist_unique(Slist *list,int32_t value){

assert (list!=NULL);
if((slist_lookup(list,value))==0){
Node  *new_node=_get_new_node_(value);
new_node->next=list->head;
list->head=new_node;
if(list->tail ==NULL){
list->tail=new_node;
}
++list->length;
}


return list;

}







//Create double linked list with methods to add, remove, to check the existence of element.
Dlist      dlist_new(){
Dlist d1= {NULL,NULL, NULL,0};

return d1;
}

static Node*   _get_new_dnode_(int32_t val){
Node *newdnode=(Node*)malloc(sizeof(Node));
newdnode->data=val;
newdnode->next=NULL;
newdnode->prev=NULL;
return newdnode;
}

uint32_t dlist_length(const Dlist *list){
assert (list!=NULL);
return list->length;
}


//adding elements to the list

Dlist*    dlist_addnode_head(Dlist *list,int32_t value){

assert (list!=NULL);
Node  *new_node=_get_new_dnode_(value);
Node *cur=list->head;
if(list->head==0){
    list->head=cur=new_node;
}
else{
    cur->next=new_node;
    new_node->prev=cur;
    cur=new_node;
}
++list->length;

assert((list->length ==1  && list->head == cur) ||
       (list->length > 1   && list->head != cur));

return list;


}

//deleting the elements from the lists

Dlist*    dlist_delnode_head(Dlist *list){

assert (list!=NULL);
Node* temp;
if(list->head!=NULL){
    temp=list->head;
    list->head=list->head->next;
    list->head->prev=NULL;
    free(temp);
    --list->length;

}

return list;

}


//to check the existence of element.
uint8_t  dlist_lookup(const Dlist  *list, int32_t  key){
 assert (list!=NULL);
 Node *cur=list->head;

 for (cur=list->head; cur!=NULL; cur=cur->next){
    if (cur->data ==key){
        break;
    }
 }
 return (cur!=NULL);

 }

