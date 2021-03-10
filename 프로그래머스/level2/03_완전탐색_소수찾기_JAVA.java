//조합 이용해서 가능한 모든 수 만들기 => 숫자로 변환해 HashSet에 넣기 (HashSet으로 중복제거)
//소수 판단하기

class Solution {
    HashSet<Integer> set = new HashSet<>();
    StringBuffer result = new StringBuffer();
    boolean[] check = new boolean[7];
        
    public int solution(String numbers) {
        int answer = 0;
        
        combination(0,numbers.length(),numbers);
        
        //소수 판단
        
        for(Integer num:set){
            boolean isPrime=true;
            if(num==0||num==1) continue;
            
            else{
                for(int i=2;i<=Math.sqrt(num);i++){
                    if(num%i==0){
                        isPrime=false;
                        break;
                    }
                }
            }
            
            if(isPrime) answer++;
            
        }
        return answer;
    }
    
    public void combination(int depth, int limit, String numbers){
        if(depth==limit) return;
        for(int i=0;i<limit;i++){
            if(!check[i]){
                check[i]=true;
                result.append(numbers.charAt(i));
                set.add(Integer.valueOf(result.toString())); //Integer는 valueOf 사용!!
                combination(depth+1,limit,numbers);
                result.deleteCharAt(result.length()-1);
                
                check[i]=false;
            }
        }
    }
}
