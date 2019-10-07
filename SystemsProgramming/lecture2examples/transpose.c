#include <stdio.h>
         
int main() {
  int m[5][4] = { {1,  1,   1,   1},
                  {2,  4,   8,  16},
                  {3,  9,  27,  81},
                  {4, 16,  64, 256},
                  {5, 25, 125, 625} };
  int ans[4][5];
  for (int row = 0; row < 5; row++)
    for (int col = 0; col < 4; col++)
      ans[col][row] = m[row][col];
  
  for (int r = 0; r < 4; r++)
    for (int c = 0; c < 5; c++)
      printf("%3d%c", ans[r][c],
          c == 4 ? '\n' : ' ');
}