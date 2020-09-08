
int BTNode {
    int mval;
    BTNode* Left;
    BTNode* Right;
};

int TreeDeep(BTNode* root) {
    if(root == NULL) return 0;

    int nLeft = TreeDeep(root -> Left);
    int nRight = TreeDeep(root -> Right);

    return (nLeft > nRight) ? (nLeft + 1) : (nRight + 1); 
}

bool isbalanced(BTNode* root, int* depth) {
    if(root == NULL) {
        *depth = 0;
        return true;
    }

    itn left, right;
    if(isbalanced(root->Left, &left) && (isbalanced(root->Right, &right)))
    {
        int diff = left - right;
        if(diff <= 1 && diff >= -1) {
            *depth = 1 + (left > right ? left : right );
            return true;
        }
    }
    return false;
}

bool isbalanced(BTNode* root) {
    int depth = 0;
    return isbalanced(root, &depth);
}