package com.mulcam.control;

//���������� 
//&&, || ������� �ʰ� �ذ�
public class GBB2 {

	public static void main(String[] args) {
		
		int com = (int) (Math.random()*3); //�����ϰ� ����(0, 1, 2) �߻�
		int my = 1;
		System.out.println("��ǻ��: "+com);

		
		int result = (com - my + 2)%3;
		String str = "";
		
		if(result == 0) {
			str = "����";
		}
		else if(result ==1) {
			str = "�̰��";
		}
		else {
			str = "����";
		}
		
		String comStr = "";
		if(my==0) comStr="����";
		else if(my==1) comStr="����";
		else comStr="��";
		
		String myStr = "";
		if(my==0) myStr="����";
		else if(my==1) myStr="����";
		else myStr="��";
		
		System.out.println("�� : "+comStr+"\t�� : "+myStr+"\t��� : "+str);

	}

}
