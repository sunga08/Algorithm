package day04.prob;

public class Stack_java {
	int[] stack;
	int idx = 0;
	
	public Stack_java(){
		stack = new int[10];
	}
	
	public Stack_java(int n) {
		stack = new int[n>0 ? n : 10 ];
	}
	
	public void push(int n) {
		if(isFull()) {
			int[] temp = new int[stack.length*2];
			System.arraycopy(stack, 0, temp, 0, stack.length);
			stack = temp;
			temp = null;
		}
		else {
			stack[idx++]=n;
		}
	}
	
	public boolean isEmpty() {
		
		return idx==0 ? true : false;
	}
	
	public boolean isFull() {

		return idx==stack.length ? true : false;
	}
	
	public int top() {
			
		return idx==0 ? -1 : stack[idx-1];
	}
	
	public int pop() {
		int data = -1;
		if(!isEmpty()) {
			data = stack[idx-1];
			stack[idx-1] = 0;
			idx--;
		}
		
		return data;
	}
}
