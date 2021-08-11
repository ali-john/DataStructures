#include <iostream>
#include <vector>
using namespace std;



void PrintArray(int Arr[],int size)

{
    cout<<endl;
    cout<<"Sorted Array is : "<<endl;
    for (int i=0;i<size;i++)
        cout<<Arr[i]<<" ";

    cout<<endl;
}

void SelectionSort(int InputArray[],int size)

{

    for (int i = 0; i < size-1; i++)

    {
        //keep record of starting position which will be swaped
        int minimum=i;
            for (int j=i+1; j<=size;j++)

            {

                if(InputArray[minimum] > InputArray[j])
                    minimum=j;


            }
        //swap the minimum value in array with the starting value
        swap(InputArray[i],InputArray[minimum]);
    }

}


void BubbleSort(int InputArray[],int size)

{
    /*
     *  Bubble sort sorts by swapping two consecutive elements. Selection sort looks for minimum in array
     */

    for (int i=0; i<size-1;i++)

    {
        for     (int j=i+1;j<size;j++)

        {
            if (InputArray[i] > InputArray[j])
                swap(InputArray[i],InputArray[j]);
        }

    }
    PrintArray(InputArray,size);


}

void InsertionSort(int InputArray[],int size)


{

    for (int i=1;i<size;i++)

    {
        int hole=i;
        int value=InputArray[i];

            while(hole>0 && InputArray[hole-1]>value)

            {
                InputArray[hole]=InputArray[hole-1];
                hole=hole-1;
            }
            InputArray[hole]=value;
    }
    PrintArray(InputArray, size);

}


void Merge (int left[],int right[],int InputArray[],int right_size,int left_size)

{

    // i--> for right array , j-->for left, k--> for main array
    int i=0,j=0,k=0;

        while (i<right_size && j<left_size)

        {
            if(right[i]<= left[j])
            {
                InputArray[k]=right[i];
                i++;
            }
            else
            {
                InputArray[k]=left[j];
                j++;
            }
            k++;

        }

        while  (i<right_size)

        {
            InputArray[k]=right[i];
            k++;
            i++;
        }

        while (j<left_size)

        {
            InputArray[k]=left[j];
            k++;
            j++;
        }

}
void MergeSort(int InputArray[],int size)

{

    if (size<2)
        return;
    else
    {
        int mid=size/2;
        int left_arr[mid];
        int right_arr[size-mid];

            for (int i=0; i < mid;i++)

            {
                    left_arr[i]=InputArray[i];

            }

            for (int j=mid;j<size;j++)

            {
                    right_arr[j-mid]=InputArray[j];
            }

            MergeSort(left_arr,mid);
            MergeSort(right_arr,(size-mid));
            Merge(left_arr,right_arr,InputArray,(size-mid),mid);

        }

}


void CountSort(int array[], int size, int x)


{

    int output[size];
    int i, count_arr[10] = {0};


        for (i = 0; i < size; i++)
            count_arr[(array[i] / x) % 10]++;


        for (i = 1; i < 10; i++)
            count_arr[i] += count_arr[i - 1];


        for (i = size - 1; i >= 0; i--) {
            output[count_arr[(array[i] / x) % 10] - 1] = array[i];
            count_arr[(array[i] / x) % 10]--;
        }



        for (i = 0; i < size; i++)
            array[i] = output[i];
}


int FindMax(int arr[],int size)//finds the maximum value in an array

{
    int max=arr[0];
        for (int i=1;i<size;i++)
                if (arr[i]> max)
                    max=arr[i];
        return max;
}
void RadixSort(int InputArray[], int size)


{

    int max_number=FindMax(InputArray,size);

        for (int x = 1; max_number / x > 0; x *= 10)
            CountSort(InputArray, size, x);
}


int Partitioning(int InputArray[],int start, int end)

{
    int pivot=InputArray[end];
    int pivot_index=start;

        for (int i=start; i<end; i++)

        {
                if (InputArray[i]<=pivot)

                {
                    swap(InputArray[i],InputArray[pivot_index]);
                    pivot_index++;
                }

        }
        swap(InputArray[end],InputArray[pivot_index]);
        return pivot_index;
}

