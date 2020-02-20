#include <stdio.h>
#include <stdlib.h>

//Jirawit  Khuanwilai

struct node{
    int data;
    struct node *next;
    struct node *prev;
};
typedef struct node create_list;
create_list *newnode(int data){
    create_list *node = (struct create_list *)malloc(sizeof(create_list));
    node->data = data;
    node->next = NULL;
    node->prev = NULL;
    return node;
}
void sortnode(create_list *node, create_list **head){
    create_list *tmp = head;
    do
    {
      if(node->data < tmp->data){
            if(head == tmp){
                *head = node;
                node->next = tmp;
                tmp->prev = node ;
            break;
            }
            else{
                tmp->prev->next = node;
                node->next = tmp;
                node->prev = tmp->prev;
                tmp->prev = node; 
            break;
            }
        }
        else if(tmp->next == NULL && tmp->data <= node->data ){
            node->next = tmp->next;
            node->prev = tmp;
            tmp->next = node;
            break;
        }
      tmp = tmp->next;
    }
    while(tmp != NULL);
}
int main(){
    int input;
    create_list *head;
    create_list *tmp;

     scanf("%d",&input);
     if(input <= -1){
        tmp = newnode(input);
        head = tmp;

        while(1){
            scanf("%d",&input);
            if (input == -1){
                break;
            }
            tmp = newnode(input);
            sortnode(tmp,&head);
        }
    }
    print_list(head);
}