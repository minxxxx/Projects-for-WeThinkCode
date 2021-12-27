import edu.princeton.cs.algs4.Stack;

import java.util.Arrays;

public class Board {
    // moves made so far to reach the board
    // private int moves;
    // save manhattan distances
    // private int manhattan = -1;
    private int[][] blocks;
    private int dimension;
    // record blank position
    private int blankI;
    private int blankJ;

    public Board(int[][] blocks) {
        if (blocks == null)
            dimension = 0;
        else
            dimension = blocks[0].length;
        this.blocks = new int[dimension][dimension];
        for (int i = 0; i < dimension; i++) {
            for (int j = 0; j < dimension; j++) {
                this.blocks[i][j] = blocks[i][j];
                if (blocks[i][j] == 0) {
                    blankI = i;
                    blankJ = j;
                }
            }
        }
        // initial value manhattan = -1
        // manhattan = manhattan();
        // this.blocks = blocks.clone();
    } // construct a board from an n-by-n array of blocks
      // (where blocks[i][j] = block in row i, column j)

    public int dimension() {
        return dimension;
    } // board dimension n

    public int hamming() {
        int count = 0;
        for (int i = 0; i < dimension; i++) {
            for (int j = 0; j < dimension; j++) {
                int num = blocks[i][j];
                if (num != 0) { // do not count the blank square
                    if (i == dimension - 1 && j == dimension - 1) {
                        int ref = 0; // last block should be blank
                        if (num != ref)
                            count++;
                    } else {
                        int ref = dimension * i + j + 1;
                        if (num != ref)
                            count++;
                    }
                }
            }
        }
        return count;
    } // number of blocks out of place

    public int manhattan() {
        // if (manhattan != -1) return manhattan;
        int distance = 0;
        for (int i = 0; i < dimension; i++) {
            for (int j = 0; j < dimension; j++) {
                int num = blocks[i][j];
                if (num != 0) {
                    int refI = (num - 1) / dimension;
                    int refJ = (num - 1) % dimension;
                    distance = distance + Math.abs(i - refI) + Math.abs(j - refJ);
                }
            }
        }
        // manhattan = distance;
        // return manhattan;
        return distance;
    } // sum of Manhattan distances between blocks and goal

    public boolean isGoal() {
        return manhattan() == 0;
    } // is this board the goal board?

    public Board twin() {
        // Copy current Board
        Board twin = new Board(blocks);
        // exchange
        if ((blankI == 0 && blankJ == 0) || (blankI == 0 && blankJ == 1)) {
            int temp = twin.blocks[1][0];
            twin.blocks[1][0] = twin.blocks[1][1];
            twin.blocks[1][1] = temp;
        } else {
            int temp = twin.blocks[0][0];
            twin.blocks[0][0] = twin.blocks[0][1];
            twin.blocks[0][1] = temp;
        }
        return twin;
    } // a board that is obtained by exchanging any pair of blocks

    public boolean equals(Object y) {
        if (y == this)
            return true;
        if (y == null)
            return false;
        if (y.getClass() != this.getClass())
            return false;
        Board that = (Board) y;
        return Arrays.deepEquals(this.blocks, that.blocks);
    } // does this board equal y?

    public Iterable<Board> neighbors() {
        Stack<Board> neighbors = new Stack<Board>();
        if (blankI - 1 >= 0) {
            Board neighbor = new Board(blocks);
            // move one step
            neighbor.blocks[blankI][blankJ] = blocks[blankI - 1][blankJ];
            neighbor.blocks[blankI - 1][blankJ] = 0;
            // update neighbor's blank point
            neighbor.blankI--;
            // add neighbor to stack
            neighbors.push(neighbor);
        }
        if (blankI + 1 < dimension) {
            Board neighbor = new Board(blocks);
            // move one step
            neighbor.blocks[blankI][blankJ] = blocks[blankI + 1][blankJ];
            neighbor.blocks[blankI + 1][blankJ] = 0;
            // update neighbor's blank point
            neighbor.blankI++;
            // add neighbor to stack
            neighbors.push(neighbor);
        }
        if (blankJ - 1 >= 0) {
            Board neighbor = new Board(blocks);
            // move one step
            neighbor.blocks[blankI][blankJ] = blocks[blankI][blankJ - 1];
            neighbor.blocks[blankI][blankJ - 1] = 0;
            // update neighbor's blank point
            neighbor.blankJ--;
            // add neighbor to stack
            neighbors.push(neighbor);
        }
        if (blankJ + 1 < dimension) {
            Board neighbor = new Board(blocks);
            // move one step
            neighbor.blocks[blankI][blankJ] = blocks[blankI][blankJ + 1];
            neighbor.blocks[blankI][blankJ + 1] = 0;
            // update neighbor's blank point
            neighbor.blankJ++;
            // add neighbor to stack
            neighbors.push(neighbor);
        }
        return neighbors;
    } // all neighboring boards

    public String toString() {
        StringBuilder s = new StringBuilder();
        s.append(dimension + "\n");
        for (int i = 0; i < dimension; i++) {
            for (int j = 0; j < dimension; j++) {
                s.append(String.format("%2d ", blocks[i][j]));
            }
            s.append("\n");
        }
        return s.toString();
    } // string representation of this board (in the output format specified below)

    public static void main(String[] args) {
        System.out.println("hello world.");
    } // unit tests (not graded)
}
