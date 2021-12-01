#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"

int main(void)
{
    p_node list = (p_node) malloc(sizeof(node));
    if(!list){
        exit(1);
    }
    else{
        inicializeVectorBlock(list);
        char option;

        do{
            option=menu();
            if (option == 'x'){
                free_list(list);
                free(list);
                
                return 0;
            }
            choose_option(list, option);
        }
        while(option);

        free(list);
        
        return 0;
        }
}

char menu(void)
{
    char option;
 
    scanf("%c", &option);
 
    return option;
}

void inicializeVectorBlock(p_node new_node)
{
    new_node->node_above = NULL;
}

p_node push()
{ 
    p_node new_node = (p_node) malloc(sizeof(node));
    if(!new_node){
        exit(1);
    }
    else{
        scanf("%s", new_node->data);
  
        return new_node;
    }
}

p_node pop (p_node list)
{
    if(list->node_above == NULL){
        
        return NULL;
    }
    else{
        p_node temporary_node = list->node_above;
        list->node_above = temporary_node->node_above;

        return temporary_node;
    }
}

int is_footer(p_node node)
{
    if(node->node_above == NULL){

        return 1;
    }    
    else{

    return 0;
    }
}

void free_list(p_node list)
{
    if(!is_footer(list)){
        p_node next_Node;
        p_node current_Node;

        current_Node = list->node_above;
        
        while(current_Node != NULL){
            next_Node = current_Node->node_above;

            free(current_Node);

            current_Node = next_Node;
        }
    }
}

void show_size(p_node list)
{
    if(is_footer(list)){
        printf("0\n");
        
        return;
    }

    int size = 0;
    p_node temporary_node = list->node_above;

    while( temporary_node != NULL){
        size += 1;
        temporary_node = temporary_node->node_above;
    }

    printf("%i\n", size);
}

void stack(p_node list)
{
    p_node new_node = push();
    p_node old_Head = list->node_above;
 
    list->node_above = new_node;
    new_node->node_above = old_Head;
}

void choose_option(p_node list, char option)
{
    p_node temporary_node;
    
    switch(option){
        case 't':
            show_size(list);

            break;
  
        case 'e':
            stack(list);

            break;  
   
        case 'd':
            temporary_node = pop(list);

            printf("%s\n", temporary_node->data);

            break;
        /*default:
            menu ();
            
            break;*/
 }
}
