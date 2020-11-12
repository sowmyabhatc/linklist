#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "slist.h"


void test_empty_list(){
Slist s1=slist_new();
Slist *list=&s1;
assert(slist_length(list)==0);
}

void test_add_at_head(){
Slist s1=slist_new();
Slist *list=&s1;
assert (slist_length(list) ==0);
list=slist_addnode_head(list,10);
assert(slist_length(list)==1);
list=slist_addnode_head(list,20);
list=slist_addnode_head(list,30);
assert(slist_length(list)==3);
assert(slist_lookup(list,20)==1);
}

void test_add_at_tail(){
Slist s1=slist_new();
Slist *list=&s1;
assert (slist_length(list) ==0);
list=slist_addnode_tail(list,10);
assert(slist_length(list)==1);
list=slist_addnode_head(list,20);
list=slist_addnode_head(list,30);
assert(slist_length(list)==3);

}


void test_delnode_head(){
Slist s1=slist_new();
Slist *list=&s1;

list=slist_addnode_tail(list,10);
list=slist_addnode_head(list,20);
list=slist_addnode_head(list,30);
assert(slist_length(list)==3);
list=slist_delnode_head(list);
assert(slist_length(list)==2);
assert(slist_lookup(list,30)==0);
assert(slist_lookup(list,20)==1);
list=slist_addnode_tail(list,30);
list=slist_addnode_head(list,40);
assert(slist_length(list)==4);
}


void test_delnode_tail(){
Slist s1=slist_new();
Slist *list=&s1;
list=slist_addnode_tail(list,10);
list=slist_addnode_head(list,20);
list=slist_addnode_head(list,30);
assert(slist_length(list)==3);
list=slist_delnode_tail(list);
assert(slist_length(list)==2);
assert(slist_lookup(list,30)==0);
assert(slist_lookup(list,20)==1);
list=slist_addnode_tail(list,30);
list=slist_addnode_head(list,40);
assert(slist_length(list)==4);
assert(slist_lookup(list,40)==1);
list=slist_delnode_tail(list);
list=slist_delnode_tail(list);
list=slist_delnode_tail(list);
list=slist_delnode_tail(list);
assert(slist_length(list)==0);
}


void test_maxmin(){
Slist s1=slist_new();
Slist *list=&s1;
list=slist_addnode_tail(list,10);
list=slist_addnode_head(list,20);
list=slist_addnode_head(list,30);
assert(slist_length(list)==3);
assert(maxmin(list)==10);
list=slist_addnode_head(list,5);
assert(maxmin(list)==10);
}


void test_slist_addnode_middle(){
Slist s1=slist_new();
Slist *list=&s1;
assert (slist_length(list) ==0);
list=slist_addnode_head(list,10);
list=slist_addnode_head(list,20);
list=slist_addnode_head(list,30);
list=slist_addnode_head(list,40);
assert(slist_length(list)==4);
list=slist_addnode_middle(list,15,2);
assert(slist_lookup(list,15)==1);
assert(slist_length(list)==5);
}

void test_slist_delnode_middle(){
Slist s1=slist_new();
Slist *list=&s1;
assert (slist_length(list) ==0);
list=slist_addnode_head(list,10);
list=slist_addnode_head(list,20);
list=slist_addnode_head(list,30);
list=slist_addnode_head(list,40);
assert(slist_length(list)==4);
list=slist_delnode_middle(list,2);
assert(slist_lookup(list,30)==0);
list=slist_addnode_head(list,100);
assert(slist_length(list)==4);
list=slist_delnode_middle(list,2);
assert(slist_lookup(list,40)==0);
assert(slist_length(list)==3);

}

void test_slist_reverse(){
Slist s1=slist_new();
Slist *list=&s1;
assert (slist_length(list) ==0);
list=slist_addnode_head(list,10);
list=slist_addnode_head(list,20);
list=slist_addnode_head(list,30);
list=slist_addnode_head(list,40);
list=slist_reverse(list);
assert(slist_length(list)==4);
list=slist_delnode_middle(list,2);
assert(slist_lookup(list,20)==0);
assert(slist_length(list)==3);

}



