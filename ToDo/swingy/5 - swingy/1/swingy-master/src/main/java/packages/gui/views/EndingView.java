package packages.gui.views;

import java.awt.Color;
import java.util.List;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
//import java.lang.management.ThreadInfo;

import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JPanel;
import javax.swing.JTextArea;

//import packages.gui.controllers.SelectHeroController;
import packages.models.HeroModel;
import packages.utils.JFrameHelper;
import packages.utils.readFile;

public class EndingView extends JFrame
{
    private JPanel _mainPanel;
    private JLabel _lblImg;
    private JPanel _bottomPanel;
    private String _gameOverText;
    private JButton _btnContinue;
    private JPanel _imgPanel;

    public EndingView()
    {
        this.setDefaultCloseOperation(JFrame.DISPOSE_ON_CLOSE);
        this.setTitle("You Lose");
        this.setSize(600, 300);
        this.setBackground(new Color(255, 255, 255));
        this.setResizable(false);
        this.setLocationRelativeTo(null);
        this.setVisible(true);

//        checkHitPoints();
        this.init();
        this.continueBtnListener(new ContinueBtnListener());        
        
    }

    public void init()
    {          
            JTextArea message = new JTextArea();
            this._mainPanel = new JPanel();
            this._bottomPanel = new JPanel();
            this._btnContinue = new JButton("Continue");
            this._lblImg = new JLabel();
            this._imgPanel = new JPanel();
            this._lblImg = JFrameHelper.getLabelImage("src/main/java/packages/images/you-lose.png", 250);
            this._mainPanel.setLayout(null);
            this._bottomPanel.add(this._btnContinue);
            this._bottomPanel.setBounds(0, this.getHeight() - 60, this.getWidth(), 60);

            this._imgPanel.add(this._lblImg);
            this._imgPanel.setBounds(0, 0, this.getWidth(), this.getHeight() - 60);

            this._mainPanel.add(this._imgPanel);
            this._mainPanel.add(this._bottomPanel);
            
            this._mainPanel.setBackground(new Color(255, 255, 255));            
            this._mainPanel.setBounds(0, 0, this.getWidth(), this.getHeight() - 60);            

            this.add(this._mainPanel);
            // this.dispose();
            // SelectHeroView selectHeroView = new SelectHeroView(readFile.simulateFile());
            // selectHeroView.setVisible(true);
    }
    
//    public void checkHitPoints()
//    {
//        // String win =
//        // "\n#     #                  #     #           ###     " +
//        // "\n #   #   ####  #    #    #  #  # # #    #  ###     " +
//        // "\n  # #   #    # #    #    #  #  # # ##   #  ###     " +
//        // "\n   #    #    # #    #    #  #  # # # #  #   #      " +
//        // "\n   #    #    # #    #    #  #  # # #  # #          " +
//        // "\n   #    #    # #    #    #  #  # # #   ##  ###     " +
//        // "\n   #     ####   ####      ## ##  # #    #  ###     ";
//
//        String loose =
//        "\n#     #                  #                                   ###         " +
//        "\n #   #   ####  #    #    #        ####   ####   ####  ###### ###         " +
//        "\n  # #   #    # #    #    #       #    # #    # #      #      ###         " +
//        "\n   #    #    # #    #    #       #    # #    #  ####  #####   #          " +
//        "\n   #    #    # #    #    #       #    # #    #      # #                  " +
//        "\n   #    #    # #    #    #       #    # #    # #    # #      ###         " +
//        "\n   #     ####   ####     #######  ####   ####   ####  ###### ###         ";
//
//        // if (__hero.getHitPoints() > 0)
//        // {
//        //     setGameOverText(win);
//        // }
//        // else
//        // {
//            setGameOverText(loose);
//        //}
//    }

//    public void setGameOverText(String gameOverText)
//    {
//        this._gameOverText = gameOverText;
//    }

//    public String getGameOverText()
//    {
//        return this._gameOverText;
//    }

    public void continueBtnListener(ActionListener listener)
    {
        this._btnContinue.addActionListener(listener);
    }

    private void exitProgram()
    {
        this.dispose();
    }

    private List<HeroModel> getHeroList(){
        List<HeroModel> heroList = null;
    
        try {
          heroList = readFile.simulateFile();
        } catch (Exception exc) {
          exc.printStackTrace();
        }
        return (heroList);
      }
    
    private class ContinueBtnListener implements ActionListener
    {
		public void actionPerformed(ActionEvent e) {
            new SelectHeroView(getHeroList()).setVisible(true);
            //System.exit(1);
            exitProgram();
		}
    }

}