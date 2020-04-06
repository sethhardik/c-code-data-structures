#include<iostream>

using namespace std;

void bubblesort(int ar[], int N);
void insertionsort(int arr[], int N);
void selectionsort(int arr[], int N);
//--------------------------------------------------------------start main---------------------------------------------------------
int main()
{
    int choice,i,N,arr[500],re_arr[500];
    cout<<"enter size of array:";
    cin>>N;
    cout<<"\nenter elements in array:\n";
    for(int i=0;i<N;i++)
    {
        cin>>arr[i];
    }
    cout<<"\t\t\tSorting Menu\n1> Bubble Sort\n2> Insertion Sort\n3> Selection Sort\n";
    cin>>choice;
    switch(choice)
    {
    case 1:
        cout<<"Bubble Sorting\n";
        bubblesort(arr,N);
        break;
    case 2:
        cout<<"\nInsertion Sorting\n";
        insertionsort(arr,N);
        break;
    case 3:
        cout<<"\nSelection Sorting\n";
        selectionsort(arr,N);
        break;
    case 4:
    	cout<<"\n Merge Sorting\n";
    	break;
    default:
        cout<<"Wrong Input";
    }

}
//--------------------------------------------------------end of if-----------------------------------------------------
//--------------------------------------------------------bubble sort----------------------------------------------------
void bubblesort(int arr[],int N)
{
    int temp,swap_counter=0;
    for(int i=0;i<N;i++)
    {
        for(int j=i+1;j<N;j++)
        {
            if(arr[i]>arr[j])
            {
                temp=arr[i];
                arr[i]=arr[j];
                arr[j]=temp;
                ++swap_counter;
            }
        }
        if(swap_counter==0)
            {
                cout<<"\nsorted array\n";
                break;
            }
        swap_counter=0;
    }
    for(int i=0;i<N;i++)
    {
        cout<<arr[i]<<endl;
    }
}
//------------------------------------------------------insertion sort-----------------------------------------------------
void insertionsort(int arr[],int N)
{
    int i,j,key;
    for(i=1;i<N;i++)     // looping from 2nd element taking 1st to be sorted
    {
        key=arr[i];      // key = to ith element
        j=i-1;           // j is starting from 0 rather than starting with i
        while((j>=0) && (key<arr[j]))   // loop below statement when both the condition satisfied
        {
            arr[j+1]=arr[j];           // put copy of j in j+1 removing key from the array. but key variable is still intact
            j--;                       // decrease value of j for above conditions
        }
        arr[j+1]=key;                   // if all comparison done and finally key>arr[j] put key in the array
    }
    for(int i=0;i<N;i++)
    {
        cout<<arr[i]<<endl;
    }
}
//--------------------------------------------------------selection sort--------------------------------------------------------
void selectionsort(int arr[],int N)
{
	int i, j,min,temp;
	for(i=0;i<N-1;i++)  //----loop1--------
	{
		min=i;
		for(j=i+1;j<N;j++) //----loop2------
		{
			if(arr[j]<arr[min])
			{
				min=j;   //-------change index-------
			}
		}
		temp=arr[min];
		arr[min]=arr[i];
		arr[i]=temp;
	}
	for(i=0;i<N;i++)      //-----------------------print-------------------
	{
		cout<<arr[i]<<endl;
	}	
}

