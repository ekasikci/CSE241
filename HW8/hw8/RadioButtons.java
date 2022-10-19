package hw8;

import java.awt.Color;
import java.awt.GridLayout;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import javax.swing.JFrame;
import javax.swing.JRadioButton;
import javax.swing.ButtonGroup;
import javax.swing.JPanel;
public class RadioButtons extends JFrame implements ActionListener
{
    /**
     * default constructor
     */
    public RadioButtons()
    {
        human = new JRadioButton("human");
        computer = new JRadioButton("computer");
        board1 = new JRadioButton("1. Board");
        board2 = new JRadioButton("2. Board");
        board3 = new JRadioButton("3. Board");
        board4 = new JRadioButton("4. Board");
        board5 = new JRadioButton("5. Board");
        board6 = new JRadioButton("6. Board");
        ButtonGroup gameType = new ButtonGroup();
        ButtonGroup boardType = new ButtonGroup();
        gameType.add(human);
        gameType.add(computer);
        boardType.add(board1);
        boardType.add(board2);
        boardType.add(board3);
        boardType.add(board4);
        boardType.add(board5);
        boardType.add(board6);
        
        board1.addActionListener( this );
        board2.addActionListener( this );
        board3.addActionListener( this );
        board4.addActionListener( this );
        board5.addActionListener( this );
        board6.addActionListener( this );
        human.addActionListener( this );
        computer.addActionListener( this );
    }
    
    /**
     * 
     * @param x jbutton object
     */
    public RadioButtons(Jbuttons x)
    {
        jbuttons = x;
        human = new JRadioButton("human");
        computer = new JRadioButton("computer");
        board1 = new JRadioButton("1. Board");
        board2 = new JRadioButton("2. Board");
        board3 = new JRadioButton("3. Board");
        board4 = new JRadioButton("4. Board");
        board5 = new JRadioButton("5. Board");
        board6 = new JRadioButton("6. Board");
        ButtonGroup gameType = new ButtonGroup();
        ButtonGroup boardType = new ButtonGroup();
        gameType.add(human);
        gameType.add(computer);
        boardType.add(board1);
        boardType.add(board2);
        boardType.add(board3);
        boardType.add(board4);
        boardType.add(board5);
        boardType.add(board6);
        
        board1.addActionListener( this );
        board2.addActionListener( this );
        board3.addActionListener( this );
        board4.addActionListener( this );
        board5.addActionListener( this );
        board6.addActionListener( this );
        human.addActionListener( this );
        computer.addActionListener( this );
    }
    
    /**
     * takes a JFrame parameter and places panel that have radio buttons on it
     * @param x Frame to build on
     */
    public void setRadioButtons(JFrame x)
    {
        rbuttonPanel.setBackground(Color.gray);
        rbuttonPanel.setBounds(0,35,640,50);
        rbuttonPanel.setLayout(new GridLayout());
        rbuttonPanel.add(board1);
        rbuttonPanel.add(board2);
        rbuttonPanel.add(board3);
        rbuttonPanel.add(board4);
        rbuttonPanel.add(board5);
        rbuttonPanel.add(board6);
        rbuttonPanel.add(human);
        rbuttonPanel.add(computer);
        
        x.add(rbuttonPanel);
        
        holder = x;
    }
    
    /**
     * selects an action to perform
     * @param event action
     */
    public void actionPerformed( ActionEvent event )
    {
        if(event.getSource() == human);
        else if(event.getSource() == computer) jbuttons.cMove();
        else 
        {
            if (event.getSource() == board1) csBoard = boardT.getboard1();
            else if (event.getSource() == board2) csBoard = boardT.getboard2();
            else if (event.getSource() == board3) csBoard = boardT.getboard3();
            else if (event.getSource() == board4) csBoard = boardT.getboard4();
            else if (event.getSource() == board5) csBoard = boardT.getboard5();
            else if (event.getSource() == board6) csBoard = boardT.getboard6();

            holder.setVisible(false);

            JFrame frame = new JFrame();
            frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
            frame.setSize(640, 640);

            JPanel back = new JPanel();
            back.setBackground(Color.black);
            back.setBounds(0,0,640,640);

            back.setLayout(new GridLayout());
            RadioButtons radioButtons = new RadioButtons();
            Jbuttons jButtons = new Jbuttons(csBoard);
            radioButtons.setRadioButtons(frame);
            jButtons.setJbuttons(frame);
            jButtons.setJbuttons2(frame);
            frame.add(back);
            frame.setVisible(true);
        }        
    }
    private JPanel rbuttonPanel = new JPanel();  
    
    private JRadioButton human;
    private JRadioButton computer;
    
    private JRadioButton board1;
    private JRadioButton board2;
    private JRadioButton board3;
    private JRadioButton board4;
    private JRadioButton board5;
    private JRadioButton board6;
    
    private Jbuttons jbuttons, jbuttons2;
    
    private PegSolitaireGame pegO;

    private JFrame holder = new JFrame();
    private BoardTypes boardT = new BoardTypes();
    private CellState[][] csBoard;   
} 