#define NO_COLOR 0
#define WHITE 1
#define BLACK 2

int color_tree(int i, int current_color, int next_color, vector<int> nodes, int G[][MAX], int n) {
    nodes[i] = current_color;
    for (int j = 0; j < n; j++)
        // consider only my neighborhood
        if (G[i][j] == 1)
            // if my neighbour has my color or it does not have any color but recursively we fail to color
            if ((nodes[j] == NO_COLOR && !color_tree(j, next_color, current_color, nodes, G, n)) || (nodes[j] == current_color))
                return false;
    return true;
}

bool isBipartite(int G[][MAX], int n) {
    vector<int> nodes (n);
    for (int i = 0; i < n; i++)
        if (nodes[i] == NO_COLOR)
            if (!color_tree(i, WHITE, BLACK, nodes, G, n))
                return false;
    return true;
}
