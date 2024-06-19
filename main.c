#include<stdio.h>
#include<stdlib.h>

struct node 
{
   int value;
   struct node* next_node;   
};

typedef struct node node;
typedef struct node* node_ptr;

// add new node in list by order
void insert_value(node_ptr* fptr,int value);
// printing out for all node
void display_list(node_ptr fptr);
int delete(node_ptr *sptr,int value);
int isEmpty(node_ptr curr_ptr);
void app(void);

int main(void)
{
    node_ptr start_node = NULL;
    int input;
    app();
    if(!scanf("%d",&input))
    {
        puts("invalid inputs!");
        return -1;
    }
    while(input >=0 && input <= 2)
    {
        switch (input)
        {
        case 0:
            printf("Enter value: ");
            if(!scanf("%d",&input))
            {
                puts("invalid inputs!");
                return -1;
            }
            insert_value(&start_node,input);
            break;
        case 1:
            printf("Enter value: ");
            if(!scanf("%d",&input))
            {
                puts("invalid inputs!");
                return -1;
            }
            insert_value(&start_node,input);
            break;
        case 2:
        if(start_node == NULL)
            break;
            display_list(start_node);
            break;
        default:
            break;
        }
        app();
        if(!scanf("%d",&input))
        {
            puts("invalid inputs!");
            return -1;
        }
    }
    
    return 0;
}
void app(void)
{
    puts("\n------------------------------------------");
    puts("0-insert node");
    puts("1-delete node");
    puts("2-display list");
    printf(" Your choice : ");
}


void insert_value(node_ptr* fptr,int value)
{
    node_ptr prev_node;
    node_ptr curr_node;
    node_ptr new_node;

    new_node = malloc(sizeof(node));

    // checks if the allocation was successful 1
    if(new_node != NULL)
    {
        new_node->value = value;
        new_node->next_node = NULL; // this indicate the end of the list for this node.

        prev_node = NULL;
        curr_node = *fptr;

        /* bubble sort ===>  new_node->value > curr_node->value */
        // curr_node != NULL --> indicate not the end of the list
        // value > curr_node->value --> the value to be inserted is greater than the value of the current node 
        while (curr_node != NULL && value > curr_node->value)  
        {
            prev_node = curr_node; 
            curr_node = curr_node->next_node; 

        }
       // check empty
        if(prev_node == NULL) // in this case we will insert first node
        {
            // will make the node as head node
            new_node->next_node = *fptr;
            *fptr =new_node;
        }
        else
        {
            prev_node->next_node = new_node;
            new_node->next_node = curr_node;
        }
    }
    else
    {
        /* Do Nothing*/
        puts("Not valid memory!!");
    }
}

int delete(node_ptr *sptr, int value) {
    node_ptr prev_node = NULL;
    node_ptr curr_node = *sptr;

    // Check for empty list first
    if (curr_node == NULL) {
        printf("List is empty\n");
        return 0; // Indicate failure
    }
    // Case 1: Delete the head node (value is the first node's value)
    if (value == (*sptr)->value) {
        node_ptr temp_node = *sptr;
        *sptr = (*sptr)->next_node;
        free(temp_node);
        return value;
    }
    // Case 2: Delete any other node
    while (curr_node != NULL && value != curr_node->value) {
        prev_node = curr_node;
        curr_node = curr_node->next_node;
    }
    // Check if the node to be deleted was found
    if (curr_node == NULL) {
        printf("Value %d not found in the list.\n", value);
        return 0; // Indicate failure
    }

    // Node found, proceed with deletion
    prev_node->next_node = curr_node->next_node;
    free(curr_node);
    return value;
}


void display_list(node_ptr fptr)
{
    puts("\nList of node");
    puts("-------------------");
    while (fptr != NULL)
    {
        printf("%d\n",fptr->value);
        fptr = fptr->next_node;
    }
}

int isEmpty(node_ptr curr_ptr)
{
    return (curr_ptr == NULL) ? 1:0;
}