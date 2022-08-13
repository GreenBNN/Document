import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;
import java.util.Arrays;

// 입력 BufferedReader 로 출력 sysout println 많이 쓰기 X

public class sol_7_1_10989 {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		int N = Integer.parseInt(br.readLine()); // 총 개수
		int[] seq = new int[10001]; // 저장되는 배열
		
		for(int i =0 ; i<N; i++) { 
			seq[Integer.parseInt(br.readLine())]++;
			
//          insertion sorting ( O(n^2)  )
//			for(int j = i ; j>0; j--) {
//				if(seq[j-1]>seq[j]) { // swap
//					int temp = seq[j-1];
//					seq[j-1] = seq[j];
//					seq[j] = temp;
//				}
//			}
		}
		
		br.close();
		
		StringBuilder sb = new StringBuilder();
		
// 		기본 내장 array sort 사용 ( O(nlogn ~ n^2)  )
//		Arrays.sort(seq);
//		
		
// 		Counting sort ( O(N + M) )
		for(int i = 1; i<10001;i++) {
			while(seq[i] > 0) {
				sb.append(i).append('\n');
				seq[i]--;
			}
		}
		System.out.println(sb);

		
	}
}