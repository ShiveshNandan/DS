#include <stdio.h>
#include <stdlib.h>


int menuOption;



    int sizearr;
    int array1[10];


void setValues()
{
    sizearr = 0;
}


int mainmenu()
{
    printf("Press 1 for insertion\n");
    printf("Press 2 for deletion\n");
    printf("Press 3 for traversing\n");
    printf("Press 4 for linear search\n");
    printf("Press 5 for selection sort\n");
    printf("Press 9 to exit\n");
    printf(" Specify your choice : \n");
    scanf("%d", &menuOption);
}

int menu1()
{
    printf("Press 1 for insertion\n");
    printf("Press 9 to exit\n");
    printf(" Specify your Choice : \n");
    scanf("%d", &menuOption);
}


void printArr()
{
    if ( sizearr == 0)
    {
        printf("The array is empty\n");
    }
    else
    {
        printf("The array is : ");
        for (int i = 0; i <  sizearr - 1; i++)
        {
            printf("%d, ",  array1[i]);
        }
        printf("%d\n",  array1[ sizearr - 1]);
    }
    printf("\n");
}

void swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}
 
void selectionSort()
{
    int i, j, min_idx;
 
   
    for (i = 0; i <  sizearr -1; i++)
    {

        min_idx = i;
        for (j = i+1; j <  sizearr; j++)
          if ( array1[j] <  array1[min_idx])
            min_idx = j;
 
        
           if(min_idx != i)
            swap(& array1[min_idx], & array1[i]);
    }
    printArr();
}

int insertion()
{
    int element, index, choice;
    int beginning()
    {
        printf("This is the first element of this array : \n");
        scanf("%d", &element);
        if ( sizearr>0)
        {
            for (int i =  sizearr; i >=0 ; i--)
            {
                 array1[i] =  array1[i-1];
            }
        }
         array1[0] = element;
         sizearr++;
        printArr();
    }
    int atIndex()
    {
        printf("Please Specify the Index: ");
        scanf("%d", &index);
        if (index<= sizearr)
        {    
            printf("This element will be inserted at %d index :%d\n", index, index);
            scanf("%d", &element);
            
            for (int i =  sizearr; i > index; i--)
            {
                 array1[i] =  array1[i-1];
            }
             array1[index] = element;
             sizearr++;
            printArr();
        }
        // checks
        else
        {
            printf("Wrong index  Useed !!!");
        }
        
    }
    int end()
    {
        printf("Last element of the array will be : \n");
        scanf("%d", &element);
         array1[ sizearr] = element;
         sizearr++;
        printArr();
    }
flag:
    switch ( sizearr)
    {
    case 0:
        beginning();
        break;

    case 2 ... 9:
        printf(" Use 1 to  Use in the beginning\n");
        printf(" Use 2 to  Use in the end\n");
        printf(" Use 3 to  Use at a specific index\n");
        scanf("%d", &choice);
        if (choice == 1)
        {
            beginning();
        }
        else if (choice == 2)
        {
            end();
        }
        else if (choice == 3)
        {
            atIndex();
        }
        else
        {
            printf("Choice out of range\n");
            goto flag;
        }
        break;
    default:
        printf("Index out of bounds\n");
        break;

    case 1:
        printf(" Use 1 to  Enter in the beginning\n");
        printf(" Use 2 to  Enter in the end\n");
        scanf("%d", &choice);
        if (choice == 1)
        {
            beginning();
        }
        else if (choice == 2)
        {
            end();
        }
        else
        {
            printf("Choice out of range\n");
            goto flag;
        }
        break;
    }
}

int deletion()
{
    int index;
flag_1:
    printf(" Specify the index of the element you want to delete\n");
    scanf("%d", &index);
    if (index >= 0 && index <=  sizearr)
    {
        for (int i = index; i <=  sizearr; i++)
        {
             array1[i] =  array1[i + 1];
        }
         sizearr--;
        printArr();
    }
    else
    {
        printf("Index out of range\n");
        goto flag_1;
    }
}


int traversing(){
    for (int i = 0; i <  sizearr; i++)
    {
        printf("\t %d \n",i);
    }
    printArr();
}

int searching()
{
    int element, crash = -1;
flag_2:
    printf(" Specify the element you want to search for: \n");
    scanf("%d", &element);
    for (int i = 0; i <  sizearr; i++)
    {
        if ( array1[i] == element)
        {
            crash = i;
        }
    }
    if (crash >= 0)
    {
        printf("The index of %d is %d\n", element, crash);
    }
    else
    {
        printf("No element found\n");
        goto flag_2;
    }
}

int sorting()
{
    int min, crash, temp;
    for (int i = 0; i <  sizearr; i++)
    {
        min =  array1[i];
        for (int j = i + 1; j <  sizearr; j++)
        {
            if ( array1[j] < min)
            {
                min =  array1[j];
                crash = j;
            }
        }
        temp =  array1[i];
         array1[i] = min;
         array1[crash] = temp;
    }
    printArr();
}

// main function
int main()
{
    setValues();
    printArr();
showMenu:
    if ( sizearr == 0)
    {
        menu1();
        switch (menuOption)
        {
        case 1:
            insertion();
            break;
        case 9:
            exit(0);
            break;
        default:
            printf("Please  Use correct input\n");
            goto showMenu;
            break;
        }
    }

    else
    {
        mainmenu();
        switch (menuOption)
        {
        case 1:
            insertion();
            break;
        case 2:
            deletion();
            break;
        case 3:
            traversing();
            break;
        case 4:
            searching();
            break;
        case 5:
            selectionSort();
            break;
        case 9:
            exit(0);
            break;
        default:
            printf("Please  Use correct input\n");
            goto showMenu;
            break;
        }
    }

    
    goto showMenu;
    return 0;
}
