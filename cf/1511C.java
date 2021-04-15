// https://codeforces.com/contest/1511/problem/C
/* package whatever; // don't place package name! */

import java.util.*;
import java.lang.*;
import java.io.*;

/* Name of the class has to be "Main" only if the class is public. */
public class Main
{
	static Scanner scanner;
	static int[] first = new int[51];
	
	public static void main (String[] args) throws java.lang.Exception
	{
		scanner = new Scanner(System.in);
		int n = scanner.nextInt();
		int m = scanner.nextInt();
		
		for (int i = 1; i <= n; ++i) {
			int c = scanner.nextInt();
			if (first[c] == 0) {
				first[c] = i;
			}
		}
		
		for (int i = 1; i <= m; ++i) {
			int c = scanner.nextInt();
			int res = first[c];
			System.out.print(res + " ");
			for (int j = 1; j < first.length; ++j) {
				if (j == c) {
					first[c] = 1;
				} else if (first[j] > 0 && first[j] < res) {
					first[j]++;
				}
			}
		}
	}
}
