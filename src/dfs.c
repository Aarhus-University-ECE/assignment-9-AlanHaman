/*
 * Search an expression using DFS.
 */

#include <stdio.h>		/* scanf, printf */
#include <stdlib.h>		/* abort */
#include <stdbool.h>		/* bool, true, false */
#include "dfs.h"
#include <assert.h> 


void DFT(node *root) {
    // Implement DFS
    // Hint: You can use print_node, print_tree and/or print_stack.

    // Allocating space for a new stack.
    stack *newStack = (stack *)malloc(sizeof(stack));
    // inserting root in the stack, so it is not empty.
    newStack->node = root;
    newStack->next = NULL;

    // while loop to run through the tree, as long the stack is not empty
    while (!isEmpty(newStack)) {
        node *currentNode = top(newStack);

        newStack = pop(newStack);

        // If currentNode has a right child, then we push it to the stack
        if (currentNode->rchild != NULL) {
            newStack = push(newStack, currentNode->rchild);
        }
        // If currentNode has a left child, we push it to the stack.
        if (currentNode->lchild != NULL) {
            newStack = push(newStack, currentNode->lchild);
        }
        print_node(currentNode);
    }
    return;
}

node *make_node(int num, node *left, node *right) {
    // allocating space and saving it in the pointer newNode.
    node *newNode = malloc(sizeof(node));

    newNode->num = num;
    newNode->visited = false;
    newNode->lchild = left;
    newNode->rchild = right;

    // Return newNode
    return newNode;
}

void free_node(node *p) {
    // assert to make sure P is not NULL
    if (p == NULL) {
        return;
    }
    // free left, then right child and then the node
    free_node(p->lchild);
    free_node(p->rchild);
    free(p);
    return;
}

void print_node(node *p) {
    if (p == NULL)
        printf("NULL\n");
    else
        printf("%d, ", p->num);
}

void print_tree(node *p, int depth) {
    for (int i = 0; i < depth; i = i + 1) printf(" ");
    printf("| ");

    if (p == NULL)
        printf("NULL\n");
    else
        printf("[%d]\n", p->num);

    if (p->lchild) {
        print_tree(p->lchild, depth + 1);
    }

    if (p->rchild) print_tree(p->rchild, depth + 1);
}

stack *push(stack *topp, node *node) {
    stack *newStack = (stack *)malloc(sizeof(stack));
    newStack->next = topp;
    newStack->node = node;
    return newStack;
}

bool isEmpty(stack *topp) {
    if (topp == NULL) {
        return true;
    } else {
        return false;
    }
}

node *top(stack *topp) { return topp->node; }

// Utility function to pop topp
// element from the stack

stack *pop(stack *topp) {
    assert(!isEmpty(topp));
    stack *newStack = topp->next;
    free(topp);
    return newStack;
}

void print_stack(stack *topp) {
    struct stack *temp = topp;

    while (temp != NULL) {
        print_node(temp->node);
        printf("\n");

        temp = temp->next;
    }

    printf("====\n");

    return;
}
