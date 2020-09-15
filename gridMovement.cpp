#include <iostream>

using namespace std;

void clear(){
    for(int i = 0; i < 75; i++){
        cout << "\n";
    }
}

void printGrid(string array[10][10]){
    for(int i = 0; i < 10; i++){
        for(int j = 0; j < 10; j++){
            cout << array[i][j];
        }
        cout << "\n";
    }
}

void findPlayer(string array[10][10], int pos[2]){
    for(int i = 0; i < 10; i++){
        for(int j = 0; j < 10; j++){
            if(array[i][j] == " o "){
                pos[0] = i;
                pos[1] = j;
            }
        }
    }
}

void movePlayer(string array[10][10], int pos[2]){
    findPlayer(array, pos);
    string direction;
    cout << "Enter a direction: [up, down, left, right] > ";
    cin >> direction;
    if(direction == "w" || direction == "a" || direction == "s" || direction == "d"){
        if(direction == "w"){
            if(pos[0] != 0){
                array[pos[0] - 1][pos[1]] = " o ";
            }
            else{
                clear();
                printGrid(array);
                movePlayer(array, pos);
            }
        }
        if(direction == "s"){
            if(pos[0] != 9){
                array[pos[0] + 1][pos[1]] = " o ";
            }
            else{
                clear();
                printGrid(array);
                movePlayer(array, pos);
            }
        }
        if(direction == "a"){
            if(pos[1] != 0){
                array[pos[0]][pos[1] - 1] = " o ";
            }
            else{
                clear();
                printGrid(array);
                movePlayer(array, pos);
            }
        }
        if(direction == "d"){
            if(pos[1] != 9){
                array[pos[0]][pos[1] + 1] = " o ";
            }
            else{
                clear();
                printGrid(array);
                movePlayer(array, pos);
            }
        }
        array[pos[0]][pos[1]] = " - ";
    }
}

int main(){
  int position[2] = {0,0};
  string grid[10][10] = {
      {" o "," - "," - "," - "," - "," - "," - "," - "," - "," - "},
      {" - "," - "," - "," - "," - "," - "," - "," - "," - "," - "},
      {" - "," - "," - "," - "," - "," - "," - "," - "," - "," - "},
      {" - "," - "," - "," - "," - "," - "," - "," - "," - "," - "},
      {" - "," - "," - "," - "," - "," - "," - "," - "," - "," - "},
      {" - "," - "," - "," - "," - "," - "," - "," - "," - "," - "},
      {" - "," - "," - "," - "," - "," - "," - "," - "," - "," - "},
      {" - "," - "," - "," - "," - "," - "," - "," - "," - "," - "},
      {" - "," - "," - "," - "," - "," - "," - "," - "," - "," - "},
      {" - "," - "," - "," - "," - "," - "," - "," - "," - "," - "}
      };
  bool run = true;

  while(run){
      clear();
      printGrid(grid);
      movePlayer(grid, position);
  }
}