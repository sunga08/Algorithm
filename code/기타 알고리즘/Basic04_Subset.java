package day01_prac;

public class Basic04_Subset {
	public static void main(String[] args) {
		char[] arr = {'A','B','C','D'};
		print(arr,arr.length);
	}
	
//	부분집합 출력 => n개의 비트로 2^n까지 표현할수 있음을 이용
	public static void print(char[] arr, int num) {
		for(int i=0;i<(1<<num);i++) { //부분집합의 개수인 2^num만큼 반복
			if(count(i)==3) { //부분집합 원소 갯수 지정 (i를 2진수로 표현했을 때 1인 비트가 3개인 경우만 출력)
				for(int j=0;j<num;j++) { //배열의 길이만큼 돌면서
					System.out.print("{");
					if((i&(1<<j))!=0) { //비트가 1인 인덱스의 값을 출력
						System.out.println(arr[j]);
					}
				}
				System.out.println("}");
			}
		}
	}
	
//  2진수로 표현했을 때 1인 갯수 
	public static int count(int num) {
		int count =0;
		while(num>0) {
			if((num&1)==1) count++;
			num = num>>1;
		}
		
		return count;
	}
}
