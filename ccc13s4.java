import java.io.*;
import java.util.*;

public class Main {

    static int n, m, maxn = 1000002;
    static ArrayList<Integer> [] graph;
    public static void main(String[] args) throws Exception{
        BufferedReader read = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer token = new StringTokenizer(read.readLine());

        n = Integer.parseInt(token.nextToken());
        m = Integer.parseInt(token.nextToken());

        graph = new ArrayList[maxn];
        for(int i = 1; i <= n; i++){
            graph[i] = new ArrayList<Integer>();
        }

        for (int i = 0; i < m; i++) {
            token = new StringTokenizer(read.readLine());
            int a = Integer.parseInt(token.nextToken());
            int b = Integer.parseInt(token.nextToken());
            graph[a].add(b);
        }

        token = new StringTokenizer(read.readLine());
        int p = Integer.parseInt(token.nextToken());
        int q = Integer.parseInt(token.nextToken());

        if(taller(p,q)) System.out.println("yes");
        else if(taller(q,p)) System.out.println("no");
        else System.out.println("unknown");

    }

    static boolean taller(int st, int end) {
        boolean vis[] = new boolean[maxn];
        Queue<Integer> que = new LinkedList<>();
        que.add(st);
        vis[st] = true;

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

