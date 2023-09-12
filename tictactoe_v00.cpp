
#include <iostream>
#include <vector>

std::vector<int> positionChoice(){

   std::vector<int> positionPlayer;
   int row;
   int column;

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



bool updateGrid(char grid[3][3], std::vector<int> positions){
   bool win = false;
   std::vector<int> checker;
   int accumulatorASCII = 0;
   int row = positions[0];
   int col = positions[1];

   grid[row][col] = 'x';
   //ASCII values
   //x = 120
   //. = 46

   
   //Checking 3 ROWS
   for(int j= 0; j< 3; j++) {
      for(int i= 0; i< 3; i++) {
         accumulatorASCII += (int)grid[j][i];
         //std::cout << "accumulator is " << accumulatorASCII << "\n";
      }
      if((accumulatorASCII/3) == 120)
         win = true;
      accumulatorASCII = 0;
   }
   //Checking 3 COLUMNS
   for(int j= 0; j< 3; j++) {
      for(int i= 0; i< 3; i++) {
         accumulatorASCII += (int)grid[i][j];
         //std::cout << "accumulator is " << accumulatorASCII << "\n";
      }
      if((accumulatorASCII/3) == 120)
         win = true;
      accumulatorASCII = 0;
   }
   //Checking DIAGONALS 1
   // for(int j= 0; j< 3; j++) {
   //    for(int i= 0; i< 3; i++) {
   //       if (i == j) {
   //          accumulatorASCII += (int)grid[j][i];
   //          std::cout << "accumulator is " << accumulatorASCII << "\n";
   //       }
   //    }
   // }
   // if((accumulatorASCII/3) == 120)
   //    win = true;
   accumulatorASCII = (int)grid[0][0] + (int)grid[1][1] + (int)grid[2][2] ;
   if((accumulatorASCII/3) == 120)
      win = true;
   accumulatorASCII = (int)grid[0][2] + (int)grid[1][1] + (int)grid[2][0] ;
   if((accumulatorASCII/3) == 120)
      win = true;


   
   
   //Displaying the grid
   for(int j= 0; j<3; j++){
      if(j!= 0){
         std::cout << "\n";
      }
      for(int i= 0; i<3; i++){
         std::cout << grid[j][i] << " ";
      }
   }

   return win;
}


int main(){

   //Grid declaration
   char grid[3][3]= {{'.', '.', '.'}, {'.', '.', '.'}, {'.', '.', '.'}};
   bool isWin = false;
   std::vector<int> rowCol;
   

   do{
      rowCol = positionChoice();
      isWin = updateGrid(grid, rowCol);
   }while(!isWin);

   if(isWin)
      std::cout << "\n" << "Win";

}



