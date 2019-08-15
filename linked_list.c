
/* 
File name is linked_list.c
 Purpose: file contains functions for manipulating singly linked list
 
 Revisions
 Doron Nussbaum 2018

 
 
 
 
 Copyright 2018 Doron Nussbaum
 
 */

/******************************************************************/
// INCLUDE 

#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "linked_list.h"


/************************************************************************/
// Define 



/************************************************************************/

/*
Purpose: insert a new node into the list as the first element
input
id - id of person
firstName - first name of person
familyName - family name of person

input/output
head - head of linked list

return
A pointer to the node that was allocated.  

NULL - if the operation was not successful

*/

PersonalInfo *insertToList(PersonalInfo **head, unsigned int id, 
        char *firstName, char *familyName)
{
	PersonalInfo *p;
	p=(PersonalInfo*)malloc(sizeof(PersonalInfo));
	if(p==NULL){
		return NULL;
	}
	
	p->id=id;
	strncpy(p->firstName,firstName,15);
	strncpy(p->familyName,familyName,15);
	p->next=(*head);
	(*head)=p;
	return p;

	// add code
       //NO!!!!
   //


}


/************************************************************************/
/*
Purpose: insert a new node into the list after the given node  

Input
node - the node after which the new node must be added to the list
id - id of person
firstName - first name of person
familyName - family name of person


return
A pointer to the node that was allocated.  

NULL - if the operation was not successful

*/


PersonalInfo *insertAfter(PersonalInfo *node, unsigned int id, char *firstName, char *familyName)
{
	PersonalInfo* p = NULL;
	p = (PersonalInfo*)malloc(sizeof(PersonalInfo));
	if(p==NULL)
	{
		printf("error in memory allocation of a block of size \n");
		return NULL;
	}

	strncpy(p->firstName, firstName,15);
	strncpy(p->familyName, familyName,15);
	p->id = id;

	p->next = node->next;
	node->next = p;
	return p;
}

/************************************************************************/
/*
Purpose: create a new node and insert it into the end of the list
Input
head - the head of the list
id - id of person
firstName - first name of person
familyName - family name of person


return
A pointer to the node that was allocated.  

NULL - if the operation was not successful

*/


PersonalInfo *insertLast(PersonalInfo **head, unsigned int id, char *firstName, char *familyName)
{
	// add code
    PersonalInfo *p,*last;
//alocate node	
    p=(PersonalInfo*)malloc(sizeof(PersonalInfo));
    
//put in data
    p->id=id;
    strncpy(p->firstName,firstName,15);
    strncpy(p->familyName,familyName,15);
//The p is the last node, so make the next of p become null
    p->next=NULL;
    last=*head;
//if the linked list is empty
    if (*head==NULL){
	*head=p;
	return p;
    }
//traverse till the end
    while(last->next!=NULL){
	last=last->next;
    }
//make the next of last become p;
    last->next=p;
    return p;

}



/************************************************************************/
/*
Purpose: search for the first node with the matching firstName
Input
head - the head of the list
firstName - first name of person

return
a pointer to the node that was found.
NULL - if no node was found or list empty

*/


PersonalInfo *searchByName(PersonalInfo *head, char *firstName)
{

	PersonalInfo *p=head;
	while (p!=NULL){
				//find matched name
	    if (strcmp(p->firstName,firstName)==0)
		return p;
				//move to next node
	    p=p->next;
	}
	return NULL;

	 
	//YES!!!!
}

/************************************************************************/
/*
Purpose: search for the first node with the matching id
Input
head - the head of the list
id - id of person person

return
a pointer to the node that was allocated.  

NULL - if no node was found or list empty 

*/


PersonalInfo *searchById(PersonalInfo *head, unsigned int id)
{
	PersonalInfo* search=head;
	while(search!=NULL){
		if(search->id==id){return search;}
		search=search->next;
	}

	return NULL;
			//YES!!!!!
 
    
}

/***************************************************************/

/*
Purpose: delete the first node from the list
Input
head - the head of the list

output
head - the head of the list
firstName - first name of delted record
familyName - family name of deleted recrod
id - id of deleted record


return

0 if node was deleted
1 if node was not deleted or list is empty

*/


int deleteFromList(PersonalInfo **head, unsigned int *id,
	char *firstName, char *familyName)

{
	PersonalInfo* p;
	p=*head;
	if(*head==NULL){
	printf("List is empty!");
	return(1);
}
	else{
	*id=p->id;
	strcpy(firstName,p->firstName);
	strcpy(familyName, p->familyName);
	*head=p->next;
	free(p);
	return(0);
	
	}

							//YES!!!!!
    

}


/***************************************************************/

