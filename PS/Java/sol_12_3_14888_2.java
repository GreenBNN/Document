import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;
import java.util.*;
public class sol_12_3_14888_2 {
	static int MAX = Integer.MIN_VALUE; // 최대값 
	static int MIN = Integer.MAX_VALUE; // 최소값 
	static String[] operators; // 연산자 배열 
	static boolean[] visited; // 연산자 사용 여부 체크 
	static int[] numbers; // 계산할 숫자 배열 
	static int N; // 숫자 개수 
	public static void main(String[] args) throws IOException { 
		BufferedReader bf = new BufferedReader(new InputStreamReader(System.in)); 
		StringTokenizer st; 
		N = Integer.parseInt(bf.readLine()); 
		numbers = new int[N]; 
		operators = new String[N-1]; 
		visited = new boolean[N]; /* numbers 받기 */ 
		st = new StringTokenizer(bf.readLine()); 
		for (int i = 0; i < N; i++) { 
			numbers[i] = Integer.parseInt(st.nextToken()); 
			} 
		/* operators 받기 */ 
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
		/* 종료 조건 */ 
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
