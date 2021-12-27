package packages.console.view;

import packages.models.*;
import packages.utils.EnemyFactory;
import packages.utils.Formulas;
import packages.utils.Menus;

import static packages.utils.Colours.*;
import packages.console.controller.*;

import java.util.*;

public class Maps
{
    private Random rand = new Random();
    private int mapSize;

    private static List<EnemyModel> enemyList;
    private static EnemyModel enemy;

    public void init(HeroModel hero) {
        
        this.mapSize = Formulas.sizeMap(hero.getLevel());
        hero.setCoordinates(new Coordinates((this.mapSize / 2), (this.mapSize / 2)));
        enemyList = EnemyFactory.getEnemyList(hero);
    }

    public void move(Scanner scan, HeroModel hero, int MapSize) {
        if (hero.getCoordinates().getX() == MapSize || hero.getCoordinates().getY() == MapSize || hero.getCoordinates().getY() == - 1 || hero.getCoordinates().getX() == - 1)
        {
            System.out.println(ANSI_YELLOW +  "\n>>>>>> You won the game! <<<<<<\n" + ANSI_RESET);
            GameSimulationModel.winGame(hero);
            ConsoleView.start();
        }
        for (EnemyModel enemyLoop: enemyList) {
            if (enemyLoop.getCoordinates().Isequals(hero.getCoordinates())){
                Menus.SimulationChoice();
                FightOrRun(hero, enemyLoop);
            }
        }

        while (scan.hasNextLine())
        {
            if (scan.hasNextInt())
            {
                int n = scan.nextInt();
                GameSimulationModel.OldX = hero.getCoordinates().getX();
                GameSimulationModel.OldY = hero.getCoordinates().getY();

                switch (n)
                {
                    case 1:
                        hero.getCoordinates().advance(1);
                        break;
                    case 2:
                        hero.getCoordinates().advance(2);
                        break;
                    case 3:
                        hero.getCoordinates().advance(3);
                        break;
                    case 4:
                        hero.getCoordinates().advance(4);
                        break;
                    case 0:
                        ConsoleView.start();
                        break;
                    default:
                        break;
                }

                drawMap(hero);
            }
            else
            {
                System.out.println(ANSI_RED + "\nINPUT MUST BE NUMERIC PLEASE SELECT ANOTHER OPTION" + ANSI_RESET);
                drawMap(hero);
            }
            
        }
    }

    public void drawMap(HeroModel hero)
    {
        System.out.println();
        System.out.println("Your coordinates: " + hero.getCoordinates().getX() + "," + hero.getCoordinates().getY());
        for (int x = 0; x < this.mapSize; x++) {
            for (int y = 0; y < this.mapSize; y++) {
                Coordinates loopCoordinates = new Coordinates(x, y);
                boolean didShow = false;
                if (loopCoordinates.Isequals(hero.getCoordinates()))
                    System.out.print(ANSI_GREEN + "0 " + ANSI_RESET);
                else 
                {
                    for (EnemyModel enemyModel : enemyList)
                    {
                        if (loopCoordinates.Isequals(enemyModel.getCoordinates()))
                        {
                            System.out.print("* ");//enemy
                            didShow = true;
                        }
                        else if (hero.getCoordinates().Isequals(enemyModel.getCoordinates()))
                        {
                            enemy = enemyModel;
                        }    
                    }
                    if (!didShow)
                    {
                        System.out.print("* ");
                    }
                }

            }
            System.out.println(); 
        }
        Menus.printMovementMenu();
        Scanner reader = new Scanner(System.in);
        move(reader, hero, mapSize);
    }

    private void FightOrRun(HeroModel hero, EnemyModel enemyModel) 
    {
        if (enemy.getHitPoints() > 0)
        {
            Scanner _reader = new Scanner(System.in);
            while (_reader.hasNextLine())
            {
                if (_reader.hasNextInt())
                {
                    int n = _reader.nextInt();
                    switch (n)
                    {
                        case 1:
                            int rn = rand.nextInt(2);
                            if (rn == 0)
                            {
                                System.out.println(ANSI_GREEN + "\nYOU CHOSE TO RUN YOU COWARD" + ANSI_RESET);
                                hero.getCoordinates().setX(GameSimulationModel.OldX);
                                hero.getCoordinates().setY(GameSimulationModel.OldY);
                                drawMap(hero);

                            }
                            else if (rn == 1)
                            {
                                System.out.println("\nLuck is not on your side, you still have to fight the enemy");
                                Fight(hero, enemyModel);
                            }
                            break;
                        case 2:
                            Fight(hero, enemyModel);
                            break;
                        default:
                            break;
                    }
                }
                else
                {
                    System.out.println(ANSI_RED + "\nINPUT MUST BE NUMERIC PLEASE SELECT ANOTHER OPTION" + ANSI_RESET);
                    FightOrRun(hero, enemyModel);
                }
            } 
        }   
    }

    private void Fight(HeroModel hero, EnemyModel enemy) 
    {
        String artifact;
        Menus.PrintFightOpponents(hero, enemy);
        try
        {
            GameSimulationModel gsm = new GameSimulationModel(hero, enemy);
            gsm.setSimulationMiliSecs(500);
            while (gsm.nextFight())
            {
                System.out.println(gsm.getSimulationOutput());
                System.out.println(ANSI_GREEN + "hero: " + ANSI_RESET + hero.getHitPoints() + ANSI_RED + " enemy: " + ANSI_RESET + enemy.getHitPoints());
            }
            if (!gsm.isHeroAlive(gsm.getHeroModel()) && !gsm.isHeroAlive(gsm.getEnemyModel())){
                System.out.println("No Winner No winner...");
            }else{
                String mssg = "";

                if (gsm.isHeroAlive(gsm.getHeroModel())){
                    mssg = gsm.getHeroModel().getName() + " won the fight";
                    System.out.println(ANSI_CYAN + "Fight Won: " + ANSI_RESET +  mssg); 
                    GameSimulationModel.resetHero(hero);
                    artifact =  GameSimulationModel.dropArtifact(enemy);
                    System.out.println("The enemy dropped a " + artifact + " do you want to keep it? \n1. Yes\n2.No \n");
                    PickOrNot(hero, enemy);
                    enemyList.remove(enemy);
                    drawMap(hero);
                }else{
                    mssg = gsm.getEnemyModel().getName() + " won the fight";
                    System.out.println(ANSI_RED + "Fight Lost: " + ANSI_RESET +  mssg);
                    System.out.println(ANSI_YELLOW + ">>>>>> GAME OVER <<<<<<" + ANSI_RESET);
                    GameSimulationModel.lostGame(hero);
                    System.exit(0);
                }
            }
        }
        catch (Exception e)
        {
            System.out.println(ANSI_RED + "ooops! Something went wrong." + ANSI_RESET);
        }
    }

    private void PickOrNot(HeroModel hero, EnemyModel enemy) 
    {
        Scanner read = new Scanner(System.in);
        int choice = 0;

        while (choice != -1)
        {
            choice = read.nextInt();
            switch (choice)
            {
                case 1:
                    GameSimulationModel.setArtifact(hero, enemy);
                    choice = -1;
                    break;
                case 2:
                    choice = -1;
                    break;
            }
        }
    }
}