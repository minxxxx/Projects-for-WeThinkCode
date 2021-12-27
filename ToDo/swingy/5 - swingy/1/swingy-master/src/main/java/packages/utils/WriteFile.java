package packages.utils;

import java.io.BufferedWriter;
import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.List;

import packages.models.HeroModel;

public class WriteFile
{
    static FileWriter fw = null;
    static BufferedWriter bw = null;
    static PrintWriter out = null;
    private static List<HeroModel> _heroList;
    private HeroModel _hero;
    public static String FileName = "hero-stats.txt";
    public static String SimulationOutputName = "simulation-output.txt";
    
    public static void write(String filename, String str, Boolean append){
        try
        {
            fw = new FileWriter(filename, append);
            bw = new BufferedWriter(fw);
            out = new PrintWriter(bw);
            out.write(str);
            out.close();
        }catch (IOException e) {
            e.printStackTrace();
        }
    }

    public static void writeToFile(HeroModel _hero)
    {
        try
        {
                _heroList = readFile.simulateFile();
                fw = new FileWriter(FileName, true);
                bw = new BufferedWriter(fw);
                out = new PrintWriter(bw);
                out.println(_hero.getName() + "," + _hero.getType() + "," + _hero.getLevel() + "," + _hero.getXPoints() + "," + _hero.getAttack() +  ","
                + _hero.getDefense() + "," + _hero.getHitPoints() + "," + _hero.getWeapon() + "," + _hero.getArmor() + "," + _hero.getHelm() + "," + _hero.getIcon());
                out.close();
        } 
        catch (IOException e) {
            e.printStackTrace();
        }
    }

    public static void findAndUpdate(List<HeroModel> _heroList, HeroModel _hero){
        try
        {
            File _file = new File(FileName);
            fw = new FileWriter(FileName);
            bw = new BufferedWriter(fw);
            out = new PrintWriter(bw);
            out.print("");
            for (HeroModel hero : _heroList) {
                if (_hero.getName().equalsIgnoreCase(hero.getName())){
                    writeToFile(_hero);    
                }else{
                    writeToFile(hero);
                }
            }
        }catch(Exception ex)
        {
            ex.printStackTrace();
        }   
    }
}