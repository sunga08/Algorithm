package day01_prac;

import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.util.Scanner;

//10
//5 10
//0000000000
//0123456789
//0000000000
//0000000000
//0000000000

public class Basic02_IO {
	static int s, r, c;
	static int[][] arr;
	
	public static void main(String[] args) throws IOException {
		System.setIn(new FileInputStream("input/input.txt")); //파일 읽어오기
		Scanner sc = new Scanner(System.in);
		
		s = sc.nextInt();
		r = sc.nextInt();
		c = sc.nextInt();
		
		arr = new int[r][c];
		
		for(int i=0;i<r;i++) {
			String s = sc.nextLine(); //한줄씩 문자열로 읽기
			for(int j=0;j<c;j++) { //문자열을 한글자씩 읽으면서 숫자로 바꿔 int 배열에 넣기
				arr[i][j]=s.charAt(j)-'0'; //문자->숫자 
			}
		}
		
		System.out.printf("%d\n%d %d\n",r,c,s);
		for(int i=0;i<r;i++) {
			for(int j=0;j<c;j++) {
				System.out.println(arr[i][j]);
			}
		}
	}
}
