
#include <stdio.h>

int max_d = -1;

bool is_balanced(node *t, int depth) {

    if(t == 0) {
        if(max_d == -1) { 
            max_d = depth-1;
            return true; // not known yet whether unbalanced
            // tree without nodes is clearly balanced
        }
        if(abs(max_d - depth + 1) > 1)
            return false; // not balanced
        return true; // this does not violate the property
    }
    if(!is_balanced(t->left, depth + 1))
        return false;
    if(!is_balanced(t->right, depth + 1))
        return false;    
    return true;    
}

is_balanced(0);


import java.util.Stack;

public class PreOrderConstruction {

public static void main(String[] args) {

    char[] preOrderList = new char[]{'N','N','L','L','L'};
    Stack<Node> stck = new Stack<Node>();

    Node inNode = null;
    for(int i=preOrderList.length-1; i>=0; i--){
        if(preOrderList[i]=='L'){//If leaf node
            stck.push(new Node(preOrderList[i]));
        }else{
            Node left = stck.pop();
            Node right = stck.pop();
            inNode = new Node(preOrderList[i]);
            inNode.setLeftNode(left);
            inNode.setRightNode(right);
            stck.push(inNode);
        }
    }
        inNode = stck.pop();
}

}

class Node{

Node left = null;
Node right = null;
char data;

public Node(char data){
    this.data = data;
}

public void setLeftNode(Node n){
    this.left = n;
}

public void setRightNode(Node n){
    this.right = n;
}

}
