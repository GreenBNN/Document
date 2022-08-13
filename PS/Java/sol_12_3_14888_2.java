import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;
import java.util.*;
public class sol_12_3_14888_2 {
	static int MAX = Integer.MIN_VALUE; // �ִ밪 
	static int MIN = Integer.MAX_VALUE; // �ּҰ� 
	static String[] operators; // ������ �迭 
	static boolean[] visited; // ������ ��� ���� üũ 
	static int[] numbers; // ����� ���� �迭 
	static int N; // ���� ���� 
	public static void main(String[] args) throws IOException { 
		BufferedReader bf = new BufferedReader(new InputStreamReader(System.in)); 
		StringTokenizer st; 
		N = Integer.parseInt(bf.readLine()); 
		numbers = new int[N]; 
		operators = new String[N-1]; 
		visited = new boolean[N]; /* numbers �ޱ� */ 
		st = new StringTokenizer(bf.readLine()); 
		for (int i = 0; i < N; i++) { 
			numbers[i] = Integer.parseInt(st.nextToken()); 
			} 
		/* operators �ޱ� */ 
		int index = 0; 
		String oper = "+-*/"; 
		st = new StringTokenizer(bf.readLine()); 
		for (int i = 0; i < 4; i++) { 
			int n = Integer.parseInt(st.nextToken()); 
			for(int j = 0; j<n;j++) {
				operators[index++] = oper.substring(i, i+1);
			}
		} 
		dfs(numbers[0], 1); 
		System.out.println(MAX); 
		System.out.println(MIN); 
	} 
	static void dfs( int sum, int depth) {
		/* ���� ���� */ 
		if (depth == N) {
			if (MAX < sum) MAX = sum; 
			if (MIN > sum) MIN = sum; 
			return; 
		} 
		for (int i = 0; i < N - 1; i++) {
			int cur = numbers[depth]; 
			if (!visited[i]) { 
				visited[i] = true;
				int result = calc(sum, cur, operators[i]);
				dfs( result, depth + 1); 
				visited[i] = false;
			} 
		} 
	} 
	static int calc(int sum, int num, String oper) {
			switch (oper) { 
			case "+": sum += num; break; 
			case "-": sum -= num; break; 
			case "*": sum *= num; break; 
			case "/": sum /= num; break; 
			}
		return sum;
	} 
}
