package packages.gui.controllers;

import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.MouseEvent;
import java.awt.event.MouseListener;
import java.util.List;

import packages.gui.views.CreateHeroView;
import packages.gui.views.GameView;
import packages.gui.views.SelectHeroView;
import packages.utils.JFrameHelper;
import packages.models.HeroModel;;

public class SelectHeroController extends JFrameHelper{
    private SelectHeroView view;
    private List<HeroModel> heroList;  

    public SelectHeroController(SelectHeroView view, List<HeroModel> heroList){
        this.view = view;
        this.heroList = heroList;

        this.view.navigateToCreateHeroListener(new NavigateToCreateHeroListener());
        this.view.loadHeroListener(new LoadHeroListener());
        this.view.heroClickListener(new HeroClickListener());
        this.view.selectHeroListener(new SelectHeroListener());
    }

    public void doActionSelectHero(int index){
        if (index < this.heroList.size()){
            view.setSelectedHero();
        }else{
            ShowErrorDialog(view, "Select an item on the list before clicking \"Load Hero\"");
        }
    }

    class NavigateToCreateHeroListener implements ActionListener{
		public void actionPerformed(ActionEvent e) {
            CreateHeroView createHeroView = new CreateHeroView();
            createHeroView.setVisible(true);
            new CreateHeroController(createHeroView, heroList);

            view.dispose();
		}
    }

    class LoadHeroListener implements ActionListener{
		public void actionPerformed(ActionEvent e) {
            if (view.getMouseClickIndex() >= 0){
                doActionSelectHero(view.getMouseClickIndex());
            }else{
                ShowErrorDialog(view, "Select an item on the list before clicking \"Load Hero\"");
            }
		}
    }

    class SelectHeroListener implements ActionListener{
		public void actionPerformed(ActionEvent e) { 
            if (GameView.FrameCount < 1){
                HeroModel hero = heroList.get(view.getMouseClickIndex());
                if (hero.getHitPoints() <= 0){
                    JFrameHelper.ShowErrorDialog(null, hero.getName() + "'s HP is " + hero.getHitPoints() + ".\nHero's HP most be \"Greater then\" zero(0)!");
                }else{
                    GameView gameView = new GameView(hero);
                    gameView.setVisible(true);
                    new GameController(gameView);
                    view.dispose();
                }
            }
        }
    }

    class HeroClickListener implements MouseListener{
		public void mouseClicked(MouseEvent e) {
            view.setMouseClickIndex(e.getPoint());

            if (e.getClickCount() == 2){
                doActionSelectHero(view.getMouseClickIndex());
            }
		}

		public void mousePressed(MouseEvent e) {}

		public void mouseReleased(MouseEvent e) {}

		public void mouseEntered(MouseEvent e) {}

		public void mouseExited(MouseEvent e) {}
    }
}