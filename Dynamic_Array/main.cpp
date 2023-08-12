#include "Dynamic_Array.h"

int* createArray(int* dataArray, int arrLen){
    int* newArr = (int*)malloc(sizeof(int)*arrLen);
    memcpy(newArr, dataArray, sizeof(int)*arrLen);
    return newArr;
}

int main() {
    int dataArray[] = {1, 2, 3, 4, 5};
    int dataArray2[]= {6, 7, 8, 9, 10};
    int arrayLength = sizeof(dataArray) / sizeof(dataArray[0]);
    int arrayLength2 = sizeof(dataArray2) / sizeof(dataArray2[0]);
    int* arr_d1 = createArray(dataArray, arrayLength);
    int* arr_d2 = createArray(dataArray2, arrayLength2);

    // Create an instance of DataContainer
    DarrContainer container(arr_d1, arrayLength);

    DarrContainer container2(arr_d2, arrayLength2);

    container.print();
    container2.print();

    printf("concat:\n");
    container.append(container2).print();
    
    printf("add 99 to index 3 :\n");
    container.add(99, 3).print();

    printf("delete element at index 6 :\n");
    container.del(6).print();

    return 0;
}
