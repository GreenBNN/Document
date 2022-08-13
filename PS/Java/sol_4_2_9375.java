import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;
//import java.util.Arrays; // �迭 ����
import java.util.HashMap; // key,value
import java.util.StringTokenizer; // ���ڿ� ������


public class sol_4_2_9375 {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

		int testCase = Integer.parseInt(br.readLine()); // �׽�Ʈ ���� �Է¹ޱ�
		int result = 0;
		for( int i =0; i<testCase;i++) {
			
			int clothNum = Integer.parseInt(br.readLine()); // ���� ����
			HashMap<String,Integer> map1 = new HashMap<String,Integer>(); // ���� ����, ����
			
			for(int j = 0 ; j<clothNum;j++) {
				StringTokenizer st = new StringTokenizer(br.readLine(), " "); // ���ڿ� �а� ���� ���� ����			
				st.nextToken();	// �� �̸� ��� X 
				
				String kind = st.nextToken();	// �� ���� 

				if (map1.containsKey(kind)) {
					map1.put(kind, map1.get(kind) + 1);
				} 
				else {
					map1.put(kind, 1);
				}
				
				}
			
			result = 1;
			for(int value :map1.values()) {
				result *= (value+1);
			}
			System.out.println(result - 1);
		}	
	}
}