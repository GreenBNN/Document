import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;
import java.util.StringTokenizer; // 문자열 나누기

import java.util.LinkedList;

public class sol_4_2_1021 {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		LinkedList<Integer> deque = new LinkedList<Integer>();
		
		int cnt = 0; // 2, 3번 연산 개수
		
		StringTokenizer st = new StringTokenizer(br.readLine(), " ");
		
		int N = Integer.parseInt(st.nextToken()); // 총 개수
		int M = Integer.parseInt(st.nextToken()); // 뽑는 숫자 개수
		
		for(int i =1 ; i<=N; i++) {
			deque.offer(i);
		}
		
		int[] seq = new int[M]; // 뽑으려고 하는 숫자 배열
		
		st = new StringTokenizer(br.readLine(), " ");
		for(int i= 0 ;i<M;i++) {
			seq[i] = Integer.parseInt(st.nextToken());
		}
		
		for(int i =0 ;i<M; i++ ) { 
			int target_idx = deque.indexOf(seq[i]); // 뽑을 숫자의 index
			int half_idx = deque.size()/2; // 10이면 5(6), 5이면 2(3) idx(실제숫자)
			
			if(target_idx <= half_idx ) { // 중간 앞에 있으면 2번 실행
				for(int j  =0; j<target_idx;j++) {
					int temp = deque.pollFirst();
					deque.offerLast(temp);
					cnt++;
				}
				
			}
			else { // 중간 뒤에 있으면 3번 실행
				for(int j =0;j<deque.size() - target_idx;j++) {
					int temp = deque.pollLast();
					deque.offerFirst(temp);
					cnt++;
				}
			}
			deque.pollFirst(); // 연산이 끝난 후 1번 실행
		}
		System.out.println(cnt);
	}
}