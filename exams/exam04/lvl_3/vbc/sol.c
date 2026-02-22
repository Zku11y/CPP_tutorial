#include <stdio.h>
#include <stdlib.h> // Use malloc.h if your specific environment demands it
#include <ctype.h>

// --- STRUCTS (Given) ---
typedef struct node {
    enum {
        ADD,
        MULTI,
        VAL
    }   type;
    int val;
    struct node *l;
    struct node *r;
}   node;

// --- HELPERS (Modified as requested) ---

node    *new_node(node n)
{
    node *ret = calloc(1, sizeof(n));
    if (!ret)
        return (NULL);
    *ret = n;
    return (ret);
}

void    destroy_tree(node *n)
{
    if (!n)
        return ;
    if (n->type != VAL)
    {
        destroy_tree(n->l);
        destroy_tree(n->r);
    }
    free(n);
}

// Fixed: Correct error messages and exit code 1
void    unexpected(char c)
{
    if (c)
        printf("Unexpected token '%c'\n", c);
    else
        printf("Unexpected end of input\n"); // Fixed "file" to "input"
    exit(1);
}

// Fixed: Actually check if **s matches c
int accept(char **s, char c)
{
    if (**s == c)
    {
        (*s)++;
        return (1);
    }
    return (0);
}

// Fixed: Pass double pointer
int expect(char **s, char c)
{
    if (accept(s, c))
        return (1);
    unexpected(**s);
    return (0);
}

// --- PARSING LOGIC (The part you need to write) ---

// Forward declaration
node    *parse_expr(char **s);

// Level 3: Numbers and Parentheses
node    *parse_factor(char **s)
{
    // 1. Handle Parentheses
    if (accept(s, '('))
    {
        node *ret = parse_expr(s); // Recurse back to top
        expect(s, ')');            // Must find closing ')'
        return ret;
    }
    
    // 2. Handle Digits (0-9)
    if (isdigit(**s))
    {
        node *ret = new_node((node){VAL, **s - '0', NULL, NULL});
        (*s)++;
        return ret;
    }

    // 3. Error
    unexpected(**s);
    return NULL;
}

// Level 2: Multiplication
node    *parse_term(char **s)
{
    node *lhs = parse_factor(s);

    while (accept(s, '*'))
    {
        node *rhs = parse_factor(s);
        // Create a new MULTI node, putting previous tree on Left, new factor on Right
        lhs = new_node((node){MULTI, 0, lhs, rhs});
    }
    return lhs;
}

// Level 1: Addition
node    *parse_expr(char **s)
{
    node *lhs = parse_term(s);
    if(!lhs)
        return NULL;

    while (accept(s, '+'))
    {
        node *rhs = parse_term(s);
        if(!rhs) return (destroy_tree(lhs), NULL);
        // Create a new ADD node, putting previous tree on Left, new term on Right
        // lhs = new_node((node){ADD, 0, lhs, rhs});
        node *n = new_node((node){ADD, 0, lhs, rhs});
        if(!n) return (destroy_tree(lhs), destroy_tree(rhs), NULL);
        lhs = n;
    }
    return lhs;
}

// --- EVALUATION (Modified as requested) ---

int eval_tree(node *tree)
{
    switch (tree->type)
    {
        case ADD:
            return (eval_tree(tree->l) + eval_tree(tree->r));
        case MULTI:
            return (eval_tree(tree->l) * eval_tree(tree->r));
        case VAL:
            return (tree->val);
    }
    return 0;
}


int main(int argc, char **argv)
{
    if (argc != 2)
        return (1);
    
    char *s = argv[1]; // Create a pointer we can move
    
    // Pass the ADDRESS of the pointer (&s) so functions can update it
    node *tree = parse_expr(&s); 

    // Check if we stopped early (e.g. "3+2 junk")
    if (*s)
        unexpected(*s);

    printf("%d\n", eval_tree(tree));
    destroy_tree(tree);
    return 0;
}