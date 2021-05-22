/*  ------------- HEAP ---------------- */

// ->A heap is a tree-based data structure in which all the nodes of the tree are in a specific order.

// ->For example, if X is the parent node of Y , then the value of Y follows a specific order with respect to the value of X and the same order will be followed across the tree.

 // -> In binary heap, if the heap is a complete binary tree with N nodes, then it has smallest possible height which is  log2N.

 /* Representation of Binary heap in an Array */

 // ---> root stored at index 1 of the array
 // ---> left child and right child of index i will be stored at indexes 2 * i and 2 * i + 1 respectively
 // ---> The parent of i node will be stored at index i / 2
// ----> Array is 1 index based.

 // Tree ->       6
        //     4      5
        // 3     2 0     1 

// Array  -> [6, 4, 5, 3, 2, 0, 1]

/*  ------------- MAX_HEAP ---------------- */

// In this type of heap, the value of parent node will always be greater than or equal to the value of child node across the tree and the node with highest value will be the root node of the tree.

void max_heapify(int arr[], int i, int N)
{
    int largest = i;
    int left = 2 * i;
    int right = 2 * i + 1;

    if(arr[left] > arr[largets] && left <= N)
        left = largest;

    if(arr[right] > arr[largest] && right <= N)
        right = largest;
    
    if(largest != i)
    {
        swap(arr[i], arr[largest]);
        max_heapify(arr, largest, N);
    }
}

// Time - Complexity = O(log(N))

/*  ------------- Building MAX_HEAP ---------------- */

void build_maxheap (int Arr[ ])
{
    for(int i = N/2 ; i >= 1 ; i-- )
    {
        max_heapify (Arr, i) ;
    }
}

// Time - Complexity = O(N) - max_heapify function has time complexity logN and build_maxheap functions runs only N / 2 times but the total time complexity for this function is actually linear.

// We can build min - heap same as max - heap, only some conditions will differ. Time - complexity will be same.

/*  ------------- HEAP_SORT ---------------- */

void heap_sort() 
{
    build_maxheap(Arr);
    for(int i = N; i >= 2; i--)
    {
        swap(Arr[i], Arr[1]);
        max_heapify(Arr, 1, i - 1);
    }
}

// Time - Complexity - O(Nlog(N))