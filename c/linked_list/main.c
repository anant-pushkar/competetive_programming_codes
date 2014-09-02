/*
Project name : linked_list
Created on : Wed Aug  6 17:59:06 2014
Author : Anant Pushkar
Linked list library basd on stanford text
*/
#include"module.h"
typedef long long int lld;
typedef unsigned long long int llu;
int debug=0;
int main(int argc , char **argv)
{
	if(argc>1 && strcmp(argv[1],"DEBUG")==0) debug=1;
	
	list * l = create_list(10);
	print_list(l);
	printf("length : %d \n",get_length(l));
	
	printf("===========================================\n");
	
	node* ptr = find_node(l , 5);
	push(&ptr , 5);
	print_list(l);
	printf("count(5) : %d \n",get_count(l,5));
	
	printf("===========================================\n");
	
	ptr = get_nth(l,7);
	push(&ptr , 5);
	print_list(l);
	printf("count(5) : %d \n",get_count(l,5));
	
	printf("===========================================\n");
	
	printf("head : %d\n",l->head->val);
	printf("popped value : %d\n",pop_from_head(l));
	printf("head : %d\n",l->head->val);
	print_list(l);
	
	printf("===========================================\n");
	
	printf("tail : %d\n",l->tail->val);
	printf("popped value : %d\n",pop_from_tail(l));
	printf("tail : %d\n",l->tail->val);
	print_list(l);
	
	printf("===========================================\n");
	
	printf("Inserting at 0\n");
	insert_nth(l,0,10);
	print_list(l);
	printf("Inserting at 5\n");
	insert_nth(l,5,10);
	printf("5th node:%d\n",get_nth(l,5)->val);
	print_list(l);
	
	printf("===========================================\n");
	
	printf("Reversing list\n");
	reverse(l);
	print_list(l);
	
	printf("===========================================\n");
	
	printf("Sorting list\n");
	quicksort(l);
	print_list(l);
	
	printf("===========================================\n");
	
	printf("Removing duplicates\n");
	remove_duplicates(l);
	print_list(l);
	
	printf("===========================================\n");
	delete_list(l);
	
	return 0;
}
