import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;
import java.util.StringTokenizer; // 문자열 나누기
import java.util.Arrays;
/*
입력
10
6 3 2 10 10 10 -10 -10 7 3
8
10 9 -5 2 3 4 5 -10
*/

public class sol_7_3_10816 {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		int N = Integer.parseInt(br.readLine()); // N 개의 정수
		int[] arrN = new int[N];
		
		StringTokenizer st = new StringTokenizer(br.readLine(), " ");
		for(int i =0; i<N;i++) {
			arrN[i] = Integer.parseInt(st.nextToken());
		}
		Arrays.sort(arrN);
		
		int M = Integer.parseInt(br.readLine()); // 뽑는 숫자 개수
		
		StringBuilder sb = new StringBuilder();
		st = new StringTokenizer(br.readLine(), " ");
		
		for(int i =0; i<M;i++) {
			int key = Integer.parseInt(st.nextToken());
			// 입력받은 정수에 따라 index 구하기 ( 개수 세기 )
			sb.append(upperBound(arrN, key) - lowerBound(arrN, key)).append(' ');
		}	
		System.out.println(sb);
	}
	private static int lowerBound(int[] arr, int key) {
		int lo = 0; 
		int hi = arr.length; 

		// lo가 hi랑 같아질 때 까지 반복
		while (lo < hi) {
			int mid = (lo + hi) / 2; // 중간위치를 구한다.
			/*
			 *  key 가 mid 보다 작거나 같으면 hi = mid 로 땡기기
			 *  
			 *  key 가 mid 보다 크면 lo = mid + 1 로 땡기기
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
 
		// lo가 hi랑 같아질 때 까지 반복
		while (lo < hi) {
			int mid = (lo + hi) / 2; // 중간위치를 구한다.
			// key값이 중간 위치의 값보다 작을 경우
			if (key < arr[mid]) {
				hi = mid;
			}
			// 중복원소의 경우 else에서 처리된다.
			else {
				lo = mid + 1;
			}
		}
		return lo;
	}
}

