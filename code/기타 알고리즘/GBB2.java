package com.mulcam.control;

//가위바위보 
//&&, || 사용하지 않고 해결
public class GBB2 {

	public static void main(String[] args) {
		
		int com = (int) (Math.random()*3); //랜덤하게 숫자(0, 1, 2) 발생
		int my = 1;
		System.out.println("컴퓨터: "+com);

		
		int result = (com - my + 2)%3;
		String str = "";
		
		if(result == 0) {
			str = "졌다";
		}
		else if(result ==1) {
			str = "이겼다";
		}
		else {
			str = "비겼다";
		}
		
		String comStr = "";
		if(my==0) comStr="가위";
		else if(my==1) comStr="바위";
		else comStr="보";
		
		String myStr = "";
		if(my==0) myStr="가위";
		else if(my==1) myStr="바위";
		else myStr="보";
		
		System.out.println("컴 : "+comStr+"\t나 : "+myStr+"\t결과 : "+str);

	}

}
