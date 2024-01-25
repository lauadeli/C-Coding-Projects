#include <stdio.h>

/*
 * Question 2: Converts any variable to the value 10
 */
void convert(int *num){
    *num = 10;
}

/* 
 * Question 3: Changes a list of length 3 to {"d", "e", "f"}
 */

void changeList(char *input, char *arr[3], int ind){
    arr[ind] = input;
    //arr[0] = input; arr[1] = input; arr[2] = input;

}

/*
 * Question 4: Sorts list to increasing order 
 */

int cmpfunc (const void * a, const void * b) {
   return ( *(int*)a - *(int*)b );
}
void InsertionSort(int nums[5]){
    qsort(nums, 5, sizeof(int), cmpfunc);
}

void sort(int *array){
    int i = 1;
    while (i<5){
        int j = i;
        while(j>0 && *(array + j - 1) > *(array + j)){
            int temp = array[j];
            array[j] = array[j-1];
            array[j-1] = temp;
            j = j -1;
        }
        ++i;
    }
}

/*
 * Question 5: Function which finds the length of a string (O(n)) where n is the length of the string 
 */

void length_str(char *string){
    
    int length = 0;
    while (*string != NULL){
        ++length;
        string ++;
    }
    printf("Question 5: The length is %d\n", length);
}

/*
 * Question 6: Function which replaces instance of arr2 in arr1 with 0s
 */

void seq_replace(int *arr1, unsigned long arr1_sz, int *arr2, unsigned long arr2_sz){
    for(int k = 0; k < arr1_sz; ++k){
        for(int l = 0; l < arr2_sz; ++l){
            if (*(arr1 + k) == *(arr2 + l)){
                *(arr1 + k) = 0;
            }
        }
    }
}


int main(void){

    //Question 2
    int a = 5;
    int *p_a = &a;
    convert(p_a);
    printf("Question 2: The interger, a, has a value of %d\n", a);

    //Question 3
    char *arr[3] = {"a", "b", "c"};
    char *input = "p";
    changeList(input, arr, 2);

    printf("Question 3: The array is %s and %s and %s\n", arr[0], arr[1], arr[2]);

    //Question 4
    
    /*
    int nums[5] = {3, 4, 2, 6, 5};
    InsertionSort(nums);
    
    for(int i = 0; i < 5; ++i){
        printf("%d\n", nums[i]);
    }
    */
    int arrrr[5] = {3, 4, 2, 6, 5};
    sort(arrrr);
    int index; 
    printf("Question 4: The sorted list is:\n");
    for(index = 0; index<5; ++index){
        printf("%d\n", *(arrrr + index));
    }

    //Question 5
    char *s = "hello";
    length_str(s);
    

    //Question 6
    int acc1[] = {5, 6, 7, 8, 6, 7};
    int acc2[] = {6,7};
    seq_replace(acc1, 6, acc2, 2);
    printf("Question 6: The edited array is this:\n");
    for(int inde = 0; inde<6; ++inde){
        printf("%d\n", *(acc1 + inde));
    }
    return 0;
}