void test_slist_unique(){
Slist s1=slist_new();
Slist *list=&s1;
assert (slist_length(list) ==0);
list=slist_unique(list,10);
list=slist_unique(list,20);
list=slist_unique(list,30);
list=slist_unique(list,30);
list=slist_unique(list,30);
assert (slist_length(list) ==3);
list=slist_unique(list,40);
list=slist_unique(list,40);
assert (slist_length(list) ==4);

}

void test_areIdentical(){
Slist s1=slist_new();
Slist s2=slist_new();
Slist *list1=&s1;
Slist *list2=&s2;
list1=slist_addnode_head(list1,10);
list1=slist_addnode_head(list1,20);
list1=slist_addnode_head(list1,30);
list1=slist_addnode_head(list1,40);
list2=slist_addnode_head(list2,20);
list2=slist_addnode_head(list2,30);
list2=slist_addnode_head(list2,30);
list2=slist_addnode_head(list2,40);
assert (areIdentical(list1,list2)==0);

}


void test_slist_merge(){
Slist s1=slist_new();
Slist s2=slist_new();
Slist *list1=&s1;
Slist *list2=&s2;

list1=slist_addnode_head(list1,10);
list1=slist_addnode_head(list1,20);
list1=slist_addnode_head(list1,30);
list1=slist_addnode_head(list1,40);
assert (slist_length(list1) ==4);
list2=slist_addnode_head(list2,50);
list2=slist_addnode_head(list2,60);
list2=slist_addnode_head(list2,70);
assert (slist_length(list2) ==3);
assert (slist_length(slist_union(list1,list2)) ==8);
assert(slist_lookup(slist_union(list1,list2),60)==1);
}


void test_slist_intersection(){
Slist s1=slist_new();
Slist s2=slist_new();
Slist *list=&s1;
Slist *list1=&s2;
Slist s4=slist_new();
Slist *list4=&s4;

assert (slist_length(list1) ==0);
list=slist_addnode_head(list,20);
list=slist_addnode_head(list,4);
list=slist_addnode_head(list,15);
list=slist_addnode_head(list,10);

list1=slist_addnode_head(list1,10);
list1=slist_addnode_head(list1,2);
list1=slist_addnode_head(list1,4);
list1=slist_addnode_head(list1,8);

list4=slist_intersection(list,list1);
assert(slist_length(list4)==2);
assert(list4->head->data==10);

}

void test_empty_dlist(){
Dlist d1=dlist_new();
Dlist *list=&d1;
assert(dlist_length(list)==0);
}

void test_dlist_addnode_head(){
Dlist d1=dlist_new();
Dlist *list=&d1;
assert (dlist_length(list) ==0);
list=dlist_addnode_head(list,10);
assert(dlist_length(list)==1);
list=dlist_addnode_head(list,20);
list=dlist_addnode_head(list,30);
assert(dlist_length(list)==3);
assert(dlist_lookup(list,20)==0);
}


void test_dlist_delnode_head(){
Dlist d1=dlist_new();
Dlist *list=&d1;

list=dlist_addnode_head(list,10);
list=dlist_addnode_head(list,20);
list=dlist_addnode_head(list,30);
assert(dlist_length(list)==3);
list=dlist_delnode_head(list);
assert(dlist_length(list)==2);
assert(dlist_lookup(list,30)==1);
assert(dlist_lookup(list,20)==0);
list=dlist_addnode_head(list,30);
list=dlist_addnode_head(list,40);
assert(dlist_length(list)==4);
}


int main()
{

       test_empty_list();
       test_add_at_head();
       test_delnode_head();
       test_delnode_tail();
       test_maxmin();
       test_slist_addnode_middle();
       test_slist_delnode_middle();
       test_slist_reverse();
       test_slist_unique();
       test_areIdentical();
       test_slist_merge();
       test_slist_intersection();
       test_empty_dlist();
       test_dlist_addnode_head();
       test_dlist_delnode_head();

    return 0;
}

