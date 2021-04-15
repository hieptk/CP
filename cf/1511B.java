// https://codeforces.com/contest/1511/problem/B
/* package whatever; // don't place package name! */

import java.util.*;
import java.lang.*;
import java.io.*;

/* Name of the class has to be "Main" only if the class is public. */
public class Main
{
	static Scanner scanner;
	
	static void solve() {
		int a, b, c;
		a = scanner.nextInt();
		b = scanner.nextInt();
		c = scanner.nextInt();
		
		int g = 1;
		for (int i = 2; i <= c; ++i) {
			g = g * 10;
		}
		
		int x = g;
		for (int i = c + 1; i <= a; ++i) {
			x = x * 10;
		}
		
		int y = g;
		for (int i = c + 1; i <= b; ++i) {
			y = y * 10;
		}
		
		if (x <= y) {
			y += g;
		} else {
			x += g;
		}
		
		System.out.println(x + " " + y);
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
