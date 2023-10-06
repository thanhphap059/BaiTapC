// So sanh theo su giong nhau
#include<stdio.h>
#include<stdbool.h>

bool isEqual(const char array1[], const char array2[]){
    
    int i=0;
    while(array1[i] == array2[i]){
        if(array1[i] == '\0') return true;
        i++;
    }
    return false;
}

void swap(int* a, int* b) {
    int t = *a;
    *a = *b;
    *b = t;
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pivot = arr[high];
        int i = low - 1;

        for (int j = low; j <= high - 1; j++) {
            if (arr[j] < pivot) {
                i++;
                swap(&arr[i], &arr[j]);
            }
        }

        swap(&arr[i + 1], &arr[high]);
        quickSort(arr, low, i);
        quickSort(arr, i + 2, high);
    }
}


void Display(int arr[], int size){
    for(int i=0;i<size;i++){
        if(arr[i]==arr[i-1]) continue;
        int count =0;
        for(int j=i;j<size;j++){
            if(arr[i]==arr[j]){
                count++;
            }else break;
        }
        printf("\n So %d xuat hien %d lan", arr[i],count);

    }
}


int main(int argc, char const *arv[]){
    int array[]={1,2,4,5,6,2,3,4,8,9,3,5,6};
    char test1[]="Hello Word!";
    char test2[]="This is Test";
    size_t size = sizeof(array)/ sizeof(array[0]);
    printf("\n Size = %d",size);

    printf("\n Result: %d",isEqual(test1,test2));

    quickSort(array, 0, size - 1);
    printf("\nMang sau khi sap xep:\n");
    for (int i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }

    Display(array,size);
    return 0;
}