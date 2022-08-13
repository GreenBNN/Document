import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;
import java.util.StringTokenizer; // ���ڿ� ������
import java.util.Arrays;
/*
�Է�
10
6 3 2 10 10 10 -10 -10 7 3
8
10 9 -5 2 3 4 5 -10
*/

public class sol_7_3_10816 {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		int N = Integer.parseInt(br.readLine()); // N ���� ����
		int[] arrN = new int[N];
		
		StringTokenizer st = new StringTokenizer(br.readLine(), " ");
		for(int i =0; i<N;i++) {
			arrN[i] = Integer.parseInt(st.nextToken());
		}
		Arrays.sort(arrN);
		
		int M = Integer.parseInt(br.readLine()); // �̴� ���� ����
		
		StringBuilder sb = new StringBuilder();
		st = new StringTokenizer(br.readLine(), " ");
		
		for(int i =0; i<M;i++) {
			int key = Integer.parseInt(st.nextToken());
			// �Է¹��� ������ ���� index ���ϱ� ( ���� ���� )
			sb.append(upperBound(arrN, key) - lowerBound(arrN, key)).append(' ');
		}	
		System.out.println(sb);
	}
	private static int lowerBound(int[] arr, int key) {
		int lo = 0; 
		int hi = arr.length; 

		// lo�� hi�� ������ �� ���� �ݺ�
		while (lo < hi) {
			int mid = (lo + hi) / 2; // �߰���ġ�� ���Ѵ�.
			/*
			 *  key �� mid ���� �۰ų� ������ hi = mid �� �����
			 *  
			 *  key �� mid ���� ũ�� lo = mid + 1 �� �����
			 */
			if (key <= arr[mid]) {
				hi = mid;
			}
			else {
				lo = mid + 1;
			}
		}
		return lo;
	}
	private static int upperBound(int[] arr, int key) {
		int lo = 0; 
		int hi = arr.length; 
 
		// lo�� hi�� ������ �� ���� �ݺ�
		while (lo < hi) {
			int mid = (lo + hi) / 2; // �߰���ġ�� ���Ѵ�.
			// key���� �߰� ��ġ�� ������ ���� ���
			if (key < arr[mid]) {
				hi = mid;
			}
			// �ߺ������� ��� else���� ó���ȴ�.
			else {
				lo = mid + 1;
			}
		}
		return lo;
	}
}

