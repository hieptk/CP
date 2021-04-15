// https://codeforces.com/contest/1511/problem/D
/* package whatever; // don't place package name! */

import java.util.*;
import java.lang.*;
import java.io.*;

/* Name of the class has to be "Main" only if the class is public. */
public class Main
{
	
	static boolean[][] cnt = new boolean[26][26];
	static int n, k;
	
	static void dfs(int i, StringBuilder res) {
		for (int j = 0; j < k; ++j) {
			if (cnt[i][j]) {
				cnt[i][j] = false;
				dfs(j, res);
			}
		}
		res.append((char) (i + 'a'));
	}
	
	public static void main (String[] args) throws java.lang.Exception
	{
		Scanner scanner = new Scanner(System.in);
		n = scanner.nextInt();
		k = scanner.nextInt();
		
		for (int i = 0; i < k; ++i) {
			Arrays.fill(cnt[i], true);
		}
		
		StringBuilder res = new StringBuilder();
		dfs(0, res);
		StringBuilder res2 = new StringBuilder(res);
		res.deleteCharAt(0);
		while (res2.length() < n) {
			res2.append(res);
		}
		
		System.out.println(res2.substring(0, n));
	}
}
