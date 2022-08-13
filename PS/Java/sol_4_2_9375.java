import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;
//import java.util.Arrays; // 배열 선언
import java.util.HashMap; // key,value
import java.util.StringTokenizer; // 문자열 나누기


public class sol_4_2_9375 {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

		int testCase = Integer.parseInt(br.readLine()); // 테스트 개수 입력받기
		int result = 0;
		for( int i =0; i<testCase;i++) {
			
			int clothNum = Integer.parseInt(br.readLine()); // 옷의 개수
			HashMap<String,Integer> map1 = new HashMap<String,Integer>(); // 옷의 종류, 개수
			
			for(int j = 0 ; j<clothNum;j++) {
				StringTokenizer st = new StringTokenizer(br.readLine(), " "); // 문자열 읽고 공백 기준 나누			
				st.nextToken();	// 옷 이름 고려 X 
				
				String kind = st.nextToken();	// 옷 종류 

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