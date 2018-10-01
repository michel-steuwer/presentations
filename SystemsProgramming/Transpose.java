import java.util.Arrays;
public class Transpose {
  public static void main(String[] args){
    int[][] m = { {1,  1,   1,   1},
                  {2,  4,   8,  16},
                  {3,  9,  27,  81},
                  {4, 16,  64, 256},
                  {5, 25, 125, 625} };
    int[][] ans = new int[4][5];
    for(int rows = 0; rows < m.length; rows++)
      for(int cols = 0; cols < m[0].length; cols++)
        ans[cols][rows] = m[rows][cols];

    for(int[] row : ans) {
      for (int x : row)
        System.out.printf("%3d ", x);
      System.out.println();
    }
  }
}