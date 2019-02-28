import java.util.*;

public class Vanilla1 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int num = sc.nextInt();
        for(int asdf = 0; asdf < num; asdf++) {
            int numNodes = sc.nextInt();
            int numEdges = sc.nextInt();
            int startNode = sc.nextInt();
            int furthestDist = sc.nextInt();
            boolean[] visited = new boolean[numNodes + 1];
            //set up adjacency list
            ArrayList<ArrayList<Integer>> list = new ArrayList<>();
            list.add(new ArrayList<>());
            for (int i = 1; i <= numNodes; i++) {
                list.add(new ArrayList<>());
            }
            //add edges
            for (int i = 0; i < numEdges; i++) {
                int a = sc.nextInt();
                int b = sc.nextInt();
                list.get(a).add(b);
                list.get(b).add(a);
            }
            //find number of components
            int count = 0;
            int numVisited = 0;
            Stack<Integer> toSearch = new Stack<>();
            while (numVisited < numNodes) {
                if (toSearch.size() == 0) {
                    count++;
                    for (int i = 1; i <= numNodes; i++) {
                        if (!visited[i]) {
                            toSearch.push(i);
                            break;
                        }
                    }
                }
                int curNode = toSearch.pop();
                if(visited[curNode])continue;
                visited[curNode] = true;
                numVisited++;
                for (int i : list.get(curNode)) {
                    if (!visited[i]) {
                        toSearch.push(i);
                    }
                }
            }//end while
            System.out.print(count + " ");
            //clear visited array
            for (int i = 1; i <= numNodes; i++) {
                visited[i] = false;
            }
            //find number of close nodes
            numVisited = 0;
            int[] dist = new int[numNodes+1];
            Queue<Integer> toSearch2 = new LinkedList<>();
            toSearch2.add(startNode);
            while (!toSearch2.isEmpty()) {
                int curNode = toSearch2.poll();
                if(visited[curNode]) continue;
                visited[curNode] = true;
                numVisited++;
                if(dist[curNode] == furthestDist) continue;
                for (int i : list.get(curNode)) {
                    if (!visited[i]) {
                        toSearch2.add(i);
                        dist[i] = dist[curNode] + 1;
                    }
                }
            }//end while
            System.out.println(numVisited);


        }
    }
}
