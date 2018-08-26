pair<int,int> maxPathSumRec(struct Node * node) {
    if (node->left == NULL && node->right == NULL) {
        pair<int,int> p;
        p.first = node->data;
        p.second = node->data;
        return p;
    }

    pair<int,int> leftPair, rightPair;
    if (node->left == NULL) {
        rightPair = maxPathSumRec(node->right);
        rightPair.first += node->data;
        return rightPair;
    }

    if (node->right == NULL) {
        leftPair = maxPathSumRec(node->left);
        leftPair.first += node->data;
        return leftPair;
    }

    leftPair = maxPathSumRec(node->left);
    rightPair = maxPathSumRec(node->right);

    int bridge = leftPair.first + rightPair.first + node->data;

    if (bridge > leftPair.second && bridge > rightPair.second) {
        pair<int,int> newPair;
        newPair.second = bridge;
        newPair.first = max(leftPair.first, rightPair.first) + node->data;
        return newPair;
    }

    if (leftPair.second > rightPair.second) {
        leftPair.first += node->data;
        return leftPair;
    } else {
        rightPair.first += node->data;
        return rightPair;
    }
}


int maxPathSum(struct Node *root) {
    return maxPathSumRec(root).second;
}
