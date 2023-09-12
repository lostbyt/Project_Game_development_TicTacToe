#include <iostream>
#include <vector>

//ASCII values('x'=120  'o'= 111  '.'=46)


bool availablePositionChecker(char grid[3][3], int row, int column) {

   if (int(grid[row][column]) != 111 && int(grid[row][column]) != 120)
      return true;
   else
      return false;
}

std::vector<int> positionChoiceP1(char grid[3][3]){
   
   bool valid = false;
   bool available = false;
   std::vector<int> positionPlayer = {1};
   int row;
   int column;

   
   while (valid == false) {
      do {
         std::cout << ":::Player one turn:::" << "\n";
         std::cout << ":::::::::::::::::::::" << "\n";
         
         std::cout << "\n" << "Enter your row position: ";
         std::cin >> row;
         std::cout << "Enter your column position: ";
         std::cin >> column;
         if (row >= 0 && row <= 2 && column >= 0 && column <= 2) {
            valid = true;
            available = availablePositionChecker(grid, row, column);
         } else {
            std::cout << "This position is not valid, try again" << "\n";
         }
      } while (available == false);
   }

   positionPlayer.push_back(row);
   positionPlayer.push_back(column);
   return positionPlayer;
}

std::vector<int> positionChoiceP2(char grid[3][3]){
   
   bool valid = false;
   bool available = false;
   std::vector<int> positionPlayer = {2};
   int row;
   int column;

   while (valid == false) {
      do {
         std::cout << ":::Player two turn:::" << "\n";
         std::cout << ":::::::::::::::::::::" << "\n";
         
         std::cout << "\n" << "Enter your row position: ";
         std::cin >> row;
         std::cout << "Enter your column position: ";
         std::cin >> column;
         if (row >= 0 && row <= 2 && column >= 0 && column <= 2) {
            valid = true;
            available = availablePositionChecker(grid, row, column);
         } else {
            std::cout << "This position is not valid, try again" << "\n";
         }
      } while (available == false);
   }
   positionPlayer.push_back(row);
   positionPlayer.push_back(column);
   return positionPlayer;
}

void displayGrid(char grid[3][3]){
   std::cout << "\n --------- " << "\n";
   for(int j= 0; j<3; j++){
      if(j!= 0){
         std::cout << "\n";
      }
      for(int i= 0; i<3; i++){
         if (i == 0) {
            std::cout << "| " << grid[j][i] << " ";
         }else if (i == 2) {
            std::cout << " " << grid[j][i] << " |";
         } else {
            std::cout << " " << grid[j][i] << " ";
         }
      }
   }
   std::cout << "\n --------- " << "\n";
   std::cout << "\n";
}

bool rowsChecker(char grid[3][3]) {
   bool win = false;
   int accumulatorASCII = 0;

   for(int j= 0; j< 3; j++) {
      for(int i= 0; i< 3; i++) {
         accumulatorASCII += (int)grid[j][i];
         //std::cout << "accumulator is " << accumulatorASCII << "\n";
      }
      if((accumulatorASCII/3) == 120 || (accumulatorASCII/3) == 111)
         win = true;
      accumulatorASCII = 0;
   }
   return win;
}

bool columnsChecker(char grid[3][3]) {
   bool win = false;
   int accumulatorASCII = 0;

   for(int j= 0; j< 3; j++) {
      for(int i= 0; i< 3; i++) {
         accumulatorASCII += (int)grid[i][j];
         //std::cout << "accumulator is " << accumulatorASCII << "\n";
      }
      if((accumulatorASCII/3) == 120 || (accumulatorASCII/3) == 111)
         win = true;
      accumulatorASCII = 0;
   }
   return win;
}

bool diagonalsChecker(char grid[3][3]) {
   bool win = false;
   int accumulatorASCII = 0;
   
   accumulatorASCII = (int)grid[0][0] + (int)grid[1][1] + (int)grid[2][2] ;
   if((accumulatorASCII/3) == 120 || (accumulatorASCII/3) == 111)
      win = true;
   accumulatorASCII = (int)grid[0][2] + (int)grid[1][1] + (int)grid[2][0] ;
   if((accumulatorASCII/3) == 120 || (accumulatorASCII/3) == 111)
      win = true;
   
   return win;
}

bool updateGrid(char grid[3][3], std::vector<int> positions){
   bool win = false;
   std::vector<int> checker;
   int accumulatorASCII = 0;
   int player = positions[0];
   int row = positions[1];
   int col = positions[2];

   if (player == 1)
      grid[row][col] = 'x';
   else
      grid[row][col] = 'o';

   
   win = rowsChecker(grid);
   if (!win)
      win = columnsChecker(grid);
      if (!win)
         win = diagonalsChecker(grid);
   
   displayGrid(grid);
   return win;
}

int main(){

   //Grid declaration
   char grid[3][3]= {{'.', '.', '.'}, {'.', '.', '.'}, {'.', '.', '.'}};
   bool isWinP1 = false;
   bool isWinP2 = false;
   std::vector<int> rowColP1;
   std::vector<int> rowColP2;
   

   while(true){
      rowColP1 = positionChoiceP1(grid);
      isWinP1 = updateGrid(grid, rowColP1);
      if (isWinP1) {
         std::cout <<  "Player1 Won!";
         break;
      }
      
      rowColP2 = positionChoiceP2(grid);
      isWinP2 = updateGrid(grid, rowColP2);
      if (isWinP2) {
         std::cout <<  "Player2 Won!";
         break;
      }
   }
}



