import java.util.ArrayDeque;
import java.util.Scanner;

public class ccc18s3v2 {

    private static int M, N;
    private static char[][] map = new char[101][101];
    private static int[][] dp = new int[101][101];
    private static boolean[][] visited = new boolean[101][101];

    private enum Direction {
        UP(0, -1),
        DOWN(0, 1),
        LEFT(-1, 0),
        RIGHT(1, 0);

        public final int x;
        public final int y;

        Direction(int x, int y) {
            this.x = x;
            this.y = y;
        }
    }

    private static class Point {
        public int x;
        public int y;

        Point(int x, int y) {
            this.x = x;
            this.y = y;
        }
    }

    private static void expandCamera(Point p) {
        int x = p.x;
        int y = p.y;
        while (x >= 0) {
            if (map[y][x] == '.' || map[y][x] == 'S') {
                map[y][x] = 'X';
            } else if (map[y][x] == 'W') {
                break;
            }
            x--;
        }
        x = p.x;
        y = p.y;
        while (x < M) {
            if (map[y][x] == '.' || map[y][x] == 'S') {
                map[y][x] = 'X';
            } else if (map[y][x] == 'W') {
                break;
            }
            x++;
        }
        x = p.x;
        y = p.y;
        while (y >= 0) {
            if (map[y][x] == '.' || map[y][x] == 'S') {
                map[y][x] = 'X';
            } else if (map[y][x] == 'W') {
                break;
            }
            y--;
        }
        x = p.x;
        y = p.y;
        while (y < N) {
            if (map[y][x] == '.' || map[y][x] == 'S') {
                map[y][x] = 'X';
            } else if (map[y][x] == 'W') {
                break;
            }
            y++;
        }
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String[] line = scanner.nextLine().trim().split(" ");
        N = Integer.parseInt(line[0]);
        M = Integer.parseInt(line[1]);

        Point start = null;
        for (int i = 0; i < N; i++) {
            char[] mapLine = scanner.nextLine().trim().toCharArray();
            for (int j = 0; j < M; j++) {
                map[i][j] = mapLine[j];
                if (mapLine[j] == 'S') {
                    start = new Point(j, i);
                }
            }
        }

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                if (map[i][j] == 'C') {
                    expandCamera(new Point(j, i));
                }
            }
        }

        ArrayDeque<Point> deque = new ArrayDeque<>();
        dp[start.y][start.x] = 0;
        if (map[start.y][start.x] == 'X') {
            dp[start.y][start.x] = -1;
        } else {
            deque.addLast(start);
        }
        visited[start.y][start.x] = true;
        while (!deque.isEmpty()) {
            Point curPoint = deque.removeFirst();
            char curPointChar = map[curPoint.y][curPoint.x];
            for (Direction direction : Direction.values()) {
                Point testPoint = new Point(curPoint.x + direction.x, curPoint.y + direction.y);
                if (!visited[testPoint.y][testPoint.x]) {
                    if (curPointChar == 'S' || curPointChar == '.' || (curPointChar == 'L' && direction.name().equals("LEFT")) || (curPointChar == 'R' && direction.name().equals("RIGHT")) || (curPointChar == 'U' && direction.name().equals("UP")) || (curPointChar == 'D' && direction.name().equals("DOWN"))) {
                        switch (map[testPoint.y][testPoint.x]) {
                            case '.':
                                deque.addLast(testPoint);
                                dp[testPoint.y][testPoint.x] = dp[curPoint.y][curPoint.x] + 1;
                                visited[testPoint.y][testPoint.x] = true;
                                break;
                            case 'L':
                            case 'R':
                            case 'U':
                            case 'D':
                                deque.addFirst(testPoint);
                                dp[testPoint.y][testPoint.x] = dp[curPoint.y][curPoint.x];
                                visited[testPoint.y][testPoint.x] = true;
                                break;
                        }
                    }
                }
            }
        }

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                if (map[i][j] == '.') {
                    if (visited[i][j]) {
                        System.out.println(dp[i][j]);
                    } else {
                        System.out.println(-1);
                    }
                } else if (map[i][j] == 'X' && !(i == start.y && j == start.x)) {
                    System.out.println(-1);
                }
            }
        }
    }

}
