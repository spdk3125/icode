import java.util.Scanner;

public class PalindromeChecker {
	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);
		System.out.print("Enter srting: ");
		String input = scanner.nextLine();
		scanner.close();

		if (isPalindrome(input)) {
         		System.out.println("Yes, \"" + input + "\" is a palindrome!");
        	} else {
           		System.out.println("No, \"" + input + "\" is not a palindrome.");
        	}
	}

	private static boolean isPalindrome(String str) {
		str = str.toLowerCase().replaceAll("[^a-zA-Z0-9]", "");
		int left = 0;
		int right = str.length() - 1;

		while (left < right) {
			if (str.charAt(left) != str.charAt(right)) {
				return false;
			}
			left++;
			right--;
		}
		return true;
	}
}
