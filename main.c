#include <stdio.h>
#include <stdlib.h>

/*
    Below will be quite a few operations I attempted successfully on a hard-coded array.
    Hopefully my comments and the code itself will help understand each better.
*/


/*
    OPERATION#1: Simply prints the list using the standard for loop. Since this function exists already
    and most of my testing involved printing the array, you'll see it being called a lot within these
    subsequent functions.
*/
void printList(int *numberList,int size)
{
    for(int i=0;i<size;i++)
    {
        printf("Item#%d : %d\n",(i+1),numberList[i]);
    }
}


/*
    OPERATION#2: Adding a new element to this array.
    This one first increments the size of the array by one,
    then works backwards from end of the array until desired position of
    new element, so it shifts new elements to the right until i is equal to the position given by user.
    Then since the user's input will be one more than the actual index of the element in the array,
     the code assigning the new number to the user is assigned there.
     In other words, if in my original {1,2,3,4,5}, user wants 6 where 3 is:
     numberList[3-1]=3;

*/
void addToList(int *numberList,int position,int number,int size)
{
    size++;
    for(int i=(size-1);i>=position;i--)
    {
        numberList[i]=numberList[i-1];
    }
    numberList[position-1]=number;
    printList(numberList,size);
}


/*
    OPERATION#3: DELETION:
    Opposite of #2 in the following ways:
    1. Uses three parameters instead of 4 since we don't need a new number from the user,
    only where they wanna delete from.
    2. We start from 1 backwards of position chosen (again to match the index in the array)
    and go FORWARD in the array instead of backwards until the very end, then the element to the
    immediate right is shifted to the left.

*/
void deleteFromList(int *numberList,int position,int size)
{
    for(int i=(position-1);i<=(size-1);i++)
    {
        numberList[i]=numberList[i+1];
    }
    printf("New list post deletion:\n");
    printList(numberList,size);
}

/*
    OPERATION #4 &#5: FINDING BIGGEST AND SMALLEST NUMBERS
    For biggest number (immediately below) we pick the number at the end of the array and assign it to a variable,
    independent of its size.Then we move through the array and compare each element to aforementioned variable
    and return accordingly. Similar logic with smallest number but with inequality signs reversed.
*/

int maxNumber(int *numberList,int size)
{
    int mkubwa=numberList[size-1];
    for(int i=0;i<size;i++)
    {
        if(numberList[i]>mkubwa)
        {
            return numberList[i];
        }
        else
        {
            return mkubwa;
        }
    }
}

int minNumber(int *numberList,int size)
{
    int mdogo=numberList[0];
    for(int i=0;i<size;i++)
    {
        if(numberList[i]<mdogo)
        {
            return numberList[i];
        }
        else
        {
            return mdogo;
        }
    }
}

/*
    OPERATION#6: SUM AND AVERAGE
    We'll initialize a variable sum to zero then use a for loop to repetitively add each element
    in the array to the sum variable to update it in real time. Average will then be sum divided by
    size(representing number of items in array) with appropriate type casting.
*/

void sumAndAverage(int *numberList,int size)
{
    double sum=0;
    for(int i=0;i<size;i++)
    {
        sum+=numberList[i];
    }
    double average= ((double)sum/size);
    printf("Sum of items: %.2lf\nAverage:%.2lf\n",sum,average);
}

/*
    OPERATION#7: REVERSAL OF ARRAY
    This one is interesting since each element in the array is assigned the one from (size-i-1).
    Notice I needed an uninitialized array at first since if I just reassigned in the original array,
    it would successfully flip it in the second half until the middle element but then duplicate those from the
    first half.In my attempts at least!
*/
void flippedArray(int *numberList, int size)
{
    int tsiLrebmun[size];
    for(int i=0;i<size;i++)
    {
        tsiLrebmun[i]=numberList[(size-i-1)];
    }
    printf("Oh, and the list flipped looks like this:\n");
    printList(tsiLrebmun,size);
}
/*
    SIDENOTE: All the functions above take the array I'm operating on as an argument hence the *,
    since in C and C++ any arrays passed to a function are passed by REFERENCE because they
    decay to pointers rather than VALUE as you would normally pass int, char and the like.
*/



int main()
{
    int numberList[5]={1,2,3,4,5};
    int arraySize= (sizeof(numberList)/4);
    //printf("%d\n",arraySize);
    int position,newNumber;
    printList(numberList,arraySize);
    printf("Enter where in this list you wanna add an item. \n");
    scanf("%d",&position);
    printf("Now enter what number you'd like to add.\n");
    scanf("%d",&newNumber);
    addToList(numberList,position,newNumber,arraySize);
    printf("Now for deletion...");
    printf("New list:\nType number of item you wanna delete: \t");
    scanf("%d",&position);
    deleteFromList(numberList,position,arraySize);
    printf("\n");
    printf("Biggest number: %d\nSmallest number: %d\n",maxNumber(numberList,arraySize),minNumber(numberList,arraySize));
    printf("\n");
    sumAndAverage(numberList,arraySize);
    printf("\n");
    flippedArray(numberList,arraySize);
}

 //Recalling how swapping is done efficiently(1st method) and creatively(2nd method)
    /*int a=50,b=70,temp;
    //Standard swapping using a 3rd varibale
    printf("Normal:%d, %d\n",a,b);
    temp=a;
    a=b;
    b=temp;
    //...then swapping again to try another swapping style
    printf("Swapped:%d, %d\n",a,b);
    temp=a;
    a=b;
    b=temp;
    //Another interesting way to swap but works with numeric data types only (no way to add strings for example!)
    printf("Normal again: %d, %d\n",a,b);
    a=(a+b);
    //a==50+70->120
    b=(a-b);
    //b==120-50 ->70
    a=a-b;
    //a== 120-70 ->50
    printf("Swapped once more: %d, %d\n",a,b);
    */
