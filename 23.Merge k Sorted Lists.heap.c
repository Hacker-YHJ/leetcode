/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
 
 void Minify(int size, struct ListNode* heap[size], int i) {
     int left = 2*i;
     int right = 2*i+1;
     int minimum = i;
     
     if (left < size && heap[left]->val < heap[minimum]->val) minimum = left;
     if (right < size && heap[right]->val < heap[minimum]->val) minimum = right;
     
     if (minimum != i) {
         struct ListNode * tmpp = heap[i];
         heap[i] = heap[minimum];
         heap[minimum] = tmpp;
         Minify(size, heap, minimum);
     }
 }

struct ListNode* getMin(int size, struct ListNode** heap) {
    if (0 == size) return NULL;
    struct ListNode* r = heap[0];
    heap[0] = heap[size-1];
    Minify(size-1, heap, 0);
    return r;
}

void insert(struct ListNode* toAdd, int size, struct ListNode** heap) {
    int pos = size;
    int parent;
    heap[pos] = toAdd;
    while (pos) {
        parent = pos/2;
        if (heap[parent]->val > heap[pos]->val) {
            struct ListNode * tmpp = heap[parent];
            heap[parent] = heap[pos];
            heap[pos] = tmpp;
        }
        pos = parent;
    }
}

void buildMin(int size, struct ListNode** heap) {
    for (int i = size/2; i >= 0; --i) {
        Minify(size, heap, i);
    }
}

struct ListNode* mergeKLists(struct ListNode** lists, int listsSize) {
    if (0 == listsSize) return NULL;
    
    struct ListNode* heap[listsSize];
    struct ListNode root;
    struct ListNode* pos = &root;
    struct ListNode* tmp;
    int currentSize = 0;
    
    root.next = NULL;
    for (int i = 0; i < listsSize; ++i) {
        if (lists[i]) {
            insert(lists[i], currentSize, heap);
            ++currentSize;
        }
    }
    
    while (tmp = getMin(currentSize, heap)) {
        --currentSize;
        pos->next = tmp;
        if (NULL != tmp->next) {
            insert(tmp->next, currentSize, heap);
            ++currentSize;
        }
        pos = pos->next;
    }
    
    return root.next;
}

// 388ms 46%
