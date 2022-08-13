import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;
import java.util.Arrays;
import java.util.StringTokenizer;

public class sol_12_1_2644 {
	static int N, a, b;
	static int[][] arr;
	static int[] visited;
	
	static int answer;
	static boolean find;
	public static void main(String[] args) throws IOException {
		
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		N = Integer.parseInt(br.readLine()); // 전체 사람
		
		StringTokenizer st = new StringTokenizer(br.readLine(), " ");
		a = Integer.parseInt(st.nextToken()); // 첫 번째 사람
		b = Integer.parseInt(st.nextToken()); // 두 번째 사람
		
		int M = Integer.parseInt(br.readLine()); // 촌수 개수
		arr = new int[101][101];
		visited = new int[101]; // 방문여부
		for(int i = 0 ; i< M; i++) {
			st = new StringTokenizer(br.readLine(), " ");
			int parent = Integer.parseInt(st.nextToken()); // 부모
			int child = Integer.parseInt(st.nextToken()); // 자식
			arr[parent][child] = 1;
			arr[child][parent] = 1;
		}
		
		

        DFS(a, b, 0);
		
		if(!find) answer = -1;
		System.out.println(answer);
		
	}
	
	public static void DFS(int a, int b, int cnt) {
		visited[a] = 1; 
		
		if(a == b) {
			find = true;
			answer = cnt;
			return;
		}
		
		for (int i = 1; i < N+1; i++) {
			if(visited[i]==0 && arr[a][i] == 1) {
				visited[i] = 1;
				DFS(i, b, cnt+1);
				visited[i] = 0;
			}
		}
		
	}
}