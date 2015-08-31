package upc.ai.uninformed;

import java.util.LinkedList;
import java.util.Queue;

/**
 *
 * @author martin.canaval
 */
public class BFSTest {
    LinkedList<State> visited;
    
    public static void main(String[] args) {
        new BFSTest().goForIt();
    }
    
    void goForIt() {
        State start = new PuzzleEight(/*0*/12356478);
        State end = new PuzzleEight(123456780);
        visited = new LinkedList<>();
        LinkedList<State> stepsToSolve = bfs(start, end);
        if (stepsToSolve != null) {
            for (State step : stepsToSolve) {
                System.out.println(step);
            }
        } else {
            System.out.println("No solution!");
        }
    }
    
    LinkedList<State> bfs(State start, State end) {
        LinkedList<State> nextStates;
        LinkedList<State> path = new LinkedList<>();
        LinkedList<State> newPath;
        Queue<LinkedList<State>> paths = new LinkedList<>();
        
        State current;
        path.add(start);
        paths.add(path);
        while (paths.size() > 0) {
            path = paths.remove(); // queue stuff
            current = path.getLast();
            visited.add(current);
            if (current.equals(end)) {
                return path;
            }
            nextStates = current.getNextStates();
            for (State nextState : nextStates) {
                if (!visited.contains(nextState)) {
                    newPath = new LinkedList<>(path);
                    newPath.addLast(nextState);
                    paths.add(newPath); // queue stuff
                }
            }
        }
        return null;
    }
}
