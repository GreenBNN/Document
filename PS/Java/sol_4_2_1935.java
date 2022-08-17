import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;

import java.util.HashMap; // key,value

import java.util.Stack;

public class sol_4_2_1935 {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		// int num = Integer.parseInt(br.readLine()); // 변수 개수
		Stack<Double> stack = new Stack<>(); // char 형 스택 선언
		HashMap<Character,Double> map1 = new HashMap<Character,Double>(); // 문자, 숫자
		String str = br.readLine(); // 후위 표기식
		
		for(int i= 0 ;i<str.length();i++) {
			
			char c = str.charAt(i);
			
			if(c == '+') { // 연산자라면 stack 에서 두 숫자 뽑아서 계산 후 넣어주기
				double a = stack.peek();
				stack.pop();
				double b = stack.peek();
				stack.pop();
				double result = b + a;
				stack.push(result);
			}
			else if(c == '-') {
				double a = stack.peek();
				stack.pop();
				double b = stack.peek();
				stack.pop();
				double result = b - a;
				stack.push(result);
			}
			else if(c == '*') {
				double a = stack.peek();
				stack.pop();
				double b = stack.peek();
				stack.pop();
				double result = b * a;
				stack.push(result);
			}
			else if(c == '/') {
				double a = stack.peek();
				stack.pop();
				double b = stack.peek();
				stack.pop();
				double result = b / a;
				stack.push(result);
			}
			else { // 문자라면 해당하는 숫자 넣어주기
				if (!map1.containsKey(c)) { // map 에 없으면 추가 
					String temp = br.readLine();
					map1.put(c,(double)Integer.parseInt(temp));
				}
				stack.push(map1.get(c));
			}
			
		}
		double r = stack.peek();
		System.out.println(String.format("%.2f", r));
	}
}