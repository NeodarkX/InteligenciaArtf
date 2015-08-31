package upc.ai.uninformed;

import java.util.LinkedList;

/**
 *
 * @author martin.canaval
 */
public interface State {

    LinkedList<State> getNextStates();
}
