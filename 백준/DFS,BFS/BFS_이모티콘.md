### JAVA 소스코드

```java
class Emoji{
    int screen;
    int board;

    public Emoji(int screen, int board){
        this.screen = screen;
        this.board = board;
    }
}

public class 이모티콘 {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();

        int[][] dist = new int[n+1][n+1];
        Queue<Emoji> q = new LinkedList<>();

        for(int i=0;i<=n;i++){
            Arrays.fill(dist[i],-1);
        }

        q.add(new Emoji(1,0));
        dist[1][0] = 0;

        while(!q.isEmpty()){
            Emoji cur = q.poll();
            int s = cur.screen;
            int c = cur.board;
            //System.out.println("s:"+s+" c:"+c);

            if(dist[s][s]==-1) {
                q.add(new Emoji(s, s));
                dist[s][s] = dist[s][c]+1;
            }

            if(s+c<=n && dist[s+c][c]==-1){ //dist[][]==-1 이면 아직 방문하지 않은 것
                q.add(new Emoji(s+c, c));
                dist[s+c][c] = dist[s][c]+1;
            }

            if(s-1>0 && dist[s-1][c]==-1){
                q.add(new Emoji(s-1, c));
                dist[s-1][c] = dist[s][c]+1;
            }

        }
        int ans = -1;
        for(int i=0;i<=n;i++){
            if(dist[n][i]!=-1){
                if(ans==-1 || dist[n][i]<ans){
                    ans = dist[n][i];
                }
            }
        }

        System.out.println(ans);
    }
}
```

### 참고

- 클립보드의 이모티콘 개수에 따라 다음 연산 결과가 달라진다.
  - ex) 현재 화면에 8개 </br>
      3번 연산 결과 = 7개 / 2번 연산 결과 = 알 수 없음(클립보드 이모티콘 개수에 따라 다름)
  - 하나의 정점을 클립보드 이모티콘 사용 개수에 따라 다르게 생각할 수 있다.

- 화면의 이모티콘 `s`, 클립보드의 이모티콘 `c` -> 정점 `(s,c)`

- 연산에 따른 다음 결과
  - 화면의 이모티콘을 모두 복사해 클립보드에 저장: (s, c) => `(s, s)`
  - 클립보드의 모든 이모티콘을 화면에 붙여넣기: (s, c) => `(s+c, c)`
  - 화면에 있는 이모티콘 중 하나 삭제: (s, c) => `(s-1, c)`
