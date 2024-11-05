#include <iostream>
#include <cmath>
using namespace std;

class BinaryTree
{
    int *tree;
    int size;

public:
    BinaryTree(int n)
    {
        size = pow(2, n) - 1; // Max nodes for height 'n'
        tree = new int[size];
        for (int i = 0; i < size; i++)
        {
            tree[i] = -1; // Initialize nodes as empty
        }
    }

    void setRoot(int key)
    {
        tree[0] = key;
    }

    void setLeft(int parentIndex, int key)
    {
        int leftIndex = 2 * parentIndex + 1;
        if (leftIndex < size)
            tree[leftIndex] = key;
    }

    void setRight(int parentIndex, int key)
    {
        int rightIndex = 2 * parentIndex + 2;
        if (rightIndex < size)
            tree[rightIndex] = key;
    }

    void display()
    {
        for (int i = 0; i < size; i++)
        {
            if (tree[i] != -1)
                cout << tree[i] << " ";
            else
                cout << "- ";
        }
        cout << endl;
    }

    ~BinaryTree()
    {
        delete[] tree;
    }
};

int main()
{
    BinaryTree bt(3); // Binary tree of height 3
    bt.setRoot(1);
    bt.setLeft(0, 2);
    bt.setRight(0, 3);
    bt.setLeft(1, 4);
    bt.setRight(1, 5);
    bt.setLeft(2, 6);
    bt.setRight(2, 7);
    bt.display();
    return 0;
}
