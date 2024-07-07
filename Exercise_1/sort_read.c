/*Question1: Two inputs here: one is the array[] mentioned above and the other has to be read from the numbers.txt file,
Take the data from both the inputs and sort in ascending order */

#include <stdio.h>
#include <stdlib.h>

void sort(int total_size, int merged_array[]){

    //for sorting the array
    for(int i=0; i<total_size; i++){
        for(int j=0; j<total_size-1; j++){
            if(merged_array[j] > merged_array[j+1]){
                merged_array[j] ^= merged_array[j + 1];
                merged_array[j + 1] ^= merged_array[j];
                merged_array[j] ^= merged_array[j + 1];
            }
        }
    }
}

void mirror(int mirror_array[],int sorted_array[], int total_size){

    for(int i=0; i<total_size; i++){
        long int rev_val = 0;
        for(int j=0; j<8; j++){
            rev_val = (rev_val << 4) | ((sorted_array[i] >> (4 * j)) & 0xF);
        }
        mirror_array[i] = rev_val;
    }

    printf("The mirror value is:\n");
    for (int i = 0; i < total_size; i++) {
        printf("%08X\t", mirror_array[i]);
    }
}

int main() {
    
    int array[] = {0x6BAF1000, 0x19F45200, 0x71802300, 0x82424000, 0x35601000};
    int array_size = sizeof(array)/sizeof(array[0]);
    int mirror_array[10];
    int sorted_array[100];

    // File input
    FILE *fp = fopen("numbers.txt", "r");
    if (fp == NULL) {
        printf("Error opening file 'hex_values.txt'\n");
        return 1;
    }

    // Read hexadecimal values from file into temp array
    int file_value[10];
    int index = 0;

    // Read hexadecimal values from file and add to char array
    char str[12]; 

    //copy the content from file to file_value[]
    while (fscanf(fp, "%s", str) == 1) {
        file_value[index++] = (int)strtol(str, NULL, 16);  /*strol is used to convert str to int*/
    }                                                                 

    fclose(fp);

    // Merging arrays (array[] and file_value[]) into merged_array
    int total_size = array_size + index;
    int merged_array[20];

    // Copy array[] elements to merged_array[]
    for (int i = 0; i < array_size; i++) {
        merged_array[i] = array[i];
    }

    // Copy file_value[] to merged_array[]
    for (int i = 0; i < index; i++) {
        merged_array[array_size + i] = file_value[i];
    }

    //merged_array[] with array[] and file_value[] elements
    printf("Before sorting array is:\n");
    for (int i = 0; i < total_size; i++) {
        printf("%#08X\t", merged_array[i]);
    }

    printf("\n");

    //for sorting the array
    sort(total_size, merged_array);

    //copy the values into sorted_array;
    for (int i = 0; i < total_size; i++) {
        sorted_array[i] = merged_array[i];
    }

    // sorted_array[] after sorting
    printf("After sorting array is:\n");
    for (int i = 0; i < total_size; i++) {
        printf("%#08X\t", sorted_array[i]);
    }

    printf("\n");

     // array after sorting in decimal
    printf("After sorting array in decimal:\n");
    for (int i = 0; i < total_size; i++) {
        printf("%d\t", sorted_array[i]);
    }

/*Question2: Use O/p of Q1 and Mirror the number, do same for all the numbers and print
for eg: if the number is 0x19F4530 mirror of the number is 0x0354F91.
*/
    printf("\n");

    mirror(mirror_array, sorted_array, total_size);

    printf("\n");


    return 0;
}


/* Out put to be printed here */

/*Before sorting array is:
0X6BAF1000      0X19F45200      0X71802300      0X82424000      0X35601000      0X79F45000     
0X89802300      0X71421400      0X67601000      0XFE139012
After sorting array is:
0X82424000      0X89802300      0XFE139012      0X19F45200      0X35601000      0X67601000     
0X6BAF1000      0X71421400      0X71802300      0X79F45000
After sorting array in decimal:
-2109587456     -1988091136     -32272366       435442176       895488000       1734348800    
 1806635008      1900155904      1904222976      2046054400
The mirror value is:
00042428        00320898        210931EF        00254F91        00010653        00010676       
0001FAB6        00412417        00320817        00054F97*/