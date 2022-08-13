import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;
import java.util.*;

public class sol_12_4_1697 {
	static int N; // 수빈
	static int K; // 동생
	static int answer ;
	
	static int visited[] = new int[100001];

	public static int bfs(int n, int k, int depth) {
		Queue<Integer> queue = new LinkedList<Integer>(); 
		queue.add(n); 
		
		visited[n] = 1; 
		while (queue.isEmpty() == false) { 
			n = queue.remove(); 
			if (n == K) { // 도달 하면 리턴
				return visited[n]-1; 
				} 
			if (n-1>=0 && visited[n-1] == 0) { //  n-1 안갔으면 방문
				visited[n-1] = visited[n]+1; 
				queue.add(n-1); 
				} 
			if (n+1 <= 100000 && visited[n+1] == 0) { // n+1 안갔으면 방문
				visited[n+1] = visited[n]+1; 
				queue.add(n+1); 
				} 
			if (2*n <= 100000 && visited[2*n] == 0) { // n*2 안갔으면 바움ㄴ
				visited[2*n] = visited[n] + 1; 
				queue.add(2*n); 
				}
			} 
		return -1;

	}
	
	public static void main(String[] args) throws IOException {
		
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		StringTokenizer st = new StringTokenizer(br.readLine(), " ");
		N = Integer.parseInt(st.nextToken()); 
		K = Integer.parseInt(st.nextToken());
		
		answer = bfs(N, K, 0);
		
		System.out.println(answer);
	}
}