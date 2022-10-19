package hw8;
/**
 *
 * @author ekasi
 */

import java.awt.Color;
import java.awt.GridLayout;
import java.awt.event.ActionListener;
import java.awt.event.ActionEvent;
import java.io.IOException;
import java.util.logging.Level;
import java.util.logging.Logger;
import javax.swing.JFrame;
import javax.swing.JButton;
import javax.swing.JPanel;

/**
 * JButtons for the PegSolitaire game
 * @author ekasi
 */
public class Jbuttons extends JFrame implements ActionListener
{
    /**
     * default constructor
     */
    public Jbuttons()
    {
        reset = new JButton( "reset" );
        load = new JButton( "load" );
        save = new JButton( "save" );
        undo = new JButton( "undo" );
        reset.setBounds(140, 10, 75, 25);
        load.setBounds(235, 10, 75, 25);
        save.setBounds(330, 10, 75, 25);
        undo.setBounds(425, 10, 75, 25);
        reset.addActionListener( this );
        load.addActionListener( this );
        save.addActionListener( this );
        undo.addActionListener( this );
    }
    
    /**
     * consturctor that takes double dimensional Cellstate
     * @param x double dimensional Cellstate
     */
    public Jbuttons(CellState[][] x)
    {
        pegO = new PegClass(x);
        
        board = new JButton[pegO.rowlength()][pegO.columnlength()];
        csBoard = new CellState[pegO.rowlength()][pegO.columnlength()];
        
        setboards();
        
        reset = new JButton( "reset" );
        load = new JButton( "load" );
        save = new JButton( "save" );
        undo = new JButton( "undo" );
        reset.addActionListener( this );
        load.addActionListener( this );
        save.addActionListener( this );
        undo.addActionListener( this );
        for(int i = 0; i < board.length; ++i)
            for(int j = 0; j < board[i].length; ++j)
                board[i][j].addActionListener( this );
    }
    
    /**
     * takes a JFrame parameter and places panel that have reset, load, save, undo JButtons on it
     * @param x Frame to build on
     */
    public void setJbuttons(JFrame x)
    {
        jbuttonPanel.setBackground(Color.gray);
        jbuttonPanel.setBounds(0,0,640,35);
        jbuttonPanel.setLayout(new GridLayout(1,4));
        jbuttonPanel.add(reset);
        jbuttonPanel.add(load);
        jbuttonPanel.add(save);
        jbuttonPanel.add(undo);
        
        x.add(jbuttonPanel);
        
        holder = x;
    }
    
    /**
     * takes a JFrame parameter and places panel that have cell JButtons on it
     * @param x Frame to build on
     */
    public void setJbuttons2(JFrame x)
    {
        cellPanel.setBackground(Color.white);
        cellPanel.setBounds(0,85,640,520);
        cellPanel.setLayout(new GridLayout(board.length,board[0].length));
        for(int i = 0; i < board.length; ++i)
            for(int j = 0; j < board[i].length; ++j)
                cellPanel.add(board[i][j]);
        
        x.add(cellPanel);
        holder = x;
    }
    
    /**
     * computer makes one move
     */
    public void cMove()
    {
        pegO.move();
        setboards();
        holder.setVisible(false);

        JFrame frame = new JFrame();
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.setSize(640, 640);

        JPanel back = new JPanel();
        back.setBackground(Color.black);
        back.setBounds(0,0,640,640);

        back.setLayout(new GridLayout());
        Jbuttons jButtons = new Jbuttons(csBoard);
        RadioButtons radioButtons = new RadioButtons(jButtons);
        radioButtons.setRadioButtons(frame);
        jButtons.setJbuttons(frame);
        jButtons.setJbuttons2(frame);
        frame.add(back);
        frame.setVisible(true);
    }
    
