void BinarySearchTree::inorder(tree_node* p1,tree_node* p2)
{
    if((p1 != NULL)||(p2 !=NULL))
    {
        if(p1->data > p2->data)
        {
            if(p1->left) inorder(p1->left,p2);
            cout<<" "<<p1->data<<" ";
            if(p1->right) inorder(p1->right,p2);
        }
        else
        {
            if(p2->left) inorder(p1,p2->left);
            cout<<" "<<p2->data<<" ";
            if(p2->right) inorder(p1,p2->right);
        }
    }
}

