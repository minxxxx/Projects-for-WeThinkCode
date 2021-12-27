package packages.gui.controllers;

import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.util.List;

import packages.gui.views.CreateHeroView;
import packages.gui.views.SelectHeroView;
import packages.gui.views.WelcomeView;
import packages.models.HeroModel;
import packages.utils.readFile;

public class WelcomeController{
  private WelcomeView view;

  public WelcomeController(WelcomeView view){
    this.view = view;

    this.view.navigateToSelectHeroListener(new NavigateToSelectHeroListener());
    this.view.navigateToCreateHeroListener(new NavigateToCreateHeroListener());
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

  class NavigateToSelectHeroListener implements ActionListener{
    public void actionPerformed(ActionEvent e) {
      new SelectHeroView(getHeroList()).setVisible(true);
      view.dispose();
    }
  }

  class NavigateToCreateHeroListener implements ActionListener{
    public void actionPerformed(ActionEvent e) {
      CreateHeroView createHeroView = new CreateHeroView();
      createHeroView.setVisible(true);
      new CreateHeroController(createHeroView, getHeroList());
      view.dispose();
    }
  }
}