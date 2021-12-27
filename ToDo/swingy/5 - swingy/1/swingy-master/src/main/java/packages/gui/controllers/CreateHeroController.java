 package packages.gui.controllers;

import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.io.File;
import java.util.List;

import javax.swing.JFileChooser;

import packages.gui.views.CreateHeroView;
import packages.gui.views.SelectHeroView;
import packages.models.HeroModel;
import packages.utils.JFrameHelper;
import packages.utils.WriteFile;
import packages.utils.readFile;

public class CreateHeroController{
    private CreateHeroView view;
    private List<HeroModel> heroList;

    public CreateHeroController(CreateHeroView view, List<HeroModel> heroList){
        this.view = view;
        this.heroList = heroList;

        this.view.cancelListener(new CancelListener());
        this.view.selectHeroImageListener(new SelectHeroImageListener());
        this.view.createHeroListener(new CreateHeroListener());
    }

    private void navigateToSelectHero(){
        List<HeroModel> heros;
        try {
            heros = readFile.simulateFile();
        } catch (Exception e) {
            JFrameHelper.ShowErrorDialog(view, "Error getting new Hero List. Old Hero List will be passed.");
            heros = this.heroList;
        }

        SelectHeroView selectHeroView = new SelectHeroView(heros);
        selectHeroView.setVisible(true);
        new SelectHeroController(selectHeroView, heros);
        
        view.dispose();
    }

    class CancelListener implements ActionListener{
		public void actionPerformed(ActionEvent e) {
            navigateToSelectHero();
		}
    }

    class SelectHeroImageListener implements ActionListener{
		public void actionPerformed(ActionEvent e) {
            int i;
            JFileChooser fileChooser = new JFileChooser();
            i = fileChooser.showOpenDialog(null);

            if (i == JFileChooser.APPROVE_OPTION)
            {
                File file = fileChooser.getSelectedFile();
                String filePath = file.getPath();
                view.setHeroImagePath(filePath);
            }
		}
    }

    class CreateHeroListener implements ActionListener{
		public void actionPerformed(ActionEvent e) {
            view.setNewHero(heroList);
            if (view.getNewHero() != null){
                WriteFile.writeToFile(view.getNewHero());
                navigateToSelectHero();
            }
		}
    }


}