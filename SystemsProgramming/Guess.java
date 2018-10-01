import java.util.Random; import java.util.Scanner;
public class Guess {
  public static void main(String[] args) {
    Scanner scan = new Scanner(System.in);
    Random random = new Random();
    int randomNumber = random.nextInt(10 + 1);
    int guessedNumber = 0;
 
    do {
      System.out.print("Guess what the number is: ");
      guessedNumber = scan.nextInt();
      if (guessedNumber > randomNumber)
        System.out.println("Your guess is too high!");
      else if (guessedNumber < randomNumber)
        System.out.println("Your guess is too low!");
      else
        System.out.println("You got it!");
    } while (guessedNumber != randomNumber);
  }
}