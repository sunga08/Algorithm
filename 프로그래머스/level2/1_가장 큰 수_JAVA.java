import java.util.Arrays;
import java.util.Comparator;

class Solution {
    public String solution(int[] numbers) {
        String[] result = new String[numbers.length];
    
        //int형 배열->string 배열로 바꾸기
        for(int i=0;i<numbers.length;i++){
            result[i]=String.valueOf(numbers[i]);
        }
        
                
        //정렬 : 문자열을 앞뒤로 붙여보고 정렬기준 판단 & 내림차순 정렬
        Arrays.sort(result, new Comparator<String>(){
           @Override
            public int compare(String s1, String s2){
                return (s2+s1).compareTo(s1+s2);
            }
        });
        
        //첫번째 원소가 0이면 나머지도 0이므로 0 하나만 return
        if(result[0].equals("0")){
            return "0";
        }
        
        //문자열 배열=>문자열에 이어붙이기
        String answer = "";
        for(int i=0;i<result.length;i++){
            answer+=result[i];
        }
        
        return answer;
    }
}
