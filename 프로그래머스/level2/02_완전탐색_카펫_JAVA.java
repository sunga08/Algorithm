class Solution {
    public int[] solution(int brown, int yellow) {
        int[] answer = new int[2];
        
        for(int i=1;i<=yellow;i++){
            if(yellow%i!=0) continue;
            int x = i;
            int y = yellow/x;
          
            if((x+2)*(y+2)-yellow==brown){
                answer[0]=Math.max(x+2,y+2);
                answer[1]=Math.min(x+2,y+2);
                break;
            }
        }
        return answer;
    }
}