    /**
     * selects an action to perform
     * @param event action
     */
    public void actionPerformed( ActionEvent event )
    {
        boolean flag = false;
        if(event.getSource() == reset)
        {
            setboards();
            holder.setVisible(false);

            JFrame frame = new JFrame();
            frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
            frame.setSize(640, 640);

            JPanel back = new JPanel();
            back.setBackground(Color.black);
            back.setBounds(0,0,640,640);

            back.setLayout(new GridLayout());
            Jbuttons jButtons = new Jbuttons(boardT.getboard1());
            RadioButtons radioButtons = new RadioButtons(jButtons);
            radioButtons.setRadioButtons(frame);
            jButtons.setJbuttons(frame);
            jButtons.setJbuttons2(frame);
            frame.add(back);
            frame.setVisible(true);
            flag = false;

        }   
        else if(event.getSource() == load) try {
            setboards();
            holder.setVisible(false);

            JFrame frame = new JFrame();
            frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
            frame.setSize(640, 640);

            JPanel back = new JPanel();
            back.setBackground(Color.black);
            back.setBounds(0,0,640,640);

            back.setLayout(new GridLayout());
            Jbuttons jButtons = new Jbuttons(pegO.loadGame());
            RadioButtons radioButtons = new RadioButtons(jButtons);
            radioButtons.setRadioButtons(frame);
            jButtons.setJbuttons(frame);
            jButtons.setJbuttons2(frame);
            frame.add(back);
            frame.setVisible(true);
            flag = false;
        } catch (IOException ex) {
            Logger.getLogger(Jbuttons.class.getName()).log(Level.SEVERE, null, ex);
        }
        else if(event.getSource() == save) try {
            pegO.saveGame();
        } catch (IOException ex) {
            Logger.getLogger(Jbuttons.class.getName()).log(Level.SEVERE, null, ex);
        }
        else if(event.getSource() == undo)
        {
            pegO.getCell(undoRow1, undoColumn1).setcellType(CellState.P);
            pegO.getCell(undoRow2, undoColumn2).setcellType(CellState.P);
            pegO.getCell(undoRow3, undoColumn3).setcellType(CellState.E);
            flag = true;
        }
        else
        {
            if (selectedCell == null)
            {
                for(int i = 0; i < board.length; ++i)
                    for(int j = 0; j < board[i].length; ++j)
                        if(event.getSource() == board[i][j])
                        {
                            selectedCell = pegO.getCell(i, j);
                            srow = i; scolumn = j;
                        }
            }
            
            else
            {
                for(int i = 0; i < board.length; ++i)
                    for(int j = 0; j < board[i].length; ++j)
                        if(event.getSource() == board[i][j])
                        {
                            if (pegO.move(selectedCell, pegO.getCell(i, j)) == true)
                            {
                                undoRow1 = selectedCell.getRow();
                                undoColumn1 = selectedCell.getColumn();
                                undoRow3 = i;
                                undoColumn3 = j;
                                if (undoRow1 > undoRow3)
                                {
                                    undoRow2 = undoRow1 - 1;
                                    undoColumn2 = undoColumn1;
                                }   
                                else if(undoRow1 < undoRow3)
                                {
                                    undoRow2 = undoRow1 + 1;
                                    undoColumn2 = undoColumn1;
                                }        
                                else if(undoColumn1 > undoColumn3)
                                {
                                    undoColumn1 = undoColumn1 - 1;
                                    undoRow2 = undoRow1;
                                }                                   
                                else if(undoRow1 < undoColumn3)
                                {
                                    undoColumn2 = undoColumn1 + 1;
                                    undoRow2 = undoRow1;
                                }                               
                            }
                        }          
                selectedCell = null;
                flag = true;
            }     
        }
        
        if(flag)
        {
            setboards();
            holder.setVisible(false);

            JFrame frame = new JFrame();
            frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
            frame.setSize(640, 640);

            JPanel back = new JPanel();
            back.setBackground(Color.black);
            back.setBounds(0,0,640,640);

            back.setLayout(new GridLayout());
            Jbuttons jButtons = new Jbuttons(csBoard);
            RadioButtons radioButtons = new RadioButtons(jButtons);   
            radioButtons.setRadioButtons(frame);
            jButtons.setJbuttons(frame);
            jButtons.setJbuttons2(frame);
            frame.add(back);
            frame.setVisible(true);
            flag = false;
        }
    }
    /**
     * saves changes on board
     */
    private void setboards()
    {
        for(int i = 0; i < pegO.rowlength(); ++i)
        {
            for(int j = 0; j < pegO.columnlength(); ++j)
            {
                if(pegO.getCell(i, j).getcellType() == CellState.A)
                {
                    board[i][j] = new JButton(" ");
                    csBoard[i][j] = CellState.A;
                }                
                else if(pegO.getCell(i, j).getcellType() == CellState.P)
                {
                    board[i][j] = new JButton("P");
                    csBoard[i][j] = CellState.P;
                }
                else if(pegO.getCell(i, j).getcellType() == CellState.E)
                {
                    board[i][j] = new JButton(".");
                    csBoard[i][j] = CellState.E;
                }
            }
        }
    }
     
    private JPanel jbuttonPanel = new JPanel();
    private JPanel cellPanel = new JPanel();
    private JButton reset;
    private JButton load;
    private JButton save;
    private JButton undo;
    private JButton board[][];
    private CellState resetV[][];
    private PegClass.Cell selectedCell;
    private int srow, scolumn;
    private static int undoRow1, undoRow2, undoRow3, undoColumn1, undoColumn2, undoColumn3;
    private JFrame holder = new JFrame();
    private PegClass pegO; // TODO try to convert PegClass to PegSolitaireGame
    private BoardTypes boardT = new BoardTypes();
    private CellState[][] csBoard; 
}
