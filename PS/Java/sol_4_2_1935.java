import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;

import java.util.HashMap; // key,value

import java.util.Stack;

public class sol_4_2_1935 {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		int num = Integer.parseInt(br.readLine()); // ���� ����
		Stack<Double> stack = new Stack<>(); // char �� ���� ����
		HashMap<Character,Double> map1 = new HashMap<Character,Double>(); // ����, ����
		String str = br.readLine(); // ���� ǥ���
		
		for(int i= 0 ;i<str.length();i++) {
			
			char c = str.charAt(i);
			
			if(c == '+') { // �����ڶ�� stack ���� �� ���� �̾Ƽ� ��� �� �־��ֱ�
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
			else { // ���ڶ�� �ش��ϴ� ���� �־��ֱ�
				if (!map1.containsKey(c)) { // map �� ������ �߰� 
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