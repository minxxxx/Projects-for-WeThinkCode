package packages.utils;

import java.io.*;
import java.util.*;

import packages.models.HeroModel;

public class readFile
{
    public static List<HeroModel>  simulateFile()
    {
        List<HeroModel> heroList = new ArrayList<HeroModel>();
        try
        {
            BufferedReader reader = new BufferedReader(new FileReader(WriteFile.FileName));
            String line = "";
            while((line = reader.readLine()) != null)
            {
                try
                {
                   if (line.trim().length() > 0){
                    HeroModel iHero = HeroFactory.newHero(line.split(",")[0], line.split(",")[1], Integer.parseInt(line.split(",")[2]), Integer.parseInt(line.split(",")[3]), Integer.parseInt(line.split(",")[4]),
                    Integer.parseInt(line.split(",")[5]), Integer.parseInt(line.split(",")[6]), line.split(",")[7], line.split(",")[8], line.split(",")[9], line.split(",")[10]);

                    heroList.add(iHero);
                   }
                }
                catch (NumberFormatException e)
                {
                    System.out.println("Number badly formatted");
                }
            }
        }catch(IOException e)
        {
            System.out.println("Cannot find file" + e);
        }
        return (heroList);
    }
}