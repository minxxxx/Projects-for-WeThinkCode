package packages.utils;

import static packages.utils.Colours.*;

import packages.models.EnemyModel;
import packages.models.HeroModel;

public class Menus {
    public static void menu()
    {
        System.out.print(ANSI_CYAN + "\n>>>>>> START <<<<<<" + "\nSELECT ONE OF THE OPTIONS\n" + ANSI_RESET + "1. Create a new Hero\n" + "2. Select from existing Heroes\n" + "3. Switch to gui\n" + "4. Exit\n");
    }

    public static void heroMenu()
    {
        System.out.println(ANSI_CYAN+ "\nSELECT HERO TYPE\n" + ANSI_RESET + "1. Knight\n" + "2. Warrior\n" + "3. Elf\n" + "4. Hunter\n" + "5. Switch to GUI\n" + "0. Back\n");
    }

    public static void printStats(HeroModel _hero)
    {
        String hero_info = ANSI_CYAN + "\nHERO STATS\n" + ANSI_RESET +
            ANSI_PURPLE  + "\nName       : " + ANSI_RESET + _hero.getName() + "\n" +
            ANSI_PURPLE  + "Type       : " + ANSI_RESET + _hero.getType() + "\n" +
            ANSI_PURPLE  + "Level      : " + ANSI_RESET + _hero.getLevel() + "\n" +
            ANSI_PURPLE  + "X-Points   : " + ANSI_RESET + _hero.getXPoints() + "\n" +
            ANSI_PURPLE  + "Attack     : " + ANSI_RESET + _hero.getAttack() + "\n" +
            ANSI_PURPLE  + "Defense    : " + ANSI_RESET + _hero.getDefense() + "\n" +
            ANSI_PURPLE  + "Hit Points : " + ANSI_RESET + _hero.getHitPoints() + "\n" +
            ANSI_PURPLE  + "Weapon     : " + ANSI_RESET + _hero.getWeapon() + "\n" +
            ANSI_PURPLE  + "Armor      : " + ANSI_RESET + _hero.getArmor() + "\n" +
            ANSI_PURPLE  + "Helm       : " + ANSI_RESET + _hero.getHelm();

        System.out.println(hero_info);
    }

    public static void printMovementMenu()
    {
        String movement = ANSI_CYAN + "\nCHOOSE A MOVEMENT DIRECTION\n" + ANSI_RESET +
            "1. North\n" +
            "2. East\n" +
            "3. West\n" +
            "4. South\n" +
                "0. Back\n";
        System.out.print(movement);
    }
    
    public static void SimulationChoice() 
    {
        String choice = ANSI_CYAN + "\nYOU HAVE ENCOUNTERED AN ENEMY, WHAT DO YOU WANT TO DO?\n" + ANSI_RESET +
            "1. Run\n" + 
            "2. Fight\n";
        System.out.println(choice);     
    }
    
    public static void PrintFightOpponents(HeroModel hero, EnemyModel enemy) 
    {
        System.out.println(ANSI_GREEN + hero.getName().toUpperCase()    + ANSI_RESET + " VS " + ANSI_RED + enemy.getName().toUpperCase() + ANSI_RESET);
        System.out.println(ANSI_GREEN + "Attack     : " + ANSI_RESET + hero.getAttack()           + ANSI_CYAN + "                     |         "     + ANSI_RESET + ANSI_RED + "Attack     : " + ANSI_RESET + enemy.getAttack());
        System.out.println(ANSI_GREEN + "Defense    : " + ANSI_RESET + hero.getDefense()          + ANSI_CYAN + "                     |         "     + ANSI_RESET + ANSI_RED + "Defense    : " + ANSI_RESET + enemy.getDefense());
        System.out.println(ANSI_GREEN + "Hit Points : " + ANSI_RESET + hero.getHitPoints()        + ANSI_CYAN + "                     |         "     + ANSI_RESET + ANSI_RED + "Hit Points : " + ANSI_RESET + enemy.getHitPoints());
        System.out.println(ANSI_GREEN + "Weapon     : " + ANSI_RESET + hero.getWeapon()           + ANSI_CYAN + "                  |         "        + ANSI_RESET + ANSI_RED + "Weapon     : " + ANSI_RESET + enemy.getWeapon());
        System.out.println(ANSI_GREEN + "Armor      : " + ANSI_RESET + hero.getArmor()            + ANSI_CYAN + "                 |         "          + ANSI_RESET + ANSI_RED + "Armor      : " + ANSI_RESET + enemy.getArmor());
        System.out.println(ANSI_GREEN + "Helm       : " + ANSI_RESET + hero.getHelm()             + ANSI_CYAN + "                 |         "        + ANSI_RESET + ANSI_RED + "Helm       : " + ANSI_RESET + enemy.getHelm() + "\n");
    }
}