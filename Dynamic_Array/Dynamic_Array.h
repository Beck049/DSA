#include <iostream>

typedef struct darr_s {
    int* data;
    int len;
}darr_t;
typedef darr_t *darr;

class DarrContainer {
public:
    darr_s darrInfo;

    // Constructor to initialize the struct's values
    DarrContainer(int* dataArray, int length) {
        darrInfo.data = dataArray;
        darrInfo.len = length;
    }

    // Method to return the value of len
    int length() {
        return darrInfo.len;
    }

    // Method to return value by index
    int retrieve(int index){
        return darrInfo.data[index];
    }

    // Method to update the value by index
    DarrContainer update(int value, int index){
        if(index >= darrInfo.len || index < 0){ return *this; }
        darrInfo.data[index] = value;
        return *this;
    }

    // Method to append another dynamic array
    DarrContainer append(DarrContainer Darr){
        int len = Darr.length();
        if(len == 0){ return *this; }
        len += darrInfo.len;
        darrInfo.data = (int*)realloc(darrInfo.data, sizeof(int)*len);
        memcpy(darrInfo.data+darrInfo.len, Darr.darrInfo.data, sizeof(int)*Darr.length());
        darrInfo.len = len;

        return *this;
    }

    // Method to add an element by index
    DarrContainer add(int value, int index){
        darrInfo.len++;
        darrInfo.data = (int*)realloc(darrInfo.data, sizeof(int)*darrInfo.len);
        for(int i = darrInfo.len-1; i >= 0; i--){
            if(i == index){
                darrInfo.data[i] = value;
                break;
            } else {
                darrInfo.data[i] = darrInfo.data[i-1];
            }
        }

        return *this;
    }

    // Method to delete an element by index
    DarrContainer del(int index){
        if(index >= darrInfo.len){ return *this; }
        darrInfo.len--;
        for(int i = index; i < darrInfo.len; i++){
            darrInfo.data[i] = darrInfo.data[i+1];
        }
        darrInfo.data = (int*)realloc(darrInfo.data, sizeof(int)*darrInfo.len);
    
        return *this;
    }

    // print the array
    void print(){
        printf("len:%d\n", darrInfo.len);

        if(darrInfo.len == 0){
            printf("The array is empty\n");
        }

        int* arr = darrInfo.data;
        for(int i = 0; i < darrInfo.len; i++){
            printf("|%3d", arr[i]);
        }
        printf("|\n");
    }
};