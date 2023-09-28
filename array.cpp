#include "array.h"

array::array(int s){
    if (s){
        size = s;
        nums.reserve(size);
        for (int i = 1; i <= size; i++){
            nums.push_back(i);
        }
        std::random_shuffle(nums.begin(), nums.end());
        sleeptime = 1000/(s^2);
    }

    CONSOLE_CURSOR_INFO cursor;
    cursor.dwSize = 0;
    cursor.bVisible = false;
    SetConsoleCursorInfo(console, & cursor);
}

void array::setxy(int x, int y){
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(console, coord);
}

void array::print(){
    setxy(0,0);
    for (int i = 0; i < size; i++){
        for (int j = 0; j < nums[i]; j++){
            setxy(10+2*i, 10+size-j);
            std::cout<<"O";
        }
    }
    Sleep(sleeptime);
    system("cls");
}

void array::swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
    print();
}

void array::sort(){
    system("cls");
    setxy(5,4); std::cout<<"1. Bubble sort";
    setxy(5,5); std::cout<<"2. Selection sort";
    setxy(5,6); std::cout<<"3. Insertion sort";
    setxy(5,7); std::cout<<"Choose algorithm: ";
    char ch = getch();
    switch (ch){
        case '1': bubbleSort();
        case '2': selectionSort();
        case '3': insertionSort();
    }

    setxy(0,0); std::cout<<"Press any key to continue";
    getch();
}

void array::bubbleSort(){
  // loop to access each array element
  for (int step = 0; step < size - 1; step++){
      
    // loop to compare array elements
    for (int i = 0; i < size - step - 1; i++){
      // compare two adjacent elements
      // change > to < to sort in descending order
      if (nums[i] > nums[i + 1]) {

        // swapping elements if elements
        // are not in the intended order
        swap(&nums[i], &nums[i+1]);
      }
    }
  }
}

void array::selectionSort(){
  for (int step = 0; step < size - 1; step++) {
    int min_idx = step;
    for (int i = step + 1; i < size; i++) {

      // To sort in descending order, change > to < in this line.
      // Select the minimum element in each loop.
      if (nums[i] < nums[min_idx])
        min_idx = i;
    }

    // put min at the correct position
    swap(&nums[min_idx], &nums[step]);
  }
}

void array::insertionSort() {
    for (int step = 0; step < size-1; step++) {
        int key = nums[step];
        int j = step - 1;

        // Compare key with each element on the left of it until an element smaller than
        // it is found.
        // For descending order, change key<array[j] to key>array[j].
        while (key < nums[j] && j >= 0) {
            nums[j + 1] = nums[j];
            j--;
            print();
        }
    nums[j + 1] = key;
    print();
    }
}
