package hw8;
/**
 *
 * @author ekasi
 */
public class BoardTypes {
    
    CellState a = CellState.A;
    CellState p = CellState.P;
    CellState e = CellState.E;
    
    /**
     * board type 1
     */
    private CellState board1[][] = {
    {a, a, p, p, p, a, a},
    {a, p, p, p, p, p, a},
    {p, p, p, e, p, p, p},
    {p, p, p, p, p, p, p},
    {p, p, p, p, p, p, p},
    {a, p, p, p, p, p, a},
    {a, a, p, p, p, a, a}
    };
    
    /**
     * board type 2
     */
    private CellState board2[][] = {
    {a, a, a, p, p, p, a, a, a},
    {a, a, a, p, p, p, a, a, a},
    {a, a, a, p, p, p, a, a, a},
    {p, p, p, p, p, p, p, p, p},
    {p, p, p, p, e, p, p, p, p},
    {p, p, p, p, p, p, p, p, p},
    {a, a, a, p, p, p, a, a, a},
    {a, a, a, p, p, p, a, a, a},
    {a, a, a, p, p, p, a, a, a}
    };
    
    /**
     * board type 3
     */
    private CellState board3[][] = {
        {a ,a, p, p, p, a, a, a},
        {a ,a, p, p, p, a, a, a},
        {a ,a, p, p, p, a, a, a},
        {p ,p, p, p, p, p, p, p},
        {p ,p, p, e, p, p, p, p},
        {p ,p, p, p, p, p, p, p},
        {a ,a, p, p, p, a, a, a},
        {a ,a, p, p, p, a, a, a}
    };
    
    /**
     * board type 4
     */
    private CellState board4[][] = {
        {a, a, p, p, p, a, a},
        {a, a, p, p, p, a, a},
        {p, p, p, p, p, p, p},
        {p, p, p, e, p, p, p},
        {p, p, p, p, p, p, p},
        {a, a, p, p, p, a, a},
        {a, a, p, p, p, a, a}
    };
    
    /**
     * board type 5
     */
    private CellState board5[][] = {
        {a, a, a, a, p, a, a, a, a},
        {a, a, a, p, p, p, a, a, a},
        {a, a, p, p, p, p, p, a, a},
        {a, p, p, p, p, p, p, p, a},
        {p, p, p, p, e, p, p, p, p},
        {a, p, p, p, p, p, p, p, a},
        {a, a, p, p, p, p, p, a, a},
        {a, a, a, p, p, p, a, a, a},
        {a, a, a, a, p, a, a, a, a}
    };
    
    /**
     * board type 6
     */
    private CellState board6[][] = {
        {a, a, a, a, e, a, a, a, a},
        {a, a, a, p, a, p, a, a, a},
        {a, a, p, a, p, a, p, a, a},
        {a, p, a, p, a, p, a, p, a}, 
        {p, a, p, a, p, a, p, a, p}
    };
    
    /**
     * returns indicated board
     * @return board type 1
     */
    public CellState[][] getboard1() { return board1; }
    /**
     * returns indicated board
     * @return board type 2
     */
    public CellState[][] getboard2() { return board2; }
    /**
     * returns indicated board
     * @return board type 3
     */
    public CellState[][] getboard3() { return board3; }
    /**
     * returns indicated board
     * @return board type 4
     */
    public CellState[][] getboard4() { return board4; }
    /**
     * returns indicated board
     * @return board type 5
     */
    public CellState[][] getboard5() { return board5; }
    /**
     * returns indicated board
     * @return board type 6
     */
    public CellState[][] getboard6() { return board6; }
}
