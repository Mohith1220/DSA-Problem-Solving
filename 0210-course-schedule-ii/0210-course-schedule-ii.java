import java.util.*;

class Solution {
    public int[] findOrder(int numCourses, int[][] prerequisites) {
        List<Integer>[] graph = new ArrayList[numCourses];
        int[] indegree = new int[numCourses];

        for (int i = 0; i < numCourses; i++) {
            graph[i] = new ArrayList<>();
        }
//finding indegree
        for (int[] p : prerequisites) {
            graph[p[1]].add(p[0]);
            indegree[p[0]]++;
        }
//travel thorugh the graph to find which has 0 degree
        Queue<Integer> queue = new ArrayDeque<>();

        for (int i = 0; i < numCourses; i++) {
            if (indegree[i] == 0) {
                queue.offer(i);
            }
        }

        int[] result = new int[numCourses];
        int index = 0;
//finding the final results
        while (!queue.isEmpty()) {
            int course = queue.poll();//pop out the top elements
            result[index++] = course;

            for (int next : graph[course]) {
                indegree[next]--; //on poping out of the parent node reduce the indegree

                if (indegree[next] == 0) {
                    queue.offer(next);// after reducing only if indegree is 0 push the coruse into the queue
                }
            }
        }

        return index == numCourses ? result : new int[0];// check whether result macthes with number of courses if yes return res orlse return empty [] 
    }
}