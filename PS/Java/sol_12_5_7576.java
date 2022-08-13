import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;
import java.util.Arrays;

public class sol_7_5_18110 {
	public static void main(String[] args) throws IOException {
		
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		int N = Integer.parseInt(br.readLine());
		double sum = 0;
		
		if (N == 0) {
			System.out.println(0);
		}
		
		else {
			int k = (int) Math.round(N*0.15);
			int[] arr = new int[N];
			for (int i = 0; i < N; i++) {
				arr[i] = Integer.parseInt(br.readLine());
			}
			Arrays.sort(arr);
			
			for (int i = k; i < N - k; i++) {
				sum += arr[i];
			}
			
			System.out.println((int)Math.round(sum/(N-2*k)));
		}
		
	}
}