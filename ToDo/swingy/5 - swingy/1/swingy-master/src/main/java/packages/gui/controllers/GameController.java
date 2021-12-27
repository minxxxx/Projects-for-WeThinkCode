package packages.gui.controllers;

import java.awt.event.KeyEvent;
import java.awt.event.KeyListener;

import packages.gui.views.GameView;
import packages.models.GameSimulationModel;
import packages.models.HeroModel;

public class GameController{
    private GameView view;
    private HeroModel hero;

    public GameController(GameView view){
        this.view = view;
        this.hero = this.view.getHero();
        this.view.setKeyListener(new TheKeyListener());
    }

    private class TheKeyListener implements KeyListener{
		public void keyTyped(KeyEvent e) {}

		public void keyPressed(KeyEvent e) {
            moveHero(e.getKeyCode());
		}

		public void keyReleased(KeyEvent e) {}
    }

    private void moveHero(int code){
        int x = hero.getCoordinates().getX();
        int y = hero.getCoordinates().getY();
        GameSimulationModel.OldX = x;
        GameSimulationModel.OldY = y;

        switch (code){
            case 38:
                // Up
                y--;
                hero.getCoordinates().setY(y);
            break;
            case 40:
                // Down
                y++;
                hero.getCoordinates().setY(y);
            break;
            case 37:
                // Left
                x--;
                hero.getCoordinates().setX(x);
            break;
            case 39:
                // Right
                x++;
                hero.getCoordinates().setX(x);
            break;
            case 81:
                this.view.disposeWindow();
            break;
            case 27:
                this.view.disposeWindow();
            break;
        }
        this.view.drawMap();
    }
}