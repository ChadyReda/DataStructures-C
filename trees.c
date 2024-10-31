#include <stdio.h>
#include <stdlib.h>

typedef struct treenode {
    int value;
    struct treenode* left;
    struct treenode* right;
} treenode;

struct treenode* createnode (int value) {
    struct treenode* result = malloc(sizeof(struct treenode));
    if (result != NULL) {
        result->left = NULL;
        result->right = NULL;
        result->value = value;
    }
    return result;
}

void printtabs(int numtabs) {
    for (int i = 0 ; i < numtabs; i++) {
        printf("\t");
    }
}

void printtree_rec(struct treenode* root, int level) {
    if (root == NULL) {
        printtabs(level);
        printf("<empty tree>\n");
        return;
    }
    // preorder traversal left first the right
    printtabs(level);
    printf("value  %d\n", root->value);

    printtabs(level);
    printf("left\n");
    printtree_rec(root->left, level+1);

    printtabs(level);
    printf("right\n");
    printtree_rec(root->right, level+1);
}

void printtree(struct treenode* root) {
    printtree_rec(root, 0);
}

int main() {
    struct treenode* n1 = createnode(10);
    struct treenode* n2 = createnode(20);
    struct treenode* n3 = createnode(30);
    struct treenode* n4 = createnode(40);
    struct treenode* n5 = createnode(50);

    n1->left = n2;
    n1->right = n3;
    n3->left = n4;
    n3->right = n5;

    printtree(n1);

    free(n1);
    free(n2);
    free(n3);
    free(n4);
    free(n5);
}