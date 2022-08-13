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
		
		N = Integer.parseInt(br.readLine()); // ��ü ���
		
		StringTokenizer st = new StringTokenizer(br.readLine(), " ");
		a = Integer.parseInt(st.nextToken()); // ù ��° ���
		b = Integer.parseInt(st.nextToken()); // �� ��° ���
		
		int M = Integer.parseInt(br.readLine()); // �̼� ����
		arr = new int[101][101];
		visited = new int[101]; // �湮����
		for(int i = 0 ; i< M; i++) {
			st = new StringTokenizer(br.readLine(), " ");
			int parent = Integer.parseInt(st.nextToken()); // �θ�
			int child = Integer.parseInt(st.nextToken()); // �ڽ�
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