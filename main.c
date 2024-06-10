#include <stdio.h>
#include <stdlib.h>

void printList(int* numberList,int size)
{
    for(int i=0;i<size;i++)
    {
        printf("Item#%d : %d\n",(i+1),numberList[i]);
    }
}

void addToList(int* numberList,int position,int number,int size)
{
    size++;
    for(int i=(size-1);i>=position;i--)
    {
        numberList[i]=numberList[i-1];
    }
    numberList[position-1]=number;
    printList(numberList,size);

}

void deleteFromList(int* numberList,int position,int size)
{
    for(int i=(position-1);i<=(size-1);i++)
    {
        numberList[i]=numberList[i+1];
    }
    printf("New list post deletion:\n");
    printList(numberList,size);

}

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

void sumAndAverage(int *numberList,int size)
{
    double sum=0;
    for(int i=0;i<size;i++)
    {
        sum+=numberList[i];
    }
    double average= ((double)sum/size);
    printf("Sum of items: %.2lf\nAverage:%.2lf",sum,average);
}

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
    printf("Biggest number: %d\nSmallest number: %d\n",maxNumber(numberList,arraySize),minNumber(numberList,arraySize));
    sumAndAverage(numberList,arraySize);



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
