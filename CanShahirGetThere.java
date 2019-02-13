import java.io.*;
import java.util.*;

public class Main {

    static int n, m, a, b;
    static ArrayList<Integer> [] graph = new ArrayList[2002];
    public static void main(String[] args) throws Exception{
        BufferedReader read = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer token = new StringTokenizer(read.readLine());

        n = Integer.parseInt(token.nextToken());
        m = Integer.parseInt(token.nextToken());
        a = Integer.parseInt(token.nextToken());
        b = Integer.parseInt(token.nextToken());

        for(int i = 1; i <= n; i++){
            graph[i] = new ArrayList<>();
        }

        for(int i = 0; i < m; i++){
            token = new StringTokenizer(read.readLine());
            int x, y;
            x = Integer.parseInt(token.nextToken());
            y = Integer.parseInt(token.nextToken());
            graph[x].add(y);
            graph[y].add(x);
        }

        if(bfs(a, b)) System.out.println("GO SHAHIR!");
        else System.out.println("NO SHAHIR!");
    }

    static boolean bfs(int st, int end) {
        boolean vis[] = new boolean[n + 1];
        Queue<Integer> que = new LinkedList<>();
        que.add(st);
        vis[st] = true;

        if(st == end) return true;

        while (!que.isEmpty()){
            int u = que.poll();

            for(int v : graph[u]){
                if(!vis[v]){
                    if(v == end) return true;
                    vis[v] = true;
                    que.add(v);
                }
            }
        }
        return false;
    }
}
