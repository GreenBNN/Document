import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;
import java.util.Stack;


public class sol_4_2_4949 {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		while(true) {
			String str = br.readLine();
			if( str.equals(".")) {
				break;
			}
			
			System.out.println(solve(str));
		}		
	}
	
	public static String solve(String s) {
		Stack<Character> stack = new Stack<>(); // char �� ���� ����
		
		for(int i = 0;i<s.length();i++) {
			char c = s.charAt(i); // i ��° ����
			
			// ���� ��ȣ��� stack �� push
			if(c=='(' || c == '[') {
				stack.push(c);
			}
			else if(c == ')') {
				if(stack.empty() || stack.peek() != '(') {
					return "no";
				}
				else {
					stack.pop();
				}
			}
			else if(c == ']') {
				if(stack.empty() || stack.peek() != '[') {
					return "no";
				}
				else {
					stack.pop();
				}
			}
		}
		
		if (stack.empty()) {
			return "yes";
		}
		else {
			return "no";
		}
	}
}