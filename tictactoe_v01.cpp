
#include <iostream>
#include <vector>


/*
TO DO:
- Check if position free before to mark the grid
- Victory message to the right player
- redondance
*/



std::vector<int> positionChoiceP1(){

   std::vector<int> positionPlayer = {1};
   int row;
   int column;

   std::cout << ":::Player one turn:::" << "\n";

   while(row < 0 || row >2){
      std::cout << "\n" << "Enter your row position: ";
      std::cin >> row;
   }
   
   while(column < 0 || column > 2){
      std::cout << "Enter your column position: ";
      std::cin >> column;
   }

   positionPlayer.push_back(row);
   positionPlayer.push_back(column);
   return positionPlayer;
}

std::vector<int> positionChoiceP2(){

   std::vector<int> positionPlayer = {2};
   int row;
   int column;

   std::cout << ":::Player two turn:::" << "\n";

   while(row < 0 || row >2){
      std::cout << "\n" << "Enter your row position: ";
      std::cin >> row;
   }
   
   while(column < 0 || column > 2){
      std::cout << "Enter your column position: ";
      std::cin >> column;
   }

   positionPlayer.push_back(row);
   positionPlayer.push_back(column);
   return positionPlayer;
}

void displayGrid(char grid[3][3]){
   for(int j= 0; j<3; j++){
         if(j!= 0){
            std::cout << "\n";
         }
         for(int i= 0; i<3; i++){
            std::cout << grid[j][i] << " ";
         }
      }
      std::cout << "\n";
      std::cout << "\n";
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

   //ASCII values('x'=120  'o'= 111  .'=46)

   

   //Checking 3 ROWS
   for(int j= 0; j< 3; j++) {
      for(int i= 0; i< 3; i++) {
         accumulatorASCII += (int)grid[j][i];
         //std::cout << "accumulator is " << accumulatorASCII << "\n";
      }
      if((accumulatorASCII/3) == 120 || (accumulatorASCII/3) == 111)
         win = true;
      accumulatorASCII = 0;
   }
   
   //Checking 3 COLUMNS
   for(int j= 0; j< 3; j++) {
      for(int i= 0; i< 3; i++) {
         accumulatorASCII += (int)grid[i][j];
         //std::cout << "accumulator is " << accumulatorASCII << "\n";
      }
      if((accumulatorASCII/3) == 120 || (accumulatorASCII/3) == 111)
         win = true;
      accumulatorASCII = 0;
   }
   
   //Checking DIAGONALS 1
   accumulatorASCII = (int)grid[0][0] + (int)grid[1][1] + (int)grid[2][2] ;
   if((accumulatorASCII/3) == 120 || (accumulatorASCII/3) == 111)
      win = true;
   accumulatorASCII = (int)grid[0][2] + (int)grid[1][1] + (int)grid[2][0] ;
   if((accumulatorASCII/3) == 120 || (accumulatorASCII/3) == 111)
      win = true;


   displayGrid(grid);
   return win;
}


int main(){

   //Grid declaration
   char grid[3][3]= {{'.', '.', '.'}, {'.', '.', '.'}, {'.', '.', '.'}};
   bool isWin = false;
   std::vector<int> rowColP1;
   std::vector<int> rowColP2;
   

   while(true){
      rowColP1 = positionChoiceP1();
      isWin = updateGrid(grid, rowColP1);
      if (isWin)
         break;
      rowColP2 = positionChoiceP2();
      isWin = updateGrid(grid, rowColP2);
      if (isWin)
         break;
   }
   

   std::cout << "\n" << "Win";

}



