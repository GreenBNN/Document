import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;

public class sol_4_2_2292 {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		int num = 0; // ã���� �ϴ� ��
		int answer = 0; // ��
		int temp = 0; // �񱳽�
		
		num = Integer.parseInt(br.readLine()); // �Է¹ޱ�
		
		for(int i =1; i<40000;i++) { 
			temp = 3*i*(i-1) +1; // temp ���� i ��° 
			if(temp >= num) {
				answer = i;
				break;
			}
		}
		
		System.out.println(answer);
	}
}