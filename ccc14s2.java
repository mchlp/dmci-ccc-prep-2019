import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class ccc14s2 {

    public static void main(String[] args) {
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        int N = 0;
        String[] first = {};
        String[] second = {};
        try {
            N = Integer.parseInt(in.readLine());
            first = in.readLine().split(" ");
            second = in.readLine().split(" ");
        } catch (IOException e) {
            e.printStackTrace();
        }

        for (int i=0; i<N; i++) {
            String p1 = first[i];
            String p2 = second[i];
            for (int j=0; j<N; j++) {
                if (first[j].equals(p2)) {
                    if (!second[j].equals(p1) || p1.equals(p2)) {
                        System.out.println("bad");
                        return;
                    }
                }
            }
        }
        System.out.println("good");
    }


}
