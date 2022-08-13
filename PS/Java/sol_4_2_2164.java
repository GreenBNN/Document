import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;
import java.util.LinkedList;
import java.util.Queue;

public class sol_4_2_2164 {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		int num = Integer.parseInt(br.readLine());
		
		Queue<Integer> queue = new LinkedList<>(); // int 형 queue 선언, linkedlist 사용
		
		for (int i = 1; i<= num;i++) {
			queue.add(i);
		}
		
		while(queue.size() != 1) {
			queue.poll();
			queue.add(queue.poll());
		}
		System.out.println(queue.poll());
	}
}