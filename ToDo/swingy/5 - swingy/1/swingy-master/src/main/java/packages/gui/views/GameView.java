package packages.gui.views;

import java.awt.Color;
import java.awt.Dimension;
import java.awt.GridLayout;
import java.awt.Toolkit;
import java.awt.event.KeyListener;
import java.awt.event.WindowAdapter;
import java.awt.event.WindowEvent;

import java.util.List;
import java.util.Random;

import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JOptionPane;
import javax.swing.JPanel;

import packages.console.controller.Coordinates;
import packages.gui.controllers.GameSimulationController;
import packages.models.EnemyModel;
import packages.models.GameSimulationModel;
import packages.models.HeroModel;
import packages.utils.EnemyFactory;
import packages.utils.Formulas;
import packages.utils.JFrameHelper;

public class GameView extends JFrame{
    //H: 1080, W: 1920 (Current Mac - screen size)
    private Dimension screenSize = Toolkit.getDefaultToolkit().getScreenSize();
    private HeroModel hero;
    private JLabel lblHeroImage;
    private JPanel panelMain;
    private int mapSize = 0;
    private List<EnemyModel> enemiesList;
    public static int FrameCount;
    private int _retHitPoints;

    public GameView(HeroModel hero){
        this.setDefaultCloseOperation(JFrame.DO_NOTHING_ON_CLOSE);
        this.setTitle("Game");
        this.setResizable(false);
        this.setLocationRelativeTo(null);
        FrameCount++;
        
        this.hero = hero;
        GameSimulationModel.setCopyHP(this.hero.getHitPoints());
        this.init();        

        this.addWindowListener(new WindowAdapter() {
            @Override
            public void windowClosing(WindowEvent windowEvent) {
                disposeWindow();
            }
        });
    }

    public void disposeWindow(){
        FrameCount--;
        this.dispose();
    }

    private void init(){
        this.mapSize = Formulas.sizeMap(this.hero.getLevel());
        this.setSize(800, 800);
        panelMain = new JPanel();
        panelMain.setBackground(new Color(255, 255, 255));
        panelMain.setLayout(new GridLayout(this.mapSize, this.mapSize, 1, 1));
        panelMain.setBounds(5, 5, (this.getWidth() - 10), (this.getHeight() - 10));
        this.lblHeroImage = new JLabel();

        this.hero.setCoordinates(new Coordinates((this.mapSize / 2), (this.mapSize / 2)));
        this.enemiesList = EnemyFactory.getEnemyList(this.hero);
        this.drawMap();

        this.add(panelMain);
    }

    public void drawMap(){
        Random rand = new Random();
        Coordinates heroEnemyCoordinatesMatch = null;
        EnemyModel enemy = null;
        int imageSize = ((this.getWidth() / Formulas.sizeMap(this.hero.getLevel())) - 12);
        this.panelMain.removeAll();

        if ((this.hero.getCoordinates().getX() < 0 || this.hero.getCoordinates().getY() < 0) ||
            (this.hero.getCoordinates().getX() >= this.mapSize || this.hero.getCoordinates().getY() >= this.mapSize))
        {
            //Check if Hero is outside the map...
            GameSimulationModel.winGame(this.hero);
            JFrameHelper.ShowInfoDialog(this, "You Won", "You win...");
            this.disposeWindow();
        }

        for (EnemyModel enemyLoop: this.enemiesList) {
            if (enemyLoop.getCoordinates().Isequals(this.hero.getCoordinates())){
                heroEnemyCoordinatesMatch = new Coordinates(enemyLoop.getCoordinates().getX(), enemyLoop.getCoordinates().getY());
                enemy = enemyLoop;
            }
        }

        for (int y = 0; y < this.mapSize; y++){
            for (int x = 0; x < this.mapSize; x++){
                JPanel panel = new JPanel();
                Coordinates loopCoordinates = new Coordinates(x, y);
                if (this.hero.getCoordinates().Isequals(loopCoordinates)){
                    this.lblHeroImage = JFrameHelper.getLabelImage(this.hero.getIcon(), imageSize);
                    panel.setBackground(new Color(rand.nextInt(255), rand.nextInt(255), rand.nextInt(255)));
                    panel.add(this.lblHeroImage);
                }
                for (EnemyModel enemyLoop: this.enemiesList) {
                    if (loopCoordinates.Isequals(enemyLoop.getCoordinates()) && enemyLoop.getHitPoints() > 0){
                        // Enemy is here, and alive
/*                      JLabel lblEnemyImage = JFrameHelper.getLabelImage(enemyLoop.getIcon(), imageSize);
                        panel.add(lblEnemyImage);*/

                        if((heroEnemyCoordinatesMatch != null && enemy != null) && enemy.getCoordinates().Isequals(enemyLoop.getCoordinates())){
                            panel.setBackground(new Color(255, 50, 50));
                        }
                    }
                    if (loopCoordinates.Isequals(enemyLoop.getCoordinates()) && enemyLoop.getHitPoints() <= 0){
                        // Enemy is here, but dead
                        panel.setBackground(new Color(126,87,194));
                    }
                }
                this.panelMain.add(panel);
            }   
        }
        this.panelMain.revalidate();
        this.panelMain.repaint();
        Random ran = new Random();
        if (heroEnemyCoordinatesMatch != null && enemy != null){
            if (enemy.getHitPoints() > 0){
                if (JFrameHelper.ShowConfirmDialog(this, "Fight || Run", "You have encounterd a Villan" + "\n      (N)Run Or (Y)Fight ")){
                    // Start fight sim...
                    GameSimulationModel model  =  new GameSimulationModel(this.hero, enemy);
                    new GameSimulationController(new GameSimulationView(model), model, this);
                    this.setVisible(false);
                }
                else
                    {
                    // eg.: hero level -= 1
                    int n = ran.nextInt(2) + 1;
                    switch(n)
                    {
                        case 1:
                            this.hero.getCoordinates().setX(GameSimulationModel.OldX);
                            this.hero.getCoordinates().setY(GameSimulationModel.OldY);
                            this.drawMap();
                            break;
                        case 2:
                            JOptionPane.showConfirmDialog(null, "The Gods say you must fight!", "The Gods Have Spoken", JOptionPane.DEFAULT_OPTION);
                            GameSimulationModel model  =  new GameSimulationModel(this.hero, enemy);
                            new GameSimulationController(new GameSimulationView(model), model, this);
                            this.setVisible(false);
                            break;
                        default:
                            break;
                    }
                }
            }
        }
    }

    public HeroModel getHero(){
         return (this.hero);
    }

    public void setKeyListener(KeyListener listener){
        this.addKeyListener(listener);
    }

    public int getMapSize(){
        return (this.mapSize);
    }

    public List<EnemyModel> getEnemyList(List<EnemyModel> list){
        return (this.enemiesList);
    }

    public void setRetHitPoints(int retHitPoints)
    {
        this._retHitPoints = retHitPoints;
    }

    public int getRetHitPoints()
    {
        return this._retHitPoints;
    }

}