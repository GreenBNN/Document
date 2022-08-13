import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;
import java.util.Arrays;

// �Է� BufferedReader �� ��� sysout println ���� ���� X

public class sol_7_1_10989 {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		int N = Integer.parseInt(br.readLine()); // �� ����
		int[] seq = new int[10001]; // ����Ǵ� �迭
		
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
		
// 		�⺻ ���� array sort ��� ( O(nlogn ~ n^2)  )
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