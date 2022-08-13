import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;

public class sol_4_2_2292 {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		int num = 0; // 찾고자 하는 수
		int answer = 0; // 답
		int temp = 0; // 비교식
		
		num = Integer.parseInt(br.readLine()); // 입력받기
		
		for(int i =1; i<40000;i++) { 
			temp = 3*i*(i-1) +1; // temp 까지 i 번째 
			if(temp >= num) {
				answer = i;
				break;
			}
		}
		
		System.out.println(answer);
	}
}