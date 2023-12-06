/* Run time allocation of 1-d arrays malloc( ) alloc( )

malloc()- The “malloc” or “memory allocation” method in C is used to
    dynamically allocate a single large block of memory with the
    specified size. It returns a pointer of type void which can be cast
    into a pointer of any form.

maybe mean calloc? lol
alloc()- calloc” or “contiguous allocation” method in C is used to
    dynamically allocate the specified number of blocks of memory of the
    specified type.
1. It initializes each block with a default value ‘0’.
2. It has two parameters or arguments as compare to malloc().
*/

/* malloc() example */
int main()
{
 /* OUTPUT: 
    Enter number of elements: 5
    Memory successfully allocated using malloc.
    The elements of the array are: 1, 2, 3, 4, 5, */
    // This pointer will hold the
    // base address of the block created
    int* ptr;
    int n, i;
 
    // Get the number of elements for the array
    printf("Enter number of elements:");
    scanf("%d",&n);
    printf("Entered number of elements: %d\n", n);
 
    // Dynamically allocate memory using malloc()
    // Here, n * sizeof(int) ins the byte-size you want to allocate
    ptr = (int*)malloc(n * sizeof(int));
 
    // Check if the memory has been successfully
    // allocated by malloc or not
    if (ptr == NULL) {
        printf("Memory not allocated.\n");
        exit(0);
    }
    else {
 
        // Memory has been successfully allocated
        printf("Memory successfully allocated using malloc.\n");
 
        // Get the elements of the array
        for (i = 0; i < n; ++i) {
            ptr[i] = i + 1;
        }
 
        // Print the elements of the array
        printf("The elements of the array are: ");
        for (i = 0; i < n; ++i) {
            printf("%d, ", ptr[i]);
        }
    }
 
    return 0;
}
/* calloc() example */
int main()
{
 
    // This pointer will hold the
    // base address of the block created
    int* ptr;
    int n, i;
 
    // Get the number of elements for the array
    n = 5;
    printf("Enter number of elements: %d\n", n);
 
    // Dynamically allocate memory using calloc()
    // Params are (n, element-size), where it allocates contiguous
    // space in memory for n elements who each of the size of the element
    ptr = (int*)calloc(n, sizeof(int));
 
    // Check if the memory has been successfully
    // allocated by calloc or not
    if (ptr == NULL) {
        printf("Memory not allocated.\n");
        exit(0);
    }
    else {
 
        // Memory has been successfully allocated
        printf("Memory successfully allocated using calloc.\n");
 
        // Get the elements of the array
        for (i = 0; i < n; ++i) {
            ptr[i] = i + 1;
        }
 
        // Print the elements of the array
        printf("The elements of the array are: ");
        for (i = 0; i < n; ++i) {
            printf("%d, ", ptr[i]);
        }
    }
 
    return 0;
}





/* Freeing allocated memory for 1-d arrays.
The memory allocated using functions malloc() and calloc() is not
de-allocated on their own. Hence the free() method is used, whenever
the dynamic memory allocation takes place. It helps to reduce 
wastage of memory by freeing it.
*/
free(ptr);

 
 /* Run-time allocation of 2-d arrays 
 REMEMBER***- free the memory for EACH ROW in the array!!
*/
int main()
{
    int r = 3, c = 4, i, j, count;
 
    int* arr[r];
    // can also do
    int** arr = (int**)malloc(r * sizeof(int*)); 

    for (i = 0; i < r; i++)
        arr[i] = (int*)malloc(c * sizeof(int));
 
    // Note that arr[i][j] is same as *(*(arr+i)+j)
    count = 0;
    for (i = 0; i < r; i++)
        for (j = 0; j < c; j++)
            arr[i][j] = ++count; // Or *(*(arr+i)+j) = ++count
 
    for (i = 0; i < r; i++)
        for (j = 0; j < c; j++)
            printf("%d ", arr[i][j]);
 
    /* Code for further processing and free the
      dynamically allocated memory */
 
    for (int i = 0; i < r; i++)
        free(arr[i]);
 
    return 0;
}

/* Freeing allocated memory for 2-d arrays.
ABOVE^^!! all good now :)
*/
