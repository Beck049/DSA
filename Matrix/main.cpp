#include "../Dynamic_Array/Dynamic_Array.h"

class MatrixContainer : public DarrContainer{
public:

    int size[2]; // row, col

    MatrixContainer(int* dataArray, int row, int col):DarrContainer(dataArray, row*col){
        //darrInfo.data = dataArray;
        //darrInfo.len = row*col;
        size[0] = row;
        size[1] = col;
    }

    MatrixContainer sum(MatrixContainer matrix2){
        if(size[0] != matrix2.size[0] || size[1] != matrix2.size[1] ){
            printf("Error: Matrix Size are different!\n");
            return *this;
        }
        for(int i = 0; i < darrInfo.len; i++){
            darrInfo.data[i] += matrix2.darrInfo.data[i];
        }
        return *this;
    }

    MatrixContainer scalarMul(int scalar){
        for(int i = 0; i < darrInfo.len; i++){
            darrInfo.data[i] *= scalar;
        }
        return *this;
    }

    int rxc(MatrixContainer matrix2, int row, int col){
        int ret = 0;
        for(int i = 0; i < size[1]; i++){
            ret += darrInfo.data[row*size[0]+i] * matrix2.darrInfo.data[i*size[0]+col];
        }
        return ret;
    }

    MatrixContainer mul(MatrixContainer matrix2){
        if(size[1] != matrix2.size[0]){
            printf("Error: Matrix Size are unavailable to multiply\n");
            return *this;
        }
        int* newMatrixData = (int*)calloc(darrInfo.len, sizeof(int));
        for(int i = 0; i < darrInfo.len; i++){
            newMatrixData[i] = rxc(matrix2, i/size[0], i%size[1]);
        }
        free(darrInfo.data);
        darrInfo.data = newMatrixData;
        darrInfo.len = size[0]*size[0];
        size[1] = size[0];
        return *this;
    }

    void print(){
        printf("%2d (%2d, %2d)\n", darrInfo.len, size[0], size[1]);
        printf("| ");
        for(int i = 0; i < darrInfo.len; i++){
            printf("%3d", darrInfo.data[i]);
            if((i+1)%size[0] != 0){
                printf(", ");
            } else {
                if(i == darrInfo.len-1){
                    printf("|\n");
                    return;
                }
                printf("|\n| ");
            }
        }
        return;
    }
};

int* createArray(int* dataArray, int arrLen){
    int* newArr = (int*)malloc(sizeof(int)*arrLen);
    memcpy(newArr, dataArray, sizeof(int)*arrLen);
    return newArr;
}

MatrixContainer copyMatrix(MatrixContainer matrix){
    MatrixContainer newMatrix(createArray(matrix.darrInfo.data, matrix.darrInfo.len), matrix.size[0], matrix.size[1]);
    return newMatrix;
}

int main(){
    // create two matrix
    int dataArray[]  = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int dataArray2[] = {1, 0, 1, 1, 1, 0, 0, 1, 1};
    int* arr_d1 = createArray(dataArray, 9);
    int* arr_d2 = createArray(dataArray2, 9);

    MatrixContainer container1(arr_d1, 3, 3);
    MatrixContainer container2(arr_d2, 3, 3);

    container1.print();
    container2.print();

    // copy 1st matrix
    printf("copy mat1:\n");
    MatrixContainer cpymat = copyMatrix(container1);
    cpymat.print();

    // sum two matrix
    printf("sum:\n");
    container1.sum(container2).print();

    // mul two matrix
    printf("mul:\n");
    cpymat.mul(container2).print();

    // scalar 2nd matrix with 3
    printf("scalar mul: \n");
    container2.scalarMul(3).print();

    return 0;
}