/*  ------------- Priority Queue ---------------- */

// Priority Queue is similar to queue where we insert an element from the back and remove an element from front, but with a difference that the logical order of elements in the priority queue depends on the priority of the elements. The element with highest priority will be moved to the front of the queue and one with lowest priority will move to the back of the queue. Thus it is possible that when you enqueue an element at the back in the queue, it can move to front because of its highest priority.

// We can use heaps to implement Priority Queue it will take O(logN) time Complexity to insert and delete each element in pq.

// Based on heap structure, priority queue also has two types max- priority queue and min - priority queue.

// Let’s focus on Max Priority Queue.

// Max Priority Queue is based on the structure of max heap and can perform following operations:

// maximum(Arr) : It returns maximum element from the Arr.
// extract_maximum (Arr) - It removes and return the maximum element from the Arr.
// increase_val (Arr, i , val) - It increases the key of element stored at index i in Arr to new value val.
// insert_val (Arr, val ) - It inserts the element with value val in Arr.

/*  ------------- maximum(Arr) ---------------- */

int maximum(int Arr[])
{
    return Arr[1];
}

//Time - Complexity - O(1)

/*  ------------- extract_maximum (Arr) ---------------- */

int extract_maximum(int Arr[])
{
    if(length == 0)
        cout << "Priority Queue is empty";

    int ans = Arr[1];
    swap(Arr[1], Arr[length]);
    length--;
    max_heapify(Arr, 1, length);
    return ans;
}

// Time - Complexity - O(log(N))


/*  ------------- Increase Value ---------------- */

// In case increasing value of any node, it may violate the property of max-heap, so we may have to swap the parent’s value with the node’s value until we get a larger value on parent node.

void increase_value(int Arr[], int i, int val) 
{
    if(val < Arr[i])
    {
        cout << "New value is less than the current value, can't be inserted";
        return;
    }
    Arr[i] = val;
    while(i > 1 && Arr[i] > Arr[i / 2])
    {
        swap(Arr[i], Arr[i / 2]);
        i /= 2;
    }
}

// Time - Complexity - O(log(N))

 void insert_value (int Arr[ ], int val)
{
    length = length + 1;
    Arr[ length ] = -1;  //assuming all the numbers greater than 0 are to be inserted in queue.
    increase_val (Arr, length, val);
}

// Time - Complexity - O(log(N))