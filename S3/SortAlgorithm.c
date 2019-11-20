#include <stdio.h>
#include <stdlib.h>


void QuickSort(int *number,int first,int last){
    int i, j, pivot, temp;

    if(first<last){
        pivot=first;
        i=first;
        j=last;

        while(i<j){
            while(number[i]<=number[pivot]&&i<last)
                i++;
            while(number[j]>number[pivot])
                j--;
            if(i<j){
                temp=number[i];
                number[i]=number[j];
                number[j]=temp;
            }
        }

        temp=number[pivot];
        number[pivot]=number[j];
        number[j]=temp;
        QuickSort(number,first,j-1);
        QuickSort(number,j+1,last);

    }
}
void  Merge(int *array,int l,int m,int r){
    int i,j,k,n1,n2,*a1,*a2;

    n1=m-l+1;
    n2=r-m;
    a1=(int*)malloc(sizeof(int)*n1);
    a2=(int*)malloc(sizeof(int)*n2);
    for(i=0;i<n1;i++)
        a1[i]=array[i+l];
    for(i=0;i<n2;i++)
        a2[i]=array[m+1+i];
    i=0;
    j=0;
    k=l;
    while (i<n1 && j<n2){
        if(a1[i]<=a2[j]){
            array[k]=a1[i];
            i++;
        }
        else{
            array[k]=a2[j];
            j++;
        }
        k++;
    }
    while (i<n1){
        array[k]=a1[i];
        i++;
        k++;
    }
    while (j<n2){
        array[k]=a2[j];
        j++;
        k++;
    }
}
void MergeSort(int *array,int l,int r){
    int mid;
    if(l<r){
        mid=(l+r)/2;
        MergeSort(array,l,mid);
        MergeSort(array,mid+1,r);
        Merge(array,l,mid,r);
    }
}
void Display(int *ar,int n){
    int i;
    printf("\nThe Sorted array is : ");
    for(i=0;i<n;i++){
        printf("%d ",ar[i]);
    }
}
void InsertionSort(int *ar,int n){
    int i,j,d;
    for(i=1;i<n;i++){
        j=i-1;
        d=ar[i];
        while (j>=0 && ar[j]>d){
            ar[j+1]=ar[j];
            j--;
        }
        ar[j+1]=d;
    }
}
void Insert(int *ar, int n){
    int i;
    for(i=0;i<n;i++){
        printf("Enter the number : ");
        scanf("%d",&ar[i]);
    }
}

int main(){
    int *ar,i,o=1,n;
    while(o<4){
        printf("\n\n1.InsertionSort\n2.MergeSort\n3.QuickSort\n4.Exit\n\nSelect an Option : ");
        scanf("%d",&o);
        switch (o){
            case 1: printf("\nEnter the Size of Array : ");
                    scanf("%d",&n);
                    ar=(int*)malloc(sizeof(int)*n);
                    Insert(ar,n);
                    InsertionSort(ar,n);
                    Display(ar,n);
                    break;
            case 2: printf("\nEnter the Size of Array : ");
                    scanf("%d",&n);
                    ar=(int*)malloc(sizeof(int)*n);
                    Insert(ar,n);
                    MergeSort(ar,0,n-1);
                    Display(ar,n);
                    break;
            case 3: printf("\nEnter the Size of Array : ");
                    scanf("%d",&n);
                    ar=(int*)malloc(sizeof(int)*n);
                    Insert(ar,n);
                    QuickSort(ar,0,n-1);
                    Display(ar,n);
        }
    }

}