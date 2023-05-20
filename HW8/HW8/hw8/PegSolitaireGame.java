package hw8;

import java.io.IOException;

/**
 *
 * @author ekasi
 */
interface PegSolitaireGame {   
    
    /**
     * computer makes one move
     */
    void move();
    
    /**
     * Prints the number of the remeaning pegs
     */
    int outPegs();
    
    /**
     * Saves current game
     */
    void saveGame() throws IOException;
    
    /**
     * Loads the saved games
     */
    CellState[][] loadGame() throws IOException;
    
    /**
     * Return true if the game has ended
     */
    boolean isEnded();
    
}

