package upc.ai.uninformed;

import java.util.LinkedList;

/**
 *
 * @author martin.canaval
 */
public class PuzzleEight implements State {

    int value;

    public PuzzleEight(int value) {
        this.value = value;
    }

    @Override
    public LinkedList<State> getNextStates() {
        LinkedList<State> states = new LinkedList<>();
        int temp = value;
        int pos0 = -1;
        for (int i = 0; i < 9 && pos0 == -1; i++) { // find the pos of the 0
            if (temp % 10 == 0) {
                pos0 = i;
            }
            temp /= 10;
        }
        if (pos0 > 2) { // move down state
            states.add(new PuzzleEight(swap(pos0, pos0 - 3)));
        }
        if (pos0 < 6) { // move up state
            states.add(new PuzzleEight(swap(pos0, pos0 + 3)));
        }
        if (pos0 % 3 == 0 || (pos0 - 1) % 3 == 0) { // move left state
            states.add(new PuzzleEight(swap(pos0, pos0 + 1)));
        }
        if ((pos0 - 2) % 3 == 0 || (pos0 - 1) % 3 == 0) { // move right state
            states.add(new PuzzleEight(swap(pos0, pos0 - 1)));
        }
        return states;  
    }

    @Override
    public String toString() {
        int top = value / 1000000;
        int mid = (value - top * 1000000) / 1000;
        int bot = value % 1000;
        return String.format("%03d\n%03d\n%03d\n---", top, mid, bot);
    }

    @Override
    public boolean equals(Object obj) {
        return value == ((PuzzleEight)obj).value;
    }
    
    // auxiliares
    private int pow10(int p) { // faster power of 10
        final int[] powers = {
            1, 10, 100, 1000, 10000, 100000, 1000000,
            10000000, 100000000, 1000000000
        };
        return powers[p];
    }
    private int swap(int pos0, int posB) {
        int p1 = pow10(posB);
        int temp = (value % pow10(posB + 1)) / p1;
        return value - temp * p1 + temp * pow10(pos0);
    }
}
