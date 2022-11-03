#include <stdio.h>
#include <stdlib.h>
struct Array
{
    int *A;
    int size;
    int length;
};
void Display(struct Array arr)
{
    int i;
    printf("\nElements are :\n");
    for (i = 0; i < arr.length; i++)
        printf("%d ", arr.A[i]);
}
void Append(struct Array *arr, int x)
{
    if (arr->length < arr->size)
        arr->A[arr->length++] = x;
}
void Insert(struct Array *arr, int index, int x)
{
    int i;
    if (index >= 0 && index <= arr->length)
    {
        for (i = arr->length; i > index; i--)
            arr->A[i] = arr->A[i - 1];
        arr->A[index] = x;
        arr->length++;
    }
}
int Delete(struct Array *arr, int index)
{
    int x = 0;
    int i;
    if (index >= 0 && index < arr->length)
    {
        x = arr->A[index];
        for (i = index; i < arr->length - 1; i++)
            arr->A[i] = arr->A[i + 1];
        arr->length--;
        return x;
    }
    return 0;
}
void swap(int *x, int *y)
{
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}
int LinearSearch(struct Array *arr, int key)
{
    int i;
    for (i = 0; i < arr->length; i++)
    {
        if (key == arr->A[i])
        {
            swap(&arr->A[i], &arr->A[0]);
            return i;
        }
    }
    return -1;
}

void selectionSort(struct Array *arr)
{
    for (int i = 0; i < arr->length - 1; i++)
    {
        int minIndex = i;

        for (int j = i + 1; j < arr->length; j++)
        {
            if (arr->A[j] < arr->A[minIndex])
            {
                minIndex = j;
            }
        }

        swap(arr->A[i], arr->A[minIndex]);
    }
}

struct Array *Difference(struct Array *arr1, struct
                         Array *arr2)
{
    int i, j, k;
    i = j = k = 0;
    struct Array *arr3 = (struct Array
                              *)malloc(sizeof(struct Array));
    while (i < arr1->length && j < arr2->length)
    {
        if (arr1->A[i] < arr2->A[j])
            arr3->A[k++] = arr1->A[i++];
        else if (arr2->A[j] < arr1->A[i])
            j++;
        else
        {
            i++;
            j++;
        }
    }
    for (; i < arr1->length; i++)
        arr3->A[k++] = arr1->A[i];
    arr3->length = k;
    arr3->size = 10;
    return arr3;
}
int main()
{
    struct Array arr1;
    int ch;
    int x, index;
    printf("Enter Size of Array : \n");
    scanf("%d", &arr1.size);
    arr1.A = (int *)malloc(arr1.size * sizeof(int));
    arr1.length = 0;
    do
    {
        printf("\n\nMenu\n");
        printf("0. Sort\n");
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Search\n");
        printf("4. Display\n");
        printf("5.Exit\n");
        printf("enter you choice: \n ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 0:
            if (arr1.length > 1)
            {
                selectionSort(&arr1);
            }
            Display(arr1);
            break;
        case 1:
            printf("Enter an element and index: \n");
            scanf("%d%d", &x, &index);
            Insert(&arr1, index, x);
            break;
        case 2:
            printf("Enter index: \n ");
            scanf("%d", &index);
            x = Delete(&arr1, index);
            printf("Deleted Element is: %d\n", x);
            break;
        case 3:
            printf("Enter element to search: \n");
            scanf("%d", &x);
            index = LinearSearch(&arr1, x);
            printf("Element index: %d", index);
            break;
        case 4:
            Display(arr1);
        }
    } while (ch < 5);
    return 0;
}
