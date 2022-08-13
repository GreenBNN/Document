import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;
import java.util.StringTokenizer; // ���ڿ� ������
import java.util.Arrays;

/*�Է� 
5
4 1 5 2 3
5
1 3 7 9 5
*/

public class sol_7_2_1920 {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		int N = Integer.parseInt(br.readLine()); // N ���� ����
		int[] arrN = new int[N];
		
		StringTokenizer st = new StringTokenizer(br.readLine(), " ");
		for(int i =0; i<N;i++) {
			arrN[i] = Integer.parseInt(st.nextToken());
		}
		
		int M = Integer.parseInt(br.readLine()); // �̴� ���� ����
		int[] arrM = new int[M];
		
		st = new StringTokenizer(br.readLine(), " ");
		StringBuilder sb = new StringBuilder();
		
//		�ϳ��� �� ã�� �ð����⵵ O(N*M) �ð��ʰ�		
//		int flag =0;
//		for(int i =0; i<M;i++) {
//			//arrM[i] = Integer.parseInt(st.nextToken());
//			int temp = Integer.parseInt(st.nextToken());
//			for(int j = 0 ; j<N;j++) {
//				if(arrN[j] == temp) {
//					flag = 1;
//					break;
//				}
//			}
//			if(flag == 1) {
//				sb.append(1).append('\n');
//				flag =0;
//			}
//			else {
//				sb.append(0).append('\n');
//			}
//		}
		Arrays.sort(arrN);
		
		for(int i = 0; i<M;i++) {
			int num = Integer.parseInt(st.nextToken());
			int left = 0;
	        int right = arrN.length - 1;
	        boolean flag = false;
	        while (left <= right) {
	            int midIndex = (left + right) / 2;
	            int midValue = arrN[midIndex];
	            if (midValue > num) {
	                right = midIndex - 1;
	            } else if (midValue < num) {
	                left = midIndex + 1;
	            } else { //ã��
	                flag = true;
	                sb.append(1).append('\n');
	                break;
	            }
	        }
	        if(!flag) {
	        	sb.append(0).append('\n');
	        }
		}
		System.out.println(sb);
	}
}