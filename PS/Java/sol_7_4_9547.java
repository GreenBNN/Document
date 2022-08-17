import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;
import java.util.StringTokenizer; // 문자열 나누기
import java.util.Arrays;
/*
입력
2
2 3
2 1
1 2
2 1
3 5
1 2 3
1 2 3
2 1 3
2 3 1
3 2 1
*/

public class sol_7_4_9547 {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int T = Integer.parseInt(br.readLine()); // 테스트케이스
		
		for(int i =0 ;i<T;i++) {
			StringTokenizer st = new StringTokenizer(br.readLine(), " ");
			int C = Integer.parseInt(st.nextToken()); // 후보 수
			int V = Integer.parseInt(st.nextToken()); // 유권자 수
			
			int[][] arr = new int[V][C]; // 유권자에 따른 선호도 저장
			int[] selectArr = new int[C+1]; // 후보자가 받을 표 수 배열
			
			for(int j = 0 ;j < V;j++) {
				
				st = new StringTokenizer(br.readLine(), " ");
				for(int k = 0; k<C ;k++) {
					arr[j][k] = Integer.parseInt(st.nextToken());
					
					if(k==0) {
						selectArr[arr[j][k]]++;
					}
				}
			}
			
			int[] votes = selectArr;
			int[] candi = findCandi(votes);
			int[][] cases = arr;
			if (candi[0] > V/2) {
				System.out.println(Integer.toString(search(votes, candi[0])) + " 1");
			}
			
			else {
				int candidate1 = search(votes, candi[0]);
				int candidate2 = searchback(votes, candi[1]);
				
				Arrays.fill(votes, 0);
				
				for (int j = 0; j < V; j++) {
					for (int k = 0; k < C; k++) {
						if (cases[j][k] == candidate1) {
							votes[candidate1] += 1;
							break;
						}
						else if (cases[j][k] == candidate2) {
							votes[candidate2] += 1;
							break;
						}
					}
				}
				
				if (votes[candidate1] > votes[candidate2]) 
					System.out.println(candidate1 + " 2");
				else
					System.out.println(candidate2 + " 2");
			}
			
//			if(max > V/2) {
//				sb.append(maxIndex).append(' ');
//				sb.append(1).append('\n');
//			}
//			else {
//				selectArr[maxIndex] = 0;
//				selectArr[preMaxIndex] = 0;
//				for(int j = 0;j<V;j++) {
//					for(int k = 0; k<C+1;k++) {
//						
//						if(arr[j][k] == maxIndex) {
//							selectArr[maxIndex]++;
//							break;
//						}
//						else if(arr[j][k] == preMaxIndex) {
//							selectArr[preMaxIndex]++;
//							break;
//						}
//						
//					}
//				}
//				
//				if(selectArr[maxIndex] > selectArr[preMaxIndex]) {
//					sb.append(maxIndex).append(' ');
//					sb.append(2).append('\n');
//				}
//				else {
//					sb.append(preMaxIndex).append(' ');
//					sb.append(2).append('\n');
//				}
//			}	
//		}
//		System.out.println(sb);
	
		}
	}
	public static int search(int[] arr, int l) {
		for (int i=0; i<arr.length; i++) {
			if (arr[i] == l) {
				return i;
			}
		}
		return -1;
	}
	
	public static int searchback(int[] arr, int l) {
		for (int i=arr.length-1; i>=0; i--) {
			if (arr[i] == l) {
				return i;
			}
		}
		return -1;
	}
	
	public static int[] findCandi(int[] arr) {
		int first = -1;
		int second = -1;
		for (int i=0; i<arr.length; i++) {
			if (arr[i] > first) {
				second = first;
				first = arr[i];
			} else if(arr[i] > second) {
				second = arr[i];
			}
		}
		int[] result = {first, second};
		return  result;
	}
}
	
	