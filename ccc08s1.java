import java.util.Scanner;

public class ccc08s1 {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        String maxCity = "";
        int minTemp = Integer.MAX_VALUE;
        while (true) {
            String[] line = in.nextLine().split(" ");
            String city = line[0];
            int temp = Integer.parseInt(line[1]);
            if (temp < minTemp) {
                maxCity = city;
                minTemp = temp;
            }
            if (city.equals("Waterloo")) {
                break;
            }
        }
        System.out.println(maxCity);
    }

}
