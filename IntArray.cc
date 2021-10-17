#include <iostream>
#include <string>
#include <sstream>
using namespace std;

struct IntArray {
  int size;                     //number of elements the array currently holds.
  int capacity;                 //number of elements the array could hold.
  int *contents;                //the array.
};

//Initializes the integer array
IntArray Initializer() {
        IntArray arr;
        arr.size = 0;
        arr.capacity = 0;
        arr.contents = nullptr;
        return ia;
}

//Allocates memory to a the new integer array
void my_malloc(IntArray& arr, int n) {
        arr.capacity = n;
        arr.contents = new int[arr.capacity];
}

//Reallocates, as more memory is needed
void my_realloc(Array& arr, int n) {
        arr.capacity = n * arr.capacity;
        int *new_Array = new int[arr.capacity];
        int j = 0;
        while (j < ia.size) {
                new_Array[j] = arr.contents[j];
                j++;
        }
        int *old_Array = arr.contents;
        arr.contents = new_Array;
        delete[] old_Array;
}

//MAIN
void main(int argc, char *argv[]) {
        IntArray ia = Initializer();
        if (ia.capacity == 0) {
                istringstream ss0(argv[1]);
                int x = 0;
                ss0 >> x;
                my_malloc(ia, x);
        } else if (ia.capacity == ia.size) {
                istringstream ss1(argv[2]);
                int y = 0;
                ss1 >> y;
                my_realloc(ia, y);
        }
}

//NOTE: Executing this program would cause a memory leak and this is only developed for cross referencing
