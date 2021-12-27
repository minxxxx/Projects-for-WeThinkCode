package packages.models;

import java.util.Random;

import javax.swing.text.DefaultStyledDocument.ElementSpec;

import packages.enums.WeaponType;
import packages.utils.*;

import packages.utils.Formulas;
import static packages.utils.Colours.*;

public class GameSimulationModel{
    private HeroModel hero;
    private EnemyModel enemy;
    private String simulationOutput = "";
    private int simulationCount = 0;
    private int simulationMiliSecs = 1500;
    private static int copyHP;
    private Random rand;
    private static int artifactType;
    private String attacks[] = {"Dragon Punch", "Blitz Upper", "Impaler Arrow", "Flash Bomb", "Fire Bomb", "Poison Bolts", "Explosive Potion", "Massacre Axe", "Cannon Bomb", "Frag Granade"};
    public static int OldX;
    public static int OldY;

    public GameSimulationModel(HeroModel hero, EnemyModel enemy){
        this.hero = hero;
        this.enemy = enemy;
        setCopyHP(this.hero.getHitPoints());
        this.rand = new Random();

        WriteFile.write(WriteFile.SimulationOutputName, "", false);
        WriteFile.write(WriteFile.SimulationOutputName, this.getVSMessage() + "\n", true);
    }

    public Boolean nextFight() throws InterruptedException{
        if (this.isHeroAlive(this.hero) && this.isHeroAlive(this.enemy)){            
            int rn = this.rand.nextInt(2);
            int attackRan = this.rand.nextInt(10);
            int dmg = 0;
            String attacker, attacked;
            simulationCount++;

            if (rn == 0){
                dmg = this.fixDmg((this.hero.getAttack() - this.enemy.getDefense()));
                this.enemy.setHitPoints((this.enemy.getHitPoints() - dmg));
                attacked = enemy.getName();
                attacker = hero.getName();
            }
            else{
                dmg = this.fixDmg((this.enemy.getAttack() - this.hero.getDefense()));
                this.hero.setHitPoints((this.hero.getHitPoints() - dmg));
                attacker = enemy.getName();
                attacked = hero.getName();
            }
            simulationOutput = attacker + " hits " + attacked + " with a " +  this.attacks[attackRan] +" Attack, Causing " + dmg + " damage.";
            WriteFile.write(WriteFile.SimulationOutputName, simulationOutput + "\n", true);
            WriteFile.write(WriteFile.SimulationOutputName, hero.getName() + ": " + hero.getHitPoints() + "HP - " + enemy.getName() + ": " + enemy.getHitPoints() + "HP\n", true);
            Thread.sleep(this.simulationMiliSecs);
            return (true);
        }
        return (false);
    }

    private int fixDmg(int dmg){
        if (dmg <= 0)
            return (0);
        return (dmg);
    }

    public static void setCopyHP(int hp){
        copyHP = hp;
    }

    public static void resetHero(HeroModel hero){
        hero.setHitPoints(copyHP);
    }

    public static void lostGame(HeroModel hero){
        resetHero(hero);
        WriteFile.findAndUpdate(readFile.simulateFile(), hero);
    }

    public String getVSMessage(){
        return (this.hero.getName() + " (" + this.hero.getHitPoints() + "HP) VS " + this.enemy.getName() + " (" + this.enemy.getHitPoints() + "HP)");
    }
    
    public static void winGame(HeroModel hero){
        resetHero(hero);
        hero.setLevel(hero.getLevel() + 1);
        hero.setXPoints(Formulas.getXPoints(hero.getLevel()));
        WriteFile.findAndUpdate(readFile.simulateFile(), hero);
    }

    public static String dropArtifact(EnemyModel enemy)
    {
        Random rand = new Random();

        switch (rand.nextInt(3))
        {
            case 0:
                    artifactType = 0;
                    return enemy.getWeapon().toString();
            case 1:
                    artifactType = 1;
                    return enemy.getArmor().toString();
            case 2:
                    artifactType = 2;
                    return enemy.getHelm().toString();
        }
        return null;
    }

    public static void setArtifact(HeroModel hero, EnemyModel enemy) 
    {
        if (artifactType == 0)
        {
            hero.setWeapon(enemy.getWeapon());
            hero.setAttack(hero.getAttack() + 2);            
        }
        else if (artifactType == 1)
        {
            hero.setArmor(enemy.getArmor());
            hero.setDefense(hero.getDefense() + 2);
        }
        else
        {
            hero.setHelm(enemy.getHelm());
            hero.setHitPoints(hero.getHitPoints() + 2);
        } 
    }

    public int getSimulationCount(){
        return (this.simulationCount);
    }

    public String getSimulationOutput(){
        return (this.simulationOutput);
    }

    public Boolean isHeroAlive(HeroModel hero){
        return (hero.getHitPoints() > 0);
    }

    public HeroModel getHeroModel(){
        return (this.hero);
    }

    public EnemyModel getEnemyModel(){
        return (this.enemy);
    }

    public void setSimulationMiliSecs(int value){
        this.simulationMiliSecs = value;
    }

    public int getSimulationMiliSecs(){
        return (this.simulationMiliSecs);
    }
}