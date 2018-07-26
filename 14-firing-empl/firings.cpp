#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <queue>

using namespace std;

template<typename T>
vector<T> get_input_sequence(size_t n) {
    vector<T> sequence(n);

    for(size_t i = 0; i < n; ++i) 
        cin >> sequence[i];
    return sequence;
}

struct Node {
    int rank;
    int parent;
    vector<int> children;
    int depth;
};

bool is_prime(int num) {
    if (num < 2)
        return 0;
    else if (num > 2 && num % 2 == 0)
        return 0;
    else if (num==2)
        return 1;
    else {
        for (int i = 2; i <= sqrt(num); ++i)
            if((num % i) == 0)
                return 0;
        return 1;
    }
}

int compute_n_black_list(vector<Node> * nodes, Node * node, int depth) {
    int counter = 0;
    node->depth = depth;
    
    if (node->depth != 0 && is_prime(node->depth + node->rank)) {
        counter++;
    }

    for (int i = 0; i < node->children.size(); ++i) {
        int child = node->children.at(i);
        Node next = nodes->at(child);
        counter += compute_n_black_list(nodes, &next, depth + 1);
    }

    return counter;
}

int main() {
    std::ios_base::sync_with_stdio(false);

    int t;
    cin >> t;
    
    string result = "";
    for (int i = 0; i < t; ++i) {
        int n;
        cin >> n;
        Node * root;
        vector<Node> nodes (n);
        vector<int> numbers = get_input_sequence<int>(n);
        for (int j = 0; j < n; ++j) {
            nodes[j].rank = j+1;
            nodes[j].parent = numbers[j];
            if (numbers[j] == 0) {
                root = &nodes[j];
            } else {
                nodes[numbers[j]-1].children.emplace_back(j);
            }
        }

        result += to_string(compute_n_black_list(&nodes, root, 0)) + "\n";
    }

    cout << result;

    return 0;
}