/*
Purpose: delete the last node from the list
Input
head - the head of the list

output
head - the head of the list
firstName - first name of delted record
familyName - family name of deleted recrod
id - id of deleted record


return

0 if node was deleted  
1 if node was not deleted or list is empty 

*/


int deleteLast(PersonalInfo **head, unsigned int *id,
                char *firstName, char *familyName)

{
	
	if(*head==NULL){
		printf("List empty!");
		return(1);
	}
	if((*head)->next!=NULL){
		deleteLast(&(*head)->next,id,firstName,familyName);

	}
	else{
		deleteFromList(head,id,firstName,familyName);
	}
      						//YES!!!!!

}



/************************************************************************/

/*
Purpose: delete the record after the given node 
Input
node - a node in the list

output
firstName - first name of delted record
familyName - family name of deleted recrod
id - id of deleted record


return
0 if node was deleted 
1 if node was not deleted (either input node is NULL or input node was the lastnode in the list)

*/



int deleteAfter(PersonalInfo *node, unsigned int *id,
                char *firstName, char *familyName)

{
	if(node==NULL)return (1); 
	else{
	deleteFromList(&(node->next), id, firstName, familyName);}

  	 						//YES!!!!!!

}

/************************************************************************/

/*
Purpose: delete the first node with the matching firstName
Input
head - the head of the list
firstName - first name of person

output
head - the head of the list
firstName - first name of deleted record
familyName - family name of deleted recrod
id - id of deleted record


return
0  if node was deleted
1 if node was not found (e.g., list is empty, no such node exists)

*/


int deleteNodeByName(PersonalInfo **head, char *firstName,
	char *familyName, unsigned int *id)
{
	PersonalInfo **Temp;
	Temp =head;
	while((*Temp)!=NULL){		// if it  is not empty,compare the firstname.
		if(strcmp(firstName,(*Temp)->firstName)==0){
			return deleteFromList(Temp, id, firstName, familyName);
					//delete the first node with the matching firstName
		}
	Temp =&((*Temp)->next);// go to the next node
	}
	return (1);
 
					//YES!!!!!

}
/************************************************************************/
/*
Purpose: deletes all nodes from the list
input/output
head - the head of the list


*/


void deleteList(PersonalInfo **head)
{
    			
  if(*head!=NULL){
	deleteList(&((*head)->next));
	free(*head);	
	}   

}



/************************************************************************/
/*
Purpose: prints the fields of a node
input:
node - a pointer to a given node

*/


void printNode(PersonalInfo *node)
{
	printf("%-20s %-20s %7d \n",node->firstName, node->familyName, node->id);

}


/************************************************************************/
/*
Purpose: prints all the records in the list

input
head - the head of the list
*/


void printList(PersonalInfo *head)
{
   PersonalInfo* pri;
    pri = head; 
    while(pri!=NULL){
        printNode(pri);
        pri=pri->next;
    }

					

}

/************************************************************************/
/*
Purpose: counts the number of nodes in the list
input
head - the head of the list

return 
the number of nodes in the list

*/


int listSize(PersonalInfo *head)
{
	 int size=0;
	if(head==NULL){return 0;}
	else{		// count the size of nodes.
				
		int size=listSize(head->next);
		return size=size+1;
	}
				//YES!!!!!!!!!!

}

/************************************************************************/
/*
Purpose: counts the number of nodes in the list with a matching firstName
input
head - the head of the list

return 
the number of nodes in the list that match the firstName


*/


int countRecords(PersonalInfo *head, char *firstName)
{
	// add code 

	if(head==NULL){return 0;}
	// if is not empty, do the recurisive at first.
	else{	int record=countRecords(head->next,firstName);
		// check the firstname is the same or not.
		if(head==NULL?0:strcmp(firstName,head->firstName)==0)
		{
		record=record+1;//accumulation
		}
		return record;
		
	     }
}				//YES!!!!!!!




/************************************************************************/
/*

Purpose: removes all duplicates records from the list.  Duplicate records are determined by their first name. 
You can assume that the listed is sorted by first name.

input
head - the head of the  list



*/




void removeDuplicates(PersonalInfo *head)
{
	
	//check if the node is not NULL or last one
	if(head!=NULL){
		if(head->next!=NULL){
		int l;
		l = strcmp(head->firstName,(head->next)->firstName);
		if(l ==0){
			char first[32];
			char family[32];
			char *firstName = first;
			char *familyName =family;
			unsigned int id=0;
			unsigned int *idAd =&id;
			deleteAfter(head,idAd,firstName,familyName);
  			removeDuplicates(head);		
		}
	else{removeDuplicates(head->next);}
}	
}
}
			//YES!!!!!

