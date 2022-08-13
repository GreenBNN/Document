import java.io.BufferedReader;

import java.io.InputStreamReader;
import java.io.IOException;
import java.util.ArrayList;
import java.util.List;

import java.util.StringTokenizer;

public class sol_12_2_2210 {
	static List<String> list = new ArrayList<>();

	static String[][] arr;
	
	static int[] dx = {-1, 1, 0, 0}; 
	static int[] dy = {0, 0, -1, 1};
	
	public static void main(String[] args) throws IOException {
		
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st;
		
		arr = new String[5][5];
		for(int i = 0; i<5;i++) {
			st = new StringTokenizer(br.readLine(), " ");
			for(int j = 0; j < 5;j++) {
				arr[i][j] = st.nextToken(); 
			}
		}
		for(int i=0;i<5;i++) { 
			for(int j=0;j<5;j++) { 
				DFS( i, j, 0, arr[i][j]); 
				} 
			} 
		System.out.println(list.size()); 
		} 
	public static void DFS( int x, int y, int cnt, String tmp) { 
		if(cnt == 5) { 
			if(!list.contains(tmp)) { 
				list.add(tmp); 
			} 
			return; 
		} 
		
		for(int i=0;i<4;i++) { 
			int nowx = x+dx[i]; 
			int nowy = y+dy[i]; 
			if((0<=nowx&&nowx<5)&&(0<=nowy&&nowy<5)) { 
				DFS(nowx, nowy, cnt+1, tmp+arr[nowx][nowy]); 
				} 
			} 
		} 
	}
