import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;
import java.util.StringTokenizer; // ���ڿ� ������

import java.util.LinkedList;

public class sol_4_2_1021 {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		LinkedList<Integer> deque = new LinkedList<Integer>();
		
		int cnt = 0; // 2, 3�� ���� ����
		
		StringTokenizer st = new StringTokenizer(br.readLine(), " ");
		
		int N = Integer.parseInt(st.nextToken()); // �� ����
		int M = Integer.parseInt(st.nextToken()); // �̴� ���� ����
		
		for(int i =1 ; i<=N; i++) {
			deque.offer(i);
		}
		
		int[] seq = new int[M]; // �������� �ϴ� ���� �迭
		
		st = new StringTokenizer(br.readLine(), " ");
		for(int i= 0 ;i<M;i++) {
			seq[i] = Integer.parseInt(st.nextToken());
		}
		
		for(int i =0 ;i<M; i++ ) { 
			int target_idx = deque.indexOf(seq[i]); // ���� ������ index
			int half_idx = deque.size()/2; // 10�̸� 5(6), 5�̸� 2(3) idx(��������)
			
			if(target_idx <= half_idx ) { // �߰� �տ� ������ 2�� ����
				for(int j  =0; j<target_idx;j++) {
					int temp = deque.pollFirst();
					deque.offerLast(temp);
					cnt++;
				}
				
			}
			else { // �߰� �ڿ� ������ 3�� ����
				for(int j =0;j<deque.size() - target_idx;j++) {
					int temp = deque.pollLast();
					deque.offerFirst(temp);
					cnt++;
				}
			}
			deque.pollFirst(); // ������ ���� �� 1�� ����
		}
		System.out.println(cnt);
	}
}