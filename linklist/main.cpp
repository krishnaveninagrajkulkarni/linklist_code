//
//  main.cpp
//  single linklist
//
//  Created by krishnaveni kulkarni on 08/09/22.
//  Copyright © 2022 krishnaveni kulkarni. All rights reserved.
//
//**************************************************************************************************
//Implemented
//1. Single Link List(sll) - Insertion at start & End of list , Deletion with key, Display the sll
//2. Double Link list(dll) - Insertion at start & End of list , Deletion with key, Display the dll
//**************************************************************************************************
#include <iostream>
//#include "double_linklist.cpp"
using namespace std;
class Node{
    
public:
    int data;
    Node *next;
};

class double_node{
public:
    int ddata;
    double_node *dnext;
    double_node *dprev;
};

//**************************************************************************************************
//                                      Single Link List(sll)
//**************************************************************************************************
//head_ref is pointer to pointer means - it holds the address of the head pointer
void insert_newnode_atfirst_sll(Node **head_ref,int value){
    Node *new_node = new Node;
    new_node->data = value;
    new_node->next = *head_ref;
    *head_ref = new_node;     //Here the addresses of newnode is stored in head pointer via *head_ref as it                           points to head pointer.
}

void insert_newnode_atend_sll(Node **head_ref,int value){
    Node *new_node = new Node;
    new_node->data = value;
    new_node->next = nullptr;
    
    if (*head_ref == nullptr)
    {
        *head_ref = new_node;
    }else{
//This code everytime traverse the linklist from start to end of sll till it finds nullptr
//& also copies the address of next node to lastnode ptr, i.e. lastnode points to next node.
        Node *lastnode = *head_ref;  //this lastnode keeps track of the previous of the lastnode
        while(lastnode->next != nullptr){
            lastnode = lastnode->next;
        }
        lastnode->next = new_node;  //if node contains null then new node address is copied to currentnode->next
    }
}
//Prints from starting element of the singlelinklist
void print_sll(Node *temp){
    while(temp != nullptr)
    { cout<<temp->data<<"\n";
        temp = temp->next; }
}

void delete_node_sll(Node **head_ref,int key){
//**head_ref is pointer to pointer as it continously holds & points address of head pointer.
    
//2 pointers used , prev & temp
//prev pointer stores address of the previous node.
//temp pointer stores address of current node which has to be deleted
    
//Instead of using temp = *head_ref, we can directly use (*head_ref) & avoid creating ptr temp.
    Node *prev = nullptr,*temp;
    temp = *head_ref;
    
    if (temp->data == key){
        *head_ref = temp->next; //head is changed as deleting the first node
        delete temp;
        return;
    }else{  //Traverse the sll till key matches
    while (temp != NULL && temp->data != key){
        prev = temp;
        temp = temp->next;
    }
    if (temp == nullptr)
    return;             //link list is empty
        
    //once the key match, copy the address of the current node to previous node as current node will be deleted
    prev->next = temp->next; //when key matches
    delete temp;
    }
}
//**************************************************************************************************
//                       Double Link List(dll)
//**************************************************************************************************
//Head pointer points to last element in the dll at the end.
//head pointer keeps on changing to new node address.
//head pointer is not constant here
void insert_node_atlast_dll(double_node **dhead_ref, int value){
    double_node *new_dnode = new double_node;
    if((*dhead_ref)!=nullptr)
        (*dhead_ref)->dnext = new_dnode; //head pointer changes to newnode address
    
    new_dnode->ddata = value;
    new_dnode->dnext = nullptr;
    new_dnode->dprev = *dhead_ref;  //previous node addr is copied into current new node - previous part
    *dhead_ref = new_dnode;     //head pointer chnages to newnode address
}

void insert_node_atstart_dll(double_node **dhead_ref, int value){
    double_node *new_dnode = new double_node;
    double_node *previous = *dhead_ref;
    if(previous!=nullptr)
        previous->dnext = new_dnode;
    
    new_dnode->ddata = value;
    new_dnode->dnext = nullptr;
    new_dnode->dprev = previous;
    *dhead_ref = new_dnode;
}


//prints from last element of the double link list
void print_dll(double_node *temp)
{
    while (temp != nullptr) {
        cout<<temp->ddata<<"\n";
        temp = temp->dprev;
        ;}
}

//head pointer is pointing to last node
//so deletion is done using previous part of each node;i.e traverse is done using previous part of each node.
void delete_node_dll(double_node **dhead_ref,int value)
{
    double_node *temp = *dhead_ref;
    double_node *prev = nullptr;
    if(temp->dprev == nullptr){
        cout<<"Double link list is empty"<<"\n";
        return;
    }else{
        while (temp->ddata != value){
            prev = temp;
            temp = temp->dprev;
        }
        prev->dprev = temp->dprev;
        prev = temp;
        temp = temp->dprev;
        temp->dnext = prev->dnext;
        delete prev;
    }
}

//**************************************************************************************************
int main(int argc, const char * argv[]) {
//head pointer will always hold the start node address of the linklist.
    Node *head = nullptr;           //single link list head pointer
    double_node *dhead = nullptr;   //double link list head pointer

//******************Single link list insertions**********************************************
 /*
//Head pointer is not constantly pointing to start of the sll.
//Head pointer keeps changing to newnode address as we keep inserting newnode as first element.
//so at the end of the sll, head pointer is bydefault pointing to start/first element of the sll.
//so there is no need of any third pointer.
//every time  we r sending same address of the pointer head in insert_new_node()

    insert_newnode_atfirst_sll(&head,100);//Last node
    insert_newnode_atfirst_sll(&head,200);//third node
    insert_newnode_atfirst_sll(&head,300);//Second node
    insert_newnode_atfirst_sll(&head,400);//first node

//Head Pointer is constant with start node,Since we are adding the element to last of sll.
//Head pointer is constantly pointing to start of the sll; additional ptr - lastnode is used to traverse the sll
//lastnode keeps track of the newly added elements
    insert_newnode_atend_sll(&head,101);//first node
    insert_newnode_atend_sll(&head,202);//second node
    insert_newnode_atend_sll(&head,303);//third node
    insert_newnode_atend_sll(&head,404);//Last node

    print_sll(head);  //head pointer holds start element address of sll.
*/
//******************  Single link list deletion  **********************************************

/*
    cout<<"I am deleting 400 from list"<<"\n";
//head pointer is pointing to start node.
    delete_node_sll(&head,400);
    print_sll(head); */

//******************Double link list Insertions **********************************************

    cout<<"Creating double link list"<<"\n";
    insert_node_atlast_dll(&dhead, 10); //first node
    insert_node_atlast_dll(&dhead, 20);//second node
    insert_node_atlast_dll(&dhead, 30);//third node
    insert_node_atlast_dll(&dhead, 40);//last node

    
    cout<<"printing double link list"<<"\n";
    //head pointer is pointing to last node
    print_dll(dhead);
        
//******************Double link list deletion **********************************************
    cout<<"Deleting element from double link list"<<"\n";
    // head pointer is still pointing to last node only
    delete_node_dll(&dhead,20);
    print_dll(dhead);
  
    cout<<"prgm ends";
    return 0;
}