void QuickSort(int InputArray[],int start,int end)

{
    if(start<end)

    {
        int partition_index=Partitioning(InputArray,start,end);
        QuickSort(InputArray, start,partition_index-1);
        QuickSort(InputArray,partition_index,end);
    }
}

int BinarySearch(int InputArray[], int start, int end, int key)

{

    if (end>=start)
    {
        int mid=start+(end-start)/2;

            if (InputArray[mid]==key)
                return mid;

            else if (InputArray[mid]>key)

            {
                return BinarySearch(InputArray,start,mid-1,key);
            }

            else

            {
                return BinarySearch(InputArray,mid+1,end,key);
            }
    }
    return -1; //key does not exist in array.


}

int LinearSearch(int InputArray[], int start,int end,int key)


{

    for (int i=start;i<end;i++)
        if (InputArray[i]==key)
            return i;

    return -1;


}
int main()


{
     cout<<"SELECTION SORT "<<endl;
     cout<<"INPUT ARRAY IS: "<<endl;
     cout<<" 3 5 0 12 5 8 19 13 10 23"<<endl;
     int arr[10]={3,5,0,12,6,8,19,13,10,23};
     SelectionSort(arr,10);

     cout<<"..............."<<endl;
     cout<<"BUBBLE SORT "<<endl;
    int arr1[10]={3,5,0,12,6,8,19,13,10,23};
    cout<<"INPUT ARRAY IS: "<<endl;
    cout<<" 3 5 0 12 5 8 19 13 10 23"<<endl;
    BubbleSort(arr1,10);
    cout<<"................."<<endl;

    cout<<"INSERTION SORT "<<endl;
    cout<<"INPUT ARRAY IS: "<<endl;
    cout<<" 3 5 0 12 5 8 19 13 10 23"<<endl;
    int arr2[10]={3,5,0,12,6,8,19,13,10,23};
    InsertionSort(arr2,10);
    cout<<".................."<<endl;


    cout<<"MERGE SORT "<<endl;
    cout<<"INPUT ARRAY IS: "<<endl;
    cout<<" 3 5 0 12 5 8 19 13 10 23"<<endl;
    int arr3[10]={3,5,0,12,6,8,19,13,10,23};
    MergeSort(arr3,10);
    PrintArray(arr3,10);
    cout<<".................."<<endl;


    cout<<"RADIX SORT "<<endl;
    cout<<"INPUT ARRAY IS: "<<endl;
    cout<<" 3 5 0 12 5 8 19 13 10 23"<<endl;
    int arr4[10]={3,5,0,12,6,8,19,13,10,23};
    RadixSort(arr4,10);
    PrintArray(arr4,10);
    cout<<".................."<<endl;


    cout<<"BINARY SEARCH "<<endl;
    cout<<"INPUT ARRAY IS: "<<endl;
    cout<<" 3 5  12 15 18 19 23  24"<<endl;
    int arr5[8]={3,5,12,15,18,19,23,24};//array must be sorted for binary search
    int index=BinarySearch(arr5,0,7,19);
    (index!=-1)? cout<<"ELEMENT 19 IS AT POSITION "<<index<<endl : cout<<"ELEMENT 19 IS NOT PRESENT "<<endl;
    cout<<".................."<<endl;


    cout<<"LINEAR SEARCH "<<endl;
    cout<<"INPUT ARRAY IS: "<<endl;
    cout<<" 3 5 0 12 5 8 19 3 10 23"<<endl;
    int arr6[10]={3,5,0,12,6,8,19,3,10,23};
    int i=LinearSearch(arr6,0,9,12);
    (index!=-1)? cout<<"ELEMENT 12 IS AT POSITION "<<i<<endl : cout<<"ELEMENT 12 IS NOT PRESENT "<<endl;
    cout<<".................."<<endl;






    return 0;
}
