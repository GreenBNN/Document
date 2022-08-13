import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;
import java.util.*;

public class sol_15_1_15903 {
	static int N, M;
	static long a;
	static long answer;
	public static void main(String[] args) throws IOException {
		
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		PriorityQueue<Long> pq = new PriorityQueue<Long>();
		
		StringTokenizer st = new StringTokenizer(br.readLine(), " ");
		N = Integer.parseInt(st.nextToken()); // 숫자 개수
		M = Integer.parseInt(st.nextToken()); // 합체 수
		
		st = new StringTokenizer(br.readLine(), " ");
		for( int i = 0; i< N; i++) {
			pq.add(Long.parseLong(st.nextToken()));
		}
		
		for(int i =0 ; i<M;i++) {
			a = pq.poll();
			a += pq.poll();
			pq.add(a);
			pq.add(a);
		}
		answer = 0;
		while(!pq.isEmpty()) {
			answer += pq.poll();
		}
		System.out.println(answer);
	}
}