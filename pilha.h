typedef struct node{
    char data[4];
    struct node* node_above;
} node;
typedef struct node* p_node;

p_node push();
p_node pop (p_node list);

void inicializeVectorBlock(p_node new_node);
int is_footer(p_node node);
void free_list(p_node list);
void show_size(p_node list);
void stack(p_node list);
void choose_option(p_node list, char option);
char menu(void);
