import edu.princeton.cs.algs4.MinPQ;
import edu.princeton.cs.algs4.In;
import edu.princeton.cs.algs4.StdOut;
import edu.princeton.cs.algs4.Stack;

import java.util.Comparator;

public class Solver {

    private int moves = -1;
    private Stack<Board> initialSolv;

    public Solver(Board ini) {
        if (ini == null)
            throw new IllegalArgumentException("passed a null argument");
        SearchNode initial = new SearchNode(ini, null, 0);
        // build twin board and SearchNode
        Board twinBoard = ini.twin();
        SearchNode twin = new SearchNode(twinBoard, null, 0);
        findSolution(initial, twin);
    } // find a solution to the initial board (using the A* algorithm)

    // find a solution to the initial board (using the A* algorithm)
    private void findSolution(SearchNode initial, SearchNode twin) {

        initialSolv = new Stack<Board>();

        // build two priority queue
        MinPQ<SearchNode> initialPQ = new MinPQ<SearchNode>(new ByManhattan());
        MinPQ<SearchNode> twinPQ = new MinPQ<SearchNode>(new ByManhattan());

        // add initial and twin board
        initialPQ.insert(initial);
        twinPQ.insert(twin);

        // A* algorithm for both board
        while (true) {
            if (!initialPQ.isEmpty()) {
                SearchNode i = initialPQ.delMin();
                if (i.b.isGoal()) {
                    this.moves = i.moves;
                    // push this sequence of answer into stack
                    while (i != null) {
                        initialSolv.push(i.b);
                        i = i.prev;
                    }
                    return;
                } else {
                    // find neighbors
                    Iterable<Board> neighbors = i.b.neighbors();
                    for (Board b : neighbors) {
                        if (i.prev != null && b.equals(i.prev.b)) {
                            continue;
                        }
                        initialPQ.insert(new SearchNode(b, i, i.moves + 1));
                    }
                }
            }
            if (!twinPQ.isEmpty()) {
                SearchNode t = twinPQ.delMin();
                if (t.b.isGoal()) {
                    this.moves = -1;
                    initialSolv = null;
                    return;
                } else {
                    Iterable<Board> neighbors = t.b.neighbors();
                    for (Board b : neighbors) {
                        if (t.prev != null && b.equals(t.prev.b)) {
                            continue;
                        }
                        twinPQ.insert(new SearchNode(b, t, t.moves + 1));
                    }
                }
            }
        }
    }

    public boolean isSolvable() {
        return this.moves != -1;
    } // is the initial board solvable?

    public int moves() {
        return this.moves;
    }

    // min number of moves to solve initial board; -1 if unsolvable
    public Iterable<Board> solution() {
        if (isSolvable())
            return initialSolv;
        else
            return null;
    } // sequence of boards in a shortest solution; null if unsolvable

    // Comparator
    private class ByManhattan implements Comparator<SearchNode> {
        public int compare(SearchNode b1, SearchNode b2) {
            int b1Manhattan = b1.priority;
            int b2Manhattan = b2.priority;
            if (b1Manhattan < b2Manhattan)
                return -1;
            else if (b1Manhattan > b2Manhattan)
                return +1;
            else
                return 0;
        }
    }

    // define a search node nested class
    private class SearchNode {
        private final Board b;
        // record previous board
        private final SearchNode prev;

        // how many moves to reach this search node
        private final int moves;
        private final int priority;

        private SearchNode(Board board, SearchNode prev, int moves) {
            this.b = board;
            this.prev = prev;
            this.moves = moves;
            priority = b.manhattan() + moves;
        }
    }

    public static void main(String[] args) {
        // create initial board from file
        In in = new In(args[0]);
        int n = in.readInt();
        int[][] blocks = new int[n][n];
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                blocks[i][j] = in.readInt();
        Board initial = new Board(blocks);

        // solve the puzzle
        Solver solver = new Solver(initial);

        // print solution to standard output
        if (!solver.isSolvable())
            StdOut.println("No solution possible");
        else {
            StdOut.println("Minimum number of moves = " + solver.moves());
            for (Board board : solver.solution())
                StdOut.println(board);
        }
    } // solve a slider puzzle (given below)
}
