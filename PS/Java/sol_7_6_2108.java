import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;
import java.util.Arrays;
 
public class sol_7_6_2108 {
	public static void main(String[] args) throws IOException {
 
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
 
		int N = Integer.parseInt(br.readLine());
		
		int[] arr = new int[N];
		int sum = 0;
		 // 배열에 저장
		for(int i = 0; i < N; i++) {
			int value = Integer.parseInt(br.readLine());
			arr[i] = value;
			sum += value;
		}
		 // 오름차순 정렬
		Arrays.sort(arr);
		
		int flag = 0;
		int freqNum = 0;
		int mode = 10000;
		
		for(int i = 0; i < N; i++) {
			int jump = 0;	// 동일한 수가 나온 수
			int count = 1;
			
			// 동일한 수 세기
			for(int j = i + 1; j < N; j++){
				if(arr[i] != arr[j]) {
					break;
				}
				count++;
				jump++;
			}
			
			// 갱신되며 최빈수 찾음
			if(count > freqNum) {
				freqNum = count;
				mode = arr[i];
				flag = 1;
			}
			// 최빈수와 같고 두번째면 변경 ( 이후에 더 나와도 위에서 걸러짐 )
			else if(count == freqNum && flag == 1) {
				mode = arr[i];
				flag = 0;
			}
			
			i += jump;
		}
		
		System.out.println((int)Math.round((double)sum / N));
		System.out.println(arr[N / 2]);
		System.out.println(mode);		
		System.out.println(arr[N - 1] - arr[0]);
		
	}
}