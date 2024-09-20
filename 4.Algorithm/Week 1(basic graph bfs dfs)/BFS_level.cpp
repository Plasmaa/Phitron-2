#include <bits/stdc++.h>
using namespace std;

// Structure to represent each node in the hierarchy (binary tree)
struct Node
{
    int data;
    Node *left;
    Node *right;

    Node(int val)
    {
        data = val;
        left = right = NULL;
    }
};

// Recursive function to construct the hierarchy (binary tree)
Node *buildHierarchy(vector<int> &employees, int start, int end)
{
    if (start > end)
    {
        return NULL;
    }

    // Middle element becomes the root for this subtree
    int mid = (start + end) / 2;
    Node *root = new Node(employees[mid]);

    // Recursively build the left and right subtrees
    root->left = buildHierarchy(employees, start, mid - 1);
    root->right = buildHierarchy(employees, mid + 1, end);

    return root;
}

// Perform BFS level-order traversal on the hierarchy
void bfs(Node *root)
{
    if (!root)
        return;

    queue<Node *> q;
    q.push(root);

    while (!q.empty())
    {
        Node *current = q.front();
        q.pop();

        // Print the current node (employee)
        cout << current->data << " ";

        // Push the left and right children to the queue
        if (current->left)
        {
            q.push(current->left);
        }
        if (current->right)
        {
            q.push(current->right);
        }
    }
    cout << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    // Number of employees = 2^n - 1
    int emp = pow(2, n) - 1;

    vector<int> employees(emp);

    // Input the employee numbers
    for (int i = 0; i < emp; i++)
    {
        cin >> employees[i];
    }

    // Build the hierarchy using the recursive function
    Node *root = buildHierarchy(employees, 0, emp - 1);

    // Perform BFS to print the hierarchy in level order
    bfs(root);

    return 0;
}
