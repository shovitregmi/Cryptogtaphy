#include <iostream>
#include <vector>
#include <climits>
using namespace std;

#define MAX_TREE_HT 50

struct MinHNode
{
    char item;
    unsigned freq;
    MinHNode *left, *right;
};

struct MinHeap
{
    unsigned size;
    unsigned capacity;
    vector<MinHNode *> array;

    MinHeap(unsigned cap)
    {
        size = 0;
        capacity = cap;
        array.resize(capacity);
    }

    void minHeapify(int idx)
    {
        int smallest = idx;
        int left = 2 * idx + 1;
        int right = 2 * idx + 2;

        if (left < size && array[left]->freq < array[smallest]->freq)
            smallest = left;

        if (right < size && array[right]->freq < array[smallest]->freq)
            smallest = right;

        if (smallest != idx)
        {
            swap(array[smallest], array[idx]);
            minHeapify(smallest);
        }
    }

    bool checkSizeOne()
    {
        return (size == 1);
    }

    MinHNode *extractMin()
    {
        MinHNode *temp = array[0];
        array[0] = array[size - 1];
        --size;
        minHeapify(0);
        return temp;
    }

    void insertMinHeap(MinHNode *minHeapNode)
    {
        ++size;
        int i = size - 1;
        while (i && minHeapNode->freq < array[(i - 1) / 2]->freq)
        {
            array[i] = array[(i - 1) / 2];
            i = (i - 1) / 2;
        }
        array[i] = minHeapNode;
    }

    void buildMinHeap()
    {
        int n = size - 1;
        for (int i = (n - 1) / 2; i >= 0; --i)
            minHeapify(i);
    }
};

MinHNode *newNode(char item, unsigned freq)
{
    MinHNode *temp = new MinHNode();
    temp->left = temp->right = nullptr;
    temp->item = item;
    temp->freq = freq;
    return temp;
}

MinHeap *createAndBuildMinHeap(char item[], int freq[], int size)
{
    MinHeap *minHeap = new MinHeap(size);
    for (int i = 0; i < size; ++i)
        minHeap->array[i] = newNode(item[i], freq[i]);

    minHeap->size = size;
    minHeap->buildMinHeap();

    return minHeap;
}

MinHNode *buildHuffmanTree(char item[], int freq[], int size)
{
    MinHNode *left, *right, *top;
    MinHeap *minHeap = createAndBuildMinHeap(item, freq, size);

    while (!minHeap->checkSizeOne())
    {
        left = minHeap->extractMin();
        right = minHeap->extractMin();

        top = newNode('$', left->freq + right->freq);

        top->left = left;
        top->right = right;

        minHeap->insertMinHeap(top);
    }
    return minHeap->extractMin();
}

void printArray(const vector<int> &arr)
{
    for (int bit : arr)
        cout << bit;
    cout << endl;
}

void printHCodes(MinHNode *root, vector<int> &arr, int top)
{
    if (root->left)
    {
        arr[top] = 0;
        printHCodes(root->left, arr, top + 1);
    }
    if (root->right)
    {
        arr[top] = 1;
        printHCodes(root->right, arr, top + 1);
    }
    if (!root->left && !root->right)
    { // Leaf node
        cout << "  " << root->item << "   | ";
        printArray(arr);
    }
}

void HuffmanCodes(char item[], int freq[], int size)
{
    MinHNode *root = buildHuffmanTree(item, freq, size);
    vector<int> arr(MAX_TREE_HT, 0);
    int top = 0;
    printHCodes(root, arr, top);
}

int main()
{
    char arr[] = {'A', 'B', 'C', 'D'};
    int freq[] = {5, 1, 6, 3};
    int size = sizeof(arr) / sizeof(arr[0]);

    cout << " Char | Huffman code ";
    cout << "\n--------------------\n";

    HuffmanCodes(arr, freq, size);
    cout << "\nName: Shovit Regmi\nRoll No.: 32\n";
    return 0;
}
