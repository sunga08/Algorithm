import java.util.*;

class Solution {

    public String solution(String p){
        String answer = getValidateString(p);
        
        return answer;
    }
    
    //주어진 로직대로 구현하기
    public String getValidateString(String p) {
        
        //1. u,v 분리하기
        int idx = splitString(p);        
        String u = p.substring(0,idx+1);
        String v = p.substring(idx+1);
        
        StringBuilder sb = new StringBuilder();
        
        if(validateString(u)){ //2. u가 올바른 괄호 문자열이면
            sb.append(u);
            if(!v.equals("")){
                sb.append(getValidateString(v));//v에 대해 1단계부터 수행 후 이어붙이기
                v="";
            }
            return sb.toString(); //반환
        }
        
        else{ //3. u가 올바른 괄호 문자열이 아니라면
            sb.append("("); //4-1. 빈 문자열에 "(" 붙이기
        
            if(!v.equals("")){ //v가 빈문자열이 아닐 때
                sb.append(getValidateString(v)); //4-2. v에 대해 1단계부터 재귀 수행 결과 이어 붙이기
                //v="";
            }
            
            sb.append(")");  //4-3. ")" 붙이기
            
            //4-4. u의 앞뒤 제거
            u = u.substring(1,u.length()-1);

            if(!u.equals("")){
                sb.append(setValidateString(u)); //나머지 문자열 괄호 방향 바꾸기    
            }
            
            return sb.toString(); //4-5. 생성된 문자열 반환
        }
    }
    
    //균형잡힌 괄호 문자열을 만드는 인덱스 구하기
    public int splitString(String p){
        String[] splitString = p.split(""); //한 글자씩 문자열 분할

        int cntP = 0;
        int idx = 0;
        for(idx=0;idx<splitString.length;idx++){
            if(splitString[idx].equals("("))
                cntP++; //"("일 때 증가
            else cntP--; //")"일 때 감소

            if(cntP==0){ //균형잡힌 문자열이 만들어짐
                break;
            }
        }
    
        return idx;
    }

    //올바른 괄호 문자열인지 판단
    public boolean validateString(String p){
        String[] split = p.split("");
        int cnt = 0;
        for(String s : split){
            if(s.equals("(")) cnt++;
            else cnt--;

            if(cnt<0) return false; //올바른 괄호 문자열은 "("이 먼저 나와야 하므로 cnt가 0보다 작아질 수 없음
        }

        return true;
    }

    //올바른 괄호 문자열 만들기=> "("이면 ")"을, ")"이면 "("을 StringBuilder에 넣어줌
    public String setValidateString(String p){
        String[] splitString = p.split("");
        StringBuilder sb = new StringBuilder();
        
        for(int i=0;i<splitString.length;i++){
            if(splitString[i].equals("(")) sb.append(")");
            else sb.append("(");
        }

        return sb.toString();
    }

}
