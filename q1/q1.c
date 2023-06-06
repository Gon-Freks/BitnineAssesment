#include <stdio.h>
#include <stdlib.h>

typedef enum TypeTag{
    ADD,
    SUB,
    MUL,
    DIV,
    INT,
    FIB
}TypeTag;

struct Node;

// Function typedef for all arithmetic functions and fibonacci
typedef int (*Function)(int, int);

// Data structure definition for struct Node
typedef struct Node {
    TypeTag type;
    Function func;
    struct Node* right;
    struct Node* left;
    int value;
    int evaluated;  // works as a boolean to indicate if the node has been evaluated or not
} Node;


// fibonacci function, the second parameter is not used but is needed such that the function signature matches the typedef
int fibo(int num, int _)
{
    int a = 0, b = 1, c;
    
    if(num <= 1)
        return 1;

    for (int i = 2; i <= num; ++i)
    {
        c = a + b;
        a = b;
        b = c;
    }
    return b;
}

int add(int a, int b) {
    return a + b;
}

int subtract(int a, int b) {
    return a - b;
}

int multiply(int a, int b) {
    return a * b;
}

// Integer Division
int divide(int a, int b) {
    if (b == 0){
        printf("Divide by zero error\n");
        return 0;
    }
    return a / b;
}

int evalNode(Node* node){

    // early return if the node is already evalNodeuated
    if(node->evaluated)
        return node->value;

    node->evaluated = 1;

    if(node->type == INT)
        return node->value;
    
    if(node->type == FIB)
        return node->value = node->func(evalNode(node->left), 0);  // fibo node has only one child which is the left child

    return node->value = node->func(evalNode(node->left), evalNode(node->right));
}

Node* createNode(TypeTag type ,Function func, Node* left, Node* right, int value) {
    Node* node  = (Node*)malloc(sizeof(Node));
    node->type  = type;      // type of the node.
    node->func  = func;      // function to apply for this node according to its type.
    node->value = value;     // the final value of the node after evaluation.
    node->left  = left;      // the left child
    node->right = right;     // the right child
    node->evaluated = 0;     // flag to indicate if the node has been evaluated or not.
    return node;
}


void showResult(int result){
    printf("The result: %d\t \n", result);
}

int main(){

    Node* num1Node = createNode(INT, NULL, NULL, NULL, 2);
    Node* num2Node = createNode(INT, NULL, NULL, NULL, 1);

    Node* addNode  = createNode(ADD, add, num1Node, num2Node,  0);
    Node* subNode  = createNode(SUB, subtract, num1Node, num2Node, 0);

    Node* mulNode  = createNode(MUL, multiply, addNode, subNode, 0);
    
    Node* fibNode  = createNode(FIB, fibo, mulNode, NULL, 0);


    showResult(evalNode(addNode));
    showResult(evalNode(subNode));
    
    showResult(evalNode(fibNode));

    // will be faster that time due to caching
    showResult(evalNode(fibNode));
    
    return 0;
}
