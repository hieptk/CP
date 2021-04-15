// https://codeforces.com/contest/1511/problem/A
/* package whatever; // don't place package name! */

import java.util.*;
import java.lang.*;
import java.io.*;

/* Name of the class has to be "Main" only if the class is public. */
public class Main
{
	static Scanner scanner;
	
	static void solve() {
		int n = scanner.nextInt();
		int res = 0;
		for (int i = 0; i < n; ++i) {
			int type = scanner.nextInt();
			if (type != 2) {
				res++;
			}
		}
		System.out.println(res);
	}
	
	public static void main (String[] args) throws java.lang.Exception
	{
		scanner = new Scanner(System.in);
		int t = scanner.nextInt();
		for (int i = 1; i <= t; ++i) {
			solve();
		}
	}
}
