import java.util.*;

class Solution {
    public String[] solution(String[] record) {
        List<String> answerTmp = new ArrayList<String>();
        LinkedHashMap<String,String> idNameMap = new LinkedHashMap<>(); 
        
        String inMsg = "님이 들어왔습니다.";
        String outMsg = "님이 나갔습니다.";
        
        int index=0;
        for(int i=0;i<record.length;i++){
            String[] splitStr = record[i].split(" ");
            
            if(splitStr[0].equals("Enter")){           
                idNameMap.put(splitStr[1],splitStr[2]); //uid, 닉네임 넣기
                answerTmp.add(splitStr[1]+","+inMsg); //uid, inMsg 넣기  
            }
            
            else if(splitStr[0].equals("Leave")){
                answerTmp.add(splitStr[1]+","+outMsg); //uid, outMsg 넣기
            }
            
            else if(splitStr[0].equals("Change")){            
                idNameMap.put(splitStr[1],splitStr[2]); //uid의 닉네임 변경
            }
        }
        

        //answerTmp에서 uid 대신 idNameMap에 저장된 닉네임 붙이고 answer 배열에 저장
        String[] answer = new String[answerTmp.size()];
        int i=0;
        for(String s:answerTmp){
            String[] splitStr = s.split(",");
            StringBuilder sb = new StringBuilder();
            sb.append(idNameMap.get(splitStr[0]));
            sb.append(splitStr[1]);
            answer[i]=sb.toString();     
            i++;
        }
        
        return answer;
    }
}
